import os

import numpy as np
import logging
import sys
import tvm
from tvm import relay, autotvm, te
import tvm.relay.testing
from tvm.autotvm.tuner import XGBTuner, GATuner, RandomTuner, GridSearchTuner
import tvm.contrib.graph_runtime as runtime
from tvm.topi.utils import get_const_tuple

#MobileNet-3
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

log_file = "autotvm_conv2d.log"
target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)
dtype="float32"

use_tuner = False
use_best = True
use_test = False

A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

@autotvm.template("conv2d_ttile_")
def conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
    out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

    Out = te.compute(
        (batch_size, out_w, out_h, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, xx + axe_kernel_w, yy  + axe_kernel_h, axe_in_channels]* W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    if use_tuner or use_best:
        #My template

        axe_batch, axe_xx, axe_yy, axe_out_channels = s[Out].op.axis
        axe_in_channels, axe_kernel_h, axe_kernel_w = s[Out].op.reduce_axis

        # get the config object
        cfg = autotvm.get_config()

        #create full tile
        cfg.define_knob("tile_in_channels", [k for k in range(1, in_channels + 1) if in_channels%k == 0])
        cfg.define_knob("tile_out_channels", [k for k in range(1, out_channels + 1) if out_channels%k == 0])
        cfg.define_knob("tile_xx", [k for k in range(1, out_w + 1) if out_w%k == 0])
        cfg.define_knob("tile_yy", [k for k in range(1, out_h + 1) if out_h%k == 0])

        cfg.define_knob("tile_kernel_h", [1, kernel_h])
        cfg.define_knob("tile_kernel_w", [1, kernel_w])


        axe_in_channelso,  axe_in_channelsi = s[Out].split(axe_in_channels, cfg["tile_in_channels"].val)
        axe_out_channelso, axe_out_channelsi = s[Out].split(axe_out_channels, cfg["tile_out_channels"].val)
        axe_yyo, axe_yyi = s[Out].split(axe_yy, cfg["tile_yy"].val)
        axe_xxo, axe_xxi = s[Out].split(axe_xx, cfg["tile_xx"].val)

        kernel_ho, kernel_hi = s[Out].split(axe_kernel_h, cfg["tile_kernel_h"].val)
        kernel_wo, kernel_wi = s[Out].split(axe_kernel_w, cfg["tile_kernel_w"].val)

        s[Out].reorder(axe_batch, axe_yyo, axe_xxo, axe_in_channelso, axe_out_channelso, axe_yyi, axe_xxi, kernel_wo, kernel_ho, kernel_wi, kernel_hi, axe_in_channelsi, axe_out_channelsi)


        # s[Out].unroll(axe_yyi)
        s[Out].unroll(axe_out_channelsi)
        s[Out].unroll(axe_in_channelsi)
        # s[Out].unroll(kernel_hi)
        # s[Out].unroll(kernel_wi)

        s[Out].vectorize(axe_out_channelsi)

        # print(tvm.lower(s, [A, W, Out]))

    else:
        
        print(tvm.lower(s, [A, W, Out]))

    return s, [A, W, Out]

if use_tuner:
    task = autotvm.task.create("conv2d_ttile_", args=(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w), target=target)
    print(task.config_space)
    print(task.flop)

    # logging config (for printing tuning log to the screen)
    logging.getLogger("autotvm").setLevel(logging.DEBUG)
    logging.getLogger("autotvm").addHandler(logging.StreamHandler(sys.stdout))

    measure_option = autotvm.measure_option(builder="local", runner=autotvm.LocalRunner(number=5))

    tuner = autotvm.tuner.XGBTuner(task)
    tuner.tune(
        n_trial=50,
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
            f = tvm.build(s, arg_bufs)
            
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
            f = tvm.build(s, arg_bufs)
            # print(f.get_source())
else:
    with tvm.target.Target(target):
        s, arg_bufs = conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
        f = tvm.build(s, arg_bufs)

out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1
a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(A.dtype), ctx)
w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(W.dtype), ctx)
o = tvm.nd.array(np.zeros(get_const_tuple((batch_size, out_w, out_h, out_channels)), dtype=dtype), ctx)
oo = tvm.nd.array(np.zeros(get_const_tuple((batch_size, out_w, out_h, out_channels)), dtype=dtype), ctx)

# Run
f(a, w, o)


tensorize_result = o.asnumpy()

evaluator = f.time_evaluator(f.entry_name, ctx, number=50)
result = evaluator(a, w, o).mean * 1e3
print("My Convolution: %f ms" % (result))
if use_tuner:
    nb_cycle = task.flop / (16 * 2) # FMA deux operations
    time_peak_perf = nb_cycle / (2.5 * 10**9) * 1000 #1000 for ms
    print("Peak Perf (GFLOPS) = ", 2.5 * 16 * 2, "Peak perf (ms)", time_peak_perf)

if use_test:
    # Conv2d ##
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
    out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1


    Out = te.extern(
        (batch_size, out_w, out_h, out_channels),
        [A, W],
        lambda ins, outs: tvm.tir.call_packed(
            "tvm.contrib.ttile.conv2d", ins[0], ins[1], outs[0], batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
        ),
        name="Out",
    )
    s = te.create_schedule(Out.op)

    ctx = tvm.cpu(0)
    func = tvm.build(s, [A, W, Out], "llvm -mcpu=core-avx2")


    f(a, w, oo)

    external_result = oo.asnumpy()

    tvm.testing.assert_allclose(tensorize_result, external_result, rtol=1e-5)

    print("ok")

    evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
    print("My Convolution with external library: %f ms" % (evaluator(a, w, oo).mean * 1e3))

    # Verify the Result
    tvm.testing.assert_allclose(o.asnumpy(), external_result, rtol=1e-5)


