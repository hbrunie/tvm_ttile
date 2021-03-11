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

