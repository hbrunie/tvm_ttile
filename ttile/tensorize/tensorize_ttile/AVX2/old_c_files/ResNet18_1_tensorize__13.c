
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (16, x); T (1, c);
  T (7, w); T (7, h); T (4, y); T (7, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c123_p_0, cp_1, c123, f, fp_0, f123_p_0, fp_1, f123, h, hp_0, w, wp_0, x, xp_0, x123_p_0, xp_1, x123, y, yp_0, y123_p_0, yp_1, y123;
IND_TYPE y124 = 0;
IND_TYPE x124 = 0;
IND_TYPE h82 = 0;
IND_TYPE w82 = 0;
IND_TYPE c124 = 0;
IND_TYPE f124 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 2) (64 / 32)
f123 = 0;
f123_p_0 = 0;
f = 0;
fp_1 = 0;
y123 = 0;
y123_p_0 = 0;
x123 = 0;
x123_p_0 = 0;
y = 0;
yp_1 = 0;
					for (h = h82, hp_0 = 0;h < h82 + 7;h += 1, hp_0 += 1){
						// y = 4, x = 16, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w82, wp_0 = 0;w < w82 + 7;w += 1, wp_0 += 1){
							// y = 4, x = 16, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c123 = c124, c123_p_0 = 0;c123 < c124 + 3;c123 += 3, c123_p_0 += 3){
								// y = 4, x = 16, h = 1, w = 1, c = 3, f = 32
								// T (x, 16) (16 / 1)
								for (x = x123, xp_1 = x123_p_0, xp_0 = 0;x < x123 + 16;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_696 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_697 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_698 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_699 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_700 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_701 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_702 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_703 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_704 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_705 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_706 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_707 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_708 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_709 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_710 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_711 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c123, cp_1 = c123_p_0, cp_0 = 0;c < c123 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_696);
												mem_vec_696 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_697);
												mem_vec_697 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_698);
												mem_vec_698 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_699);
												mem_vec_699 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_700);
												mem_vec_700 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_701);
												mem_vec_701 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_702);
												mem_vec_702 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_703);
												mem_vec_703 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_704);
												mem_vec_704 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_705);
												mem_vec_705 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_706);
												mem_vec_706 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_707);
												mem_vec_707 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_708);
												mem_vec_708 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_709);
												mem_vec_709 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_710);
												mem_vec_710 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_711);
												mem_vec_711 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_696);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_697);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_698);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_699);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_700);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_701);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_702);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_703);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_704);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_705);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_706);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_707);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_708);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_709);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_710);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_711);
								}
							}
						}
					}
}
