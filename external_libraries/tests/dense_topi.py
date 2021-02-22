import logging
import sys

import numpy as np
import tvm
from tvm import te
import tvm.testing

from tvm import autotvm
from tvm.topi.nn import dense
from tvm.topi.cuda import dense
from tvm.relay.op.strategy import *
from tvm.autotvm.task import get_config
from tvm.autotvm.task.space import SplitEntity

N, L, M = 512, 512, 512
dtype = "float32"
A = te.placeholder((N, L), name="A", dtype=dtype)
B = te.placeholder((L, M), name="B", dtype=dtype)

target='opencl -device=kmppa -max_num_threads=16'
# target='llvm'


C = tvm.topi.nn.dense(A, B)
cfg = autotvm.get_config()
s = te.create_schedule(C.op)

num_thread = 16

A, _ = C.op.input_tensors
_, in_dim = get_const_tuple(A.shape)

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

#################


f = tvm.build(s, [A, B, C], target)

ctx = tvm.context(target)
a_np = np.random.uniform(size=(N, L)).astype(np.float32)
b_np = np.random.uniform(size=(L, M)).astype(np.float32)
c_np = a_np.dot(np.transpose(b_np))

c_tvm = tvm.nd.empty(c_np.shape, ctx=ctx)
a_tvm = tvm.nd.array(a_np, ctx=ctx)
b_tvm = tvm.nd.array(b_np, ctx=ctx)
f(a_tvm, b_tvm, c_tvm)
print(c_tvm.asnumpy())
tvm.testing.assert_allclose(c_np, c_tvm.asnumpy(), rtol=1e-2)