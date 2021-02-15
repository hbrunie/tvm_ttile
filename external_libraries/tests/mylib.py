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

import torch
from torch import nn

batch_size = 1
height = 7
width = 7
in_channels = 50
out_channels = 50

kernel_h = 3
kernel_w = 3

pad_h = 1
pad_w = 1
stride_h = 1
stride_w = 1
dilation_h = 1
dilation_w = 1

A = te.placeholder((batch_size, in_channels, height, width), name="A")
W = te.placeholder((out_channels, in_channels, kernel_h, kernel_w), name="W")

Out = te.extern(
    (batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1),
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
ctx = tvm.cpu(0)
f = tvm.build(s, [A, W, Out], "llvm -mcpu=core-avx2")

# create A, W, Out
a = tvm.nd.array(np.random.uniform(size=(batch_size, in_channels, height, width)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(out_channels, in_channels, kernel_h, kernel_w)).astype(W.dtype), ctx)
o = tvm.nd.array(np.zeros((batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1), dtype=Out.dtype), ctx)

# Run
f(a, w, o)


## Torch ##
conv = nn.Conv2d(in_channels = in_channels, out_channels = out_channels, kernel_size = 3, stride = 1, padding = 1, bias=False)

input = torch.from_numpy(a.asnumpy())
weight = torch.from_numpy(w.asnumpy())

conv.weight.data = weight

output_torch = conv(input).detach().numpy()

# Verify the Result
tvm.testing.assert_allclose(o.asnumpy(), output_torch, rtol=1e-5)

######################################################################
# Evaluate the Result
# -----------------
#

evaluator = f.time_evaluator(f.entry_name, ctx, number=1)
print("My Convolution: %f ms" % (evaluator(a, w, o).mean * 1e3))