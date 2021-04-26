
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (2, c); T (4, y); T (272, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]]
*/
IND_TYPE c, cp_0, c504_p_0, cp_1, c504, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x602_p_0, xp_1, x602, y, yp_0, y545_p_0, yp_1, y545;
IND_TYPE y546 = 0;
IND_TYPE x603 = 0;
IND_TYPE h295 = 0;
IND_TYPE w279 = 0;
IND_TYPE c505 = 0;
IND_TYPE f279 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4777 ,mem_vec_4778 ,mem_vec_4779 ,mem_vec_4780 ,mem_vec_4781 ,mem_vec_4782 ,mem_vec_4783 ,mem_vec_4784 ,mem_vec_4785 ,mem_vec_4786 ,mem_vec_4787 ,mem_vec_4788 ,mem_vec_4789 ,mem_vec_4790 ,mem_vec_4791 ,mem_vec_4792 ,mem_vec_4793 ,mem_vec_4794 ,mem_vec_4795 ,mem_vec_4796 ,mem_vec_4797 ,mem_vec_4798 ,mem_vec_4799 ,mem_vec_4800 ,mem_vec_4801 ,mem_vec_4802 ,mem_vec_4803 ,mem_vec_4804 ,mem_vec_4805 ,mem_vec_4806 ,mem_vec_4807 ,mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,mem_vec_4812 ,mem_vec_4813 ,mem_vec_4814 ,mem_vec_4815 ,mem_vec_4816 ,mem_vec_4817 ,mem_vec_4818 ,mem_vec_4819 ,mem_vec_4820 ,mem_vec_4821 ,mem_vec_4822 ,mem_vec_4823 ,mem_vec_4824 ,mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y545 = 0;
y545_p_0 = 0;
x602 = 0;
x602_p_0 = 0;
y = 0;
yp_1 = 0;
c504 = 0;
c504_p_0 = 0;
f = 0;
fp_0 = 0;
x = 0;
xp_1 = 0;
							for (h = h295, hp_0 = 0;h < h295 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w279, wp_0 = 0;w < w279 + 3;w += 1, wp_0 += 1){
											mem_vec_4777 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4778 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4779 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4780 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4781 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4782 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4783 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4784 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4785 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4786 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_4787 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4788 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_4789 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_4791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_4793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_4795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_4797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_4798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_4799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_4800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_4801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_4802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c504, cp_1 = c504_p_0, cp_0 = 0;c < c504 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4777);
												mem_vec_4777 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4778);
												mem_vec_4778 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4779);
												mem_vec_4779 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4780);
												mem_vec_4780 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4781);
												mem_vec_4781 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4782);
												mem_vec_4782 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4783);
												mem_vec_4783 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4784);
												mem_vec_4784 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4785);
												mem_vec_4785 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4786);
												mem_vec_4786 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4787);
												mem_vec_4787 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4788);
												mem_vec_4788 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4789);
												mem_vec_4789 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4790);
												mem_vec_4790 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4791);
												mem_vec_4791 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4792);
												mem_vec_4792 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4793);
												mem_vec_4793 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4794);
												mem_vec_4794 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4795);
												mem_vec_4795 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4796);
												mem_vec_4796 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4797);
												mem_vec_4797 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4798);
												mem_vec_4798 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4799);
												mem_vec_4799 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4800);
												mem_vec_4800 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4801);
												mem_vec_4801 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4802);
												mem_vec_4802 = vec_40;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4777);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4778);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4779);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4780);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4781);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4782);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4783);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4784);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4785);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4786);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4787);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4788);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4789);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4790);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4791);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4792);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4793);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4794);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4795);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4796);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4797);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4798);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4799);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4800);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4801);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_4802);
								}
							}
}
