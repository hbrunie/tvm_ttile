void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (16, c); T (1, x); T (8, x)]
*/
IND_TYPE c, cp_0, c1068_p_0, cp_1, c1068, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1780_p_0, x1781_p_0, x1782_p_0, xp_1, x1780_p_1, x1781_p_1, xp_2, x1780_p_2, xp_3, x1780, x1781, x1782, y, yp_0;
IND_TYPE y712 = 0;
IND_TYPE x1783 = 0;
IND_TYPE h712 = 0;
IND_TYPE w572 = 0;
IND_TYPE c1069 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8384 ,mem_vec_8385 ,mem_vec_8386 ,mem_vec_8387 ,mem_vec_8388 ,mem_vec_8389 ,mem_vec_8390 ,mem_vec_8391 ,mem_vec_8392 ,mem_vec_8393 ,mem_vec_8394 ,mem_vec_8395 ,mem_vec_8396 ,mem_vec_8397 ,mem_vec_8398 ,mem_vec_8399 ,mem_vec_8400 ,mem_vec_8401 ,mem_vec_8402 ,mem_vec_8403 ,mem_vec_8404 ,mem_vec_8405 ,mem_vec_8406 ,mem_vec_8407 ,mem_vec_8408 ,mem_vec_8409 ,mem_vec_8410 ,mem_vec_8411 ,mem_vec_8412 ,mem_vec_8413 ,mem_vec_8414 ,mem_vec_8415 ,mem_vec_8416 ,mem_vec_8417 ,mem_vec_8418 ,mem_vec_8419 ,mem_vec_8420 ,mem_vec_8421 ,mem_vec_8422 ,mem_vec_8423 ,mem_vec_8424 ,mem_vec_8425 ,mem_vec_8426 ,mem_vec_8427 ,mem_vec_8428 ,mem_vec_8429 ,mem_vec_8430 ,mem_vec_8431 ,mem_vec_8432 ,mem_vec_8433 ,mem_vec_8434 ,mem_vec_8435 ,mem_vec_8436 ,mem_vec_8437 ,mem_vec_8438 ,mem_vec_8439 ,mem_vec_8440 ,mem_vec_8441 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 8) (272 / 34)
x1782 = 0;
x1782_p_0 = 0;
x1781 = 0;
x1781_p_1 = 0;
c1068 = 0;
c1068_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1780 = 0;
x1780_p_2 = 0;
							for (h = h712, hp_0 = 0;h < h712 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w572, wp_0 = 0;w < w572 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
									// T (x, 34) (34 / 1)
									for (x = x1780, xp_3 = x1780_p_2, xp_2 = x1780_p_1, xp_1 = x1780_p_0, xp_0 = 0;x < x1780 + 34;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_8413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_8414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_8415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_8416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_8417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_8418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_8419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_8420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_8421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_8422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_8423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_8424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_8425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_8426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_8427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_8428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_8429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_8430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_8431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_8432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_8433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_8434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_8435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_8436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_8437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_8438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_8439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												mem_vec_8440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
												mem_vec_8441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1068, cp_1 = c1068_p_0, cp_0 = 0;c < c1068 + 2;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8412);
													mem_vec_8412 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8413);
													mem_vec_8413 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8414);
													mem_vec_8414 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8415);
													mem_vec_8415 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8416);
													mem_vec_8416 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8417);
													mem_vec_8417 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8418);
													mem_vec_8418 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8419);
													mem_vec_8419 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8420);
													mem_vec_8420 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8421);
													mem_vec_8421 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8422);
													mem_vec_8422 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8423);
													mem_vec_8423 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8424);
													mem_vec_8424 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8425);
													mem_vec_8425 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8426);
													mem_vec_8426 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8427);
													mem_vec_8427 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8428);
													mem_vec_8428 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8429);
													mem_vec_8429 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8430);
													mem_vec_8430 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8431);
													mem_vec_8431 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8432);
													mem_vec_8432 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8433);
													mem_vec_8433 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8434);
													mem_vec_8434 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8435);
													mem_vec_8435 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8436);
													mem_vec_8436 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8437);
													mem_vec_8437 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8438);
													mem_vec_8438 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8439);
													mem_vec_8439 = vec_43;
													scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);
													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8440);
													mem_vec_8440 = vec_44;
													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8441);
													mem_vec_8441 = vec_46;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8412);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8413);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8414);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8415);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8416);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8417);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8418);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8419);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8420);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8421);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8422);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8423);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8424);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8425);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8426);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8427);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8428);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8429);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8430);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8431);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8432);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8433);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8434);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8435);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_8436);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_8437);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_8438);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_8439);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_8440);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_8441);
									}
								}
							}
}
