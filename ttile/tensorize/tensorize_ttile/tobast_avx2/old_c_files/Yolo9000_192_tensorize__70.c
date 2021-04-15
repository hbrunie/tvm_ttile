void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (256, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c708_p_0, cp_1, c708, f, fp_0, f944_p_0, f945_p_0, fp_1, f944_p_1, fp_2, f944, f945, x, xp_0, x944_p_0, x945_p_0, xp_1, x944_p_1, xp_2, x944, x945, y, yp_0;
IND_TYPE y472 = 0;
IND_TYPE x946 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c709 = 0;
IND_TYPE f946 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,mem_vec_8501 ,mem_vec_8502 ,mem_vec_8503 ,mem_vec_8504 ,mem_vec_8505 ,mem_vec_8506 ,mem_vec_8507 ,mem_vec_8508 ,mem_vec_8509 ,mem_vec_8510 ,mem_vec_8511 ,mem_vec_8512 ,mem_vec_8513 ,mem_vec_8514 ,mem_vec_8515 ,mem_vec_8516 ,mem_vec_8517 ,mem_vec_8518 ,mem_vec_8519 ,mem_vec_8520 ,mem_vec_8521 ,mem_vec_8522 ,mem_vec_8523 ,mem_vec_8524 ,mem_vec_8525 ,mem_vec_8526 ,mem_vec_8527 ,mem_vec_8528 ,mem_vec_8529 ,mem_vec_8530 ,mem_vec_8531 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f945 = 0;
f945_p_0 = 0;
x945 = 0;
x945_p_0 = 0;
c708 = 0;
c708_p_0 = 0;
f944 = 0;
f944_p_1 = 0;
y = 0;
yp_0 = 0;
x944 = 0;
x944_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x944, xp_2 = x944_p_1, xp_1 = x944_p_0, xp_0 = 0;x < x944 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8512 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_8513 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_8514 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_8515 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_8516 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_8517 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_8518 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_8519 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_8520 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_8521 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_8522 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_8523 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_8524 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_8525 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_8526 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_8527 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_8528 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_8529 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_8530 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_8531 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c708, cp_1 = c708_p_0, cp_0 = 0;c < c708 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8512);
												mem_vec_8512 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8513);
												mem_vec_8513 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8514);
												mem_vec_8514 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8515);
												mem_vec_8515 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8516);
												mem_vec_8516 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8517);
												mem_vec_8517 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8518);
												mem_vec_8518 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8519);
												mem_vec_8519 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8520);
												mem_vec_8520 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8521);
												mem_vec_8521 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8522);
												mem_vec_8522 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8523);
												mem_vec_8523 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8524);
												mem_vec_8524 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8525);
												mem_vec_8525 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8526);
												mem_vec_8526 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8527);
												mem_vec_8527 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8528);
												mem_vec_8528 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8529);
												mem_vec_8529 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8530);
												mem_vec_8530 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8531);
												mem_vec_8531 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8512);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_8513);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8514);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_8515);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8516);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_8517);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8518);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_8519);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8520);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_8521);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8522);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_8523);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8524);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_8525);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8526);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_8527);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8528);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_8529);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8530);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_8531);
								}
}
