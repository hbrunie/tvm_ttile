import tvm
from tvm import te
import numpy as np
from tvm.contrib import graph_runtime as runtime
from tvm import relay, autotvm
from tvm.relay import testing
import tvm.testing
import os
import logging
from tvm.autotvm.tuner import XGBTuner, GATuner, RandomTuner, GridSearchTuner
import sys
import input_conv
from tvm.autotvm.graph_tuner import DPTuner, PBQPTuner

name_conv = sys.argv[1]

out_channels, in_channels, height, width, kernel_h, kernel_w = input_conv.input_conv[name_conv]

batch_size = 1
pad_h = 0
pad_w = 0
stride_h = 1
stride_w = 1
dilation_h = 0
dilation_w = 0

target = "llvm -mcpu=skylake-avx512"
log_file = "log/%s.log" % name_conv
graph_opt_sch_file = "%s_graph_opt.log" % name_conv
dtype = "float32"
input_name = "data"

num_threads = 1
os.environ["TVM_NUM_THREADS"] = str(num_threads)

data = relay.var("data", relay.TensorType((batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1), "float32"))
weight = relay.var("weight", relay.TensorType((out_channels, in_channels, kernel_h, kernel_w), "float32"))
net = relay.nn.conv2d(
    data=data, weight=weight, kernel_size=(kernel_h, kernel_w), channels=in_channels, padding=(0, 0),
)

data_shape = (batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1)
weight_shape = (out_channels, in_channels, kernel_h, kernel_w)
net, params = testing.create_workload(net)

tuning_option = {
    "log_filename": log_file,
    "tuner": "random",
    "early_stopping": None,
    "measure_option": autotvm.measure_option(
        builder=autotvm.LocalBuilder(),
        runner=autotvm.LocalRunner(
            number=1, repeat=10, min_repeat_ms=0, enable_cpu_cache_flush=True
        ),
    ),
}

# logging.basicConfig(level=logging.DEBUG)  # to dump TVM IR after fusion



def evaluate(tuning_opt, mod, params, data_shape):

    with autotvm.apply_history_best(log_file):
        with tvm.transform.PassContext(opt_level=3):
            lib = relay.build_module.build(mod, target=target, params=params)

        # upload parameters to device
        ctx = tvm.cpu()
        data_tvm = tvm.nd.array((np.random.uniform(size=data_shape)).astype(dtype))
        module = runtime.GraphModule(lib["default"](ctx))
        module.set_input(input_name, data_tvm)

        # evaluate
        ftimer = module.module.time_evaluator("run", ctx, number=3, repeat=10)
        prof_res = np.array(ftimer().results) * 1000  # convert to millisecond
        print(np.mean(prof_res), end='')


evaluate(tuning_option, net, params, data_shape)
