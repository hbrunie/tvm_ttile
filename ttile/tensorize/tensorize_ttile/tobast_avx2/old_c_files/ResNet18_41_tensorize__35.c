
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (32, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (8, f);
  T (14, x)]
*/
IND_TYPE c, cp_0, c950_p_0, cp_1, c950, f, fp_0, w, wp_0, x, xp_0, x1094_p_0, x1095_p_0, xp_1, x1094_p_1, xp_2, x1094, x1095, y, yp_0;
IND_TYPE y584 = 0;
IND_TYPE x1096 = 0;
IND_TYPE h = 0;
IND_TYPE w448 = 0;
IND_TYPE c951 = 0;
IND_TYPE f658 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7968 ,mem_vec_7969 ,mem_vec_7970 ,mem_vec_7971 ,mem_vec_7972 ,mem_vec_7973 ,mem_vec_7974 ,mem_vec_7975 ,mem_vec_7976 ,mem_vec_7977 ,mem_vec_7978 ,mem_vec_7979 ,mem_vec_7980 ,mem_vec_7981 ,mem_vec_7982 ,mem_vec_7983 ,mem_vec_7984 ,mem_vec_7985 ,mem_vec_7986 ,mem_vec_7987 ,mem_vec_7988 ,mem_vec_7989 ,mem_vec_7990 ,mem_vec_7991 ,mem_vec_7992 ,mem_vec_7993 ,mem_vec_7994 ,mem_vec_7995 ,mem_vec_7996 ,mem_vec_7997 ,mem_vec_7998 ,mem_vec_7999 ,mem_vec_8000 ,mem_vec_8001 ,mem_vec_8002 ,mem_vec_8003 ,mem_vec_8004 ,mem_vec_8005 ,mem_vec_8006 ,mem_vec_8007 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 14) (28 / 2)
x1095 = 0;
x1095_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1094 = 0;
x1094_p_1 = 0;
c950 = 0;
c950_p_0 = 0;
						for (w = w448, wp_0 = 0;w < w448 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
							// T (x, 1) (1 / 1)
							for (x = x1094, xp_2 = x1094_p_1, xp_1 = x1094_p_0, xp_0 = 0;x < x1094 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7968 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7969 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_7970 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7971 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_7972 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7973 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_7974 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7975 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_7976 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7977 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_7978 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_7979 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_7980 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_7981 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_7982 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_7983 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
										// T (c, 2) (2 / 1)
										for (c = c950, cp_1 = c950_p_0, cp_0 = 0;c < c950 + 2;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7968);
											mem_vec_7968 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7969);
											mem_vec_7969 = vec_3;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7970);
											mem_vec_7970 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7971);
											mem_vec_7971 = vec_7;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7972);
											mem_vec_7972 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7973);
											mem_vec_7973 = vec_10;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7974);
											mem_vec_7974 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7975);
											mem_vec_7975 = vec_13;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7976);
											mem_vec_7976 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7977);
											mem_vec_7977 = vec_16;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7978);
											mem_vec_7978 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7979);
											mem_vec_7979 = vec_19;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7980);
											mem_vec_7980 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7981);
											mem_vec_7981 = vec_22;
											scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7982);
											mem_vec_7982 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7983);
											mem_vec_7983 = vec_25;
											scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_7968);
											mem_vec_7968 = vec_26;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_7969);
											mem_vec_7969 = vec_29;
											scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
											vec_32 = _mm256_set1_ps(scal_9);
											vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_7970);
											mem_vec_7970 = vec_31;
											vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_7971);
											mem_vec_7971 = vec_33;
											scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_7972);
											mem_vec_7972 = vec_34;
											vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_7973);
											mem_vec_7973 = vec_36;
											scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_7974);
											mem_vec_7974 = vec_37;
											vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_7975);
											mem_vec_7975 = vec_39;
											scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_7976);
											mem_vec_7976 = vec_40;
											vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_7977);
											mem_vec_7977 = vec_42;
											scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7978);
											mem_vec_7978 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7979);
											mem_vec_7979 = vec_45;
											scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_7980);
											mem_vec_7980 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_7981);
											mem_vec_7981 = vec_48;
											scal_15 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_7982);
											mem_vec_7982 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_7983);
											mem_vec_7983 = vec_51;
											scal_16 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_7968);
											mem_vec_7968 = vec_52;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_7969);
											mem_vec_7969 = vec_55;
											scal_17 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_17);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7970);
											mem_vec_7970 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7971);
											mem_vec_7971 = vec_59;
											scal_18 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 2) + c];
											vec_61 = _mm256_set1_ps(scal_18);
											vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_7972);
											mem_vec_7972 = vec_60;
											vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_7973);
											mem_vec_7973 = vec_62;
											scal_19 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);
											vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_7974);
											mem_vec_7974 = vec_63;
											vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_7975);
											mem_vec_7975 = vec_65;
											scal_20 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_7976);
											mem_vec_7976 = vec_66;
											vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_7977);
											mem_vec_7977 = vec_68;
											scal_21 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);
											vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_7978);
											mem_vec_7978 = vec_69;
											vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_7979);
											mem_vec_7979 = vec_71;
											scal_22 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_7980);
											mem_vec_7980 = vec_72;
											vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_7981);
											mem_vec_7981 = vec_74;
											scal_23 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);
											vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_7982);
											mem_vec_7982 = vec_75;
											vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_7983);
											mem_vec_7983 = vec_77;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7968);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7969);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7970);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7971);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7972);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7973);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7974);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7975);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7976);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_7977);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7978);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_7979);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7980);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_7981);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7982);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_7983);
							}
						}
}
