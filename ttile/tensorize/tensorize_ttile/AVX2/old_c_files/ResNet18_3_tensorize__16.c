
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (7, x); T (2, f);
  T (2, x); T (14, y); T (4, x); T (1, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x52_p_0, x53_p_0, xp_1, x52_p_1, xp_2, x52, x53, y, yp_0, y39_p_0, yp_1, y39;
IND_TYPE y40 = 0;
IND_TYPE x54 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c26 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
y39 = 0;
y39_p_0 = 0;
x53 = 0;
x53_p_0 = 0;
y = 0;
yp_1 = 0;
x52 = 0;
x52_p_1 = 0;
f = 0;
fp_0 = 0;
					for (x = x52, xp_2 = x52_p_1, xp_1 = x52_p_0, xp_0 = 0;x < x52 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_208 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_209 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
								mem_vec_210 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_211 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
								mem_vec_212 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_213 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
								mem_vec_214 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_215 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
								mem_vec_216 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_217 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
								mem_vec_218 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_219 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
								mem_vec_220 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_221 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
								mem_vec_222 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_223 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c26, cp_0 = 0;c < c26 + 64;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_208);
									mem_vec_208 = vec_0;
									vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_209);
									mem_vec_209 = vec_3;
									vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_210);
									mem_vec_210 = vec_5;
									vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_211);
									mem_vec_211 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);
									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_212);
									mem_vec_212 = vec_9;
									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_213);
									mem_vec_213 = vec_11;
									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_214);
									mem_vec_214 = vec_12;
									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_215);
									mem_vec_215 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);
									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_216);
									mem_vec_216 = vec_14;
									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_217);
									mem_vec_217 = vec_16;
									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_218);
									mem_vec_218 = vec_17;
									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_219);
									mem_vec_219 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);
									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_220);
									mem_vec_220 = vec_19;
									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_221);
									mem_vec_221 = vec_21;
									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_222);
									mem_vec_222 = vec_22;
									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_223);
									mem_vec_223 = vec_23;
								}
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_208);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_209);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_210);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_211);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_212);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_213);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_214);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_215);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_216);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_217);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_218);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_219);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_220);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_221);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_222);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_223);
					}
}
