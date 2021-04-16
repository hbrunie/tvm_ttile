
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (2, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, x, xp_0, x15_p_0, xp_1, x15, y, yp_0, y15_p_0, yp_1, y15;
IND_TYPE y16 = 0;
IND_TYPE x16 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c16 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y15 = 0;
y15_p_0 = 0;
x15 = 0;
x15_p_0 = 0;
c15 = 0;
c15_p_0 = 0;
			for (f = f10, fp_0 = 0;f < f10 + 512;f += 32, fp_0 += 32){
					for (y = y15, yp_1 = y15_p_0, yp_0 = 0;y < y15 + 12;y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x15, xp_1 = x15_p_0, xp_0 = 0;x < x15 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_180 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_181 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_182 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_183 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_188 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_189 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_190 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_191 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_192 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_193 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_194 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_195 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c15, cp_1 = c15_p_0, cp_0 = 0;c < c15 + 512;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_180);
										mem_vec_180 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_181);
										mem_vec_181 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_182);
										mem_vec_182 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_183);
										mem_vec_183 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_184);
										mem_vec_184 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_185);
										mem_vec_185 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_186);
										mem_vec_186 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_187);
										mem_vec_187 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_188);
										mem_vec_188 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_189);
										mem_vec_189 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_190);
										mem_vec_190 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_191);
										mem_vec_191 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_192);
										mem_vec_192 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_193);
										mem_vec_193 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_194);
										mem_vec_194 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_195);
										mem_vec_195 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_180);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_181);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_182);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_183);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_184);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_185);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_186);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_187);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_188);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_189);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_190);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_191);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_192);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_193);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_194);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_195);
						}
					}
					for (y = y15 + 12, yp_1 = y15_p_0, yp_0 = 0;y < y15 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x15, xp_1 = x15_p_0, xp_0 = 0;x < x15 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_196 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_197 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_198 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_199 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_200 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_201 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_202 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_203 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_204 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_205 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_206 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_207 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_208 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_209 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_210 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_211 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_212 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_213 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_214 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_215 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c15, cp_1 = c15_p_0, cp_0 = 0;c < c15 + 512;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_196);
										mem_vec_196 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_197);
										mem_vec_197 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_198);
										mem_vec_198 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_199);
										mem_vec_199 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_200);
										mem_vec_200 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_201);
										mem_vec_201 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_202);
										mem_vec_202 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_203);
										mem_vec_203 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_204);
										mem_vec_204 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_205);
										mem_vec_205 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_206);
										mem_vec_206 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_207);
										mem_vec_207 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_208);
										mem_vec_208 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_209);
										mem_vec_209 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_210);
										mem_vec_210 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_211);
										mem_vec_211 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_212);
										mem_vec_212 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_213);
										mem_vec_213 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_214);
										mem_vec_214 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_215);
										mem_vec_215 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_196);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_197);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_198);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_199);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_200);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_201);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_202);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_203);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_204);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_205);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_206);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_207);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_208);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_209);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_210);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_211);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_212);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_213);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_214);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_215);
						}
					}
			}
}
