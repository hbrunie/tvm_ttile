
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (2, f);
  T (8, c); T (56, x)]
*/
IND_TYPE c, cp_0, c596_p_0, cp_1, c596, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x650_p_0, x651_p_0, xp_1, x650_p_1, xp_2, x650, x651, y, yp_0;
IND_TYPE y356 = 0;
IND_TYPE x652 = 0;
IND_TYPE h320 = 0;
IND_TYPE w332 = 0;
IND_TYPE c597 = 0;
IND_TYPE f294 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5488 ,mem_vec_5489 ,mem_vec_5490 ,mem_vec_5491 ,mem_vec_5492 ,mem_vec_5493 ,mem_vec_5494 ,mem_vec_5495 ,mem_vec_5496 ,mem_vec_5497 ,mem_vec_5498 ,mem_vec_5499 ,mem_vec_5500 ,mem_vec_5501 ,mem_vec_5502 ,mem_vec_5503 ,mem_vec_5504 ,mem_vec_5505 ,mem_vec_5506 ,mem_vec_5507 ,mem_vec_5508 ,mem_vec_5509 ,mem_vec_5510 ,mem_vec_5511 ,mem_vec_5512 ,mem_vec_5513 ,mem_vec_5514 ,mem_vec_5515 ,mem_vec_5516 ,mem_vec_5517 ,mem_vec_5518 ,mem_vec_5519 ,mem_vec_5520 ,mem_vec_5521 ,mem_vec_5522 ,mem_vec_5523 ,mem_vec_5524 ,mem_vec_5525 ,mem_vec_5526 ,mem_vec_5527 ,mem_vec_5528 ,mem_vec_5529 ,mem_vec_5530 ,mem_vec_5531 ,mem_vec_5532 ,mem_vec_5533 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 56) (56 / 1)
x651 = 0;
x651_p_0 = 0;
c596 = 0;
c596_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x650 = 0;
x650_p_1 = 0;
						for (h = h320, hp_0 = 0;h < h320 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w332, wp_0 = 0;w < w332 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x650, xp_2 = x650_p_1, xp_1 = x650_p_0, xp_0 = 0;x < x650 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5488 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5489 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5490 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5491 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5492 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5493 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5494 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5495 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5496 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5497 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5498 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5499 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5500 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5501 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_5502 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5503 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_5504 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5505 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_5506 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_5507 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c596, cp_1 = c596_p_0, cp_0 = 0;c < c596 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5488);
												mem_vec_5488 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5489);
												mem_vec_5489 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5490);
												mem_vec_5490 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5491);
												mem_vec_5491 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5492);
												mem_vec_5492 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5493);
												mem_vec_5493 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5494);
												mem_vec_5494 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5495);
												mem_vec_5495 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5496);
												mem_vec_5496 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5497);
												mem_vec_5497 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5498);
												mem_vec_5498 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5499);
												mem_vec_5499 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5500);
												mem_vec_5500 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5501);
												mem_vec_5501 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5502);
												mem_vec_5502 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5503);
												mem_vec_5503 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5504);
												mem_vec_5504 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5505);
												mem_vec_5505 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5506);
												mem_vec_5506 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5507);
												mem_vec_5507 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5488);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5489);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5490);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5491);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5492);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5493);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5494);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5495);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5496);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5497);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5498);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5499);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5500);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5501);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5502);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5503);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5504);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5505);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5506);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5507);
								}
							}
						}
}
