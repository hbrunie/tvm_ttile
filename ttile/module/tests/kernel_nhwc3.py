import numpy as np
import tvm
from tvm import te
from tvm.topi.util import get_const_tuple

target='opencl -device=kmppa -max_num_threads=16'
# target = "llvm"
ctx = tvm.context(target)
dtype = "float32"

# The sizes of inputs and filters
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

# Algorithm
A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

B = te.compute(
    (batch_size, out_w, out_h, out_channels),
    lambda batch, xx, yy, out_channels: te.sum(
        A[batch, xx + axe_kernel_w, yy  + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )

s = te.create_schedule(B.op)

# Get the GPU thread indices
block_x = te.thread_axis("blockIdx.x")
block_y = te.thread_axis("blockIdx.y")
block_z = te.thread_axis("blockIdx.z")

# Split the workloads
ni, hi, wi, fi = s[B].op.axis
bz = s[B].fuse(hi, wi)

s[B].bind(bz, block_x)

print(tvm.lower(s, [A, W, B]))

func = tvm.build(s, [A, W, B], target)

print(func.imported_modules[0].get_source())

# save the kernel
func.imported_modules[0].save("kernel_nhwc3.cl")

# export test_mppa.so
# func.export_library("conv2d.so")

# Load the kernel conv2d.cl and replace the kernel
# loaded_lib = tvm.runtime.load_module("kernel_conv2d.cl")
# func.import_module(loaded_lib)

# Load the library .so 
# func = tvm.runtime.load_module("conv2d.so")


a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)
b = tvm.nd.array(np.zeros(get_const_tuple(B.shape), dtype=dtype), ctx)


func(a, w, b)

# print(b.asnumpy())
evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
print("Convolution: %f ms" % (evaluator(a, w, b).mean * 1e3))
