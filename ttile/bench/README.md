# Benchmark

## Time Mobilenet3


| Version                            | Time  (ms) |
|----------------------------------- |:----------:|
| external library                   |  ~34       |
| replace all code with tensorize    |  ~30       |
| tensorize and //                   |  ~7.8      |

### To run external library

```sh
python3 gen_conv_mbnet3_avx2_library.py
```
I use the external library inside so you need to do:

```sh
gcc -o ttile.o -c gen_conv_mbnet3_avx2_library.c -mavx2 -mfma -O3
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/
```

### To run replace all code with tensorize

```sh
python3 gen_conv_mbnet3_avx2_tensorize_all.py
```

### To run tensorize and //  

```sh
python3 gen_conv_mbnet3_avx2_tensorize.py
```

I use the external library inside so you need to do:

```sh
gcc -o ttile.o -c gen_conv_mbnet3_avx2_library.c -mavx2 -mfma -O3
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/
```

## Time Yolo


| Version                            | Time  (ms) |
|----------------------------------- |:----------:|
| external library                   |  ~90       |
| replace all code with tensorize    |  ~103      |
| tensorize and //                   |  ~22.84    |


### To run external library

```sh
python3 gen_conv_yolo4_avx2_library.py
```
I use the external library inside so you need to do:

```sh
gcc -o ttile.o -c gen_conv_yolo4_avx2_library.c -mavx2 -mfma -O3
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/
```

### To run replace all code with tensorize

```sh
python3 gen_conv_yolo4_avx2_tensorize_all.py
```

### To run tensorize and //  

```sh
python3 gen_conv_yolo4_avx2_tensorize.py
```

I use the external library inside so you need to do:

```sh
gcc -o ttile.o -c gen_conv_yolo4_avx2_library.c -mavx2 -mfma -O3
gcc -shared -o libttile.so ttile.o -lm
sudo mv libttile.so /usr/lib/
```
