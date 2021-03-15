# Create an external library

## Different call to my external library

External Libray can be used in three different ways, here an example with my external library TTile:

### With te.extern
```python3
Output = tvm.te.extern(
    (batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1),
    [Data, W],
    lambda ins, outs: tvm.tir.call_packed(
        "tvm.contrib.ttile.conv2d", ins[0], ins[1], outs[0], batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
    ),
    name="Output",
)
```

### By importing tvm.contrib.ttile
```python3
from tvm.contrib import ttile

Output = ttile.conv2d(Data, W, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w)
```

### By specifying in the target the library to use (-libs=ttile)
```python3
simple_net = relay.nn.conv2d(
    data=data, weight=weight, kernel_size=(3, 3), channels=in_channels, padding=(0, 0),
)
target = "llvm -libs=ttile"
```

## Add an external library to TVM

- Create a folder NAME_LIBRARY in src/runtime/contrib/

Please see https://github.com/S12P/tvm_ttile/tree/x86/src/runtime/contrib/ttile

- Add information of your library in /src/support/libinfo.cc
```C
#ifndef TVM_INFO_USE_TTILE
#define TVM_INFO_USE_TTILE "NOT-FOUND"
#endif
```
```C
{"USE_TTILE", TVM_INFO_USE_TTILE},
```
- Create a Cmake in cmake/modules/contrib/

Please see https://github.com/S12P/tvm_ttile/blob/x86/cmake/modules/contrib/TTILE.cmake
- Add information in cmake/config.cmake
```cmake
# TTILE 
set(USE_TTILE ON)
```
- Add information in CMakeLists.txt
```cmake
tvm_option(USE_TTILE "Build with Ttile" ON)
```
```cmake
include(cmake/modules/contrib/TTILE.cmake)
```
- Add information in cmake/modules/LibInfo.cmake
```cmake
TVM_INFO_USE_TTILE="${USE_TTILE}"
```

### To use import tvm.contrib.ttile

- add python/tvm/contrib/<NAME_LIBRARY>.py
Please see https://github.com/S12P/tvm_ttile/blob/x86/python/tvm/contrib/ttile.py

## To use -libs=ttile

- Add import of your library in python/tvm/topi/x86/__init__.py

```python
from .conv2d_ttile import *
```
- add startegy in python/tvm/relay/op/strategy/x86.py
```python
elif "ttile" in target.libs:
                strategy.add_implementation(
                    wrap_compute_conv2d(topi.x86.conv2d_ttile),
                    wrap_topi_schedule(topi.x86.schedule_conv2d_ttile),
                    name="conv2d_ttile.x86",
                )
```

- add file to python/tvm/topi/x86/<NAME_FUNCTION>_<NAME_LIBRARY>.py

Please see https://github.com/S12P/tvm_ttile/blob/x86/python/tvm/topi/x86/conv2d_ttile.py



