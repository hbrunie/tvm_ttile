# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
"""
External Tensor Functions
=========================
**Author**: `Tianqi Chen <https://tqchen.github.io>`_

While TVM supports transparent code generation, sometimes
it is also helpful to incorporate manual written code into
the pipeline. For example, we might want to use cuDNN for
some of the convolution kernels and define the rest of the stages.

TVM supports these black box function calls natively.
Specfically, TVM support all the tensor functions that are DLPack compatible.
Which means we can call any function with POD types(pointer, int, float)
or pointer to DLTensor as argument.
"""
from __future__ import absolute_import, print_function

import tvm
from tvm import te
import numpy as np
from tvm.contrib import cblas
import tvm.testing

from tvm import relay
from tvm.relay import testing
import tvm
from tvm import te
from tvm.contrib import graph_runtime
# save the graph, lib and params into separate files
from tvm.contrib import util
from tvm.contrib import graph_runtime as runtime

target='opencl -device=kmppa -max_num_threads=16'
# target = "llvm -libs=cblas"

n = 512
l = 512
m = 512

data = relay.var("data", relay.TensorType((n,l), "float32"))
weight = relay.var("weight", relay.TensorType((m,l), "float32"))

ctx = tvm.context(target)

# USE THE FUNCTION DENSE
C = tvm.relay.nn.dense(data=data, weight=weight)

net, params = testing.create_workload(C)
lib = relay.build_module.build(net, target)
ctx = tvm.context(target, 0)

#INIT INPUT
data_shape = (n,l)
weight_shape = (m,l)
a = tvm.nd.array(np.random.uniform(size=(n, l)).astype("float32"), ctx)
b = tvm.nd.array(np.random.uniform(size=(m, l)).astype("float32"), ctx)

module = runtime.GraphModule(lib["default"](ctx))

#PUT INPUT
module.set_input(data=a)
module.set_input(weight=b)

#RUN
module.run()
#OUT = result
out = module.get_output(0, tvm.nd.empty((n,m)))
output = out.asnumpy()
print(output)

# test if the result is correct
tvm.testing.assert_allclose(output, np.dot(a.asnumpy(),np.transpose(b.asnumpy())), rtol=1e-5)