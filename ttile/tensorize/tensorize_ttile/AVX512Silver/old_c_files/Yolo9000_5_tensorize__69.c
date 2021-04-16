
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (2, f);
  T (136, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x255_p_0, xp_1, x255, y, yp_0, y255_p_0, yp_1, y255;
IND_TYPE y256 = 0;
IND_TYPE x256 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c192 = 0;
IND_TYPE f148 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3550 ,mem_vec_3551 ,mem_vec_3552 ,mem_vec_3553 ,mem_vec_3554 ,mem_vec_3555 ,mem_vec_3556 ,mem_vec_3557 ,mem_vec_3558 ,mem_vec_3559 ,mem_vec_3560 ,mem_vec_3561 ,mem_vec_3562 ,mem_vec_3563 ,mem_vec_3564 ,mem_vec_3565 ,mem_vec_3566 ,mem_vec_3567 ,mem_vec_3568 ,mem_vec_3569 ,mem_vec_3570 ,mem_vec_3571 ,mem_vec_3572 ,mem_vec_3573 ,mem_vec_3574 ,mem_vec_3575 ,mem_vec_3576 ,mem_vec_3577 ,mem_vec_3578 ,mem_vec_3579 ,mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,mem_vec_3596 ,mem_vec_3597 ,mem_vec_3598 ,mem_vec_3599 ,mem_vec_3600 ,mem_vec_3601 ,mem_vec_3602 ,mem_vec_3603 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
y255 = 0;
y255_p_0 = 0;
x255 = 0;
x255_p_0 = 0;
		for (f = f148, fp_0 = 0;f < f148 + 64;f += 32, fp_0 += 32){
				for (y = y255, yp_1 = y255_p_0, yp_0 = 0;y < y255 + 26;y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x255, xp_1 = x255_p_0, xp_0 = 0;x < x255 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_3551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_3552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_3553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_3554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_3555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_3556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_3557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_3558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_3559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_3560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_3561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_3562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_3563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_3564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_3565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_3566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_3567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_3568 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_3569 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								mem_vec_3570 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
								mem_vec_3571 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
								mem_vec_3572 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
								mem_vec_3573 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
								mem_vec_3574 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
								mem_vec_3575 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c192, cp_0 = 0;c < c192 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3550);
									mem_vec_3550 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3551);
									mem_vec_3551 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3552);
									mem_vec_3552 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3553);
									mem_vec_3553 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3554);
									mem_vec_3554 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3555);
									mem_vec_3555 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3556);
									mem_vec_3556 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3557);
									mem_vec_3557 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3558);
									mem_vec_3558 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3559);
									mem_vec_3559 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3560);
									mem_vec_3560 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3561);
									mem_vec_3561 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3562);
									mem_vec_3562 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3563);
									mem_vec_3563 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3564);
									mem_vec_3564 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3565);
									mem_vec_3565 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3566);
									mem_vec_3566 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3567);
									mem_vec_3567 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3568);
									mem_vec_3568 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3569);
									mem_vec_3569 = vec_31;
									scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3570);
									mem_vec_3570 = vec_32;
									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3571);
									mem_vec_3571 = vec_34;
									scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3572);
									mem_vec_3572 = vec_35;
									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3573);
									mem_vec_3573 = vec_37;
									scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);
									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3574);
									mem_vec_3574 = vec_38;
									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3575);
									mem_vec_3575 = vec_40;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3550);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3551);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3552);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3553);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3554);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3555);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3556);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3557);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3558);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3559);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3560);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3561);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3562);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3563);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3564);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3565);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3566);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3567);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3568);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3569);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3570);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3571);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_3572);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_3573);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_3574);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_3575);
					}
				}
				for (y = y255 + 26, yp_1 = y255_p_0, yp_0 = 0;y < y255 + 26 + 42;y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x255, xp_1 = x255_p_0, xp_0 = 0;x < x255 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3576 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_3577 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_3578 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_3579 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_3580 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_3581 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_3582 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_3583 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_3584 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_3585 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_3586 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_3587 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_3588 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_3589 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_3590 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_3591 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_3592 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_3593 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_3594 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_3595 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								mem_vec_3596 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
								mem_vec_3597 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
								mem_vec_3598 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
								mem_vec_3599 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
								mem_vec_3600 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
								mem_vec_3601 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
								mem_vec_3602 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
								mem_vec_3603 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c192, cp_0 = 0;c < c192 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3576);
									mem_vec_3576 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3577);
									mem_vec_3577 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3578);
									mem_vec_3578 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3579);
									mem_vec_3579 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3580);
									mem_vec_3580 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3581);
									mem_vec_3581 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3582);
									mem_vec_3582 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3583);
									mem_vec_3583 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3584);
									mem_vec_3584 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3585);
									mem_vec_3585 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3586);
									mem_vec_3586 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3587);
									mem_vec_3587 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3588);
									mem_vec_3588 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3589);
									mem_vec_3589 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3590);
									mem_vec_3590 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3591);
									mem_vec_3591 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3592);
									mem_vec_3592 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3593);
									mem_vec_3593 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3594);
									mem_vec_3594 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3595);
									mem_vec_3595 = vec_31;
									scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3596);
									mem_vec_3596 = vec_32;
									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3597);
									mem_vec_3597 = vec_34;
									scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3598);
									mem_vec_3598 = vec_35;
									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3599);
									mem_vec_3599 = vec_37;
									scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);
									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3600);
									mem_vec_3600 = vec_38;
									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3601);
									mem_vec_3601 = vec_40;
									scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);
									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3602);
									mem_vec_3602 = vec_41;
									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3603);
									mem_vec_3603 = vec_43;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3576);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3577);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3578);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3579);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3580);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3581);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3582);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3583);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3584);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3585);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3586);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3587);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3588);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3589);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3590);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3591);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3592);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3593);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3594);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3595);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3596);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3597);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_3598);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_3599);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_3600);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_3601);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_3602);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_3603);
					}
				}
		}
}
