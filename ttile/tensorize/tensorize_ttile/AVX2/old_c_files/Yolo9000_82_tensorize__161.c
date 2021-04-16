void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (3, w);
  T (68, x); T (1, c); T (16, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (1, c)]
*/
IND_TYPE c, cp_0, c24_p_0, c25_p_0, c26_p_0, cp_1, c24_p_1, c25_p_1, cp_2, c24_p_2, cp_3, c24, c25, c26, f, fp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h = 0;
IND_TYPE w6 = 0;
IND_TYPE c27 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
c26 = 0;
c26_p_0 = 0;
y = 0;
yp_0 = 0;
x18 = 0;
x18_p_0 = 0;
c25 = 0;
c25_p_1 = 0;
f = 0;
fp_0 = 0;
c24 = 0;
c24_p_2 = 0;
x = 0;
xp_1 = 0;
								for (w = w6, wp_0 = 0;w < w6 + 3;w += 1, wp_0 += 1){
											mem_vec_208 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_209 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_210 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_211 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_212 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_213 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_214 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_215 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_216 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_217 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_218 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_219 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_220 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_221 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_222 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_223 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_224 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_225 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											mem_vec_226 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_227 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
											mem_vec_228 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_229 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8]);
											mem_vec_230 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_231 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
											// T (c, 128) (128 / 1)
											for (c = c24, cp_3 = c24_p_2, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;c < c24 + 128;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_208);
												mem_vec_208 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_209);
												mem_vec_209 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_210);
												mem_vec_210 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_211);
												mem_vec_211 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_212);
												mem_vec_212 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_213);
												mem_vec_213 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_214);
												mem_vec_214 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_215);
												mem_vec_215 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_216);
												mem_vec_216 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_217);
												mem_vec_217 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_218);
												mem_vec_218 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_219);
												mem_vec_219 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_220);
												mem_vec_220 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_221);
												mem_vec_221 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_222);
												mem_vec_222 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_223);
												mem_vec_223 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_224);
												mem_vec_224 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_225);
												mem_vec_225 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_226);
												mem_vec_226 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_227);
												mem_vec_227 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_228);
												mem_vec_228 = vec_32;
												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_229);
												mem_vec_229 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_230);
												mem_vec_230 = vec_35;
												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_231);
												mem_vec_231 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_208);
												mem_vec_208 = vec_38;
												vec_42 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_209);
												mem_vec_209 = vec_41;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_210);
												mem_vec_210 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_211);
												mem_vec_211 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_212);
												mem_vec_212 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_213);
												mem_vec_213 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_214);
												mem_vec_214 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_215);
												mem_vec_215 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_216);
												mem_vec_216 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_217);
												mem_vec_217 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_218);
												mem_vec_218 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_219);
												mem_vec_219 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_220);
												mem_vec_220 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_221);
												mem_vec_221 = vec_60;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);
												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_222);
												mem_vec_222 = vec_61;
												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_223);
												mem_vec_223 = vec_63;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_224);
												mem_vec_224 = vec_64;
												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_225);
												mem_vec_225 = vec_66;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_226);
												mem_vec_226 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_227);
												mem_vec_227 = vec_69;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_228);
												mem_vec_228 = vec_70;
												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_229);
												mem_vec_229 = vec_72;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);
												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_230);
												mem_vec_230 = vec_73;
												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_231);
												mem_vec_231 = vec_75;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_208);
												mem_vec_208 = vec_76;
												vec_80 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_209);
												mem_vec_209 = vec_79;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_210);
												mem_vec_210 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_211);
												mem_vec_211 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_212);
												mem_vec_212 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_213);
												mem_vec_213 = vec_86;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_214);
												mem_vec_214 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_215);
												mem_vec_215 = vec_89;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);
												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_216);
												mem_vec_216 = vec_90;
												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_217);
												mem_vec_217 = vec_92;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);
												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_218);
												mem_vec_218 = vec_93;
												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_219);
												mem_vec_219 = vec_95;
												scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);
												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_220);
												mem_vec_220 = vec_96;
												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_221);
												mem_vec_221 = vec_98;
												scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);
												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_222);
												mem_vec_222 = vec_99;
												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_223);
												mem_vec_223 = vec_101;
												scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);
												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_224);
												mem_vec_224 = vec_102;
												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_225);
												mem_vec_225 = vec_104;
												scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);
												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_226);
												mem_vec_226 = vec_105;
												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_227);
												mem_vec_227 = vec_107;
												scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);
												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_228);
												mem_vec_228 = vec_108;
												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_229);
												mem_vec_229 = vec_110;
												scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);
												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_230);
												mem_vec_230 = vec_111;
												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_231);
												mem_vec_231 = vec_113;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_208);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_209);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_210);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_211);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_212);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_213);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_214);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_215);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_216);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_217);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_218);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_219);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_220);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_221);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_222);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_223);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_224);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_225);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_226);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_227);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_228);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8], mem_vec_229);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_230);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8], mem_vec_231);
								}
}
