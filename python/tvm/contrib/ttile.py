import tvm
from tvm import te


def conv2d(A, W, batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w):
    """Create an extern op that compute 2D convolution with Ttile

    Parameters
    ----------
    A: Tensor
        input
    w: Tensor
        convolution weight
    o: Tensor
        output
    height: int
    width: int 
    in_channels: int
    out_channels: int
    kernel_h: int
    kernel_w: int
    pad_h: int
    pad_w: int
    stride_h: int
    stride_w: int
    dilation_h: int
    dilation_w: int
    """
    return te.extern(
    (batch_size, out_channels, (height + 2 * pad_h - kernel_h) // stride_h + 1, (width + 2 * pad_w - kernel_w) // stride_w + 1), #size output
    [A, W],
    lambda ins, outs: tvm.tir.call_packed(
        "tvm.contrib.ttile.conv2d", ins[0], ins[1], outs[0], batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
    ),
    name="Out",
)