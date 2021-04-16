
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (3, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (2, x);
  Lambda_apply y [((Iter 11), (Arg 10)); ((Iter 2), (Arg 13))]; T (272, x);
  T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, w, wp_0, x, xp_0, x576_p_0, x577_p_0, xp_1, x576_p_1, xp_2, x576, x577, y, yp_0, y628_p_0, yp_1, y628;
IND_TYPE y629 = 0;
IND_TYPE x578 = 0;
IND_TYPE h = 0;
IND_TYPE w310 = 0;
IND_TYPE c456 = 0;
IND_TYPE f232 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4128 ,mem_vec_4129 ,mem_vec_4130 ,mem_vec_4131 ,mem_vec_4132 ,mem_vec_4133 ,mem_vec_4134 ,mem_vec_4135 ,mem_vec_4136 ,mem_vec_4137 ,mem_vec_4138 ,mem_vec_4139 ,mem_vec_4140 ,mem_vec_4141 ,mem_vec_4142 ,mem_vec_4143 ,mem_vec_4144 ,mem_vec_4145 ,mem_vec_4146 ,mem_vec_4147 ,mem_vec_4148 ,mem_vec_4149 ,mem_vec_4150 ,mem_vec_4151 ,mem_vec_4152 ,mem_vec_4153 ,mem_vec_4154 ,mem_vec_4155 ,mem_vec_4156 ,mem_vec_4157 ,mem_vec_4158 ,mem_vec_4159 ,mem_vec_4160 ,mem_vec_4161 ,mem_vec_4162 ,mem_vec_4163 ,mem_vec_4164 ,mem_vec_4165 ,mem_vec_4166 ,mem_vec_4167 ,mem_vec_4168 ,mem_vec_4169 ,mem_vec_4170 ,mem_vec_4171 ,mem_vec_4172 ,mem_vec_4173 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
y628 = 0;
y628_p_0 = 0;
	for (x577 = x578, x577_p_0 = 0;x577 < x578 + 544;x577 += 2, x577_p_0 += 2){
			for (y = y628, yp_1 = y628_p_0, yp_0 = 0;y < y628 + 110;y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (x, 2) (2 / 1)
				for (x576 = x577, x576_p_1 = x577_p_0, x576_p_0 = 0;x576 < x577 + 2;x576 += 1, x576_p_1 += 1, x576_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (f, 2) (32 / 16)
					for (f = f232, fp_0 = 0;f < f232 + 32;f += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 16
						// T (w, 3) (3 / 1)
						for (w = w310, wp_0 = 0;w < w310 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 3, f = 16
							// T (x, 1) (1 / 1)
							for (x = x576, xp_2 = x576_p_1, xp_1 = x576_p_0, xp_0 = 0;x < x576 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4128 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4129 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_4130 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4131 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_4132 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4133 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_4134 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4135 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_4136 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4137 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_4138 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4139 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_4140 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4141 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_4142 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4143 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										mem_vec_4144 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4145 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
										mem_vec_4146 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4147 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 3, f = 16
										// T (c, 3) (3 / 1)
										for (c = c456, cp_0 = 0;c < c456 + 3;c += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4128);
											mem_vec_4128 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4129);
											mem_vec_4129 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4130);
											mem_vec_4130 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4131);
											mem_vec_4131 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4132);
											mem_vec_4132 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4133);
											mem_vec_4133 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4134);
											mem_vec_4134 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4135);
											mem_vec_4135 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4136);
											mem_vec_4136 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4137);
											mem_vec_4137 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4138);
											mem_vec_4138 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4139);
											mem_vec_4139 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4140);
											mem_vec_4140 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4141);
											mem_vec_4141 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4142);
											mem_vec_4142 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4143);
											mem_vec_4143 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4144);
											mem_vec_4144 = vec_26;
											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4145);
											mem_vec_4145 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);
											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4146);
											mem_vec_4146 = vec_29;
											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4147);
											mem_vec_4147 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_4128);
											mem_vec_4128 = vec_32;
											vec_36 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_4129);
											mem_vec_4129 = vec_35;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_4130);
											mem_vec_4130 = vec_37;
											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_4131);
											mem_vec_4131 = vec_39;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_4132);
											mem_vec_4132 = vec_40;
											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_4133);
											mem_vec_4133 = vec_42;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_4134);
											mem_vec_4134 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_4135);
											mem_vec_4135 = vec_45;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_4136);
											mem_vec_4136 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_4137);
											mem_vec_4137 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_4138);
											mem_vec_4138 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_4139);
											mem_vec_4139 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_4140);
											mem_vec_4140 = vec_52;
											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_4141);
											mem_vec_4141 = vec_54;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);
											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_4142);
											mem_vec_4142 = vec_55;
											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_4143);
											mem_vec_4143 = vec_57;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);
											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_4144);
											mem_vec_4144 = vec_58;
											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_4145);
											mem_vec_4145 = vec_60;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);
											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_4146);
											mem_vec_4146 = vec_61;
											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_4147);
											mem_vec_4147 = vec_63;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_4128);
											mem_vec_4128 = vec_64;
											vec_68 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_4129);
											mem_vec_4129 = vec_67;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);
											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_4130);
											mem_vec_4130 = vec_69;
											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_4131);
											mem_vec_4131 = vec_71;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4132);
											mem_vec_4132 = vec_72;
											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_4133);
											mem_vec_4133 = vec_74;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);
											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_4134);
											mem_vec_4134 = vec_75;
											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_4135);
											mem_vec_4135 = vec_77;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);
											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_4136);
											mem_vec_4136 = vec_78;
											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_4137);
											mem_vec_4137 = vec_80;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);
											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_4138);
											mem_vec_4138 = vec_81;
											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_4139);
											mem_vec_4139 = vec_83;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_4140);
											mem_vec_4140 = vec_84;
											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_4141);
											mem_vec_4141 = vec_86;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);
											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_4142);
											mem_vec_4142 = vec_87;
											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_4143);
											mem_vec_4143 = vec_89;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);
											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_4144);
											mem_vec_4144 = vec_90;
											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_4145);
											mem_vec_4145 = vec_92;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);
											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_4146);
											mem_vec_4146 = vec_93;
											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_4147);
											mem_vec_4147 = vec_95;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4128);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4129);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4130);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4131);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4132);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4133);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4134);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4135);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4136);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4137);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4138);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_4139);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4140);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_4141);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4142);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_4143);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4144);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_4145);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4146);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_4147);
							}
						}
					}
				}
			}
			for (y = y628 + 110, yp_1 = y628_p_0, yp_0 = 0;y < y628 + 110 + 26;y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (x, 2) (2 / 1)
				for (x576 = x577, x576_p_1 = x577_p_0, x576_p_0 = 0;x576 < x577 + 2;x576 += 1, x576_p_1 += 1, x576_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (f, 2) (32 / 16)
					for (f = f232, fp_0 = 0;f < f232 + 32;f += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 16
						// T (w, 3) (3 / 1)
						for (w = w310, wp_0 = 0;w < w310 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 3, f = 16
							// T (x, 1) (1 / 1)
							for (x = x576, xp_2 = x576_p_1, xp_1 = x576_p_0, xp_0 = 0;x < x576 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4148 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4149 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_4150 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4151 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_4152 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4153 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_4154 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4155 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_4156 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4157 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_4158 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4159 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_4160 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4161 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_4162 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4163 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										mem_vec_4164 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4165 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
										mem_vec_4166 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4167 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
										mem_vec_4168 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4169 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8]);
										mem_vec_4170 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_4171 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8]);
										mem_vec_4172 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_4173 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 3, f = 16
										// T (c, 3) (3 / 1)
										for (c = c456, cp_0 = 0;c < c456 + 3;c += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4148);
											mem_vec_4148 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4149);
											mem_vec_4149 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4150);
											mem_vec_4150 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4151);
											mem_vec_4151 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4152);
											mem_vec_4152 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4153);
											mem_vec_4153 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4154);
											mem_vec_4154 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4155);
											mem_vec_4155 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4156);
											mem_vec_4156 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4157);
											mem_vec_4157 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4158);
											mem_vec_4158 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4159);
											mem_vec_4159 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4160);
											mem_vec_4160 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4161);
											mem_vec_4161 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4162);
											mem_vec_4162 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4163);
											mem_vec_4163 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4164);
											mem_vec_4164 = vec_26;
											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4165);
											mem_vec_4165 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);
											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4166);
											mem_vec_4166 = vec_29;
											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4167);
											mem_vec_4167 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_4168);
											mem_vec_4168 = vec_32;
											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_4169);
											mem_vec_4169 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);
											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_4170);
											mem_vec_4170 = vec_35;
											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_4171);
											mem_vec_4171 = vec_37;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_4172);
											mem_vec_4172 = vec_38;
											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_4173);
											mem_vec_4173 = vec_40;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_42 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_4148);
											mem_vec_4148 = vec_41;
											vec_45 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_4149);
											mem_vec_4149 = vec_44;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_4150);
											mem_vec_4150 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_4151);
											mem_vec_4151 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_4152);
											mem_vec_4152 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_4153);
											mem_vec_4153 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_4154);
											mem_vec_4154 = vec_52;
											vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_4155);
											mem_vec_4155 = vec_54;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);
											vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_4156);
											mem_vec_4156 = vec_55;
											vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_4157);
											mem_vec_4157 = vec_57;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);
											vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_4158);
											mem_vec_4158 = vec_58;
											vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_4159);
											mem_vec_4159 = vec_60;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);
											vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_4160);
											mem_vec_4160 = vec_61;
											vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_4161);
											mem_vec_4161 = vec_63;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_4162);
											mem_vec_4162 = vec_64;
											vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_4163);
											mem_vec_4163 = vec_66;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_4164);
											mem_vec_4164 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_4165);
											mem_vec_4165 = vec_69;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);
											vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_4166);
											mem_vec_4166 = vec_70;
											vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_4167);
											mem_vec_4167 = vec_72;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);
											vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_4168);
											mem_vec_4168 = vec_73;
											vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_4169);
											mem_vec_4169 = vec_75;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);
											vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_4170);
											mem_vec_4170 = vec_76;
											vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_4171);
											mem_vec_4171 = vec_78;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);
											vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_4172);
											mem_vec_4172 = vec_79;
											vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_4173);
											mem_vec_4173 = vec_81;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_4148);
											mem_vec_4148 = vec_82;
											vec_86 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_4149);
											mem_vec_4149 = vec_85;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);
											vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_4150);
											mem_vec_4150 = vec_87;
											vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_4151);
											mem_vec_4151 = vec_89;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);
											vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_4152);
											mem_vec_4152 = vec_90;
											vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_4153);
											mem_vec_4153 = vec_92;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);
											vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_4154);
											mem_vec_4154 = vec_93;
											vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_4155);
											mem_vec_4155 = vec_95;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);
											vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_4156);
											mem_vec_4156 = vec_96;
											vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_4157);
											mem_vec_4157 = vec_98;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);
											vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_4158);
											mem_vec_4158 = vec_99;
											vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_4159);
											mem_vec_4159 = vec_101;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);
											vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_4160);
											mem_vec_4160 = vec_102;
											vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_4161);
											mem_vec_4161 = vec_104;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);
											vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_4162);
											mem_vec_4162 = vec_105;
											vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_4163);
											mem_vec_4163 = vec_107;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);
											vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_4164);
											mem_vec_4164 = vec_108;
											vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_4165);
											mem_vec_4165 = vec_110;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);
											vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_4166);
											mem_vec_4166 = vec_111;
											vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_4167);
											mem_vec_4167 = vec_113;
											scal_36 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);
											vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_4168);
											mem_vec_4168 = vec_114;
											vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_4169);
											mem_vec_4169 = vec_116;
											scal_37 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);
											vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_4170);
											mem_vec_4170 = vec_117;
											vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_4171);
											mem_vec_4171 = vec_119;
											scal_38 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);
											vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_4172);
											mem_vec_4172 = vec_120;
											vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_4173);
											mem_vec_4173 = vec_122;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4148);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4149);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4150);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4151);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4152);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4153);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4154);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4155);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4156);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4157);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4158);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_4159);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4160);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_4161);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4162);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_4163);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4164);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_4165);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4166);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_4167);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4168);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8], mem_vec_4169);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4170);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8], mem_vec_4171);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4172);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 8], mem_vec_4173);
							}
						}
					}
				}
			}
	}
}
