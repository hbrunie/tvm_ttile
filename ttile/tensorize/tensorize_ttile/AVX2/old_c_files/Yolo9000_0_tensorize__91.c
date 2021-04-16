
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (544, x); T (2, y); T (2, y)]
*/
IND_TYPE c, cp_0, c46_p_0, cp_1, c46, h, hp_0, w, wp_0, x, xp_0, x50_p_0, xp_1, x50, y, yp_0, y62_p_0, y63_p_0, yp_1, y62_p_1, yp_2, y62, y63;
IND_TYPE y64 = 0;
IND_TYPE x51 = 0;
IND_TYPE h28 = 0;
IND_TYPE w30 = 0;
IND_TYPE c47 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
y63 = 0;
y63_p_0 = 0;
y62 = 0;
y62_p_1 = 0;
x50 = 0;
x50_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h28, hp_0 = 0;h < h28 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w30, wp_0 = 0;w < w30 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c46 = c47, c46_p_0 = 0;c46 < c47 + 3;c46 += 3, c46_p_0 += 3){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x50, xp_1 = x50_p_0, xp_0 = 0;x < x50 + 1;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_276 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_277 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_278 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_279 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_280 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_281 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_282 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_283 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_284 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_285 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_286 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_287 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_288 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_289 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c46, cp_1 = c46_p_0, cp_0 = 0;c < c46 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_274);
											mem_vec_274 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_275);
											mem_vec_275 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_276);
											mem_vec_276 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_277);
											mem_vec_277 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_278);
											mem_vec_278 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_279);
											mem_vec_279 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_280);
											mem_vec_280 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_281);
											mem_vec_281 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_282);
											mem_vec_282 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_283);
											mem_vec_283 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_284);
											mem_vec_284 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_285);
											mem_vec_285 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_286);
											mem_vec_286 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_287);
											mem_vec_287 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_288);
											mem_vec_288 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_289);
											mem_vec_289 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_274);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_275);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_276);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_277);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_278);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_279);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_280);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_281);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_282);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_283);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_284);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_285);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_286);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_287);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_288);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_289);
							}
						}
					}
				}
}
