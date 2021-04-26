
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (56, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c99_p_0, cp_1, c99, f, fp_0, f90_p_0, f91_p_0, fp_1, f90_p_1, fp_2, f90, f91, w, wp_0, x, xp_0, x114_p_0, xp_1, x114, y, yp_0;
IND_TYPE y66 = 0;
IND_TYPE x115 = 0;
IND_TYPE h = 0;
IND_TYPE w62 = 0;
IND_TYPE c100 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
f91 = 0;
f91_p_0 = 0;
f90 = 0;
f90_p_1 = 0;
x114 = 0;
x114_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c99 = 0;
c99_p_0 = 0;
							for (w = w62, wp_0 = 0;w < w62 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
								// T (x, 1) (1 / 1)
								for (x = x114, xp_1 = x114_p_0, xp_0 = 0;x < x114 + 1;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_726 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_727 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_728 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_729 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_730 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_731 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_732 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_733 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_734 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_735 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
											// T (c, 128) (128 / 1)
											for (c = c99, cp_1 = c99_p_0, cp_0 = 0;c < c99 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_726);
												mem_vec_726 = vec_0;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);
												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_727);
												mem_vec_727 = vec_3;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_728);
												mem_vec_728 = vec_5;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);
												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_729);
												mem_vec_729 = vec_7;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_730);
												mem_vec_730 = vec_9;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_731);
												mem_vec_731 = vec_11;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);
												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_732);
												mem_vec_732 = vec_13;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);
												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_733);
												mem_vec_733 = vec_15;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_734);
												mem_vec_734 = vec_17;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_20 = _mm512_set1_ps(scal_9);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_735);
												mem_vec_735 = vec_19;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_22 = _mm512_set1_ps(scal_10);
												vec_23 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_21 = _mm512_fmadd_ps(vec_22, vec_23, mem_vec_726);
												mem_vec_726 = vec_21;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_23, mem_vec_727);
												mem_vec_727 = vec_24;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_23, mem_vec_728);
												mem_vec_728 = vec_26;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_729);
												mem_vec_729 = vec_28;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);
												vec_30 = _mm512_fmadd_ps(vec_31, vec_23, mem_vec_730);
												mem_vec_730 = vec_30;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_23, mem_vec_731);
												mem_vec_731 = vec_32;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_23, mem_vec_732);
												mem_vec_732 = vec_34;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);
												vec_36 = _mm512_fmadd_ps(vec_37, vec_23, mem_vec_733);
												mem_vec_733 = vec_36;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_18);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_23, mem_vec_734);
												mem_vec_734 = vec_38;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_19);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_23, mem_vec_735);
												mem_vec_735 = vec_40;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_43 = _mm512_set1_ps(scal_20);
												vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_42 = _mm512_fmadd_ps(vec_43, vec_44, mem_vec_726);
												mem_vec_726 = vec_42;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_46 = _mm512_set1_ps(scal_21);
												vec_45 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_727);
												mem_vec_727 = vec_45;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_22);
												vec_47 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_728);
												mem_vec_728 = vec_47;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_50 = _mm512_set1_ps(scal_23);
												vec_49 = _mm512_fmadd_ps(vec_50, vec_44, mem_vec_729);
												mem_vec_729 = vec_49;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_24);
												vec_51 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_730);
												mem_vec_730 = vec_51;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_54 = _mm512_set1_ps(scal_25);
												vec_53 = _mm512_fmadd_ps(vec_54, vec_44, mem_vec_731);
												mem_vec_731 = vec_53;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_56 = _mm512_set1_ps(scal_26);
												vec_55 = _mm512_fmadd_ps(vec_56, vec_44, mem_vec_732);
												mem_vec_732 = vec_55;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_27);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_733);
												mem_vec_733 = vec_57;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_60 = _mm512_set1_ps(scal_28);
												vec_59 = _mm512_fmadd_ps(vec_60, vec_44, mem_vec_734);
												mem_vec_734 = vec_59;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_62 = _mm512_set1_ps(scal_29);
												vec_61 = _mm512_fmadd_ps(vec_62, vec_44, mem_vec_735);
												mem_vec_735 = vec_61;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_726);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_727);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_728);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_729);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_730);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_731);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_732);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_733);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_734);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_735);
								}
							}
}
