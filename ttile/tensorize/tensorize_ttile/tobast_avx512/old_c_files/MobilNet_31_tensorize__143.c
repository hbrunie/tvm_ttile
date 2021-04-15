
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))];
  T (2, f); T (64, c); T (2, f); T (4, x); T (2, f)]
*/
IND_TYPE c, cp_0, c780_p_0, cp_1, c780, f, fp_0, f788_p_0, f789_p_0, fp_1, f788_p_1, fp_2, f788, f789, h, hp_0, x, xp_0, x906_p_0, xp_1, x906, y, yp_0;
IND_TYPE y520 = 0;
IND_TYPE x907 = 0;
IND_TYPE h346 = 0;
IND_TYPE w = 0;
IND_TYPE c781 = 0;
IND_TYPE f790 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5830 ,mem_vec_5831 ,mem_vec_5832 ,mem_vec_5833 ,mem_vec_5834 ,mem_vec_5835 ,mem_vec_5836 ,mem_vec_5837 ,mem_vec_5838 ,mem_vec_5839 ,mem_vec_5840 ,mem_vec_5841 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f789 = 0;
f789_p_0 = 0;
x906 = 0;
x906_p_0 = 0;
f788 = 0;
f788_p_1 = 0;
c780 = 0;
c780_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h346, hp_0 = 0;h < h346 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 16
								// T (x, 14) (14 / 1)
								for (x = x906, xp_1 = x906_p_0, xp_0 = 0;x < x906 + 14;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5832 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5833 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5834 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c780, cp_1 = c780_p_0, cp_0 = 0;c < c780 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5830);
												mem_vec_5830 = vec_0;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);
												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5831);
												mem_vec_5831 = vec_3;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5832);
												mem_vec_5832 = vec_5;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);
												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5833);
												mem_vec_5833 = vec_7;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5834);
												mem_vec_5834 = vec_9;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_13 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_5830);
												mem_vec_5830 = vec_11;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_15 = _mm512_set1_ps(scal_6);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_5831);
												mem_vec_5831 = vec_14;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_17 = _mm512_set1_ps(scal_7);
												vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_5832);
												mem_vec_5832 = vec_16;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_19 = _mm512_set1_ps(scal_8);
												vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_5833);
												mem_vec_5833 = vec_18;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_21 = _mm512_set1_ps(scal_9);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_5834);
												mem_vec_5834 = vec_20;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_23 = _mm512_set1_ps(scal_10);
												vec_24 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_5830);
												mem_vec_5830 = vec_22;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_26 = _mm512_set1_ps(scal_11);
												vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_5831);
												mem_vec_5831 = vec_25;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_28 = _mm512_set1_ps(scal_12);
												vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_5832);
												mem_vec_5832 = vec_27;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_30 = _mm512_set1_ps(scal_13);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_5833);
												mem_vec_5833 = vec_29;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_32 = _mm512_set1_ps(scal_14);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_5834);
												mem_vec_5834 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5830);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5831);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5832);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5833);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5834);
								}
							}
}
