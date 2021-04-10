Tensorize
======


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

## Comparison with TVM + IOOPT (i.e. I give order and tile sizes)

I compare the execution time of tensorize, tvm with one or two microkernels and tvm with just one microkernel

Files
----
```
input_conv.py               Dictionnary with convolution sizes
launch.py                   Launch main.py for all input
main.py                     Generate C files with TTile and compute the convolution with tensorize
main_tvm_1kernel.py         Compute the convolution with the same parameters (order and tile sizes) of TTile for one microkernel
main_tvm.py                 Compute the convolution with the same parameters (order and tile sizes) of TTile for one or two microkernels
run*.py                     Compute one convolution, it uses for measure


```