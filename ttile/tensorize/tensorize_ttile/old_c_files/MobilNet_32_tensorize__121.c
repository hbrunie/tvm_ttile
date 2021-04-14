void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (4, f);
  T (8, c); T (4, x)]
*/
IND_TYPE c, cp_0, c486_p_0, cp_1, c486, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x616_p_0, x617_p_0, xp_1, x616_p_1, xp_2, x616, x617, y, yp_0;
IND_TYPE y324 = 0;
IND_TYPE x618 = 0;
IND_TYPE h276 = 0;
IND_TYPE w294 = 0;
IND_TYPE c487 = 0;
IND_TYPE f388 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4604 ,mem_vec_4605 ,mem_vec_4606 ,mem_vec_4607 ,mem_vec_4608 ,mem_vec_4609 ,mem_vec_4610 ,mem_vec_4611 ,mem_vec_4612 ,mem_vec_4613 ,mem_vec_4614 ,mem_vec_4615 ,mem_vec_4616 ,mem_vec_4617 ,mem_vec_4618 ,mem_vec_4619 ,mem_vec_4620 ,mem_vec_4621 ,mem_vec_4622 ,mem_vec_4623 ,mem_vec_4624 ,mem_vec_4625 ,mem_vec_4626 ,mem_vec_4627 ,mem_vec_4628 ,mem_vec_4629 ,mem_vec_4630 ,mem_vec_4631 ,mem_vec_4632 ,mem_vec_4633 ,mem_vec_4634 ,mem_vec_4635 ,mem_vec_4636 ,mem_vec_4637 ,mem_vec_4638 ,mem_vec_4639 ,mem_vec_4640 ,mem_vec_4641 ,mem_vec_4642 ,mem_vec_4643 ,mem_vec_4644 ,mem_vec_4645 ,mem_vec_4646 ,mem_vec_4647 ,mem_vec_4648 ,mem_vec_4649 ,mem_vec_4650 ,mem_vec_4651 ,mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
x617 = 0;
x617_p_0 = 0;
c486 = 0;
c486_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x616 = 0;
x616_p_1 = 0;
						for (h = h276, hp_0 = 0;h < h276 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w294, wp_0 = 0;w < w294 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 16, f = 32
								// T (x, 14) (14 / 1)
								for (x = x616, xp_2 = x616_p_1, xp_1 = x616_p_0, xp_0 = 0;x < x616 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_4636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_4638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_4640 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4641 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_4642 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4643 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_4644 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4645 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_4646 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_4647 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_4648 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_4649 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_4650 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_4651 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											mem_vec_4652 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
											mem_vec_4653 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
											mem_vec_4654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
											mem_vec_4655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c486, cp_1 = c486_p_0, cp_0 = 0;c < c486 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4626);
												mem_vec_4626 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4627);
												mem_vec_4627 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4628);
												mem_vec_4628 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4629);
												mem_vec_4629 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4630);
												mem_vec_4630 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4631);
												mem_vec_4631 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4632);
												mem_vec_4632 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4633);
												mem_vec_4633 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4634);
												mem_vec_4634 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4635);
												mem_vec_4635 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4636);
												mem_vec_4636 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4637);
												mem_vec_4637 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4638);
												mem_vec_4638 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4639);
												mem_vec_4639 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4640);
												mem_vec_4640 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4641);
												mem_vec_4641 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4642);
												mem_vec_4642 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4643);
												mem_vec_4643 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4644);
												mem_vec_4644 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4645);
												mem_vec_4645 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4646);
												mem_vec_4646 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4647);
												mem_vec_4647 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4648);
												mem_vec_4648 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4649);
												mem_vec_4649 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4650);
												mem_vec_4650 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4651);
												mem_vec_4651 = vec_40;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4652);
												mem_vec_4652 = vec_41;
												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4653);
												mem_vec_4653 = vec_43;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);
												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_4654);
												mem_vec_4654 = vec_44;
												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_4655);
												mem_vec_4655 = vec_46;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4626);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4627);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4628);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4629);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4630);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4631);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4632);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4633);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4634);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4635);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4636);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4637);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4638);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4639);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4640);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4641);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4642);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4643);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4644);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4645);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4646);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4647);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4648);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4649);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4650);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_4651);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_4652);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_4653);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_4654);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_4655);
								}
							}
						}
}
