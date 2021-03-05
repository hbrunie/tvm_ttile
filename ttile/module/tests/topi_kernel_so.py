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


target='opencl -device=kmppa -max_num_threads=16'
# target='llvm'
ctx = tvm.context(target)

loaded_lib = tvm.runtime.load_module("test_mppa.so")

ctx = tvm.context(target)
a_np = np.ones((N, L), dtype="float32")
b_np = np.ones((M, L), dtype="float32")
cc_np = np.zeros((N, M), dtype="float32")
# c_np = a_np.dot(np.transpose(b_np))

c_tvm = tvm.nd.array(cc_np, ctx=ctx)
a_tvm = tvm.nd.array(a_np, ctx=ctx)
b_tvm = tvm.nd.array(b_np, ctx=ctx)
loaded_lib(a_tvm, b_tvm, c_tvm)
print(c_tvm.asnumpy())

# tvm.testing.assert_allclose(c_np, c_tvm.asnumpy(), rtol=1e-5)