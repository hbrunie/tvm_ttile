
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (14, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (1, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c630_p_0, cp_1, c630, h, hp_0, w, wp_0, x, xp_0, x840_p_0, x841_p_0, xp_1, x840_p_1, xp_2, x840, x841, y, yp_0;
IND_TYPE y420 = 0;
IND_TYPE x842 = 0;
IND_TYPE h400 = 0;
IND_TYPE w420 = 0;
IND_TYPE c631 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7540 ,mem_vec_7541 ,mem_vec_7542 ,mem_vec_7543 ,mem_vec_7544 ,mem_vec_7545 ,mem_vec_7546 ,mem_vec_7547 ,mem_vec_7548 ,mem_vec_7549 ,mem_vec_7550 ,mem_vec_7551 ,mem_vec_7552 ,mem_vec_7553 ,mem_vec_7554 ,mem_vec_7555 ,mem_vec_7556 ,mem_vec_7557 ,mem_vec_7558 ,mem_vec_7559 ,mem_vec_7560 ,mem_vec_7561 ,mem_vec_7562 ,mem_vec_7563 ,mem_vec_7564 ,mem_vec_7565 ,mem_vec_7566 ,mem_vec_7567 ,mem_vec_7568 ,mem_vec_7569 ,mem_vec_7570 ,mem_vec_7571 ,mem_vec_7572 ,mem_vec_7573 ,mem_vec_7574 ,mem_vec_7575 ,mem_vec_7576 ,mem_vec_7577 ,mem_vec_7578 ,mem_vec_7579 ,mem_vec_7580 ,mem_vec_7581 ,mem_vec_7582 ,mem_vec_7583 ,mem_vec_7584 ,mem_vec_7585 ,mem_vec_7586 ,mem_vec_7587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
x841 = 0;
x841_p_0 = 0;
c630 = 0;
c630_p_0 = 0;
y = 0;
yp_0 = 0;
x840 = 0;
x840_p_1 = 0;
					for (h = h400, hp_0 = 0;h < h400 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w420, wp_0 = 0;w < w420 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
							// T (x, 2) (2 / 1)
							for (x = x840, xp_2 = x840_p_1, xp_1 = x840_p_0, xp_0 = 0;x < x840 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7540 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7541 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_7542 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7543 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_7544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_7546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_7548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_7550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_7551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_7552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_7553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_7554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_7555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_7556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_7557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_7558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_7559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_7560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_7561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c630, cp_1 = c630_p_0, cp_0 = 0;c < c630 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7540);
											mem_vec_7540 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7541);
											mem_vec_7541 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7542);
											mem_vec_7542 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7543);
											mem_vec_7543 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7544);
											mem_vec_7544 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7545);
											mem_vec_7545 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7546);
											mem_vec_7546 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7547);
											mem_vec_7547 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7548);
											mem_vec_7548 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7549);
											mem_vec_7549 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7550);
											mem_vec_7550 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7551);
											mem_vec_7551 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7552);
											mem_vec_7552 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7553);
											mem_vec_7553 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7554);
											mem_vec_7554 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7555);
											mem_vec_7555 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7556);
											mem_vec_7556 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7557);
											mem_vec_7557 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7558);
											mem_vec_7558 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7559);
											mem_vec_7559 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7560);
											mem_vec_7560 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7561);
											mem_vec_7561 = vec_34;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7540);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7541);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7542);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7543);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7544);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7545);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7546);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7547);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7548);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7549);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7550);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7551);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7552);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7553);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7554);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7555);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_7556);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_7557);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_7558);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_7559);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_7560);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_7561);
							}
						}
					}
}
