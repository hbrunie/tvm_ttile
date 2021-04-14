
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (16, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (16, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c696_p_0, cp_1, c696, h, hp_0, w, wp_0, x, xp_0, x928_p_0, x929_p_0, xp_1, x928_p_1, xp_2, x928, x929, y, yp_0;
IND_TYPE y464 = 0;
IND_TYPE x930 = 0;
IND_TYPE h444 = 0;
IND_TYPE w464 = 0;
IND_TYPE c697 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8612 ,mem_vec_8613 ,mem_vec_8614 ,mem_vec_8615 ,mem_vec_8616 ,mem_vec_8617 ,mem_vec_8618 ,mem_vec_8619 ,mem_vec_8620 ,mem_vec_8621 ,mem_vec_8622 ,mem_vec_8623 ,mem_vec_8624 ,mem_vec_8625 ,mem_vec_8626 ,mem_vec_8627 ,mem_vec_8628 ,mem_vec_8629 ,mem_vec_8630 ,mem_vec_8631 ,mem_vec_8632 ,mem_vec_8633 ,mem_vec_8634 ,mem_vec_8635 ,mem_vec_8636 ,mem_vec_8637 ,mem_vec_8638 ,mem_vec_8639 ,mem_vec_8640 ,mem_vec_8641 ,mem_vec_8642 ,mem_vec_8643 ,mem_vec_8644 ,mem_vec_8645 ,mem_vec_8646 ,mem_vec_8647 ,mem_vec_8648 ,mem_vec_8649 ,mem_vec_8650 ,mem_vec_8651 ,mem_vec_8652 ,mem_vec_8653 ,mem_vec_8654 ,mem_vec_8655 ,mem_vec_8656 ,mem_vec_8657 ,mem_vec_8658 ,mem_vec_8659 ,mem_vec_8660 ,mem_vec_8661 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
x929 = 0;
x929_p_0 = 0;
c696 = 0;
c696_p_0 = 0;
y = 0;
yp_0 = 0;
x928 = 0;
x928_p_1 = 0;
					for (h = h444, hp_0 = 0;h < h444 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w464, wp_0 = 0;w < w464 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 1, c = 2, f = 32
							// T (x, 7) (7 / 1)
							for (x = x928, xp_2 = x928_p_1, xp_1 = x928_p_0, xp_0 = 0;x < x928 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_8614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_8616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_8617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_8618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_8619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_8620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_8621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_8622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_8623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_8624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_8625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_8626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_8627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_8628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_8629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_8630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_8631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_8632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_8633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_8634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_8635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c696, cp_1 = c696_p_0, cp_0 = 0;c < c696 + 2;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8612);
											mem_vec_8612 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8613);
											mem_vec_8613 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8614);
											mem_vec_8614 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8615);
											mem_vec_8615 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8616);
											mem_vec_8616 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8617);
											mem_vec_8617 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8618);
											mem_vec_8618 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8619);
											mem_vec_8619 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8620);
											mem_vec_8620 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8621);
											mem_vec_8621 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8622);
											mem_vec_8622 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8623);
											mem_vec_8623 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8624);
											mem_vec_8624 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8625);
											mem_vec_8625 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8626);
											mem_vec_8626 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8627);
											mem_vec_8627 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8628);
											mem_vec_8628 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8629);
											mem_vec_8629 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8630);
											mem_vec_8630 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8631);
											mem_vec_8631 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8632);
											mem_vec_8632 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8633);
											mem_vec_8633 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8634);
											mem_vec_8634 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8635);
											mem_vec_8635 = vec_37;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8612);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8613);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8614);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8615);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8616);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8617);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8618);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8619);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8620);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8621);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8622);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8623);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8624);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8625);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8626);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8627);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8628);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8629);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8630);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8631);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8632);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8633);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8634);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8635);
							}
						}
					}
}
