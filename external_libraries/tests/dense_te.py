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

        cfg = autotvm.get_config() ##### TODO ici le pb

        in_dim = 512
        cfg.define_split("tile_k", in_dim, num_outputs=2)
        if cfg.is_fallback:
            cfg["tile_k"] = SplitEntity([-1, num_thread] if in_dim > num_thread else [1, num_thread])

        _, kf = cfg["tile_k"].apply(s, C, C.op.reduce_axis[0])
        CF = s.rfactor(C, kf)

        if C.op in s.outputs:
            Out = C
        else:
            Out = s.outputs[0].output(0)
            s[C].compute_at(s[Out], s[Out].op.axis[1])
        s[Out].bind(s[Out].op.axis[0], te.thread_axis("blockIdx.y"))
        s[Out].bind(s[Out].op.axis[1], te.thread_axis("blockIdx.x"))

        tx = s[C].op.reduce_axis[0]
        thread_x = te.thread_axis("threadIdx.x")
        s[C].bind(tx, thread_x)
        s[CF].compute_at(s[C], tx)
        s[C].set_store_predicate(thread_x.var.equal(0))
        s[Out].set_store_predicate(thread_x.var.equal(0))

        tx = s[C].op.reduce_axis[0]
        thread_x = te.thread_axis("threadIdx.x")
        s[C].bind(tx, thread_x)
        s[CF].compute_at(s[C], tx)
        s[C].set_store_predicate(thread_x.var.equal(0))
        s[Out].set_store_predicate(thread_x.var.equal(0))

    return s, [A, B, C]


N, L, M = 512, 512, 512
dtype = "float32"

# target='opencl -device=kmppa -max_num_threads=16'
target='llvm'


with tvm.target.Target(target):
    s, arg_bufs = dense(N, L, M, "float32", target)
    func = tvm.build(s, arg_bufs)

##################

#INPUTS
a_np = np.random.uniform(size=(N, L)).astype(np.float32)
b_np = np.random.uniform(size=(L, M)).astype(np.float32)
c_np = a_np.dot(np.transpose(b_np))

#TEST THE RESULT
c_tvm = tvm.nd.empty(c_np.shape)
func(tvm.nd.array(a_np), tvm.nd.array(b_np), c_tvm)
print(c_tvm.asnumpy())
tvm.testing.assert_allclose(c_np, c_tvm.asnumpy(), rtol=1e-2)