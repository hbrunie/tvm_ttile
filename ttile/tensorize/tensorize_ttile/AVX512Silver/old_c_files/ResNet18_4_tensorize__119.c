
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (7, y); T (1, f); T (1, c); T (8, f)]
*/
IND_TYPE c, cp_0, c189_p_0, cp_1, c189, f, fp_0, f189_p_0, fp_1, f189, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y126 = 0;
IND_TYPE x176 = 0;
IND_TYPE h85 = 0;
IND_TYPE w = 0;
IND_TYPE c190 = 0;
IND_TYPE f190 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1573 ,mem_vec_1574 ,mem_vec_1575 ,mem_vec_1576 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 8) (128 / 16)
f189 = 0;
f189_p_0 = 0;
c189 = 0;
c189_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
					for (h = h85, hp_0 = 0;h < h85 + 3;h += 1, hp_0 += 1){
								mem_vec_1573 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_1574 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_1575 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_1576 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 16
								// T (c, 64) (64 / 1)
								for (c = c189, cp_1 = c189_p_0, cp_0 = 0;c < c189 + 64;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1573);
									mem_vec_1573 = vec_0;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);
									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1574);
									mem_vec_1574 = vec_3;
									scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1575);
									mem_vec_1575 = vec_5;
									scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);
									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1576);
									mem_vec_1576 = vec_7;
									scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
									vec_10 = _mm512_set1_ps(scal_4);
									vec_11 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_1573);
									mem_vec_1573 = vec_9;
									scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
									vec_13 = _mm512_set1_ps(scal_5);
									vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_1574);
									mem_vec_1574 = vec_12;
									scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_6);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_1575);
									mem_vec_1575 = vec_14;
									scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
									vec_17 = _mm512_set1_ps(scal_7);
									vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_1576);
									mem_vec_1576 = vec_16;
									scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
									vec_19 = _mm512_set1_ps(scal_8);
									vec_20 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
									vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_1573);
									mem_vec_1573 = vec_18;
									scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
									vec_22 = _mm512_set1_ps(scal_9);
									vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_1574);
									mem_vec_1574 = vec_21;
									scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
									vec_24 = _mm512_set1_ps(scal_10);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1575);
									mem_vec_1575 = vec_23;
									scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
									vec_26 = _mm512_set1_ps(scal_11);
									vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_1576);
									mem_vec_1576 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1573);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1574);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1575);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1576);
					}
}
