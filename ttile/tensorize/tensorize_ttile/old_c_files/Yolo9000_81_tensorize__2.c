
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))];
  T (1, f); T (64, c); T (1, f); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1152_p_0, cp_1, c1152, f, fp_0, f1460_p_0, f1461_p_0, fp_1, f1460_p_1, fp_2, f1460, f1461, w, wp_0, x, xp_0, x1242_p_0, xp_1, x1242, y, yp_0;
IND_TYPE y768 = 0;
IND_TYPE x1243 = 0;
IND_TYPE h = 0;
IND_TYPE w716 = 0;
IND_TYPE c1153 = 0;
IND_TYPE f1462 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14704 ,mem_vec_14705 ,mem_vec_14706 ,mem_vec_14707 ,mem_vec_14708 ,mem_vec_14709 ,mem_vec_14710 ,mem_vec_14711 ,mem_vec_14712 ,mem_vec_14713 ,mem_vec_14714 ,mem_vec_14715 ,mem_vec_14716 ,mem_vec_14717 ,mem_vec_14718 ,mem_vec_14719 ,mem_vec_14720 ,mem_vec_14721 ,mem_vec_14722 ,mem_vec_14723 ,mem_vec_14724 ,mem_vec_14725 ,mem_vec_14726 ,mem_vec_14727 ,mem_vec_14728 ,mem_vec_14729 ,mem_vec_14730 ,mem_vec_14731 ,mem_vec_14732 ,mem_vec_14733 ,mem_vec_14734 ,mem_vec_14735 ,mem_vec_14736 ,mem_vec_14737 ,mem_vec_14738 ,mem_vec_14739 ,mem_vec_14740 ,mem_vec_14741 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
f1461 = 0;
f1461_p_0 = 0;
x1242 = 0;
x1242_p_0 = 0;
f1460 = 0;
f1460_p_1 = 0;
c1152 = 0;
c1152_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (w = w716, wp_0 = 0;w < w716 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 2, f = 32
								// T (x, 4) (4 / 1)
								for (x = x1242, xp_1 = x1242_p_0, xp_0 = 0;x < x1242 + 4;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_14705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_14706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_14707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_14708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_14709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_14710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_14711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_14712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_14713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_14714 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_14715 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_14716 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_14717 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_14718 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_14719 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_14720 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_14721 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1152, cp_1 = c1152_p_0, cp_0 = 0;c < c1152 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14704);
												mem_vec_14704 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14705);
												mem_vec_14705 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14706);
												mem_vec_14706 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14707);
												mem_vec_14707 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14708);
												mem_vec_14708 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14709);
												mem_vec_14709 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14710);
												mem_vec_14710 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14711);
												mem_vec_14711 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14712);
												mem_vec_14712 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14713);
												mem_vec_14713 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14714);
												mem_vec_14714 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14715);
												mem_vec_14715 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14716);
												mem_vec_14716 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14717);
												mem_vec_14717 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14718);
												mem_vec_14718 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14719);
												mem_vec_14719 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14720);
												mem_vec_14720 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14721);
												mem_vec_14721 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_14704);
												mem_vec_14704 = vec_29;
												vec_33 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_14705);
												mem_vec_14705 = vec_32;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_14706);
												mem_vec_14706 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_14707);
												mem_vec_14707 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_14708);
												mem_vec_14708 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_14709);
												mem_vec_14709 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_14710);
												mem_vec_14710 = vec_40;
												vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_14711);
												mem_vec_14711 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_14712);
												mem_vec_14712 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_14713);
												mem_vec_14713 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_14714);
												mem_vec_14714 = vec_46;
												vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_14715);
												mem_vec_14715 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);
												vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_14716);
												mem_vec_14716 = vec_49;
												vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_14717);
												mem_vec_14717 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_14718);
												mem_vec_14718 = vec_52;
												vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_14719);
												mem_vec_14719 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);
												vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_14720);
												mem_vec_14720 = vec_55;
												vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_14721);
												mem_vec_14721 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_18);
												vec_60 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_14704);
												mem_vec_14704 = vec_58;
												vec_62 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_14705);
												mem_vec_14705 = vec_61;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_19);
												vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_14706);
												mem_vec_14706 = vec_63;
												vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_14707);
												mem_vec_14707 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_67 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_14708);
												mem_vec_14708 = vec_66;
												vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_14709);
												mem_vec_14709 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);
												vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_14710);
												mem_vec_14710 = vec_69;
												vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_14711);
												mem_vec_14711 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);
												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_14712);
												mem_vec_14712 = vec_72;
												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_14713);
												mem_vec_14713 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);
												vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_14714);
												mem_vec_14714 = vec_75;
												vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_14715);
												mem_vec_14715 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);
												vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_14716);
												mem_vec_14716 = vec_78;
												vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_14717);
												mem_vec_14717 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);
												vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_14718);
												mem_vec_14718 = vec_81;
												vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_14719);
												mem_vec_14719 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);
												vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_14720);
												mem_vec_14720 = vec_84;
												vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_14721);
												mem_vec_14721 = vec_86;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14704);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14705);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14706);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14707);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14708);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14709);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14710);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14711);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14712);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14713);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_14714);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_14715);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_14716);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_14717);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_14718);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_14719);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_14720);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_14721);
								}
							}
}
