
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, y); T (2, f); T (2, c); T (1, f); T (128, c); T (28, x);
  T (2, f)]
*/
IND_TYPE c, cp_0, c352_p_0, c353_p_0, cp_1, c352_p_1, cp_2, c352, c353, f, fp_0, f340_p_0, f341_p_0, fp_1, f340_p_1, fp_2, f340, f341, h, hp_0, w, wp_0, x, xp_0, x264_p_0, xp_1, x264, y, yp_0;
IND_TYPE y176 = 0;
IND_TYPE x265 = 0;
IND_TYPE h176 = 0;
IND_TYPE w176 = 0;
IND_TYPE c354 = 0;
IND_TYPE f342 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2464 ,mem_vec_2465 ,mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,mem_vec_2490 ,mem_vec_2491 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
f341 = 0;
f341_p_0 = 0;
x264 = 0;
x264_p_0 = 0;
c353 = 0;
c353_p_0 = 0;
f340 = 0;
f340_p_1 = 0;
c352 = 0;
c352_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h176, hp_0 = 0;h < h176 + 3;h += 1, hp_0 += 1){
								// y = 7, x = 1, h = 1, w = 3, c = 1, f = 64
								// T (w, 3) (3 / 1)
								for (w = w176, wp_0 = 0;w < w176 + 3;w += 1, wp_0 += 1){
									// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (x, 1) (1 / 1)
									for (x = x264, xp_1 = x264_p_0, xp_0 = 0;x < x264 + 1;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2464 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2465 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2466 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_2467 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_2468 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2469 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2470 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_2471 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_2472 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2473 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2474 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_2475 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_2476 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2477 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2478 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_2479 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_2480 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_2481 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_2482 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_2483 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_2484 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_2485 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_2486 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_2487 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												mem_vec_2488 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_2489 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_2490 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
												mem_vec_2491 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
												// T (c, 1) (1 / 1)
												for (c = c352, cp_2 = c352_p_1, cp_1 = c352_p_0, cp_0 = 0;c < c352 + 1;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2464);
													mem_vec_2464 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2465);
													mem_vec_2465 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2466);
													mem_vec_2466 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2467);
													mem_vec_2467 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2468);
													mem_vec_2468 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2469);
													mem_vec_2469 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2470);
													mem_vec_2470 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2471);
													mem_vec_2471 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2472);
													mem_vec_2472 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2473);
													mem_vec_2473 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2474);
													mem_vec_2474 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2475);
													mem_vec_2475 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2476);
													mem_vec_2476 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2477);
													mem_vec_2477 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2478);
													mem_vec_2478 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2479);
													mem_vec_2479 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2480);
													mem_vec_2480 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2481);
													mem_vec_2481 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2482);
													mem_vec_2482 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2483);
													mem_vec_2483 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2484);
													mem_vec_2484 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2485);
													mem_vec_2485 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2486);
													mem_vec_2486 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2487);
													mem_vec_2487 = vec_33;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2488);
													mem_vec_2488 = vec_34;
													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2489);
													mem_vec_2489 = vec_36;
													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2490);
													mem_vec_2490 = vec_37;
													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2491);
													mem_vec_2491 = vec_38;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2464);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2465);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2466);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2467);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2468);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2469);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2470);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2471);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2472);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2473);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2474);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2475);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2476);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2477);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2478);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2479);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2480);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2481);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_2482);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_2483);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2484);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2485);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_2486);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_2487);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2488);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2489);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_2490);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_2491);
									}
								}
							}
}
