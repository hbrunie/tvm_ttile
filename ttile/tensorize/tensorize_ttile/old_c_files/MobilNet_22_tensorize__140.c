void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (2, f);
  T (8, c); T (2, x)]
*/
IND_TYPE c, cp_0, c410_p_0, cp_1, c410, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x402_p_0, x403_p_0, xp_1, x402_p_1, xp_2, x402, x403, y, yp_0;
IND_TYPE y232 = 0;
IND_TYPE x404 = 0;
IND_TYPE h196 = 0;
IND_TYPE w208 = 0;
IND_TYPE c411 = 0;
IND_TYPE f170 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2752 ,mem_vec_2753 ,mem_vec_2754 ,mem_vec_2755 ,mem_vec_2756 ,mem_vec_2757 ,mem_vec_2758 ,mem_vec_2759 ,mem_vec_2760 ,mem_vec_2761 ,mem_vec_2762 ,mem_vec_2763 ,mem_vec_2764 ,mem_vec_2765 ,mem_vec_2766 ,mem_vec_2767 ,mem_vec_2768 ,mem_vec_2769 ,mem_vec_2770 ,mem_vec_2771 ,mem_vec_2772 ,mem_vec_2773 ,mem_vec_2774 ,mem_vec_2775 ,mem_vec_2776 ,mem_vec_2777 ,mem_vec_2778 ,mem_vec_2779 ,mem_vec_2780 ,mem_vec_2781 ,mem_vec_2782 ,mem_vec_2783 ,mem_vec_2784 ,mem_vec_2785 ,mem_vec_2786 ,mem_vec_2787 ,mem_vec_2788 ,mem_vec_2789 ,mem_vec_2790 ,mem_vec_2791 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
x403 = 0;
x403_p_0 = 0;
c410 = 0;
c410_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x402 = 0;
x402_p_1 = 0;
						for (h = h196, hp_0 = 0;h < h196 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w208, wp_0 = 0;w < w208 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 8, f = 32
								// T (x, 14) (14 / 1)
								for (x = x402, xp_2 = x402_p_1, xp_1 = x402_p_0, xp_0 = 0;x < x402 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2770 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2771 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2772 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2773 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2774 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2775 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2776 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2777 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2778 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2779 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2780 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2781 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_2782 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2783 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_2784 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2785 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_2786 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2787 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_2788 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_2789 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_2790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_2791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c410, cp_1 = c410_p_0, cp_0 = 0;c < c410 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2770);
												mem_vec_2770 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2771);
												mem_vec_2771 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2772);
												mem_vec_2772 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2773);
												mem_vec_2773 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2774);
												mem_vec_2774 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2775);
												mem_vec_2775 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2776);
												mem_vec_2776 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2777);
												mem_vec_2777 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2778);
												mem_vec_2778 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2779);
												mem_vec_2779 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2780);
												mem_vec_2780 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2781);
												mem_vec_2781 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2782);
												mem_vec_2782 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2783);
												mem_vec_2783 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2784);
												mem_vec_2784 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2785);
												mem_vec_2785 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2786);
												mem_vec_2786 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2787);
												mem_vec_2787 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2788);
												mem_vec_2788 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2789);
												mem_vec_2789 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2790);
												mem_vec_2790 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2791);
												mem_vec_2791 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2770);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2771);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2772);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2773);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2774);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2775);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2776);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2777);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2778);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2779);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2780);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2781);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2782);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2783);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2784);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2785);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2786);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2787);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2788);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2789);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2790);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_2791);
								}
							}
						}
}
