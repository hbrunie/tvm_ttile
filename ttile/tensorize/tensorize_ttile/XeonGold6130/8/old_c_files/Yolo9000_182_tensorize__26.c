void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (8, c)]
*/
IND_TYPE c, cp_0, c345_p_0, c346_p_0, c347_p_0, cp_1, c345_p_1, c346_p_1, cp_2, c345_p_2, cp_3, c345, c346, c347, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y138 = 0;
IND_TYPE x138 = 0;
IND_TYPE h120 = 0;
IND_TYPE w120 = 0;
IND_TYPE c348 = 0;
IND_TYPE f138 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_2778 ,mem_vec_2779 ,mem_vec_2780 ,mem_vec_2781 ,mem_vec_2782 ,mem_vec_2783 ,mem_vec_2784 ,mem_vec_2785 ,mem_vec_2786 ,mem_vec_2787 ,mem_vec_2788 ,mem_vec_2789 ,mem_vec_2790 ,mem_vec_2791 ,mem_vec_2792 ,mem_vec_2793 ,mem_vec_2794 ,mem_vec_2795 ,mem_vec_2796 ,mem_vec_2797 ,mem_vec_2798 ,mem_vec_2799 ,mem_vec_2800 ,mem_vec_2801 ,mem_vec_2802 ,mem_vec_2803 ,mem_vec_2804 ,mem_vec_2805 ,mem_vec_2806 ,mem_vec_2807 ,mem_vec_2808 ,mem_vec_2809 ,mem_vec_2810 ,mem_vec_2811 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 8) (512 / 64)
c347 = 0;
c347_p_0 = 0;
c346 = 0;
c346_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
c345 = 0;
c345_p_2 = 0;
x = 0;
xp_0 = 0;
							for (h = h120, hp_0 = 0;h < h120 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w120, wp_0 = 0;w < w120 + 3;w += 1, wp_0 += 1){
											mem_vec_2794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_2806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_2807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_2808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_2809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_2810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_2811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c345, cp_3 = c345_p_2, cp_2 = c345_p_1, cp_1 = c345_p_0, cp_0 = 0;c < c345 + 64;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2794);
												mem_vec_2794 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2795);
												mem_vec_2795 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2796);
												mem_vec_2796 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2797);
												mem_vec_2797 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2798);
												mem_vec_2798 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2799);
												mem_vec_2799 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2800);
												mem_vec_2800 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2801);
												mem_vec_2801 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2802);
												mem_vec_2802 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2803);
												mem_vec_2803 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2804);
												mem_vec_2804 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2805);
												mem_vec_2805 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2806);
												mem_vec_2806 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2807);
												mem_vec_2807 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2808);
												mem_vec_2808 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2809);
												mem_vec_2809 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2810);
												mem_vec_2810 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2811);
												mem_vec_2811 = vec_28;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2794);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2795);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2796);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2797);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2798);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2799);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2800);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2801);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2802);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2803);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2804);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2805);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2806);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2807);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2808);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2809);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2810);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2811);
								}
							}
}
