
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (7, x); T (16, f);
  T (16, c); T (1, x)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, x, xp_0, x52_p_0, xp_1, x52;
IND_TYPE y = 0;
IND_TYPE x53 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c73 = 0;
IND_TYPE f68 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (x, 1) (7 / 7)
x52 = 0;
x52_p_0 = 0;
c72 = 0;
c72_p_0 = 0;
f = 0;
fp_0 = 0;
			for (x = x52, xp_1 = x52_p_0, xp_0 = 0;x < x52 + 7;x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
						mem_vec_617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
						mem_vec_618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
						mem_vec_619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
						mem_vec_620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
						mem_vec_621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
						mem_vec_622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
						mem_vec_623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
						mem_vec_624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
						mem_vec_625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
						mem_vec_626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
						mem_vec_627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
						mem_vec_628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
						mem_vec_629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (c, 16) (16 / 1)
						for (c = c72, cp_1 = c72_p_0, cp_0 = 0;c < c72 + 16;c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_616);
							mem_vec_616 = vec_0;
							vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_617);
							mem_vec_617 = vec_3;
							scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);
							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_618);
							mem_vec_618 = vec_5;
							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_619);
							mem_vec_619 = vec_7;
							scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);
							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_620);
							mem_vec_620 = vec_8;
							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_621);
							mem_vec_621 = vec_10;
							scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);
							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_622);
							mem_vec_622 = vec_11;
							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_623);
							mem_vec_623 = vec_13;
							scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);
							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_624);
							mem_vec_624 = vec_14;
							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_625);
							mem_vec_625 = vec_16;
							scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);
							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_626);
							mem_vec_626 = vec_17;
							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_627);
							mem_vec_627 = vec_19;
							scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);
							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_628);
							mem_vec_628 = vec_20;
							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_629);
							mem_vec_629 = vec_22;
						}
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_616);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_617);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_618);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_619);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_620);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_621);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_622);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_623);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_624);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_625);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_626);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_627);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_628);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_629);
			}
}
