
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (4, f);
  T (64, c); T (136, x)]
*/
IND_TYPE c, cp_0, c786_p_0, cp_1, c786, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1048_p_0, x1049_p_0, xp_1, x1048_p_1, xp_2, x1048, x1049, y, yp_0;
IND_TYPE y524 = 0;
IND_TYPE x1050 = 0;
IND_TYPE h524 = 0;
IND_TYPE w494 = 0;
IND_TYPE c787 = 0;
IND_TYPE f524 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10512 ,mem_vec_10513 ,mem_vec_10514 ,mem_vec_10515 ,mem_vec_10516 ,mem_vec_10517 ,mem_vec_10518 ,mem_vec_10519 ,mem_vec_10520 ,mem_vec_10521 ,mem_vec_10522 ,mem_vec_10523 ,mem_vec_10524 ,mem_vec_10525 ,mem_vec_10526 ,mem_vec_10527 ,mem_vec_10528 ,mem_vec_10529 ,mem_vec_10530 ,mem_vec_10531 ,mem_vec_10532 ,mem_vec_10533 ,mem_vec_10534 ,mem_vec_10535 ,mem_vec_10536 ,mem_vec_10537 ,mem_vec_10538 ,mem_vec_10539 ,mem_vec_10540 ,mem_vec_10541 ,mem_vec_10542 ,mem_vec_10543 ,mem_vec_10544 ,mem_vec_10545 ,mem_vec_10546 ,mem_vec_10547 ,mem_vec_10548 ,mem_vec_10549 ,mem_vec_10550 ,mem_vec_10551 ,mem_vec_10552 ,mem_vec_10553 ,mem_vec_10554 ,mem_vec_10555 ,mem_vec_10556 ,mem_vec_10557 ,mem_vec_10558 ,mem_vec_10559 ,mem_vec_10560 ,mem_vec_10561 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 136) (136 / 1)
x1049 = 0;
x1049_p_0 = 0;
c786 = 0;
c786_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1048 = 0;
x1048_p_1 = 0;
						for (h = h524, hp_0 = 0;h < h524 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w494, wp_0 = 0;w < w494 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;x < x1048 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10512 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_10513 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_10514 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_10515 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_10516 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_10517 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_10518 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_10519 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_10520 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_10521 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_10522 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_10523 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_10524 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_10525 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_10526 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_10527 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_10528 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_10529 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_10530 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_10531 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_10532 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_10533 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_10534 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_10535 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c786, cp_1 = c786_p_0, cp_0 = 0;c < c786 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10512);
												mem_vec_10512 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10513);
												mem_vec_10513 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10514);
												mem_vec_10514 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10515);
												mem_vec_10515 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10516);
												mem_vec_10516 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10517);
												mem_vec_10517 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10518);
												mem_vec_10518 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10519);
												mem_vec_10519 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10520);
												mem_vec_10520 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10521);
												mem_vec_10521 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10522);
												mem_vec_10522 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10523);
												mem_vec_10523 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10524);
												mem_vec_10524 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10525);
												mem_vec_10525 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10526);
												mem_vec_10526 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10527);
												mem_vec_10527 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10528);
												mem_vec_10528 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10529);
												mem_vec_10529 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10530);
												mem_vec_10530 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10531);
												mem_vec_10531 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10532);
												mem_vec_10532 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10533);
												mem_vec_10533 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10534);
												mem_vec_10534 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10535);
												mem_vec_10535 = vec_37;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10512);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10513);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10514);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10515);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10516);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10517);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10518);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10519);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_10520);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_10521);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_10522);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_10523);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_10524);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_10525);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_10526);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_10527);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_10528);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_10529);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_10530);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_10531);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_10532);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_10533);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_10534);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_10535);
								}
							}
						}
}
