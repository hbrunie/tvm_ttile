# External Libraries


## To create the library

```sh

gcc -o ttile.o -c ttile.c
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/

```

## To test the library

```sh

cd tests
python3 mylib.py

```

## Use of TTile

TTile can be used in three different ways:

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
