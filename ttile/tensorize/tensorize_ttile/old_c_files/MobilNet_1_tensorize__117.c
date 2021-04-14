
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (16, x); T (8, y); T (2, c); T (7, x)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, h, hp_0, w, wp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0;
IND_TYPE y68 = 0;
IND_TYPE x138 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c103 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x137 = 0;
x137_p_0 = 0;
c102 = 0;
c102_p_0 = 0;
y = 0;
yp_0 = 0;
x136 = 0;
x136_p_1 = 0;
				for (h = h68, hp_0 = 0;h < h68 + 3;h += 1, hp_0 += 1){
					// y = 14, x = 1, h = 1, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w68, wp_0 = 0;w < w68 + 3;w += 1, wp_0 += 1){
						// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;x < x136 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_688 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_689 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_690 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_691 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_692 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_693 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_694 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_695 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									mem_vec_704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
									mem_vec_706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
									mem_vec_708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
									mem_vec_709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
									mem_vec_710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
									mem_vec_711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
									mem_vec_712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
									mem_vec_713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
									mem_vec_714 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
									mem_vec_715 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c102, cp_1 = c102_p_0, cp_0 = 0;c < c102 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_688);
										mem_vec_688 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_689);
										mem_vec_689 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_690);
										mem_vec_690 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_691);
										mem_vec_691 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_692);
										mem_vec_692 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_693);
										mem_vec_693 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_694);
										mem_vec_694 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_695);
										mem_vec_695 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_696);
										mem_vec_696 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_697);
										mem_vec_697 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_698);
										mem_vec_698 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_699);
										mem_vec_699 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_700);
										mem_vec_700 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_701);
										mem_vec_701 = vec_22;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_702);
										mem_vec_702 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_703);
										mem_vec_703 = vec_25;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_704);
										mem_vec_704 = vec_26;
										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_705);
										mem_vec_705 = vec_28;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_706);
										mem_vec_706 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_707);
										mem_vec_707 = vec_31;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);
										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_708);
										mem_vec_708 = vec_32;
										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_709);
										mem_vec_709 = vec_34;
										scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_710);
										mem_vec_710 = vec_35;
										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_711);
										mem_vec_711 = vec_37;
										scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);
										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_712);
										mem_vec_712 = vec_38;
										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_713);
										mem_vec_713 = vec_40;
										scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);
										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_714);
										mem_vec_714 = vec_41;
										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_715);
										mem_vec_715 = vec_43;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_688);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_689);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_690);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_691);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_692);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_693);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_694);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_695);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_696);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_697);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_698);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_699);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_700);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_701);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_702);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_703);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_704);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_705);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_706);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_707);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_708);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_709);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_710);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_711);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_712);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_713);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_714);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_715);
						}
					}
				}
}
