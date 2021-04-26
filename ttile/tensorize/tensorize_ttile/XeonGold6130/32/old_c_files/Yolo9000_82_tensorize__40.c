void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, f368_p_0, f369_p_0, fp_1, f368_p_1, fp_2, f368, f369, h, hp_0, w, wp_0, x, xp_0, x276_p_0, xp_1, x276, y, yp_0;
IND_TYPE y184 = 0;
IND_TYPE x277 = 0;
IND_TYPE h184 = 0;
IND_TYPE w164 = 0;
IND_TYPE c277 = 0;
IND_TYPE f370 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,mem_vec_3596 ,mem_vec_3597 ,mem_vec_3598 ,mem_vec_3599 ,mem_vec_3600 ,mem_vec_3601 ,mem_vec_3602 ,mem_vec_3603 ,mem_vec_3604 ,mem_vec_3605 ,mem_vec_3606 ,mem_vec_3607 ,mem_vec_3608 ,mem_vec_3609 ,mem_vec_3610 ,mem_vec_3611 ,mem_vec_3612 ,mem_vec_3613 ,mem_vec_3614 ,mem_vec_3615 ,mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f369 = 0;
f369_p_0 = 0;
f368 = 0;
f368_p_1 = 0;
x276 = 0;
x276_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c276 = 0;
c276_p_0 = 0;
							for (w = w164, wp_0 = 0;w < w164 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x276, xp_1 = x276_p_0, xp_0 = 0;x < x276 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h184, hp_0 = 0;h < h184 + 3;h += 1, hp_0 += 1){
												mem_vec_3596 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3597 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3598 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3599 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3600 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3601 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3602 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3603 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3604 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_3605 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_3606 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_3607 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_3608 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_3609 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_3610 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_3611 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_3612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_3613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_3614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_3615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_3616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_3617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_3618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_3619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3596);
													mem_vec_3596 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3597);
													mem_vec_3597 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3598);
													mem_vec_3598 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3599);
													mem_vec_3599 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3600);
													mem_vec_3600 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3601);
													mem_vec_3601 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3602);
													mem_vec_3602 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3603);
													mem_vec_3603 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3604);
													mem_vec_3604 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3605);
													mem_vec_3605 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3606);
													mem_vec_3606 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3607);
													mem_vec_3607 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3608);
													mem_vec_3608 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3609);
													mem_vec_3609 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3610);
													mem_vec_3610 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3611);
													mem_vec_3611 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3612);
													mem_vec_3612 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3613);
													mem_vec_3613 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3614);
													mem_vec_3614 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3615);
													mem_vec_3615 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3616);
													mem_vec_3616 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3617);
													mem_vec_3617 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3618);
													mem_vec_3618 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3619);
													mem_vec_3619 = vec_37;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3596);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3597);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3598);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3599);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3600);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3601);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3602);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3603);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3604);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3605);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3606);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3607);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3608);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3609);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3610);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3611);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3612);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3613);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3614);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3615);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3616);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3617);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_3618);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_3619);
									}
								}
							}
}
