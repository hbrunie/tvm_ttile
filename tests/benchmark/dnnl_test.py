import os
import sys

import numpy as np

import tvm
import tvm.relay.testing
import tvm.relay.op as reg
from tvm import relay
from tvm import runtime
from tvm.relay import transform
from tvm.contrib import utils
from tvm.relay.backend import compile_engine
from tvm.relay.expr_functor import ExprMutator
from tvm.relay.op.annotation import compiler_begin, compiler_end
from tvm.relay.op.contrib.register import get_pattern_table
from tvm.relay.build_module import bind_params_by_name

class WholeGraphAnnotator(ExprMutator):
    """
    An annotator that creates a compiler for an entire graph.
    """

    def __init__(self, compiler):
        super(WholeGraphAnnotator, self).__init__()
        self.compiler = compiler
        self.last_call = True

    def visit_call(self, call):
        curr_last = self.last_call
        self.last_call = False

        params = []
        for arg in call.args:
            param = super().visit(arg)
            if isinstance(param, relay.expr.Var):
                param = compiler_begin(param, self.compiler)
            params.append(param)

        new_call = relay.Call(call.op, params, call.attrs)
        if curr_last:
            new_call = compiler_end(new_call, self.compiler)
        return new_call


def check_result(
    mod, map_inputs, out_shape, result, tol=1e-5, target="llvm -mcpu=skylake-avx512", device=tvm.cpu(), params=None
):
    ishape = out_shape

    def check_graph_executor_result(ishape):
        #compile_engine.get().clear()
        with tvm.transform.PassContext(opt_level=3):
            lib = relay.build(mod, target=target, params=params)
        from tvm.contrib import graph_executor
        dev = tvm.cpu(0)
        dtype="float32"
        data = tvm.nd.array((np.random.uniform(size=ishape)).astype(dtype))
        gmod = graph_executor.GraphModule(lib["default"](dev))
        gmod.set_input("data", data)
        print("Evaluate inference time cost...")
        ftimer = gmod.module.time_evaluator("run", dev, number=10, repeat=10)
        print(ftimer)
        prof_res = np.array(ftimer().results) * 1000  # convert to millisecond
        print(
            "Mean inference time (std dev): %.2f ms (%.2f ms)"
            % (np.mean(prof_res), np.std(prof_res))
        )
    check_graph_executor_result(ishape)

def test_extern_dnnl():
    if not tvm.get_global_func("relay.ext.dnnl", True):
        print("skip because DNNL codegen is not available")
        return

    x = 112
    y = 112
    w = h = 3
    f = 32
    c = 32
    dtype = "float32"
    ishape = (1, c, x, y) #b c x y
    w1shape = (f, 1, w, h) ## f b w h

    def get_func():
        data = relay.var("data", shape=(ishape), dtype=dtype)
        weight1 = relay.var("weight1", shape=(w1shape), dtype=dtype)
        out = relay.nn.conv2d(
            data, weight1, kernel_size=(w, h), padding=(1, 1), groups=c
        )
        #depthwise_conv2d_2 = relay.nn.conv2d(
        #    depthwise_conv2d_1, weight1, kernel_size=(3, 3), padding=(1, 1), groups=32
        #)
        #out = relay.add(depthwise_conv2d)

        return relay.Function([data, weight1], out)

    mod = tvm.IRModule()
    mod["main"] = WholeGraphAnnotator("dnnl").visit(get_func())
    mod = transform.PartitionGraph()(mod)
    mod = transform.InferType()(mod)

    ref_mod = tvm.IRModule()
    ref_mod["main"] = get_func()

    i_data = np.random.uniform(0, 1, ishape).astype(dtype)
    w1_data = np.random.uniform(0, 1, w1shape).astype(dtype)

    ref_ex = relay.create_executor("graph", mod=ref_mod, device=tvm.cpu())
    ref_res = ref_ex.evaluate()(i_data, w1_data)
    ishape = (1, c, x, y) ## b c x y
    check_result(
        mod, {"data": i_data, "weight1": w1_data}, ishape, ref_res.numpy(), tol=1e-5
    )

test_extern_dnnl()
