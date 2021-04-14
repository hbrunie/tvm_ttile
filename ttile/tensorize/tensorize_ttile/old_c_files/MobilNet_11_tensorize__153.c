
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (8, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c642_p_0, cp_1, c642, h, hp_0, w, wp_0, x, xp_0, x856_p_0, x857_p_0, xp_1, x856_p_1, xp_2, x856, x857, y, yp_0;
IND_TYPE y428 = 0;
IND_TYPE x858 = 0;
IND_TYPE h408 = 0;
IND_TYPE w428 = 0;
IND_TYPE c643 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7732 ,mem_vec_7733 ,mem_vec_7734 ,mem_vec_7735 ,mem_vec_7736 ,mem_vec_7737 ,mem_vec_7738 ,mem_vec_7739 ,mem_vec_7740 ,mem_vec_7741 ,mem_vec_7742 ,mem_vec_7743 ,mem_vec_7744 ,mem_vec_7745 ,mem_vec_7746 ,mem_vec_7747 ,mem_vec_7748 ,mem_vec_7749 ,mem_vec_7750 ,mem_vec_7751 ,mem_vec_7752 ,mem_vec_7753 ,mem_vec_7754 ,mem_vec_7755 ,mem_vec_7756 ,mem_vec_7757 ,mem_vec_7758 ,mem_vec_7759 ,mem_vec_7760 ,mem_vec_7761 ,mem_vec_7762 ,mem_vec_7763 ,mem_vec_7764 ,mem_vec_7765 ,mem_vec_7766 ,mem_vec_7767 ,mem_vec_7768 ,mem_vec_7769 ,mem_vec_7770 ,mem_vec_7771 ,mem_vec_7772 ,mem_vec_7773 ,mem_vec_7774 ,mem_vec_7775 ,mem_vec_7776 ,mem_vec_7777 ,mem_vec_7778 ,mem_vec_7779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x857 = 0;
x857_p_0 = 0;
c642 = 0;
c642_p_0 = 0;
y = 0;
yp_0 = 0;
x856 = 0;
x856_p_1 = 0;
					for (h = h408, hp_0 = 0;h < h408 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w428, wp_0 = 0;w < w428 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 16, f = 32
							// T (x, 2) (2 / 1)
							for (x = x856, xp_2 = x856_p_1, xp_1 = x856_p_0, xp_0 = 0;x < x856 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7732 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7733 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_7734 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7735 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_7736 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7737 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_7738 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7739 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_7740 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7741 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_7742 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_7743 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_7744 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_7745 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_7746 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_7747 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_7748 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_7749 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_7750 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_7751 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_7752 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_7753 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c642, cp_1 = c642_p_0, cp_0 = 0;c < c642 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7732);
											mem_vec_7732 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7733);
											mem_vec_7733 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7734);
											mem_vec_7734 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7735);
											mem_vec_7735 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7736);
											mem_vec_7736 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7737);
											mem_vec_7737 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7738);
											mem_vec_7738 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7739);
											mem_vec_7739 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7740);
											mem_vec_7740 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7741);
											mem_vec_7741 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7742);
											mem_vec_7742 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7743);
											mem_vec_7743 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7744);
											mem_vec_7744 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7745);
											mem_vec_7745 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7746);
											mem_vec_7746 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7747);
											mem_vec_7747 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7748);
											mem_vec_7748 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7749);
											mem_vec_7749 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7750);
											mem_vec_7750 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7751);
											mem_vec_7751 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7752);
											mem_vec_7752 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7753);
											mem_vec_7753 = vec_34;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7732);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7733);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7734);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7735);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7736);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7737);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7738);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7739);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7740);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7741);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7742);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7743);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7744);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7745);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7746);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7747);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_7748);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_7749);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_7750);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_7751);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_7752);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_7753);
							}
						}
					}
}
