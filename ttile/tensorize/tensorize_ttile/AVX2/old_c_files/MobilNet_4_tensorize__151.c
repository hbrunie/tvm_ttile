
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (4, f); T (4, c); T (1, f); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c219_p_0, cp_1, c219, f, fp_0, f214_p_0, f215_p_0, fp_1, f214_p_1, fp_2, f214, f215, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y111_p_0, yp_1, y111;
IND_TYPE y112 = 0;
IND_TYPE x110 = 0;
IND_TYPE h86 = 0;
IND_TYPE w80 = 0;
IND_TYPE c220 = 0;
IND_TYPE f216 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1408 ,mem_vec_1409 ,mem_vec_1410 ,mem_vec_1411 ,mem_vec_1412 ,mem_vec_1413 ,mem_vec_1414 ,mem_vec_1415 ,mem_vec_1416 ,mem_vec_1417 ,mem_vec_1418 ,mem_vec_1419 ,mem_vec_1420 ,mem_vec_1421 ,mem_vec_1422 ,mem_vec_1423 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f215 = 0;
f215_p_0 = 0;
y111 = 0;
y111_p_0 = 0;
f214 = 0;
f214_p_1 = 0;
c219 = 0;
c219_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
							for (h = h86, hp_0 = 0;h < h86 + 3;h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w80, wp_0 = 0;w < w80 + 3;w += 1, wp_0 += 1){
											mem_vec_1408 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1409 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_1410 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1411 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_1412 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1413 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_1414 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1415 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_1416 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1417 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_1418 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1419 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_1420 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1421 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_1422 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1423 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c219, cp_1 = c219_p_0, cp_0 = 0;c < c219 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1408);
												mem_vec_1408 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1409);
												mem_vec_1409 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1410);
												mem_vec_1410 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1411);
												mem_vec_1411 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1412);
												mem_vec_1412 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1413);
												mem_vec_1413 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1414);
												mem_vec_1414 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1415);
												mem_vec_1415 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1416);
												mem_vec_1416 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1417);
												mem_vec_1417 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1418);
												mem_vec_1418 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1419);
												mem_vec_1419 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1420);
												mem_vec_1420 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1421);
												mem_vec_1421 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1422);
												mem_vec_1422 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1423);
												mem_vec_1423 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1408);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1409);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1410);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1411);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1412);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1413);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1414);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1415);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1416);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1417);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1418);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1419);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1420);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1421);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1422);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1423);
								}
							}
}
