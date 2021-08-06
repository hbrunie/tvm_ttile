# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
"""
Adapted from https://github.com/tornadomeet/ResNet/blob/master/symbol_resnet.py
Original author Wei Wu

Implemented the following paper:

Kaiming He, Xiangyu Zhang, Shaoqing Ren, Jian Sun. "Identity Mappings in Deep Residual Networks"
"""
# pylint: disable=unused-argument
from tvm import relay
import tvm
from init import create_workload
import layers

import argcomplete, argparse
import os

parser = argparse.ArgumentParser(description='Execute full resnet CNN.')
parser.add_argument('--skylake_avx512',action='store_true',
        help="Add -mcpu=skylake-avx512 to TVM target.")

argcomplete.autocomplete(parser)
args = parser.parse_args()

def residual_unit(
    data,
    num_filter,
    stride,
    dim_match,
    name,
    bottle_neck=True,
    data_layout="NCHW",
    kernel_layout="IOHW",
):
    """Return ResNet Unit symbol for building ResNet

    Parameters
    ----------
    data : str
        Input data

    num_filter : int
        Number of output channels

    bnf : int
        Bottle neck channels factor with regard to num_filter

    stride : tuple
        Stride used in convolution

    dim_match : bool
        True means channel number between input and output is the same,
        otherwise means differ

    name : str
        Base name of the operators
    """
    bn_axis = data_layout.index("C")
    if bottle_neck:
        bn1 = layers.batch_norm_infer(data=data, epsilon=2e-5, axis=bn_axis, name=name + "_bn1")
        act1 = relay.nn.relu(data=bn1)
        conv1 = layers.conv2d(
            data=act1,
            channels=int(num_filter * 0.25),
            kernel_size=(1, 1),
            strides=stride,
            padding=(0, 0),
            name=name + "_conv1",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
        bn2 = layers.batch_norm_infer(data=conv1, epsilon=2e-5, axis=bn_axis, name=name + "_bn2")
        act2 = relay.nn.relu(data=bn2)
        conv2 = layers.conv2d(
            data=act2,
            channels=int(num_filter * 0.25),
            kernel_size=(3, 3),
            strides=(1, 1),
            padding=(1, 1),
            name=name + "_conv2",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
        bn3 = layers.batch_norm_infer(data=conv2, epsilon=2e-5, axis=bn_axis, name=name + "_bn3")
        act3 = relay.nn.relu(data=bn3)
        conv3 = layers.conv2d(
            data=act3,
            channels=num_filter,
            kernel_size=(1, 1),
            strides=(1, 1),
            padding=(0, 0),
            name=name + "_conv3",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
        if dim_match:
            shortcut = data
        else:
            shortcut = layers.conv2d(
                data=act1,
                channels=num_filter,
                kernel_size=(1, 1),
                strides=stride,
                name=name + "_sc",
                data_layout=data_layout,
                kernel_layout=kernel_layout,
            )
        return relay.add(conv3, shortcut)

    bn1 = layers.batch_norm_infer(data=data, epsilon=2e-5, axis=bn_axis, name=name + "_bn1")
    act1 = relay.nn.relu(data=bn1)
    conv1 = layers.conv2d(
        data=act1,
        channels=num_filter,
        kernel_size=(3, 3),
        strides=stride,
        padding=(1, 1),
        name=name + "_conv1",
        data_layout=data_layout,
        kernel_layout=kernel_layout,
    )
    bn2 = layers.batch_norm_infer(data=conv1, epsilon=2e-5, axis=bn_axis, name=name + "_bn2")
    act2 = relay.nn.relu(data=bn2)
    conv2 = layers.conv2d(
        data=act2,
        channels=num_filter,
        kernel_size=(3, 3),
        strides=(1, 1),
        padding=(1, 1),
        name=name + "_conv2",
        data_layout=data_layout,
        kernel_layout=kernel_layout,
    )

    if dim_match:
        shortcut = data
    else:
        shortcut = layers.conv2d(
            data=act1,
            channels=num_filter,
            kernel_size=(1, 1),
            strides=stride,
            name=name + "_sc",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
    return relay.add(conv2, shortcut)


def resnet(
    units,
    num_stages,
    filter_list,
    num_classes,
    data_shape,
    bottle_neck=True,
    layout="NCHW",
    dtype="float32",
):
    """Return ResNet Program.

    Parameters
    ----------
    units : list
        Number of units in each stage

    num_stages : int
        Number of stages

    filter_list : list
        Channel size of each stage

    num_classes : int
        Output size of symbol

    data_shape : tuple of int.
        The shape of input data.

    bottle_neck : bool
        Whether apply bottleneck transformation.

    layout: str
        The data layout for conv2d

    dtype : str
        The global data type.
    """

    data_layout = layout
    kernel_layout = "OIHW" if layout == "NCHW" else "HWIO"
    bn_axis = data_layout.index("C")

    num_unit = len(units)
    assert num_unit == num_stages
    data = relay.var("data", shape=data_shape, dtype=dtype)
    data = layers.batch_norm_infer(
        data=data, epsilon=2e-5, axis=bn_axis, scale=False, name="bn_data"
    )
    (_, _, height, _) = data_shape
    if layout == "NHWC":
        (_, height, _, _) = data_shape
    if height <= 32:  # such as cifar10
        body = layers.conv2d(
            data=data,
            channels=filter_list[0],
            kernel_size=(3, 3),
            strides=(1, 1),
            padding=(1, 1),
            name="conv0",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
    else:  # often expected to be 224 such as imagenet
        body = layers.conv2d(
            data=data,
            channels=filter_list[0],
            kernel_size=(7, 7),
            strides=(2, 2),
            padding=(3, 3),
            name="conv0",
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
        body = layers.batch_norm_infer(data=body, epsilon=2e-5, axis=bn_axis, name="bn0")
        body = relay.nn.relu(data=body)
        body = relay.nn.max_pool2d(
            data=body, pool_size=(3, 3), strides=(2, 2), padding=(1, 1), layout=data_layout
        )

    ##TODO: uncomment list. Right now debugging.
    ## we use just one conv2d, the one above.
    for i in range(num_stages):
        body = residual_unit(
            body,
            filter_list[i + 1],
            (1 if i == 0 else 2, 1 if i == 0 else 2),
            False,
            name="stage%d_unit%d" % (i + 1, 1),
            bottle_neck=bottle_neck,
            data_layout=data_layout,
            kernel_layout=kernel_layout,
        )
        for j in range(units[i] - 1):
            body = residual_unit(
                body,
                filter_list[i + 1],
                (1, 1),
                True,
                name="stage%d_unit%d" % (i + 1, j + 2),
                bottle_neck=bottle_neck,
                data_layout=data_layout,
                kernel_layout=kernel_layout,
            )
    bn1 = layers.batch_norm_infer(data=body, epsilon=2e-5, axis=bn_axis, name="bn1")
    relu1 = relay.nn.relu(data=bn1)
    # Although kernel is not used here when global_pool=True, we should put one
    pool1 = relay.nn.global_avg_pool2d(data=relu1, layout=data_layout)
    flat = relay.nn.batch_flatten(data=pool1)
    fc1 = layers.dense_add_bias(data=flat, units=num_classes, name="fc1")
    net = relay.nn.softmax(data=fc1)
    return relay.Function(relay.analysis.free_vars(net), net)


def get_net(
    batch_size,
    num_classes,
    num_layers=50,
    image_shape=(3, 224, 224),
    layout="NCHW",
    dtype="float32",
    **kwargs,
):
    """
    Adapted from https://github.com/tornadomeet/ResNet/blob/master/train_resnet.py
    Original author Wei Wu
    """
    (_, height, _) = image_shape
    if layout == "NHWC":
        (height, _, _) = image_shape
    data_shape = (batch_size,) + image_shape
    if height <= 28:
        num_stages = 3
        if (num_layers - 2) % 9 == 0 and num_layers >= 164:
            per_unit = [(num_layers - 2) // 9]
            filter_list = [16, 64, 128, 256]
            bottle_neck = True
        elif (num_layers - 2) % 6 == 0 and num_layers < 164:
            per_unit = [(num_layers - 2) // 6]
            filter_list = [16, 16, 32, 64]
            bottle_neck = False
        else:
            raise ValueError("no experiments done on num_layers {}".format(num_layers))
        units = per_unit * num_stages
    else:
        #print("Resnet",num_layers)
        if num_layers >= 50:
            filter_list = [64, 256, 512, 1024, 2048]
            bottle_neck = True
        else:
            filter_list = [64, 64, 128, 256, 512]
            bottle_neck = False
        num_stages = 4
        if num_layers == 18:
            units = [2, 2, 2, 2]
        elif num_layers == 34:
            units = [3, 4, 6, 3]
        elif num_layers == 50:
            units = [3, 4, 6, 3]
        elif num_layers == 101:
            units = [3, 4, 23, 3]
        elif num_layers == 152:
            units = [3, 8, 36, 3]
        elif num_layers == 200:
            units = [3, 24, 36, 3]
        elif num_layers == 269:
            units = [3, 30, 48, 8]
        else:
            raise ValueError("no experiments done on num_layers {}".format(num_layers))

    return resnet(
        units=units,
        num_stages=num_stages,
        filter_list=filter_list,
        num_classes=num_classes,
        data_shape=data_shape,
        bottle_neck=bottle_neck,
        layout=layout,
        dtype=dtype,
    )


def get_workload(
    batch_size=1,
    num_classes=1000,
    num_layers=18,
    image_shape=(3, 224, 224),
    layout="NCHW",
    dtype="float32",
    **kwargs,
):
    """Get benchmark workload for resnet

    Parameters
    ----------
    batch_size : int
        The batch size used in the model

    num_classes : int, optional
        Number of classes

    num_layers : int, optional
        Number of layers

    image_shape : tuple, optional
        The input image shape

    layout: str
        The data layout for conv2d

    dtype : str, optional
        The data type

    kwargs : dict
        Extra arguments

    Returns
    -------
    mod : tvm.IRModule
        The relay module that contains a ResNet network.

    params : dict of str to NDArray
        The parameters.
    """
    net = get_net(
        batch_size=batch_size,
        num_classes=num_classes,
        num_layers=num_layers,
        image_shape=image_shape,
        dtype=dtype,
        layout=layout,
        **kwargs,
    )
    return create_workload(net)

## UNUSED code as MKLDNN aka OneDNN aka DNNL is finally not used.
#if not tvm.get_global_func("relay.ext.dnnl", True):
#    print("skip because DNNL codegen is not available")
#    exit(1)

from tvm.contrib import graph_executor
import numpy as np
dtype = "float32"
## default layout in get_workload: NCHW
image_shape = (3, 224, 224)
## LAYOUT needed for TTILE: NHWC
image_shape=(224,224,3)
mod , params = get_workload(image_shape=image_shape, layout="NHWC")
target = "llvm -libs=ttile"
if args.skylake_avx512:
    target += " -mcpu=skylake-avx512"
target = tvm.target.Target(target, host=target)
dev = tvm.cpu(0)

## Building the CNN:
## with optimization = 3 --> fuse conv2d with either relu or add
## with optimization = 0 --> no fusion: better for us.
with tvm.transform.PassContext(opt_level=0):
    lib = relay.build(mod, target=target, params = params)
m = graph_executor.GraphModule(lib["default"](dev))
## TODO: is layout ok for data_tvm generation?
data_tvm = tvm.nd.array(np.random.uniform(size=image_shape).astype(dtype))
m.set_input("data", data_tvm)
## just running
m.run()
## evaluating execution time
time_evaluation = False
if time_evaluation:
    ftimer = m.module.time_evaluator("run", dev, repeat=3, min_repeat_ms=500)
    prof_res = np.array(ftimer().results) * 1e3 # convert to ms
    print("Mean inference time full ResNet18 CNN (std dev): %.2f ms (%.2f ms)" % (np.mean(prof_res), np.std(prof_res)))

def comparing_different_results():
    """
        Debug function.
        Not tested lately, may not work.
        Goal is to compare output between different run (with and without
        padding for example) to highlight changes.
    """
    import pickle
    fname = "result_output_padding.pkl"
    for i in range(m.get_num_outputs()):
        out = m.get_output(i)
        nout = out.numpy()
        with open(fname, 'wb') as ouf:
            pickle.dump(nout, ouf)
    for i in range(m.get_num_outputs()):
        out = m.get_output(i)
        nout = out.numpy()
        with open(fname, 'rb') as inf:
            ref = pickle.load(inf)
            nref = np.array(ref)
        comparison = nref == nout
        equal_arrays = comparison.all()
        print(equal_arrays)
