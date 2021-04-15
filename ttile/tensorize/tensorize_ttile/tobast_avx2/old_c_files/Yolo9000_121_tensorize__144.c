
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (16, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, f);
  T (64, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1508_p_0, cp_1, c1508, f, fp_0, f1040_p_0, f1041_p_0, fp_1, f1040_p_1, fp_2, f1040, f1041, h, hp_0, x, xp_0, x1456_p_0, x1457_p_0, xp_1, x1456_p_1, xp_2, x1456, x1457, y, yp_0;
IND_TYPE y728 = 0;
IND_TYPE x1458 = 0;
IND_TYPE h418 = 0;
IND_TYPE w = 0;
IND_TYPE c1509 = 0;
IND_TYPE f1042 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_15504 ,mem_vec_15505 ,mem_vec_15506 ,mem_vec_15507 ,mem_vec_15508 ,mem_vec_15509 ,mem_vec_15510 ,mem_vec_15511 ,mem_vec_15512 ,mem_vec_15513 ,mem_vec_15514 ,mem_vec_15515 ,mem_vec_15516 ,mem_vec_15517 ,mem_vec_15518 ,mem_vec_15519 ,mem_vec_15520 ,mem_vec_15521 ,mem_vec_15522 ,mem_vec_15523 ,mem_vec_15524 ,mem_vec_15525 ,mem_vec_15526 ,mem_vec_15527 ,mem_vec_15528 ,mem_vec_15529 ,mem_vec_15530 ,mem_vec_15531 ,mem_vec_15532 ,mem_vec_15533 ,mem_vec_15534 ,mem_vec_15535 ,mem_vec_15536 ,mem_vec_15537 ,mem_vec_15538 ,mem_vec_15539 ,mem_vec_15540 ,mem_vec_15541 ,mem_vec_15542 ,mem_vec_15543 ,mem_vec_15544 ,mem_vec_15545 ,mem_vec_15546 ,mem_vec_15547 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f1041 = 0;
f1041_p_0 = 0;
x1457 = 0;
x1457_p_0 = 0;
c1508 = 0;
c1508_p_0 = 0;
f1040 = 0;
f1040_p_1 = 0;
y = 0;
yp_0 = 0;
x1456 = 0;
x1456_p_1 = 0;
f = 0;
fp_2 = 0;
								for (h = h418, hp_0 = 0;h < h418 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1456, xp_2 = x1456_p_1, xp_1 = x1456_p_0, xp_0 = 0;x < x1456 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_15504 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_15505 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_15506 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_15507 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_15508 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_15509 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_15510 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_15511 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_15512 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_15513 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_15514 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_15515 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_15516 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_15517 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_15518 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_15519 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1508, cp_1 = c1508_p_0, cp_0 = 0;c < c1508 + 4;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15504);
													mem_vec_15504 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15505);
													mem_vec_15505 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15506);
													mem_vec_15506 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15507);
													mem_vec_15507 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_15508);
													mem_vec_15508 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_15509);
													mem_vec_15509 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_15510);
													mem_vec_15510 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_15511);
													mem_vec_15511 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_15512);
													mem_vec_15512 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_15513);
													mem_vec_15513 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_15514);
													mem_vec_15514 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_15515);
													mem_vec_15515 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_15516);
													mem_vec_15516 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_15517);
													mem_vec_15517 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_15518);
													mem_vec_15518 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15519);
													mem_vec_15519 = vec_23;
													scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_15504);
													mem_vec_15504 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_15505);
													mem_vec_15505 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_15506);
													mem_vec_15506 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_15507);
													mem_vec_15507 = vec_31;
													scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_15508);
													mem_vec_15508 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_15509);
													mem_vec_15509 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_15510);
													mem_vec_15510 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_15511);
													mem_vec_15511 = vec_37;
													scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_15512);
													mem_vec_15512 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_15513);
													mem_vec_15513 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_15514);
													mem_vec_15514 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_15515);
													mem_vec_15515 = vec_42;
													scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_15516);
													mem_vec_15516 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_15517);
													mem_vec_15517 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_15518);
													mem_vec_15518 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_15519);
													mem_vec_15519 = vec_47;
													scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_15504);
													mem_vec_15504 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_15505);
													mem_vec_15505 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_15506);
													mem_vec_15506 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_15507);
													mem_vec_15507 = vec_55;
													scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_15508);
													mem_vec_15508 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_15509);
													mem_vec_15509 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_15510);
													mem_vec_15510 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_15511);
													mem_vec_15511 = vec_61;
													scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_15512);
													mem_vec_15512 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_15513);
													mem_vec_15513 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_15514);
													mem_vec_15514 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_15515);
													mem_vec_15515 = vec_66;
													scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_15516);
													mem_vec_15516 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_15517);
													mem_vec_15517 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_15518);
													mem_vec_15518 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_15519);
													mem_vec_15519 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_15504);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_15505);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_15506);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_15507);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_15508);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_15509);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_15510);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_15511);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_15512);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_15513);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_15514);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_15515);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_15516);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_15517);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_15518);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_15519);
									}
								}
}
