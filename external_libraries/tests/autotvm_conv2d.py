import os

import numpy as np
import logging
import sys
import tvm
from tvm import relay, autotvm, te
import tvm.relay.testing
from tvm.autotvm.tuner import XGBTuner, GATuner, RandomTuner, GridSearchTuner
import tvm.contrib.graph_runtime as runtime

#MobileNet-3
batch_size = 1
height = 56
width = 56
in_channels = 128
out_channels = 128
kernel_h = 3
kernel_w = 3

total_op = kernel_w * kernel_h * out_channels * in_channels * width * height * batch_size


pad_h = 1
pad_w = 1
stride_h = 1
stride_w = 1
dilation_h = 1
dilation_w = 1

log_file = "autotvm_conv2d.log"
target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)

use_tuner = False
use_best = True
use_test = False

@autotvm.template("conv2d_ttile_")
def conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    A = te.placeholder((batch_size, in_channels, height + kernel_h - 1, width + kernel_w - 1), name="A")
    W = te.placeholder((out_channels, in_channels, kernel_h, kernel_w), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = (height + 2 * pad_h - kernel_h) // stride_h + 1
    out_w = (width + 2 * pad_w - kernel_w) // stride_w + 1

    Out = te.compute(
        (batch_size, out_channels, out_h, out_w),
        lambda batch, out_channels, yy, xx: te.sum(
            A[batch, axe_in_channels, yy * stride_h + axe_kernel_h * dilation_h, xx * stride_w + axe_kernel_w * dilation_w]* W[out_channels, axe_in_channels, axe_kernel_h, axe_kernel_w],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    if use_tuner or use_best:
        """
        Best with TTile
        [V k; U (1, k); U (14, h); U (3, s); 
        T (128, c); T (1, w); T (3, r); T (1, s); T (1, h); T (8, k); T (1, c); T (56, w); T (4, h)]  
        Trad:
            k ou f = out_channels
            w = xx = size(output[2])
            c = in_channels
            h = yy = size(output[3])
            s = kernel_w
            r = kernel_h

        """
        #My template

        axe_batch, axe_out_channels, axe_yy, axe_xx = s[Out].op.axis
        axe_in_channels, axe_kernel_h, axe_kernel_w = s[Out].op.reduce_axis

        # get the config object
        cfg = autotvm.get_config()

        #create full tile
        cfg.define_knob("tile_in_channels", [k for k in range(1, in_channels) if in_channels%k == 0])
        cfg.define_knob("tile_out_channels", [k for k in range(1, out_channels) if out_channels%k == 0])
        cfg.define_knob("tile_xx", [k for k in range(1, out_w) if out_w%k == 0])
        cfg.define_knob("tile_yy", [k for k in range(1, out_h) if out_h%k == 0])

        cfg.define_knob("tile_kernel_h", [1, kernel_h])
        cfg.define_knob("tile_kernel_w", [1, kernel_w])


        in_channelso, in_channelsi = s[Out].split(axe_in_channels, cfg["tile_in_channels"].val)
        out_channelso, out_channelsi = s[Out].split(axe_out_channels, cfg["tile_out_channels"].val)
        yyo, yyi = s[Out].split(axe_yy, cfg["tile_yy"].val)
        xxo, xxi = s[Out].split(axe_xx, cfg["tile_xx"].val)

        kernel_ho, kernel_hi = s[Out].split(axe_kernel_h, cfg["tile_kernel_h"].val)
        kernel_wo, kernel_wi = s[Out].split(axe_kernel_w, cfg["tile_kernel_w"].val)

        s[Out].reorder(axe_batch, yyo, out_channelso, xxo, yyi, xxi, in_channelso, kernel_ho, kernel_wo, in_channelsi, kernel_hi, kernel_wi, out_channelsi )
        #s[Out].reorder(axe_batch, yyo, out_channelso, xxo, yyi, xxi, out_channelsi, in_channelso, kernel_ho, kernel_wo, in_channelsi, kernel_hi, kernel_wi )
        # 97ms s[Out].reorder(axe_batch, yyo, out_channelso, xxo, yyi, out_channelsi, in_channelso, kernel_ho, kernel_wo, in_channelsi, kernel_hi, kernel_wi,  xxi)
        
        s[Out].unroll(yyi)
        s[Out].unroll(out_channelsi)
        s[Out].unroll(in_channelsi)
        s[Out].unroll(kernel_hi)
        s[Out].unroll(kernel_wi)

        s[Out].vectorize(xxi)

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
        n_trial=200,
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
else:
    with tvm.target.Target(target):
        s, arg_bufs = conv2d_ttile_(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
        f = tvm.build(s, arg_bufs)



o = tvm.nd.array(np.zeros((batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1), dtype="float32"), ctx)
a = tvm.nd.array(np.random.uniform(size=(batch_size, in_channels,  height + kernel_h - 1, width + kernel_w - 1)).astype("float32"), ctx)
w = tvm.nd.array(np.random.uniform(size=(out_channels, in_channels, kernel_h, kernel_w)).astype("float32"), ctx)


# Run
f(a, w, o)



if use_test:
    # Conv2d ##
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

    output_conv2d = conv2d(w.asnumpy(), a.asnumpy(), o.asnumpy(), batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)


    # Verify the Result
    tvm.testing.assert_allclose(o.asnumpy(), output_conv2d, rtol=1e-5)

evaluator = f.time_evaluator(f.entry_name, ctx, number=10)
result = evaluator(a, w, o).mean * 1e3
print("My Convolution: %f ms" % (result))
if use_tuner:
    nb_cycle = task.flop / (16 * 2) # FMA deux operations
    time_peak_perf = nb_cycle / (2.5 * 10**9) * 1000
    print("Peak Perf (GFLOPS) = ", 2.5 * 16 * 2, "Peak perf (ms)", time_peak_perf)
