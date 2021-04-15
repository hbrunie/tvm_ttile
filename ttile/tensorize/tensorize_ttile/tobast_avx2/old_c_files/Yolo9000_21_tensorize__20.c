
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (16, x);
  T (3, w); T (17, y); T (1, f); T (32, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 6))]; T (2, f);
  T (17, x)]
*/
IND_TYPE c, cp_0, c810_p_0, cp_1, c810, f, fp_0, f682_p_0, fp_1, f682, w, wp_0, x, xp_0, x1080_p_0, x1081_p_0, xp_1, x1080_p_1, xp_2, x1080, x1081, y, yp_0, y810_p_0, yp_1, y810;
IND_TYPE y811 = 0;
IND_TYPE x1082 = 0;
IND_TYPE h = 0;
IND_TYPE w490 = 0;
IND_TYPE c811 = 0;
IND_TYPE f683 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7712 ,mem_vec_7713 ,mem_vec_7714 ,mem_vec_7715 ,mem_vec_7716 ,mem_vec_7717 ,mem_vec_7718 ,mem_vec_7719 ,mem_vec_7720 ,mem_vec_7721 ,mem_vec_7722 ,mem_vec_7723 ,mem_vec_7724 ,mem_vec_7725 ,mem_vec_7726 ,mem_vec_7727 ,mem_vec_7728 ,mem_vec_7729 ,mem_vec_7730 ,mem_vec_7731 ,mem_vec_7732 ,mem_vec_7733 ,mem_vec_7734 ,mem_vec_7735 ,mem_vec_7736 ,mem_vec_7737 ,mem_vec_7738 ,mem_vec_7739 ,mem_vec_7740 ,mem_vec_7741 ,mem_vec_7742 ,mem_vec_7743 ,mem_vec_7744 ,mem_vec_7745 ,mem_vec_7746 ,mem_vec_7747 ,mem_vec_7748 ,mem_vec_7749 ,mem_vec_7750 ,mem_vec_7751 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 17) (272 / 16)
x1081 = 0;
x1081_p_0 = 0;
f682 = 0;
f682_p_0 = 0;
y810 = 0;
y810_p_0 = 0;
x1080 = 0;
x1080_p_1 = 0;
c810 = 0;
c810_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
								for (w = w490, wp_0 = 0;w < w490 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 16, h = 3, w = 1, c = 1, f = 32
									// T (x, 16) (16 / 1)
									for (x = x1080, xp_2 = x1080_p_1, xp_1 = x1080_p_0, xp_0 = 0;x < x1080 + 16;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7712 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_7713 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_7714 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_7715 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_7716 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_7717 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_7718 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_7719 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_7720 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_7721 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_7722 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_7723 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_7724 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_7725 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_7726 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_7727 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c810, cp_1 = c810_p_0, cp_0 = 0;c < c810 + 1;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7712);
													mem_vec_7712 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7713);
													mem_vec_7713 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7714);
													mem_vec_7714 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7715);
													mem_vec_7715 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7716);
													mem_vec_7716 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7717);
													mem_vec_7717 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7718);
													mem_vec_7718 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7719);
													mem_vec_7719 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7720);
													mem_vec_7720 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7721);
													mem_vec_7721 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7722);
													mem_vec_7722 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7723);
													mem_vec_7723 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7724);
													mem_vec_7724 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7725);
													mem_vec_7725 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7726);
													mem_vec_7726 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7727);
													mem_vec_7727 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7712);
													mem_vec_7712 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7713);
													mem_vec_7713 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7714);
													mem_vec_7714 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7715);
													mem_vec_7715 = vec_31;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7716);
													mem_vec_7716 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7717);
													mem_vec_7717 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7718);
													mem_vec_7718 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7719);
													mem_vec_7719 = vec_37;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7720);
													mem_vec_7720 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7721);
													mem_vec_7721 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7722);
													mem_vec_7722 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7723);
													mem_vec_7723 = vec_42;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7724);
													mem_vec_7724 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7725);
													mem_vec_7725 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7726);
													mem_vec_7726 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7727);
													mem_vec_7727 = vec_47;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7712);
													mem_vec_7712 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7713);
													mem_vec_7713 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7714);
													mem_vec_7714 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7715);
													mem_vec_7715 = vec_55;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7716);
													mem_vec_7716 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7717);
													mem_vec_7717 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7718);
													mem_vec_7718 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7719);
													mem_vec_7719 = vec_61;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7720);
													mem_vec_7720 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7721);
													mem_vec_7721 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7722);
													mem_vec_7722 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7723);
													mem_vec_7723 = vec_66;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7724);
													mem_vec_7724 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7725);
													mem_vec_7725 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7726);
													mem_vec_7726 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7727);
													mem_vec_7727 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7712);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7713);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7714);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_7715);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7716);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7717);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7718);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_7719);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7720);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7721);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7722);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_7723);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7724);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7725);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7726);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_7727);
									}
								}
}
