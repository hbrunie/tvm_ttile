import numpy as np
import tvm
from tvm import te


target='opencl -device=kmppa -max_num_threads=16'
# target = "llvm"
ctx = tvm.context(target)

# The sizes of inputs and filters
batch = 12
in_channel = 100
out_channel = 100
in_size = 14
kernel = 3
pad = 1
stride = 1

# Algorithm
A = te.placeholder((in_size, in_size, in_channel, batch), name="A")
W = te.placeholder((kernel, kernel, in_channel, out_channel), name="W")
out_size = (in_size - kernel + 2 * pad) // stride + 1
# Pad input
Apad = te.compute(
    (in_size + 2 * pad, in_size + 2 * pad, in_channel, batch),
    lambda yy, xx, cc, nn: tvm.tir.if_then_else(
        tvm.tir.all(yy >= pad, yy - pad < in_size, xx >= pad, xx - pad < in_size),
        A[yy - pad, xx - pad, cc, nn],
        tvm.tir.const(0.0, "float32"),
    ),
    name="Apad",
)
# Create reduction variables
rc = te.reduce_axis((0, in_channel), name="rc")
ry = te.reduce_axis((0, kernel), name="ry")
rx = te.reduce_axis((0, kernel), name="rx")
# Compute the convolution
B = te.compute(
    (out_size, out_size, out_channel, batch),
    lambda yy, xx, ff, nn: te.sum(
        Apad[yy * stride + ry, xx * stride + rx, rc, nn] * W[ry, rx, rc, ff], axis=[ry, rx, rc]
    ),
    name="B",
)

# Designate the memory hierarchy
s = te.create_schedule(B.op)

s[Apad].compute_inline()  # compute Apad inline

# Get the GPU thread indices
block_x = te.thread_axis("blockIdx.x")
block_y = te.thread_axis("blockIdx.y")
block_z = te.thread_axis("blockIdx.z")

# Split the workloads
hi, wi, fi, ni = s[B].op.axis
bz = s[B].fuse(hi, wi)

# Bind the iteration variables to GPU thread indices
s[B].bind(bz, block_z)
s[B].bind(fi, block_y)
s[B].bind(ni, block_x)

print(tvm.lower(s, [A, W, B]))

func = tvm.build(s, [A, W, B], target)

# save the kernel
func.imported_modules[0].save("kernel1.cl")

# export test_mppa.so
# func.export_library("conv2d.so")

# Load the kernel conv2d.cl and replace the kernel
# loaded_lib = tvm.runtime.load_module("kernel_conv2d.cl")
# func.import_module(loaded_lib)

# Load the library .so 
# func = tvm.runtime.load_module("conv2d.so")


a_np = np.random.uniform(size=(in_size, in_size, in_channel, batch)).astype(A.dtype)
w_np = np.random.uniform(size=(kernel, kernel, in_channel, out_channel)).astype(W.dtype)

# a_np = np.ones((in_size, in_size, in_channel, batch), dtype="float32")
# w_np = np.ones((kernel, kernel, in_channel, out_channel), dtype="float32")

a = tvm.nd.array(a_np, ctx)
w = tvm.nd.array(w_np, ctx)
b = tvm.nd.array(np.zeros((out_size, out_size, out_channel, batch), dtype=B.dtype), ctx)
func(a, w, b)

# print(b.asnumpy())
evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
print("Convolution: %f ms" % (evaluator(a, w, b).mean * 1e3))
