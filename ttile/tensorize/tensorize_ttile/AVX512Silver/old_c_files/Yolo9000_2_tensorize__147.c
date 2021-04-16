
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, h); T (1, x);
  T (3, w); T (2, c); T (1, x); T (17, y); T (1, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c264_p_0, cp_1, c264, h, hp_0, w, wp_0, x, xp_0, x355_p_0, x356_p_0, xp_1, x355_p_1, xp_2, x355, x356, y, yp_0, y349_p_0, y350_p_0, yp_1, y349_p_1, yp_2, y349, y350;
IND_TYPE y351 = 0;
IND_TYPE x357 = 0;
IND_TYPE h134 = 0;
IND_TYPE w131 = 0;
IND_TYPE c265 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
y350 = 0;
y350_p_0 = 0;
x356 = 0;
x356_p_0 = 0;
y349 = 0;
y349_p_1 = 0;
y = 0;
yp_2 = 0;
x355 = 0;
x355_p_1 = 0;
c264 = 0;
c264_p_0 = 0;
						for (w = w131, wp_0 = 0;w < w131 + 3;w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (x, 1) (1 / 1)
							for (x = x355, xp_2 = x355_p_1, xp_1 = x355_p_0, xp_0 = 0;x < x355 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
								// T (h, 3) (3 / 1)
								for (h = h134, hp_0 = 0;h < h134 + 3;h += 1, hp_0 += 1){
											mem_vec_700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_714 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_715 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
											// T (c, 16) (16 / 1)
											for (c = c264, cp_1 = c264_p_0, cp_0 = 0;c < c264 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_700);
												mem_vec_700 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_701);
												mem_vec_701 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_702);
												mem_vec_702 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_703);
												mem_vec_703 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_704);
												mem_vec_704 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_705);
												mem_vec_705 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_706);
												mem_vec_706 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_707);
												mem_vec_707 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_708);
												mem_vec_708 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_709);
												mem_vec_709 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_710);
												mem_vec_710 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_711);
												mem_vec_711 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_712);
												mem_vec_712 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_713);
												mem_vec_713 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_714);
												mem_vec_714 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_715);
												mem_vec_715 = vec_23;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_700);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_701);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_702);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_703);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_704);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_705);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_706);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_707);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_708);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_709);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_710);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_711);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_712);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_713);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_714);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_715);
								}
							}
						}
}
