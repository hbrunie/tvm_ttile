void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, f); T (2, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (1, f)]
*/
IND_TYPE c, cp_0, c684_p_0, cp_1, c684, f, fp_0, f684_p_0, fp_1, f684, h, hp_0, w, wp_0, x, xp_0, x684_p_0, xp_1, x684, y, yp_0;
IND_TYPE y456 = 0;
IND_TYPE x685 = 0;
IND_TYPE h388 = 0;
IND_TYPE w426 = 0;
IND_TYPE c685 = 0;
IND_TYPE f685 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6492 ,mem_vec_6493 ,mem_vec_6494 ,mem_vec_6495 ,mem_vec_6496 ,mem_vec_6497 ,mem_vec_6498 ,mem_vec_6499 ,mem_vec_6500 ,mem_vec_6501 ,mem_vec_6502 ,mem_vec_6503 ,mem_vec_6504 ,mem_vec_6505 ,mem_vec_6506 ,mem_vec_6507 ,mem_vec_6508 ,mem_vec_6509 ,mem_vec_6510 ,mem_vec_6511 ,mem_vec_6512 ,mem_vec_6513 ,mem_vec_6514 ,mem_vec_6515 ,mem_vec_6516 ,mem_vec_6517 ,mem_vec_6518 ,mem_vec_6519 ,mem_vec_6520 ,mem_vec_6521 ,mem_vec_6522 ,mem_vec_6523 ,mem_vec_6524 ,mem_vec_6525 ,mem_vec_6526 ,mem_vec_6527 ,mem_vec_6528 ,mem_vec_6529 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f684 = 0;
f684_p_0 = 0;
y = 0;
yp_0 = 0;
x684 = 0;
x684_p_0 = 0;
c684 = 0;
c684_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h388, hp_0 = 0;h < h388 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w426, wp_0 = 0;w < w426 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x684, xp_1 = x684_p_0, xp_0 = 0;x < x684 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6510 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6511 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6512 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6513 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6514 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6515 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6516 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6517 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6518 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6519 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6520 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6521 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6522 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6523 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6524 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_6525 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_6526 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_6527 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_6528 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_6529 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c684, cp_1 = c684_p_0, cp_0 = 0;c < c684 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6510);
												mem_vec_6510 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6511);
												mem_vec_6511 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6512);
												mem_vec_6512 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6513);
												mem_vec_6513 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6514);
												mem_vec_6514 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6515);
												mem_vec_6515 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6516);
												mem_vec_6516 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6517);
												mem_vec_6517 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6518);
												mem_vec_6518 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6519);
												mem_vec_6519 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6520);
												mem_vec_6520 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6521);
												mem_vec_6521 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6522);
												mem_vec_6522 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6523);
												mem_vec_6523 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6524);
												mem_vec_6524 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6525);
												mem_vec_6525 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6526);
												mem_vec_6526 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6527);
												mem_vec_6527 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6528);
												mem_vec_6528 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6529);
												mem_vec_6529 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6510);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6511);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6512);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6513);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6514);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6515);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6516);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6517);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6518);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6519);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6520);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6521);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6522);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6523);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6524);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6525);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6526);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6527);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6528);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6529);
								}
							}
						}
}
