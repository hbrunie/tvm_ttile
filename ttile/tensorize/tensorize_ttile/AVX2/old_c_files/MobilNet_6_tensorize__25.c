
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (14, x); T (2, y); T (2, f); T (8, c); T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c117_p_0, cp_1, c117, f, fp_0, f156_p_0, f157_p_0, fp_1, f156_p_1, fp_2, f156, f157, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y78 = 0;
IND_TYPE x78 = 0;
IND_TYPE h58 = 0;
IND_TYPE w = 0;
IND_TYPE c118 = 0;
IND_TYPE f158 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1092 ,mem_vec_1093 ,mem_vec_1094 ,mem_vec_1095 ,mem_vec_1096 ,mem_vec_1097 ,mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,mem_vec_1104 ,mem_vec_1105 ,mem_vec_1106 ,mem_vec_1107 ,mem_vec_1108 ,mem_vec_1109 ,mem_vec_1110 ,mem_vec_1111 ,mem_vec_1112 ,mem_vec_1113 ,mem_vec_1114 ,mem_vec_1115 ,mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
f157 = 0;
f157_p_0 = 0;
f156 = 0;
f156_p_1 = 0;
c117 = 0;
c117_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
						for (h = h58, hp_0 = 0;h < h58 + 3;h += 1, hp_0 += 1){
									mem_vec_1092 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1093 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_1094 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1095 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_1096 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1097 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_1098 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1099 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_1100 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1101 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_1102 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1103 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_1104 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1105 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_1106 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1107 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_1108 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_1109 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_1110 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_1111 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									mem_vec_1112 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_1113 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
									mem_vec_1114 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_1115 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
									mem_vec_1116 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_1117 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
									mem_vec_1118 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_1119 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24]);
									// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c117, cp_1 = c117_p_0, cp_0 = 0;c < c117 + 32;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1092);
										mem_vec_1092 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1093);
										mem_vec_1093 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1094);
										mem_vec_1094 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1095);
										mem_vec_1095 = vec_7;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1096);
										mem_vec_1096 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1097);
										mem_vec_1097 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1098);
										mem_vec_1098 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1099);
										mem_vec_1099 = vec_13;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1100);
										mem_vec_1100 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1101);
										mem_vec_1101 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1102);
										mem_vec_1102 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1103);
										mem_vec_1103 = vec_18;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1104);
										mem_vec_1104 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1105);
										mem_vec_1105 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1106);
										mem_vec_1106 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1107);
										mem_vec_1107 = vec_23;
										scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1108);
										mem_vec_1108 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1109);
										mem_vec_1109 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1110);
										mem_vec_1110 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1111);
										mem_vec_1111 = vec_28;
										scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);
										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1112);
										mem_vec_1112 = vec_29;
										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1113);
										mem_vec_1113 = vec_31;
										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1114);
										mem_vec_1114 = vec_32;
										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1115);
										mem_vec_1115 = vec_33;
										scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
										vec_35 = _mm256_set1_ps(scal_6);
										vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_1116);
										mem_vec_1116 = vec_34;
										vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_1117);
										mem_vec_1117 = vec_36;
										vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_1118);
										mem_vec_1118 = vec_37;
										vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_1119);
										mem_vec_1119 = vec_38;
										scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
										vec_40 = _mm256_set1_ps(scal_7);
										vec_41 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_1092);
										mem_vec_1092 = vec_39;
										vec_43 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
										vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_1093);
										mem_vec_1093 = vec_42;
										vec_45 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_1094);
										mem_vec_1094 = vec_44;
										vec_47 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
										vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_1095);
										mem_vec_1095 = vec_46;
										scal_8 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_1096);
										mem_vec_1096 = vec_48;
										vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_1097);
										mem_vec_1097 = vec_50;
										vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_1098);
										mem_vec_1098 = vec_51;
										vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_1099);
										mem_vec_1099 = vec_52;
										scal_9 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
										vec_54 = _mm256_set1_ps(scal_9);
										vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_1100);
										mem_vec_1100 = vec_53;
										vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_1101);
										mem_vec_1101 = vec_55;
										vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_1102);
										mem_vec_1102 = vec_56;
										vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_1103);
										mem_vec_1103 = vec_57;
										scal_10 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
										vec_59 = _mm256_set1_ps(scal_10);
										vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_1104);
										mem_vec_1104 = vec_58;
										vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_1105);
										mem_vec_1105 = vec_60;
										vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_1106);
										mem_vec_1106 = vec_61;
										vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_1107);
										mem_vec_1107 = vec_62;
										scal_11 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 4) + h) + c];
										vec_64 = _mm256_set1_ps(scal_11);
										vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_1108);
										mem_vec_1108 = vec_63;
										vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_1109);
										mem_vec_1109 = vec_65;
										vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_1110);
										mem_vec_1110 = vec_66;
										vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_1111);
										mem_vec_1111 = vec_67;
										scal_12 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 5) + h) + c];
										vec_69 = _mm256_set1_ps(scal_12);
										vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_1112);
										mem_vec_1112 = vec_68;
										vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_1113);
										mem_vec_1113 = vec_70;
										vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_1114);
										mem_vec_1114 = vec_71;
										vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_1115);
										mem_vec_1115 = vec_72;
										scal_13 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 6) + h) + c];
										vec_74 = _mm256_set1_ps(scal_13);
										vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_1116);
										mem_vec_1116 = vec_73;
										vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_1117);
										mem_vec_1117 = vec_75;
										vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_1118);
										mem_vec_1118 = vec_76;
										vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_1119);
										mem_vec_1119 = vec_77;
										scal_14 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
										vec_79 = _mm256_set1_ps(scal_14);
										vec_80 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_1092);
										mem_vec_1092 = vec_78;
										vec_82 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
										vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_1093);
										mem_vec_1093 = vec_81;
										vec_84 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_1094);
										mem_vec_1094 = vec_83;
										vec_86 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
										vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_1095);
										mem_vec_1095 = vec_85;
										scal_15 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
										vec_88 = _mm256_set1_ps(scal_15);
										vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_1096);
										mem_vec_1096 = vec_87;
										vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_1097);
										mem_vec_1097 = vec_89;
										vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1098);
										mem_vec_1098 = vec_90;
										vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1099);
										mem_vec_1099 = vec_91;
										scal_16 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
										vec_93 = _mm256_set1_ps(scal_16);
										vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_1100);
										mem_vec_1100 = vec_92;
										vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_1101);
										mem_vec_1101 = vec_94;
										vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_1102);
										mem_vec_1102 = vec_95;
										vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_1103);
										mem_vec_1103 = vec_96;
										scal_17 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
										vec_98 = _mm256_set1_ps(scal_17);
										vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_1104);
										mem_vec_1104 = vec_97;
										vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_1105);
										mem_vec_1105 = vec_99;
										vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_1106);
										mem_vec_1106 = vec_100;
										vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_1107);
										mem_vec_1107 = vec_101;
										scal_18 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 4) + h) + c];
										vec_103 = _mm256_set1_ps(scal_18);
										vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_1108);
										mem_vec_1108 = vec_102;
										vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_1109);
										mem_vec_1109 = vec_104;
										vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_1110);
										mem_vec_1110 = vec_105;
										vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_1111);
										mem_vec_1111 = vec_106;
										scal_19 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 5) + h) + c];
										vec_108 = _mm256_set1_ps(scal_19);
										vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_1112);
										mem_vec_1112 = vec_107;
										vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_1113);
										mem_vec_1113 = vec_109;
										vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_1114);
										mem_vec_1114 = vec_110;
										vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_1115);
										mem_vec_1115 = vec_111;
										scal_20 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 6) + h) + c];
										vec_113 = _mm256_set1_ps(scal_20);
										vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_1116);
										mem_vec_1116 = vec_112;
										vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_1117);
										mem_vec_1117 = vec_114;
										vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_1118);
										mem_vec_1118 = vec_115;
										vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_1119);
										mem_vec_1119 = vec_116;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1092);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1093);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1094);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1095);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1096);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1097);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1098);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1099);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1100);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1101);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1102);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1103);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1104);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1105);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1106);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1107);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1108);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1109);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1110);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1111);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1112);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_1113);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1114);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_1115);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1116);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_1117);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1118);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24], mem_vec_1119);
						}
}
