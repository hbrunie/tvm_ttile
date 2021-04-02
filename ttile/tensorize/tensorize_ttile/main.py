import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple
import string
import input_conv
import parser
import sys



def generate_ttile_conv2d(name_file, number_of_file):

    cc_code_begin = """
extern "C" {
    """

    if number_of_file == 1:
        file_ = open("tensorize_files/" + name_file + ".c", "r")
        cc_code_midle = file_.read()
        file_.close()
    else:
        file_ = open("tensorize_files/" + name_file + "1.c", "r")
        cc_code_midle1 = file_.read()
        file_.close()
        file_ = open("tensorize_files/" + name_file + "2.c", "r")
        cc_code_midle2 = file_.read()
        file_.close()
        cc_code_midle = cc_code_midle1 + cc_code_midle2


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


def conv_impl(name_file, number_of_file):

    cc_code = generate_ttile_conv2d(name_file, number_of_file)
    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    options = option_compilation
    # Create LLVM ir from c source code
    ll_code = clang.create_llvm(cc_code, output=ll_path, options=options)
    return ll_code



def intrin_conv(name_function, W, H, C, F, X, Y):

    """
    W = kernel_w,
    H = kernel_h,
    C = in_channels,
    F = out_channels,
    X = width,
    Y = height
    """

    a = te.placeholder((1, X + H - 1, Y + W - 1, C), name="a")
    w = te.placeholder((W, H, C, F), name="b")

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
        a[batch, xx + axe_kernel_w, yy  + axe_kernel_h, axe_in_channels]* w[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
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
                    cc.strides[1],
                    cc.strides[2],
                    aa.strides[1],
                    aa.strides[2],
                    ww.strides[0],
                    ww.strides[1],
                    ww.strides[2],
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




def conv2d_ttile_1kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile):
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
            A[batch, xx + axe_kernel_w, yy  + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    axe_batch, axe_xx, axe_yy, axe_out_channels = Out.op.axis
    axe_in_channels, axe_kernel_h, axe_kernel_w = Out.op.reduce_axis

    factor_out_channels = info_tile[1]["factor_out_channels"]
    factor_yy = info_tile[1]["factor_yy"]
    factor_xx = info_tile[1]["factor_xx"]
    factor_in_channels = info_tile[1]["factor_in_channels"]

    axe_in_channelso, axe_in_channelsi = s[Out].split(axe_in_channels, factor=factor_in_channels)
    axe_out_channelso, axe_out_channelsi = s[Out].split(axe_out_channels, factor=factor_out_channels)
    axe_yyo, axe_yyi = s[Out].split(axe_yy, factor=factor_yy)
    axe_xxo, axe_xxi = s[Out].split(axe_xx, factor=factor_xx)

    dic_order = {
        "axe_yyo":axe_yyo,
        "axe_yyi": axe_yyi,
        "axe_xxo":axe_xxo,
        "axe_xxi": axe_xxi,
        "axe_in_channelso":axe_in_channelso,
        "axe_in_channelsi": axe_in_channelsi,
        "axe_out_channelso":axe_out_channelso,
        "axe_out_channelsi": axe_out_channelsi,
        "axe_kernel_ho": axe_kernel_h,
        "axe_kernel_wo": axe_kernel_w,
    }

    order_string = info_tile[1]["order"]
    order = [axe_batch]
    for k in order_string:
        order += [dic_order[k]]
    order += [axe_out_channelsi]

    s[Out].reorder(*order)

    fuse_loop = []

    if info_tile[1]["nb_loop_no_tensorize"] == 0:
        return s, [A, W, Out]
    else: 
        fuse_loop += [order[k] for k in range(1, info_tile[1]["nb_loop_no_tensorize"])]

    fuse_loop = s[Out].fuse(*fuse_loop)
    s[Out].parallel(fuse_loop)

    conv = intrin_conv("gen_conv", kernel_h, kernel_w, factor_in_channels, factor_out_channels, factor_xx, factor_yy)
    
    s[Out].tensorize(dic_order[info_tile[1]["axe_to_tensorize"]], conv)
    s[Out].pragma(axe_batch, "import_llvm", conv_impl(name, len(info_tile)))

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

    return s, [A, W, Out]



def conv2d_ttile_2kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile):

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

    out_h1 = info_tile[1]["height"] // stride_h
    out_h2 = info_tile[2]["height"] // stride_h

    Out1 = te.compute(
        (batch_size, out_w, out_h1, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, xx + axe_kernel_w1, yy  + axe_kernel_h1, axe_in_channels1]* W[axe_kernel_w1, axe_kernel_h1, axe_in_channels1, out_channels],
            axis=[axe_in_channels1, axe_kernel_h1, axe_kernel_w1],)
        )
    Out2 = te.compute(
        (batch_size, out_w, out_h2, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, xx + axe_kernel_w2, yy + 24 + axe_kernel_h2, axe_in_channels2]* W[axe_kernel_w2, axe_kernel_h2, axe_in_channels2, out_channels],
            axis=[axe_in_channels2, axe_kernel_h2, axe_kernel_w2],)
        )

    @tvm.te.hybrid.script
    def assign_output(c1, c2):
        c = output_tensor((c1.shape[0], height, width, c1.shape[3]), 'float32')
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

    axe_batch1, axe_xx1, axe_yy1, axe_out_channels1 = Out1.op.axis
    axe_in_channels1, axe_kernel_h1, axe_kernel_w1 = Out1.op.reduce_axis

    axe_batch2, axe_xx2, axe_yy2, axe_out_channels2 = Out2.op.axis
    axe_in_channels2, axe_kernel_h2, axe_kernel_w2 = Out2.op.reduce_axis

    factor_out_channels1 = info_tile[1]["factor_out_channels"]
    factor_yy1 = info_tile[1]["factor_yy"]
    factor_xx1 = info_tile[1]["factor_xx"]
    factor_in_channels1 = info_tile[1]["factor_in_channels"]

    factor_out_channels2 = info_tile[2]["factor_out_channels"]
    factor_yy2 = info_tile[2]["factor_yy"]
    factor_xx2 = info_tile[2]["factor_xx"]
    factor_in_channels2 = info_tile[2]["factor_in_channels"]

    axe_in_channels1o, axe_in_channels1i = s[Out1].split(axe_in_channels1, factor=factor_in_channels1)
    axe_out_channels1o, axe_out_channels1i = s[Out1].split(axe_out_channels1, factor=factor_out_channels1)
    axe_yy1o, axe_yy1i = s[Out1].split(axe_yy1, factor=factor_yy1)
    axe_xx1o, axe_xx1i = s[Out1].split(axe_xx1, factor=factor_xx1)

    axe_in_channels2o, axe_in_channels2i = s[Out2].split(axe_in_channels2, factor=factor_in_channels2)
    axe_out_channels2o, axe_out_channels2i = s[Out2].split(axe_out_channels2, factor=factor_out_channels2)
    axe_yy2o, axe_yy2i = s[Out2].split(axe_yy2, factor=factor_yy2)
    axe_xx2o, axe_xx2i = s[Out2].split(axe_xx2, factor=factor_xx2)

    dic_order = {
        "axe_yy1o":axe_yy1o,
        "axe_yy1i": axe_yy1i,
        "axe_xx1o":axe_xx1o,
        "axe_xx1i": axe_xx1i,
        "axe_in_channels1o":axe_in_channels1o,
        "axe_in_channels1i": axe_in_channels1i,
        "axe_out_channels1o":axe_out_channels1o,
        "axe_out_channels1i": axe_out_channels1i,
        "axe_kernel_h1o": axe_kernel_h1,
        "axe_kernel_w1o": axe_kernel_w1,

        "axe_yy2o":axe_yy2o,
        "axe_yy2i": axe_yy2i,
        "axe_xx2o":axe_xx2o,
        "axe_xx2i": axe_xx2i,
        "axe_in_channels2o":axe_in_channels2o,
        "axe_in_channels2i": axe_in_channels2i,
        "axe_out_channels2o":axe_out_channels2o,
        "axe_out_channels2i": axe_out_channels2i,
        "axe_kernel_h2o": axe_kernel_h2,
        "axe_kernel_w2o": axe_kernel_w2,
    }

    order1 = []
    order2 = []

    order_string1 = info_tile[1]["order"]
    order_string2 = info_tile[2]["order"]

    order1 = [axe_batch1]
    for k in order_string1:
        order1 += [dic_order[k]]
    order1 += [axe_out_channels1i]

    order2 = [axe_batch2]
    for k in order_string2:
        order2 += [dic_order[k]]
    order2 += [axe_out_channels2i]

    s[Out1].reorder(*order1)
    s[Out2].reorder(*order2)

    fuse_loop1 = []
    fuse_loop2 = []

    if info_tile[1]["nb_loop_no_tensorize"] == 0:
        return s, [A, W, Out]
    else: 
        fuse_loop1 += [order1[k] for k in range(1, info_tile[1]["nb_loop_no_tensorize"])]

    if info_tile[2]["nb_loop_no_tensorize"] == 0:
        return s, [A, W, Out]
    else: 
        fuse_loop2 += [order2[k] for k in range(1, info_tile[2]["nb_loop_no_tensorize"])]

    fuse_loop1 = s[Out1].fuse(*fuse_loop1)
    fuse_loop2 = s[Out2].fuse(*fuse_loop2)


    s[Out1].parallel(fuse_loop1)
    s[Out2].parallel(fuse_loop2)

    conv1 = intrin_conv("gen_conv1", kernel_h, kernel_w, factor_in_channels1, factor_out_channels1, factor_xx1, factor_yy1)
    conv2 = intrin_conv("gen_conv2", kernel_h, kernel_w, factor_in_channels2, factor_out_channels2, factor_xx2, factor_yy2)

    s[Out1].tensorize(dic_order[info_tile[1]["axe_to_tensorize"]], conv1)
    s[Out1].pragma(axe_batch1, "import_llvm", conv_impl(name, len(info_tile)))

    s[Out2].tensorize(dic_order[info_tile[2]["axe_to_tensorize"]], conv2)

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

    return s, [A, W, Out]




if __name__ == '__main__':

    name_conv = sys.argv[1]
    archi = sys.argv[2]

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

    info_tile = parser.parser(name_conv)

    if len(info_tile) == 1:
        s, I = conv2d_ttile_1kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile)
        A, W, Out = I
    else:
        s, I = conv2d_ttile_2kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile)
        A, W, Out = I

    func = tvm.build(s, [A, W, Out], target=target, name="conv")



    a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
    w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)

    # a = tvm.nd.array(np.ones((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), dtype="float32"), ctx)
    # w = tvm.nd.array(np.ones((kernel_w, kernel_h, in_channels, out_channels), dtype="float32"), ctx)
    o = tvm.nd.array(np.zeros((batch_size, width, height, out_channels), dtype=dtype), ctx)
    oo = tvm.nd.array(np.zeros((batch_size, width, height, out_channels), dtype=dtype), ctx)

    func(a, w, o)

    tensorize_result = o.asnumpy()

    # evaluate
    evaluator = func.time_evaluator(func.entry_name, ctx, number=3, repeat=10)
    print("My Convolution with tensorize: %f ms" % (evaluator(a, w, o).mean * 1e3))

    #check result

    from tvm.topi.nn import conv2d_nhwc

    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    Out_test = conv2d_nhwc(A, W, stride_h, 0, 1, "float32")

    s = te.create_schedule(Out_test.op)

    f_test = tvm.build(s, [A, W, Out_test], target)
    f_test(a, w, oo)
    # evaluator = f_test.time_evaluator(f_test.entry_name, ctx, number=3, repeat=10)
    # print("TVM: %f ms" % (evaluator(a, w, o).mean * 1e3))

    output_conv2d_test = oo.asnumpy()


    tvm.testing.assert_allclose(tensorize_result, output_conv2d_test, rtol=1e-5)
