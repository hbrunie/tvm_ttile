
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x39_p_0, xp_1, x39, y, yp_0, y39_p_0, yp_1, y39;
IND_TYPE y40 = 0;
IND_TYPE x40 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c26 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
y39 = 0;
y39_p_0 = 0;
x39 = 0;
x39_p_0 = 0;
		for (f = f26, fp_0 = 0;f < f26 + 64;f += 32, fp_0 += 32){
				for (y = y39, yp_1 = y39_p_0, yp_0 = 0;y < y39 + 8;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x39, xp_1 = x39_p_0, xp_0 = 0;x < x39 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_528 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_529 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_530 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_531 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_532 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_533 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_534 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_535 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_536 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_537 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_538 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_539 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_540 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_541 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_542 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_543 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c26, cp_0 = 0;c < c26 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_528);
									mem_vec_528 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_529);
									mem_vec_529 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_530);
									mem_vec_530 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_531);
									mem_vec_531 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_532);
									mem_vec_532 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_533);
									mem_vec_533 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_534);
									mem_vec_534 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_535);
									mem_vec_535 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_536);
									mem_vec_536 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_537);
									mem_vec_537 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_538);
									mem_vec_538 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_539);
									mem_vec_539 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_540);
									mem_vec_540 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_541);
									mem_vec_541 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_542);
									mem_vec_542 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_543);
									mem_vec_543 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_528);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_529);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_530);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_531);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_532);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_533);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_534);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_535);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_536);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_537);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_538);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_539);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_540);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_541);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_542);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_543);
					}
				}
				for (y = y39 + 8, yp_1 = y39_p_0, yp_0 = 0;y < y39 + 8 + 60;y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x39, xp_1 = x39_p_0, xp_0 = 0;x < x39 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								mem_vec_564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
								mem_vec_565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
								mem_vec_566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
								mem_vec_567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c26, cp_0 = 0;c < c26 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_544);
									mem_vec_544 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_545);
									mem_vec_545 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_546);
									mem_vec_546 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_547);
									mem_vec_547 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_548);
									mem_vec_548 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_549);
									mem_vec_549 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_550);
									mem_vec_550 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_551);
									mem_vec_551 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_552);
									mem_vec_552 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_553);
									mem_vec_553 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_554);
									mem_vec_554 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_555);
									mem_vec_555 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_556);
									mem_vec_556 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_557);
									mem_vec_557 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_558);
									mem_vec_558 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_559);
									mem_vec_559 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_560);
									mem_vec_560 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_561);
									mem_vec_561 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_562);
									mem_vec_562 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_563);
									mem_vec_563 = vec_31;
									scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_564);
									mem_vec_564 = vec_32;
									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_565);
									mem_vec_565 = vec_34;
									scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_566);
									mem_vec_566 = vec_35;
									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_567);
									mem_vec_567 = vec_37;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_544);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_545);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_546);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_547);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_548);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_549);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_550);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_551);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_552);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_553);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_554);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_555);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_556);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_557);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_558);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_559);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_560);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_561);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_562);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_563);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_564);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_565);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_566);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_567);
					}
				}
		}
}
