from __future__ import absolute_import, print_function
from scipy import signal
import tvm
from tvm import te
import numpy as np
import tvm.testing
import scipy
from tvm import relay
from tvm import topi
from tvm import te
from tvm.relay import testing
from tvm.topi.utils import get_const_tuple

log_file = "autotvm_conv2d.log"
target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)
dtype = "float32"

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

print(tvm.lower(s, [A, W, Out]))

######################################################################
# Verify the Result 
# -----------------
# We can verify that the result matches what we expected.
#

## TVM ##
f = tvm.build(s, [A, W, Out], target)

# create A, W, Out

a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)
o = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)
oo = tvm.nd.array(np.zeros(get_const_tuple(Out.shape), dtype=dtype), ctx)


# Run
f(a, w, o)

result_external = o.asnumpy()


## Conv2d ##
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

output_conv2d = conv2d(w.asnumpy(), a.asnumpy(), oo.asnumpy(), batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)


# Verify the Result
tvm.testing.assert_allclose(result_external, output_conv2d, rtol=1e-5)

######################################################################
# Evaluate the Result
# -----------------
#

evaluator = f.time_evaluator(f.entry_name, ctx, number=10)
print("My Convolution: %f ms" % (evaluator(a, w, o).mean * 1e3))
