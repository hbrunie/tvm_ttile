
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (1, x); T (34, y);
  T (16, c); T (136, x)]
*/
IND_TYPE c, cp_0, c236_p_0, cp_1, c236, x, xp_0, x292_p_0, xp_1, x292, y, yp_0;
IND_TYPE y176 = 0;
IND_TYPE x293 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c237 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1408 ,mem_vec_1409 ,mem_vec_1410 ,mem_vec_1411 ,mem_vec_1412 ,mem_vec_1413 ,mem_vec_1414 ,mem_vec_1415 ,mem_vec_1416 ,mem_vec_1417 ,mem_vec_1418 ,mem_vec_1419 ,mem_vec_1420 ,mem_vec_1421 ,mem_vec_1422 ,mem_vec_1423 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 136) (136 / 1)
x292 = 0;
x292_p_0 = 0;
c236 = 0;
c236_p_0 = 0;
y = 0;
yp_0 = 0;
			for (x = x292, xp_1 = x292_p_0, xp_0 = 0;x < x292 + 1;x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_1408 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
						mem_vec_1409 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
						mem_vec_1410 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
						mem_vec_1411 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
						mem_vec_1412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
						mem_vec_1413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
						mem_vec_1414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
						mem_vec_1415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
						mem_vec_1416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
						mem_vec_1417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
						mem_vec_1418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
						mem_vec_1419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
						mem_vec_1420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
						mem_vec_1421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
						mem_vec_1422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
						mem_vec_1423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (c, 8) (8 / 1)
						for (c = c236, cp_1 = c236_p_0, cp_0 = 0;c < c236 + 8;c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1408);
							mem_vec_1408 = vec_0;
							vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1409);
							mem_vec_1409 = vec_3;
							vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1410);
							mem_vec_1410 = vec_5;
							vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1411);
							mem_vec_1411 = vec_7;
							scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);
							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1412);
							mem_vec_1412 = vec_9;
							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1413);
							mem_vec_1413 = vec_11;
							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1414);
							mem_vec_1414 = vec_12;
							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1415);
							mem_vec_1415 = vec_13;
							scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);
							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1416);
							mem_vec_1416 = vec_14;
							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1417);
							mem_vec_1417 = vec_16;
							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1418);
							mem_vec_1418 = vec_17;
							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1419);
							mem_vec_1419 = vec_18;
							scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);
							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1420);
							mem_vec_1420 = vec_19;
							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1421);
							mem_vec_1421 = vec_21;
							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1422);
							mem_vec_1422 = vec_22;
							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1423);
							mem_vec_1423 = vec_23;
						}
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1408);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1409);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1410);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1411);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1412);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1413);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1414);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1415);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1416);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1417);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1418);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1419);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1420);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1421);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1422);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1423);
			}
}
