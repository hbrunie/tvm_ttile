
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (14, x); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (8, f); T (8, c); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, f, fp_0, f124_p_0, f125_p_0, fp_1, f124_p_1, fp_2, f124, f125, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y62 = 0;
IND_TYPE x62 = 0;
IND_TYPE h = 0;
IND_TYPE w47 = 0;
IND_TYPE c94 = 0;
IND_TYPE f126 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 2) (512 / 256)
f125 = 0;
f125_p_0 = 0;
f124 = 0;
f124_p_1 = 0;
c93 = 0;
c93_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (w = w47, wp_0 = 0;w < w47 + 3;w += 1, wp_0 += 1){
										mem_vec_880 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_881 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_882 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_883 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_884 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_885 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_886 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_887 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_888 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_889 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_890 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_891 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_892 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_893 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_894 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_895 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c93, cp_1 = c93_p_0, cp_0 = 0;c < c93 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_880);
											mem_vec_880 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_881);
											mem_vec_881 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_882);
											mem_vec_882 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_883);
											mem_vec_883 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_884);
											mem_vec_884 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_885);
											mem_vec_885 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_886);
											mem_vec_886 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_887);
											mem_vec_887 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_888);
											mem_vec_888 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_889);
											mem_vec_889 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_890);
											mem_vec_890 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_891);
											mem_vec_891 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_892);
											mem_vec_892 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_893);
											mem_vec_893 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_894);
											mem_vec_894 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_895);
											mem_vec_895 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_880);
											mem_vec_880 = vec_24;
											vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_881);
											mem_vec_881 = vec_27;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_882);
											mem_vec_882 = vec_29;
											vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_883);
											mem_vec_883 = vec_31;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);
											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_884);
											mem_vec_884 = vec_33;
											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_885);
											mem_vec_885 = vec_35;
											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_886);
											mem_vec_886 = vec_36;
											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_887);
											mem_vec_887 = vec_37;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_888);
											mem_vec_888 = vec_38;
											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_889);
											mem_vec_889 = vec_40;
											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_890);
											mem_vec_890 = vec_41;
											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_891);
											mem_vec_891 = vec_42;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_892);
											mem_vec_892 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_893);
											mem_vec_893 = vec_45;
											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_894);
											mem_vec_894 = vec_46;
											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_895);
											mem_vec_895 = vec_47;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_880);
											mem_vec_880 = vec_48;
											vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_881);
											mem_vec_881 = vec_51;
											vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_882);
											mem_vec_882 = vec_53;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_883);
											mem_vec_883 = vec_55;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_884);
											mem_vec_884 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_885);
											mem_vec_885 = vec_59;
											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_886);
											mem_vec_886 = vec_60;
											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_887);
											mem_vec_887 = vec_61;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);
											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_888);
											mem_vec_888 = vec_62;
											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_889);
											mem_vec_889 = vec_64;
											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_890);
											mem_vec_890 = vec_65;
											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_891);
											mem_vec_891 = vec_66;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_892);
											mem_vec_892 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_893);
											mem_vec_893 = vec_69;
											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_894);
											mem_vec_894 = vec_70;
											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_895);
											mem_vec_895 = vec_71;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_880);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_881);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_882);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_883);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_884);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_885);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_886);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_887);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_888);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_889);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_890);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_891);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_892);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_893);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_894);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_895);
							}
}
