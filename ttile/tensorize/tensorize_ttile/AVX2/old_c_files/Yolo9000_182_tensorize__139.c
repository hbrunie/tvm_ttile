void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (8, c); T (16, f); T (1, f)]
*/
IND_TYPE c, cp_0, c615_p_0, cp_1, c615, f, fp_0, f680_p_0, f681_p_0, fp_1, f680_p_1, fp_2, f680, f681, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y400 = 0;
IND_TYPE x370 = 0;
IND_TYPE h254 = 0;
IND_TYPE w = 0;
IND_TYPE c616 = 0;
IND_TYPE f682 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,mem_vec_7300 ,mem_vec_7301 ,mem_vec_7302 ,mem_vec_7303 ,mem_vec_7304 ,mem_vec_7305 ,mem_vec_7306 ,mem_vec_7307 ,mem_vec_7308 ,mem_vec_7309 ,mem_vec_7310 ,mem_vec_7311 ,mem_vec_7312 ,mem_vec_7313 ,mem_vec_7314 ,mem_vec_7315 ,mem_vec_7316 ,mem_vec_7317 ,mem_vec_7318 ,mem_vec_7319 ,mem_vec_7320 ,mem_vec_7321 ,mem_vec_7322 ,mem_vec_7323 ,mem_vec_7324 ,mem_vec_7325 ,mem_vec_7326 ,mem_vec_7327 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
f681 = 0;
f681_p_0 = 0;
f680 = 0;
f680_p_1 = 0;
c615 = 0;
c615_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (h = h254, hp_0 = 0;h < h254 + 3;h += 1, hp_0 += 1){
										mem_vec_7308 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7309 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_7310 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_7311 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_7312 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7313 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_7314 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_7315 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_7316 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7317 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_7318 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_7319 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_7320 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7321 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_7322 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_7323 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										mem_vec_7324 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7325 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_7326 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_7327 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c615, cp_1 = c615_p_0, cp_0 = 0;c < c615 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7308);
											mem_vec_7308 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7309);
											mem_vec_7309 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7310);
											mem_vec_7310 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7311);
											mem_vec_7311 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7312);
											mem_vec_7312 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7313);
											mem_vec_7313 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7314);
											mem_vec_7314 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7315);
											mem_vec_7315 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7316);
											mem_vec_7316 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7317);
											mem_vec_7317 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7318);
											mem_vec_7318 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7319);
											mem_vec_7319 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7320);
											mem_vec_7320 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7321);
											mem_vec_7321 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7322);
											mem_vec_7322 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7323);
											mem_vec_7323 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7324);
											mem_vec_7324 = vec_24;
											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7325);
											mem_vec_7325 = vec_26;
											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7326);
											mem_vec_7326 = vec_27;
											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7327);
											mem_vec_7327 = vec_28;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_7308);
											mem_vec_7308 = vec_29;
											vec_33 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_7309);
											mem_vec_7309 = vec_32;
											vec_35 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_7310);
											mem_vec_7310 = vec_34;
											vec_37 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_7311);
											mem_vec_7311 = vec_36;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_7312);
											mem_vec_7312 = vec_38;
											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_7313);
											mem_vec_7313 = vec_40;
											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_7314);
											mem_vec_7314 = vec_41;
											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_7315);
											mem_vec_7315 = vec_42;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_7316);
											mem_vec_7316 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_7317);
											mem_vec_7317 = vec_45;
											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_7318);
											mem_vec_7318 = vec_46;
											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_7319);
											mem_vec_7319 = vec_47;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_7320);
											mem_vec_7320 = vec_48;
											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_7321);
											mem_vec_7321 = vec_50;
											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_7322);
											mem_vec_7322 = vec_51;
											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_7323);
											mem_vec_7323 = vec_52;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);
											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_7324);
											mem_vec_7324 = vec_53;
											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_7325);
											mem_vec_7325 = vec_55;
											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_7326);
											mem_vec_7326 = vec_56;
											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_7327);
											mem_vec_7327 = vec_57;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_7308);
											mem_vec_7308 = vec_58;
											vec_62 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_7309);
											mem_vec_7309 = vec_61;
											vec_64 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_7310);
											mem_vec_7310 = vec_63;
											vec_66 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_7311);
											mem_vec_7311 = vec_65;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_7312);
											mem_vec_7312 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_7313);
											mem_vec_7313 = vec_69;
											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_7314);
											mem_vec_7314 = vec_70;
											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_7315);
											mem_vec_7315 = vec_71;
											scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);
											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_7316);
											mem_vec_7316 = vec_72;
											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_7317);
											mem_vec_7317 = vec_74;
											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_7318);
											mem_vec_7318 = vec_75;
											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_7319);
											mem_vec_7319 = vec_76;
											scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);
											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_7320);
											mem_vec_7320 = vec_77;
											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_7321);
											mem_vec_7321 = vec_79;
											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_7322);
											mem_vec_7322 = vec_80;
											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_7323);
											mem_vec_7323 = vec_81;
											scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);
											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_7324);
											mem_vec_7324 = vec_82;
											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_7325);
											mem_vec_7325 = vec_84;
											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_7326);
											mem_vec_7326 = vec_85;
											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_7327);
											mem_vec_7327 = vec_86;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7308);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7309);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7310);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_7311);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7312);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7313);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7314);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_7315);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7316);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7317);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7318);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_7319);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7320);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7321);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7322);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_7323);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7324);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_7325);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7326);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_7327);
							}
}
