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

CPU and L1 are fixed by the size of microkernel and MEM are fixed by the size of the problem.

I will use autoTVM for the size of L2. AutoTVM must search size of axis which multiply the size of this axis in the microkernel and divide the size of this axis in MEM.


For example:

if Height (axe_y) = 20 and y in the microkernel is 2
