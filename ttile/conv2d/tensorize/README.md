Tensorize
======

Install Dependency
-----

```
apt-get install -y git
apt-get install -y python3 python3-dev python3-setuptools gcc libtinfo-dev zlib1g-dev build-essential cmake libedit-dev libxml2-dev llvm clang
apt-get install -y python-pip
apt-get install -y lsb-release wget software-properties-common pkg-config
bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
apt-get install -y python3-pip
echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo
git clone --recursive git@gitlab.inria.fr:spouget/tvm_ttile.git

(cd tvm_ttile && git checkout x86)
(cd tvm_ttile && mkdir build && cp cmake/config.cmake build/)
(cd tvm_ttile/build && cmake .. && make -j$(nproc))

pip3 install numpy decorator attrs tornado psutil xgboost cloudpickle pytest argcomplete

apt-get install -y libpapi-dev papi-tools
sysctl -w kernel.perf_event_paranoid=0
git clone git@gitlab.inria.fr:ntollena/matmul_bench.git


apt-get install -y opam
# environment setup
opam init
eval `opam env`
# install given version of the compiler
opam switch create 4.12.0
eval `opam env`
# check you got what you want
which ocaml
opam install dune
eval `opam env`
(cd matmul_bench && sh install.sh)
eval `opam env`
(cd matmul_bench/ml_utils && make python_install)

```

Export
-----
```
export TVM_HOME=/root/tvm_ttile
export PYTHONPATH=$TVM_HOME/python:${PYTHONPATH}
```


Run
-----

For all convolutions:

```sh
python3 launch.py <NAME CPU> --avx <AVX2 / AVX512> --nbthreads <NUMBER OF THREAD> --nbconfiguration <NUMBER OF DIFFERENTES CONFIGURATIONS TO RUN> --architecture <NAME ARCHITECTURE>
```

For grid5000:

```sh
python3 launch.py XeonGold6130 --avx avx512 --architecture skylake --nbthreads 32

```

Note that you can change the test of different configuration in launch.py

For a specific convolution:

```sh
python3 main.py <NAME_CONVOLUTION> <{AVX2, AVX512}> <NB_RUNS> <NAME CPU> <NUMBER OF THREAD>
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

Training for full CNN
---------------------

When launching TVM+TTILE wiht for eg:
`python3 launch.py pinocchio --avx avx512 --nbthreads 1 --nbconfigurations 5 --architecture skylake --method random`
The script will use the directory `picke_files`  to dump automatically generate pickle binary files.
From `main.py`:
``` python
        for id_method_of_parallelization, method in enumerate(lpar_methods):
            information_ttile = information_ttile_all_method_parallelization[method]
            # Log parameters into a pickle file so we can restart it later
            letters = string.ascii_letters
            hashkey = ''.join(random.choice(letters) for i in range(6))  
            pickle_filename = "pickle_files/{}_{}_{}_err.pkl".format(name_conv, hashkey, id_information_ttile)
```

A column is added to the result CSV, which name is `hashkey`
``` python
            # IdRun;hashkey;InfottilePickleName;MethodParallelization;NameConv;Time(ms);
            csvdump_str  = str(id_information_ttile) + ";" + hashkey + ";" + pickle_filename +";" 
```
Thus reading the CSV file it is possible to get the binary pickle containing the `info_ttile` dictionnary with enough information to build the conv2dschedule.
This is done in `python/tvm/topi/x86/conv2d.py: def schedule_conv2d_nhwc_ttile(outs)`
