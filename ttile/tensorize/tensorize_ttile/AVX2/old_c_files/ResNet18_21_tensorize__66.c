
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c501_p_0, cp_1, c501, f, fp_0, f641_p_0, f642_p_0, fp_1, f641_p_1, fp_2, f641, f642, h, hp_0, x, xp_0, x502_p_0, xp_1, x502, y, yp_0;
IND_TYPE y346 = 0;
IND_TYPE x503 = 0;
IND_TYPE h235 = 0;
IND_TYPE w = 0;
IND_TYPE c502 = 0;
IND_TYPE f643 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6456 ,mem_vec_6457 ,mem_vec_6458 ,mem_vec_6459 ,mem_vec_6460 ,mem_vec_6461 ,mem_vec_6462 ,mem_vec_6463 ,mem_vec_6464 ,mem_vec_6465 ,mem_vec_6466 ,mem_vec_6467 ,mem_vec_6468 ,mem_vec_6469 ,mem_vec_6470 ,mem_vec_6471 ,mem_vec_6472 ,mem_vec_6473 ,mem_vec_6474 ,mem_vec_6475 ,mem_vec_6476 ,mem_vec_6477 ,mem_vec_6478 ,mem_vec_6479 ,mem_vec_6480 ,mem_vec_6481 ,mem_vec_6482 ,mem_vec_6483 ,mem_vec_6484 ,mem_vec_6485 ,mem_vec_6486 ,mem_vec_6487 ,mem_vec_6488 ,mem_vec_6489 ,mem_vec_6490 ,mem_vec_6491 ,mem_vec_6492 ,mem_vec_6493 ,mem_vec_6494 ,mem_vec_6495 ,mem_vec_6496 ,mem_vec_6497 ,mem_vec_6498 ,mem_vec_6499 ,mem_vec_6500 ,mem_vec_6501 ,mem_vec_6502 ,mem_vec_6503 ,mem_vec_6504 ,mem_vec_6505 ,mem_vec_6506 ,mem_vec_6507 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
f642 = 0;
f642_p_0 = 0;
f641 = 0;
f641_p_1 = 0;
x502 = 0;
x502_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c501 = 0;
c501_p_0 = 0;
							for (h = h235, hp_0 = 0;h < h235 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 32, f = 32
								// T (x, 7) (7 / 1)
								for (x = x502, xp_1 = x502_p_0, xp_0 = 0;x < x502 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6456 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6457 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_6458 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6459 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_6460 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6461 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_6462 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6463 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_6464 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6465 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_6466 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6467 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_6468 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6469 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_6470 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6471 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_6472 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6473 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_6474 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6475 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											mem_vec_6476 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6477 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_6478 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6479 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c501, cp_1 = c501_p_0, cp_0 = 0;c < c501 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6456);
												mem_vec_6456 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6457);
												mem_vec_6457 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6458);
												mem_vec_6458 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6459);
												mem_vec_6459 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6460);
												mem_vec_6460 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6461);
												mem_vec_6461 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6462);
												mem_vec_6462 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6463);
												mem_vec_6463 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6464);
												mem_vec_6464 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6465);
												mem_vec_6465 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6466);
												mem_vec_6466 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6467);
												mem_vec_6467 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6468);
												mem_vec_6468 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6469);
												mem_vec_6469 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6470);
												mem_vec_6470 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6471);
												mem_vec_6471 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6472);
												mem_vec_6472 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6473);
												mem_vec_6473 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6474);
												mem_vec_6474 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6475);
												mem_vec_6475 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6476);
												mem_vec_6476 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6477);
												mem_vec_6477 = vec_31;
												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6478);
												mem_vec_6478 = vec_32;
												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6479);
												mem_vec_6479 = vec_33;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6456);
												mem_vec_6456 = vec_34;
												vec_38 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6457);
												mem_vec_6457 = vec_37;
												vec_40 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6458);
												mem_vec_6458 = vec_39;
												vec_42 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6459);
												mem_vec_6459 = vec_41;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6460);
												mem_vec_6460 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6461);
												mem_vec_6461 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6462);
												mem_vec_6462 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6463);
												mem_vec_6463 = vec_47;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6464);
												mem_vec_6464 = vec_48;
												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6465);
												mem_vec_6465 = vec_50;
												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6466);
												mem_vec_6466 = vec_51;
												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6467);
												mem_vec_6467 = vec_52;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);
												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6468);
												mem_vec_6468 = vec_53;
												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6469);
												mem_vec_6469 = vec_55;
												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6470);
												mem_vec_6470 = vec_56;
												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6471);
												mem_vec_6471 = vec_57;
												scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6472);
												mem_vec_6472 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6473);
												mem_vec_6473 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6474);
												mem_vec_6474 = vec_61;
												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6475);
												mem_vec_6475 = vec_62;
												scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6476);
												mem_vec_6476 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6477);
												mem_vec_6477 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6478);
												mem_vec_6478 = vec_66;
												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6479);
												mem_vec_6479 = vec_67;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6456);
												mem_vec_6456 = vec_68;
												vec_72 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6457);
												mem_vec_6457 = vec_71;
												vec_74 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6458);
												mem_vec_6458 = vec_73;
												vec_76 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6459);
												mem_vec_6459 = vec_75;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);
												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6460);
												mem_vec_6460 = vec_77;
												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6461);
												mem_vec_6461 = vec_79;
												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6462);
												mem_vec_6462 = vec_80;
												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6463);
												mem_vec_6463 = vec_81;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);
												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6464);
												mem_vec_6464 = vec_82;
												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6465);
												mem_vec_6465 = vec_84;
												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6466);
												mem_vec_6466 = vec_85;
												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6467);
												mem_vec_6467 = vec_86;
												scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6468);
												mem_vec_6468 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6469);
												mem_vec_6469 = vec_89;
												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6470);
												mem_vec_6470 = vec_90;
												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6471);
												mem_vec_6471 = vec_91;
												scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);
												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6472);
												mem_vec_6472 = vec_92;
												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6473);
												mem_vec_6473 = vec_94;
												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6474);
												mem_vec_6474 = vec_95;
												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6475);
												mem_vec_6475 = vec_96;
												scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);
												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6476);
												mem_vec_6476 = vec_97;
												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6477);
												mem_vec_6477 = vec_99;
												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6478);
												mem_vec_6478 = vec_100;
												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6479);
												mem_vec_6479 = vec_101;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6456);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_6457);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6458);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_6459);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6460);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_6461);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6462);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_6463);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6464);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_6465);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6466);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_6467);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6468);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_6469);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6470);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_6471);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6472);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_6473);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6474);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_6475);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6476);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_6477);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6478);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_6479);
								}
							}
}
