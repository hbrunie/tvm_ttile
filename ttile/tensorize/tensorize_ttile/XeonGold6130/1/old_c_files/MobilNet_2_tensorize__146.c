
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (1, x); T (8, y); T (4, x)]
*/
IND_TYPE c, cp_0, c336_p_0, cp_1, c336, h, hp_0, w, wp_0, x, xp_0, x422_p_0, x423_p_0, xp_1, x422_p_1, xp_2, x422, x423, y, yp_0;
IND_TYPE y237 = 0;
IND_TYPE x424 = 0;
IND_TYPE h199 = 0;
IND_TYPE w204 = 0;
IND_TYPE c337 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
x423 = 0;
x423_p_0 = 0;
y = 0;
yp_0 = 0;
x422 = 0;
x422_p_1 = 0;
c336 = 0;
c336_p_0 = 0;
				for (w = w204, wp_0 = 0;w < w204 + 3;w += 1, wp_0 += 1){
					// y = 7, x = 14, h = 3, w = 1, c = 16, f = 64
					// T (x, 14) (14 / 1)
					for (x = x422, xp_2 = x422_p_1, xp_1 = x422_p_0, xp_0 = 0;x < x422 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h199, hp_0 = 0;h < h199 + 3;h += 1, hp_0 += 1){
									mem_vec_3436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_3437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_3438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_3439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_3440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_3441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_3442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_3443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_3444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_3445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_3446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_3447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_3448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_3449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_3450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_3451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_3452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_3453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_3454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_3455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_3456 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_3457 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_3458 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_3459 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_3460 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_3461 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_3462 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_3463 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c336, cp_1 = c336_p_0, cp_0 = 0;c < c336 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3436);
										mem_vec_3436 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3437);
										mem_vec_3437 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3438);
										mem_vec_3438 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3439);
										mem_vec_3439 = vec_7;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3440);
										mem_vec_3440 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3441);
										mem_vec_3441 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3442);
										mem_vec_3442 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3443);
										mem_vec_3443 = vec_13;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3444);
										mem_vec_3444 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3445);
										mem_vec_3445 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3446);
										mem_vec_3446 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3447);
										mem_vec_3447 = vec_18;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3448);
										mem_vec_3448 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3449);
										mem_vec_3449 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3450);
										mem_vec_3450 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3451);
										mem_vec_3451 = vec_23;
										scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3452);
										mem_vec_3452 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3453);
										mem_vec_3453 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3454);
										mem_vec_3454 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3455);
										mem_vec_3455 = vec_28;
										scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3456);
										mem_vec_3456 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3457);
										mem_vec_3457 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3458);
										mem_vec_3458 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3459);
										mem_vec_3459 = vec_33;
										scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3460);
										mem_vec_3460 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3461);
										mem_vec_3461 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3462);
										mem_vec_3462 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3463);
										mem_vec_3463 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3436);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3437);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3438);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3439);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3440);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3441);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3442);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3443);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3444);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3445);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3446);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3447);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3448);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3449);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3450);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3451);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3452);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3453);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_3454);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_3455);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3456);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3457);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_3458);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_3459);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3460);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3461);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_3462);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_3463);
						}
					}
				}
}
