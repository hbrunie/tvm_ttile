
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 2), (Arg 14))]; T (2, f);
  T (34, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x189_p_0, xp_1, x189, y, yp_0, y189_p_0, yp_1, y189;
IND_TYPE y190 = 0;
IND_TYPE x190 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c126 = 0;
IND_TYPE f126 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,mem_vec_2490 ,mem_vec_2491 ,mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,mem_vec_2500 ,mem_vec_2501 ,mem_vec_2502 ,mem_vec_2503 ,mem_vec_2504 ,mem_vec_2505 ,mem_vec_2506 ,mem_vec_2507 ,mem_vec_2508 ,mem_vec_2509 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
y189 = 0;
y189_p_0 = 0;
x189 = 0;
x189_p_0 = 0;
		for (f = f126, fp_0 = 0;f < f126 + 64;f += 32, fp_0 += 32){
				for (y = y189, yp_1 = y189_p_0, yp_0 = 0;y < y189 + 40;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x189, xp_1 = x189_p_0, xp_0 = 0;x < x189 + 4;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2466 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_2467 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_2468 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_2469 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_2470 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_2471 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_2472 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_2473 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_2474 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_2475 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_2476 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_2477 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_2478 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_2479 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_2480 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_2481 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c126, cp_0 = 0;c < c126 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2466);
									mem_vec_2466 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2467);
									mem_vec_2467 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2468);
									mem_vec_2468 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2469);
									mem_vec_2469 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2470);
									mem_vec_2470 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2471);
									mem_vec_2471 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2472);
									mem_vec_2472 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2473);
									mem_vec_2473 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2474);
									mem_vec_2474 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2475);
									mem_vec_2475 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2476);
									mem_vec_2476 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2477);
									mem_vec_2477 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2478);
									mem_vec_2478 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2479);
									mem_vec_2479 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2480);
									mem_vec_2480 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2481);
									mem_vec_2481 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2466);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2467);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2468);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2469);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2470);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2471);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2472);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2473);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2474);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2475);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2476);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2477);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2478);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2479);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2480);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2481);
					}
				}
				for (y = y189 + 40, yp_1 = y189_p_0, yp_0 = 0;y < y189 + 40 + 28;y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x189, xp_1 = x189_p_0, xp_0 = 0;x < x189 + 4;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2482 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_2483 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_2484 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_2485 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_2486 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_2487 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_2488 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_2489 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_2490 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_2491 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_2492 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_2493 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_2494 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_2495 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_2496 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_2497 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_2498 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_2499 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_2500 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_2501 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								mem_vec_2502 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
								mem_vec_2503 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
								mem_vec_2504 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
								mem_vec_2505 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
								mem_vec_2506 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
								mem_vec_2507 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
								mem_vec_2508 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
								mem_vec_2509 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c126, cp_0 = 0;c < c126 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2482);
									mem_vec_2482 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2483);
									mem_vec_2483 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2484);
									mem_vec_2484 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2485);
									mem_vec_2485 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2486);
									mem_vec_2486 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2487);
									mem_vec_2487 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2488);
									mem_vec_2488 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2489);
									mem_vec_2489 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2490);
									mem_vec_2490 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2491);
									mem_vec_2491 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2492);
									mem_vec_2492 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2493);
									mem_vec_2493 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2494);
									mem_vec_2494 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2495);
									mem_vec_2495 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2496);
									mem_vec_2496 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2497);
									mem_vec_2497 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2498);
									mem_vec_2498 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2499);
									mem_vec_2499 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2500);
									mem_vec_2500 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2501);
									mem_vec_2501 = vec_31;
									scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2502);
									mem_vec_2502 = vec_32;
									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2503);
									mem_vec_2503 = vec_34;
									scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2504);
									mem_vec_2504 = vec_35;
									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2505);
									mem_vec_2505 = vec_37;
									scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);
									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2506);
									mem_vec_2506 = vec_38;
									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2507);
									mem_vec_2507 = vec_40;
									scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);
									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2508);
									mem_vec_2508 = vec_41;
									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2509);
									mem_vec_2509 = vec_43;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2482);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2483);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2484);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2485);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2486);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2487);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2488);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2489);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2490);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2491);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2492);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2493);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2494);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2495);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2496);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2497);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2498);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2499);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2500);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2501);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2502);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_2503);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_2504);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_2505);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_2506);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_2507);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_2508);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_2509);
					}
				}
		}
}
