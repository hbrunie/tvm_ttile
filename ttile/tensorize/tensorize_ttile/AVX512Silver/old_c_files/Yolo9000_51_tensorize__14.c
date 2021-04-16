
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (8, y);
  T (1, c); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, x, xp_0, x129_p_0, xp_1, x129, y, yp_0, y129_p_0, yp_1, y129;
IND_TYPE y130 = 0;
IND_TYPE x130 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c94 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1780 ,mem_vec_1781 ,mem_vec_1782 ,mem_vec_1783 ,mem_vec_1784 ,mem_vec_1785 ,mem_vec_1786 ,mem_vec_1787 ,mem_vec_1788 ,mem_vec_1789 ,mem_vec_1790 ,mem_vec_1791 ,mem_vec_1792 ,mem_vec_1793 ,mem_vec_1794 ,mem_vec_1795 ,mem_vec_1796 ,mem_vec_1797 ,mem_vec_1798 ,mem_vec_1799 ,mem_vec_1800 ,mem_vec_1801 ,mem_vec_1802 ,mem_vec_1803 ,mem_vec_1804 ,mem_vec_1805 ,mem_vec_1806 ,mem_vec_1807 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y129 = 0;
y129_p_0 = 0;
x129 = 0;
x129_p_0 = 0;
c93 = 0;
c93_p_0 = 0;
y = 0;
yp_1 = 0;
					for (x = x129, xp_1 = x129_p_0, xp_0 = 0;x < x129 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1780 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_1781 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_1782 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_1783 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_1784 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_1785 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_1786 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_1787 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_1788 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_1789 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_1790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_1791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c93, cp_1 = c93_p_0, cp_0 = 0;c < c93 + 128;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1780);
									mem_vec_1780 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1781);
									mem_vec_1781 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1782);
									mem_vec_1782 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1783);
									mem_vec_1783 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1784);
									mem_vec_1784 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1785);
									mem_vec_1785 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1786);
									mem_vec_1786 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1787);
									mem_vec_1787 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1788);
									mem_vec_1788 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1789);
									mem_vec_1789 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1790);
									mem_vec_1790 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1791);
									mem_vec_1791 = vec_18;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1780);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1781);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1782);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1783);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1784);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1785);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1786);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1787);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1788);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1789);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1790);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1791);
					}
}
