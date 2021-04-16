
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (3, w); T (68, x);
  T (3, h); T (32, c); T (17, y); T (1, x); T (4, f); T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c288_p_0, c289_p_0, cp_1, c288_p_1, cp_2, c288, c289, f, fp_0, f167_p_0, fp_1, f167, h, hp_0, w, wp_0, x, xp_0, x195_p_0, xp_1, x195, y, yp_0;
IND_TYPE y130 = 0;
IND_TYPE x196 = 0;
IND_TYPE h102 = 0;
IND_TYPE w106 = 0;
IND_TYPE c290 = 0;
IND_TYPE f168 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2172 ,mem_vec_2173 ,mem_vec_2174 ,mem_vec_2175 ,mem_vec_2176 ,mem_vec_2177 ,mem_vec_2178 ,mem_vec_2179 ,mem_vec_2180 ,mem_vec_2181 ,mem_vec_2182 ,mem_vec_2183 ,mem_vec_2184 ,mem_vec_2185 ,mem_vec_2186 ,mem_vec_2187 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f167 = 0;
f167_p_0 = 0;
c289 = 0;
c289_p_0 = 0;
f = 0;
fp_1 = 0;
x195 = 0;
x195_p_0 = 0;
y = 0;
yp_0 = 0;
c288 = 0;
c288_p_1 = 0;
						for (h = h102, hp_0 = 0;h < h102 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 4, f = 32
							// T (x, 68) (68 / 1)
							for (x = x195, xp_1 = x195_p_0, xp_0 = 0;x < x195 + 68;x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w106, wp_0 = 0;w < w106 + 3;w += 1, wp_0 += 1){
											mem_vec_2172 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2173 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_2174 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2175 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_2176 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2177 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_2178 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2179 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_2180 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2181 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_2182 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2183 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_2184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_2186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c288, cp_2 = c288_p_1, cp_1 = c288_p_0, cp_0 = 0;c < c288 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2172);
												mem_vec_2172 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2173);
												mem_vec_2173 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2174);
												mem_vec_2174 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2175);
												mem_vec_2175 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2176);
												mem_vec_2176 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2177);
												mem_vec_2177 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2178);
												mem_vec_2178 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2179);
												mem_vec_2179 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2180);
												mem_vec_2180 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2181);
												mem_vec_2181 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2182);
												mem_vec_2182 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2183);
												mem_vec_2183 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2184);
												mem_vec_2184 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2185);
												mem_vec_2185 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2186);
												mem_vec_2186 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2187);
												mem_vec_2187 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2172);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2173);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2174);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2175);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2176);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2177);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2178);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2179);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2180);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2181);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2182);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2183);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2184);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2185);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2186);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2187);
								}
							}
						}
}
