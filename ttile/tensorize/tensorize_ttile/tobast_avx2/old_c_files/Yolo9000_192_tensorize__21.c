void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (512, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c786_p_0, cp_1, c786, f, fp_0, f1048_p_0, f1049_p_0, fp_1, f1048_p_1, fp_2, f1048, f1049, x, xp_0, x1048_p_0, x1049_p_0, xp_1, x1048_p_1, xp_2, x1048, x1049, y, yp_0;
IND_TYPE y524 = 0;
IND_TYPE x1050 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c787 = 0;
IND_TYPE f1050 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9432 ,mem_vec_9433 ,mem_vec_9434 ,mem_vec_9435 ,mem_vec_9436 ,mem_vec_9437 ,mem_vec_9438 ,mem_vec_9439 ,mem_vec_9440 ,mem_vec_9441 ,mem_vec_9442 ,mem_vec_9443 ,mem_vec_9444 ,mem_vec_9445 ,mem_vec_9446 ,mem_vec_9447 ,mem_vec_9448 ,mem_vec_9449 ,mem_vec_9450 ,mem_vec_9451 ,mem_vec_9452 ,mem_vec_9453 ,mem_vec_9454 ,mem_vec_9455 ,mem_vec_9456 ,mem_vec_9457 ,mem_vec_9458 ,mem_vec_9459 ,mem_vec_9460 ,mem_vec_9461 ,mem_vec_9462 ,mem_vec_9463 ,mem_vec_9464 ,mem_vec_9465 ,mem_vec_9466 ,mem_vec_9467 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
f1049 = 0;
f1049_p_0 = 0;
x1049 = 0;
x1049_p_0 = 0;
c786 = 0;
c786_p_0 = 0;
f1048 = 0;
f1048_p_1 = 0;
y = 0;
yp_0 = 0;
x1048 = 0;
x1048_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;x < x1048 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9448 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_9449 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_9450 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_9451 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_9452 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_9453 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_9454 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_9455 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_9456 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_9457 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_9458 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_9459 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_9460 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_9461 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_9462 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_9463 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_9464 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_9465 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_9466 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_9467 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c786, cp_1 = c786_p_0, cp_0 = 0;c < c786 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9448);
												mem_vec_9448 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9449);
												mem_vec_9449 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9450);
												mem_vec_9450 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9451);
												mem_vec_9451 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9452);
												mem_vec_9452 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9453);
												mem_vec_9453 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9454);
												mem_vec_9454 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9455);
												mem_vec_9455 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9456);
												mem_vec_9456 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9457);
												mem_vec_9457 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9458);
												mem_vec_9458 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9459);
												mem_vec_9459 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9460);
												mem_vec_9460 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9461);
												mem_vec_9461 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9462);
												mem_vec_9462 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9463);
												mem_vec_9463 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9464);
												mem_vec_9464 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9465);
												mem_vec_9465 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9466);
												mem_vec_9466 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9467);
												mem_vec_9467 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_9448);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_9449);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_9450);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_9451);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_9452);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_9453);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_9454);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_9455);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9456);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_9457);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_9458);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_9459);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9460);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_9461);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_9462);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_9463);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_9464);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_9465);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_9466);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_9467);
								}
}
