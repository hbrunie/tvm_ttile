void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (16, y); T (1, f); T (1, c); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, f);
  T (1, x)]
*/
IND_TYPE c, cp_0, c426_p_0, cp_1, c426, f, fp_0, f392_p_0, fp_1, f392, h, hp_0, w, wp_0, x, xp_0, x568_p_0, x569_p_0, xp_1, x568_p_1, xp_2, x568, x569, y, yp_0, y426_p_0, yp_1, y426;
IND_TYPE y427 = 0;
IND_TYPE x570 = 0;
IND_TYPE h236 = 0;
IND_TYPE w234 = 0;
IND_TYPE c427 = 0;
IND_TYPE f393 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2464 ,mem_vec_2465 ,mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,mem_vec_2490 ,mem_vec_2491 ,mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
x569 = 0;
x569_p_0 = 0;
f392 = 0;
f392_p_0 = 0;
y426 = 0;
y426_p_0 = 0;
x568 = 0;
x568_p_1 = 0;
c426 = 0;
c426_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
								for (h = h236, hp_0 = 0;h < h236 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w234, wp_0 = 0;w < w234 + 3;w += 1, wp_0 += 1){
										// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
										// T (x, 2) (2 / 1)
										for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;x < x568 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2480 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
													mem_vec_2481 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
													mem_vec_2482 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
													mem_vec_2483 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
													mem_vec_2484 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
													mem_vec_2485 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
													mem_vec_2486 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
													mem_vec_2487 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
													mem_vec_2488 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
													mem_vec_2489 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
													mem_vec_2490 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
													mem_vec_2491 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
													mem_vec_2492 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
													mem_vec_2493 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
													mem_vec_2494 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
													mem_vec_2495 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
													mem_vec_2496 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
													mem_vec_2497 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
													mem_vec_2498 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
													mem_vec_2499 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
													// T (c, 32) (32 / 1)
													for (c = c426, cp_1 = c426_p_0, cp_0 = 0;c < c426 + 32;c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2480);
														mem_vec_2480 = vec_0;
														vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2481);
														mem_vec_2481 = vec_3;
														vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2482);
														mem_vec_2482 = vec_5;
														vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2483);
														mem_vec_2483 = vec_7;
														scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);
														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2484);
														mem_vec_2484 = vec_9;
														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2485);
														mem_vec_2485 = vec_11;
														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2486);
														mem_vec_2486 = vec_12;
														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2487);
														mem_vec_2487 = vec_13;
														scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);
														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2488);
														mem_vec_2488 = vec_14;
														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2489);
														mem_vec_2489 = vec_16;
														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2490);
														mem_vec_2490 = vec_17;
														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2491);
														mem_vec_2491 = vec_18;
														scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);
														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2492);
														mem_vec_2492 = vec_19;
														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2493);
														mem_vec_2493 = vec_21;
														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2494);
														mem_vec_2494 = vec_22;
														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2495);
														mem_vec_2495 = vec_23;
														scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);
														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2496);
														mem_vec_2496 = vec_24;
														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2497);
														mem_vec_2497 = vec_26;
														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2498);
														mem_vec_2498 = vec_27;
														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2499);
														mem_vec_2499 = vec_28;
													}
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2480);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2481);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2482);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2483);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2484);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2485);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2486);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2487);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2488);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2489);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2490);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2491);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2492);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2493);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2494);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2495);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2496);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2497);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2498);
												_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_2499);
										}
									}
								}
}
