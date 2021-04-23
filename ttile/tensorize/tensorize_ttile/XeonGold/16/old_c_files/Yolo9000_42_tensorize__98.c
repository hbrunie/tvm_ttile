void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (8, x);
  T (3, w); T (2, c); T (4, f); T (17, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (1, x)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x674_p_0, x675_p_0, xp_1, x674_p_1, xp_2, x674, x675, y, yp_0;
IND_TYPE y448 = 0;
IND_TYPE x676 = 0;
IND_TYPE h332 = 0;
IND_TYPE w388 = 0;
IND_TYPE c592 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7416 ,mem_vec_7417 ,mem_vec_7418 ,mem_vec_7419 ,mem_vec_7420 ,mem_vec_7421 ,mem_vec_7422 ,mem_vec_7423 ,mem_vec_7424 ,mem_vec_7425 ,mem_vec_7426 ,mem_vec_7427 ,mem_vec_7428 ,mem_vec_7429 ,mem_vec_7430 ,mem_vec_7431 ,mem_vec_7432 ,mem_vec_7433 ,mem_vec_7434 ,mem_vec_7435 ,mem_vec_7436 ,mem_vec_7437 ,mem_vec_7438 ,mem_vec_7439 ,mem_vec_7440 ,mem_vec_7441 ,mem_vec_7442 ,mem_vec_7443 ,mem_vec_7444 ,mem_vec_7445 ,mem_vec_7446 ,mem_vec_7447 ,mem_vec_7448 ,mem_vec_7449 ,mem_vec_7450 ,mem_vec_7451 ,mem_vec_7452 ,mem_vec_7453 ,mem_vec_7454 ,mem_vec_7455 ,mem_vec_7456 ,mem_vec_7457 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
x675 = 0;
x675_p_0 = 0;
y = 0;
yp_0 = 0;
x674 = 0;
x674_p_1 = 0;
f = 0;
fp_0 = 0;
c591 = 0;
c591_p_0 = 0;
						for (w = w388, wp_0 = 0;w < w388 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 3, w = 1, c = 32, f = 32
							// T (x, 8) (8 / 1)
							for (x = x674, xp_2 = x674_p_1, xp_1 = x674_p_0, xp_0 = 0;x < x674 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h332, hp_0 = 0;h < h332 + 3;h += 1, hp_0 += 1){
											mem_vec_7436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_7437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_7438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_7439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_7440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_7441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_7442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_7443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_7444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_7445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_7446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_7447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_7448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_7449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_7450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_7451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_7452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_7453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_7454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_7455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_7456 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_7457 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c591, cp_1 = c591_p_0, cp_0 = 0;c < c591 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7436);
												mem_vec_7436 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7437);
												mem_vec_7437 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7438);
												mem_vec_7438 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7439);
												mem_vec_7439 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7440);
												mem_vec_7440 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7441);
												mem_vec_7441 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7442);
												mem_vec_7442 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7443);
												mem_vec_7443 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7444);
												mem_vec_7444 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7445);
												mem_vec_7445 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7446);
												mem_vec_7446 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7447);
												mem_vec_7447 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7448);
												mem_vec_7448 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7449);
												mem_vec_7449 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7450);
												mem_vec_7450 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7451);
												mem_vec_7451 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7452);
												mem_vec_7452 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7453);
												mem_vec_7453 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7454);
												mem_vec_7454 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7455);
												mem_vec_7455 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7456);
												mem_vec_7456 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7457);
												mem_vec_7457 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7436);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7437);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7438);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7439);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7440);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7441);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7442);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7443);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7444);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7445);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7446);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7447);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7448);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7449);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7450);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7451);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_7452);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_7453);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_7454);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_7455);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_7456);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_7457);
								}
							}
						}
}
