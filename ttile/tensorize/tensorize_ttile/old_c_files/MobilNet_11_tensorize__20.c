
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))]; T (32, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c354_p_0, cp_1, c354, h, hp_0, w, wp_0, x, xp_0, x472_p_0, x473_p_0, xp_1, x472_p_1, xp_2, x472, x473, y, yp_0;
IND_TYPE y236 = 0;
IND_TYPE x474 = 0;
IND_TYPE h216 = 0;
IND_TYPE w236 = 0;
IND_TYPE c355 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3376 ,mem_vec_3377 ,mem_vec_3378 ,mem_vec_3379 ,mem_vec_3380 ,mem_vec_3381 ,mem_vec_3382 ,mem_vec_3383 ,mem_vec_3384 ,mem_vec_3385 ,mem_vec_3386 ,mem_vec_3387 ,mem_vec_3388 ,mem_vec_3389 ,mem_vec_3390 ,mem_vec_3391 ,mem_vec_3392 ,mem_vec_3393 ,mem_vec_3394 ,mem_vec_3395 ,mem_vec_3396 ,mem_vec_3397 ,mem_vec_3398 ,mem_vec_3399 ,mem_vec_3400 ,mem_vec_3401 ,mem_vec_3402 ,mem_vec_3403 ,mem_vec_3404 ,mem_vec_3405 ,mem_vec_3406 ,mem_vec_3407 ,mem_vec_3408 ,mem_vec_3409 ,mem_vec_3410 ,mem_vec_3411 ,mem_vec_3412 ,mem_vec_3413 ,mem_vec_3414 ,mem_vec_3415 ,mem_vec_3416 ,mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
x473 = 0;
x473_p_0 = 0;
c354 = 0;
c354_p_0 = 0;
y = 0;
yp_0 = 0;
x472 = 0;
x472_p_1 = 0;
					for (h = h216, hp_0 = 0;h < h216 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w236, wp_0 = 0;w < w236 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 1, f = 32
							// T (x, 8) (8 / 1)
							for (x = x472, xp_2 = x472_p_1, xp_1 = x472_p_0, xp_0 = 0;x < x472 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3376 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3377 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3378 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3379 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3388 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_3389 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_3390 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_3391 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c354, cp_1 = c354_p_0, cp_0 = 0;c < c354 + 1;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3376);
											mem_vec_3376 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3377);
											mem_vec_3377 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3378);
											mem_vec_3378 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3379);
											mem_vec_3379 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3380);
											mem_vec_3380 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3381);
											mem_vec_3381 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3382);
											mem_vec_3382 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3383);
											mem_vec_3383 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3384);
											mem_vec_3384 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3385);
											mem_vec_3385 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3386);
											mem_vec_3386 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3387);
											mem_vec_3387 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3388);
											mem_vec_3388 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3389);
											mem_vec_3389 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3390);
											mem_vec_3390 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3391);
											mem_vec_3391 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3376);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3377);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3378);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3379);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3380);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3381);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3382);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3383);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3384);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3385);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3386);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3387);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3388);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3389);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3390);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3391);
							}
						}
					}
}
