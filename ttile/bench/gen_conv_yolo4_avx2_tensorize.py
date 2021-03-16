from __future__ import absolute_import, print_function

import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple
import string

batch_size = 1
height = 136
width = 136
in_channels = 64
out_channels = 128

kernel_h = 3
kernel_w = 3

pad_h = 1
pad_w = 1
stride_h = 1
stride_w = 1
dilation_h = 1
dilation_w = 1


log_file = "autotvm_conv2d.log"
target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)
dtype = "float32"

height1 = 24
height2 = height - height1

A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

axe_in_channels1 = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h1 = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w1 = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

axe_in_channels2 = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h2 = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w2 = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = height
out_h1 = height1
out_h2 = height2
out_w = width


@tvm.te.hybrid.script
def assign_output(a, b):
    c = output_tensor((a.shape[0], 136, 136, a.shape[3]), 'float32')
    for x in range(a.shape[0]):
        for y in range(a.shape[1]):
            for z in range(a.shape[2]):
                for t in range(b.shape[3]):
                    c[x,y,z,t] = a[x,y,z,t]
            for z in range(b.shape[2]):
                for t in range(b.shape[3]):
                    c[x,y,z + a.shape[2],t] = b[x,y,z,t]
    return c


Out1 = te.compute(
    (batch_size, out_w, 24, out_channels),
    lambda batch, xx, yy, out_channels: te.sum(
        A[batch, xx + axe_kernel_w1, yy  + axe_kernel_h1, axe_in_channels1]* W[axe_kernel_w1, axe_kernel_h1, axe_in_channels1, out_channels],
        axis=[axe_in_channels1, axe_kernel_h1, axe_kernel_w1],)
    )
Out2 = te.compute(
    (batch_size, out_w, out_h - 24, out_channels),
    lambda batch, xx, yy, out_channels: te.sum(
        A[batch, xx + axe_kernel_w2, yy + 24 + axe_kernel_h2, axe_in_channels2]* W[axe_kernel_w2, axe_kernel_h2, axe_in_channels2, out_channels],
        axis=[axe_in_channels2, axe_kernel_h2, axe_kernel_w2],)
    )

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

factor_out_channels1 = 16
factor_yy1 = 24
factor_xx1 = 1
factor_in_channels1 = in_channels

factor_out_channels2 = 16
factor_yy2 = 28
factor_xx2 = 1
factor_in_channels2 = in_channels


axe_in_channelso1, axe_in_channelsi1 = s[Out1].split(axe_in_channels1, factor=factor_in_channels1)
axe_out_channelso1, axe_out_channelsi1 = s[Out1].split(axe_out_channels1, factor=factor_out_channels1)
axe_yyo1, axe_yyi1 = s[Out1].split(axe_yy1, factor=factor_yy1)
axe_xxo1, axe_xxi1 = s[Out1].split(axe_xx1, factor=factor_xx1)

axe_in_channelso2, axe_in_channelsi2 = s[Out2].split(axe_in_channels2, factor=factor_in_channels2)
axe_out_channelso2, axe_out_channelsi2 = s[Out2].split(axe_out_channels2, factor=factor_out_channels2)
axe_yyo2, axe_yyi2 = s[Out2].split(axe_yy2, factor=factor_yy2)
axe_xxo2, axe_xxi2 = s[Out2].split(axe_xx2, factor=factor_xx2)

s[Out1].reorder(axe_batch1, axe_yyo1, axe_xxo1, axe_in_channelso1, axe_out_channelso1, axe_yyi1, axe_kernel_h1, axe_kernel_w1, axe_xxi1, axe_in_channelsi1, axe_out_channelsi1)
s[Out2].reorder(axe_batch2, axe_yyo2, axe_xxo2, axe_in_channelso2, axe_out_channelso2, axe_yyi2, axe_kernel_h2, axe_kernel_w2, axe_xxi2, axe_in_channelsi2, axe_out_channelsi2)


xxyy1 = s[Out1].fuse(axe_yyo1, axe_xxo1)
s[Out1].parallel(xxyy1)

xxyy2 = s[Out2].fuse(axe_yyo2, axe_xxo2)
s[Out2].parallel(xxyy2)

# print(tvm.lower(s, [A,W,Out]))


def generate_ttile_conv2d():


    cc_code_begin = """
extern "C" {
    """

    file_ = open("gen_conv_yolo4_avx2_tensorize.c", "r")
    cc_code_midle = file_.read()
    file_.close()

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




def conv_impl():

    cc_code = generate_ttile_conv2d()


    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    options = ["-mavx2", "-mfma"]#, "-O3"]
    # Create LLVM ir from c source code
    ll_code = clang.create_llvm(cc_code, output=ll_path, options=options)
    return ll_code

    

def intrin_gemv1(W, H, C, F, X, Y):

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
        aa, bb = ins
        cc = outs[0]


        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    "Yolo_ttile_conv2d1",
                    bb.access_ptr("r"),
                    aa.access_ptr("r"),
                    cc.access_ptr("w"),
                    W,
                    H,
                    C,
                    F,
                    X,
                    Y,
                    cc.strides[1],
                    cc.strides[2],
                    aa.strides[1],
                    aa.strides[2],
                    bb.strides[0],
                    bb.strides[1],
                    bb.strides[2],
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


def intrin_gemv2(W, H, C, F, X, Y):

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
        aa, bb = ins
        cc = outs[0]


        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    "Yolo_ttile_conv2d2",
                    bb.access_ptr("r"),
                    aa.access_ptr("r"),
                    cc.access_ptr("w"),
                    W,
                    H,
                    C,
                    F,
                    X,
                    Y,
                    cc.strides[1],
                    cc.strides[2],
                    aa.strides[1],
                    aa.strides[2],
                    bb.strides[0],
                    bb.strides[1],
                    bb.strides[2],
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


conv1 = intrin_gemv1(kernel_h, kernel_w, factor_in_channels1, factor_out_channels1, factor_xx1, factor_yy1)
conv2 = intrin_gemv2(kernel_h, kernel_w, factor_in_channels2, factor_out_channels2, factor_xx2, factor_yy2)

s[Out1].tensorize(axe_yyi1, conv1)
s[Out1].pragma(axe_batch1, "import_llvm", conv_impl())

s[Out2].tensorize(axe_yyi2, conv2)
# s[Out1].pragma(axe_batch1, "import_llvm", conv_impl())

print(tvm.lower(s, [A, W, Out], simple_mode=True))


func = tvm.build(s, [A, W, Out], target="llvm -mcpu=core-avx2", name="conv")
# func2 = tvm.build(s2, [A2, W, Out2], target="llvm -mcpu=core-avx2", name="conv2")



a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)

# a = tvm.nd.array(np.ones((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), dtype="float32"), ctx)
# w = tvm.nd.array(np.ones((kernel_w, kernel_h, in_channels, out_channels), dtype="float32"), ctx)
o = tvm.nd.array(np.zeros((batch_size, width, height, out_channels), dtype=dtype), ctx)
oo = tvm.nd.array(np.zeros((batch_size, width, height, out_channels), dtype=dtype), ctx)

func(a, w, o)

tensorize_result = o.asnumpy()


evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
print("My Convolution with tensorize: %f ms" % (evaluator(a, w, o).mean * 1e3))

#########################################
# With Library
#########################################

A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1



Out = te.extern(
    (batch_size, width, height, out_channels),
    [A, W],
    lambda ins, outs: tvm.tir.call_packed(
        "tvm.contrib.ttile.conv2d", ins[0], ins[1], outs[0], batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
    ),
    name="Out",
)
s = te.create_schedule(Out.op)


ctx = tvm.cpu(0)
f = tvm.build(s, [A, W, Out], "llvm -mcpu=core-avx2")
f(a, w, oo)
external_result = oo.asnumpy()

tvm.testing.assert_allclose(tensorize_result, external_result, rtol=1e-5)

print("ok")

evaluator = f.time_evaluator(f.entry_name, ctx, number=10)
print("My Convolution with external library: %f ms" % (evaluator(a, w, o).mean * 1e3))

