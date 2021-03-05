import tvm
from tvm import te
import numpy as np
from tvm.contrib import graph_runtime as runtime
from tvm import relay
from tvm.relay import testing
import tvm.testing

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

data = relay.var("data", relay.TensorType((batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1), "float32"))
weight = relay.var("weight", relay.TensorType((out_channels, in_channels, kernel_h, kernel_w), "float32"))

simple_net = relay.nn.conv2d(
    data=data, weight=weight, kernel_size=(3, 3), channels=in_channels, padding=(0, 0), 
)

data_shape = (batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1)
weight_shape = (out_channels, in_channels, kernel_h, kernel_w)
net, params = testing.create_workload(simple_net)

import logging

logging.basicConfig(level=logging.DEBUG)  # to dump TVM IR after fusion

target = "llvm -libs=ttile"
lib = relay.build_module.build(net, target)

ctx = tvm.context(target, 0)
data = np.random.uniform(-1, 1, size=data_shape).astype("float32")
weight = np.random.uniform(-1, 1, size=weight_shape).astype("float32")
module = runtime.GraphModule(lib["default"](ctx))

module.set_input(data=data)
module.set_input(weight=weight)

out_shape = (batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1)

module.run()

out = module.get_output(0, tvm.nd.empty(out_shape))
output_ttile = out.asnumpy()


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

output_numpy = np.zeros((batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1), dtype="float32")

conv2d(weight, data, output_numpy, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, 1, 1, stride_h, stride_w, dilation_h, dilation_w)

tvm.testing.assert_allclose(output_ttile, output_numpy, rtol=1e-5)
