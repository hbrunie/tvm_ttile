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


ctx = tvm.cpu(0)

# We just load the .so
f = tvm.runtime.load_module("test_mylib.so")


batch_size = 1
height = 7
width = 7
in_channels = 100
out_channels = 100

kernel_h = 3
kernel_w = 3

pad_h = 1
pad_w = 1
stride_h = 1
stride_w = 1
dilation_h = 1
dilation_w = 1

# create A, W, Out
o = tvm.nd.array(np.zeros((batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1), dtype="float32"), ctx)
# a = tvm.nd.array(np.random.uniform(size=(batch_size, in_channels,  height + kernel_h - 1, width + kernel_w - 1)).astype("float32"), ctx)
# w = tvm.nd.array(np.random.uniform(size=(out_channels, in_channels, kernel_h, kernel_w)).astype("float32"), ctx)
a = tvm.nd.array(np.ones((batch_size, in_channels,  height + kernel_h - 1, width + kernel_w - 1), dtype="float32"), ctx)
w = tvm.nd.array(np.ones((out_channels, in_channels, kernel_h, kernel_w), dtype="float32"), ctx)

# Run
f(a, w, o)


## Conv2d ##
def conv2d(weight, input, output, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    for b in range(batch_size):
        for c in range(out_channels):
            for y in range((height + 2 * pad_h - kernel_h) // stride_h + 1):
                for x in range((width + 2 * pad_w - kernel_w) // stride_w + 1):
                    output[b, c, y, x] = 0
                    for k in range(in_channels):
                        for dy in range(kernel_h):
                            for dx in range(kernel_w):
                                output[b, c, y, x] += input[b, k, stride_w * y + dy, stride_h * x + dx] * weight[c, k, dy, dx]
    return output

output_conv2d = conv2d(w.asnumpy(), a.asnumpy(), o.asnumpy(), batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)


# Verify the Result
tvm.testing.assert_allclose(o.asnumpy(), output_conv2d, rtol=1e-5)

print(output_conv2d)


print(o.asnumpy())
######################################################################
# Evaluate the Result
# -----------------
#

evaluator = f.time_evaluator(f.entry_name, ctx, number=1)
print("My Convolution: %f ms" % (evaluator(a, w, o).mean * 1e3))

