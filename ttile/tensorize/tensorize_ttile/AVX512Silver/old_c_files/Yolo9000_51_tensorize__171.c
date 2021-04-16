
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (4, y);
  T (1, c); T (136, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c233_p_0, cp_1, c233, x, xp_0, x309_p_0, xp_1, x309, y, yp_0, y309_p_0, yp_1, y309;
IND_TYPE y310 = 0;
IND_TYPE x310 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c234 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4310 ,mem_vec_4311 ,mem_vec_4312 ,mem_vec_4313 ,mem_vec_4314 ,mem_vec_4315 ,mem_vec_4316 ,mem_vec_4317 ,mem_vec_4318 ,mem_vec_4319 ,mem_vec_4320 ,mem_vec_4321 ,mem_vec_4322 ,mem_vec_4323 ,mem_vec_4324 ,mem_vec_4325 ,mem_vec_4326 ,mem_vec_4327 ,mem_vec_4328 ,mem_vec_4329 ,mem_vec_4330 ,mem_vec_4331 ,mem_vec_4332 ,mem_vec_4333 ,mem_vec_4334 ,mem_vec_4335 ,mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,mem_vec_4345 ,mem_vec_4346 ,mem_vec_4347 ,mem_vec_4348 ,mem_vec_4349 ,mem_vec_4350 ,mem_vec_4351 ,mem_vec_4352 ,mem_vec_4353 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y309 = 0;
y309_p_0 = 0;
x309 = 0;
x309_p_0 = 0;
c233 = 0;
c233_p_0 = 0;
y = 0;
yp_1 = 0;
					for (x = x309, xp_1 = x309_p_0, xp_0 = 0;x < x309 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_4311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_4312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_4313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_4314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_4315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_4316 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_4317 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_4318 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_4319 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_4320 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_4321 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_4322 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_4323 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_4324 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_4325 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c233, cp_1 = c233_p_0, cp_0 = 0;c < c233 + 128;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4310);
									mem_vec_4310 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4311);
									mem_vec_4311 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4312);
									mem_vec_4312 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4313);
									mem_vec_4313 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4314);
									mem_vec_4314 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4315);
									mem_vec_4315 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4316);
									mem_vec_4316 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4317);
									mem_vec_4317 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4318);
									mem_vec_4318 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4319);
									mem_vec_4319 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4320);
									mem_vec_4320 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4321);
									mem_vec_4321 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4322);
									mem_vec_4322 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4323);
									mem_vec_4323 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4324);
									mem_vec_4324 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4325);
									mem_vec_4325 = vec_23;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4310);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4311);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4312);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4313);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4314);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4315);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4316);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4317);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4318);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4319);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4320);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4321);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4322);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4323);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_4324);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_4325);
					}
}
