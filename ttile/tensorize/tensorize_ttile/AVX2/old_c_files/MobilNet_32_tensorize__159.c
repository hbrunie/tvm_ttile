void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (28, x); T (4, c); T (8, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]]
*/
IND_TYPE c, cp_0, c788_p_0, c789_p_0, cp_1, c788_p_1, cp_2, c788, c789, f, fp_0, w, wp_0, x, xp_0, x591_p_0, xp_1, x591, y, yp_0;
IND_TYPE y394 = 0;
IND_TYPE x592 = 0;
IND_TYPE h = 0;
IND_TYPE w312 = 0;
IND_TYPE c790 = 0;
IND_TYPE f570 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9000 ,mem_vec_9001 ,mem_vec_9002 ,mem_vec_9003 ,mem_vec_9004 ,mem_vec_9005 ,mem_vec_9006 ,mem_vec_9007 ,mem_vec_9008 ,mem_vec_9009 ,mem_vec_9010 ,mem_vec_9011 ,mem_vec_9012 ,mem_vec_9013 ,mem_vec_9014 ,mem_vec_9015 ,mem_vec_9016 ,mem_vec_9017 ,mem_vec_9018 ,mem_vec_9019 ,mem_vec_9020 ,mem_vec_9021 ,mem_vec_9022 ,mem_vec_9023 ,mem_vec_9024 ,mem_vec_9025 ,mem_vec_9026 ,mem_vec_9027 ,mem_vec_9028 ,mem_vec_9029 ,mem_vec_9030 ,mem_vec_9031 ,mem_vec_9032 ,mem_vec_9033 ,mem_vec_9034 ,mem_vec_9035 ,mem_vec_9036 ,mem_vec_9037 ,mem_vec_9038 ,mem_vec_9039 ,mem_vec_9040 ,mem_vec_9041 ,mem_vec_9042 ,mem_vec_9043 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
y = 0;
yp_0 = 0;
x591 = 0;
x591_p_0 = 0;
c789 = 0;
c789_p_0 = 0;
f = 0;
fp_0 = 0;
c788 = 0;
c788_p_1 = 0;
x = 0;
xp_1 = 0;
							for (w = w312, wp_0 = 0;w < w312 + 3;w += 1, wp_0 += 1){
										mem_vec_9020 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_9021 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_9022 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_9023 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_9024 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_9025 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_9026 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_9027 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_9028 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_9029 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_9030 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_9031 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_9032 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_9033 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_9034 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_9035 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										mem_vec_9036 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_9037 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
										mem_vec_9038 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_9039 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
										mem_vec_9040 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_9041 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8]);
										mem_vec_9042 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_9043 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c788, cp_2 = c788_p_1, cp_1 = c788_p_0, cp_0 = 0;c < c788 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9020);
											mem_vec_9020 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9021);
											mem_vec_9021 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9022);
											mem_vec_9022 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9023);
											mem_vec_9023 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9024);
											mem_vec_9024 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9025);
											mem_vec_9025 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9026);
											mem_vec_9026 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9027);
											mem_vec_9027 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9028);
											mem_vec_9028 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9029);
											mem_vec_9029 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9030);
											mem_vec_9030 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9031);
											mem_vec_9031 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9032);
											mem_vec_9032 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9033);
											mem_vec_9033 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9034);
											mem_vec_9034 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9035);
											mem_vec_9035 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9036);
											mem_vec_9036 = vec_26;
											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9037);
											mem_vec_9037 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);
											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9038);
											mem_vec_9038 = vec_29;
											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9039);
											mem_vec_9039 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_9040);
											mem_vec_9040 = vec_32;
											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_9041);
											mem_vec_9041 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);
											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_9042);
											mem_vec_9042 = vec_35;
											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_9043);
											mem_vec_9043 = vec_37;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_9020);
											mem_vec_9020 = vec_38;
											vec_42 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_9021);
											mem_vec_9021 = vec_41;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_9022);
											mem_vec_9022 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_9023);
											mem_vec_9023 = vec_45;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_9024);
											mem_vec_9024 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_9025);
											mem_vec_9025 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_9026);
											mem_vec_9026 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_9027);
											mem_vec_9027 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_9028);
											mem_vec_9028 = vec_52;
											vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_9029);
											mem_vec_9029 = vec_54;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);
											vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_9030);
											mem_vec_9030 = vec_55;
											vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_9031);
											mem_vec_9031 = vec_57;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);
											vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_9032);
											mem_vec_9032 = vec_58;
											vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_9033);
											mem_vec_9033 = vec_60;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);
											vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_9034);
											mem_vec_9034 = vec_61;
											vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_9035);
											mem_vec_9035 = vec_63;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_9036);
											mem_vec_9036 = vec_64;
											vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_9037);
											mem_vec_9037 = vec_66;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_9038);
											mem_vec_9038 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_9039);
											mem_vec_9039 = vec_69;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);
											vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_9040);
											mem_vec_9040 = vec_70;
											vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_9041);
											mem_vec_9041 = vec_72;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);
											vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_9042);
											mem_vec_9042 = vec_73;
											vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_9043);
											mem_vec_9043 = vec_75;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_77 = _mm256_set1_ps(scal_24);
											vec_78 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_9020);
											mem_vec_9020 = vec_76;
											vec_80 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_9021);
											mem_vec_9021 = vec_79;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);
											vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_9022);
											mem_vec_9022 = vec_81;
											vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_9023);
											mem_vec_9023 = vec_83;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_9024);
											mem_vec_9024 = vec_84;
											vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_9025);
											mem_vec_9025 = vec_86;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);
											vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_9026);
											mem_vec_9026 = vec_87;
											vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_9027);
											mem_vec_9027 = vec_89;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);
											vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_9028);
											mem_vec_9028 = vec_90;
											vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_9029);
											mem_vec_9029 = vec_92;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);
											vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_9030);
											mem_vec_9030 = vec_93;
											vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_9031);
											mem_vec_9031 = vec_95;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);
											vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_9032);
											mem_vec_9032 = vec_96;
											vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_9033);
											mem_vec_9033 = vec_98;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);
											vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_9034);
											mem_vec_9034 = vec_99;
											vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_9035);
											mem_vec_9035 = vec_101;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);
											vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_9036);
											mem_vec_9036 = vec_102;
											vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_9037);
											mem_vec_9037 = vec_104;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);
											vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_9038);
											mem_vec_9038 = vec_105;
											vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_9039);
											mem_vec_9039 = vec_107;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);
											vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_9040);
											mem_vec_9040 = vec_108;
											vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_9041);
											mem_vec_9041 = vec_110;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);
											vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_9042);
											mem_vec_9042 = vec_111;
											vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_9043);
											mem_vec_9043 = vec_113;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_9020);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_9021);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_9022);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_9023);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9024);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_9025);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9026);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_9027);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_9028);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_9029);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_9030);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_9031);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_9032);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_9033);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_9034);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_9035);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_9036);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_9037);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_9038);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_9039);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_9040);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8], mem_vec_9041);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_9042);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 8], mem_vec_9043);
							}
}
