void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))];
  T (4, f); T (8, c); T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c364_p_0, cp_1, c364, f, fp_0, f392_p_0, f393_p_0, fp_1, f392_p_1, fp_2, f392, f393, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y236 = 0;
IND_TYPE x216 = 0;
IND_TYPE h = 0;
IND_TYPE w190 = 0;
IND_TYPE c365 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4236 ,mem_vec_4237 ,mem_vec_4238 ,mem_vec_4239 ,mem_vec_4240 ,mem_vec_4241 ,mem_vec_4242 ,mem_vec_4243 ,mem_vec_4244 ,mem_vec_4245 ,mem_vec_4246 ,mem_vec_4247 ,mem_vec_4248 ,mem_vec_4249 ,mem_vec_4250 ,mem_vec_4251 ,mem_vec_4252 ,mem_vec_4253 ,mem_vec_4254 ,mem_vec_4255 ,mem_vec_4256 ,mem_vec_4257 ,mem_vec_4258 ,mem_vec_4259 ,mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,mem_vec_4280 ,mem_vec_4281 ,mem_vec_4282 ,mem_vec_4283 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
f393 = 0;
f393_p_0 = 0;
f392 = 0;
f392_p_1 = 0;
c364 = 0;
c364_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (w = w190, wp_0 = 0;w < w190 + 3;w += 1, wp_0 += 1){
										mem_vec_4256 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4257 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_4258 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4259 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_4260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_4262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_4264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_4266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_4268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_4270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										mem_vec_4272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_4274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
										mem_vec_4276 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4277 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_4278 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4279 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
										mem_vec_4280 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4281 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_4282 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4283 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c364, cp_1 = c364_p_0, cp_0 = 0;c < c364 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4256);
											mem_vec_4256 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4257);
											mem_vec_4257 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4258);
											mem_vec_4258 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4259);
											mem_vec_4259 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4260);
											mem_vec_4260 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4261);
											mem_vec_4261 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4262);
											mem_vec_4262 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4263);
											mem_vec_4263 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4264);
											mem_vec_4264 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4265);
											mem_vec_4265 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4266);
											mem_vec_4266 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4267);
											mem_vec_4267 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4268);
											mem_vec_4268 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4269);
											mem_vec_4269 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4270);
											mem_vec_4270 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4271);
											mem_vec_4271 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4272);
											mem_vec_4272 = vec_24;
											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4273);
											mem_vec_4273 = vec_26;
											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4274);
											mem_vec_4274 = vec_27;
											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4275);
											mem_vec_4275 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4276);
											mem_vec_4276 = vec_29;
											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4277);
											mem_vec_4277 = vec_31;
											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_4278);
											mem_vec_4278 = vec_32;
											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_4279);
											mem_vec_4279 = vec_33;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_4280);
											mem_vec_4280 = vec_34;
											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_4281);
											mem_vec_4281 = vec_36;
											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_4282);
											mem_vec_4282 = vec_37;
											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_4283);
											mem_vec_4283 = vec_38;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_4256);
											mem_vec_4256 = vec_39;
											vec_43 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_4257);
											mem_vec_4257 = vec_42;
											vec_45 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_4258);
											mem_vec_4258 = vec_44;
											vec_47 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_4259);
											mem_vec_4259 = vec_46;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_4260);
											mem_vec_4260 = vec_48;
											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_4261);
											mem_vec_4261 = vec_50;
											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_4262);
											mem_vec_4262 = vec_51;
											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_4263);
											mem_vec_4263 = vec_52;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);
											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_4264);
											mem_vec_4264 = vec_53;
											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_4265);
											mem_vec_4265 = vec_55;
											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_4266);
											mem_vec_4266 = vec_56;
											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_4267);
											mem_vec_4267 = vec_57;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_4268);
											mem_vec_4268 = vec_58;
											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_4269);
											mem_vec_4269 = vec_60;
											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_4270);
											mem_vec_4270 = vec_61;
											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_4271);
											mem_vec_4271 = vec_62;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);
											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_4272);
											mem_vec_4272 = vec_63;
											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_4273);
											mem_vec_4273 = vec_65;
											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_4274);
											mem_vec_4274 = vec_66;
											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_4275);
											mem_vec_4275 = vec_67;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_4276);
											mem_vec_4276 = vec_68;
											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_4277);
											mem_vec_4277 = vec_70;
											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_4278);
											mem_vec_4278 = vec_71;
											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_4279);
											mem_vec_4279 = vec_72;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);
											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_4280);
											mem_vec_4280 = vec_73;
											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_4281);
											mem_vec_4281 = vec_75;
											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_4282);
											mem_vec_4282 = vec_76;
											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_4283);
											mem_vec_4283 = vec_77;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_4256);
											mem_vec_4256 = vec_78;
											vec_82 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_4257);
											mem_vec_4257 = vec_81;
											vec_84 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_4258);
											mem_vec_4258 = vec_83;
											vec_86 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_4259);
											mem_vec_4259 = vec_85;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);
											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_4260);
											mem_vec_4260 = vec_87;
											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_4261);
											mem_vec_4261 = vec_89;
											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_4262);
											mem_vec_4262 = vec_90;
											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_4263);
											mem_vec_4263 = vec_91;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);
											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_4264);
											mem_vec_4264 = vec_92;
											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_4265);
											mem_vec_4265 = vec_94;
											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_4266);
											mem_vec_4266 = vec_95;
											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_4267);
											mem_vec_4267 = vec_96;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);
											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_4268);
											mem_vec_4268 = vec_97;
											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_4269);
											mem_vec_4269 = vec_99;
											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_4270);
											mem_vec_4270 = vec_100;
											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_4271);
											mem_vec_4271 = vec_101;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);
											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_4272);
											mem_vec_4272 = vec_102;
											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_4273);
											mem_vec_4273 = vec_104;
											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_4274);
											mem_vec_4274 = vec_105;
											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_4275);
											mem_vec_4275 = vec_106;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);
											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_4276);
											mem_vec_4276 = vec_107;
											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_4277);
											mem_vec_4277 = vec_109;
											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_4278);
											mem_vec_4278 = vec_110;
											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_4279);
											mem_vec_4279 = vec_111;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);
											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_4280);
											mem_vec_4280 = vec_112;
											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_4281);
											mem_vec_4281 = vec_114;
											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_4282);
											mem_vec_4282 = vec_115;
											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_4283);
											mem_vec_4283 = vec_116;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4256);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4257);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4258);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4259);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4260);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4261);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4262);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4263);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4264);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4265);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4266);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4267);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4268);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4269);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4270);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4271);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4272);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4273);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4274);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_4275);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4276);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_4277);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4278);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_4279);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4280);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_4281);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4282);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24], mem_vec_4283);
							}
}
