from __future__ import absolute_import, print_function

import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple
import string

batch_size = 1
height = 56
width = 56
in_channels = 128
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

A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

Out = te.compute(
    (batch_size, out_w, out_h, out_channels),
    lambda batch, xx, yy, out_channels: te.sum(
        A[batch, xx + axe_kernel_w, yy  + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
s = te.create_schedule(Out.op)


axe_batch, axe_xx, axe_yy, axe_out_channels = Out.op.axis
axe_in_channels, axe_kernel_h, axe_kernel_w = Out.op.reduce_axis

axe_out_channelso, axe_out_channelsi = s[Out].split(axe_out_channels, factor=out_channels)
axe_yyo, axe_yyi = s[Out].split(axe_yy, factor=out_h)
axe_xxo, axe_xxi = s[Out].split(axe_xx, factor=out_w)
axe_in_channelso, axe_in_channelsi = s[Out].split(axe_in_channels, factor=in_channels)

s[Out].reorder(axe_batch, axe_out_channelso, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelsi, axe_yyi, axe_xxi, axe_in_channelsi, axe_kernel_h, axe_kernel_w)
# print(tvm.lower(s, [A, W, Out], simple_mode=True))

def generate_ttile_conv2d():


    cc_code_begin = """
extern "C" {
    """

    file_ = open("convV1.c", "r")
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

    

def intrin_gemv(W, H, C, F, X, Y):

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
                    "int32",
                    "MMttile_conv2d",
                    bb.access_ptr("r"),
                    aa.access_ptr("r"),
                    cc.access_ptr("w"),
                    W,
                    H,
                    C,
                    F,
                    Y,
                    X,
                )
            )
            return ib.get()

        def _reduce_reset():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "int32", 
                    "ttile_conv2d_reset", 
                    cc.access_ptr("w"), 
                    F,
                    Y,
                    X,
                    cc.strides[1],
                    cc.strides[2],
                )
            )
            return ib.get()

        def _reduce_update():
            return _body()

        return _body(), _reduce_reset(), _reduce_update()

    return te.decl_tensor_intrin(o.op, intrin_func, binds={a: Ab, w: Ww, o: Oo})


gemv = intrin_gemv(kernel_h, kernel_w, in_channels, out_channels, width, height)
s[Out].tensorize(axe_out_channelsi, gemv)
s[Out].pragma(axe_batch, "import_llvm", conv_impl())

print(tvm.lower(s, [A, W, Out], simple_mode=True))


func = tvm.build(s, [A, W, Out], target="llvm -mcpu=core-avx2", name="conv")

a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)
o = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)
func(a, w, o)

tensorize_result = o.asnumpy()


A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")



axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1


Out = te.extern(
    (batch_size, out_w, out_h, out_channels),
    [A, W],
    lambda ins, outs: tvm.tir.call_packed(
        "tvm.contrib.ttile.conv2d", ins[0], ins[1], outs[0], batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
    ),
    name="Out",
)
s = te.create_schedule(Out.op)

o = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)

ctx = tvm.cpu(0)
f = tvm.build(s, [A, W, Out], "llvm -mcpu=core-avx2")

oo = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)

f(a, w, oo)

external_result = oo.asnumpy()

tvm.testing.assert_allclose(tensorize_result, external_result, rtol=1e-5)


o = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)
def conv2d(weight, input_, output, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    for b in range(batch_size):
        for c in range(out_channels):
            for y in range((height + 2 * pad_h - kernel_h) // stride_h + 1):
                for x in range((width + 2 * pad_w - kernel_w) // stride_w + 1):
                    output[b, x, y, c] = 0
                    for k in range(in_channels):
                        for dy in range(kernel_h):
                            for dx in range(kernel_w):
                                output[b, x, y, c] += input_[b, stride_h * x + dx, stride_w * y + dy, k] * weight[dx, dy, k, c]
    return output

# output_conv2d = conv2d(w.asnumpy(), a.asnumpy(), o.asnumpy(), batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)

evaluator = f.time_evaluator(f.entry_name, ctx, number=50)
print("My Convolution with external library: %f ms" % (evaluator(a, w, o).mean * 1e3))


# tvm.testing.assert_allclose(output_conv2d, external_result, rtol=1e-5)