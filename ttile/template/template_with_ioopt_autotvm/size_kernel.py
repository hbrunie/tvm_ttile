dic = {}


dic["i7"] = {
    "MobilNet_1": {
        "in_channels_kernel" : 1,
        "out_channels_kernel": 32,
        "xx_kernel"          : 1,
        "yy_kernel"          : 1,
        "kernel_h_kernel"    : 3,
        "kernel_w_kernel"    : 3
    }
}



def size_kernel(name_conv, archi):
    
    return dic[archi][name_conv]