
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (17, x); T (1, y); T (8, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c393_p_0, cp_1, c393, f, fp_0, x, xp_0, x524_p_0, x525_p_0, xp_1, x524_p_1, xp_2, x524, x525, y, yp_0, y385_p_0, yp_1, y385;
IND_TYPE y386 = 0;
IND_TYPE x526 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c394 = 0;
IND_TYPE f262 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5530 ,mem_vec_5531 ,mem_vec_5532 ,mem_vec_5533 ,mem_vec_5534 ,mem_vec_5535 ,mem_vec_5536 ,mem_vec_5537 ,mem_vec_5538 ,mem_vec_5539 ,mem_vec_5540 ,mem_vec_5541 ,mem_vec_5542 ,mem_vec_5543 ,mem_vec_5544 ,mem_vec_5545 ,mem_vec_5546 ,mem_vec_5547 ,mem_vec_5548 ,mem_vec_5549 ,mem_vec_5550 ,mem_vec_5551 ,mem_vec_5552 ,mem_vec_5553 ,mem_vec_5554 ,mem_vec_5555 ,mem_vec_5556 ,mem_vec_5557 ,mem_vec_5558 ,mem_vec_5559 ,mem_vec_5560 ,mem_vec_5561 ,mem_vec_5562 ,mem_vec_5563 ,mem_vec_5564 ,mem_vec_5565 ,mem_vec_5566 ,mem_vec_5567 ,mem_vec_5568 ,mem_vec_5569 ,mem_vec_5570 ,mem_vec_5571 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y385 = 0;
y385_p_0 = 0;
x525 = 0;
x525_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
x524 = 0;
x524_p_1 = 0;
c393 = 0;
c393_p_0 = 0;
							for (x = x524, xp_2 = x524_p_1, xp_1 = x524_p_0, xp_0 = 0;x < x524 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5530 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5531 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5532 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5533 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5534 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5535 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5536 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5537 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5538 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5539 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5540 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5541 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5542 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5543 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_5544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c393, cp_1 = c393_p_0, cp_0 = 0;c < c393 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5530);
											mem_vec_5530 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5531);
											mem_vec_5531 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5532);
											mem_vec_5532 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5533);
											mem_vec_5533 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5534);
											mem_vec_5534 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5535);
											mem_vec_5535 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5536);
											mem_vec_5536 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5537);
											mem_vec_5537 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5538);
											mem_vec_5538 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5539);
											mem_vec_5539 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5540);
											mem_vec_5540 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5541);
											mem_vec_5541 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5542);
											mem_vec_5542 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5543);
											mem_vec_5543 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5544);
											mem_vec_5544 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5545);
											mem_vec_5545 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5530);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5531);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5532);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5533);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5534);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5535);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5536);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5537);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5538);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5539);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5540);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5541);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5542);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5543);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5544);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5545);
							}
}
