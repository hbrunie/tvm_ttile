void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (4, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (4, x)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x598_p_0, x599_p_0, xp_1, x598_p_1, xp_2, x598, x599, y, yp_0;
IND_TYPE y364 = 0;
IND_TYPE x600 = 0;
IND_TYPE h251 = 0;
IND_TYPE w342 = 0;
IND_TYPE c547 = 0;
IND_TYPE f568 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4406 ,mem_vec_4407 ,mem_vec_4408 ,mem_vec_4409 ,mem_vec_4410 ,mem_vec_4411 ,mem_vec_4412 ,mem_vec_4413 ,mem_vec_4414 ,mem_vec_4415 ,mem_vec_4416 ,mem_vec_4417 ,mem_vec_4418 ,mem_vec_4419 ,mem_vec_4420 ,mem_vec_4421 ,mem_vec_4422 ,mem_vec_4423 ,mem_vec_4424 ,mem_vec_4425 ,mem_vec_4426 ,mem_vec_4427 ,mem_vec_4428 ,mem_vec_4429 ,mem_vec_4430 ,mem_vec_4431 ,mem_vec_4432 ,mem_vec_4433 ,mem_vec_4434 ,mem_vec_4435 ,mem_vec_4436 ,mem_vec_4437 ,mem_vec_4438 ,mem_vec_4439 ,mem_vec_4440 ,mem_vec_4441 ,mem_vec_4442 ,mem_vec_4443 ,mem_vec_4444 ,mem_vec_4445 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
x599 = 0;
x599_p_0 = 0;
y = 0;
yp_0 = 0;
x598 = 0;
x598_p_1 = 0;
f = 0;
fp_0 = 0;
c546 = 0;
c546_p_0 = 0;
						for (w = w342, wp_0 = 0;w < w342 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x598, xp_2 = x598_p_1, xp_1 = x598_p_0, xp_0 = 0;x < x598 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h251, hp_0 = 0;h < h251 + 3;h += 1, hp_0 += 1){
											mem_vec_4424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_4434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_4436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_4438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_4440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_4442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_4444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_4445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;c < c546 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4424);
												mem_vec_4424 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4425);
												mem_vec_4425 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4426);
												mem_vec_4426 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4427);
												mem_vec_4427 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4428);
												mem_vec_4428 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4429);
												mem_vec_4429 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4430);
												mem_vec_4430 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4431);
												mem_vec_4431 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4432);
												mem_vec_4432 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4433);
												mem_vec_4433 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4434);
												mem_vec_4434 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4435);
												mem_vec_4435 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4436);
												mem_vec_4436 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4437);
												mem_vec_4437 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4438);
												mem_vec_4438 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4439);
												mem_vec_4439 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4440);
												mem_vec_4440 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4441);
												mem_vec_4441 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4442);
												mem_vec_4442 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4443);
												mem_vec_4443 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4444);
												mem_vec_4444 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4445);
												mem_vec_4445 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4424);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4425);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4426);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4427);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4428);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4429);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4430);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4431);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4432);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4433);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4434);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4435);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4436);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4437);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4438);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4439);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4440);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4441);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4442);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4443);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4444);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4445);
								}
							}
						}
}
