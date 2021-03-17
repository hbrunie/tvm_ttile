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

target = "llvm -mcpu=core-avx2"
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
    "tuner": "xgb",
    "early_stopping": None,
    "measure_option": autotvm.measure_option(
        builder=autotvm.LocalBuilder(),
        runner=autotvm.LocalRunner(
            number=1, repeat=10, min_repeat_ms=0, enable_cpu_cache_flush=True
        ),
    ),
}

# logging.basicConfig(level=logging.DEBUG)  # to dump TVM IR after fusion

def tune_kernels(tasks, measure_option, tuner="gridsearch", early_stopping=None, log_filename="log/autotvm" + name_conv + ".log"):

    for i, task in enumerate(tasks):
        prefix = "[Task " + name_conv +"]"

        # create tuner
        if tuner == "xgb" or tuner == "xgb-rank":
            tuner_obj = XGBTuner(task, loss_type="rank")
        elif tuner == "ga":
            tuner_obj = GATuner(task, pop_size=50)
        elif tuner == "random":
            tuner_obj = RandomTuner(task)
        elif tuner == "gridsearch":
            tuner_obj = GridSearchTuner(task)
        else:
            raise ValueError("Invalid tuner: " + tuner)

        # do tuning
        n_trial = len(task.config_space)
        # n_trial = 4
        tuner_obj.tune(
            n_trial=n_trial,
            early_stopping=early_stopping,
            measure_option=measure_option,
            callbacks=[
                autotvm.callback.progress_bar(n_trial, prefix=prefix),
                autotvm.callback.log_to_file(log_filename),
            ],
        )

def tune_and_evaluate(tuning_opt, mod, params, data_shape):
    # extract workloads from relay program
    tasks = autotvm.task.extract_from_program(
        mod["main"], target=target, params=params, ops=(relay.op.get("nn.conv2d"),)
    )

    # run tuning tasks
    tune_kernels(tasks, **tuning_opt)

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

    return np.mean(prof_res)


time = [tune_and_evaluate(tuning_option, net, params, data_shape)]

for k in range(19):
    time += [float(os.popen("python3 conv_NCHW_best.py " + name_conv).read())]


for k in range(5):
    time.remove(max(time))
    time.remove(min(time))

result = np.mean(time)

f = open("result/result.txt", "a")
f.write(name_conv + " " + str(result) + "\n")
f.close()

