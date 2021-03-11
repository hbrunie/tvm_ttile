__kernel void default_function_kernel0(__global float* restrict compute, __global float* restrict A, __global float* restrict W) {
  for (int out_channels = 0; out_channels < 128; ++out_channels) {
    compute[(((((int)get_group_id(0)) * 128) + out_channels))] = 0.000000e+00f;
    for (int axe_in_channels = 0; axe_in_channels < 128; ++axe_in_channels) {
      for (int axe_kernel_h = 0; axe_kernel_h < 3; ++axe_kernel_h) {
        for (int axe_kernel_w = 0; axe_kernel_w < 3; ++axe_kernel_w) {
          compute[(((((int)get_group_id(0)) * 128) + out_channels))] = (compute[(((((int)get_group_id(0)) * 128) + out_channels))] + (A[(((((((((int)get_group_id(0)) / 56) * 7424) + (axe_kernel_w * 7424)) + (axe_kernel_h * 128)) + ((((int)get_group_id(0)) % 56) * 128)) + axe_in_channels))] * W[(((((axe_kernel_w * 49152) + (axe_kernel_h * 16384)) + (axe_in_channels * 128)) + out_channels))]));
        }
      }
    }
  }
}

