
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (4, x); T (4, f);
  T (1, x); T (1, y); T (7, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x76_p_0, x77_p_0, xp_1, x76_p_1, xp_2, x76, x77, y, yp_0, y57_p_0, yp_1, y57;
IND_TYPE y58 = 0;
IND_TYPE x78 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c38 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 7) (28 / 4)
y57 = 0;
y57_p_0 = 0;
x77 = 0;
x77_p_0 = 0;
y = 0;
yp_1 = 0;
x76 = 0;
x76_p_1 = 0;
f = 0;
fp_0 = 0;
					for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;x < x76 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_304 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_305 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
								mem_vec_306 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_307 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
								mem_vec_308 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_309 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
								mem_vec_310 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_311 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
								mem_vec_312 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_313 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
								mem_vec_314 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_315 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
								mem_vec_316 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_317 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
								mem_vec_318 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_319 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c38, cp_0 = 0;c < c38 + 64;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_304);
									mem_vec_304 = vec_0;
									vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_305);
									mem_vec_305 = vec_3;
									vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_306);
									mem_vec_306 = vec_5;
									vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_307);
									mem_vec_307 = vec_7;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);
									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_308);
									mem_vec_308 = vec_9;
									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_309);
									mem_vec_309 = vec_11;
									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_310);
									mem_vec_310 = vec_12;
									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_311);
									mem_vec_311 = vec_13;
									scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);
									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_312);
									mem_vec_312 = vec_14;
									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_313);
									mem_vec_313 = vec_16;
									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_314);
									mem_vec_314 = vec_17;
									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_315);
									mem_vec_315 = vec_18;
									scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);
									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_316);
									mem_vec_316 = vec_19;
									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_317);
									mem_vec_317 = vec_21;
									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_318);
									mem_vec_318 = vec_22;
									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_319);
									mem_vec_319 = vec_23;
								}
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_304);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_305);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_306);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_307);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_308);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_309);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_310);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_311);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_312);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_313);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_314);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_315);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_316);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_317);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_318);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_319);
					}
}
