
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (32, c); T (17, x); T (16, y); T (2, f); T (8, x)]
*/
IND_TYPE c, cp_0, c450_p_0, cp_1, c450, f, fp_0, f416_p_0, fp_1, f416, h, hp_0, w, wp_0, x, xp_0, x600_p_0, x601_p_0, xp_1, x600_p_1, xp_2, x600, x601, y, yp_0, y450_p_0, yp_1, y450;
IND_TYPE y451 = 0;
IND_TYPE x602 = 0;
IND_TYPE h252 = 0;
IND_TYPE w250 = 0;
IND_TYPE c451 = 0;
IND_TYPE f417 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2752 ,mem_vec_2753 ,mem_vec_2754 ,mem_vec_2755 ,mem_vec_2756 ,mem_vec_2757 ,mem_vec_2758 ,mem_vec_2759 ,mem_vec_2760 ,mem_vec_2761 ,mem_vec_2762 ,mem_vec_2763 ,mem_vec_2764 ,mem_vec_2765 ,mem_vec_2766 ,mem_vec_2767 ,mem_vec_2768 ,mem_vec_2769 ,mem_vec_2770 ,mem_vec_2771 ,mem_vec_2772 ,mem_vec_2773 ,mem_vec_2774 ,mem_vec_2775 ,mem_vec_2776 ,mem_vec_2777 ,mem_vec_2778 ,mem_vec_2779 ,mem_vec_2780 ,mem_vec_2781 ,mem_vec_2782 ,mem_vec_2783 ,mem_vec_2784 ,mem_vec_2785 ,mem_vec_2786 ,mem_vec_2787 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 8) (272 / 34)
x601 = 0;
x601_p_0 = 0;
f416 = 0;
f416_p_0 = 0;
y450 = 0;
y450_p_0 = 0;
x600 = 0;
x600_p_1 = 0;
c450 = 0;
c450_p_0 = 0;
					for (f = f416, fp_1 = f416_p_0, fp_0 = 0;f < f416 + 32;f += 32, fp_1 += 32, fp_0 += 32){
							for (y = y450, yp_1 = y450_p_0, yp_0 = 0;y < y450 + 12;y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h252, hp_0 = 0;h < h252 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 32
									// T (w, 3) (3 / 1)
									for (w = w250, wp_0 = 0;w < w250 + 3;w += 1, wp_0 += 1){
										// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
										// T (x, 2) (2 / 1)
										for (x = x600, xp_2 = x600_p_1, xp_1 = x600_p_0, xp_0 = 0;x < x600 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2752 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
													mem_vec_2753 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
													mem_vec_2754 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
													mem_vec_2755 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
													mem_vec_2756 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
													mem_vec_2757 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
													mem_vec_2758 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
													mem_vec_2759 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
													mem_vec_2760 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
													mem_vec_2761 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
													mem_vec_2762 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
													mem_vec_2763 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
													mem_vec_2764 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
													mem_vec_2765 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
													mem_vec_2766 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
													mem_vec_2767 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
													// T (c, 1) (1 / 1)
													for (c = c450, cp_1 = c450_p_0, cp_0 = 0;c < c450 + 1;c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2752);
														mem_vec_2752 = vec_0;
														vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2753);
														mem_vec_2753 = vec_3;
														vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2754);
														mem_vec_2754 = vec_5;
														vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2755);
														mem_vec_2755 = vec_7;
														scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);
														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2756);
														mem_vec_2756 = vec_9;
														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2757);
														mem_vec_2757 = vec_11;
														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2758);
														mem_vec_2758 = vec_12;
														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2759);
														mem_vec_2759 = vec_13;
														scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);
														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2760);
														mem_vec_2760 = vec_14;
														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2761);
														mem_vec_2761 = vec_16;
														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2762);
														mem_vec_2762 = vec_17;
														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2763);
														mem_vec_2763 = vec_18;
														scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);
														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2764);
														mem_vec_2764 = vec_19;
														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2765);
														mem_vec_2765 = vec_21;
														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2766);
														mem_vec_2766 = vec_22;
														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2767);
														mem_vec_2767 = vec_23;
													}
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2752);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2753);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2754);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2755);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2756);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2757);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2758);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2759);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2760);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2761);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2762);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2763);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2764);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2765);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2766);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2767);
										}
									}
								}
							}
							for (y = y450 + 12, yp_1 = y450_p_0, yp_0 = 0;y < y450 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h252, hp_0 = 0;h < h252 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 32
									// T (w, 3) (3 / 1)
									for (w = w250, wp_0 = 0;w < w250 + 3;w += 1, wp_0 += 1){
										// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
										// T (x, 2) (2 / 1)
										for (x = x600, xp_2 = x600_p_1, xp_1 = x600_p_0, xp_0 = 0;x < x600 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2768 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
													mem_vec_2769 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
													mem_vec_2770 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
													mem_vec_2771 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
													mem_vec_2772 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
													mem_vec_2773 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
													mem_vec_2774 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
													mem_vec_2775 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
													mem_vec_2776 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
													mem_vec_2777 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
													mem_vec_2778 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
													mem_vec_2779 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
													mem_vec_2780 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
													mem_vec_2781 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
													mem_vec_2782 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
													mem_vec_2783 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
													mem_vec_2784 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
													mem_vec_2785 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
													mem_vec_2786 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
													mem_vec_2787 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
													// T (c, 1) (1 / 1)
													for (c = c450, cp_1 = c450_p_0, cp_0 = 0;c < c450 + 1;c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2768);
														mem_vec_2768 = vec_0;
														vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2769);
														mem_vec_2769 = vec_3;
														vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2770);
														mem_vec_2770 = vec_5;
														vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2771);
														mem_vec_2771 = vec_7;
														scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);
														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2772);
														mem_vec_2772 = vec_9;
														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2773);
														mem_vec_2773 = vec_11;
														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2774);
														mem_vec_2774 = vec_12;
														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2775);
														mem_vec_2775 = vec_13;
														scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);
														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2776);
														mem_vec_2776 = vec_14;
														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2777);
														mem_vec_2777 = vec_16;
														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2778);
														mem_vec_2778 = vec_17;
														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2779);
														mem_vec_2779 = vec_18;
														scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);
														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2780);
														mem_vec_2780 = vec_19;
														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2781);
														mem_vec_2781 = vec_21;
														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2782);
														mem_vec_2782 = vec_22;
														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2783);
														mem_vec_2783 = vec_23;
														scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);
														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2784);
														mem_vec_2784 = vec_24;
														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2785);
														mem_vec_2785 = vec_26;
														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2786);
														mem_vec_2786 = vec_27;
														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2787);
														mem_vec_2787 = vec_28;
													}
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2768);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2769);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2770);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2771);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2772);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2773);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2774);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2775);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2776);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2777);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2778);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2779);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2780);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2781);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2782);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2783);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2784);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2785);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2786);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_2787);
										}
									}
								}
							}
					}
}
