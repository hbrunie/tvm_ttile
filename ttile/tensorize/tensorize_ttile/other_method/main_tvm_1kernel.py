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

# HOME = "/root"
HOME = "/home/colo"


def conv2d_ttile_1kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = height // stride_h
    out_w = width // stride_w

    Out = te.compute(
        (batch_size, out_w, out_h, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w, stride_h * yy + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    

    locals()["axe_batch_0"], locals()["axe_xx_0"], locals()["axe_yy_0"], locals()["axe_out_channels_0"] = Out.op.axis
    locals()["axe_in_channels_0"], locals()["axe_h_0"], locals()["axe_w_0"] = Out.op.reduce_axis


    for id_conv in [1]:
        for factor in ["factor_out_channels", "factor_yy", "factor_xx", "factor_in_channels", "factor_h", "factor_w"]:
            for nb_factor in range(len(info_tile[id_conv][factor])):
                locals()[factor + "_" + str(nb_factor)] = info_tile[id_conv][factor][nb_factor]

    for id_conv in [1]:
        for name_axe in ["out_channels", "xx", "yy", "in_channels", "h", "w"]:
            factor = "factor_" + name_axe
            for nb_factor in range(len(info_tile[id_conv][factor])):
                axe0 = "axe_" + name_axe + "_" + str(nb_factor)
                axe1 = "axe_" + name_axe  + "_" + str(nb_factor + 1)
                locals()[axe0], locals()[axe1] = s[Out].split(locals()[axe0], factor = locals()["factor_" + name_axe  + "_" + str(nb_factor)])

    order1 = []

    order_string1 = info_tile[1]["order"]

    order1 = [locals()["axe_batch_0"]]
    for k in order_string1:
        order1 += [locals()[k]]


    s[Out].reorder(*order1)

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

    fuse1 = info_tile[1]["fuse"]

    if len(fuse1) != 0:

        try:
            fuse_loop1 = s[Out].fuse(locals()[fuse1[0]], locals()[fuse1[1]])
            for k in range(2, len(fuse1)):
                try: 
                    fuse_loop1 = s[Out].fuse(fuse_loop1, locals()[fuse1[k]])
                except:
                    continue
        except:
            fuse_loop1 = locals()[fuse1[0]]

        s[Out].parallel(fuse_loop1)

    s[Out].unroll(order1[-2])
    s[Out].unroll(order1[-1])

    s[Out].vectorize(order1[-1])


    return s, [A, W, Out]



if __name__ == '__main__':

    try:
        os.mkdir("old_c_files")
    except FileExistsError:
        pass

    try:
        os.mkdir("c_files")
    except FileExistsError:
        pass

    try:
        os.mkdir("tensorize_files")
    except FileExistsError:
        pass

    name_conv = sys.argv[1]
    archi = sys.argv[2]
    runs = int(sys.argv[3])


    out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_conv]
    batch_size = 1

    if archi == "avx2":
        target = "llvm -mcpu=core-avx2"
        option_compilation = ["-mavx2", "-mfma"]#, "-O3"]
    else:
        target = "llvm -mcpu=skylake-avx512"
        option_compilation = ["-mavx512f", "-mfma"]#, "-O3"]

    log_file = "autotvm_conv2d.log"
    ctx = tvm.context(target)
    dtype = "float32"

    info_tile = parser.parser(name_conv, stride_h)

    #TODO change that...
    if len(info_tile) == 2:
        # I have problem of name if len(info_tile) == 2 
        o = info_tile[1]["order"]
        f = info_tile[1]["fuse"]
        at = info_tile[1]["axe_to_tensorize"]

        for k in range(len(o)):
            l = o[k].split("_")
            l[-2] = l[-2][:-1]
            o[k] = "_".join(l)

        for k in range(len(f)):
            l = f[k].split("_")
            l[-2] = l[-2][:-1]
            f[k] = "_".join(l)

        l = at.split("_")
        l[-2] = l[-2][:-1]
        at = "_".join(l)


        info_tile[1]["order"] = o
        info_tile[1]["fuse"] = f
        info_tile[1]["axe_to_tensorize"] = at

    s, I = conv2d_ttile_1kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h)
    A, W, Out = I

    func = tvm.build(s, [A, W, Out], target=target, name="conv")

    a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
    w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)

    o = tvm.nd.array(np.zeros((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype), ctx)
    oo = tvm.nd.array(np.zeros((batch_size, width // stride_h, height // stride_h, out_channels), dtype=dtype), ctx)

    func(a, w, o)

    tensorize_result = o.asnumpy()

    # evaluate
    evaluator = func.time_evaluator(func.entry_name, ctx, number=3, repeat=10)

    results = [(evaluator(a, w, o).mean * 1e3)]
    #check result

    from tvm.topi.nn import conv2d_nhwc

    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    Out_test = conv2d_nhwc(A, W, stride_h, 0, 1, "float32")

    s = te.create_schedule(Out_test.op)

    f_test = tvm.build(s, [A, W, Out_test], target)
    f_test(a, w, oo)

    output_conv2d_test = oo.asnumpy()


    tvm.testing.assert_allclose(tensorize_result, output_conv2d_test, rtol=1e-5)

    for k in range(19):
        results += [float(os.popen("python3.8 run_tvm_1kernel.py " + name_conv + " " + archi).read())]

    for k in range(5):
        results.remove(max(results))
        results.remove(min(results))

    result = np.mean(results)
    std = np.std(results)


    file_ = open("result_tvm_1kernel.csv", "a")
    file_.write(str(runs) + ";" + name_conv + ";" + str(result) + ";" + str(std) + ";" + str(len(info_tile)) + "\n")
    file_.close()

    os.system("cp c_files/" + name_conv + ".c old_c_files/" + name_conv + "__" + str(runs) + ".c" )
    if len(info_tile) == 1:
        os.system("cp tensorize_files/" + name_conv + ".c old_c_files/" + name_conv + "_tensorize__" + str(runs) + ".c" )
    else:
        os.system("cp tensorize_files/" + name_conv + "1.c old_c_files/" + name_conv + "1_tensorize__" + str(runs) + ".c" )
        os.system("cp tensorize_files/" + name_conv + "2.c old_c_files/" + name_conv + "2_tensorize__" + str(runs) + ".c" )


