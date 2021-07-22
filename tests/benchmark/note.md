2 possibilities for CODEGEN --> JSON or C_SRC.
----------------
* JSON works but bad perf: read somewehere that only composed operators are supported:
    - relay/backend/contrib/dnnl/codegen.cc:444
`ICHECK(comp.defined()) << "DNNL JSON runtime only supports composite functions.";`

* C_SRC does not work:
```
>> python3 dnnl_test.py 
Traceback (most recent call last):
  File "dnnl_test.py", line 115, in <module>
    test_extern_dnnl()
  File "dnnl_test.py", line 112, in test_extern_dnnl
    mod, {"data": i_data, "weight1": w1_data}, ishape, tol=1e-5
  File "dnnl_test.py", line 69, in check_result
    check_graph_executor_result(ishape)
  File "dnnl_test.py", line 59, in check_graph_executor_result
    gmod = graph_executor.GraphModule(lib["default"](dev))
  File "/home/hbrunie/tvm/python/tvm/_ffi/_ctypes/packed_func.py", line 237, in __call__
    raise get_last_ffi_error()
tvm._ffi.base.TVMError: Traceback (most recent call last):
  5: TVMFuncCall
  4: std::_Function_handler<void (tvm::runtime::TVMArgs, tvm::runtime::TVMRetValue*), tvm::runtime::GraphExecutorFactory::GetFunction(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, tvm::runtime::ObjectPtr<tvm::runtime::Object> const&)::{lambda(tvm::runtime::TVMArgs, tvm::runtime::TVMRetValue*)#1}>::_M_invoke(std::_Any_data const&, tvm::runtime::TVMArgs&&, tvm::runtime::TVMRetValue*&&)
  3: tvm::runtime::GraphExecutorFactory::ExecutorCreate(std::vector<DLDevice, std::allocator<DLDevice> > const&)
  2: tvm::runtime::GraphExecutor::Init(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, tvm::runtime::Module, std::vector<DLDevice, std::allocator<DLDevice> > const&, tvm::runtime::PackedFunc)
  1: tvm::runtime::GraphExecutor::SetupOpExecs()
  0: tvm::runtime::GraphExecutor::CreateTVMOp(tvm::runtime::TVMOpParam const&, std::vector<DLTensor, std::allocator<DLTensor> > const&, unsigned long)
  File "/home/hbrunie/tvm/src/runtime/graph_executor/graph_executor.cc", line 434
TVMError: 
---------------------------------------------------------------
An error occurred during the execution of TVM.
For more information, please see: https://tvm.apache.org/docs/errors.html
---------------------------------------------------------------
  Check failed: (pf != nullptr) is false: no such function in module: tvmgen_default_dnnl_0
```
