
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (2, c); T (4, x); T (1, x)]
*/
IND_TYPE c, cp_0, c912_p_0, cp_1, c912, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1520_p_0, x1521_p_0, x1522_p_0, xp_1, x1520_p_1, x1521_p_1, xp_2, x1520_p_2, xp_3, x1520, x1521, x1522, y, yp_0;
IND_TYPE y608 = 0;
IND_TYPE x1523 = 0;
IND_TYPE h608 = 0;
IND_TYPE w468 = 0;
IND_TYPE c913 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,mem_vec_5401 ,mem_vec_5402 ,mem_vec_5403 ,mem_vec_5404 ,mem_vec_5405 ,mem_vec_5406 ,mem_vec_5407 ,mem_vec_5408 ,mem_vec_5409 ,mem_vec_5410 ,mem_vec_5411 ,mem_vec_5412 ,mem_vec_5413 ,mem_vec_5414 ,mem_vec_5415 ,mem_vec_5416 ,mem_vec_5417 ,mem_vec_5418 ,mem_vec_5419 ,mem_vec_5420 ,mem_vec_5421 ,mem_vec_5422 ,mem_vec_5423 ,mem_vec_5424 ,mem_vec_5425 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
x1522 = 0;
x1522_p_0 = 0;
x1521 = 0;
x1521_p_1 = 0;
c912 = 0;
c912_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1520 = 0;
x1520_p_2 = 0;
							for (h = h608, hp_0 = 0;h < h608 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w468, wp_0 = 0;w < w468 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 16, f = 32
									// T (x, 68) (68 / 1)
									for (x = x1520, xp_3 = x1520_p_2, xp_2 = x1520_p_1, xp_1 = x1520_p_0, xp_0 = 0;x < x1520 + 68;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5368 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_5369 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_5370 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_5371 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_5372 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_5373 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_5374 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_5375 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_5376 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_5377 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_5378 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_5379 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_5380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_5381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_5382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_5383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_5384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_5385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_5386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_5387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_5388 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_5389 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_5390 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_5391 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_5392 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_5393 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_5394 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_5395 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c912, cp_1 = c912_p_0, cp_0 = 0;c < c912 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5368);
													mem_vec_5368 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5369);
													mem_vec_5369 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5370);
													mem_vec_5370 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5371);
													mem_vec_5371 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5372);
													mem_vec_5372 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5373);
													mem_vec_5373 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5374);
													mem_vec_5374 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5375);
													mem_vec_5375 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5376);
													mem_vec_5376 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5377);
													mem_vec_5377 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5378);
													mem_vec_5378 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5379);
													mem_vec_5379 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5380);
													mem_vec_5380 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5381);
													mem_vec_5381 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5382);
													mem_vec_5382 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5383);
													mem_vec_5383 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5384);
													mem_vec_5384 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5385);
													mem_vec_5385 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5386);
													mem_vec_5386 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5387);
													mem_vec_5387 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5388);
													mem_vec_5388 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5389);
													mem_vec_5389 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5390);
													mem_vec_5390 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5391);
													mem_vec_5391 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5392);
													mem_vec_5392 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5393);
													mem_vec_5393 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5394);
													mem_vec_5394 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5395);
													mem_vec_5395 = vec_43;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5368);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5369);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5370);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5371);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5372);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5373);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5374);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5375);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5376);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5377);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5378);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5379);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5380);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5381);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5382);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5383);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5384);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5385);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5386);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5387);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_5388);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_5389);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_5390);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_5391);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_5392);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_5393);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_5394);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_5395);
									}
								}
							}
}
