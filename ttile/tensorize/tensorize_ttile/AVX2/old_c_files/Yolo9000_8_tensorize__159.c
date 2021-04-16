
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (8, c); T (17, y); T (4, x); T (8, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c540_p_0, c541_p_0, cp_1, c540_p_1, cp_2, c540, c541, f, fp_0, f328_p_0, fp_1, f328, h, hp_0, w, wp_0, x, xp_0, x372_p_0, xp_1, x372, y, yp_0;
IND_TYPE y248 = 0;
IND_TYPE x373 = 0;
IND_TYPE h188 = 0;
IND_TYPE w212 = 0;
IND_TYPE c542 = 0;
IND_TYPE f329 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3468 ,mem_vec_3469 ,mem_vec_3470 ,mem_vec_3471 ,mem_vec_3472 ,mem_vec_3473 ,mem_vec_3474 ,mem_vec_3475 ,mem_vec_3476 ,mem_vec_3477 ,mem_vec_3478 ,mem_vec_3479 ,mem_vec_3480 ,mem_vec_3481 ,mem_vec_3482 ,mem_vec_3483 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f328 = 0;
f328_p_0 = 0;
c541 = 0;
c541_p_0 = 0;
f = 0;
fp_1 = 0;
x372 = 0;
x372_p_0 = 0;
y = 0;
yp_0 = 0;
c540 = 0;
c540_p_1 = 0;
						for (h = h188, hp_0 = 0;h < h188 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 8, f = 32
							// T (x, 17) (17 / 1)
							for (x = x372, xp_1 = x372_p_0, xp_0 = 0;x < x372 + 17;x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w212, wp_0 = 0;w < w212 + 3;w += 1, wp_0 += 1){
											mem_vec_3468 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3469 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_3470 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3471 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_3472 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3473 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_3474 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3475 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_3476 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3477 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_3478 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3479 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_3480 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3481 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_3482 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3483 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c540, cp_2 = c540_p_1, cp_1 = c540_p_0, cp_0 = 0;c < c540 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3468);
												mem_vec_3468 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3469);
												mem_vec_3469 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3470);
												mem_vec_3470 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3471);
												mem_vec_3471 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3472);
												mem_vec_3472 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3473);
												mem_vec_3473 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3474);
												mem_vec_3474 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3475);
												mem_vec_3475 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3476);
												mem_vec_3476 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3477);
												mem_vec_3477 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3478);
												mem_vec_3478 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3479);
												mem_vec_3479 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3480);
												mem_vec_3480 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3481);
												mem_vec_3481 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3482);
												mem_vec_3482 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3483);
												mem_vec_3483 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3468);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3469);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3470);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3471);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3472);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3473);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3474);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3475);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3476);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3477);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3478);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3479);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3480);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3481);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3482);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3483);
								}
							}
						}
}
