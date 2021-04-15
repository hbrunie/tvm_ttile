
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (8, c); T (8, f); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1112_p_0, c1113_p_0, cp_1, c1112_p_1, cp_2, c1112, c1113, f, fp_0, h, hp_0, x, xp_0, x942_p_0, xp_1, x942, y, yp_0;
IND_TYPE y628 = 0;
IND_TYPE x943 = 0;
IND_TYPE h462 = 0;
IND_TYPE w = 0;
IND_TYPE c1114 = 0;
IND_TYPE f916 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,mem_vec_6784 ,mem_vec_6785 ,mem_vec_6786 ,mem_vec_6787 ,mem_vec_6788 ,mem_vec_6789 ,mem_vec_6790 ,mem_vec_6791 ,mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (c, 2) (256 / 128)
c1113 = 0;
c1113_p_0 = 0;
y = 0;
yp_0 = 0;
x942 = 0;
x942_p_0 = 0;
f = 0;
fp_0 = 0;
c1112 = 0;
c1112_p_1 = 0;
						for (h = h462, hp_0 = 0;h < h462 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
							// T (x, 7) (7 / 1)
							for (x = x942, xp_1 = x942_p_0, xp_0 = 0;x < x942 + 7;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6760 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6761 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6762 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6763 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6764 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6765 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6766 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6767 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6768 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6769 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6770 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6771 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6772 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6773 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6774 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6775 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c1112, cp_2 = c1112_p_1, cp_1 = c1112_p_0, cp_0 = 0;c < c1112 + 16;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6760);
											mem_vec_6760 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6761);
											mem_vec_6761 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6762);
											mem_vec_6762 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6763);
											mem_vec_6763 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6764);
											mem_vec_6764 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6765);
											mem_vec_6765 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6766);
											mem_vec_6766 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6767);
											mem_vec_6767 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6768);
											mem_vec_6768 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6769);
											mem_vec_6769 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6770);
											mem_vec_6770 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6771);
											mem_vec_6771 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6772);
											mem_vec_6772 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6773);
											mem_vec_6773 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6774);
											mem_vec_6774 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6775);
											mem_vec_6775 = vec_25;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_6760);
											mem_vec_6760 = vec_26;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_6761);
											mem_vec_6761 = vec_29;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_6762);
											mem_vec_6762 = vec_31;
											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_6763);
											mem_vec_6763 = vec_33;
											scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_6764);
											mem_vec_6764 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_6765);
											mem_vec_6765 = vec_36;
											scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_6766);
											mem_vec_6766 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6767);
											mem_vec_6767 = vec_39;
											scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_6768);
											mem_vec_6768 = vec_40;
											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_6769);
											mem_vec_6769 = vec_42;
											scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_6770);
											mem_vec_6770 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_6771);
											mem_vec_6771 = vec_45;
											scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_6772);
											mem_vec_6772 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_6773);
											mem_vec_6773 = vec_48;
											scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_6774);
											mem_vec_6774 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_6775);
											mem_vec_6775 = vec_51;
											scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_6760);
											mem_vec_6760 = vec_52;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_6761);
											mem_vec_6761 = vec_55;
											scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_6762);
											mem_vec_6762 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_6763);
											mem_vec_6763 = vec_59;
											scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_6764);
											mem_vec_6764 = vec_60;
											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_6765);
											mem_vec_6765 = vec_62;
											scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_6766);
											mem_vec_6766 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_6767);
											mem_vec_6767 = vec_65;
											scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_6768);
											mem_vec_6768 = vec_66;
											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_6769);
											mem_vec_6769 = vec_68;
											scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_6770);
											mem_vec_6770 = vec_69;
											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_6771);
											mem_vec_6771 = vec_71;
											scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_6772);
											mem_vec_6772 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_6773);
											mem_vec_6773 = vec_74;
											scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_6774);
											mem_vec_6774 = vec_75;
											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_6775);
											mem_vec_6775 = vec_77;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6760);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6761);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6762);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6763);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6764);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6765);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6766);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6767);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6768);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6769);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6770);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6771);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6772);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6773);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6774);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6775);
							}
						}
}
