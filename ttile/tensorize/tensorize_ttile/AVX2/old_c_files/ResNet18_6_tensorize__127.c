
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (8, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (16, c); T (7, y); T (1, f); T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c683_p_0, c684_p_0, cp_1, c683_p_1, cp_2, c683, c684, f, fp_0, f685_p_0, fp_1, f685, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y361 = 0;
IND_TYPE x348 = 0;
IND_TYPE h273 = 0;
IND_TYPE w = 0;
IND_TYPE c685 = 0;
IND_TYPE f686 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4400 ,mem_vec_4401 ,mem_vec_4402 ,mem_vec_4403 ,mem_vec_4404 ,mem_vec_4405 ,mem_vec_4406 ,mem_vec_4407 ,mem_vec_4408 ,mem_vec_4409 ,mem_vec_4410 ,mem_vec_4411 ,mem_vec_4412 ,mem_vec_4413 ,mem_vec_4414 ,mem_vec_4415 ,mem_vec_4416 ,mem_vec_4417 ,mem_vec_4418 ,mem_vec_4419 ,mem_vec_4420 ,mem_vec_4421 ,mem_vec_4422 ,mem_vec_4423 ,mem_vec_4424 ,mem_vec_4425 ,mem_vec_4426 ,mem_vec_4427 ,mem_vec_4428 ,mem_vec_4429 ,mem_vec_4430 ,mem_vec_4431 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f685 = 0;
f685_p_0 = 0;
c684 = 0;
c684_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_0 = 0;
c683 = 0;
c683_p_1 = 0;
x = 0;
xp_0 = 0;
						for (h = h273, hp_0 = 0;h < h273 + 3;h += 1, hp_0 += 1){
									mem_vec_4400 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_4401 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_4402 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_4403 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_4404 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_4405 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 40]);
									mem_vec_4406 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_4407 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 56]);
									mem_vec_4408 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_4409 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_4410 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_4411 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_4412 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_4413 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 40]);
									mem_vec_4414 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_4415 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 56]);
									mem_vec_4416 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_4417 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_4418 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_4419 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_4420 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_4421 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 40]);
									mem_vec_4422 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_4423 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 56]);
									mem_vec_4424 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_4425 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_4426 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_4427 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_4428 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_4429 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 40]);
									mem_vec_4430 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_4431 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 56]);
									// y = 4, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c683, cp_2 = c683_p_1, cp_1 = c683_p_0, cp_0 = 0;c < c683 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4400);
										mem_vec_4400 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4401);
										mem_vec_4401 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4402);
										mem_vec_4402 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4403);
										mem_vec_4403 = vec_7;
										vec_10 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_4404);
										mem_vec_4404 = vec_9;
										vec_12 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 40]);
										vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_4405);
										mem_vec_4405 = vec_11;
										vec_14 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_4406);
										mem_vec_4406 = vec_13;
										vec_16 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 56]);
										vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_4407);
										mem_vec_4407 = vec_15;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_18 = _mm256_set1_ps(scal_1);
										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4408);
										mem_vec_4408 = vec_17;
										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4409);
										mem_vec_4409 = vec_19;
										vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_4410);
										mem_vec_4410 = vec_20;
										vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_4411);
										mem_vec_4411 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_4412);
										mem_vec_4412 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_4413);
										mem_vec_4413 = vec_23;
										vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_4414);
										mem_vec_4414 = vec_24;
										vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_4415);
										mem_vec_4415 = vec_25;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_27 = _mm256_set1_ps(scal_2);
										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4416);
										mem_vec_4416 = vec_26;
										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4417);
										mem_vec_4417 = vec_28;
										vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_4418);
										mem_vec_4418 = vec_29;
										vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_4419);
										mem_vec_4419 = vec_30;
										vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_4420);
										mem_vec_4420 = vec_31;
										vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_4421);
										mem_vec_4421 = vec_32;
										vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_4422);
										mem_vec_4422 = vec_33;
										vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_4423);
										mem_vec_4423 = vec_34;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_36 = _mm256_set1_ps(scal_3);
										vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_4424);
										mem_vec_4424 = vec_35;
										vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_4425);
										mem_vec_4425 = vec_37;
										vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_4426);
										mem_vec_4426 = vec_38;
										vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_4427);
										mem_vec_4427 = vec_39;
										vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_4428);
										mem_vec_4428 = vec_40;
										vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_4429);
										mem_vec_4429 = vec_41;
										vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_4430);
										mem_vec_4430 = vec_42;
										vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_4431);
										mem_vec_4431 = vec_43;
										scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_45 = _mm256_set1_ps(scal_4);
										vec_46 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_4400);
										mem_vec_4400 = vec_44;
										vec_48 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
										vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_4401);
										mem_vec_4401 = vec_47;
										vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_4402);
										mem_vec_4402 = vec_49;
										vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
										vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_4403);
										mem_vec_4403 = vec_51;
										vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
										vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_4404);
										mem_vec_4404 = vec_53;
										vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 40]);
										vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_4405);
										mem_vec_4405 = vec_55;
										vec_58 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
										vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_4406);
										mem_vec_4406 = vec_57;
										vec_60 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 56]);
										vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_4407);
										mem_vec_4407 = vec_59;
										scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_62 = _mm256_set1_ps(scal_5);
										vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_4408);
										mem_vec_4408 = vec_61;
										vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_4409);
										mem_vec_4409 = vec_63;
										vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_4410);
										mem_vec_4410 = vec_64;
										vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_4411);
										mem_vec_4411 = vec_65;
										vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_4412);
										mem_vec_4412 = vec_66;
										vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_4413);
										mem_vec_4413 = vec_67;
										vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_4414);
										mem_vec_4414 = vec_68;
										vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_4415);
										mem_vec_4415 = vec_69;
										scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_71 = _mm256_set1_ps(scal_6);
										vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_4416);
										mem_vec_4416 = vec_70;
										vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_4417);
										mem_vec_4417 = vec_72;
										vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_4418);
										mem_vec_4418 = vec_73;
										vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_4419);
										mem_vec_4419 = vec_74;
										vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_4420);
										mem_vec_4420 = vec_75;
										vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_4421);
										mem_vec_4421 = vec_76;
										vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_4422);
										mem_vec_4422 = vec_77;
										vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_4423);
										mem_vec_4423 = vec_78;
										scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_80 = _mm256_set1_ps(scal_7);
										vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_4424);
										mem_vec_4424 = vec_79;
										vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_4425);
										mem_vec_4425 = vec_81;
										vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_4426);
										mem_vec_4426 = vec_82;
										vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_4427);
										mem_vec_4427 = vec_83;
										vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_4428);
										mem_vec_4428 = vec_84;
										vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_4429);
										mem_vec_4429 = vec_85;
										vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_4430);
										mem_vec_4430 = vec_86;
										vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_4431);
										mem_vec_4431 = vec_87;
										scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_89 = _mm256_set1_ps(scal_8);
										vec_90 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_4400);
										mem_vec_4400 = vec_88;
										vec_92 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
										vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_4401);
										mem_vec_4401 = vec_91;
										vec_94 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_4402);
										mem_vec_4402 = vec_93;
										vec_96 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
										vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_4403);
										mem_vec_4403 = vec_95;
										vec_98 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
										vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_4404);
										mem_vec_4404 = vec_97;
										vec_100 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 40]);
										vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_4405);
										mem_vec_4405 = vec_99;
										vec_102 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
										vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_4406);
										mem_vec_4406 = vec_101;
										vec_104 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 56]);
										vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_4407);
										mem_vec_4407 = vec_103;
										scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_106 = _mm256_set1_ps(scal_9);
										vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_4408);
										mem_vec_4408 = vec_105;
										vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_4409);
										mem_vec_4409 = vec_107;
										vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_4410);
										mem_vec_4410 = vec_108;
										vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_4411);
										mem_vec_4411 = vec_109;
										vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_4412);
										mem_vec_4412 = vec_110;
										vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_4413);
										mem_vec_4413 = vec_111;
										vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_4414);
										mem_vec_4414 = vec_112;
										vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_4415);
										mem_vec_4415 = vec_113;
										scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_115 = _mm256_set1_ps(scal_10);
										vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_4416);
										mem_vec_4416 = vec_114;
										vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_4417);
										mem_vec_4417 = vec_116;
										vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_4418);
										mem_vec_4418 = vec_117;
										vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_4419);
										mem_vec_4419 = vec_118;
										vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_4420);
										mem_vec_4420 = vec_119;
										vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_4421);
										mem_vec_4421 = vec_120;
										vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_4422);
										mem_vec_4422 = vec_121;
										vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_4423);
										mem_vec_4423 = vec_122;
										scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_124 = _mm256_set1_ps(scal_11);
										vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_4424);
										mem_vec_4424 = vec_123;
										vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_4425);
										mem_vec_4425 = vec_125;
										vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_4426);
										mem_vec_4426 = vec_126;
										vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_4427);
										mem_vec_4427 = vec_127;
										vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_4428);
										mem_vec_4428 = vec_128;
										vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_4429);
										mem_vec_4429 = vec_129;
										vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_4430);
										mem_vec_4430 = vec_130;
										vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_4431);
										mem_vec_4431 = vec_131;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4400);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4401);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4402);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4403);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4404);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 40], mem_vec_4405);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4406);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 56], mem_vec_4407);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4408);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4409);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4410);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4411);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4412);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 40], mem_vec_4413);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4414);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 56], mem_vec_4415);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4416);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4417);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4418);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4419);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4420);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 40], mem_vec_4421);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4422);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 56], mem_vec_4423);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4424);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4425);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4426);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4427);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_4428);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 40], mem_vec_4429);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_4430);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 56], mem_vec_4431);
						}
}
