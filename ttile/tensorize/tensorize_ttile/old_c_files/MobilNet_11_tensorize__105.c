
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (16, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (32, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c282_p_0, cp_1, c282, h, hp_0, w, wp_0, x, xp_0, x376_p_0, x377_p_0, xp_1, x376_p_1, xp_2, x376, x377, y, yp_0;
IND_TYPE y188 = 0;
IND_TYPE x378 = 0;
IND_TYPE h168 = 0;
IND_TYPE w188 = 0;
IND_TYPE c283 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2376 ,mem_vec_2377 ,mem_vec_2378 ,mem_vec_2379 ,mem_vec_2380 ,mem_vec_2381 ,mem_vec_2382 ,mem_vec_2383 ,mem_vec_2384 ,mem_vec_2385 ,mem_vec_2386 ,mem_vec_2387 ,mem_vec_2388 ,mem_vec_2389 ,mem_vec_2390 ,mem_vec_2391 ,mem_vec_2392 ,mem_vec_2393 ,mem_vec_2394 ,mem_vec_2395 ,mem_vec_2396 ,mem_vec_2397 ,mem_vec_2398 ,mem_vec_2399 ,mem_vec_2400 ,mem_vec_2401 ,mem_vec_2402 ,mem_vec_2403 ,mem_vec_2404 ,mem_vec_2405 ,mem_vec_2406 ,mem_vec_2407 ,mem_vec_2408 ,mem_vec_2409 ,mem_vec_2410 ,mem_vec_2411 ,mem_vec_2412 ,mem_vec_2413 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x377 = 0;
x377_p_0 = 0;
c282 = 0;
c282_p_0 = 0;
y = 0;
yp_0 = 0;
x376 = 0;
x376_p_1 = 0;
					for (h = h168, hp_0 = 0;h < h168 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w188, wp_0 = 0;w < w188 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
							// T (x, 1) (1 / 1)
							for (x = x376, xp_2 = x376_p_1, xp_1 = x376_p_0, xp_0 = 0;x < x376 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2376 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2377 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2378 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2379 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_2385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_2386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_2387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_2388 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_2389 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_2390 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_2391 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c282, cp_1 = c282_p_0, cp_0 = 0;c < c282 + 1;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2376);
											mem_vec_2376 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2377);
											mem_vec_2377 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2378);
											mem_vec_2378 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2379);
											mem_vec_2379 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2380);
											mem_vec_2380 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2381);
											mem_vec_2381 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2382);
											mem_vec_2382 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2383);
											mem_vec_2383 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2384);
											mem_vec_2384 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2385);
											mem_vec_2385 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2386);
											mem_vec_2386 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2387);
											mem_vec_2387 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2388);
											mem_vec_2388 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2389);
											mem_vec_2389 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2390);
											mem_vec_2390 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2391);
											mem_vec_2391 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2376);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2377);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2378);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2379);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2380);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2381);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2382);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2383);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2384);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2385);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2386);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2387);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2388);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2389);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2390);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2391);
							}
						}
					}
}
