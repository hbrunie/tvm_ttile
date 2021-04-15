
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (14, x);
  Lambda_apply y [((Iter 5), (Arg 6)); ((Iter 2), (Arg 13))]; T (2, f);
  T (2, c); T (4, x)]
*/
IND_TYPE c, cp_0, c590_p_0, cp_1, c590, f, fp_0, w, wp_0, x, xp_0, x712_p_0, x713_p_0, xp_1, x712_p_1, xp_2, x712, x713, y, yp_0;
IND_TYPE y372 = 0;
IND_TYPE x714 = 0;
IND_TYPE h = 0;
IND_TYPE w314 = 0;
IND_TYPE c591 = 0;
IND_TYPE f340 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4192 ,mem_vec_4193 ,mem_vec_4194 ,mem_vec_4195 ,mem_vec_4196 ,mem_vec_4197 ,mem_vec_4198 ,mem_vec_4199 ,mem_vec_4200 ,mem_vec_4201 ,mem_vec_4202 ,mem_vec_4203 ,mem_vec_4204 ,mem_vec_4205 ,mem_vec_4206 ,mem_vec_4207 ,mem_vec_4208 ,mem_vec_4209 ,mem_vec_4210 ,mem_vec_4211 ,mem_vec_4212 ,mem_vec_4213 ,mem_vec_4214 ,mem_vec_4215 ,mem_vec_4216 ,mem_vec_4217 ,mem_vec_4218 ,mem_vec_4219 ,mem_vec_4220 ,mem_vec_4221 ,mem_vec_4222 ,mem_vec_4223 ,mem_vec_4224 ,mem_vec_4225 ,mem_vec_4226 ,mem_vec_4227 ,mem_vec_4228 ,mem_vec_4229 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
x713 = 0;
x713_p_0 = 0;
c590 = 0;
c590_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x712 = 0;
x712_p_1 = 0;
						for (w = w314, wp_0 = 0;w < w314 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (x, 1) (1 / 1)
							for (x = x712, xp_2 = x712_p_1, xp_1 = x712_p_0, xp_0 = 0;x < x712 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4192 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4193 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4194 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4195 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4196 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4197 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4198 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4199 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4200 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4201 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4202 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4203 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c590, cp_1 = c590_p_0, cp_0 = 0;c < c590 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4192);
											mem_vec_4192 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4193);
											mem_vec_4193 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4194);
											mem_vec_4194 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4195);
											mem_vec_4195 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4196);
											mem_vec_4196 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4197);
											mem_vec_4197 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4198);
											mem_vec_4198 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4199);
											mem_vec_4199 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4200);
											mem_vec_4200 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4201);
											mem_vec_4201 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4202);
											mem_vec_4202 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4203);
											mem_vec_4203 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_4192);
											mem_vec_4192 = vec_20;
											vec_24 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_4193);
											mem_vec_4193 = vec_23;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_4194);
											mem_vec_4194 = vec_25;
											vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_4195);
											mem_vec_4195 = vec_27;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_4196);
											mem_vec_4196 = vec_28;
											vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_4197);
											mem_vec_4197 = vec_30;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_4198);
											mem_vec_4198 = vec_31;
											vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_4199);
											mem_vec_4199 = vec_33;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_4200);
											mem_vec_4200 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_4201);
											mem_vec_4201 = vec_36;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_4202);
											mem_vec_4202 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_4203);
											mem_vec_4203 = vec_39;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_4192);
											mem_vec_4192 = vec_40;
											vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_4193);
											mem_vec_4193 = vec_43;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_13);
											vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_4194);
											mem_vec_4194 = vec_45;
											vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_4195);
											mem_vec_4195 = vec_47;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_49 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_4196);
											mem_vec_4196 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_4197);
											mem_vec_4197 = vec_50;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_15);
											vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_4198);
											mem_vec_4198 = vec_51;
											vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_4199);
											mem_vec_4199 = vec_53;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_4200);
											mem_vec_4200 = vec_54;
											vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_4201);
											mem_vec_4201 = vec_56;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_4202);
											mem_vec_4202 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_4203);
											mem_vec_4203 = vec_59;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4192);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4193);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4194);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4195);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4196);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4197);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4198);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4199);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4200);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4201);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4202);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4203);
							}
						}
}
