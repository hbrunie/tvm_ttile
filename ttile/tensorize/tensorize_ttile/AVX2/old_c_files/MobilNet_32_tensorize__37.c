void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (1, c);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (14, x);
  T (2, f); T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c608_p_0, c609_p_0, cp_1, c608_p_1, cp_2, c608, c609, f, fp_0, f449_p_0, fp_1, f449, w, wp_0, x, xp_0, x456_p_0, xp_1, x456, y, yp_0;
IND_TYPE y304 = 0;
IND_TYPE x457 = 0;
IND_TYPE h = 0;
IND_TYPE w236 = 0;
IND_TYPE c610 = 0;
IND_TYPE f450 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,mem_vec_6784 ,mem_vec_6785 ,mem_vec_6786 ,mem_vec_6787 ,mem_vec_6788 ,mem_vec_6789 ,mem_vec_6790 ,mem_vec_6791 ,mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f449 = 0;
f449_p_0 = 0;
c609 = 0;
c609_p_0 = 0;
f = 0;
fp_1 = 0;
x456 = 0;
x456_p_0 = 0;
y = 0;
yp_0 = 0;
c608 = 0;
c608_p_1 = 0;
							for (w = w236, wp_0 = 0;w < w236 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 32
								// T (x, 4) (4 / 1)
								for (x = x456, xp_1 = x456_p_0, xp_0 = 0;x < x456 + 4;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6780 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6781 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_6782 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6783 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_6784 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6785 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_6786 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6787 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_6788 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6789 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_6790 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6791 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_6792 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6793 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_6794 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6795 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_6796 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6797 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_6798 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6799 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											mem_vec_6800 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6801 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_6802 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6803 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
											mem_vec_6804 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6805 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_6806 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6807 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c608, cp_2 = c608_p_1, cp_1 = c608_p_0, cp_0 = 0;c < c608 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6780);
												mem_vec_6780 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6781);
												mem_vec_6781 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6782);
												mem_vec_6782 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6783);
												mem_vec_6783 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6784);
												mem_vec_6784 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6785);
												mem_vec_6785 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6786);
												mem_vec_6786 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6787);
												mem_vec_6787 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6788);
												mem_vec_6788 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6789);
												mem_vec_6789 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6790);
												mem_vec_6790 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6791);
												mem_vec_6791 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6792);
												mem_vec_6792 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6793);
												mem_vec_6793 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6794);
												mem_vec_6794 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6795);
												mem_vec_6795 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6796);
												mem_vec_6796 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6797);
												mem_vec_6797 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6798);
												mem_vec_6798 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6799);
												mem_vec_6799 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6800);
												mem_vec_6800 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6801);
												mem_vec_6801 = vec_31;
												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6802);
												mem_vec_6802 = vec_32;
												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6803);
												mem_vec_6803 = vec_33;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6804);
												mem_vec_6804 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6805);
												mem_vec_6805 = vec_36;
												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6806);
												mem_vec_6806 = vec_37;
												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6807);
												mem_vec_6807 = vec_38;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6780);
												mem_vec_6780 = vec_39;
												vec_43 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6781);
												mem_vec_6781 = vec_42;
												vec_45 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6782);
												mem_vec_6782 = vec_44;
												vec_47 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6783);
												mem_vec_6783 = vec_46;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6784);
												mem_vec_6784 = vec_48;
												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6785);
												mem_vec_6785 = vec_50;
												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6786);
												mem_vec_6786 = vec_51;
												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6787);
												mem_vec_6787 = vec_52;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);
												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6788);
												mem_vec_6788 = vec_53;
												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6789);
												mem_vec_6789 = vec_55;
												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6790);
												mem_vec_6790 = vec_56;
												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6791);
												mem_vec_6791 = vec_57;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6792);
												mem_vec_6792 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6793);
												mem_vec_6793 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6794);
												mem_vec_6794 = vec_61;
												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6795);
												mem_vec_6795 = vec_62;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6796);
												mem_vec_6796 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6797);
												mem_vec_6797 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6798);
												mem_vec_6798 = vec_66;
												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6799);
												mem_vec_6799 = vec_67;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6800);
												mem_vec_6800 = vec_68;
												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6801);
												mem_vec_6801 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6802);
												mem_vec_6802 = vec_71;
												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6803);
												mem_vec_6803 = vec_72;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);
												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6804);
												mem_vec_6804 = vec_73;
												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6805);
												mem_vec_6805 = vec_75;
												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6806);
												mem_vec_6806 = vec_76;
												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6807);
												mem_vec_6807 = vec_77;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6780);
												mem_vec_6780 = vec_78;
												vec_82 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6781);
												mem_vec_6781 = vec_81;
												vec_84 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6782);
												mem_vec_6782 = vec_83;
												vec_86 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6783);
												mem_vec_6783 = vec_85;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6784);
												mem_vec_6784 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6785);
												mem_vec_6785 = vec_89;
												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6786);
												mem_vec_6786 = vec_90;
												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6787);
												mem_vec_6787 = vec_91;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);
												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6788);
												mem_vec_6788 = vec_92;
												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6789);
												mem_vec_6789 = vec_94;
												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6790);
												mem_vec_6790 = vec_95;
												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6791);
												mem_vec_6791 = vec_96;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);
												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6792);
												mem_vec_6792 = vec_97;
												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6793);
												mem_vec_6793 = vec_99;
												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6794);
												mem_vec_6794 = vec_100;
												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6795);
												mem_vec_6795 = vec_101;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);
												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6796);
												mem_vec_6796 = vec_102;
												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6797);
												mem_vec_6797 = vec_104;
												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6798);
												mem_vec_6798 = vec_105;
												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6799);
												mem_vec_6799 = vec_106;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);
												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6800);
												mem_vec_6800 = vec_107;
												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6801);
												mem_vec_6801 = vec_109;
												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6802);
												mem_vec_6802 = vec_110;
												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6803);
												mem_vec_6803 = vec_111;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);
												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6804);
												mem_vec_6804 = vec_112;
												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6805);
												mem_vec_6805 = vec_114;
												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6806);
												mem_vec_6806 = vec_115;
												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6807);
												mem_vec_6807 = vec_116;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6780);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_6781);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6782);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_6783);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6784);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_6785);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6786);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_6787);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6788);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_6789);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6790);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_6791);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6792);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_6793);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6794);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_6795);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6796);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_6797);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6798);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_6799);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6800);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_6801);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6802);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_6803);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6804);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_6805);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6806);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 24], mem_vec_6807);
								}
							}
}
