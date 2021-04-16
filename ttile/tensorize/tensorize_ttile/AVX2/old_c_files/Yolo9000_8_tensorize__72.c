
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (4, c); T (17, y); T (4, x); T (4, f); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c528_p_0, c529_p_0, cp_1, c528_p_1, cp_2, c528, c529, f, fp_0, f319_p_0, fp_1, f319, h, hp_0, w, wp_0, x, xp_0, x363_p_0, xp_1, x363, y, yp_0;
IND_TYPE y242 = 0;
IND_TYPE x364 = 0;
IND_TYPE h182 = 0;
IND_TYPE w206 = 0;
IND_TYPE c530 = 0;
IND_TYPE f320 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f319 = 0;
f319_p_0 = 0;
c529 = 0;
c529_p_0 = 0;
f = 0;
fp_1 = 0;
x363 = 0;
x363_p_0 = 0;
y = 0;
yp_0 = 0;
c528 = 0;
c528_p_1 = 0;
						for (h = h182, hp_0 = 0;h < h182 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 16, f = 32
							// T (x, 17) (17 / 1)
							for (x = x363, xp_1 = x363_p_0, xp_0 = 0;x < x363 + 17;x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w206, wp_0 = 0;w < w206 + 3;w += 1, wp_0 += 1){
											mem_vec_3420 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3421 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_3422 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3423 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_3424 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3425 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_3426 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3427 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_3428 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3429 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_3430 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3431 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_3432 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3433 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_3434 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3435 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c528, cp_2 = c528_p_1, cp_1 = c528_p_0, cp_0 = 0;c < c528 + 16;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3420);
												mem_vec_3420 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3421);
												mem_vec_3421 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3422);
												mem_vec_3422 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3423);
												mem_vec_3423 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3424);
												mem_vec_3424 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3425);
												mem_vec_3425 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3426);
												mem_vec_3426 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3427);
												mem_vec_3427 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3428);
												mem_vec_3428 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3429);
												mem_vec_3429 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3430);
												mem_vec_3430 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3431);
												mem_vec_3431 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3432);
												mem_vec_3432 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3433);
												mem_vec_3433 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3434);
												mem_vec_3434 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3435);
												mem_vec_3435 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3420);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3421);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3422);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3423);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3424);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3425);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3426);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3427);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3428);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3429);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3430);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3431);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3432);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3433);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3434);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3435);
								}
							}
						}
}
