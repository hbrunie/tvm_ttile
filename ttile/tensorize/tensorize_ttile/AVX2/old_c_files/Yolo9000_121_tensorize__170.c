
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (16, c); T (32, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (2, c)]
*/
IND_TYPE c, cp_0, c689_p_0, c690_p_0, c691_p_0, cp_1, c689_p_1, c690_p_1, cp_2, c689_p_2, cp_3, c689, c690, c691, f, fp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y381 = 0;
IND_TYPE x350 = 0;
IND_TYPE h = 0;
IND_TYPE w294 = 0;
IND_TYPE c692 = 0;
IND_TYPE f536 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7748 ,mem_vec_7749 ,mem_vec_7750 ,mem_vec_7751 ,mem_vec_7752 ,mem_vec_7753 ,mem_vec_7754 ,mem_vec_7755 ,mem_vec_7756 ,mem_vec_7757 ,mem_vec_7758 ,mem_vec_7759 ,mem_vec_7760 ,mem_vec_7761 ,mem_vec_7762 ,mem_vec_7763 ,mem_vec_7764 ,mem_vec_7765 ,mem_vec_7766 ,mem_vec_7767 ,mem_vec_7768 ,mem_vec_7769 ,mem_vec_7770 ,mem_vec_7771 ,mem_vec_7772 ,mem_vec_7773 ,mem_vec_7774 ,mem_vec_7775 ,mem_vec_7776 ,mem_vec_7777 ,mem_vec_7778 ,mem_vec_7779 ,mem_vec_7780 ,mem_vec_7781 ,mem_vec_7782 ,mem_vec_7783 ,mem_vec_7784 ,mem_vec_7785 ,mem_vec_7786 ,mem_vec_7787 ,mem_vec_7788 ,mem_vec_7789 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 2) (256 / 128)
c691 = 0;
c691_p_0 = 0;
y = 0;
yp_0 = 0;
c690 = 0;
c690_p_1 = 0;
f = 0;
fp_0 = 0;
c689 = 0;
c689_p_2 = 0;
x = 0;
xp_0 = 0;
							for (w = w294, wp_0 = 0;w < w294 + 3;w += 1, wp_0 += 1){
										mem_vec_7748 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7749 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_7750 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7751 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_7752 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7753 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_7754 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7755 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_7756 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7757 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_7758 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_7759 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
										mem_vec_7760 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_7761 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
										mem_vec_7762 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_7763 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c689, cp_3 = c689_p_2, cp_2 = c689_p_1, cp_1 = c689_p_0, cp_0 = 0;c < c689 + 8;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7748);
											mem_vec_7748 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7749);
											mem_vec_7749 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);
											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7750);
											mem_vec_7750 = vec_5;
											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7751);
											mem_vec_7751 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);
											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7752);
											mem_vec_7752 = vec_8;
											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7753);
											mem_vec_7753 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);
											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7754);
											mem_vec_7754 = vec_11;
											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7755);
											mem_vec_7755 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7756);
											mem_vec_7756 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7757);
											mem_vec_7757 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);
											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7758);
											mem_vec_7758 = vec_17;
											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7759);
											mem_vec_7759 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);
											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7760);
											mem_vec_7760 = vec_20;
											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7761);
											mem_vec_7761 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);
											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7762);
											mem_vec_7762 = vec_23;
											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7763);
											mem_vec_7763 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_7748);
											mem_vec_7748 = vec_26;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_7749);
											mem_vec_7749 = vec_29;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_32 = _mm256_set1_ps(scal_9);
											vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_7750);
											mem_vec_7750 = vec_31;
											vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_7751);
											mem_vec_7751 = vec_33;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_7752);
											mem_vec_7752 = vec_34;
											vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_7753);
											mem_vec_7753 = vec_36;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);
											vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_7754);
											mem_vec_7754 = vec_37;
											vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_7755);
											mem_vec_7755 = vec_39;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);
											vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_7756);
											mem_vec_7756 = vec_40;
											vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_7757);
											mem_vec_7757 = vec_42;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7758);
											mem_vec_7758 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7759);
											mem_vec_7759 = vec_45;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);
											vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_7760);
											mem_vec_7760 = vec_46;
											vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_7761);
											mem_vec_7761 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);
											vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_7762);
											mem_vec_7762 = vec_49;
											vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_7763);
											mem_vec_7763 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_7748);
											mem_vec_7748 = vec_52;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_7749);
											mem_vec_7749 = vec_55;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_17);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7750);
											mem_vec_7750 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7751);
											mem_vec_7751 = vec_59;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_61 = _mm256_set1_ps(scal_18);
											vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_7752);
											mem_vec_7752 = vec_60;
											vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_7753);
											mem_vec_7753 = vec_62;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);
											vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_7754);
											mem_vec_7754 = vec_63;
											vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_7755);
											mem_vec_7755 = vec_65;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_7756);
											mem_vec_7756 = vec_66;
											vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_7757);
											mem_vec_7757 = vec_68;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);
											vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_7758);
											mem_vec_7758 = vec_69;
											vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_7759);
											mem_vec_7759 = vec_71;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);
											vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_7760);
											mem_vec_7760 = vec_72;
											vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_7761);
											mem_vec_7761 = vec_74;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);
											vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_7762);
											mem_vec_7762 = vec_75;
											vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_7763);
											mem_vec_7763 = vec_77;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7748);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7749);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7750);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7751);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7752);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7753);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7754);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7755);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7756);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_7757);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7758);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_7759);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7760);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_7761);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7762);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_7763);
							}
}
