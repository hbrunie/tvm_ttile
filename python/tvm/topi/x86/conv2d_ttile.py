"""Conv2D schedule on x86"""

import logging

import tvm
from tvm import te
from tvm import autotvm
from .. import nn
from ..nn.conv2d import conv2d_infer_layout, _get_workload as _get_conv2d_workload
from ..nn.conv2d import unpack_NCHWc_to_nchw
from ..nn.depthwise_conv2d import _get_workload as _get_depthwise_conv2d_workload
from ..nn.utils import get_pad_tuple
from ..utils import get_const_tuple, traverse_inline
from . import conv2d_avx_1x1, conv2d_avx_common
from tvm.contrib import ttile
from .. import generic, tag

logger = logging.getLogger("topi")

@autotvm.register_topi_compute("conv2d_NHWC_ttile.x86")
def conv2d_ttile(cfg, data, kernel, strides, padding, dilation, out_dtype):
    """Compute conv2d using Ttile library"""

    batch_size, in_channels, th, tw = get_const_tuple(data.shape)
    out_channels, in_channels, kernel_h, kernel_w = get_const_tuple(kernel.shape)

    height = th - kernel_h + 1
    width = tw - kernel_w + 1

    return ttile.conv2d(data, kernel, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, 1, 1, strides[1], strides[0], 0, 0)


@autotvm.register_topi_schedule("conv2d_ttile.x86")
def schedule_conv2d_ttile(cfg, outs):
    return generic.schedule_extern(outs)