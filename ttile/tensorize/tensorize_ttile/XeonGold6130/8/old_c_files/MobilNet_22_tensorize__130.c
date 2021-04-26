void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (2, c); T (2, f); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (1, x)]
*/
IND_TYPE c, cp_0, c429_p_0, cp_1, c429, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x530_p_0, x531_p_0, xp_1, x530_p_1, xp_2, x530, x531, y, yp_0;
IND_TYPE y307 = 0;
IND_TYPE x532 = 0;
IND_TYPE h247 = 0;
IND_TYPE w256 = 0;
IND_TYPE c430 = 0;
IND_TYPE f236 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4316 ,mem_vec_4317 ,mem_vec_4318 ,mem_vec_4319 ,mem_vec_4320 ,mem_vec_4321 ,mem_vec_4322 ,mem_vec_4323 ,mem_vec_4324 ,mem_vec_4325 ,mem_vec_4326 ,mem_vec_4327 ,mem_vec_4328 ,mem_vec_4329 ,mem_vec_4330 ,mem_vec_4331 ,mem_vec_4332 ,mem_vec_4333 ,mem_vec_4334 ,mem_vec_4335 ,mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,mem_vec_4345 ,mem_vec_4346 ,mem_vec_4347 ,mem_vec_4348 ,mem_vec_4349 ,mem_vec_4350 ,mem_vec_4351 ,mem_vec_4352 ,mem_vec_4353 ,mem_vec_4354 ,mem_vec_4355 ,mem_vec_4356 ,mem_vec_4357 ,mem_vec_4358 ,mem_vec_4359 ,mem_vec_4360 ,mem_vec_4361 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
x531 = 0;
x531_p_0 = 0;
y = 0;
yp_0 = 0;
x530 = 0;
x530_p_1 = 0;
f = 0;
fp_0 = 0;
c429 = 0;
c429_p_0 = 0;
						for (w = w256, wp_0 = 0;w < w256 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x530, xp_2 = x530_p_1, xp_1 = x530_p_0, xp_0 = 0;x < x530 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h247, hp_0 = 0;h < h247 + 3;h += 1, hp_0 += 1){
											mem_vec_4336 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4337 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4338 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4339 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4340 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4341 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4342 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4343 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4344 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4345 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_4346 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4347 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_4348 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4349 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_4350 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4351 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_4352 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4353 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_4354 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4355 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_4356 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_4357 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_4358 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_4359 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_4360 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_4361 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c429, cp_1 = c429_p_0, cp_0 = 0;c < c429 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4336);
												mem_vec_4336 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4337);
												mem_vec_4337 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4338);
												mem_vec_4338 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4339);
												mem_vec_4339 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4340);
												mem_vec_4340 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4341);
												mem_vec_4341 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4342);
												mem_vec_4342 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4343);
												mem_vec_4343 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4344);
												mem_vec_4344 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4345);
												mem_vec_4345 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4346);
												mem_vec_4346 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4347);
												mem_vec_4347 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4348);
												mem_vec_4348 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4349);
												mem_vec_4349 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4350);
												mem_vec_4350 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4351);
												mem_vec_4351 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4352);
												mem_vec_4352 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4353);
												mem_vec_4353 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4354);
												mem_vec_4354 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4355);
												mem_vec_4355 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4356);
												mem_vec_4356 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4357);
												mem_vec_4357 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4358);
												mem_vec_4358 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4359);
												mem_vec_4359 = vec_37;
												scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4360);
												mem_vec_4360 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4361);
												mem_vec_4361 = vec_40;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4336);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4337);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4338);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4339);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4340);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4341);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4342);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4343);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4344);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4345);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4346);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4347);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4348);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4349);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4350);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4351);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4352);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4353);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4354);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4355);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4356);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4357);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4358);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4359);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4360);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_4361);
								}
							}
						}
}
