# Template with IOOPT

## To run the template

Choose your architecture, your target and the name of the input in launch.py and run this file:

```sh
python3 launch.py
```


## Idea

I take as input a size of microkernel and a permutation of loop e.g.

```
CPU:[f,y],  L1:[c,w,h],  L2:[x,y,c],  MEM:[y,x,f,c,w,h]
```

The size of CPU, L1 and MEM are fixed.

CPU and L1 are fixed by the size of microkernel and MEM are fixed by the size of the convolution.

I will use autoTVM for the size of L2. AutoTVM must search size of axis which multiply the size of this axis in the microkernel and divide the size of this axis in MEM.


For example:

if Height (axe y) = 20 and y in the microkernel has a size of 2 then autoTVM has 4 possibilities which are [2, 4, 10, 20].


Let y_kernel the size of y in the kernel and y_size the size of y determine by the convoluiton.

The knob will be define as [k for k in range(1, y_size + 1) if (y_size%k == 0 and k%y_kernel == 0)]

