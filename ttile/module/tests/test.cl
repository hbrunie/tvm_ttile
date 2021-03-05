__kernel void default_function_kernel0(__global float* restrict T_dense, __global float* restrict A, __global float* restrict B) {
  T_dense[(((((int)get_group_id(1)) * 512) + ((int)get_group_id(0))))] = 2.000000e+00f;
  for (int k = 0; k < 512; ++k) {
    T_dense[(((((int)get_group_id(1)) * 512) + ((int)get_group_id(0))))] = 7.5;//(T_dense[(((((int)get_group_id(1)) * 512) + ((int)get_group_id(0))))] + (A[(((((int)get_group_id(1)) * 512) + k))] * B[(((((int)get_group_id(0)) * 512) + k))]));
  }
}

