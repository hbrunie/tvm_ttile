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

def set_func_attr(func, compile_name, symbol_name):
    func = func.with_attr("Primitive", tvm.tir.IntImm("int32", 1))
    func = func.with_attr("Inline", tvm.tir.IntImm("int32", 1))
    func = func.with_attr("Compiler", compile_name)
    func = func.with_attr("global_symbol", symbol_name)
    return func

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
    mod, map_inputs, out_shape, result, tol=1e-5, target="llvm", device=tvm.cpu(), params=None
):
    if sys.platform == "win32":
        print("Skip test on Windows for now")
        return

    def update_lib(lib):
        test_dir = os.path.dirname(os.path.realpath(os.path.expanduser(__file__)))
        source_dir = os.path.join(test_dir, "..", "..", "..")
        contrib_path = os.path.join(source_dir, "src", "runtime", "contrib")

        kwargs = {}
        kwargs["options"] = ["-O2", "-std=c++14", "-I" + contrib_path]
        tmp_path = utils.tempdir()
        lib_name = "lib.so"
        lib_path = tmp_path.relpath(lib_name)
        lib.export_library(lib_path, fcompile=False, **kwargs)
        lib = runtime.load_module(lib_path)

        return lib

    def check_vm_result():
        compile_engine.get().clear()
        with tvm.transform.PassContext(opt_level=3):
            exe = relay.vm.compile(mod, target=target, params=params)
        code, lib = exe.save()
        lib = update_lib(lib)
        exe = runtime.vm.Executable.load_exec(code, lib)
        vm = runtime.vm.VirtualMachine(exe, device)
        outs = vm.run(**map_inputs)
        outs = outs if isinstance(outs, runtime.container.ADT) else [outs]
        results = result if isinstance(result, list) else [result]
        for out, ref in zip(outs, results):
            tvm.testing.assert_allclose(out.numpy(), ref, rtol=tol, atol=tol)

    def check_graph_executor_result():
        compile_engine.get().clear()
        with tvm.transform.PassContext(opt_level=3):
            json, lib, param = relay.build(mod, target=target, params=params)
        lib = update_lib(lib)
        rt_mod = tvm.contrib.graph_executor.create(json, lib, device)

        for name, data in map_inputs.items():
            rt_mod.set_input(name, data)
        rt_mod.set_input(**param)
        rt_mod.run()

        out_shapes = out_shape if isinstance(out_shape, list) else [out_shape]
        results = result if isinstance(result, list) else [result]

        for idx, shape in enumerate(out_shapes):
            out = tvm.nd.empty(shape, device=device)
            out = rt_mod.get_output(idx, out)
            tvm.testing.assert_allclose(out.numpy(), results[idx], rtol=tol, atol=tol)

    check_vm_result()
    check_graph_executor_result()

def test_extern_dnnl():
    if not tvm.get_global_func("relay.ext.dnnl", True):
        print("skip because DNNL codegen is not available")
        return

    dtype = "float32"
    ishape = (1, 32, 14, 14)
    w1shape = (32, 1, 3, 3)

    def expected():
        data0 = relay.var("data", shape=(ishape), dtype=dtype)
        input0 = relay.var("input", shape=(w1shape), dtype=dtype)
        depthwise_conv2d_1 = relay.nn.conv2d(
            data0, input0, kernel_size=(3, 3), padding=(1, 1), groups=32
        )
        depthwise_conv2d_2 = relay.nn.conv2d(
            depthwise_conv2d_1, input0, kernel_size=(3, 3), padding=(1, 1), groups=32
        )
        out = relay.add(depthwise_conv2d_1, depthwise_conv2d_2)

        func = relay.Function([data0, input0], out)
        func = set_func_attr(func, "dnnl", "tvmgen_default_dnnl_0")
        glb_var = relay.GlobalVar("tvmgen_default_dnnl_0")
        mod = tvm.IRModule()
        mod[glb_var] = func
        mod = transform.InferType()(mod)

        data = relay.var("data", shape=(ishape), dtype=dtype)
        weight = relay.var("input", shape=(w1shape), dtype=dtype)
        main_f = relay.Function([data, weight], glb_var(data, weight))
        mod["main"] = main_f
        mod = transform.InferType()(mod)

        return mod

    def get_func():
        data = relay.var("data", shape=(ishape), dtype=dtype)
        weight1 = relay.var("weight1", shape=(w1shape), dtype=dtype)
        depthwise_conv2d_1 = relay.nn.conv2d(
            data, weight1, kernel_size=(3, 3), padding=(1, 1), groups=32
        )
        depthwise_conv2d_2 = relay.nn.conv2d(
            depthwise_conv2d_1, weight1, kernel_size=(3, 3), padding=(1, 1), groups=32
        )
        out = relay.add(depthwise_conv2d_1, depthwise_conv2d_2)

        return relay.Function([data, weight1], out)

    mod = tvm.IRModule()
    mod["main"] = WholeGraphAnnotator("dnnl").visit(get_func())
    mod = transform.PartitionGraph()(mod)
    mod = transform.InferType()(mod)

    assert tvm.ir.structural_equal(mod, expected(), map_free_vars=True)

    ref_mod = tvm.IRModule()
    ref_mod["main"] = get_func()

    i_data = np.random.uniform(0, 1, ishape).astype(dtype)
    w1_data = np.random.uniform(0, 1, w1shape).astype(dtype)

    ref_ex = relay.create_executor("graph", mod=ref_mod, device=tvm.cpu())
    ref_res = ref_ex.evaluate()(i_data, w1_data)
    check_result(
        mod, {"data": i_data, "weight1": w1_data}, (1, 32, 14, 14), ref_res.numpy(), tol=1e-5
    )
test_extern_dnnl()
