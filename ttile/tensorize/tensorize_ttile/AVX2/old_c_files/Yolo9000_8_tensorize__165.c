
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (2, c); T (17, y); T (4, x); T (4, f); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c512_p_0, c513_p_0, cp_1, c512_p_1, cp_2, c512, c513, f, fp_0, f307_p_0, fp_1, f307, h, hp_0, w, wp_0, x, xp_0, x351_p_0, xp_1, x351, y, yp_0;
IND_TYPE y234 = 0;
IND_TYPE x352 = 0;
IND_TYPE h174 = 0;
IND_TYPE w198 = 0;
IND_TYPE c514 = 0;
IND_TYPE f308 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3356 ,mem_vec_3357 ,mem_vec_3358 ,mem_vec_3359 ,mem_vec_3360 ,mem_vec_3361 ,mem_vec_3362 ,mem_vec_3363 ,mem_vec_3364 ,mem_vec_3365 ,mem_vec_3366 ,mem_vec_3367 ,mem_vec_3368 ,mem_vec_3369 ,mem_vec_3370 ,mem_vec_3371 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f307 = 0;
f307_p_0 = 0;
c513 = 0;
c513_p_0 = 0;
f = 0;
fp_1 = 0;
x351 = 0;
x351_p_0 = 0;
y = 0;
yp_0 = 0;
c512 = 0;
c512_p_1 = 0;
						for (h = h174, hp_0 = 0;h < h174 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 32, f = 32
							// T (x, 17) (17 / 1)
							for (x = x351, xp_1 = x351_p_0, xp_0 = 0;x < x351 + 17;x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w198, wp_0 = 0;w < w198 + 3;w += 1, wp_0 += 1){
											mem_vec_3356 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3357 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_3358 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3359 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_3360 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3361 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_3362 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3363 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_3364 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3365 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_3366 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3367 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_3368 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3369 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_3370 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3371 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c512, cp_2 = c512_p_1, cp_1 = c512_p_0, cp_0 = 0;c < c512 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3356);
												mem_vec_3356 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3357);
												mem_vec_3357 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3358);
												mem_vec_3358 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3359);
												mem_vec_3359 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3360);
												mem_vec_3360 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3361);
												mem_vec_3361 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3362);
												mem_vec_3362 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3363);
												mem_vec_3363 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3364);
												mem_vec_3364 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3365);
												mem_vec_3365 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3366);
												mem_vec_3366 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3367);
												mem_vec_3367 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3368);
												mem_vec_3368 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3369);
												mem_vec_3369 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3370);
												mem_vec_3370 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3371);
												mem_vec_3371 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3356);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3357);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3358);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3359);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3360);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3361);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3362);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3363);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3364);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3365);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3366);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3367);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3368);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3369);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3370);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3371);
								}
							}
						}
}
