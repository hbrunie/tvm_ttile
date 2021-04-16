
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (2, x); T (4, y); T (4, c); T (7, y); T (56, x)]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, h, hp_0, w, wp_0, x, xp_0, x33_p_0, xp_1, x33, y, yp_0, y33_p_0, yp_1, y33;
IND_TYPE y34 = 0;
IND_TYPE x34 = 0;
IND_TYPE h22 = 0;
IND_TYPE w22 = 0;
IND_TYPE c34 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
x33 = 0;
x33_p_0 = 0;
y33 = 0;
y33_p_0 = 0;
c33 = 0;
c33_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_1 = 0;
					for (h = h22, hp_0 = 0;h < h22 + 3;h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w22, wp_0 = 0;w < w22 + 3;w += 1, wp_0 += 1){
									mem_vec_176 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_177 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_178 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_179 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_180 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_181 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_182 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_183 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_188 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_189 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_190 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_191 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;c < c33 + 8;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_176);
										mem_vec_176 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_177);
										mem_vec_177 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_178);
										mem_vec_178 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_179);
										mem_vec_179 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_180);
										mem_vec_180 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_181);
										mem_vec_181 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_182);
										mem_vec_182 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_183);
										mem_vec_183 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_184);
										mem_vec_184 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_185);
										mem_vec_185 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_186);
										mem_vec_186 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_187);
										mem_vec_187 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_188);
										mem_vec_188 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_189);
										mem_vec_189 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_190);
										mem_vec_190 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_191);
										mem_vec_191 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_176);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_177);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_178);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_179);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_180);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_181);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_182);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_183);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_184);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_185);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_186);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_187);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_188);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_189);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_190);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_191);
						}
					}
}
