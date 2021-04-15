
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (68, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 13))];
  T (2, f); T (16, c); T (1, f); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c312_p_0, cp_1, c312, f, fp_0, f392_p_0, f393_p_0, fp_1, f392_p_1, fp_2, f392, f393, w, wp_0, x, xp_0, x342_p_0, xp_1, x342, y, yp_0;
IND_TYPE y208 = 0;
IND_TYPE x343 = 0;
IND_TYPE h = 0;
IND_TYPE w182 = 0;
IND_TYPE c313 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2694 ,mem_vec_2695 ,mem_vec_2696 ,mem_vec_2697 ,mem_vec_2698 ,mem_vec_2699 ,mem_vec_2700 ,mem_vec_2701 ,mem_vec_2702 ,mem_vec_2703 ,mem_vec_2704 ,mem_vec_2705 ,mem_vec_2706 ,mem_vec_2707 ,mem_vec_2708 ,mem_vec_2709 ,mem_vec_2710 ,mem_vec_2711 ,mem_vec_2712 ,mem_vec_2713 ,mem_vec_2714 ,mem_vec_2715 ,mem_vec_2716 ,mem_vec_2717 ,mem_vec_2718 ,mem_vec_2719 ,mem_vec_2720 ,mem_vec_2721 ,mem_vec_2722 ,mem_vec_2723 ,mem_vec_2724 ,mem_vec_2725 ,mem_vec_2726 ,mem_vec_2727 ,mem_vec_2728 ,mem_vec_2729 ,mem_vec_2730 ,mem_vec_2731 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
f393 = 0;
f393_p_0 = 0;
x342 = 0;
x342_p_0 = 0;
f392 = 0;
f392_p_1 = 0;
c312 = 0;
c312_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (w = w182, wp_0 = 0;w < w182 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 68, h = 3, w = 1, c = 8, f = 32
								// T (x, 68) (68 / 1)
								for (x = x342, xp_1 = x342_p_0, xp_0 = 0;x < x342 + 68;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2694 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2695 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_2703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_2704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_2705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c312, cp_1 = c312_p_0, cp_0 = 0;c < c312 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2694);
												mem_vec_2694 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2695);
												mem_vec_2695 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2696);
												mem_vec_2696 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2697);
												mem_vec_2697 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2698);
												mem_vec_2698 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2699);
												mem_vec_2699 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2700);
												mem_vec_2700 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2701);
												mem_vec_2701 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2702);
												mem_vec_2702 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2703);
												mem_vec_2703 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2704);
												mem_vec_2704 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2705);
												mem_vec_2705 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_2694);
												mem_vec_2694 = vec_20;
												vec_24 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_2695);
												mem_vec_2695 = vec_23;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_26 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_2696);
												mem_vec_2696 = vec_25;
												vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_2697);
												mem_vec_2697 = vec_27;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_2698);
												mem_vec_2698 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_2699);
												mem_vec_2699 = vec_30;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_32 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_2700);
												mem_vec_2700 = vec_31;
												vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_2701);
												mem_vec_2701 = vec_33;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_2702);
												mem_vec_2702 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_2703);
												mem_vec_2703 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_2704);
												mem_vec_2704 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_2705);
												mem_vec_2705 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_2694);
												mem_vec_2694 = vec_40;
												vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_2695);
												mem_vec_2695 = vec_43;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_46 = _mm512_set1_ps(scal_13);
												vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_2696);
												mem_vec_2696 = vec_45;
												vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_2697);
												mem_vec_2697 = vec_47;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_49 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2698);
												mem_vec_2698 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_2699);
												mem_vec_2699 = vec_50;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_15);
												vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_2700);
												mem_vec_2700 = vec_51;
												vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_2701);
												mem_vec_2701 = vec_53;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_55 = _mm512_set1_ps(scal_16);
												vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_2702);
												mem_vec_2702 = vec_54;
												vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_2703);
												mem_vec_2703 = vec_56;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_17);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_2704);
												mem_vec_2704 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_2705);
												mem_vec_2705 = vec_59;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2694);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2695);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2696);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2697);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2698);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2699);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2700);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2701);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2702);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2703);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2704);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2705);
								}
							}
}
