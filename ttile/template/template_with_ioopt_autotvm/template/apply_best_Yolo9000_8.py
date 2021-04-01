
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

log_file = "log/autotvm_conv2d_Yolo9000-8.log"
target = "llvm -mcpu=core-avx2"
ctx = tvm.context(target)
dtype="float32"

batch_size = 1
height = 68
width = 68
in_channels = 128
out_channels = 256
kernel_h = 3
kernel_w = 3
stride_h = 1
stride_w = 1
    
@autotvm.template("conv2d_ttile_Yolo9000_8")
def conv2d_ttile_Yolo9000_8(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_h = height  // stride_h 
    out_w = width // stride_w 

    Out = te.compute(
        (batch_size, out_w, out_h, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w, stride_h * yy  + axe_kernel_h, axe_in_channels] * W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    axe_batch, axe_xx, axe_yy, axe_out_channels = s[Out].op.axis
    axe_in_channels, axe_kernel_h, axe_kernel_w = s[Out].op.reduce_axis

    # get the config object
    cfg = autotvm.get_config()
    
    cfg.define_knob("tile_out_channels_0", [k for k in range(1, out_channels + 1) if out_channels%k == 0])
            
    cfg.define_knob("tile_out_channels_1", [k for k in range(1, out_channels + 1) if out_channels%k == 0])
            
    cfg.define_knob("tile_in_channels_0", [k for k in range(1, in_channels + 1) if in_channels%k == 0])
            
    cfg.define_knob("tile_out_w_0", [k for k in range(1, out_w + 1) if out_w%k == 0])
            
    cfg.define_knob("tile_out_h_0", [k for k in range(1, out_h + 1) if out_h%k == 0])
            
    axe_out_channels_1, axe_out_channels_0 = s[Out].split(axe_out_channels, cfg["tile_out_channels_0"].val)
                
    axe_out_channels_2, axe_out_channels_1 = s[Out].split(axe_out_channels_1, cfg["tile_out_channels_1"].val)
                
    axe_in_channels_1, axe_in_channels_0 = s[Out].split(axe_in_channels, cfg["tile_in_channels_0"].val)
                
    axe_xx_1, axe_xx_0 = s[Out].split(axe_xx, cfg["tile_out_w_0"].val)
                
    axe_yy_1, axe_yy_0 = s[Out].split(axe_yy, cfg["tile_out_h_0"].val)
                
    s[Out].reorder(axe_in_channels_1,axe_out_channels_1,axe_yy_1,axe_xx_1,axe_in_channels_0,axe_kernel_h,axe_kernel_w,axe_yy_0,axe_xx_0,axe_out_channels_0)
    
    cfg.define_knob("unroll_axe_out_channels_0", [True, False])
        
    cfg.define_knob("unroll_axe_xx_0", [True, False])
        
    if cfg["unroll_axe_out_channels_0"].val:
        s[Out].unroll(axe_out_channels_0)
        
    if cfg["unroll_axe_xx_0"].val:
        s[Out].unroll(axe_xx_0)
        
    #s[Out].vectorize(axe_out_channels_0)
    s[Out].vectorize(axe_out_channels_0)
     
    #print(tvm.lower(s, [A, W, Out]))

    return s, [A, W, Out]
    
def evaluate():

    measure_option = autotvm.measure_option(builder="local", runner=autotvm.LocalRunner(number=5))

    with autotvm.apply_history_best(log_file):
        with tvm.target.Target(target):
            s, arg_bufs = conv2d_ttile_Yolo9000_8(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w)
            f = tvm.build(s, arg_bufs)

    out_h = height // stride_h 
    out_w = width // stride_w 

    a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(dtype), ctx)
    w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(dtype), ctx)
    o = tvm.nd.array(np.zeros((batch_size, out_w, out_h, out_channels), dtype=dtype), ctx)
    oo = tvm.nd.array(np.zeros((batch_size, out_w, out_h, out_channels), dtype=dtype), ctx)

    # Run
    f(a, w, o)


    output_conv2d = o.asnumpy()

    evaluator = f.time_evaluator(f.entry_name, ctx, number=3, repeat=10)
    result = evaluator(a, w, o).mean * 1e3
    print(result)

evaluate()


    