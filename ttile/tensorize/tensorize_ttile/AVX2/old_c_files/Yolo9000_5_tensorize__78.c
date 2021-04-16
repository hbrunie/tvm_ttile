
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (1, x); T (2, y); T (2, f); T (34, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, f, fp_0, x, xp_0, x760_p_0, x761_p_0, x762_p_0, xp_1, x760_p_1, x761_p_1, xp_2, x760_p_2, xp_3, x760, x761, x762, y, yp_0, y608_p_0, y609_p_0, yp_1, y608_p_1, yp_2, y608, y609;
IND_TYPE y610 = 0;
IND_TYPE x763 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c457 = 0;
IND_TYPE f304 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4352 ,mem_vec_4353 ,mem_vec_4354 ,mem_vec_4355 ,mem_vec_4356 ,mem_vec_4357 ,mem_vec_4358 ,mem_vec_4359 ,mem_vec_4360 ,mem_vec_4361 ,mem_vec_4362 ,mem_vec_4363 ,mem_vec_4364 ,mem_vec_4365 ,mem_vec_4366 ,mem_vec_4367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
y609 = 0;
y609_p_0 = 0;
x762 = 0;
x762_p_0 = 0;
y608 = 0;
y608_p_1 = 0;
x761 = 0;
x761_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x760 = 0;
x760_p_2 = 0;
c456 = 0;
c456_p_0 = 0;
								for (x = x760, xp_3 = x760_p_2, xp_2 = x760_p_1, xp_1 = x760_p_0, xp_0 = 0;x < x760 + 4;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4352 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4353 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_4354 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4355 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_4356 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4357 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_4358 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4359 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_4360 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4361 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_4362 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4363 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_4364 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4365 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_4366 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4367 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c456, cp_1 = c456_p_0, cp_0 = 0;c < c456 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4352);
												mem_vec_4352 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4353);
												mem_vec_4353 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4354);
												mem_vec_4354 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4355);
												mem_vec_4355 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4356);
												mem_vec_4356 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4357);
												mem_vec_4357 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4358);
												mem_vec_4358 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4359);
												mem_vec_4359 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4360);
												mem_vec_4360 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4361);
												mem_vec_4361 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4362);
												mem_vec_4362 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4363);
												mem_vec_4363 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4364);
												mem_vec_4364 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4365);
												mem_vec_4365 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4366);
												mem_vec_4366 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4367);
												mem_vec_4367 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4352);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4353);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4354);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4355);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4356);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4357);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4358);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4359);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4360);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4361);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4362);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4363);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4364);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4365);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4366);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4367);
								}
}
