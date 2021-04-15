
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (4, f); T (1, c); T (7, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c114_p_0, cp_1, c114, f, fp_0, f114_p_0, fp_1, f114, h, hp_0, x, xp_0, x114_p_0, xp_1, x114, y, yp_0;
IND_TYPE y76 = 0;
IND_TYPE x115 = 0;
IND_TYPE h62 = 0;
IND_TYPE w = 0;
IND_TYPE c115 = 0;
IND_TYPE f115 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 2) (128 / 64)
f114 = 0;
f114_p_0 = 0;
y = 0;
yp_0 = 0;
x114 = 0;
x114_p_0 = 0;
c114 = 0;
c114_p_0 = 0;
f = 0;
fp_1 = 0;
					for (h = h62, hp_0 = 0;h < h62 + 3;h += 1, hp_0 += 1){
						// y = 4, x = 4, h = 1, w = 3, c = 64, f = 16
						// T (x, 4) (4 / 1)
						for (x = x114, xp_1 = x114_p_0, xp_0 = 0;x < x114 + 4;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									// y = 4, x = 1, h = 1, w = 3, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c114, cp_1 = c114_p_0, cp_0 = 0;c < c114 + 64;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_628);
										mem_vec_628 = vec_0;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);
										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_629);
										mem_vec_629 = vec_3;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_630);
										mem_vec_630 = vec_5;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);
										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_631);
										mem_vec_631 = vec_7;
										scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_11 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_628);
										mem_vec_628 = vec_9;
										scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
										vec_13 = _mm512_set1_ps(scal_5);
										vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_629);
										mem_vec_629 = vec_12;
										scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_6);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_630);
										mem_vec_630 = vec_14;
										scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
										vec_17 = _mm512_set1_ps(scal_7);
										vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_631);
										mem_vec_631 = vec_16;
										scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
										vec_19 = _mm512_set1_ps(scal_8);
										vec_20 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_628);
										mem_vec_628 = vec_18;
										scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
										vec_22 = _mm512_set1_ps(scal_9);
										vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_629);
										mem_vec_629 = vec_21;
										scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
										vec_24 = _mm512_set1_ps(scal_10);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_630);
										mem_vec_630 = vec_23;
										scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
										vec_26 = _mm512_set1_ps(scal_11);
										vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_631);
										mem_vec_631 = vec_25;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_628);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_629);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_630);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_631);
						}
					}
}
