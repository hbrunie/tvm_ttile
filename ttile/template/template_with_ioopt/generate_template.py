import input_conv
import input_sol
import solution
import reorder


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
    "x": "out_w",
    "y": "out_h",
    "w": "kernel_w",
    "h": "kernel_h"
}

def find_axe_to_vectorize(order, sol):
    """
    for k in range(len(order)):
        if "kernel" not in order[-1 - k] and "in_channels" not in order[-1 - k]:
            return order[-1-k]
    """
    if sol["f"][0] != 0:
        return("axe_out_channels_0")
    else:
        return("axe_out_channels")

def find_size_tile(axis, tile_ioopt, mode):
    dup = 0
    ddown = 0
    dclosest = 0
    if mode == "up" or mode == "closest":
        for k in range(tile_ioopt, axis + 1):
            if axis % k == 0:
                dup = k
                break
    if mode == "down" or mode == "closest":
        for k in range(tile_ioopt, 0, -1):
            if axis & k == 0:
                ddown = k
                break
    if mode == "closest":
        if dup - tile_ioopt <= tile_ioopt - ddown:
            dclosest = dup
        else:
            dclosest = ddown
    if mode == "up":
        return dup
    elif mode == "down":
        return ddown
    elif mode == "closest":
        return dclosest
    else:
        print("Problem with mode")
        return axis
    



def generate_template(name_input, target, archi, mode):

    f = open("template/template_" + name_input.replace("-", "_") + ".py", "w")

    name_input_ = name_input.replace("-", "_")

    batch_size = 1
    out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_input]

    out_h = height  // stride_h 
    out_w = width // stride_w 

    value_input = {
        "out_channels": out_channels, 
        "in_channels": in_channels, 
        "height": height, 
        "width": width, 
        "kernel_h": kernel_h, 
        "kernel_w": kernel_w, 
        "stride_h": stride_h, 
        "stride_w": stride_w,
        "out_h": out_h,
        "out_w": out_w
    }

    

    sol = solution.solution(name_input, archi)
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

batch_size = {batch_size}
height = {height}
width = {width}
in_channels = {in_channels}
out_channels = {out_channels}
kernel_h = {kernel_h}
kernel_w = {kernel_w}
stride_h = {stride_h}
stride_w = {stride_w}
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
    """)



    for key in sol:
        if sol[key][0] != 0: 
            name_axe_init = convert_axe[key]
            name_axe_intermediate = convert_axe[key]
            value_axis = value_input[convert_name[key]]
            for id_split in range(sol[key][0]):
                #check les indentations
                if int(sol[key][-1 - id_split]) > value_axis:
                    tile_size_ioopt = value_axis
                else:
                    tile_size_ioopt = int(sol[key][-1 - id_split])
                tile_size = find_size_tile(value_axis, tile_size_ioopt, mode)
                f.write(f"""
    {name_axe_init}_{id_split+1}, {name_axe_init}_{id_split} = s[Out].split({name_axe_intermediate}, {tile_size})
                """)
                name_axe_intermediate = name_axe_init + "_" + str(id_split+1)
                value_axis = tile_size_ioopt

    lorder = reorder.reorder(name_input, archi)
    order = ",".join(lorder)
    f.write(f"""
    s[Out].reorder({order})
    """)

    for k in range(3):
        f.write(f"""
    cfg.define_knob("unroll_{lorder[-1-k]}", [True, False])
        """)

    for k in range(3):
        f.write(f"""
    if cfg["unroll_{lorder[-1-k]}"].val:
        s[Out].unroll({lorder[-1-k]})
        """)

    f.write(f"""
    #s[Out].vectorize({lorder[-1]})
    s[Out].vectorize({find_axe_to_vectorize(lorder, sol)})
     """)    

    f.write(f"""
    #print(tvm.lower(s, [A, W, Out]))

    return s, [A, W, Out]
    """)

    f.write(f"""
def evaluate():
    task = autotvm.task.create("conv2d_ttile_{name_input_}", args=(batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, stride_h, stride_w), target=target)
    print(task.config_space)
    print(task.flop)

    # logging config (for printing tuning log to the screen)
    logging.getLogger("autotvm").setLevel(logging.DEBUG)
    logging.getLogger("autotvm").addHandler(logging.StreamHandler(sys.stdout))

    measure_option = autotvm.measure_option(builder="local", runner=autotvm.LocalRunner(number=5))

    tuner = autotvm.tuner.XGBTuner(task)
    tuner.tune(
        n_trial = 1000,
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
    print("My Convolution: %f ms" % (result))

    time = [result]

    # Test Result

    # from tvm.topi.nn import conv2d_nhwc

    # A = te.placeholder((batch_size, width + kernel_w - 1, height + kernel_h - 1, in_channels), name="A")
    # W = te.placeholder((kernel_w, kernel_h, in_channels, out_channels), name="W")

    # Out_test = conv2d_nhwc(A, W, stride_h, 0, 1, "float32")

    # s = te.create_schedule(Out_test.op)

    # f_test = tvm.build(s, [A, W, Out_test], target)
    # f_test(a, w, oo)

    # output_conv2d_test = oo.asnumpy()

    # tvm.testing.assert_allclose(output_conv2d, output_conv2d_test, rtol=1e-5)


    # for k in range(19):
    #     time += [float(os.popen("python3 template/apply_best_{name_input.replace("-", "_")}.py").read())]

    # for k in range(5):
    #     time.remove(max(time))
    #     time.remove(min(time))

    # result = np.mean(time)
    # std = np.std(time)

    # f = open("result.txt", "a")
    # f.write("{name_input.replace("-", "_")} " + str(result) + " " + str(std) + "\\n")
    # f.close()

    f = open("result.txt", "a")
    f.write("{name_input.replace("-", "_")} " + str(result) + "\\n")
    f.close()


    """)
    f.close()



def generate_apply_best(name_input, target, archi, mode):

    f = open("template/apply_best_" + name_input.replace("-", "_") + ".py", "w")

    name_input_ = name_input.replace("-", "_")

    batch_size = 1
    out_channels, in_channels, height, width, kernel_h, kernel_w, stride_h, stride_w = input_conv.input_conv[name_input]

    out_h = height  // stride_h 
    out_w = width // stride_w 

    value_input = {
        "out_channels": out_channels, 
        "in_channels": in_channels, 
        "height": height, 
        "width": width, 
        "kernel_h": kernel_h, 
        "kernel_w": kernel_w, 
        "stride_h": stride_h, 
        "stride_w": stride_w,
        "out_h": out_h,
        "out_w": out_w
    }

    sol = solution.solution(name_input, archi)
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

batch_size = {batch_size}
height = {height}
width = {width}
in_channels = {in_channels}
out_channels = {out_channels}
kernel_h = {kernel_h}
kernel_w = {kernel_w}
stride_h = {stride_h}
stride_w = {stride_w}
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
    """)

    for key in sol:
        if sol[key][0] != 0: 
            name_axe_init = convert_axe[key]
            name_axe_intermediate = convert_axe[key]
            value_axis = value_input[convert_name[key]]
            for id_split in range(sol[key][0]):
                #check les indentations
                tile_size = find_size_tile(value_axis, int(sol[key][-1 - id_split]), mode)
                f.write(f"""
    {name_axe_init}_{id_split+1}, {name_axe_init}_{id_split} = s[Out].split({name_axe_intermediate}, {tile_size})
                """)
                name_axe_intermediate = name_axe_init + "_" + str(id_split+1)
                value_axis = int(sol[key][-1 - id_split])

    lorder = reorder.reorder(name_input, archi)
    order = ",".join(lorder)
    f.write(f"""
    s[Out].reorder({order})
    """)

    for k in range(3):
        f.write(f"""
    cfg.define_knob("unroll_{lorder[-1-k]}", [True, False])
        """)

    for k in range(3):
        f.write(f"""
    if cfg["unroll_{lorder[-1-k]}"].val:
        s[Out].unroll({lorder[-1-k]})
        """)

    f.write(f"""
    #s[Out].vectorize({lorder[-1]})
    s[Out].vectorize({find_axe_to_vectorize(lorder, sol)})
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


    """)
    f.close()
