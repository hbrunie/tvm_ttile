
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (56, x); T (4, c); T (2, f); T (14, y); T (1, f); T (1, f)]
*/
IND_TYPE c, cp_0, c522_p_0, cp_1, c522, f, fp_0, f663_p_0, f664_p_0, fp_1, f663_p_1, fp_2, f663, f664, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y363 = 0;
IND_TYPE x521 = 0;
IND_TYPE h246 = 0;
IND_TYPE w278 = 0;
IND_TYPE c523 = 0;
IND_TYPE f665 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_6730 ,mem_vec_6731 ,mem_vec_6732 ,mem_vec_6733 ,mem_vec_6734 ,mem_vec_6735 ,mem_vec_6736 ,mem_vec_6737 ,mem_vec_6738 ,mem_vec_6739 ,mem_vec_6740 ,mem_vec_6741 ,mem_vec_6742 ,mem_vec_6743 ,mem_vec_6744 ,mem_vec_6745 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
f664 = 0;
f664_p_0 = 0;
f663 = 0;
f663_p_1 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c522 = 0;
c522_p_0 = 0;
x = 0;
xp_0 = 0;
						for (h = h246, hp_0 = 0;h < h246 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w278, wp_0 = 0;w < w278 + 3;w += 1, wp_0 += 1){
										mem_vec_6730 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6731 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_6732 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6733 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_6734 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6735 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_6736 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6737 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_6738 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6739 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_6740 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6741 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_6742 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6743 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_6744 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6745 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c522, cp_1 = c522_p_0, cp_0 = 0;c < c522 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6730);
											mem_vec_6730 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6731);
											mem_vec_6731 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6732);
											mem_vec_6732 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6733);
											mem_vec_6733 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6734);
											mem_vec_6734 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6735);
											mem_vec_6735 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6736);
											mem_vec_6736 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6737);
											mem_vec_6737 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6738);
											mem_vec_6738 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6739);
											mem_vec_6739 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6740);
											mem_vec_6740 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6741);
											mem_vec_6741 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6742);
											mem_vec_6742 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6743);
											mem_vec_6743 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6744);
											mem_vec_6744 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6745);
											mem_vec_6745 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6730);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_6731);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6732);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_6733);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6734);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_6735);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6736);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_6737);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6738);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_6739);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6740);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_6741);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6742);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_6743);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6744);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_6745);
							}
						}
}
