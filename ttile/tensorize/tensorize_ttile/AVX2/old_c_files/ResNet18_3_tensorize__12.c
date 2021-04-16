
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (4, x); T (2, f);
  T (7, x); T (7, y); T (2, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x36_p_0, x37_p_0, xp_1, x36_p_1, xp_2, x36, x37, y, yp_0, y27_p_0, yp_1, y27;
IND_TYPE y28 = 0;
IND_TYPE x38 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c18 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 2) (56 / 28)
y27 = 0;
y27_p_0 = 0;
x37 = 0;
x37_p_0 = 0;
y = 0;
yp_1 = 0;
x36 = 0;
x36_p_1 = 0;
f = 0;
fp_0 = 0;
					for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;x < x36 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_144 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_145 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
								mem_vec_146 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_147 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
								mem_vec_148 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_149 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
								mem_vec_150 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_151 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
								mem_vec_152 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_153 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
								mem_vec_154 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_155 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
								mem_vec_156 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_157 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
								mem_vec_158 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_159 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c18, cp_0 = 0;c < c18 + 64;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_144);
									mem_vec_144 = vec_0;
									vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_145);
									mem_vec_145 = vec_3;
									vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_146);
									mem_vec_146 = vec_5;
									vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_147);
									mem_vec_147 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);
									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_148);
									mem_vec_148 = vec_9;
									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_149);
									mem_vec_149 = vec_11;
									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_150);
									mem_vec_150 = vec_12;
									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_151);
									mem_vec_151 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);
									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_152);
									mem_vec_152 = vec_14;
									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_153);
									mem_vec_153 = vec_16;
									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_154);
									mem_vec_154 = vec_17;
									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_155);
									mem_vec_155 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);
									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_156);
									mem_vec_156 = vec_19;
									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_157);
									mem_vec_157 = vec_21;
									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_158);
									mem_vec_158 = vec_22;
									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_159);
									mem_vec_159 = vec_23;
								}
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_144);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_145);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_146);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_147);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_148);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_149);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_150);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_151);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_152);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_153);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_154);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_155);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_156);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_157);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_158);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_159);
					}
}
