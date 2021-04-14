
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (2, f);
  T (1, c); T (14, x)]
*/
IND_TYPE c, cp_0, c528_p_0, cp_1, c528, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x672_p_0, x673_p_0, xp_1, x672_p_1, xp_2, x672, x673, y, yp_0;
IND_TYPE y352 = 0;
IND_TYPE x674 = 0;
IND_TYPE h304 = 0;
IND_TYPE w322 = 0;
IND_TYPE c529 = 0;
IND_TYPE f416 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,mem_vec_5366 ,mem_vec_5367 ,mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 14) (56 / 4)
x673 = 0;
x673_p_0 = 0;
c528 = 0;
c528_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x672 = 0;
x672_p_1 = 0;
						for (h = h304, hp_0 = 0;h < h304 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 64
							// T (w, 3) (3 / 1)
							for (w = w322, wp_0 = 0;w < w322 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
								// T (x, 4) (4 / 1)
								for (x = x672, xp_2 = x672_p_1, xp_1 = x672_p_0, xp_0 = 0;x < x672 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5332 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5333 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5334 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_5335 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_5336 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5337 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5338 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_5339 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_5340 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5341 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5342 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_5343 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_5344 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5345 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5346 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_5347 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											mem_vec_5348 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5349 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5350 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
											mem_vec_5351 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
											mem_vec_5352 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5353 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5354 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
											mem_vec_5355 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c528, cp_1 = c528_p_0, cp_0 = 0;c < c528 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5332);
												mem_vec_5332 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5333);
												mem_vec_5333 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5334);
												mem_vec_5334 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5335);
												mem_vec_5335 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5336);
												mem_vec_5336 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5337);
												mem_vec_5337 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5338);
												mem_vec_5338 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5339);
												mem_vec_5339 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5340);
												mem_vec_5340 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5341);
												mem_vec_5341 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5342);
												mem_vec_5342 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5343);
												mem_vec_5343 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5344);
												mem_vec_5344 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5345);
												mem_vec_5345 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5346);
												mem_vec_5346 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5347);
												mem_vec_5347 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5348);
												mem_vec_5348 = vec_24;
												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5349);
												mem_vec_5349 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5350);
												mem_vec_5350 = vec_27;
												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5351);
												mem_vec_5351 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5352);
												mem_vec_5352 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5353);
												mem_vec_5353 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5354);
												mem_vec_5354 = vec_32;
												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5355);
												mem_vec_5355 = vec_33;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5332);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5333);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5334);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5335);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5336);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5337);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5338);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5339);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5340);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5341);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5342);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5343);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5344);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5345);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5346);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5347);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5348);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5349);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_5350);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_5351);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5352);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5353);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_5354);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_5355);
								}
							}
						}
}
