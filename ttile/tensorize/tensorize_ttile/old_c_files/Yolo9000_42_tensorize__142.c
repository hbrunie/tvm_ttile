void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 13)); ((Iter 3), (Arg 15))]; T (4, f);
  T (8, c); T (17, x)]
*/
IND_TYPE c, cp_0, c846_p_0, cp_1, c846, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1128_p_0, x1129_p_0, xp_1, x1128_p_1, xp_2, x1128, x1129, y, yp_0;
IND_TYPE y564 = 0;
IND_TYPE x1130 = 0;
IND_TYPE h564 = 0;
IND_TYPE w534 = 0;
IND_TYPE c847 = 0;
IND_TYPE f564 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11620 ,mem_vec_11621 ,mem_vec_11622 ,mem_vec_11623 ,mem_vec_11624 ,mem_vec_11625 ,mem_vec_11626 ,mem_vec_11627 ,mem_vec_11628 ,mem_vec_11629 ,mem_vec_11630 ,mem_vec_11631 ,mem_vec_11632 ,mem_vec_11633 ,mem_vec_11634 ,mem_vec_11635 ,mem_vec_11636 ,mem_vec_11637 ,mem_vec_11638 ,mem_vec_11639 ,mem_vec_11640 ,mem_vec_11641 ,mem_vec_11642 ,mem_vec_11643 ,mem_vec_11644 ,mem_vec_11645 ,mem_vec_11646 ,mem_vec_11647 ,mem_vec_11648 ,mem_vec_11649 ,mem_vec_11650 ,mem_vec_11651 ,mem_vec_11652 ,mem_vec_11653 ,mem_vec_11654 ,mem_vec_11655 ,mem_vec_11656 ,mem_vec_11657 ,mem_vec_11658 ,mem_vec_11659 ,mem_vec_11660 ,mem_vec_11661 ,mem_vec_11662 ,mem_vec_11663 ,mem_vec_11664 ,mem_vec_11665 ,mem_vec_11666 ,mem_vec_11667 ,mem_vec_11668 ,mem_vec_11669 ,mem_vec_11670 ,mem_vec_11671 ,mem_vec_11672 ,mem_vec_11673 ,mem_vec_11674 ,mem_vec_11675 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 17) (136 / 8)
x1129 = 0;
x1129_p_0 = 0;
c846 = 0;
c846_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1128 = 0;
x1128_p_1 = 0;
						for (h = h564, hp_0 = 0;h < h564 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w534, wp_0 = 0;w < w534 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1128, xp_2 = x1128_p_1, xp_1 = x1128_p_0, xp_0 = 0;x < x1128 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11646 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11647 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11648 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11649 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11650 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11651 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11652 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11653 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_11655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_11656 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_11657 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_11658 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_11659 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_11660 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_11661 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_11662 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_11663 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_11664 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_11665 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_11666 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_11667 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_11668 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_11669 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_11670 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_11671 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											mem_vec_11672 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
											mem_vec_11673 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
											mem_vec_11674 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
											mem_vec_11675 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c846, cp_1 = c846_p_0, cp_0 = 0;c < c846 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11646);
												mem_vec_11646 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11647);
												mem_vec_11647 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11648);
												mem_vec_11648 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11649);
												mem_vec_11649 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11650);
												mem_vec_11650 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11651);
												mem_vec_11651 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11652);
												mem_vec_11652 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11653);
												mem_vec_11653 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11654);
												mem_vec_11654 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11655);
												mem_vec_11655 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11656);
												mem_vec_11656 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11657);
												mem_vec_11657 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11658);
												mem_vec_11658 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11659);
												mem_vec_11659 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11660);
												mem_vec_11660 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11661);
												mem_vec_11661 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11662);
												mem_vec_11662 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11663);
												mem_vec_11663 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11664);
												mem_vec_11664 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11665);
												mem_vec_11665 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11666);
												mem_vec_11666 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11667);
												mem_vec_11667 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11668);
												mem_vec_11668 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11669);
												mem_vec_11669 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11670);
												mem_vec_11670 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11671);
												mem_vec_11671 = vec_40;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11672);
												mem_vec_11672 = vec_41;
												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11673);
												mem_vec_11673 = vec_43;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);
												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_11674);
												mem_vec_11674 = vec_44;
												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_11675);
												mem_vec_11675 = vec_46;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11646);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11647);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11648);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11649);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11650);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11651);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11652);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11653);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11654);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11655);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_11656);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_11657);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_11658);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_11659);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_11660);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_11661);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_11662);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_11663);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_11664);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_11665);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_11666);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_11667);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_11668);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_11669);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_11670);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_11671);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_11672);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_11673);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_11674);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_11675);
								}
							}
						}
}
