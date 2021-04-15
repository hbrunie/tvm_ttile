
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (1, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (16, f);
  T (2, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1142_p_0, cp_1, c1142, f, fp_0, f552_p_0, f553_p_0, fp_1, f552_p_1, fp_2, f552, f553, w, wp_0, x, xp_0, x968_p_0, x969_p_0, xp_1, x968_p_1, xp_2, x968, x969, y, yp_0;
IND_TYPE y484 = 0;
IND_TYPE x970 = 0;
IND_TYPE h = 0;
IND_TYPE w484 = 0;
IND_TYPE c1143 = 0;
IND_TYPE f554 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10008 ,mem_vec_10009 ,mem_vec_10010 ,mem_vec_10011 ,mem_vec_10012 ,mem_vec_10013 ,mem_vec_10014 ,mem_vec_10015 ,mem_vec_10016 ,mem_vec_10017 ,mem_vec_10018 ,mem_vec_10019 ,mem_vec_10020 ,mem_vec_10021 ,mem_vec_10022 ,mem_vec_10023 ,mem_vec_10024 ,mem_vec_10025 ,mem_vec_10026 ,mem_vec_10027 ,mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f553 = 0;
f553_p_0 = 0;
x969 = 0;
x969_p_0 = 0;
c1142 = 0;
c1142_p_0 = 0;
f552 = 0;
f552_p_1 = 0;
y = 0;
yp_0 = 0;
x968 = 0;
x968_p_1 = 0;
f = 0;
fp_2 = 0;
								for (w = w484, wp_0 = 0;w < w484 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 3, w = 1, c = 128, f = 32
									// T (x, 34) (34 / 1)
									for (x = x968, xp_2 = x968_p_1, xp_1 = x968_p_0, xp_0 = 0;x < x968 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10008 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_10009 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_10010 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_10011 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_10012 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_10013 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_10014 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_10015 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_10016 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_10017 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_10018 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_10019 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_10020 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_10021 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_10022 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_10023 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c1142, cp_1 = c1142_p_0, cp_0 = 0;c < c1142 + 128;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10008);
													mem_vec_10008 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10009);
													mem_vec_10009 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10010);
													mem_vec_10010 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10011);
													mem_vec_10011 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10012);
													mem_vec_10012 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10013);
													mem_vec_10013 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10014);
													mem_vec_10014 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10015);
													mem_vec_10015 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10016);
													mem_vec_10016 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10017);
													mem_vec_10017 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10018);
													mem_vec_10018 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10019);
													mem_vec_10019 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10020);
													mem_vec_10020 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10021);
													mem_vec_10021 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10022);
													mem_vec_10022 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10023);
													mem_vec_10023 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10008);
													mem_vec_10008 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10009);
													mem_vec_10009 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10010);
													mem_vec_10010 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10011);
													mem_vec_10011 = vec_31;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10012);
													mem_vec_10012 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10013);
													mem_vec_10013 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10014);
													mem_vec_10014 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10015);
													mem_vec_10015 = vec_37;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10016);
													mem_vec_10016 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10017);
													mem_vec_10017 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10018);
													mem_vec_10018 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10019);
													mem_vec_10019 = vec_42;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10020);
													mem_vec_10020 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10021);
													mem_vec_10021 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10022);
													mem_vec_10022 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10023);
													mem_vec_10023 = vec_47;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10008);
													mem_vec_10008 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10009);
													mem_vec_10009 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10010);
													mem_vec_10010 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10011);
													mem_vec_10011 = vec_55;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10012);
													mem_vec_10012 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10013);
													mem_vec_10013 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10014);
													mem_vec_10014 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10015);
													mem_vec_10015 = vec_61;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10016);
													mem_vec_10016 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10017);
													mem_vec_10017 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10018);
													mem_vec_10018 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10019);
													mem_vec_10019 = vec_66;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10020);
													mem_vec_10020 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10021);
													mem_vec_10021 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10022);
													mem_vec_10022 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10023);
													mem_vec_10023 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10008);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10009);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10010);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10011);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10012);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10013);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10014);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10015);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10016);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10017);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10018);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10019);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10020);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10021);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10022);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10023);
									}
								}
}
