import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple
import string
import input_conv
import parser
import sys
import os
import random
import time
import pickle
from pathlib import Path


def generate_ttile_conv2d(name_file, files):
    cc_code_begin = """
extern "C" {
    #include <stdio.h>
    """

    if len(files) == 1:
        cc_code_midle = files[0]
    else:
        cc_code_midle = files[0]
        cc_code_midle += "\n\n"
        cc_code_midle += files[1]

    cc_code_end = """
    void ttile_conv2d_reset(float * Output, int F, int X, int Y, int strideO1, int strideO2) {
        /*
        Simple Convolution

        Inputs:
            - Output: Output
            - F: out_channels
            - X: width
            - Y: height

        */
        for (int f=0; f<F; f++){
            for (int y=0; y<Y; y++){
                for (int x=0; x<X; x++){
                    Output[x*strideO1 + y*strideO2 + f] = 0.0;
                }
            }
        }
        return;
    }
}
    """
    cc_code = cc_code_begin + cc_code_midle + cc_code_end
    return cc_code

def conv_impl(name_file, option_compilation, files):
    cc_code = generate_ttile_conv2d(name_file, files)
    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    options = option_compilation
    # Create LLVM ir from c source code
    ll_code = clang.create_llvm(cc_code, output=ll_path, options=options)
    return ll_code

def intrin_conv(name_function, W, H, C, F, X, Y, stride_w, stride_h):

    """
    W = kernel_w,
    H = kernel_h,
    C = in_channels,
    F = out_channels,
    X = width,
    Y = height
    """
    if stride_h == 1:
        a = te.placeholder((1, X  + W - 1, Y  + H - 1, C), name="a")
    else:
        a = te.placeholder((1, X * stride_w + W - 1, Y * stride_h + H - 1, C), name="a")
    w = te.placeholder((W, H, C, F), name="w")

    axe_in_channels = te.reduce_axis((0, C), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, H), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, W), name="axe_kernel_w")

    strideA1 = tvm.te.var("sA1")
    strideA2 = tvm.te.var("sA2")
    strideA3 = tvm.te.var("sA3")

    strideB1 = tvm.te.var("sB1")
    strideB2 = tvm.te.var("sB2")
    strideB3 = tvm.te.var("sB3")

    strideC1 = tvm.te.var("sC1")
    strideC2 = tvm.te.var("sC2")
    strideC3 = tvm.te.var("sC3")

    o = te.compute(
    (1, X, Y, F),
    lambda batch, xx, yy, out_channels: te.sum(
        a[batch, stride_w * xx + axe_kernel_w, stride_h * yy + axe_kernel_h, axe_in_channels]* w[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
    Ab = tvm.tir.decl_buffer(a.shape, a.dtype, name="A", offset_factor=1, strides=[strideA1, strideA2, strideA3, 1])
    Ww = tvm.tir.decl_buffer(w.shape, w.dtype, name="W", offset_factor=1, strides=[strideB1, strideB2, strideB3, 1])
    Oo = tvm.tir.decl_buffer(o.shape, o.dtype, name="O", offset_factor=1, strides=[strideC1, strideC2, strideC3, 1])


    def intrin_func(ins, outs):
        aa, ww = ins
        cc = outs[0]


        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    name_function,
                    cc.access_ptr("w"),
                    aa.access_ptr("r"),
                    ww.access_ptr("r"),
                    X,
                    W,
                    Y,
                    H,
                    C,
                    F,
                )
            )
            return ib.get()

        def _reduce_reset():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    "ttile_conv2d_reset",
                    cc.access_ptr("w"),
                    F,
                    X,
                    Y,
                    cc.strides[1],
                    cc.strides[2],
                )
            )
            return ib.get()

        def _reduce_update():
            return _body()

        return _body(), _reduce_reset(), _reduce_update()

    return te.decl_tensor_intrin(o.op, intrin_func, binds={a: Ab, w: Ww, o: Oo})

def conv2d_ttile_1kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h, option_compilation, files):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = height // stride_h
    out_w = width // stride_w

    Out1 = te.compute(
        (batch_size, out_w, out_h, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w, stride_h * yy + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out1.op)


    locals()["axe_batch1_0"], locals()["axe_xx1_0"], locals()["axe_yy1_0"], locals()["axe_out_channels1_0"] = Out1.op.axis
    locals()["axe_in_channels1_0"], locals()["axe_h1_0"], locals()["axe_w1_0"] = Out1.op.reduce_axis


    for id_conv in [1]:
        for factor in ["factor_out_channels", "factor_yy", "factor_xx", "factor_in_channels", "factor_h", "factor_w"]:
            for nb_factor in range(len(info_tile[id_conv][factor])):
                locals()[factor + str(id_conv) + "_" + str(nb_factor)] = info_tile[id_conv][factor][nb_factor]

    for id_conv in [1]:
        for name_axe in ["out_channels", "xx", "yy", "in_channels", "h", "w"]:
            factor = "factor_" + name_axe
            for nb_factor in range(len(info_tile[id_conv][factor])):
                axe0 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor)
                axe1 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor + 1)
                locals()[axe0], locals()[axe1] = s[Out1].split(locals()[axe0], factor = locals()["factor_" + name_axe + str(id_conv) + "_" + str(nb_factor)])


    order1 = []

    order_string1 = info_tile[1]["order"]

    order1 = [locals()["axe_batch1_0"]]
    for k in order_string1:
        order1 += [locals()[k]]


    s[Out1].reorder(*order1)
    fuse1 = info_tile[1]["fuse"]

    if len(fuse1) != 0:
        if len(fuse1) > 1:
            fuse_loop1 = s[Out1].fuse(locals()[fuse1[0]], locals()[fuse1[1]])
            for k in range(2, len(fuse1)):
                fuse_loop1 = s[Out1].fuse(fuse_loop1, locals()[fuse1[k]])
        else:
            fuse_loop1 = locals()[fuse1[0]]

        s[Out1].parallel(fuse_loop1)

    # print(tvm.lower(s, [A, W, Out1], simple_mode=True))

    conv1 = intrin_conv("gen_conv", info_tile[1]["w_t"], info_tile[1]["h_t"], info_tile[1]["c_t"], info_tile[1]["f_t"], info_tile[1]["x_t"], info_tile[1]["y_t"], stride_w, stride_h)

    s[Out1].tensorize(locals()[info_tile[1]["axe_to_tensorize"]], conv1)
    s[Out1].pragma(locals()["axe_batch1_0"], "import_llvm", conv_impl(name, option_compilation, files))
    # print(tvm.lower(s, [A, W, Out1], simple_mode=True))

    return s, [A, W, Out1]

def conv2d_ttile_2kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h, option_compilation, files):

    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels1 = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h1 = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w1 = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    axe_in_channels2 = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h2 = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w2 = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = height // stride_h
    out_w = width // stride_w

    # with info_tile height and width are already / by strides
    out_h1 = info_tile[1]["height"]
    out_h2 = info_tile[2]["height"]

    size_h1 = info_tile[1]["height"]
    size_h2 = info_tile[2]["height"]

    Out1 = te.compute(
        (batch_size, out_w, out_h1, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w1, stride_h * yy + axe_kernel_h1, axe_in_channels1]* W[axe_kernel_w1, axe_kernel_h1, axe_in_channels1, out_channels],
            axis=[axe_in_channels1, axe_kernel_h1, axe_kernel_w1],)
        )
    Out2 = te.compute(
        (batch_size, out_w, out_h2, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w2, stride_h * (yy + out_h1) + axe_kernel_h2, axe_in_channels2]* W[axe_kernel_w2, axe_kernel_h2, axe_in_channels2, out_channels],
            axis=[axe_in_channels2, axe_kernel_h2, axe_kernel_w2],)
        )

    @tvm.te.hybrid.script
    def assign_output(c1, c2):
        c = output_tensor((c1.shape[0], out_w, out_h, c1.shape[3]), 'float32')
        for x in range(c1.shape[0]):
            for y in range(c1.shape[1]):
                for z in range(c1.shape[2]):
                    for t in range(c1.shape[3]):
                        c[x,y,z,t] = c1[x,y,z,t]
                for z in range(c2.shape[2]):
                    for t in range(c2.shape[3]):
                        c[x,y,z + c1.shape[2],t] = c2[x,y,z,t]
        return c
    # TODO

    # tester si avec deux A c'est mieux ou pas

    Out = assign_output(Out1, Out2)


    s = te.create_schedule(Out.op)

    n, h, out_h1, out_f1, out_h2, out_f2 = Out.op.axis

    nh = s[Out].fuse(n, h)
    s[Out].parallel(nh)
    s[Out].vectorize(out_f1)
    s[Out].vectorize(out_f2)

    locals()["axe_batch1_0"], locals()["axe_xx1_0"], locals()["axe_yy1_0"], locals()["axe_out_channels1_0"] = Out1.op.axis
    locals()["axe_in_channels1_0"], locals()["axe_h1_0"], locals()["axe_w1_0"] = Out1.op.reduce_axis

    locals()["axe_batch2_0"], locals()["axe_xx2_0"], locals()["axe_yy2_0"], locals()["axe_out_channels2_0"] = Out2.op.axis
    locals()["axe_in_channels2_0"], locals()["axe_h2_0"], locals()["axe_w2_0"] = Out2.op.reduce_axis

    for id_conv in [1, 2]:
        for factor in ["factor_out_channels", "factor_yy", "factor_xx", "factor_in_channels", "factor_h", "factor_w"]:
            for nb_factor in range(len(info_tile[id_conv][factor])):
                locals()[factor + str(id_conv) + "_" + str(nb_factor)] = info_tile[id_conv][factor][nb_factor]

    for id_conv in [1]:
        for name_axe in ["out_channels", "xx", "yy", "in_channels", "h", "w"]:
            factor = "factor_" + name_axe
            for nb_factor in range(len(info_tile[id_conv][factor])):
                axe0 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor)
                axe1 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor + 1)
                locals()[axe0], locals()[axe1] = s[Out1].split(locals()[axe0], factor = locals()["factor_" + name_axe + str(id_conv) + "_" + str(nb_factor)])

    for id_conv in [2]:
        for name_axe in ["out_channels", "xx", "yy", "in_channels", "h", "w"]:
            factor = "factor_" + name_axe
            for nb_factor in range(len(info_tile[id_conv][factor])):
                axe0 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor)
                axe1 = "axe_" + name_axe + str(id_conv) + "_" + str(nb_factor + 1)
                locals()[axe0], locals()[axe1] = s[Out2].split(locals()[axe0], factor = locals()["factor_" + name_axe + str(id_conv) + "_" + str(nb_factor)])

    order1 = []
    order2 = []

    order_string1 = info_tile[1]["order"]
    order_string2 = info_tile[2]["order"]


    order1 = [locals()["axe_batch1_0"]]
    for k in order_string1:
        order1 += [locals()[k]]

    order2 = [locals()["axe_batch2_0"]]
    for k in order_string2:
        order2 += [locals()[k]]


    s[Out1].reorder(*order1)
    s[Out2].reorder(*order2)


    fuse1 = info_tile[1]["fuse"]
    fuse2 = info_tile[2]["fuse"]


    if len(fuse1) != 0:
        if len(fuse1) > 1:
            fuse_loop1 = s[Out1].fuse(locals()[fuse1[0]], locals()[fuse1[1]])
            for k in range(2, len(fuse1)):
                fuse_loop1 = s[Out1].fuse(fuse_loop1, locals()[fuse1[k]])
        else:
            fuse_loop1 = locals()[fuse1[0]]

        s[Out1].parallel(fuse_loop1)

    if len(fuse2) != 0:
        if len(fuse2) > 1:
            fuse_loop2 = s[Out2].fuse(locals()[fuse2[0]], locals()[fuse2[1]])
            for k in range(2, len(fuse2)):
                fuse_loop2 = s[Out2].fuse(fuse_loop2, locals()[fuse2[k]])
        else:
            fuse_loop2= locals()[fuse2[0]]

        s[Out2].parallel(fuse_loop2)

    conv1 = intrin_conv("gen_conv1", info_tile[1]["w_t"], info_tile[1]["h_t"], info_tile[1]["c_t"], info_tile[1]["f_t"], info_tile[1]["x_t"], info_tile[1]["y_t"], stride_w, stride_h)
    conv2 = intrin_conv("gen_conv2", info_tile[2]["w_t"], info_tile[2]["h_t"], info_tile[2]["c_t"], info_tile[2]["f_t"], info_tile[2]["x_t"], info_tile[2]["y_t"], stride_w, stride_h)

    s[Out1].tensorize(locals()[info_tile[1]["axe_to_tensorize"]], conv1)
    s[Out1].pragma(locals()["axe_batch1_0"], "import_llvm", conv_impl(name, option_compilation, files))

    s[Out2].tensorize(locals()[info_tile[2]["axe_to_tensorize"]], conv2)

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

    return s, [A, W, Out]

def conv2d(name_conv, name_architecture, version_avx, nb_configuration, name_cpu, NUM_THREAD, lpar_methods, method_parser):

    begin_time = time.time()

    try:
        os.mkdir("results_" + method_parser)
    except FileExistsError:
        pass


    os.environ["TVM_NUM_THREADS"] = str(NUM_THREAD)
    os.environ["TVM_AFFINITY"] = str(1)


    PATH_MATMUL = os.getcwd().split("tvm")[0] + "matmul_bench/ml_utils"
    assert PATH_MATMUL == "/home/hbrunie/matmul_bench/ml_utils"

    informations_ttile = parser.parser(name_conv, name_architecture, nb_configuration, PATH_MATMUL,
            lpar_methods, method_parser, NUM_THREAD)

    search_time = time.time() - begin_time

    fname = "results_" + method_parser + "/result_" + str(NUM_THREAD) + "_" + version_avx + "_" + name_cpu + "_" + name_conv + ".csv"
    my_file = Path(fname)
    if not my_file.is_file():
        file_result = open(fname, "w")
        file_result.write("IdRun;hashkey;InfottilePickleName;MethodParallelization;NameConv;Time(ms);std;NbMicroKernel;AxeFuse1;SizeAxeFuse1;order1;AxeFuse2;SizeAxeFuse2;order2;Schema;Time_search\n")
        file_result.close()

    for id_information_ttile, information_ttile_all_method_parallelization in enumerate(informations_ttile):
        print(name_conv, "id:", id_information_ttile, float(str(round(id_information_ttile / len(informations_ttile) * 100, 2))) , "% of total")



        out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_conv]
        batch_size = 1

        if version_avx == "avx2":
            target = "llvm -mcpu=core-avx2"
            option_compilation = ["-mavx2", "-mfma"]
        else:
            target = "llvm -mcpu=skylake-avx512"
            option_compilation = ["-mavx512f", "-mfma"]

        log_file = "autotvm_conv2d.log"

        ctx = tvm.cpu()
        dtype = "float32"
        import string
        import random
        for id_method_of_parallelization, method in enumerate(lpar_methods):
            information_ttile = information_ttile_all_method_parallelization[method]
            # Log parameters into a pickle file so we can restart it later
            letters = string.ascii_letters
            hashkey = ''.join(random.choice(letters) for i in range(6))  
            pickle_filename = "pickle_files/{}_{}_{}_err.pkl".format(name_conv, hashkey, id_information_ttile)
            with open(pickle_filename, 'wb') as f:
                pickle.dump(information_ttile, f)

            if len(information_ttile) == 1:
                files = [information_ttile[1]["file"]]
                s, I = conv2d_ttile_1kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, information_ttile, stride_w, stride_h, option_compilation, files)
                A, W, Out = I
            else:
                files = [information_ttile[1]["file"], information_ttile[2]["file"]]
                s, I = conv2d_ttile_2kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, information_ttile, stride_w, stride_h, option_compilation, files)
                A, W, Out = I

            func = tvm.build(s, [A, W, Out], target=target, name="conv")


            a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
            w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)

            o = tvm.nd.array(np.ones((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype), ctx)
            oo = tvm.nd.array(np.zeros((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype), ctx)

            func(a, w, o)

            tensorize_result = o.asnumpy()

            #check result

            from tvm.topi.nn import conv2d_nhwc

            A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
            W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

            Out_test = conv2d_nhwc(A, W, stride_h, 0, 1, "float32")

            s = te.create_schedule(Out_test.op)

            f_test = tvm.build(s, [A, W, Out_test], target)
            f_test(a, w, oo)

            output_conv2d_test = oo.asnumpy()

            tvm.testing.assert_allclose(tensorize_result, output_conv2d_test, rtol=1e-3)

            # evaluate

            dtype = "float32"
            aa = np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels))
            ww = np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels))
            oo = np.zeros((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype)

            la = []
            lw = []
            lo = []

            for k in range(20):
                aa = np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels))
                ww = np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels))
                oo = np.zeros((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype)

                la += [tvm.nd.array(aa.astype(A.dtype), ctx)]
                lw += [tvm.nd.array(ww.astype(W.dtype), ctx)]
                lo += [tvm.nd.array(oo, ctx)]

            # evaluate
            results = []
            for k in range(20):
                evaluator = func.time_evaluator(func.entry_name, ctx, number=1, repeat=1)
                results += [(evaluator(la[k], lw[k], lo[k]).mean * 1e3)]

            for k in range(5):
                results.remove(max(results))
                results.remove(min(results))

            result = np.mean(results)
            std = np.std(results)

            #NbMicroKernel;AxeFuse;SizeAxeFuse;Schema
            axe_fuse1 = ",".join(information_ttile[1]["fuse"])
            size_axe_fuse1 = information_ttile[1]["size_axe_fuse"]
            schema = information_ttile[1]["schema"]

            search_time = time.time() - begin_time
            fname = "results_" + method_parser + "/result_" + str(NUM_THREAD) + "_" + version_avx + "_" + name_cpu + "_" + name_conv + ".csv"
            file_result = open(fname, "a")
            ## Build schema string
            schema_str = ""
            for x, y in schema:
                schema_str += str(x) + ":" + str(y) + ", "
            csvdump_str = None
            order1 = ",".join(information_ttile[1]["order"])
            # IdRun;hashkey;InfottilePickleName;MethodParallelization;NameConv;Time(ms);
            csvdump_str  = str(id_information_ttile) + ";" + hashkey + ";" + pickle_filename +";" 
            # MethodParallelization;NameConv;Time(ms);std;
            csvdump_str += str(id_method_of_parallelization) + ";" + name_conv + ";" + str(result) + ";" + str(std) + ";" 
            # NbMicroKernel;AxeFuse1;SizeAxeFuse1;order1;
            csvdump_str += str(len(information_ttile)) + ";" + axe_fuse1 + ";" + str(size_axe_fuse1) + ";" + order1 + ";"
            # AxeFuse2;SizeAxeFuse2;order2;
            axe_fuse2 = ""
            size_axe_fuse2 = ""
            order2 = ""
            ## Dump CSV data row for 2 kernels (Lambda)
            if len(information_ttile) != 1:
                # AxeFuse2;SizeAxeFuse2;order2;
                axe_fuse2 = ",".join(information_ttile[2]["fuse"])
                size_axe_fuse2 = str(information_ttile[2]["size_axe_fuse"])
                order2 = ",".join(information_ttile[2]["order"])
            # AxeFuse2;SizeAxeFuse2;order2;
            csvdump_str += axe_fuse2 + ";" + size_axe_fuse2 + ";" + order2 + ";"
            # Schema;Time_search
            csvdump_str += schema_str + ";" + str(search_time) + "\n"
            file_result.write(csvdump_str)
            file_result.close()
