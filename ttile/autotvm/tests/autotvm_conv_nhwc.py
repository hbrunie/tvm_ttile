import numpy as np
import sys
import tvm
import logging
from tvm import relay, autotvm, te
import tvm.relay.testing
from tvm.autotvm.tuner import XGBTuner, GATuner, RandomTuner, GridSearchTuner
import tvm.contrib.graph_runtime as runtime
from tvm.topi.util import get_const_tuple

target='opencl -device=kmppa -max_num_threads=64'
# target = "llvm"
ctx = tvm.context(target)
dtype = "float32"
log_file = "autotvm_conv2d.log"

use_tuner = True
use_best = False
use_test = False
use_no = False

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

@autotvm.template("conv2d_ttile_")
def conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
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
    thread_x = te.thread_axis("threadIdx.x")
    thread_y = te.thread_axis("threadIdx.y")
    thread_z = te.thread_axis("threadIdx.z")

    axe_batch, axe_xx, axe_yy, axe_out_channels = B.op.axis
    axe_in_channels, axe_kernel_h, axe_kernel_w = B.op.reduce_axis

    # get the config object
    cfg = autotvm.get_config()

    #create full tile
    cfg.define_knob("tile_in_channels", [k for k in range(1, in_channels + 1) if in_channels%k == 0])
    cfg.define_knob("tile_out_channels", [k for k in range(1, out_channels + 1) if out_channels%k == 0])
    cfg.define_knob("tile_xx", [k for k in range(1, out_w + 1) if out_w%k == 0])
    cfg.define_knob("tile_yy", [k for k in range(1, out_h + 1) if out_h%k == 0])

    # [('tile_in_channels', 4), ('tile_out_channels', 8), ('tile_xx', 14), ('tile_yy', 2)],None,858

    # factor_out_channels = 16
    # factor_yy = 14
    # factor_xx = 1
    # factor_in_channels = in_channels




    # axe_in_channelso, axe_in_channelsi = s[B].split(axe_in_channels, factor=factor_in_channels)
    # axe_out_channelso, axe_out_channelsi = s[B].split(axe_out_channels, factor=factor_out_channels)
    # axe_yyo, axe_yyi = s[B].split(axe_yy, factor=factor_yy)
    # axe_xxo, axe_xxi = s[B].split(axe_xx, factor=factor_xx)

    axe_in_channelso,  axe_in_channelsi = s[B].split(axe_in_channels, cfg["tile_in_channels"].val)
    axe_out_channelso, axe_out_channelsi = s[B].split(axe_out_channels, cfg["tile_out_channels"].val)
    axe_yyo, axe_yyi = s[B].split(axe_yy, cfg["tile_yy"].val)
    axe_xxo, axe_xxi = s[B].split(axe_xx, cfg["tile_xx"].val)


    # s[B].bind(axe_batch, block_x)
    s[B].bind(axe_yyo, block_y)
    s[B].bind(axe_xxo, block_z)

    # s[B].bind(axe_kernel_h, thread_y)
    s[B].bind(axe_yyi, thread_y)
    s[B].bind(axe_xxi, thread_z)

    s[B].unroll(axe_yyi)
    # s[B].reorder(axe_batch, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelso, axe_yyi, axe_xxi, axe_kernel_h, axe_kernel_w, axe_in_channelsi, axe_out_channelsi)
    s[B].reorder(axe_batch, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelso, axe_xxi, axe_kernel_w, axe_kernel_h, axe_in_channelsi, axe_yyi, axe_out_channelsi)
    # s[B].unroll(axe_out_channelsi)
    s[B].vectorize(axe_out_channelsi)

    return s, [A, W, B]

if use_tuner:
    task = autotvm.task.create("conv2d_ttile_", args=(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w), target=target)
    print(task.config_space)
    print(task.flop)

    # logging config (for printing tuning log to the screen)
    logging.getLogger("autotvm").setLevel(logging.DEBUG)
    logging.getLogger("autotvm").addHandler(logging.StreamHandler(sys.stdout))

    measure_option = autotvm.measure_option(
        builder=autotvm.KLocalBuilder(timeout=10),
        runner=autotvm.KLocalRunner(number=40, repeat=2, timeout=15),)


    # Begin tuning with GATuner, log records to log_file
    tuner = autotvm.tuner.GATuner(task, pop_size=50, kmod=False)
    tuner.tune(
        n_trial=500,
        measure_option=measure_option,
        callbacks=[autotvm.callback.log_to_file(log_file)],
)

    # inspect the best config
    dispatch_context = autotvm.apply_history_best(log_file)
    best_config = dispatch_context.query(task.target, task.workload)
    print("\nBest config:")
    print(best_config)

    with autotvm.apply_history_best(log_file):
        with tvm.target.Target(target):
            s, arg_bufs = conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
            func = tvm.build(s, arg_bufs)
            
elif use_best:
    task = autotvm.task.create("conv2d_ttile_", args=(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w), target=target)
    print(task.config_space)
    print(task.flop)
    # inspect the best config
    dispatch_context = autotvm.apply_history_best(log_file)
    best_config = dispatch_context.query(task.target, task.workload)
    print("\nBest config:")
    print(best_config)

    with autotvm.apply_history_best(log_file):
        with tvm.target.Target(target):
            s, arg_bufs = conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
            func = tvm.build(s, arg_bufs)
            # print(f.get_source())


elif use_no:
    with tvm.target.Target(target):
        s, arg_bufs = conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
        func = tvm.build(s, arg_bufs)
        # print(f.get_source())

a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(dtype), ctx)
b = tvm.nd.array(np.zeros(get_const_tuple((batch_size, width, height, out_channels)), dtype=dtype), ctx)


func(a, w, b)

# print(b.asnumpy())
evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
print("Convolution: %f ms" % (evaluator(a, w, b).mean * 1e3))
