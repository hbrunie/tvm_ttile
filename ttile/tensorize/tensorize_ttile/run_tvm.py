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

def conv2d_ttile_2kernel(name, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h):

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

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

    fuse1 = info_tile[1]["fuse"]
    fuse2 = info_tile[2]["fuse"]

    if len(fuse1) != 0:

        try:
            fuse_loop1 = s[Out1].fuse(locals()[fuse1[0]], locals()[fuse1[1]])
            for k in range(2, len(fuse1)):
                try: 
                    fuse_loop1 = s[Out1].fuse(fuse_loop1, locals()[fuse1[k]])
                except:
                    continue
        except:
            fuse_loop1 = locals()[fuse1[0]]

        s[Out1].parallel(fuse_loop1)

    if len(fuse2) != 0:

        try:
            fuse_loop2 = s[Out2].fuse(locals()[fuse2[0]], locals()[fuse2[1]])
            for k in range(2, len(fuse2)):
                try: 
                    fuse_loop1 = s[Out1].fuse(fuse_loop2, locals()[fuse2[k]])
                except:
                    continue
        except:
            fuse_loop2= locals()[fuse2[0]]

        s[Out2].parallel(fuse_loop2)

    s[Out1].unroll(order1[-2])
    s[Out1].unroll(order1[-1])
    s[Out1].vectorize(order1[-1])

    s[Out2].unroll(order2[-2])
    s[Out2].unroll(order2[-1])
    s[Out2].vectorize(order2[-1])

    # print(tvm.lower(s, [A, W, Out], simple_mode=True))

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

    if len(info_tile) == 1:
        s, I = conv2d_ttile_1kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h)
        A, W, Out = I
    else:
        s, I = conv2d_ttile_2kernel(name_conv, batch_size, width, height, kernel_w, kernel_h, in_channels, out_channels, info_tile, stride_w, stride_h)
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
    print(evaluator(a, w, o).mean * 1e3)

