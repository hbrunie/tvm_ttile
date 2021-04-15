void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (1, f); T (16, c); T (2, f); T (8, c); T (7, x); T (4, f)]
*/
IND_TYPE c, cp_0, c646_p_0, c647_p_0, cp_1, c646_p_1, cp_2, c646, c647, f, fp_0, f638_p_0, f639_p_0, fp_1, f638_p_1, fp_2, f638, f639, h, hp_0, x, xp_0, x550_p_0, xp_1, x550, y, yp_0;
IND_TYPE y368 = 0;
IND_TYPE x551 = 0;
IND_TYPE h294 = 0;
IND_TYPE w = 0;
IND_TYPE c648 = 0;
IND_TYPE f640 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3524 ,mem_vec_3525 ,mem_vec_3526 ,mem_vec_3527 ,mem_vec_3528 ,mem_vec_3529 ,mem_vec_3530 ,mem_vec_3531 ,mem_vec_3532 ,mem_vec_3533 ,mem_vec_3534 ,mem_vec_3535 ,mem_vec_3536 ,mem_vec_3537 ,mem_vec_3538 ,mem_vec_3539 ,mem_vec_3540 ,mem_vec_3541 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
f639 = 0;
f639_p_0 = 0;
x550 = 0;
x550_p_0 = 0;
c647 = 0;
c647_p_0 = 0;
f638 = 0;
f638_p_1 = 0;
c646 = 0;
c646_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
								for (h = h294, hp_0 = 0;h < h294 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
									// T (x, 2) (2 / 1)
									for (x = x550, xp_1 = x550_p_0, xp_0 = 0;x < x550 + 2;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3532 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3533 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3534 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3535 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3536 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3537 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3538 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3539 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3540 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_3541 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c646, cp_2 = c646_p_1, cp_1 = c646_p_0, cp_0 = 0;c < c646 + 2;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3532);
													mem_vec_3532 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3533);
													mem_vec_3533 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3534);
													mem_vec_3534 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3535);
													mem_vec_3535 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3536);
													mem_vec_3536 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3537);
													mem_vec_3537 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3538);
													mem_vec_3538 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3539);
													mem_vec_3539 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3540);
													mem_vec_3540 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3541);
													mem_vec_3541 = vec_16;
													scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_3532);
													mem_vec_3532 = vec_17;
													vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_3533);
													mem_vec_3533 = vec_20;
													scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_3534);
													mem_vec_3534 = vec_22;
													vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_3535);
													mem_vec_3535 = vec_24;
													scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);
													vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_3536);
													mem_vec_3536 = vec_25;
													vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_3537);
													mem_vec_3537 = vec_27;
													scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_3538);
													mem_vec_3538 = vec_28;
													vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_3539);
													mem_vec_3539 = vec_30;
													scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);
													vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_3540);
													mem_vec_3540 = vec_31;
													vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_3541);
													mem_vec_3541 = vec_33;
													scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_3532);
													mem_vec_3532 = vec_34;
													vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_3533);
													mem_vec_3533 = vec_37;
													scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);
													vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_3534);
													mem_vec_3534 = vec_39;
													vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_3535);
													mem_vec_3535 = vec_41;
													scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
													vec_43 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_3536);
													mem_vec_3536 = vec_42;
													vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_3537);
													mem_vec_3537 = vec_44;
													scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);
													vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_3538);
													mem_vec_3538 = vec_45;
													vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_3539);
													mem_vec_3539 = vec_47;
													scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);
													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_3540);
													mem_vec_3540 = vec_48;
													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_3541);
													mem_vec_3541 = vec_50;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3532);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3533);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3534);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3535);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3536);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3537);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3538);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3539);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3540);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3541);
									}
								}
}
