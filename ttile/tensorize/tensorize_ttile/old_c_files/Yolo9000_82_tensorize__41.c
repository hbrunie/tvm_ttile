void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))];
  T (8, f); T (16, c); T (1, f); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, f368_p_0, f369_p_0, fp_1, f368_p_1, fp_2, f368, f369, h, hp_0, w, wp_0, x, xp_0, x328_p_0, xp_1, x328, y, yp_0;
IND_TYPE y184 = 0;
IND_TYPE x329 = 0;
IND_TYPE h184 = 0;
IND_TYPE w132 = 0;
IND_TYPE c277 = 0;
IND_TYPE f370 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2376 ,mem_vec_2377 ,mem_vec_2378 ,mem_vec_2379 ,mem_vec_2380 ,mem_vec_2381 ,mem_vec_2382 ,mem_vec_2383 ,mem_vec_2384 ,mem_vec_2385 ,mem_vec_2386 ,mem_vec_2387 ,mem_vec_2388 ,mem_vec_2389 ,mem_vec_2390 ,mem_vec_2391 ,mem_vec_2392 ,mem_vec_2393 ,mem_vec_2394 ,mem_vec_2395 ,mem_vec_2396 ,mem_vec_2397 ,mem_vec_2398 ,mem_vec_2399 ,mem_vec_2400 ,mem_vec_2401 ,mem_vec_2402 ,mem_vec_2403 ,mem_vec_2404 ,mem_vec_2405 ,mem_vec_2406 ,mem_vec_2407 ,mem_vec_2408 ,mem_vec_2409 ,mem_vec_2410 ,mem_vec_2411 ,mem_vec_2412 ,mem_vec_2413 ,mem_vec_2414 ,mem_vec_2415 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f369 = 0;
f369_p_0 = 0;
x328 = 0;
x328_p_0 = 0;
f368 = 0;
f368_p_1 = 0;
c276 = 0;
c276_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h184, hp_0 = 0;h < h184 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w132, wp_0 = 0;w < w132 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
									// T (x, 34) (34 / 1)
									for (x = x328, xp_1 = x328_p_0, xp_0 = 0;x < x328 + 34;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2392 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2393 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2394 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2395 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2396 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2397 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2398 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2399 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2400 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_2401 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_2402 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_2403 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_2404 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_2405 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_2406 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_2407 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_2408 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_2409 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_2410 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_2411 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_2412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_2413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_2414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_2415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 8;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2392);
													mem_vec_2392 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2393);
													mem_vec_2393 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2394);
													mem_vec_2394 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2395);
													mem_vec_2395 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2396);
													mem_vec_2396 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2397);
													mem_vec_2397 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2398);
													mem_vec_2398 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2399);
													mem_vec_2399 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2400);
													mem_vec_2400 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2401);
													mem_vec_2401 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2402);
													mem_vec_2402 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2403);
													mem_vec_2403 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2404);
													mem_vec_2404 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2405);
													mem_vec_2405 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2406);
													mem_vec_2406 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2407);
													mem_vec_2407 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2408);
													mem_vec_2408 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2409);
													mem_vec_2409 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2410);
													mem_vec_2410 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2411);
													mem_vec_2411 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2412);
													mem_vec_2412 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2413);
													mem_vec_2413 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2414);
													mem_vec_2414 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2415);
													mem_vec_2415 = vec_37;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2392);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2393);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2394);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2395);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2396);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2397);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2398);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2399);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2400);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2401);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2402);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2403);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2404);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2405);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2406);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2407);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_2408);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_2409);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_2410);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_2411);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_2412);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_2413);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_2414);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_2415);
									}
								}
							}
}
