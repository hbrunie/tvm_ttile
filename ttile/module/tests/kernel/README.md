# Kernel

## Kernel 1
```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W) {
  B[((((((int)get_group_id(2)) * 1200) + (((int)get_group_id(1)) * 12)) + ((int)get_group_id(0))))] = 0.000000e+00f;
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      for (int rc = 0; rc < 100; ++rc) {
        B[((((((int)get_group_id(2)) * 1200) + (((int)get_group_id(1)) * 12)) + ((int)get_group_id(0))))] = (B[((((((int)get_group_id(2)) * 1200) + (((int)get_group_id(1)) * 12)) + ((int)get_group_id(0))))] + ((((((1 <= ((((int)get_group_id(2)) / 14) + ry)) && (((((int)get_group_id(2)) / 14) + ry) < 15)) && (1 <= (rx + (((int)get_group_id(2)) % 14)))) && ((rx + (((int)get_group_id(2)) % 14)) < 15)) ? A[(((((((ry * 16800) + (((int)get_group_id(2)) * 1200)) + (rx * 1200)) + (rc * 12)) + ((int)get_group_id(0))) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ((int)get_group_id(1))))]));
      }
    }
  }
}
```

## Kernel 2
```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W) {
  for (int xx = 0; xx < 14; ++xx) {
    for (int ff = 0; ff < 100; ++ff) {
      for (int nn = 0; nn < 12; ++nn) {
        B[(((((((int)get_group_id(0)) * 16800) + (xx * 1200)) + (ff * 12)) + nn))] = 0.000000e+00f;
        for (int ry = 0; ry < 3; ++ry) {
          for (int rx = 0; rx < 3; ++rx) {
            for (int rc = 0; rc < 100; ++rc) {
              B[(((((((int)get_group_id(0)) * 16800) + (xx * 1200)) + (ff * 12)) + nn))] = (B[(((((((int)get_group_id(0)) * 16800) + (xx * 1200)) + (ff * 12)) + nn))] + ((((((1 <= (((int)get_group_id(0)) + ry)) && ((((int)get_group_id(0)) + ry) < 15)) && (1 <= (xx + rx))) && ((xx + rx) < 15)) ? A[((((((((((int)get_group_id(0)) * 16800) + (ry * 16800)) + (xx * 1200)) + (rx * 1200)) + (rc * 12)) + nn) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
            }
          }
        }
      }
    }
  }
}

```

## Kernel 3
```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W) {
  for (int ff = 0; ff < 100; ++ff) {
    for (int nn = 0; nn < 12; ++nn) {
      B[((((((int)get_group_id(0)) * 1200) + (ff * 12)) + nn))] = 0.000000e+00f;
      for (int ry = 0; ry < 3; ++ry) {
        for (int rx = 0; rx < 3; ++rx) {
          for (int rc = 0; rc < 100; ++rc) {
            B[((((((int)get_group_id(0)) * 1200) + (ff * 12)) + nn))] = (B[((((((int)get_group_id(0)) * 1200) + (ff * 12)) + nn))] + ((((((1 <= ((((int)get_group_id(0)) / 14) + ry)) && (((((int)get_group_id(0)) / 14) + ry) < 15)) && (1 <= (rx + (((int)get_group_id(0)) % 14)))) && ((rx + (((int)get_group_id(0)) % 14)) < 15)) ? A[(((((((ry * 16800) + (((int)get_group_id(0)) * 1200)) + (rx * 1200)) + (rc * 12)) + nn) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
          }
        }
      }
    }
  }
}

```

## Kernel 4x

```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W, int yy, int xx, int ff) {
  B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] = 0.000000e+00f;
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      for (int rc = 0; rc < 100; ++rc) {
        B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] = 
        (B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] + 
        ((((((1 <= (yy + ry)) && ((yy + ry) < 15)) && (1 <= (xx + rx))) && ((xx + rx) < 15)) ? A[((((((((yy * 16800) + (ry * 16800)) + (xx * 1200)) + (rx * 1200)) + (rc * 12)) + ((int)get_group_id(0))) - 18000))] : 0.000000e+00f) 
        * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
      }
    }
  }
}
```

## Kernel 4y

```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W, int yy, int xx, int ff) {
  B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(1))))] = 0.000000e+00f;
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      for (int rc = 0; rc < 100; ++rc) {
        B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(1))))] = (B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(1))))] + ((((((1 <= (yy + ry)) && ((yy + ry) < 15)) && (1 <= (xx + rx))) && ((xx + rx) < 15)) ? A[((((((((yy * 16800) + (ry * 16800)) + (xx * 1200)) + (rx * 1200)) + (rc * 12)) + ((int)get_group_id(1))) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
      }
    }
  }
}

```


## Kernel 4z

```opencl
__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W, int yy, int xx, int ff) {
  B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(2))))] = 0.000000e+00f;
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      for (int rc = 0; rc < 100; ++rc) {
        B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(2))))] = (B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(2))))] + ((((((1 <= (yy + ry)) && ((yy + ry) < 15)) && (1 <= (xx + rx))) && ((xx + rx) < 15)) ? A[((((((((yy * 16800) + (ry * 16800)) + (xx * 1200)) + (rx * 1200)) + (rc * 12)) + ((int)get_group_id(2))) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
      }
    }
  }
}
```


## Time

| Kernel   | Time on mppa (ms) |
|--------  |:-----------------:|
| Kernel1  | 1963              |
| Kernel2  | 2229              |
| Kernel3  | 2065              |
| Kernel4x | 26993             |
| Kernel4y | 26787             |
| Kernel4z | 26838             |

In comparison the same convolution (cpu.py) without optimisation on x86 (Intel(R) Core(TM) i7-3820 CPU @ 3.60GHz) is execute in 242 ms.


| Kernel   | Time on mppa (ms) with POCL_MPPA_EXTRA_EXEC_MODE=LW |
|--------  |:---------------------------------------------------:|
| Kernel1  | 124                                                 |
| Kernel2  | 744                                                 |
| Kernel3  | 165                                                 |
| Kernel4x | 24842                                               |
| Kernel4y |                                                |
| Kernel4z |                                                |