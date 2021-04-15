
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (8, f); T (1, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 3), (Arg 8))]; T (2, f)]
*/
IND_TYPE c, cp_0, c710_p_0, cp_1, c710, f, fp_0, f694_p_0, fp_1, f694, h, hp_0, x, xp_0, x702_p_0, xp_1, x702, y, yp_0;
IND_TYPE y468 = 0;
IND_TYPE x703 = 0;
IND_TYPE h334 = 0;
IND_TYPE w = 0;
IND_TYPE c711 = 0;
IND_TYPE f695 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f694 = 0;
f694_p_0 = 0;
y = 0;
yp_0 = 0;
x702 = 0;
x702_p_0 = 0;
c710 = 0;
c710_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h334, hp_0 = 0;h < h334 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 16
							// T (x, 2) (2 / 1)
							for (x = x702, xp_1 = x702_p_0, xp_0 = 0;x < x702 + 2;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c710, cp_1 = c710_p_0, cp_0 = 0;c < c710 + 128;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5620);
											mem_vec_5620 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5621);
											mem_vec_5621 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5622);
											mem_vec_5622 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5623);
											mem_vec_5623 = vec_7;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_5620);
											mem_vec_5620 = vec_9;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_13 = _mm512_set1_ps(scal_5);
											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_5621);
											mem_vec_5621 = vec_12;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_5622);
											mem_vec_5622 = vec_14;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);
											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_5623);
											mem_vec_5623 = vec_16;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_5620);
											mem_vec_5620 = vec_18;
											scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_22 = _mm512_set1_ps(scal_9);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_5621);
											mem_vec_5621 = vec_21;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_24 = _mm512_set1_ps(scal_10);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_5622);
											mem_vec_5622 = vec_23;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_5623);
											mem_vec_5623 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5620);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5621);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5622);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5623);
							}
						}
}
