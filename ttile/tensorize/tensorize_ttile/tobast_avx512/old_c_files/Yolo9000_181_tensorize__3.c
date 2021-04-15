
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (64, c); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 5), (Arg 3))]; T (2, c);
  T (1, f)]
*/
IND_TYPE c, cp_0, c902_p_0, c903_p_0, cp_1, c902_p_1, cp_2, c902, c903, f, fp_0, f1016_p_0, fp_1, f1016, h, hp_0, x, xp_0, x822_p_0, xp_1, x822, y, yp_0;
IND_TYPE y548 = 0;
IND_TYPE x823 = 0;
IND_TYPE h434 = 0;
IND_TYPE w = 0;
IND_TYPE c904 = 0;
IND_TYPE f1017 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7790 ,mem_vec_7791 ,mem_vec_7792 ,mem_vec_7793 ,mem_vec_7794 ,mem_vec_7795 ,mem_vec_7796 ,mem_vec_7797 ,mem_vec_7798 ,mem_vec_7799 ,mem_vec_7800 ,mem_vec_7801 ,mem_vec_7802 ,mem_vec_7803 ,mem_vec_7804 ,mem_vec_7805 ,mem_vec_7806 ,mem_vec_7807 ,mem_vec_7808 ,mem_vec_7809 ,mem_vec_7810 ,mem_vec_7811 ,mem_vec_7812 ,mem_vec_7813 ,mem_vec_7814 ,mem_vec_7815 ,mem_vec_7816 ,mem_vec_7817 ,mem_vec_7818 ,mem_vec_7819 ,mem_vec_7820 ,mem_vec_7821 ,mem_vec_7822 ,mem_vec_7823 ,mem_vec_7824 ,mem_vec_7825 ,mem_vec_7826 ,mem_vec_7827 ,mem_vec_7828 ,mem_vec_7829 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
f1016 = 0;
f1016_p_0 = 0;
c903 = 0;
c903_p_0 = 0;
y = 0;
yp_0 = 0;
x822 = 0;
x822_p_0 = 0;
f = 0;
fp_1 = 0;
c902 = 0;
c902_p_1 = 0;
							for (h = h434, hp_0 = 0;h < h434 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 128
								// T (x, 17) (17 / 1)
								for (x = x822, xp_1 = x822_p_0, xp_0 = 0;x < x822 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_7791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_7792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_7793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_7794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 64]);
											mem_vec_7795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 80]);
											mem_vec_7796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 96]);
											mem_vec_7797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 112]);
											mem_vec_7798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_7799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_7800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_7801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_7802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64]);
											mem_vec_7803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80]);
											mem_vec_7804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96]);
											mem_vec_7805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 128
											// T (c, 4) (4 / 1)
											for (c = c902, cp_2 = c902_p_1, cp_1 = c902_p_0, cp_0 = 0;c < c902 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7790);
												mem_vec_7790 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7791);
												mem_vec_7791 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7792);
												mem_vec_7792 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7793);
												mem_vec_7793 = vec_7;
												vec_10 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 64]);
												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7794);
												mem_vec_7794 = vec_9;
												vec_12 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 80]);
												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7795);
												mem_vec_7795 = vec_11;
												vec_14 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 96]);
												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7796);
												mem_vec_7796 = vec_13;
												vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 112]);
												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7797);
												mem_vec_7797 = vec_15;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7798);
												mem_vec_7798 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7799);
												mem_vec_7799 = vec_19;
												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7800);
												mem_vec_7800 = vec_20;
												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7801);
												mem_vec_7801 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7802);
												mem_vec_7802 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7803);
												mem_vec_7803 = vec_23;
												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7804);
												mem_vec_7804 = vec_24;
												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7805);
												mem_vec_7805 = vec_25;
												scal_2 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7790);
												mem_vec_7790 = vec_26;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7791);
												mem_vec_7791 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_7792);
												mem_vec_7792 = vec_31;
												vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_7793);
												mem_vec_7793 = vec_33;
												vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 64]);
												vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_7794);
												mem_vec_7794 = vec_35;
												vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 80]);
												vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_7795);
												mem_vec_7795 = vec_37;
												vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 96]);
												vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_7796);
												mem_vec_7796 = vec_39;
												vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 112]);
												vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_7797);
												mem_vec_7797 = vec_41;
												scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_3);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7798);
												mem_vec_7798 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7799);
												mem_vec_7799 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7800);
												mem_vec_7800 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_7801);
												mem_vec_7801 = vec_47;
												vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7802);
												mem_vec_7802 = vec_48;
												vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7803);
												mem_vec_7803 = vec_49;
												vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7804);
												mem_vec_7804 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7805);
												mem_vec_7805 = vec_51;
												scal_4 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7790);
												mem_vec_7790 = vec_52;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7791);
												mem_vec_7791 = vec_55;
												vec_58 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_7792);
												mem_vec_7792 = vec_57;
												vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_7793);
												mem_vec_7793 = vec_59;
												vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 64]);
												vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_7794);
												mem_vec_7794 = vec_61;
												vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 80]);
												vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_7795);
												mem_vec_7795 = vec_63;
												vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 96]);
												vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_7796);
												mem_vec_7796 = vec_65;
												vec_68 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 112]);
												vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_7797);
												mem_vec_7797 = vec_67;
												scal_5 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_70 = _mm512_set1_ps(scal_5);
												vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7798);
												mem_vec_7798 = vec_69;
												vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7799);
												mem_vec_7799 = vec_71;
												vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_7800);
												mem_vec_7800 = vec_72;
												vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7801);
												mem_vec_7801 = vec_73;
												vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7802);
												mem_vec_7802 = vec_74;
												vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_7803);
												mem_vec_7803 = vec_75;
												vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_7804);
												mem_vec_7804 = vec_76;
												vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_7805);
												mem_vec_7805 = vec_77;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7790);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7791);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_7792);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_7793);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 64], mem_vec_7794);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 80], mem_vec_7795);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 96], mem_vec_7796);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 112], mem_vec_7797);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7798);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7799);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_7800);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_7801);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64], mem_vec_7802);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80], mem_vec_7803);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96], mem_vec_7804);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112], mem_vec_7805);
								}
							}
}
