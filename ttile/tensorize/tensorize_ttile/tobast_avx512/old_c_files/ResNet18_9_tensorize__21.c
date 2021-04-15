
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (64, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (4, f); T (4, c); T (7, x); T (7, y); T (1, f)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, f66_p_0, fp_1, f66, w, wp_0, x, xp_0, x66_p_0, xp_1, x66, y, yp_0;
IND_TYPE y44 = 0;
IND_TYPE x67 = 0;
IND_TYPE h = 0;
IND_TYPE w44 = 0;
IND_TYPE c67 = 0;
IND_TYPE f67 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
f66 = 0;
f66_p_0 = 0;
y = 0;
yp_0 = 0;
x66 = 0;
x66_p_0 = 0;
c66 = 0;
c66_p_0 = 0;
f = 0;
fp_1 = 0;
					for (w = w44, wp_0 = 0;w < w44 + 3;w += 1, wp_0 += 1){
						// y = 2, x = 2, h = 3, w = 1, c = 64, f = 64
						// T (x, 2) (2 / 1)
						for (x = x66, xp_1 = x66_p_0, xp_0 = 0;x < x66 + 2;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_338 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_339 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_340 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_341 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_342 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_343 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_344 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_345 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									// y = 2, x = 1, h = 3, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c66, cp_1 = c66_p_0, cp_0 = 0;c < c66 + 64;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_338);
										mem_vec_338 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_339);
										mem_vec_339 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_340);
										mem_vec_340 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_341);
										mem_vec_341 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_342);
										mem_vec_342 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_343);
										mem_vec_343 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_344);
										mem_vec_344 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_345);
										mem_vec_345 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_338);
										mem_vec_338 = vec_14;
										vec_18 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_339);
										mem_vec_339 = vec_17;
										vec_20 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_340);
										mem_vec_340 = vec_19;
										vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_341);
										mem_vec_341 = vec_21;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_342);
										mem_vec_342 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_343);
										mem_vec_343 = vec_25;
										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_344);
										mem_vec_344 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_345);
										mem_vec_345 = vec_27;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_338);
										mem_vec_338 = vec_28;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_339);
										mem_vec_339 = vec_31;
										vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_340);
										mem_vec_340 = vec_33;
										vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_341);
										mem_vec_341 = vec_35;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_342);
										mem_vec_342 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_343);
										mem_vec_343 = vec_39;
										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_344);
										mem_vec_344 = vec_40;
										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_345);
										mem_vec_345 = vec_41;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_338);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_339);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_340);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_341);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_342);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_343);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_344);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_345);
						}
					}
}
