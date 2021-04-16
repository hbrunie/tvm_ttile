
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (56, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, f82_p_0, f83_p_0, fp_1, f82_p_1, fp_2, f82, f83, w, wp_0, x, xp_0, x66_p_0, xp_1, x66, y, yp_0;
IND_TYPE y47 = 0;
IND_TYPE x67 = 0;
IND_TYPE h = 0;
IND_TYPE w44 = 0;
IND_TYPE c67 = 0;
IND_TYPE f84 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
f83 = 0;
f83_p_0 = 0;
f82 = 0;
f82_p_1 = 0;
x66 = 0;
x66_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c66 = 0;
c66_p_0 = 0;
							for (w = w44, wp_0 = 0;w < w44 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x66, xp_1 = x66_p_0, xp_0 = 0;x < x66 + 1;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_912 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_913 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_914 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_915 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_916 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_917 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_918 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_919 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_920 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_921 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_922 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_923 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_924 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_925 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_926 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_927 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_928 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_929 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_930 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_931 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c66, cp_1 = c66_p_0, cp_0 = 0;c < c66 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_912);
												mem_vec_912 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_913);
												mem_vec_913 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_914);
												mem_vec_914 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_915);
												mem_vec_915 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_916);
												mem_vec_916 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_917);
												mem_vec_917 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_918);
												mem_vec_918 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_919);
												mem_vec_919 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_920);
												mem_vec_920 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_921);
												mem_vec_921 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_922);
												mem_vec_922 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_923);
												mem_vec_923 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_924);
												mem_vec_924 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_925);
												mem_vec_925 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_926);
												mem_vec_926 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_927);
												mem_vec_927 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_928);
												mem_vec_928 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_929);
												mem_vec_929 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_930);
												mem_vec_930 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_931);
												mem_vec_931 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_912);
												mem_vec_912 = vec_29;
												vec_33 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_913);
												mem_vec_913 = vec_32;
												vec_35 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_914);
												mem_vec_914 = vec_34;
												vec_37 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_915);
												mem_vec_915 = vec_36;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_916);
												mem_vec_916 = vec_38;
												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_917);
												mem_vec_917 = vec_40;
												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_918);
												mem_vec_918 = vec_41;
												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_919);
												mem_vec_919 = vec_42;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_920);
												mem_vec_920 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_921);
												mem_vec_921 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_922);
												mem_vec_922 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_923);
												mem_vec_923 = vec_47;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_924);
												mem_vec_924 = vec_48;
												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_925);
												mem_vec_925 = vec_50;
												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_926);
												mem_vec_926 = vec_51;
												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_927);
												mem_vec_927 = vec_52;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);
												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_928);
												mem_vec_928 = vec_53;
												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_929);
												mem_vec_929 = vec_55;
												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_930);
												mem_vec_930 = vec_56;
												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_931);
												mem_vec_931 = vec_57;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_912);
												mem_vec_912 = vec_58;
												vec_62 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_913);
												mem_vec_913 = vec_61;
												vec_64 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_914);
												mem_vec_914 = vec_63;
												vec_66 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_915);
												mem_vec_915 = vec_65;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_916);
												mem_vec_916 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_917);
												mem_vec_917 = vec_69;
												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_918);
												mem_vec_918 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_919);
												mem_vec_919 = vec_71;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_920);
												mem_vec_920 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_921);
												mem_vec_921 = vec_74;
												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_922);
												mem_vec_922 = vec_75;
												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_923);
												mem_vec_923 = vec_76;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);
												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_924);
												mem_vec_924 = vec_77;
												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_925);
												mem_vec_925 = vec_79;
												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_926);
												mem_vec_926 = vec_80;
												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_927);
												mem_vec_927 = vec_81;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);
												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_928);
												mem_vec_928 = vec_82;
												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_929);
												mem_vec_929 = vec_84;
												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_930);
												mem_vec_930 = vec_85;
												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_931);
												mem_vec_931 = vec_86;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_912);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_913);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_914);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_915);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_916);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_917);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_918);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_919);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_920);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_921);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_922);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_923);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_924);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_925);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_926);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_927);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_928);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_929);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_930);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_931);
								}
							}
}
