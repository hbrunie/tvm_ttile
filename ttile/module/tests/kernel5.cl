__kernel void default_function_kernel0(__global float* restrict B, __global float* restrict A, __global float* restrict W, int yy, int xx, int ff) {
  B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] = 0.000000e+00f;
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      for (int rc = 0; rc < 100; ++rc) {
        B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] = (B[(((((yy * 16800) + (xx * 1200)) + (ff * 12)) + ((int)get_group_id(0))))] + ((((((1 <= (yy + ry)) && ((yy + ry) < 15)) && (1 <= (xx + rx))) && ((xx + rx) < 15)) ? A[((((((((yy * 16800) + (ry * 16800)) + (xx * 1200)) + (rx * 1200)) + (rc * 12)) + ((int)get_group_id(0))) - 18000))] : 0.000000e+00f) * W[(((((ry * 30000) + (rx * 10000)) + (rc * 100)) + ff))]));
      }
    }
  }
}

