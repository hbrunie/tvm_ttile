import input_conv
import reorder
import size_kernel

convert_axe = {
    "f": "axe_out_channels",
    "c": "axe_in_channels",
    "x": "axe_xx",
    "y": "axe_yy",
    "w": "axe_kernel_w",
    "h": "axe_kernel_h"
}

convert_name = {
    "f": "out_channels",
    "c": "in_channels",
    "x": "out_width",
    "y": "out_height",
    "w": "kernel_w",
    "h": "kernel_h"
}


def generate_template(name_input, target, archi):

    f = open("template/template_" + name_input.replace("-", "_") + ".py", "w")

    name_input_ = name_input.replace("-", "_")

    batch_size = 1
    out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_input]

    lorder, cpu, l1, l2, fuse = reorder.reorder(name_input, archi)
    #headers
    f.write("""
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
""")

    f.write(f"""
log_file = "log/autotvm_conv2d_{name_input}.log"
target = \"{target}\"
ctx = tvm.context(target)
dtype="float32"

batch_size   = {batch_size}
height = yy  = {height}
width = xx   = {width}
in_channels  = {in_channels}
out_channels = {out_channels}
kernel_h     = {kernel_h}
kernel_w     = {kernel_w}
stride_h     = {stride_h}
stride_w     = {stride_w}

size_in_channels_kernel  = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["in_channels_kernel"]}
size_out_channels_kernel = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["out_channels_kernel"]}
size_xx_kernel           = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["xx_kernel"]}
size_yy_kernel           = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["yy_kernel"]}
size_kernel_h_kernel     = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["kernel_h_kernel"]}
size_kernel_w_kernel     = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["kernel_w_kernel"]}

    """)

    #function
    f.write(f"""
@autotvm.template("conv2d_ttile_{name_input_}")
def conv2d_ttile_{name_input_}(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_height = height  // stride_h 
    out_width = width // stride_w 

    Out = te.compute(
        (batch_size, out_width, out_height, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w, stride_h * yy  + axe_kernel_h, axe_in_channels] * W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    axe_batch, axe_xx, axe_yy, axe_out_channels = s[Out].op.axis
    axe_in_channels, axe_kernel_h, axe_kernel_w = s[Out].op.reduce_axis

    # get the config object
    cfg = autotvm.get_config()
    """)

    deja_vu = set()

    # for k in l2:
    #     f.write(f"""
    # print([k for k in range(size_{"_".join(k.split("_")[1:-1])}_kernel, {"_".join(k.split("_")[1:-1])} + 1) if {"_".join(k.split("_")[1:-1])}%k == 0 and k%size_{"_".join(k.split("_")[1:-1])}_kernel == 0])
    #     """)

    for k in l2:
        f.write(f"""
    cfg.define_knob("tile_{k}", [k for k in range(size_{"_".join(k.split("_")[1:-1])}_kernel, {"_".join(k.split("_")[1:-1])} + 1) if {"_".join(k.split("_")[1:-1])}%k == 0 and k%size_{"_".join(k.split("_")[1:-1])}_kernel == 0])
        """)


    for k in l2:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, cfg["tile_{k}"].val)
        """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    for k in l1:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        if name_axe_o in deja_vu:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({name_axe_o}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        else:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    for k in cpu:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        if name_axe_o in deja_vu:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({name_axe_o}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        else:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    
    order = ",".join(lorder)
    f.write(f"""
    s[Out].reorder({order})
    """)

    for k in range(2):
        f.write(f"""
    cfg.define_knob("unroll_{lorder[-1-k]}", [True, False])
        """)

    for k in range(2):
        f.write(f"""
    if cfg["unroll_{lorder[-1-k]}"].val:
        s[Out].unroll({lorder[-1-k]})
        """)

    f.write(f"""
    s[Out].vectorize({lorder[-1]})
     """) 

    f.write(f"""
    fuse = s[Out].fuse({",".join(fuse)})
    s[Out].parallel(fuse)
    """)

    f.write(f"""
    #print(tvm.lower(s, [A, W, Out]))

    return s, [A, W, Out]
    """)

    f.write(f"""
def evaluate():
    try:
        os.mkdir("log")
    except FileExistsError:
        pass

    task = autotvm.task.create("conv2d_ttile_{name_input_}", args=(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w), target=target)
    print(task.config_space)
    print(task.flop)

    # logging config (for printing tuning log to the screen)
    logging.getLogger("autotvm").setLevel(logging.DEBUG)
    logging.getLogger("autotvm").addHandler(logging.StreamHandler(sys.stdout))

    measure_option = autotvm.measure_option(builder="local", runner=autotvm.LocalRunner(number=5))

    tuner = autotvm.tuner.XGBTuner(task)
    tuner.tune(
        n_trial = 10,
        #n_trial=len(task.config_space),
        measure_option=measure_option,
        callbacks=[autotvm.callback.log_to_file(log_file)],
    )

    # inspect the best config
    dispatch_context = autotvm.apply_history_best(log_file)
    best_config = dispatch_context.query(task.target, task.workload)
    print("\\nBest config:")
    print(best_config)

    with autotvm.apply_history_best(log_file):
        with tvm.target.Target(target):
            s, arg_bufs = conv2d_ttile_{name_input_}(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w)
            f = tvm.build(s, arg_bufs)

    out_height = height // stride_h 
    out_width = width // stride_w 

    a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(dtype), ctx)
    w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(dtype), ctx)
    o = tvm.nd.array(np.zeros((batch_size, out_width, out_height, out_channels), dtype=dtype), ctx)
    oo = tvm.nd.array(np.zeros((batch_size, out_width, out_height, out_channels), dtype=dtype), ctx)

    # Run
    f(a, w, o)


    output_conv2d = o.asnumpy()

    evaluator = f.time_evaluator(f.entry_name, ctx, number=3, repeat=10)
    result = evaluator(a, w, o).mean * 1e3
    print("My Convolution: %f ms" % (result))

    time = [result]

    # Test Result

    from tvm.topi.nn import conv2d_nhwc

    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    Out_test = conv2d_nhwc(A, W, stride_h, 0, 1, "float32")

    s = te.create_schedule(Out_test.op)

    f_test = tvm.build(s, [A, W, Out_test], target)
    f_test(a, w, oo)

    output_conv2d_test = oo.asnumpy()

    tvm.testing.assert_allclose(output_conv2d, output_conv2d_test, rtol=1e-5)


    for k in range(19):
        time += [float(os.popen("python3 template/apply_best_{name_input.replace("-", "_")}.py").read())]

    for k in range(5):
        time.remove(max(time))
        time.remove(min(time))

    result = np.mean(time)
    std = np.std(time)

    f = open("result.txt", "a")
    f.write("{name_input.replace("-", "_")} " + str(result) + " " + str(std) + "\\n")
    f.close()


    """)
    f.close()



def generate_apply_best(name_input, target, archi):

    f = open("template/apply_best_" + name_input.replace("-", "_") + ".py", "w")

    name_input_ = name_input.replace("-", "_")

    batch_size = 1
    out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_input]
    lorder, cpu, l1, l2, fuse = reorder.reorder(name_input, archi)
    #headers
    f.write("""
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
""")

    f.write(f"""
log_file = "log/autotvm_conv2d_{name_input}.log"
target = \"{target}\"
ctx = tvm.context(target)
dtype="float32"

batch_size   = {batch_size}
height = yy  = {height}
width = xx   = {width}
in_channels  = {in_channels}
out_channels = {out_channels}
kernel_h     = {kernel_h}
kernel_w     = {kernel_w}
stride_h     = {stride_h}
stride_w     = {stride_w}

size_in_channels_kernel  = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["in_channels_kernel"]}
size_out_channels_kernel = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["out_channels_kernel"]}
size_xx_kernel           = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["xx_kernel"]}
size_yy_kernel           = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["yy_kernel"]}
size_kernel_h_kernel     = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["kernel_h_kernel"]}
size_kernel_w_kernel     = {size_kernel.size_kernel(name_input.replace("-", "_"), archi)["kernel_w_kernel"]}

    """)

    #function
    f.write(f"""
@autotvm.template("conv2d_ttile_{name_input_}")
def conv2d_ttile_{name_input_}(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w):
    A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    axe_in_channels = te.reduce_axis((0, in_channels), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, kernel_h), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, kernel_w), name="axe_kernel_w")

    out_height = height  // stride_h 
    out_width = width // stride_w 

    Out = te.compute(
        (batch_size, out_width, out_height, out_channels),
        lambda batch, xx, yy, out_channels: te.sum(
            A[batch, stride_w * xx + axe_kernel_w, stride_h * yy  + axe_kernel_h, axe_in_channels] * W[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
            axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
        )
    s = te.create_schedule(Out.op)

    axe_batch, axe_xx, axe_yy, axe_out_channels = s[Out].op.axis
    axe_in_channels, axe_kernel_h, axe_kernel_w = s[Out].op.reduce_axis

    # get the config object
    cfg = autotvm.get_config()
    """)

    deja_vu = set()

    # for k in l2:
    #     f.write(f"""
    # print([k for k in range(size_{"_".join(k.split("_")[1:-1])}_kernel, {"_".join(k.split("_")[1:-1])} + 1) if {"_".join(k.split("_")[1:-1])}%k == 0 and k%size_{"_".join(k.split("_")[1:-1])}_kernel == 0])
    #     """)

    for k in l2:
        f.write(f"""
    cfg.define_knob("tile_{k}", [k for k in range(size_{"_".join(k.split("_")[1:-1])}_kernel, {"_".join(k.split("_")[1:-1])} + 1) if {"_".join(k.split("_")[1:-1])}%k == 0 and k%size_{"_".join(k.split("_")[1:-1])}_kernel == 0])
        """)


    for k in l2:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, cfg["tile_{k}"].val)
        """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    for k in l1:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        if name_axe_o in deja_vu:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({name_axe_o}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        else:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    for k in cpu:
        name_axe_i = k
        id = int(k.split("_")[-1]) + 1
        name_axe_o = "_".join(k.split("_")[:-1]) + "_" + str(id)
        if name_axe_o in deja_vu:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({name_axe_o}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        else:
            f.write(f"""
    {name_axe_o}, {name_axe_i} = s[Out].split({"_".join(k.split("_")[:-1])}, size_{"_".join(k.split("_")[1:-1])}_kernel)
            """)
        deja_vu.add(name_axe_o)
        deja_vu.add(name_axe_i)

    
    order = ",".join(lorder)
    f.write(f"""
    s[Out].reorder({order})
    """)

    for k in range(2):
        f.write(f"""
    cfg.define_knob("unroll_{lorder[-1-k]}", [True, False])
        """)

    for k in range(2):
        f.write(f"""
    if cfg["unroll_{lorder[-1-k]}"].val:
        s[Out].unroll({lorder[-1-k]})
        """)

    f.write(f"""
    s[Out].vectorize({lorder[-1]})
     """) 

    f.write(f"""
    fuse = s[Out].fuse({",".join(fuse)})
    s[Out].parallel(fuse)
    """)

    f.write(f"""
    #print(tvm.lower(s, [A, W, Out]))

    return s, [A, W, Out]
    """)

    f.write(f"""
def evaluate():

    measure_option = autotvm.measure_option(builder="local", runner=autotvm.LocalRunner(number=5))

    with autotvm.apply_history_best(log_file):
        with tvm.target.Target(target):
            s, arg_bufs = conv2d_ttile_{name_input_}(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w)
            f = tvm.build(s, arg_bufs)

    out_height = height // stride_h 
    out_width = width // stride_w 

    a = tvm.nd.array(np.random.uniform(size=(batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels)).astype(dtype), ctx)
    w = tvm.nd.array(np.random.uniform(size=(kernel_w, kernel_h, in_channels, out_channels)).astype(dtype), ctx)
    o = tvm.nd.array(np.zeros((batch_size, out_width, out_height, out_channels), dtype=dtype), ctx)
    oo = tvm.nd.array(np.zeros((batch_size, out_width, out_height, out_channels), dtype=dtype), ctx)

    # Run
    f(a, w, o)


    output_conv2d = o.asnumpy()

    evaluator = f.time_evaluator(f.entry_name, ctx, number=3, repeat=10)
    result = evaluator(a, w, o).mean * 1e3
    print(result)

evaluate()


    """)
    f.close()
