
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (1, x); T (8, c);
  T (1, x); T (17, y); T (2, f); T (136, x); T (2, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, x, xp_0, x15_p_0, x16_p_0, x17_p_0, xp_1, x15_p_1, x16_p_1, xp_2, x15_p_2, xp_3, x15, x16, x17, y, yp_0, y12_p_0, y13_p_0, yp_1, y12_p_1, yp_2, y12, y13;
IND_TYPE y14 = 0;
IND_TYPE x18 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f6 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
y13 = 0;
y13_p_0 = 0;
x17 = 0;
x17_p_0 = 0;
y12 = 0;
y12_p_1 = 0;
x16 = 0;
x16_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x15 = 0;
x15_p_2 = 0;
c9 = 0;
c9_p_0 = 0;
								for (x = x15, xp_3 = x15_p_2, xp_2 = x15_p_1, xp_1 = x15_p_0, xp_0 = 0;x < x15 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_48 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_49 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_50 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_51 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_52 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_53 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_54 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_55 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_56 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_57 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_58 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_59 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_60 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_61 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_62 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_63 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c9, cp_1 = c9_p_0, cp_0 = 0;c < c9 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_48);
												mem_vec_48 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_49);
												mem_vec_49 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_50);
												mem_vec_50 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_51);
												mem_vec_51 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_52);
												mem_vec_52 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_53);
												mem_vec_53 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_54);
												mem_vec_54 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_55);
												mem_vec_55 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_56);
												mem_vec_56 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_57);
												mem_vec_57 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_58);
												mem_vec_58 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_59);
												mem_vec_59 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_60);
												mem_vec_60 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_61);
												mem_vec_61 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_62);
												mem_vec_62 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_63);
												mem_vec_63 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_48);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_49);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_50);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_51);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_52);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_53);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_54);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_55);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_56);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_57);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_58);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_59);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_60);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_61);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_62);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_63);
								}
}
