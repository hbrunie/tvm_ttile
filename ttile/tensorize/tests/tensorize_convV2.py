from __future__ import absolute_import, print_function

import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple

batch_size = 1
height = 32
width = 32
in_channels = 32
out_channels = 32
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

A = te.placeholder((batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1), name="A")
W = te.placeholder((out_channels, in_channels, kernel_h, kernel_w), name="W")

axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

Out = te.compute(
    (batch_size, out_channels, out_h, out_w),
    lambda batch, out_channels, yy, xx: te.sum(
        A[batch, axe_in_channels, yy * stride_h + axe_kernel_h * dilation_h, xx * stride_w + axe_kernel_w * dilation_w]* W[out_channels, axe_in_channels, axe_kernel_h, axe_kernel_w],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
s = te.create_schedule(Out.op)

# print("ici", Out.shape)

axe_batch, axe_out_channels, axe_yy, axe_xx = Out.op.axis
axe_in_channels, axe_kernel_h, axe_kernel_w = Out.op.reduce_axis

factor = 16


axe_out_channelso, axe_out_channelsi = s[Out].split(axe_out_channels, factor=factor)
axe_yyo, axe_yyi = s[Out].split(axe_yy, factor=factor)
axe_xxo, axe_xxi = s[Out].split(axe_xx, factor=factor)
axe_in_channelso, axe_in_channelsi = s[Out].split(axe_in_channels, factor=factor)
# axe_kernel_ho, axe_kernel_hi = s[Out].split(axe_kernel_h, factor=factor)
# axe_kernel_wo, axe_kernel_wi = s[Out].split(axe_kernel_w, factor=factor)

s[Out].reorder(axe_batch, axe_out_channelso, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelsi, axe_yyi, axe_xxi, axe_in_channelsi, axe_kernel_h, axe_kernel_w)
# print(tvm.lower(s, [A, W, Out], simple_mode=True))

def conv_impl():
    cc_code = """
extern "C" {
    #include <immintrin.h>
    #define SIZE_VECTOR 8

    int Mttile_conv2d(float* K, float * Input, float * Output, int W, int H, int C, int F, int X, int Y, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
        /*
        Simple Convolution

        Inputs:
            - K: weight
            - Input: Input
            - Output: Output
            - W: kernel_w
            - H: kernel_h
            - C: in_channels
            - F: out_channels
            - X: width
            - Y: height

        */
        for (int h=0; h<H; h++){
            for (int w=0; w<W; w++){
                for (int f=0; f<F; f++){
                    for (int y=0; y<Y; y++){
                        for (int x=0; x<X; x++){
                            for (int c=0; c<C; c++){
                                Output[f*strideO1 + y*strideO2 + x] += Input[c*strideA1 + (y+h)*strideA2 + x + w] * K[f * strideW1 + c * strideW2 + h*strideW3 + w];
                                //Output[f*strideO1 + y*strideO2 + x] =  0;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    int ttile_conv2d_reset(float * Output, int F, int X, int Y, int strideO1, int strideO2) {
        /*
        Simple Convolution

        Inputs:
            - Output: Output
            - F: out_channels
            - X: width, X%SIZE_VECTOR = 0
            - Y: height, Y%SIZE_VECTOR = 0

        */
        for (int f=0; f<F; f++){
            for (int y=0; y<Y; y+=2){
                for (int x=0; x<X; x+=8){
                    _mm256_store_ps(&Output[f*strideO1 + y*strideO2 + x], _mm256_setzero_ps());
                    _mm256_store_ps(&Output[f*strideO1 + (y + 1)*strideO2 + x], _mm256_setzero_ps());
                }
            }
        }
        return 0;
    }
}
    """
    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    options = ["-mavx2"]
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

    a = te.placeholder((1, C, Y + W - 1, X + H - 1), name="a")
    w = te.placeholder((F, C, H, W), name="b")
    # o = te.placeholder((1, F, Y + 2 - W, X + 2 - H), name="b")
    
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

    # print((1, F, Y + 2 - W, X + 2 - H))

    o = te.compute(
    (1, F, Y , X ),
    lambda batch, out_channels, yy, xx: te.sum(
        a[batch, axe_in_channels, yy + axe_kernel_h, xx + axe_kernel_w]* w[out_channels, axe_in_channels, axe_kernel_h, axe_kernel_w],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
    Ab = tvm.tir.decl_buffer(a.shape, a.dtype, name="A", offset_factor=1, strides=[strideA1, strideA2, strideA3, 1])
    Ww = tvm.tir.decl_buffer(w.shape, w.dtype, name="W", offset_factor=1, strides=[strideB1, strideB2, strideB3, 1])
    Oo = tvm.tir.decl_buffer(o.shape, o.dtype, name="O", offset_factor=1, strides=[strideC1, strideC2, strideC3, 1])

    def intrin_func(ins, outs):
        aa, bb = ins
        cc = outs[0]

        print(bb.strides[0],bb.strides[1],bb.strides[2])

        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "int32",
                    "Mttile_conv2d",
                    bb.access_ptr("r"),
                    aa.access_ptr("r"),
                    cc.access_ptr("w"),
                    W,
                    H,
                    C,
                    F,
                    Y,
                    X,
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



gemv = intrin_gemv(kernel_h, kernel_w, factor, factor, factor, factor)
s[Out].tensorize(axe_out_channelsi, gemv)
s[Out].pragma(axe_batch, "import_llvm", conv_impl())

# print(tvm.lower(s, [A, W, Out], simple_mode=True))

func = tvm.build(s, [A, W, Out], target="llvm -mcpu=core-avx2", name="gemv")
# a = np.ones(get_const_tuple(A.shape), dtype="float32")
# w = np.ones(get_const_tuple(W.shape), dtype="float32")
a = tvm.nd.array(np.random.uniform(size=(batch_size, in_channels,  height + kernel_h - 1, width + kernel_w - 1)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(out_channels, in_channels, kernel_h, kernel_w)).astype(W.dtype), ctx)
o = tvm.nd.array(np.ones(get_const_tuple(Out.shape), dtype=dtype), ctx)
func(tvm.nd.array(a, ctx), tvm.nd.array(w, ctx), o)
oo = np.ones(get_const_tuple(Out.shape), dtype=dtype)
# print(o)
def conv2d(weight, input_, output, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    for b in range(batch_size):
        for c in range(out_channels):
            for y in range((height + 2 * pad_h - kernel_h) // stride_h + 1):
                for x in range((width + 2 * pad_w - kernel_w) // stride_w + 1):
                    output[b, c, y, x] = 0
                    for k in range(in_channels):
                        for dy in range(kernel_h):
                            for dx in range(kernel_w):
                                output[b, c, y, x] += input_[b, k, stride_w * y + dy, stride_h * x + dx] * 1 * weight[c, k, dy, dx]
    return output

# output_conv2d = conv2d(w.asnumpy(), a.asnumpy(), oo, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
# print(output_conv2d)



# tvm.testing.assert_allclose(o.asnumpy(), output_conv2d, rtol=1e-3)

evaluator = func.time_evaluator(func.entry_name, ctx, number=50)
print("My Convolution with tensorize: %f ms" % (evaluator(a, w, o).mean * 1e3))



print("ok")

#########################################################

target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)
dtype = "float32"

A = te.placeholder((batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1), name="A")
W = te.placeholder((out_channels, in_channels, kernel_h, kernel_w), name="W")

axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

Out = te.compute(
    (batch_size, out_channels, out_h, out_w),
    lambda batch, out_channels, yy, xx: te.sum(
        A[batch, axe_in_channels, yy * stride_h + axe_kernel_h * dilation_h, xx * stride_w + axe_kernel_w * dilation_w]* W[out_channels, axe_in_channels, axe_kernel_h, axe_kernel_w],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
s = te.create_schedule(Out.op)

# print("ici", Out.shape)

axe_batch, axe_out_channels, axe_yy, axe_xx = Out.op.axis
axe_in_channels, axe_kernel_h, axe_kernel_w = Out.op.reduce_axis

factor = 16


axe_out_channelso, axe_out_channelsi = s[Out].split(axe_out_channels, factor=factor)
axe_yyo, axe_yyi = s[Out].split(axe_yy, factor=factor)
axe_xxo, axe_xxi = s[Out].split(axe_xx, factor=factor)
axe_in_channelso, axe_in_channelsi = s[Out].split(axe_in_channels, factor=factor)
# axe_kernel_ho, axe_kernel_hi = s[Out].split(axe_kernel_h, factor=factor)
# axe_kernel_wo, axe_kernel_wi = s[Out].split(axe_kernel_w, factor=factor)

s[Out].reorder(axe_batch, axe_out_channelso, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelsi, axe_yyi, axe_xxi, axe_in_channelsi, axe_kernel_h, axe_kernel_w)

func = tvm.build(s, [A, W, Out], target="llvm -mcpu=core-avx2", name="gemv")
# a = np.ones(get_const_tuple(A.shape), dtype="float32")
# w = np.ones(get_const_tuple(W.shape), dtype="float32")
a = tvm.nd.array(np.random.uniform(size=(batch_size, in_channels,  height + kernel_h - 1, width + kernel_w - 1)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(out_channels, in_channels, kernel_h, kernel_w)).astype(W.dtype), ctx)
o = tvm.nd.array(np.ones(get_const_tuple(Out.shape), dtype=dtype), ctx)
func(tvm.nd.array(a, ctx), tvm.nd.array(w, ctx), o)

evaluator = func.time_evaluator(func.entry_name, ctx, number=50)
print("My Convolution without tensorize: %f ms" % (evaluator(a, w, o).mean * 1e3))