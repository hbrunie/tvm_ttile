
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (4, f);
  T (256, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1020_p_0, cp_1, c1020, f, fp_0, f1360_p_0, f1361_p_0, fp_1, f1360_p_1, fp_2, f1360, f1361, h, hp_0, x, xp_0, x1020_p_0, xp_1, x1020, y, yp_0;
IND_TYPE y680 = 0;
IND_TYPE x1021 = 0;
IND_TYPE h494 = 0;
IND_TYPE w = 0;
IND_TYPE c1021 = 0;
IND_TYPE f1362 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11808 ,mem_vec_11809 ,mem_vec_11810 ,mem_vec_11811 ,mem_vec_11812 ,mem_vec_11813 ,mem_vec_11814 ,mem_vec_11815 ,mem_vec_11816 ,mem_vec_11817 ,mem_vec_11818 ,mem_vec_11819 ,mem_vec_11820 ,mem_vec_11821 ,mem_vec_11822 ,mem_vec_11823 ,mem_vec_11824 ,mem_vec_11825 ,mem_vec_11826 ,mem_vec_11827 ,mem_vec_11828 ,mem_vec_11829 ,mem_vec_11830 ,mem_vec_11831 ,mem_vec_11832 ,mem_vec_11833 ,mem_vec_11834 ,mem_vec_11835 ,mem_vec_11836 ,mem_vec_11837 ,mem_vec_11838 ,mem_vec_11839 ,mem_vec_11840 ,mem_vec_11841 ,mem_vec_11842 ,mem_vec_11843 ,mem_vec_11844 ,mem_vec_11845 ,mem_vec_11846 ,mem_vec_11847 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
f1361 = 0;
f1361_p_0 = 0;
c1020 = 0;
c1020_p_0 = 0;
f1360 = 0;
f1360_p_1 = 0;
y = 0;
yp_0 = 0;
x1020 = 0;
x1020_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h494, hp_0 = 0;h < h494 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 32
								// T (x, 14) (14 / 1)
								for (x = x1020, xp_1 = x1020_p_0, xp_0 = 0;x < x1020 + 14;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11808 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11809 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_11810 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11811 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_11812 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11813 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_11814 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11815 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_11816 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11817 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_11818 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11819 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_11820 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11821 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_11822 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11823 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1020, cp_1 = c1020_p_0, cp_0 = 0;c < c1020 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11808);
												mem_vec_11808 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11809);
												mem_vec_11809 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11810);
												mem_vec_11810 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11811);
												mem_vec_11811 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11812);
												mem_vec_11812 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11813);
												mem_vec_11813 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11814);
												mem_vec_11814 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11815);
												mem_vec_11815 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11816);
												mem_vec_11816 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11817);
												mem_vec_11817 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11818);
												mem_vec_11818 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11819);
												mem_vec_11819 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11820);
												mem_vec_11820 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11821);
												mem_vec_11821 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11822);
												mem_vec_11822 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11823);
												mem_vec_11823 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11808);
												mem_vec_11808 = vec_24;
												vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11809);
												mem_vec_11809 = vec_27;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11810);
												mem_vec_11810 = vec_29;
												vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11811);
												mem_vec_11811 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);
												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11812);
												mem_vec_11812 = vec_33;
												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11813);
												mem_vec_11813 = vec_35;
												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11814);
												mem_vec_11814 = vec_36;
												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11815);
												mem_vec_11815 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11816);
												mem_vec_11816 = vec_38;
												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11817);
												mem_vec_11817 = vec_40;
												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11818);
												mem_vec_11818 = vec_41;
												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11819);
												mem_vec_11819 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11820);
												mem_vec_11820 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11821);
												mem_vec_11821 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11822);
												mem_vec_11822 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11823);
												mem_vec_11823 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11808);
												mem_vec_11808 = vec_48;
												vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11809);
												mem_vec_11809 = vec_51;
												vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11810);
												mem_vec_11810 = vec_53;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11811);
												mem_vec_11811 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11812);
												mem_vec_11812 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11813);
												mem_vec_11813 = vec_59;
												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11814);
												mem_vec_11814 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11815);
												mem_vec_11815 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);
												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11816);
												mem_vec_11816 = vec_62;
												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11817);
												mem_vec_11817 = vec_64;
												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11818);
												mem_vec_11818 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11819);
												mem_vec_11819 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11820);
												mem_vec_11820 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11821);
												mem_vec_11821 = vec_69;
												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11822);
												mem_vec_11822 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11823);
												mem_vec_11823 = vec_71;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11808);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_11809);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11810);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_11811);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11812);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_11813);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11814);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_11815);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11816);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_11817);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11818);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_11819);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11820);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_11821);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11822);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_11823);
								}
							}
}
