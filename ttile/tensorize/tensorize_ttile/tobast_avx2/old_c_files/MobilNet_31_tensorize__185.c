
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, f); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (2, f);
  T (2, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1028_p_0, cp_1, c1028, f, fp_0, f1024_p_0, f1025_p_0, fp_1, f1024_p_1, fp_2, f1024, f1025, h, hp_0, x, xp_0, x1232_p_0, x1233_p_0, xp_1, x1232_p_1, xp_2, x1232, x1233, y, yp_0;
IND_TYPE y616 = 0;
IND_TYPE x1234 = 0;
IND_TYPE h378 = 0;
IND_TYPE w = 0;
IND_TYPE c1029 = 0;
IND_TYPE f1026 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10528 ,mem_vec_10529 ,mem_vec_10530 ,mem_vec_10531 ,mem_vec_10532 ,mem_vec_10533 ,mem_vec_10534 ,mem_vec_10535 ,mem_vec_10536 ,mem_vec_10537 ,mem_vec_10538 ,mem_vec_10539 ,mem_vec_10540 ,mem_vec_10541 ,mem_vec_10542 ,mem_vec_10543 ,mem_vec_10544 ,mem_vec_10545 ,mem_vec_10546 ,mem_vec_10547 ,mem_vec_10548 ,mem_vec_10549 ,mem_vec_10550 ,mem_vec_10551 ,mem_vec_10552 ,mem_vec_10553 ,mem_vec_10554 ,mem_vec_10555 ,mem_vec_10556 ,mem_vec_10557 ,mem_vec_10558 ,mem_vec_10559 ,mem_vec_10560 ,mem_vec_10561 ,mem_vec_10562 ,mem_vec_10563 ,mem_vec_10564 ,mem_vec_10565 ,mem_vec_10566 ,mem_vec_10567 ,mem_vec_10568 ,mem_vec_10569 ,mem_vec_10570 ,mem_vec_10571 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f1025 = 0;
f1025_p_0 = 0;
x1233 = 0;
x1233_p_0 = 0;
c1028 = 0;
c1028_p_0 = 0;
f1024 = 0;
f1024_p_1 = 0;
y = 0;
yp_0 = 0;
x1232 = 0;
x1232_p_1 = 0;
f = 0;
fp_2 = 0;
								for (h = h378, hp_0 = 0;h < h378 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 64, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1232, xp_2 = x1232_p_1, xp_1 = x1232_p_0, xp_0 = 0;x < x1232 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10528 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_10529 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_10530 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_10531 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_10532 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_10533 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_10534 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_10535 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_10536 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_10537 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_10538 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_10539 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_10540 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_10541 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_10542 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_10543 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c1028, cp_1 = c1028_p_0, cp_0 = 0;c < c1028 + 64;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10528);
													mem_vec_10528 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10529);
													mem_vec_10529 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10530);
													mem_vec_10530 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10531);
													mem_vec_10531 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10532);
													mem_vec_10532 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10533);
													mem_vec_10533 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10534);
													mem_vec_10534 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10535);
													mem_vec_10535 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10536);
													mem_vec_10536 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10537);
													mem_vec_10537 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10538);
													mem_vec_10538 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10539);
													mem_vec_10539 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10540);
													mem_vec_10540 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10541);
													mem_vec_10541 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10542);
													mem_vec_10542 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10543);
													mem_vec_10543 = vec_23;
													scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10528);
													mem_vec_10528 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10529);
													mem_vec_10529 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10530);
													mem_vec_10530 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10531);
													mem_vec_10531 = vec_31;
													scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10532);
													mem_vec_10532 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10533);
													mem_vec_10533 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10534);
													mem_vec_10534 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10535);
													mem_vec_10535 = vec_37;
													scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10536);
													mem_vec_10536 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10537);
													mem_vec_10537 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10538);
													mem_vec_10538 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10539);
													mem_vec_10539 = vec_42;
													scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10540);
													mem_vec_10540 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10541);
													mem_vec_10541 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10542);
													mem_vec_10542 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10543);
													mem_vec_10543 = vec_47;
													scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10528);
													mem_vec_10528 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10529);
													mem_vec_10529 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10530);
													mem_vec_10530 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10531);
													mem_vec_10531 = vec_55;
													scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10532);
													mem_vec_10532 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10533);
													mem_vec_10533 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10534);
													mem_vec_10534 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10535);
													mem_vec_10535 = vec_61;
													scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10536);
													mem_vec_10536 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10537);
													mem_vec_10537 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10538);
													mem_vec_10538 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10539);
													mem_vec_10539 = vec_66;
													scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10540);
													mem_vec_10540 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10541);
													mem_vec_10541 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10542);
													mem_vec_10542 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10543);
													mem_vec_10543 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10528);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10529);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10530);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10531);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10532);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10533);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10534);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10535);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10536);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10537);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10538);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10539);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10540);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10541);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10542);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10543);
									}
								}
}
