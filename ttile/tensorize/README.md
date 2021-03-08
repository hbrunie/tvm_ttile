# Tensorize


| Version  | Time with tensorize (ms) | Time without tensorize (ms) |
|--------- |:------------------------:|:---------------------------:|
| 1        | 12.15                    |         13.31               |
| 2        |          1.32            |                13.17        |
| 3        |                          |                             |
| 4        |                          |                             |


The time for V2 is better because of the reorder loop in the cc_code



# Replace all the code

The file replace_function_w_tensorize.py replace all the code by C code which I write directly in the file. Below the pseudo code:

```python
    @tir.call_extern("ttile_conv2d_reset", @tir.tvm_access_ptr(@tir.type_annotation(, dtype=float32), compute_2, 0, 32768, 2, dtype=handle), 32, 32, 32, 1024, 32, dtype=int32)
    @tir.call_extern("Mttile_conv2d", @tir.tvm_access_ptr(@tir.type_annotation(, dtype=float32), W_2, 0, 9216, 1, dtype=handle), @tir.tvm_access_ptr(@tir.type_annotation(, dtype=float32), A_2, 0, 36992, 1, dtype=handle), @tir.tvm_access_ptr(@tir.type_annotation(, dtype=float32), compute_2, 0, 32768, 2, dtype=handle), 3, 3, 32, 32, 32, 32, 1024, 32, 1156, 34, 288, 9, 3, dtype=int32)

```