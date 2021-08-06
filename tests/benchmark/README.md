BE AWARE:
---------
* There are some hard coded absolute path in the TVM code:
- in `python/tvm/topi/x86/conv2d.py`
``` python
##TODO: make it automatic for abspath
def resnet_name_from_number(n, abspath = "/home/hbrunie/tvm/ttile/conv2d/tensorize/results_random",
                            avxtype="avx512", machine="pinocchio",CNN="ResNet18",nbthreads=1):
    "Returns CSV fname from conv2d number + abspath + machine"
    res = "/result_{}_{}_{}_{}_".format(nbthreads,avxtype,machine,CNN)
    res = abspath + res
    # numbers with only one figure
    if n <10:
        return res+f"0{n}.csv"
    else:# numbers with two figures
        return res+f"{n}.csv"

##TODO: make it automatic for abspath
def get_pkl_fname_from_dataFrame(df,abspath="/home/hbrunie/tvm/ttile/conv2d/tensorize/"):
    """
    """
    pkl_fname = df.InfottilePickleName

    return pkl_fname
```

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
