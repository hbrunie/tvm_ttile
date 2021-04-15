
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (4, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (1, c); T (1, f); T (8, c); T (14, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1214_p_0, c1215_p_0, cp_1, c1214_p_1, cp_2, c1214, c1215, f, fp_0, f1140_p_0, f1141_p_0, fp_1, f1140_p_1, fp_2, f1140, f1141, h, hp_0, x, xp_0, x1026_p_0, xp_1, x1026, y, yp_0;
IND_TYPE y640 = 0;
IND_TYPE x1027 = 0;
IND_TYPE h424 = 0;
IND_TYPE w = 0;
IND_TYPE c1216 = 0;
IND_TYPE f1142 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10936 ,mem_vec_10937 ,mem_vec_10938 ,mem_vec_10939 ,mem_vec_10940 ,mem_vec_10941 ,mem_vec_10942 ,mem_vec_10943 ,mem_vec_10944 ,mem_vec_10945 ,mem_vec_10946 ,mem_vec_10947 ,mem_vec_10948 ,mem_vec_10949 ,mem_vec_10950 ,mem_vec_10951 ,mem_vec_10952 ,mem_vec_10953 ,mem_vec_10954 ,mem_vec_10955 ,mem_vec_10956 ,mem_vec_10957 ,mem_vec_10958 ,mem_vec_10959 ,mem_vec_10960 ,mem_vec_10961 ,mem_vec_10962 ,mem_vec_10963 ,mem_vec_10964 ,mem_vec_10965 ,mem_vec_10966 ,mem_vec_10967 ,mem_vec_10968 ,mem_vec_10969 ,mem_vec_10970 ,mem_vec_10971 ,mem_vec_10972 ,mem_vec_10973 ,mem_vec_10974 ,mem_vec_10975 ,mem_vec_10976 ,mem_vec_10977 ,mem_vec_10978 ,mem_vec_10979 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
f1141 = 0;
f1141_p_0 = 0;
x1026 = 0;
x1026_p_0 = 0;
c1215 = 0;
c1215_p_0 = 0;
f1140 = 0;
f1140_p_1 = 0;
c1214 = 0;
c1214_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
								for (h = h424, hp_0 = 0;h < h424 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1026, xp_1 = x1026_p_0, xp_0 = 0;x < x1026 + 4;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10936 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_10937 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_10938 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_10939 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_10940 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_10941 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_10942 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_10943 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_10944 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_10945 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_10946 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_10947 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_10948 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_10949 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_10950 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_10951 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1214, cp_2 = c1214_p_1, cp_1 = c1214_p_0, cp_0 = 0;c < c1214 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10936);
													mem_vec_10936 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10937);
													mem_vec_10937 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10938);
													mem_vec_10938 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10939);
													mem_vec_10939 = vec_7;
													scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10940);
													mem_vec_10940 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10941);
													mem_vec_10941 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10942);
													mem_vec_10942 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10943);
													mem_vec_10943 = vec_13;
													scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10944);
													mem_vec_10944 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10945);
													mem_vec_10945 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10946);
													mem_vec_10946 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10947);
													mem_vec_10947 = vec_18;
													scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10948);
													mem_vec_10948 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10949);
													mem_vec_10949 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10950);
													mem_vec_10950 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10951);
													mem_vec_10951 = vec_23;
													scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10936);
													mem_vec_10936 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10937);
													mem_vec_10937 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10938);
													mem_vec_10938 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10939);
													mem_vec_10939 = vec_31;
													scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10940);
													mem_vec_10940 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10941);
													mem_vec_10941 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10942);
													mem_vec_10942 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10943);
													mem_vec_10943 = vec_37;
													scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10944);
													mem_vec_10944 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10945);
													mem_vec_10945 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10946);
													mem_vec_10946 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10947);
													mem_vec_10947 = vec_42;
													scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10948);
													mem_vec_10948 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10949);
													mem_vec_10949 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10950);
													mem_vec_10950 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10951);
													mem_vec_10951 = vec_47;
													scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10936);
													mem_vec_10936 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10937);
													mem_vec_10937 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10938);
													mem_vec_10938 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10939);
													mem_vec_10939 = vec_55;
													scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10940);
													mem_vec_10940 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10941);
													mem_vec_10941 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10942);
													mem_vec_10942 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10943);
													mem_vec_10943 = vec_61;
													scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10944);
													mem_vec_10944 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10945);
													mem_vec_10945 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10946);
													mem_vec_10946 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10947);
													mem_vec_10947 = vec_66;
													scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10948);
													mem_vec_10948 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10949);
													mem_vec_10949 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10950);
													mem_vec_10950 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10951);
													mem_vec_10951 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10936);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10937);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10938);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10939);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10940);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10941);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10942);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10943);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10944);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10945);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10946);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10947);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10948);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10949);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10950);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10951);
									}
								}
}
