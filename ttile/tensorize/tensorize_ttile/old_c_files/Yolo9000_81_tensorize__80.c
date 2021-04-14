
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))];
  T (4, f); T (64, c); T (2, f); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, f936_p_0, f937_p_0, fp_1, f936_p_1, fp_2, f936, f937, h, hp_0, w, wp_0, x, xp_0, x754_p_0, xp_1, x754, y, yp_0;
IND_TYPE y468 = 0;
IND_TYPE x755 = 0;
IND_TYPE h468 = 0;
IND_TYPE w416 = 0;
IND_TYPE c703 = 0;
IND_TYPE f938 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8372 ,mem_vec_8373 ,mem_vec_8374 ,mem_vec_8375 ,mem_vec_8376 ,mem_vec_8377 ,mem_vec_8378 ,mem_vec_8379 ,mem_vec_8380 ,mem_vec_8381 ,mem_vec_8382 ,mem_vec_8383 ,mem_vec_8384 ,mem_vec_8385 ,mem_vec_8386 ,mem_vec_8387 ,mem_vec_8388 ,mem_vec_8389 ,mem_vec_8390 ,mem_vec_8391 ,mem_vec_8392 ,mem_vec_8393 ,mem_vec_8394 ,mem_vec_8395 ,mem_vec_8396 ,mem_vec_8397 ,mem_vec_8398 ,mem_vec_8399 ,mem_vec_8400 ,mem_vec_8401 ,mem_vec_8402 ,mem_vec_8403 ,mem_vec_8404 ,mem_vec_8405 ,mem_vec_8406 ,mem_vec_8407 ,mem_vec_8408 ,mem_vec_8409 ,mem_vec_8410 ,mem_vec_8411 ,mem_vec_8412 ,mem_vec_8413 ,mem_vec_8414 ,mem_vec_8415 ,mem_vec_8416 ,mem_vec_8417 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f937 = 0;
f937_p_0 = 0;
x754 = 0;
x754_p_0 = 0;
f936 = 0;
f936_p_1 = 0;
c702 = 0;
c702_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h468, hp_0 = 0;h < h468 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w416, wp_0 = 0;w < w416 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 2, f = 32
									// T (x, 68) (68 / 1)
									for (x = x754, xp_1 = x754_p_0, xp_0 = 0;x < x754 + 68;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8372 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_8373 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_8374 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_8375 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_8376 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_8377 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_8378 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_8379 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_8380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_8381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_8382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_8383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_8384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_8385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_8386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_8387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_8388 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_8389 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c702, cp_1 = c702_p_0, cp_0 = 0;c < c702 + 2;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8372);
													mem_vec_8372 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8373);
													mem_vec_8373 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8374);
													mem_vec_8374 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8375);
													mem_vec_8375 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8376);
													mem_vec_8376 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8377);
													mem_vec_8377 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8378);
													mem_vec_8378 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8379);
													mem_vec_8379 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8380);
													mem_vec_8380 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8381);
													mem_vec_8381 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8382);
													mem_vec_8382 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8383);
													mem_vec_8383 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8384);
													mem_vec_8384 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8385);
													mem_vec_8385 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8386);
													mem_vec_8386 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8387);
													mem_vec_8387 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8388);
													mem_vec_8388 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8389);
													mem_vec_8389 = vec_28;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8372);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8373);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8374);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8375);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8376);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8377);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8378);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8379);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8380);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8381);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8382);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8383);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8384);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8385);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8386);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8387);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8388);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8389);
									}
								}
							}
}
