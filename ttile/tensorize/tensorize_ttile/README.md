Tensorize
======

Installation
-----

```
apt install git
apt-get install -y python3 python3-dev python3-setuptools gcc libtinfo-dev zlib1g-dev build-essential cmake libedit-dev libxml2-dev llvm clang
apt install lsb-release wget software-properties-common
bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
apt install python3-pip
echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo
git clone --recursive git@github.com:S12P/tvm_ttile.git

pip3 install numpy decorator attrs tornado psutil xgboost cloudpickle pytest

apt install libpapi-dev papi-tools
sysctl -w kernel.perf_event_paranoid=0
git clone git@gitlab.inria.fr:ntollena/matmul_bench.git
(cd matmul_bench && git checkout stephane_metric)


apt install opam
# environment setup
opam init
eval `opam env`
# install given version of the compiler
opam switch create 4.12.0
eval `opam env`
# check you got what you want
which ocaml
```

```
cd matmul_bench
sh install.sh
```

Export
-----
```
export TVM_HOME=/root/tvm_ttile
export PYTHONPATH=$TVM_HOME/python:${PYTHONPATH}
```

Change
------

Please change the HOME in main.py and matmul_bench/create.py

For Grid5000, it is the good home so you don't have to change.




Run
-----

For all convolutions:

```sh
python3 launch.py
```

Note that you can change the test of different configuration un launch.py

For a specific convolution:

```sh
python3 main.py <NAME_CONVOLUTION> <{AVX2, AVX512}> <NB_RUNS>
```


Explanation
-------

## Choice of tensorize

I choice to tensorize at the lowest possible level i.e. the loop where the reduction axes are inside this loop or this loop itself. Note that the reduction axes can be split, so it is mandatory to have one loop of each reduction axes not the entire loop.

## Measure

I launch 20 times run.py, I delete the 5 best times and the 5 worst times and I compute the mean of the 10 others. I launch run.py in order to reduce the observed instability.



Files
----
```
input_conv.py               Dictionnary with convolution sizes
launch.py                   Launch main.py for all input
main.py                     Generate C files with TTile and compute the convolution with tensorize
test.py                     Compute the convolution with tensorize for convolution in the folder c_files


```
