
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (8, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1124_p_0, cp_1, c1124, f, fp_0, f1152_p_0, f1153_p_0, fp_1, f1152_p_1, fp_2, f1152, f1153, h, hp_0, x, xp_0, x1360_p_0, x1361_p_0, xp_1, x1360_p_1, xp_2, x1360, x1361, y, yp_0;
IND_TYPE y680 = 0;
IND_TYPE x1362 = 0;
IND_TYPE h442 = 0;
IND_TYPE w = 0;
IND_TYPE c1125 = 0;
IND_TYPE f1154 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11936 ,mem_vec_11937 ,mem_vec_11938 ,mem_vec_11939 ,mem_vec_11940 ,mem_vec_11941 ,mem_vec_11942 ,mem_vec_11943 ,mem_vec_11944 ,mem_vec_11945 ,mem_vec_11946 ,mem_vec_11947 ,mem_vec_11948 ,mem_vec_11949 ,mem_vec_11950 ,mem_vec_11951 ,mem_vec_11952 ,mem_vec_11953 ,mem_vec_11954 ,mem_vec_11955 ,mem_vec_11956 ,mem_vec_11957 ,mem_vec_11958 ,mem_vec_11959 ,mem_vec_11960 ,mem_vec_11961 ,mem_vec_11962 ,mem_vec_11963 ,mem_vec_11964 ,mem_vec_11965 ,mem_vec_11966 ,mem_vec_11967 ,mem_vec_11968 ,mem_vec_11969 ,mem_vec_11970 ,mem_vec_11971 ,mem_vec_11972 ,mem_vec_11973 ,mem_vec_11974 ,mem_vec_11975 ,mem_vec_11976 ,mem_vec_11977 ,mem_vec_11978 ,mem_vec_11979 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f1153 = 0;
f1153_p_0 = 0;
x1361 = 0;
x1361_p_0 = 0;
c1124 = 0;
c1124_p_0 = 0;
f1152 = 0;
f1152_p_1 = 0;
y = 0;
yp_0 = 0;
x1360 = 0;
x1360_p_1 = 0;
f = 0;
fp_2 = 0;
								for (h = h442, hp_0 = 0;h < h442 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1360, xp_2 = x1360_p_1, xp_1 = x1360_p_0, xp_0 = 0;x < x1360 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11936 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_11937 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_11938 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_11939 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_11940 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_11941 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_11942 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_11943 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_11944 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_11945 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_11946 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_11947 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_11948 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_11949 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_11950 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_11951 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1124, cp_1 = c1124_p_0, cp_0 = 0;c < c1124 + 2;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11936);
													mem_vec_11936 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11937);
													mem_vec_11937 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11938);
													mem_vec_11938 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11939);
													mem_vec_11939 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11940);
													mem_vec_11940 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11941);
													mem_vec_11941 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11942);
													mem_vec_11942 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11943);
													mem_vec_11943 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11944);
													mem_vec_11944 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11945);
													mem_vec_11945 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11946);
													mem_vec_11946 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11947);
													mem_vec_11947 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11948);
													mem_vec_11948 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11949);
													mem_vec_11949 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11950);
													mem_vec_11950 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11951);
													mem_vec_11951 = vec_23;
													scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11936);
													mem_vec_11936 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11937);
													mem_vec_11937 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11938);
													mem_vec_11938 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11939);
													mem_vec_11939 = vec_31;
													scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11940);
													mem_vec_11940 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11941);
													mem_vec_11941 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11942);
													mem_vec_11942 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11943);
													mem_vec_11943 = vec_37;
													scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11944);
													mem_vec_11944 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11945);
													mem_vec_11945 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11946);
													mem_vec_11946 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11947);
													mem_vec_11947 = vec_42;
													scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11948);
													mem_vec_11948 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11949);
													mem_vec_11949 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11950);
													mem_vec_11950 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11951);
													mem_vec_11951 = vec_47;
													scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11936);
													mem_vec_11936 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11937);
													mem_vec_11937 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11938);
													mem_vec_11938 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11939);
													mem_vec_11939 = vec_55;
													scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11940);
													mem_vec_11940 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11941);
													mem_vec_11941 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11942);
													mem_vec_11942 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11943);
													mem_vec_11943 = vec_61;
													scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11944);
													mem_vec_11944 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11945);
													mem_vec_11945 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11946);
													mem_vec_11946 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11947);
													mem_vec_11947 = vec_66;
													scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11948);
													mem_vec_11948 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11949);
													mem_vec_11949 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11950);
													mem_vec_11950 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11951);
													mem_vec_11951 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11936);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_11937);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11938);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_11939);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11940);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_11941);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11942);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_11943);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11944);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_11945);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11946);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_11947);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11948);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_11949);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11950);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_11951);
									}
								}
}
