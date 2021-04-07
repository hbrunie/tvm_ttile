void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))]; T (4, c);
  T (56, x)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, h, hp_0, x, x0, xp_0, x0_p_0, x1_p_0, x1, xp_1, x0_p_1, xp_2, y, yp_0;
IND_TYPE y0 = 0;
IND_TYPE x2 = 0;
IND_TYPE h0 = 0;
IND_TYPE w = 0;
IND_TYPE c1 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_4 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,mem_vec_48 ,mem_vec_49 ,mem_vec_5 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_6 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_135 ,vec_136 ,vec_137 ,vec_138 ,vec_139 ,vec_14 ,vec_140 ,vec_141 ,vec_142 ,vec_143 ,vec_144 ,vec_145 ,vec_146 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
x1 = 0;
x1_p_0 = 0;
c0 = 0;
c0_p_0 = 0;
y = 0;
yp_0 = 0;
x0 = 0;
x0_p_1 = 0;
					for (h = h0, hp_0 = 0;h < h0 + 3;h += 1, hp_0 += 1){
						// y = u_y, x = 2, h = 1, w = 3, c = 8, f = 32
						// T (x, 2) (2 / 1)
						for (x = x0, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;x < x0 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_32 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_33 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_34 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_35 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_36 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_37 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_38 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_39 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_40 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_41 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_42 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_43 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_44 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_45 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_46 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_47 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_48 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_49 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_50 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_51 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									mem_vec_52 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_53 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
									mem_vec_54 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_55 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
									mem_vec_56 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_57 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
									mem_vec_58 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_59 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24]);
									mem_vec_60 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_61 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
									mem_vec_62 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									mem_vec_63 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 24]);
									mem_vec_64 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_65 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
									mem_vec_66 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
									mem_vec_67 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 24]);
									// y = u_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c0, cp_1 = c0_p_0, cp_0 = 0;c < c0 + 8;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_32);
										mem_vec_32 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_33);
										mem_vec_33 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_34);
										mem_vec_34 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_35);
										mem_vec_35 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_36);
										mem_vec_36 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_37);
										mem_vec_37 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_38);
										mem_vec_38 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_39);
										mem_vec_39 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_40);
										mem_vec_40 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_41);
										mem_vec_41 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_42);
										mem_vec_42 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_43);
										mem_vec_43 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_44);
										mem_vec_44 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_45);
										mem_vec_45 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_46);
										mem_vec_46 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_47);
										mem_vec_47 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_48);
										mem_vec_48 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_49);
										mem_vec_49 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_50);
										mem_vec_50 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_51);
										mem_vec_51 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);
										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_52);
										mem_vec_52 = vec_29;
										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_53);
										mem_vec_53 = vec_31;
										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_54);
										mem_vec_54 = vec_32;
										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_55);
										mem_vec_55 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm256_set1_ps(scal_6);
										vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_56);
										mem_vec_56 = vec_34;
										vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_57);
										mem_vec_57 = vec_36;
										vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_58);
										mem_vec_58 = vec_37;
										vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_59);
										mem_vec_59 = vec_38;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_40 = _mm256_set1_ps(scal_7);
										vec_39 = _mm256_fmadd_ps(vec_40, vec_2, mem_vec_60);
										mem_vec_60 = vec_39;
										vec_41 = _mm256_fmadd_ps(vec_40, vec_4, mem_vec_61);
										mem_vec_61 = vec_41;
										vec_42 = _mm256_fmadd_ps(vec_40, vec_6, mem_vec_62);
										mem_vec_62 = vec_42;
										vec_43 = _mm256_fmadd_ps(vec_40, vec_8, mem_vec_63);
										mem_vec_63 = vec_43;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_45 = _mm256_set1_ps(scal_8);
										vec_44 = _mm256_fmadd_ps(vec_45, vec_2, mem_vec_64);
										mem_vec_64 = vec_44;
										vec_46 = _mm256_fmadd_ps(vec_45, vec_4, mem_vec_65);
										mem_vec_65 = vec_46;
										vec_47 = _mm256_fmadd_ps(vec_45, vec_6, mem_vec_66);
										mem_vec_66 = vec_47;
										vec_48 = _mm256_fmadd_ps(vec_45, vec_8, mem_vec_67);
										mem_vec_67 = vec_48;
										scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_50 = _mm256_set1_ps(scal_9);
										vec_51 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_49 = _mm256_fmadd_ps(vec_50, vec_51, mem_vec_32);
										mem_vec_32 = vec_49;
										vec_53 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
										vec_52 = _mm256_fmadd_ps(vec_50, vec_53, mem_vec_33);
										mem_vec_33 = vec_52;
										vec_55 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_54 = _mm256_fmadd_ps(vec_50, vec_55, mem_vec_34);
										mem_vec_34 = vec_54;
										vec_57 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
										vec_56 = _mm256_fmadd_ps(vec_50, vec_57, mem_vec_35);
										mem_vec_35 = vec_56;
										scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_59 = _mm256_set1_ps(scal_10);
										vec_58 = _mm256_fmadd_ps(vec_59, vec_51, mem_vec_36);
										mem_vec_36 = vec_58;
										vec_60 = _mm256_fmadd_ps(vec_59, vec_53, mem_vec_37);
										mem_vec_37 = vec_60;
										vec_61 = _mm256_fmadd_ps(vec_59, vec_55, mem_vec_38);
										mem_vec_38 = vec_61;
										vec_62 = _mm256_fmadd_ps(vec_59, vec_57, mem_vec_39);
										mem_vec_39 = vec_62;
										scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_64 = _mm256_set1_ps(scal_11);
										vec_63 = _mm256_fmadd_ps(vec_64, vec_51, mem_vec_40);
										mem_vec_40 = vec_63;
										vec_65 = _mm256_fmadd_ps(vec_64, vec_53, mem_vec_41);
										mem_vec_41 = vec_65;
										vec_66 = _mm256_fmadd_ps(vec_64, vec_55, mem_vec_42);
										mem_vec_42 = vec_66;
										vec_67 = _mm256_fmadd_ps(vec_64, vec_57, mem_vec_43);
										mem_vec_43 = vec_67;
										scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_69 = _mm256_set1_ps(scal_12);
										vec_68 = _mm256_fmadd_ps(vec_69, vec_51, mem_vec_44);
										mem_vec_44 = vec_68;
										vec_70 = _mm256_fmadd_ps(vec_69, vec_53, mem_vec_45);
										mem_vec_45 = vec_70;
										vec_71 = _mm256_fmadd_ps(vec_69, vec_55, mem_vec_46);
										mem_vec_46 = vec_71;
										vec_72 = _mm256_fmadd_ps(vec_69, vec_57, mem_vec_47);
										mem_vec_47 = vec_72;
										scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
										vec_74 = _mm256_set1_ps(scal_13);
										vec_73 = _mm256_fmadd_ps(vec_74, vec_51, mem_vec_48);
										mem_vec_48 = vec_73;
										vec_75 = _mm256_fmadd_ps(vec_74, vec_53, mem_vec_49);
										mem_vec_49 = vec_75;
										vec_76 = _mm256_fmadd_ps(vec_74, vec_55, mem_vec_50);
										mem_vec_50 = vec_76;
										vec_77 = _mm256_fmadd_ps(vec_74, vec_57, mem_vec_51);
										mem_vec_51 = vec_77;
										scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
										vec_79 = _mm256_set1_ps(scal_14);
										vec_78 = _mm256_fmadd_ps(vec_79, vec_51, mem_vec_52);
										mem_vec_52 = vec_78;
										vec_80 = _mm256_fmadd_ps(vec_79, vec_53, mem_vec_53);
										mem_vec_53 = vec_80;
										vec_81 = _mm256_fmadd_ps(vec_79, vec_55, mem_vec_54);
										mem_vec_54 = vec_81;
										vec_82 = _mm256_fmadd_ps(vec_79, vec_57, mem_vec_55);
										mem_vec_55 = vec_82;
										scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
										vec_84 = _mm256_set1_ps(scal_15);
										vec_83 = _mm256_fmadd_ps(vec_84, vec_51, mem_vec_56);
										mem_vec_56 = vec_83;
										vec_85 = _mm256_fmadd_ps(vec_84, vec_53, mem_vec_57);
										mem_vec_57 = vec_85;
										vec_86 = _mm256_fmadd_ps(vec_84, vec_55, mem_vec_58);
										mem_vec_58 = vec_86;
										vec_87 = _mm256_fmadd_ps(vec_84, vec_57, mem_vec_59);
										mem_vec_59 = vec_87;
										scal_16 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
										vec_89 = _mm256_set1_ps(scal_16);
										vec_88 = _mm256_fmadd_ps(vec_89, vec_51, mem_vec_60);
										mem_vec_60 = vec_88;
										vec_90 = _mm256_fmadd_ps(vec_89, vec_53, mem_vec_61);
										mem_vec_61 = vec_90;
										vec_91 = _mm256_fmadd_ps(vec_89, vec_55, mem_vec_62);
										mem_vec_62 = vec_91;
										vec_92 = _mm256_fmadd_ps(vec_89, vec_57, mem_vec_63);
										mem_vec_63 = vec_92;
										scal_17 = input[strideA1 * (x + w + 1) + strideA2 * (y + 8 + h) + c];
										vec_94 = _mm256_set1_ps(scal_17);
										vec_93 = _mm256_fmadd_ps(vec_94, vec_51, mem_vec_64);
										mem_vec_64 = vec_93;
										vec_95 = _mm256_fmadd_ps(vec_94, vec_53, mem_vec_65);
										mem_vec_65 = vec_95;
										vec_96 = _mm256_fmadd_ps(vec_94, vec_55, mem_vec_66);
										mem_vec_66 = vec_96;
										vec_97 = _mm256_fmadd_ps(vec_94, vec_57, mem_vec_67);
										mem_vec_67 = vec_97;
										scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_99 = _mm256_set1_ps(scal_18);
										vec_100 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_98 = _mm256_fmadd_ps(vec_99, vec_100, mem_vec_32);
										mem_vec_32 = vec_98;
										vec_102 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
										vec_101 = _mm256_fmadd_ps(vec_99, vec_102, mem_vec_33);
										mem_vec_33 = vec_101;
										vec_104 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_103 = _mm256_fmadd_ps(vec_99, vec_104, mem_vec_34);
										mem_vec_34 = vec_103;
										vec_106 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
										vec_105 = _mm256_fmadd_ps(vec_99, vec_106, mem_vec_35);
										mem_vec_35 = vec_105;
										scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_108 = _mm256_set1_ps(scal_19);
										vec_107 = _mm256_fmadd_ps(vec_108, vec_100, mem_vec_36);
										mem_vec_36 = vec_107;
										vec_109 = _mm256_fmadd_ps(vec_108, vec_102, mem_vec_37);
										mem_vec_37 = vec_109;
										vec_110 = _mm256_fmadd_ps(vec_108, vec_104, mem_vec_38);
										mem_vec_38 = vec_110;
										vec_111 = _mm256_fmadd_ps(vec_108, vec_106, mem_vec_39);
										mem_vec_39 = vec_111;
										scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_113 = _mm256_set1_ps(scal_20);
										vec_112 = _mm256_fmadd_ps(vec_113, vec_100, mem_vec_40);
										mem_vec_40 = vec_112;
										vec_114 = _mm256_fmadd_ps(vec_113, vec_102, mem_vec_41);
										mem_vec_41 = vec_114;
										vec_115 = _mm256_fmadd_ps(vec_113, vec_104, mem_vec_42);
										mem_vec_42 = vec_115;
										vec_116 = _mm256_fmadd_ps(vec_113, vec_106, mem_vec_43);
										mem_vec_43 = vec_116;
										scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_118 = _mm256_set1_ps(scal_21);
										vec_117 = _mm256_fmadd_ps(vec_118, vec_100, mem_vec_44);
										mem_vec_44 = vec_117;
										vec_119 = _mm256_fmadd_ps(vec_118, vec_102, mem_vec_45);
										mem_vec_45 = vec_119;
										vec_120 = _mm256_fmadd_ps(vec_118, vec_104, mem_vec_46);
										mem_vec_46 = vec_120;
										vec_121 = _mm256_fmadd_ps(vec_118, vec_106, mem_vec_47);
										mem_vec_47 = vec_121;
										scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
										vec_123 = _mm256_set1_ps(scal_22);
										vec_122 = _mm256_fmadd_ps(vec_123, vec_100, mem_vec_48);
										mem_vec_48 = vec_122;
										vec_124 = _mm256_fmadd_ps(vec_123, vec_102, mem_vec_49);
										mem_vec_49 = vec_124;
										vec_125 = _mm256_fmadd_ps(vec_123, vec_104, mem_vec_50);
										mem_vec_50 = vec_125;
										vec_126 = _mm256_fmadd_ps(vec_123, vec_106, mem_vec_51);
										mem_vec_51 = vec_126;
										scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
										vec_128 = _mm256_set1_ps(scal_23);
										vec_127 = _mm256_fmadd_ps(vec_128, vec_100, mem_vec_52);
										mem_vec_52 = vec_127;
										vec_129 = _mm256_fmadd_ps(vec_128, vec_102, mem_vec_53);
										mem_vec_53 = vec_129;
										vec_130 = _mm256_fmadd_ps(vec_128, vec_104, mem_vec_54);
										mem_vec_54 = vec_130;
										vec_131 = _mm256_fmadd_ps(vec_128, vec_106, mem_vec_55);
										mem_vec_55 = vec_131;
										scal_24 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
										vec_133 = _mm256_set1_ps(scal_24);
										vec_132 = _mm256_fmadd_ps(vec_133, vec_100, mem_vec_56);
										mem_vec_56 = vec_132;
										vec_134 = _mm256_fmadd_ps(vec_133, vec_102, mem_vec_57);
										mem_vec_57 = vec_134;
										vec_135 = _mm256_fmadd_ps(vec_133, vec_104, mem_vec_58);
										mem_vec_58 = vec_135;
										vec_136 = _mm256_fmadd_ps(vec_133, vec_106, mem_vec_59);
										mem_vec_59 = vec_136;
										scal_25 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
										vec_138 = _mm256_set1_ps(scal_25);
										vec_137 = _mm256_fmadd_ps(vec_138, vec_100, mem_vec_60);
										mem_vec_60 = vec_137;
										vec_139 = _mm256_fmadd_ps(vec_138, vec_102, mem_vec_61);
										mem_vec_61 = vec_139;
										vec_140 = _mm256_fmadd_ps(vec_138, vec_104, mem_vec_62);
										mem_vec_62 = vec_140;
										vec_141 = _mm256_fmadd_ps(vec_138, vec_106, mem_vec_63);
										mem_vec_63 = vec_141;
										scal_26 = input[strideA1 * (x + w + 2) + strideA2 * (y + 8 + h) + c];
										vec_143 = _mm256_set1_ps(scal_26);
										vec_142 = _mm256_fmadd_ps(vec_143, vec_100, mem_vec_64);
										mem_vec_64 = vec_142;
										vec_144 = _mm256_fmadd_ps(vec_143, vec_102, mem_vec_65);
										mem_vec_65 = vec_144;
										vec_145 = _mm256_fmadd_ps(vec_143, vec_104, mem_vec_66);
										mem_vec_66 = vec_145;
										vec_146 = _mm256_fmadd_ps(vec_143, vec_106, mem_vec_67);
										mem_vec_67 = vec_146;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_32);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_33);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_34);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_35);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_36);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_37);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_38);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_39);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_40);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_41);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_42);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_43);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_44);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_45);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_46);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_47);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_48);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_49);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_50);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_51);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_52);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_53);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_54);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_55);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_56);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_57);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_58);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24], mem_vec_59);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_60);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_61);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_62);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 24], mem_vec_63);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_64);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_65);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_66);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 24], mem_vec_67);
						}
					}
}
