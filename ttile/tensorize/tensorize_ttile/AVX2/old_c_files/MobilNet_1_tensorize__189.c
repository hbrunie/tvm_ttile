
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (2, x); T (2, y); T (1, c); T (14, y); T (56, x)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0, y36_p_0, yp_1, y36;
IND_TYPE y37 = 0;
IND_TYPE x37 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
x36 = 0;
x36_p_0 = 0;
y36 = 0;
y36_p_0 = 0;
c36 = 0;
c36_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_1 = 0;
					for (h = h24, hp_0 = 0;h < h24 + 3;h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w24, wp_0 = 0;w < w24 + 3;w += 1, wp_0 += 1){
									mem_vec_192 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_193 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_194 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_195 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_196 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_197 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_198 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_199 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_200 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_201 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_202 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_203 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_204 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_205 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_206 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_207 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;c < c36 + 32;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_192);
										mem_vec_192 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_193);
										mem_vec_193 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_194);
										mem_vec_194 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_195);
										mem_vec_195 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_196);
										mem_vec_196 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_197);
										mem_vec_197 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_198);
										mem_vec_198 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_199);
										mem_vec_199 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_200);
										mem_vec_200 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_201);
										mem_vec_201 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_202);
										mem_vec_202 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_203);
										mem_vec_203 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_204);
										mem_vec_204 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_205);
										mem_vec_205 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_206);
										mem_vec_206 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_207);
										mem_vec_207 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_192);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_193);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_194);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_195);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_196);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_197);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_198);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_199);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_200);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_201);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_202);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_203);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_204);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_205);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_206);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_207);
						}
					}
}
