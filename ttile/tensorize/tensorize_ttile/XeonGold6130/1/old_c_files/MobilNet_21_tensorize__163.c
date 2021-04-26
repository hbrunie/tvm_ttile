
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (28, x);
  T (3, w); T (4, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (1, x)]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, w, wp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0;
IND_TYPE y76 = 0;
IND_TYPE x138 = 0;
IND_TYPE h = 0;
IND_TYPE w67 = 0;
IND_TYPE c109 = 0;
IND_TYPE f63 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,mem_vec_1088 ,mem_vec_1089 ,mem_vec_1090 ,mem_vec_1091 ,mem_vec_1092 ,mem_vec_1093 ,mem_vec_1094 ,mem_vec_1095 ,mem_vec_1096 ,mem_vec_1097 ,mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,mem_vec_1104 ,mem_vec_1105 ,mem_vec_1106 ,mem_vec_1107 ,mem_vec_1108 ,mem_vec_1109 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
x137 = 0;
x137_p_0 = 0;
y = 0;
yp_0 = 0;
x136 = 0;
x136_p_1 = 0;
f = 0;
fp_0 = 0;
c108 = 0;
c108_p_0 = 0;
						for (w = w67, wp_0 = 0;w < w67 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 16, f = 32
							// T (x, 28) (28 / 1)
							for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;x < x136 + 28;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1064 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1065 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1066 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1067 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1068 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1069 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1070 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1071 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1072 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_1073 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_1074 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_1075 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_1076 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_1077 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_1078 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_1079 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_1080 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_1081 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_1082 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_1083 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_1084 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_1085 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c108, cp_1 = c108_p_0, cp_0 = 0;c < c108 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1064);
											mem_vec_1064 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1065);
											mem_vec_1065 = vec_3;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1066);
											mem_vec_1066 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1067);
											mem_vec_1067 = vec_7;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1068);
											mem_vec_1068 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1069);
											mem_vec_1069 = vec_10;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1070);
											mem_vec_1070 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1071);
											mem_vec_1071 = vec_13;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1072);
											mem_vec_1072 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1073);
											mem_vec_1073 = vec_16;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1074);
											mem_vec_1074 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1075);
											mem_vec_1075 = vec_19;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1076);
											mem_vec_1076 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1077);
											mem_vec_1077 = vec_22;
											scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1078);
											mem_vec_1078 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1079);
											mem_vec_1079 = vec_25;
											scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1080);
											mem_vec_1080 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1081);
											mem_vec_1081 = vec_28;
											scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1082);
											mem_vec_1082 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1083);
											mem_vec_1083 = vec_31;
											scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1084);
											mem_vec_1084 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1085);
											mem_vec_1085 = vec_34;
											scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_1064);
											mem_vec_1064 = vec_35;
											vec_39 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_1065);
											mem_vec_1065 = vec_38;
											scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_1066);
											mem_vec_1066 = vec_40;
											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_1067);
											mem_vec_1067 = vec_42;
											scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_1068);
											mem_vec_1068 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_1069);
											mem_vec_1069 = vec_45;
											scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_1070);
											mem_vec_1070 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_1071);
											mem_vec_1071 = vec_48;
											scal_15 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_1072);
											mem_vec_1072 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_1073);
											mem_vec_1073 = vec_51;
											scal_16 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_1074);
											mem_vec_1074 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_1075);
											mem_vec_1075 = vec_54;
											scal_17 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_1076);
											mem_vec_1076 = vec_55;
											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_1077);
											mem_vec_1077 = vec_57;
											scal_18 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_1078);
											mem_vec_1078 = vec_58;
											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_1079);
											mem_vec_1079 = vec_60;
											scal_19 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_1080);
											mem_vec_1080 = vec_61;
											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_1081);
											mem_vec_1081 = vec_63;
											scal_20 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_1082);
											mem_vec_1082 = vec_64;
											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_1083);
											mem_vec_1083 = vec_66;
											scal_21 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_1084);
											mem_vec_1084 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_1085);
											mem_vec_1085 = vec_69;
											scal_22 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_1064);
											mem_vec_1064 = vec_70;
											vec_74 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_1065);
											mem_vec_1065 = vec_73;
											scal_23 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_1066);
											mem_vec_1066 = vec_75;
											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_1067);
											mem_vec_1067 = vec_77;
											scal_24 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_1068);
											mem_vec_1068 = vec_78;
											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_1069);
											mem_vec_1069 = vec_80;
											scal_25 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);
											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_1070);
											mem_vec_1070 = vec_81;
											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_1071);
											mem_vec_1071 = vec_83;
											scal_26 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_1072);
											mem_vec_1072 = vec_84;
											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_1073);
											mem_vec_1073 = vec_86;
											scal_27 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);
											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_1074);
											mem_vec_1074 = vec_87;
											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_1075);
											mem_vec_1075 = vec_89;
											scal_28 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);
											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_1076);
											mem_vec_1076 = vec_90;
											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_1077);
											mem_vec_1077 = vec_92;
											scal_29 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);
											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_1078);
											mem_vec_1078 = vec_93;
											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_1079);
											mem_vec_1079 = vec_95;
											scal_30 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);
											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_1080);
											mem_vec_1080 = vec_96;
											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_1081);
											mem_vec_1081 = vec_98;
											scal_31 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);
											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_1082);
											mem_vec_1082 = vec_99;
											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_1083);
											mem_vec_1083 = vec_101;
											scal_32 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);
											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_1084);
											mem_vec_1084 = vec_102;
											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_1085);
											mem_vec_1085 = vec_104;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1064);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1065);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1066);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1067);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1068);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1069);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1070);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1071);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1072);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1073);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1074);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1075);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1076);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1077);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1078);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1079);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1080);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1081);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1082);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1083);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_1084);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_1085);
							}
						}
}
