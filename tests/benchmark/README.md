Execute:
--------
Don't forget to set:
```
export TVM_HOME=/path/to/tvm_ttile/
export PYTHONPATH=$TVM_HOME/python:${PYTHONPATH}
```
then execute with:
    * `python3 main.py`

TODO:
-----
* Compile the C++ OneDNN wrapper developed by Guillaume and use it as an
external library with TVM. The idea is to be able to switch inside TVM between
using TTILE and using OneDNN.
    - Hugo tried to use OneDNN directly within TVM (compiling libtvm.so with what
    they call USE_MKLDNN) but the perfromance were much worst on MobilNet
    convolution than using OneDNN with matmul_bench.
