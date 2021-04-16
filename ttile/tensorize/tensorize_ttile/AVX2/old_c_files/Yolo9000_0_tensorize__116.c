
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
  T (3, w); T (3, h); T (34, y); T (544, x); T (4, y); T (1, y)]
*/
IND_TYPE c, cp_0, c43_p_0, cp_1, c43, h, hp_0, w, wp_0, x, xp_0, x47_p_0, xp_1, x47, y, yp_0, y58_p_0, y59_p_0, yp_1, y58_p_1, yp_2, y58, y59;
IND_TYPE y60 = 0;
IND_TYPE x48 = 0;
IND_TYPE h26 = 0;
IND_TYPE w28 = 0;
IND_TYPE c44 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
y59 = 0;
y59_p_0 = 0;
y58 = 0;
y58_p_1 = 0;
x47 = 0;
x47_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h26, hp_0 = 0;h < h26 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w28, wp_0 = 0;w < w28 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c43 = c44, c43_p_0 = 0;c43 < c44 + 3;c43 += 3, c43_p_0 += 3){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x47, xp_1 = x47_p_0, xp_0 = 0;x < x47 + 1;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_258 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_259 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c43, cp_1 = c43_p_0, cp_0 = 0;c < c43 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_258);
											mem_vec_258 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_259);
											mem_vec_259 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_260);
											mem_vec_260 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_261);
											mem_vec_261 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_262);
											mem_vec_262 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_263);
											mem_vec_263 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_264);
											mem_vec_264 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_265);
											mem_vec_265 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_266);
											mem_vec_266 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_267);
											mem_vec_267 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_268);
											mem_vec_268 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_269);
											mem_vec_269 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_270);
											mem_vec_270 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_271);
											mem_vec_271 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_272);
											mem_vec_272 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_273);
											mem_vec_273 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_258);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_259);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_260);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_261);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_262);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_263);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_264);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_265);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_266);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_267);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_268);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_269);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_270);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_271);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_272);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_273);
							}
						}
					}
				}
}
