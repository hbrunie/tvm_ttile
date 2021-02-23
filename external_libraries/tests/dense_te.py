import logging
import sys

import numpy as np
import tvm
from tvm import te
import tvm.testing

# the module is called `autotvm`
from tvm import autotvm

from tvm.relay import testing

def dense(N, L, M, dtype, target):
    A = te.placeholder((N, L), name="A", dtype=dtype)
    B = te.placeholder((L, M), name="B", dtype=dtype)


    batch, in_dim = A.shape
    out_dim, _ = B.shape
    k = te.reduce_axis((0, in_dim), name="k")
    C = te.compute(
        (batch, out_dim),
        lambda i, j: te.sum(A[i, k].astype(dtype) * B[j, k].astype(dtype), axis=k),
        name="T_dense",
        tag="dense",
    )

    s = te.create_schedule(C.op)

    if target == 'opencl -device=kmppa -max_num_threads=16':

        from tvm.autotvm.task.space import SplitEntity

        num_thread = 16

        cfg = autotvm.get_config()

        in_dim = 512

        s[C].bind(s[C].op.axis[0], te.thread_axis("blockIdx.y"))
        s[C].bind(s[C].op.axis[1], te.thread_axis("blockIdx.x"))

    return s, [A, B, C]


N, L, M = 512, 512, 512
dtype = "float32"

target='opencl -device=kmppa -max_num_threads=16'
# target='llvm'


with tvm.target.Target(target):
    s, arg_bufs = dense(N, L, M, "float32", target)
    func = tvm.build(s, arg_bufs)

##################
ctx = tvm.context(target)
#INPUTS
a_np = np.random.uniform(size=(N, L)).astype(np.float32)
b_np = np.random.uniform(size=(L, M)).astype(np.float32)
c_np = a_np.dot(np.transpose(b_np))


#TEST THE RESULT
c_tvm = tvm.nd.empty(c_np.shape, ctx=ctx)
a_tvm = tvm.nd.array(a_np, ctx=ctx)
b_tvm = tvm.nd.array(b_np, ctx=ctx)
func(a_tvm, b_tvm, c_tvm)
print(c_tvm.asnumpy())
tvm.testing.assert_allclose(c_np, c_tvm.asnumpy(), rtol=1e-2)

######################################################################
# Evaluate the Result
# -----------------
#

evaluator = func.time_evaluator(func.entry_name, ctx, number=1)
print("My Convolution: %f ms" % (evaluator(a_tvm, b_tvm, c_tvm).mean * 1e3))
