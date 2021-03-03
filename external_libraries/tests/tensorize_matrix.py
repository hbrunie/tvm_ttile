from __future__ import absolute_import, print_function

import tvm
from tvm import te
import tvm.testing
import numpy as np
from tvm.topi.utils import get_const_tuple

N, M, L = 1024, 512, 64
A = te.placeholder((N, L), name="A")
B = te.placeholder((M, L), name="B")
k = te.reduce_axis((0, L), name="k")
C = te.compute((N, M), lambda i, j: te.sum(A[i, k] * B[j, k], axis=k), name="C")
s = te.create_schedule(C.op)
print(tvm.lower(s, [A, B, C], simple_mode=True))
dtype = A.dtype
ctx = tvm.context("cpu", 0)

factor = 16
x, y = C.op.axis
(z,) = C.op.reduce_axis


yo, yi = s[C].split(y, factor=factor)
xo, xi = s[C].split(x, factor=factor)
zo, zi = s[C].split(z, factor=factor)

s[C].reorder(xo, yo, zo, xi, yi, zi)
print(tvm.lower(s, [A, B, C], simple_mode=True))

def gemv_impl():
    cc_code = """
      extern "C" int gemv_update(float *cc, float *aa, float *bb, int n, int m, int l, int strideA, int strideB, int strideC) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < l; ++k){
                    cc[i * strideC + j] += aa[i * strideA + k] * bb[j * strideB + k];
                    //cc[i] = i;
                }
            }
        }
        return 0;
      }
      extern "C" int gemv_reset(float *cc, int n, int m, int strideC) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                cc[i * strideC + j] = 0.0;
            }
        }
        return 0;
      }
    """
    from tvm.contrib import utils, clang

    temp = utils.tempdir()
    ll_path = temp.relpath("temp.ll")
    # Create LLVM ir from c source code
    ll_code = clang.create_llvm(cc_code, output=ll_path)
    return ll_code


def intrin_gemv(n, m, l):
    a = te.placeholder((n, l), name="a")
    b = te.placeholder((m, l), name="b")
    k = te.reduce_axis((0, l), name="k")

    strideA = tvm.te.var("sA")
    strideB = tvm.te.var("sB")
    strideC = tvm.te.var("sC")

    c = te.compute((n,m), lambda i, j: te.sum(a[i,k] * b[j, k], axis=k), name="c")
    Ab = tvm.tir.decl_buffer(a.shape, a.dtype, name="A", offset_factor=1, strides=[strideA, 1])
    Bb = tvm.tir.decl_buffer(b.shape, b.dtype, name="B", offset_factor=1, strides=[strideB, 1])
    Cb = tvm.tir.decl_buffer(c.shape, c.dtype, name="C", offset_factor=1, strides=[strideC, 1])

    def intrin_func(ins, outs):
        aa, bb = ins
        cc = outs[0]

        def _body():
            ib = tvm.tir.ir_builder.create()
            ib.emit(
                tvm.tir.call_extern(
                    "int32",
                    "gemv_update",
                    cc.access_ptr("w"),
                    aa.access_ptr("r"),
                    bb.access_ptr("r"),
                    n,
                    m,
                    l,
                    aa.strides[0],
                    bb.strides[0],
                    cc.strides[0],
                )
            )
            return ib.get()

        def _reduce_reset():
            ib = tvm.tir.ir_builder.create()
            ib.emit(tvm.tir.call_extern("int32", "gemv_reset", cc.access_ptr("w"), n, m, cc.strides[0],))
            return ib.get()

        def _reduce_update():
            return _body()

        return _body(), _reduce_reset(), _reduce_update()

    return te.decl_tensor_intrin(c.op, intrin_func, binds={a: Ab, b: Bb, c: Cb})



gemv = intrin_gemv(factor, factor, factor)
s[C].tensorize(xi, gemv)
s[C].pragma(yo, "import_llvm", gemv_impl())

print(tvm.lower(s, [A, B, C], simple_mode=True))

func = tvm.build(s, [A, B, C], target="llvm", name="gemv")
a = np.random.uniform(size=get_const_tuple(A.shape)).astype(dtype)
b = np.random.uniform(size=get_const_tuple(B.shape)).astype(dtype)
c = tvm.nd.array(np.ones(get_const_tuple(C.shape), dtype=dtype), ctx)
func(tvm.nd.array(a, ctx), tvm.nd.array(b, ctx), c)
tvm.testing.assert_allclose(c.asnumpy(), np.dot(a, b.T), rtol=1e-3)

# print(c.asnumpy())
print("ok")

