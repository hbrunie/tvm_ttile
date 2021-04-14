
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, f); T (128, c); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c474_p_0, cp_1, c474, f, fp_0, f474_p_0, fp_1, f474, h, hp_0, w, wp_0, x, xp_0, x474_p_0, xp_1, x474, y, yp_0;
IND_TYPE y316 = 0;
IND_TYPE x475 = 0;
IND_TYPE h248 = 0;
IND_TYPE w286 = 0;
IND_TYPE c475 = 0;
IND_TYPE f475 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,mem_vec_3814 ,mem_vec_3815 ,mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
f474 = 0;
f474_p_0 = 0;
y = 0;
yp_0 = 0;
x474 = 0;
x474_p_0 = 0;
c474 = 0;
c474_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h248, hp_0 = 0;h < h248 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w286, wp_0 = 0;w < w286 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 32
								// T (x, 7) (7 / 1)
								for (x = x474, xp_1 = x474_p_0, xp_0 = 0;x < x474 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_3811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_3812 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_3813 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_3814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_3815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c474, cp_1 = c474_p_0, cp_0 = 0;c < c474 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3800);
												mem_vec_3800 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3801);
												mem_vec_3801 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3802);
												mem_vec_3802 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3803);
												mem_vec_3803 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3804);
												mem_vec_3804 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3805);
												mem_vec_3805 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3806);
												mem_vec_3806 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3807);
												mem_vec_3807 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3808);
												mem_vec_3808 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3809);
												mem_vec_3809 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3810);
												mem_vec_3810 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3811);
												mem_vec_3811 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3812);
												mem_vec_3812 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3813);
												mem_vec_3813 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3814);
												mem_vec_3814 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3815);
												mem_vec_3815 = vec_25;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3800);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3801);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3802);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3803);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3804);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3805);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3806);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3807);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3808);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3809);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3810);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3811);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3812);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3813);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3814);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3815);
								}
							}
						}
}
