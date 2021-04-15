void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (16, y); T (2, f); T (8, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f);
  T (272, x)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, f, fp_0, f422_p_0, fp_1, f422, h, hp_0, w, wp_0, x, xp_0, x608_p_0, x609_p_0, xp_1, x608_p_1, xp_2, x608, x609, y, yp_0, y456_p_0, yp_1, y456;
IND_TYPE y457 = 0;
IND_TYPE x610 = 0;
IND_TYPE h256 = 0;
IND_TYPE w254 = 0;
IND_TYPE c457 = 0;
IND_TYPE f423 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2824 ,mem_vec_2825 ,mem_vec_2826 ,mem_vec_2827 ,mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,mem_vec_2836 ,mem_vec_2837 ,mem_vec_2838 ,mem_vec_2839 ,mem_vec_2840 ,mem_vec_2841 ,mem_vec_2842 ,mem_vec_2843 ,mem_vec_2844 ,mem_vec_2845 ,mem_vec_2846 ,mem_vec_2847 ,mem_vec_2848 ,mem_vec_2849 ,mem_vec_2850 ,mem_vec_2851 ,mem_vec_2852 ,mem_vec_2853 ,mem_vec_2854 ,mem_vec_2855 ,mem_vec_2856 ,mem_vec_2857 ,mem_vec_2858 ,mem_vec_2859 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 272) (272 / 1)
x609 = 0;
x609_p_0 = 0;
f422 = 0;
f422_p_0 = 0;
y456 = 0;
y456_p_0 = 0;
x608 = 0;
x608_p_1 = 0;
c456 = 0;
c456_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
								for (h = h256, hp_0 = 0;h < h256 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
									// T (w, 3) (3 / 1)
									for (w = w254, wp_0 = 0;w < w254 + 3;w += 1, wp_0 += 1){
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (x, 1) (1 / 1)
										for (x = x608, xp_2 = x608_p_1, xp_1 = x608_p_0, xp_0 = 0;x < x608 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2840 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
													mem_vec_2841 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
													mem_vec_2842 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
													mem_vec_2843 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
													mem_vec_2844 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
													mem_vec_2845 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
													mem_vec_2846 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
													mem_vec_2847 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
													mem_vec_2848 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
													mem_vec_2849 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
													mem_vec_2850 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
													mem_vec_2851 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
													mem_vec_2852 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
													mem_vec_2853 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
													mem_vec_2854 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
													mem_vec_2855 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
													mem_vec_2856 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
													mem_vec_2857 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
													mem_vec_2858 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
													mem_vec_2859 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
													// T (c, 4) (4 / 1)
													for (c = c456, cp_1 = c456_p_0, cp_0 = 0;c < c456 + 4;c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2840);
														mem_vec_2840 = vec_0;
														vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2841);
														mem_vec_2841 = vec_3;
														vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2842);
														mem_vec_2842 = vec_5;
														vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2843);
														mem_vec_2843 = vec_7;
														scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);
														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2844);
														mem_vec_2844 = vec_9;
														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2845);
														mem_vec_2845 = vec_11;
														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2846);
														mem_vec_2846 = vec_12;
														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2847);
														mem_vec_2847 = vec_13;
														scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);
														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2848);
														mem_vec_2848 = vec_14;
														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2849);
														mem_vec_2849 = vec_16;
														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2850);
														mem_vec_2850 = vec_17;
														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2851);
														mem_vec_2851 = vec_18;
														scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);
														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2852);
														mem_vec_2852 = vec_19;
														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2853);
														mem_vec_2853 = vec_21;
														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2854);
														mem_vec_2854 = vec_22;
														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2855);
														mem_vec_2855 = vec_23;
														scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);
														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2856);
														mem_vec_2856 = vec_24;
														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2857);
														mem_vec_2857 = vec_26;
														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2858);
														mem_vec_2858 = vec_27;
														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2859);
														mem_vec_2859 = vec_28;
													}
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2840);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2841);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2842);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2843);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2844);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2845);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2846);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2847);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2848);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2849);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2850);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2851);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2852);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2853);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2854);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2855);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2856);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2857);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2858);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_2859);
										}
									}
								}
}
