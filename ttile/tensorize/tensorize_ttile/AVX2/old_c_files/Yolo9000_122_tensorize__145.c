void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (8, c); T (16, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c226_p_0, cp_1, c226, f, fp_0, f187_p_0, f188_p_0, fp_1, f187_p_1, fp_2, f187, f188, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y137_p_0, yp_1, y137;
IND_TYPE y138 = 0;
IND_TYPE x118 = 0;
IND_TYPE h92 = 0;
IND_TYPE w104 = 0;
IND_TYPE c227 = 0;
IND_TYPE f189 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2512 ,mem_vec_2513 ,mem_vec_2514 ,mem_vec_2515 ,mem_vec_2516 ,mem_vec_2517 ,mem_vec_2518 ,mem_vec_2519 ,mem_vec_2520 ,mem_vec_2521 ,mem_vec_2522 ,mem_vec_2523 ,mem_vec_2524 ,mem_vec_2525 ,mem_vec_2526 ,mem_vec_2527 ,mem_vec_2528 ,mem_vec_2529 ,mem_vec_2530 ,mem_vec_2531 ,mem_vec_2532 ,mem_vec_2533 ,mem_vec_2534 ,mem_vec_2535 ,mem_vec_2536 ,mem_vec_2537 ,mem_vec_2538 ,mem_vec_2539 ,mem_vec_2540 ,mem_vec_2541 ,mem_vec_2542 ,mem_vec_2543 ,mem_vec_2544 ,mem_vec_2545 ,mem_vec_2546 ,mem_vec_2547 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f188 = 0;
f188_p_0 = 0;
y137 = 0;
y137_p_0 = 0;
f187 = 0;
f187_p_1 = 0;
c226 = 0;
c226_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
								for (h = h92, hp_0 = 0;h < h92 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w104, wp_0 = 0;w < w104 + 3;w += 1, wp_0 += 1){
												mem_vec_2528 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2529 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_2530 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2531 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_2532 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2533 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_2534 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2535 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_2536 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2537 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_2538 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2539 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_2540 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2541 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_2542 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2543 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_2544 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_2545 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_2546 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_2547 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c226, cp_1 = c226_p_0, cp_0 = 0;c < c226 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2528);
													mem_vec_2528 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2529);
													mem_vec_2529 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2530);
													mem_vec_2530 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2531);
													mem_vec_2531 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2532);
													mem_vec_2532 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2533);
													mem_vec_2533 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2534);
													mem_vec_2534 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2535);
													mem_vec_2535 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2536);
													mem_vec_2536 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2537);
													mem_vec_2537 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2538);
													mem_vec_2538 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2539);
													mem_vec_2539 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2540);
													mem_vec_2540 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2541);
													mem_vec_2541 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2542);
													mem_vec_2542 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2543);
													mem_vec_2543 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2544);
													mem_vec_2544 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2545);
													mem_vec_2545 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2546);
													mem_vec_2546 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2547);
													mem_vec_2547 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2528);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2529);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2530);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2531);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2532);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2533);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2534);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2535);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2536);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2537);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2538);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2539);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2540);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2541);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2542);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2543);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2544);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_2545);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2546);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_2547);
									}
								}
}
