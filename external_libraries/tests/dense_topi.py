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

in_dim = 512

s[C].bind(s[C].op.axis[0], te.thread_axis("blockIdx.y"))
s[C].bind(s[C].op.axis[1], te.thread_axis("blockIdx.x"))

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