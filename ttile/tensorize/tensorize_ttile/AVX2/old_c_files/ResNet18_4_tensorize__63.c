
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (1, f); T (1, c); T (1, f); T (1, y); T (4, f)]
*/
IND_TYPE c, cp_0, c183_p_0, cp_1, c183, f, fp_0, f244_p_0, f245_p_0, fp_1, f244_p_1, fp_2, f244, f245, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y141_p_0, yp_1, y141;
IND_TYPE y142 = 0;
IND_TYPE x122 = 0;
IND_TYPE h104 = 0;
IND_TYPE w98 = 0;
IND_TYPE c184 = 0;
IND_TYPE f246 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1504 ,mem_vec_1505 ,mem_vec_1506 ,mem_vec_1507 ,mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
f245 = 0;
f245_p_0 = 0;
y141 = 0;
y141_p_0 = 0;
f244 = 0;
f244_p_1 = 0;
c183 = 0;
c183_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
							for (h = h104, hp_0 = 0;h < h104 + 3;h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w98, wp_0 = 0;w < w98 + 3;w += 1, wp_0 += 1){
											mem_vec_1504 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1505 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_1506 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1507 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_1508 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1509 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_1510 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1511 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_1512 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1513 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_1514 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1515 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_1516 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1517 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_1518 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1519 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c183, cp_1 = c183_p_0, cp_0 = 0;c < c183 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1504);
												mem_vec_1504 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1505);
												mem_vec_1505 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1506);
												mem_vec_1506 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1507);
												mem_vec_1507 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1508);
												mem_vec_1508 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1509);
												mem_vec_1509 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1510);
												mem_vec_1510 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1511);
												mem_vec_1511 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1512);
												mem_vec_1512 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1513);
												mem_vec_1513 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1514);
												mem_vec_1514 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1515);
												mem_vec_1515 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1516);
												mem_vec_1516 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1517);
												mem_vec_1517 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1518);
												mem_vec_1518 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1519);
												mem_vec_1519 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1504);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1505);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1506);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1507);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1508);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1509);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1510);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1511);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1512);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1513);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1514);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1515);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1516);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1517);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1518);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1519);
								}
							}
}
