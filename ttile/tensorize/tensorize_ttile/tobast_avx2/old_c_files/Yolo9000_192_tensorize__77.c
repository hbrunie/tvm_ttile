void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (4, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c954_p_0, cp_1, c954, f, fp_0, f1272_p_0, f1273_p_0, fp_1, f1272_p_1, fp_2, f1272, f1273, x, xp_0, x1272_p_0, x1273_p_0, xp_1, x1272_p_1, xp_2, x1272, x1273, y, yp_0;
IND_TYPE y636 = 0;
IND_TYPE x1274 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c955 = 0;
IND_TYPE f1274 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_11448 ,mem_vec_11449 ,mem_vec_11450 ,mem_vec_11451 ,mem_vec_11452 ,mem_vec_11453 ,mem_vec_11454 ,mem_vec_11455 ,mem_vec_11456 ,mem_vec_11457 ,mem_vec_11458 ,mem_vec_11459 ,mem_vec_11460 ,mem_vec_11461 ,mem_vec_11462 ,mem_vec_11463 ,mem_vec_11464 ,mem_vec_11465 ,mem_vec_11466 ,mem_vec_11467 ,mem_vec_11468 ,mem_vec_11469 ,mem_vec_11470 ,mem_vec_11471 ,mem_vec_11472 ,mem_vec_11473 ,mem_vec_11474 ,mem_vec_11475 ,mem_vec_11476 ,mem_vec_11477 ,mem_vec_11478 ,mem_vec_11479 ,mem_vec_11480 ,mem_vec_11481 ,mem_vec_11482 ,mem_vec_11483 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
f1273 = 0;
f1273_p_0 = 0;
x1273 = 0;
x1273_p_0 = 0;
c954 = 0;
c954_p_0 = 0;
f1272 = 0;
f1272_p_1 = 0;
y = 0;
yp_0 = 0;
x1272 = 0;
x1272_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1272, xp_2 = x1272_p_1, xp_1 = x1272_p_0, xp_0 = 0;x < x1272 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11464 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11465 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_11466 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11467 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_11468 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11469 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_11470 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11471 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_11472 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11473 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_11474 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11475 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_11476 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11477 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_11478 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11479 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_11480 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_11481 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_11482 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_11483 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c954, cp_1 = c954_p_0, cp_0 = 0;c < c954 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11464);
												mem_vec_11464 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11465);
												mem_vec_11465 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11466);
												mem_vec_11466 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11467);
												mem_vec_11467 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11468);
												mem_vec_11468 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11469);
												mem_vec_11469 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11470);
												mem_vec_11470 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11471);
												mem_vec_11471 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11472);
												mem_vec_11472 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11473);
												mem_vec_11473 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11474);
												mem_vec_11474 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11475);
												mem_vec_11475 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11476);
												mem_vec_11476 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11477);
												mem_vec_11477 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11478);
												mem_vec_11478 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11479);
												mem_vec_11479 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11480);
												mem_vec_11480 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11481);
												mem_vec_11481 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11482);
												mem_vec_11482 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11483);
												mem_vec_11483 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11464);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_11465);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11466);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_11467);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11468);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_11469);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11470);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_11471);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11472);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_11473);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11474);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_11475);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11476);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_11477);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11478);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_11479);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11480);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_11481);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11482);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_11483);
								}
}
