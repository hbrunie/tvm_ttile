
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (14, x); T (1, c);
  T (7, w); T (7, h); T (4, y); T (8, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c129_p_0, cp_1, c129, f, fp_0, f129_p_0, fp_1, f129, h, hp_0, w, wp_0, x, xp_0, x129_p_0, xp_1, x129, y, yp_0, y129_p_0, yp_1, y129;
IND_TYPE y130 = 0;
IND_TYPE x130 = 0;
IND_TYPE h86 = 0;
IND_TYPE w86 = 0;
IND_TYPE c130 = 0;
IND_TYPE f130 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 2) (64 / 32)
f129 = 0;
f129_p_0 = 0;
f = 0;
fp_1 = 0;
y129 = 0;
y129_p_0 = 0;
x129 = 0;
x129_p_0 = 0;
y = 0;
yp_1 = 0;
					for (h = h86, hp_0 = 0;h < h86 + 7;h += 1, hp_0 += 1){
						// y = 4, x = 14, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w86, wp_0 = 0;w < w86 + 7;w += 1, wp_0 += 1){
							// y = 4, x = 14, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c129 = c130, c129_p_0 = 0;c129 < c130 + 3;c129 += 3, c129_p_0 += 3){
								// y = 4, x = 14, h = 1, w = 1, c = 3, f = 32
								// T (x, 14) (14 / 1)
								for (x = x129, xp_1 = x129_p_0, xp_0 = 0;x < x129 + 14;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_728 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_729 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_730 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_731 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_732 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_733 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_734 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_735 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_736 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_737 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_738 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_739 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_740 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_741 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_742 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_743 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c129, cp_1 = c129_p_0, cp_0 = 0;c < c129 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_728);
												mem_vec_728 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_729);
												mem_vec_729 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_730);
												mem_vec_730 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_731);
												mem_vec_731 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_732);
												mem_vec_732 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_733);
												mem_vec_733 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_734);
												mem_vec_734 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_735);
												mem_vec_735 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_736);
												mem_vec_736 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_737);
												mem_vec_737 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_738);
												mem_vec_738 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_739);
												mem_vec_739 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_740);
												mem_vec_740 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_741);
												mem_vec_741 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_742);
												mem_vec_742 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_743);
												mem_vec_743 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_728);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_729);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_730);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_731);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_732);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_733);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_734);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_735);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_736);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_737);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_738);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_739);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_740);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_741);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_742);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_743);
								}
							}
						}
					}
}
