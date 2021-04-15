
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (16, c); T (2, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (1, c);
  T (8, f); T (4, c)]
*/
IND_TYPE c, cp_0, c1318_p_0, c1319_p_0, c1320_p_0, cp_1, c1318_p_1, c1319_p_1, cp_2, c1318_p_2, cp_3, c1318, c1319, c1320, f, fp_0, f906_p_0, fp_1, f906, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y410 = 0;
IND_TYPE x556 = 0;
IND_TYPE h = 0;
IND_TYPE w436 = 0;
IND_TYPE c1321 = 0;
IND_TYPE f907 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,mem_vec_4848 ,mem_vec_4849 ,mem_vec_4850 ,mem_vec_4851 ,mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
c1320 = 0;
c1320_p_0 = 0;
f906 = 0;
f906_p_0 = 0;
c1319 = 0;
c1319_p_1 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_1 = 0;
c1318 = 0;
c1318_p_2 = 0;
							for (w = w436, wp_0 = 0;w < w436 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 16, f = 64
								// T (x, 7) (7 / 1)
								for (x = x556, xp_0 = 0;x < x556 + 7;x += 1, xp_0 += 1){
											mem_vec_4836 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4837 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4838 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_4839 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_4840 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4841 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4842 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_4843 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
											// T (c, 16) (16 / 1)
											for (c = c1318, cp_3 = c1318_p_2, cp_2 = c1318_p_1, cp_1 = c1318_p_0, cp_0 = 0;c < c1318 + 16;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4836);
												mem_vec_4836 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4837);
												mem_vec_4837 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4838);
												mem_vec_4838 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4839);
												mem_vec_4839 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4840);
												mem_vec_4840 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4841);
												mem_vec_4841 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4842);
												mem_vec_4842 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4843);
												mem_vec_4843 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4836);
												mem_vec_4836 = vec_14;
												vec_18 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4837);
												mem_vec_4837 = vec_17;
												vec_20 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_4838);
												mem_vec_4838 = vec_19;
												vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_4839);
												mem_vec_4839 = vec_21;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_3);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4840);
												mem_vec_4840 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_4841);
												mem_vec_4841 = vec_25;
												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4842);
												mem_vec_4842 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_4843);
												mem_vec_4843 = vec_27;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4836);
												mem_vec_4836 = vec_28;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4837);
												mem_vec_4837 = vec_31;
												vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_4838);
												mem_vec_4838 = vec_33;
												vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_4839);
												mem_vec_4839 = vec_35;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_5);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4840);
												mem_vec_4840 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_4841);
												mem_vec_4841 = vec_39;
												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4842);
												mem_vec_4842 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4843);
												mem_vec_4843 = vec_41;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4836);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4837);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4838);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4839);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4840);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4841);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4842);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4843);
								}
							}
}
