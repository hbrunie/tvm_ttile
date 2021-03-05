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

