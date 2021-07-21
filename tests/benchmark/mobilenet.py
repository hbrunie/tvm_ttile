import os
import sys
import numpy as np
import pytest

import tvm
import tvm.relay.testing
import tvm.relay.transform as transform
from tvm import relay
from tvm import runtime
from tvm.contrib import utils

if not tvm.get_global_func("relay.ext.dnnl", True):
    print("skip because DNNL codegen is not available")
    exit(1)

import argcomplete, argparse

parser = argparse.ArgumentParser(description='Execute full resnet CNN.')
parser.add_argument('--skylake_avx512',action='store_true',
        help="Add -mcpu=skylake-avx512 to TVM target.")

argcomplete.autocomplete(parser)
args = parser.parse_args()

#i_data = np.random.uniform(0, 1, ishape).astype(dtype)

#ref_mod, params = relay.testing.mobilenet.get_workload(batch_size=1, dtype="float32")
#ref_ex = relay.create_executor("graph", mod=ref_mod, device=tvm.cpu(0))
#ref_res = ref_ex.evaluate()(i_data, **params)
#dev = tvm.cpu(0)

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
        with tvm.transform.PassContext(opt_level=3, disabled_pass=["AlterOpLayout"]):
            exe = relay.vm.compile(mod, target=target, params=params)
        code, lib = exe.save()
        lib = update_lib(lib)
        exe = runtime.vm.Executable.load_exec(code, lib)
        vm = runtime.vm.VirtualMachine(exe, device)
        out = vm.run(**map_inputs)
        tvm.testing.assert_allclose(out.numpy(), result, rtol=tol, atol=tol)

    def check_graph_executor_result():
        with tvm.transform.PassContext(opt_level=3, disabled_pass=["AlterOpLayout"]):
            json, lib, param = relay.build(mod, target=target, params=params)
        lib = update_lib(lib)
        rt_mod = tvm.contrib.graph_executor.create(json, lib, device)

        for name, data in map_inputs.items():
            rt_mod.set_input(name, data)
        rt_mod.set_input(**param)
        rt_mod.run()
        out = tvm.nd.empty(out_shape, device=device)
        out = rt_mod.get_output(0, out)

        tvm.testing.assert_allclose(out.numpy(), result, rtol=tol, atol=tol)

    check_vm_result()
    check_graph_executor_result()

target = "llvm"
if args.skylake_avx512:
    target += " -mcpu=skylake-avx512"
target = tvm.target.Target(target, host=target)

dtype = "float32"
ishape = (1, 3, 224, 224)
mod, params = relay.testing.mobilenet.get_workload(batch_size=1, dtype="float32")

import tvm.contrib.graph_executor as runtime
mod["main"] = relay.build_module.bind_params_by_name(mod["main"], params)
mod = transform.AnnotateTarget("dnnl")(mod)
mod = transform.PartitionGraph()(mod)
with tvm.transform.PassContext(opt_level=3):
    lib = relay.build_module.build(mod, target=target, params=params)
data_tvm = tvm.nd.array((np.random.uniform(size=ishape)).astype(dtype))
dev = tvm.cpu(0)
print(lib)
module = runtime.GraphModule(lib["default"](dev))
input_name = "data"
module.set_input(input_name, data_tvm)

# evaluate
print("Evaluate inference time cost...")
ftimer = module.module.time_evaluator("run", dev, number=100, repeat=3)
print(ftimer)
prof_res = np.array(ftimer().results) * 1000  # convert to millisecond
print(
    "Mean inference time (std dev): %.2f ms (%.2f ms)"
    % (np.mean(prof_res), np.std(prof_res))
)
