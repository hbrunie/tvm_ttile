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
"""Core kernel of dot product of 4 Int8 operations"""
# pylint: disable=invalid-name
import tvm
from tvm import te
import tvm.target.codegen


def dot_16x1x16_uint8_int8_int32():
    """Dispatch the most optimized intrin depending on the target"""
    mcpu = tvm.target.Target.current().mcpu

    assert mcpu in (
        "skylake-avx512",
        "cascadelake",
    ), "An old Intel machine that does not have fast Int8 support."
    if mcpu == "skylake-avx512":
        return dot_16x1x16_uint8_int8_int32_skylake()
    # cascadelake
    return dot_16x1x16_uint8_int8_int32_cascadelake()


def dot_16x1x16_uint8_int8_int32_skylake():
    """
    Int8 dot product by every 4 elements using AVX512 Skylake instructions.
    This function takes two arrays of uint8 and int8 datatype -- data[4] and
    kernel[16][4] -- and computes a dot product of data[4] with every
    4 elements of kernels, resulting in output[16] of int32 datatype.
    The pseudo code is as follows.
    .. code-block:: c
        void dot_16x1x16_uint8_int8_int32(uint8 data[4], int8 kernel[16][4],
                int32 output[16]){
            for (int i = 0; i < 16; i++){
                output[i] = 0;
                for (int k = 0; k < 4; k++){
                    output[i] += data[k] * kernel[i][k]
                }
            }
        }

    Physically, the kernel array sits in an AVX512 vector register and
    the data[4] is broadcasted to another AVX512 vector register. This
    function returns a TensorIntrin that can be used to tensorize
    a schedule.

    Returns
    -------
    intrin : TensorIntrin
        The Skylake int8 TensorIntrin that can be used in tensorizing schedule
    """

    int32_lanes = 16  # 16 int32 lanes in AVX512
    num_int8_elements = 4  # 4 int8 elements in int32
    data = te.placeholder((num_int8_elements,), dtype="uint8", name="data")
    kernel = te.placeholder((int32_lanes, num_int8_elements), dtype="int8", name="kernel")
    k = te.reduce_axis((0, num_int8_elements), name="k")
    C = te.compute(
        (int32_lanes,),
        lambda i: te.sum(data[k].astype("int32") * kernel[i, k].astype("int32"), axis=k),
        name="C",
    )

    a_buffer = tvm.tir.decl_buffer(
        data.shape, dtype="uint8", name="a_buffer", offset_factor=1, strides=[1]
    )
    b_buffer = tvm.tir.decl_buffer(
        kernel.shape, dtype="int8", name="b_buffer", offset_factor=1, strides=[te.var("ldw"), 1]
    )

    def _intrin_func(ins, outs):
        def _instr(index):
            ib = tvm.tir.ir_builder.create()
            if index == 1:
                ib.emit(outs[0].vstore(0, tvm.tir.const(0, "int32x16")))
                return ib.get()

            a_int8 = ins[0].vload([0], "uint8x4")
            re_int32 = tvm.tir.call_intrin("int32", "tir.reinterpret", a_int8)
            vec_ai32 = re_int32.astype("int32x16")
            vec_a = tvm.tir.call_intrin("int8x64", "tir.reinterpret", vec_ai32)
            vec_b = ins[1].vload([0, 0], "int8x64")
            vec_one = tvm.tir.const(1, "int16x32")
            pair_reduction = tvm.tir.call_llvm_pure_intrin(
                "int16x32",
                "llvm.x86.avx512.pmaddubs.w.512",
                tvm.tir.const(0, "uint32"),
                vec_a,
                vec_b,
            )
            quad_reduction = tvm.tir.call_llvm_pure_intrin(
                "int32x16",
                "llvm.x86.avx512.pmaddw.d.512",
                tvm.tir.const(0, "uint32"),
                pair_reduction,
                vec_one,
            )
            if index == 0:
                ib.emit(outs[0].vstore(0, quad_reduction))
            else:
                ib.emit(outs[0].vstore(0, quad_reduction + outs[0].vload([0], "int32x16")))
            return ib.get()

        # body, reset, update
        return _instr(0), _instr(1), _instr(2)

    buffer_params = {"offset_factor": 1}
    return te.decl_tensor_intrin(
        C.op,
        _intrin_func,
        binds={data: a_buffer, kernel: b_buffer},
        default_buffer_params=buffer_params,
    )


def dot_16x1x16_uint8_int8_int16():
    """
    Int8 dot product by every 2 elements using AVX512 Skylake instructions.
    This function takes two arrays of uint8 and int8 datatype -- data[2] and
    kernel[4][32][2] -- and computes a dot product of data[2] with every
    2 elements of kernels, resulting in output[4][32] of int16 datatype.
    The pseudo code is as follows.
    .. code-block:: c
        void dot_16x1x16_uint8_int8_int16(uint8 data[2], int8 kernel[32*4][2],
                int16 output[32*4]){
            for (int i = 0; i< 4; i++){
                for (int j = 0; j < 32; j++){
                    output[i][i] = 0;
                    for (int k = 0; k < 2; k++){
                        output[i][j][k] += data[k] * kernel[i][j][k]
                    }
                }
            }
        }

    Physically, the kernel array sits in four AVX512 vector registers and
    the data[2] is broadcasted to another AVX512 vector register. This
    function returns a TensorIntrin that can be used to tensorize
    a schedule.

    Returns
    -------
    intrin : TensorIntrin
        The Skylake int8 TensorIntrin that can be used in tensorizing schedule
    """

    int16_lanes = 4 * 32  # 4*32 int32 lanes in 4 AVX512 vector registers
    num_int8_elements = 2  # 2 int8 elements in int16
    data = te.placeholder((num_int8_elements,), dtype="uint8", name="data")
    kernel = te.placeholder((int16_lanes, num_int8_elements), dtype="int8", name="kernel")
    k = te.reduce_axis((0, num_int8_elements), name="k")
    C = te.compute(
        (int16_lanes,),
        lambda i: te.sum(data[k].astype("int16") * kernel[i, k].astype("int16"), axis=k),
        name="C",
    )

    a_buffer = tvm.tir.decl_buffer(
        data.shape, dtype="uint8", name="a_buffer", offset_factor=1, strides=[1]
    )
    b_buffer = tvm.tir.decl_buffer(kernel.shape, dtype="int8", name="b_buffer", offset_factor=1)
    # strides=[te.var('ldw'), 1, 1])

    def _intrin_func(ins, outs):
        def _instr(index):
            ib = tvm.tir.ir_builder.create()
            if index == 1:
                for i in range(4):
                    ib.emit(outs[0].vstore([i * 32], tvm.tir.const(0, "int16x32")))
                return ib.get()

            a_int8 = ins[0].vload([0], "uint8x2")
            re_int16 = tvm.tir.call_intrin("int16", "tir.reinterpret", a_int8)
            vec_ai16 = re_int16.astype("int16x32")
            vec_a = tvm.tir.call_intrin("int8x64", "tir.reinterpret", vec_ai16)

            for i in range(4):
                vec_b = ins[1].vload([i * 32, 0], "int8x64")
                pair_reduction = tvm.tir.call_llvm_pure_intrin(
                    "int16x32",
                    "llvm.x86.avx512.pmaddubs.w.512",
                    tvm.tir.const(0, "uint32"),
                    vec_a,
                    vec_b,
                )
                if index == 0:
                    ib.emit(outs[0].vstore([i * 32], pair_reduction))
                else:
                    ib.emit(
                        outs[0].vstore(
                            [i * 32], pair_reduction + outs[0].vload([i * 32], "int16x32")
                        )
                    )
            return ib.get()

        # body, reset, update
        return _instr(0), _instr(1), _instr(2)

    buffer_params = {"offset_factor": 1}
    return te.decl_tensor_intrin(
        C.op,
        _intrin_func,
        binds={data: a_buffer, kernel: b_buffer},
        default_buffer_params=buffer_params,
    )


def dot_16x1x16_uint8_int8_int32_cascadelake():
    """
    Int8 dot product by every 4 elements using AVX512VNNI Cascade Lake instructions.
    This function takes two arrays of uint8 and int8 datatype -- data[4] and
    kernel[16][4] -- and computes a dot product of data[4] with every
    4 elements of kernels, resulting in output[16] of int32 datatype.
    The pseudo code is as follows.
    .. code-block:: c
        void dot_16x1x16_uint8_int8_int32_cascadelake(uint8 data[4], int8 kernel[16][4],
                int32 output[16]){
            for (int i = 0; i < 16; i++){
                output[i] = 0;
                for (int k = 0; k < 4; k++){
                    output[i] += data[k] * kernel[i][k]
                }
            }
        }

    Physically, the kernel array sits in an AVX512 vector register and
    the data[4] is broadcasted to another AVX512 vector register. This
    function returns a TensorIntrin that can be used to tensorize
    a schedule.

    Returns
    -------
    intrin : TensorIntrin
        The Cascade Lake int8 TensorIntrin that can be used in tensorizing schedule
    """

    int32_lanes = 16  # 16 int32 lanes in AVX512
    num_int8_elements = 4  # 4 int8 elements in int32
    data = te.placeholder((num_int8_elements,), dtype="uint8", name="data")
    kernel = te.placeholder((int32_lanes, num_int8_elements), dtype="int8", name="kernel")
    k = te.reduce_axis((0, num_int8_elements), name="k")
    C = te.compute(
        (int32_lanes,),
        lambda i: te.sum(data[k].astype("int32") * kernel[i, k].astype("int32"), axis=k),
        name="C",
    )

    a_buffer = tvm.tir.decl_buffer(
        data.shape, dtype="uint8", name="a_buffer", offset_factor=1, strides=[1]
    )
    b_buffer = tvm.tir.decl_buffer(
        kernel.shape, dtype="int8", name="b_buffer", offset_factor=1, strides=[te.var("ldw"), 1]
    )

    def _intrin_func(ins, outs):
        def _instr(index):
            ib = tvm.tir.ir_builder.create()
            if index == 1:
                ib.emit(outs[0].vstore(0, tvm.tir.const(0, "int32x16")))
                return ib.get()

            a_int8 = ins[0].vload([0], "uint8x4")
            re_int32 = tvm.tir.call_intrin("int32", "tir.reinterpret", a_int8)
            vec_ai32 = re_int32.astype("int32x16")
            vec_b = ins[1].vload([0, 0], "int8x64")

            vnni_inst_name = "llvm.x86.avx512.vpdpbusd.512"
            llvm_id = tvm.target.codegen.llvm_lookup_intrinsic_id(vnni_inst_name)

            if llvm_id != 0:  # VNNI is available for current LLVM version
                vec_bi32 = tvm.tir.call_intrin("int32x16", "tir.reinterpret", vec_b)
                vec_zero = tvm.tir.const(0, "int32x16")
                quad_reduction = tvm.tir.call_llvm_pure_intrin(
                    "int32x16",
                    "llvm.x86.avx512.vpdpbusd.512",
                    tvm.tir.const(0, "uint32"),
                    vec_zero,
                    vec_ai32,
                    vec_bi32,
                )
            else:  # Fall back to the normal AVX512
                vec_a = tvm.tir.call_intrin("int8x64", "tir.reinterpret", vec_ai32)
                vec_one = tvm.tir.const(1, "int16x32")
                pair_reduction = tvm.tir.call_llvm_pure_intrin(
                    "int16x32",
                    "llvm.x86.avx512.pmaddubs.w.512",
                    tvm.tir.const(0, "uint32"),
                    vec_a,
                    vec_b,
                )
                quad_reduction = tvm.tir.call_llvm_pure_intrin(
                    "int32x16",
                    "llvm.x86.avx512.pmaddw.d.512",
                    tvm.tir.const(0, "uint32"),
                    pair_reduction,
                    vec_one,
                )

            if index == 0:
                ib.emit(outs[0].vstore(0, quad_reduction))
            else:
                ib.emit(outs[0].vstore(0, quad_reduction + outs[0].vload([0], "int32x16")))
            return ib.get()

        # body, reset, update
        return _instr(0), _instr(1), _instr(2)

    buffer_params = {"offset_factor": 1}
    return te.decl_tensor_intrin(
        C.op,
        _intrin_func,
        binds={data: a_buffer, kernel: b_buffer},
        default_buffer_params=buffer_params,
    )

def generate_ttile_conv2d(files):
    cc_code_begin = """
extern "C" {
    #include <stdio.h>
    """

    if len(files) == 1:
        cc_code_midle = files[0]
    else:
        cc_code_midle = files[0]
        cc_code_midle += "\n\n"
        cc_code_midle += files[1]

    cc_code_end = """
    void ttile_conv2d_reset(float * Output, int F, int X, int Y, int strideO1, int strideO2) {
        /*
        Simple Convolution

        Inputs:
            - Output: Output
            - F: out_channels
            - X: width
            - Y: height

        */
        for (int f=0; f<F; f++){
            for (int y=0; y<Y; y++){
                for (int x=0; x<X; x++){
                    Output[x*strideO1 + y*strideO2 + f] = 0.0;
                }
            }
        }
        return;
    }
}
    """
    cc_code = cc_code_begin + cc_code_midle + cc_code_end
    return cc_code

def conv_impl(option_compilation, files):
    cc_code = generate_ttile_conv2d(files)
    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    options = option_compilation
    # Create LLVM ir from c source code
    ll_code = clang.create_llvm(cc_code, output=ll_path, options=options)
    return ll_code

def intrin_conv(name_function, W, H, C, F, X, Y, stride_w, stride_h):

    """
    W = kernel_w,
    H = kernel_h,
    C = in_channels,
    F = out_channels,
    X = width,
    Y = height
    """
    if stride_h == 1:
        a = te.placeholder((1, X  + W - 1, Y  + H - 1, C), name="a")
    else:
        a = te.placeholder((1, X * stride_w + W - 1, Y * stride_h + H - 1, C), name="a")
    w = te.placeholder((W, H, C, F), name="w")

    axe_in_channels = te.reduce_axis((0, C), name="axe_in_channels")
    axe_kernel_h = te.reduce_axis((0, H), name="axe_kernel_h")
    axe_kernel_w = te.reduce_axis((0, W), name="axe_kernel_w")

    strideA1 = tvm.te.var("sA1")
    strideA2 = tvm.te.var("sA2")
    strideA3 = tvm.te.var("sA3")

    strideB1 = tvm.te.var("sB1")
    strideB2 = tvm.te.var("sB2")
    strideB3 = tvm.te.var("sB3")

    strideC1 = tvm.te.var("sC1")
    strideC2 = tvm.te.var("sC2")
    strideC3 = tvm.te.var("sC3")

    o = te.compute(
    (1, X, Y, F),
    lambda batch, xx, yy, out_channels: te.sum(
        a[batch, stride_w * xx + axe_kernel_w, stride_h * yy + axe_kernel_h, axe_in_channels]* w[axe_kernel_w, axe_kernel_h, axe_in_channels, out_channels ],
        axis=[axe_in_channels, axe_kernel_h, axe_kernel_w],)
    )
    Ab = tvm.tir.decl_buffer(a.shape, a.dtype, name="A", offset_factor=1, strides=[strideA1, strideA2, strideA3, 1])
    Ww = tvm.tir.decl_buffer(w.shape, w.dtype, name="W", offset_factor=1, strides=[strideB1, strideB2, strideB3, 1])
    Oo = tvm.tir.decl_buffer(o.shape, o.dtype, name="O", offset_factor=1, strides=[strideC1, strideC2, strideC3, 1])


    def intrin_func(ins, outs):
        aa, ww = ins
        cc = outs[0]


        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    name_function,
                    cc.access_ptr("w"),
                    aa.access_ptr("r"),
                    ww.access_ptr("r"),
                    X,
                    W,
                    Y,
                    H,
                    C,
                    F,
                )
            )
            return ib.get()

        def _reduce_reset():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "float32",
                    "ttile_conv2d_reset",
                    cc.access_ptr("w"),
                    F,
                    X,
                    Y,
                    cc.strides[1],
                    cc.strides[2],
                )
            )
            return ib.get()

        def _reduce_update():
            return _body()

        return _body(), _reduce_reset(), _reduce_update()

    return te.decl_tensor_intrin(o.op, intrin_func, binds={a: Ab, w: Ww, o: Oo})