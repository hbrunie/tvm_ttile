void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, c); T (2, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, x);
  T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c453_p_0, cp_1, c453, f, fp_0, f598_p_0, f599_p_0, fp_1, f598_p_1, fp_2, f598, f599, w, wp_0, x, xp_0, x453_p_0, xp_1, x453, y, yp_0;
IND_TYPE y305 = 0;
IND_TYPE x454 = 0;
IND_TYPE h = 0;
IND_TYPE w279 = 0;
IND_TYPE c454 = 0;
IND_TYPE f600 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5846 ,mem_vec_5847 ,mem_vec_5848 ,mem_vec_5849 ,mem_vec_5850 ,mem_vec_5851 ,mem_vec_5852 ,mem_vec_5853 ,mem_vec_5854 ,mem_vec_5855 ,mem_vec_5856 ,mem_vec_5857 ,mem_vec_5858 ,mem_vec_5859 ,mem_vec_5860 ,mem_vec_5861 ,mem_vec_5862 ,mem_vec_5863 ,mem_vec_5864 ,mem_vec_5865 ,mem_vec_5866 ,mem_vec_5867 ,mem_vec_5868 ,mem_vec_5869 ,mem_vec_5870 ,mem_vec_5871 ,mem_vec_5872 ,mem_vec_5873 ,mem_vec_5874 ,mem_vec_5875 ,mem_vec_5876 ,mem_vec_5877 ,mem_vec_5878 ,mem_vec_5879 ,mem_vec_5880 ,mem_vec_5881 ,mem_vec_5882 ,mem_vec_5883 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
f599 = 0;
f599_p_0 = 0;
f598 = 0;
f598_p_1 = 0;
x453 = 0;
x453_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c453 = 0;
c453_p_0 = 0;
							for (w = w279, wp_0 = 0;w < w279 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x453, xp_1 = x453_p_0, xp_0 = 0;x < x453 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5864 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5865 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5866 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5867 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5868 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5869 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_5878 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5879 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_5880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_5882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_5883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c453, cp_1 = c453_p_0, cp_0 = 0;c < c453 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5864);
												mem_vec_5864 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5865);
												mem_vec_5865 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5866);
												mem_vec_5866 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5867);
												mem_vec_5867 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5868);
												mem_vec_5868 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5869);
												mem_vec_5869 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5870);
												mem_vec_5870 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5871);
												mem_vec_5871 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5872);
												mem_vec_5872 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5873);
												mem_vec_5873 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5874);
												mem_vec_5874 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5875);
												mem_vec_5875 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5876);
												mem_vec_5876 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5877);
												mem_vec_5877 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5878);
												mem_vec_5878 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5879);
												mem_vec_5879 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5880);
												mem_vec_5880 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5881);
												mem_vec_5881 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5882);
												mem_vec_5882 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5883);
												mem_vec_5883 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_5864);
												mem_vec_5864 = vec_32;
												vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_5865);
												mem_vec_5865 = vec_35;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_5866);
												mem_vec_5866 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_5867);
												mem_vec_5867 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_5868);
												mem_vec_5868 = vec_40;
												vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_5869);
												mem_vec_5869 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_5870);
												mem_vec_5870 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5871);
												mem_vec_5871 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_5872);
												mem_vec_5872 = vec_46;
												vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_5873);
												mem_vec_5873 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);
												vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_5874);
												mem_vec_5874 = vec_49;
												vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_5875);
												mem_vec_5875 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_5876);
												mem_vec_5876 = vec_52;
												vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_5877);
												mem_vec_5877 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);
												vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_5878);
												mem_vec_5878 = vec_55;
												vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_5879);
												mem_vec_5879 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);
												vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_5880);
												mem_vec_5880 = vec_58;
												vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5881);
												mem_vec_5881 = vec_60;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);
												vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_5882);
												mem_vec_5882 = vec_61;
												vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_5883);
												mem_vec_5883 = vec_63;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_65 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_5864);
												mem_vec_5864 = vec_64;
												vec_68 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_5865);
												mem_vec_5865 = vec_67;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);
												vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_5866);
												mem_vec_5866 = vec_69;
												vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_5867);
												mem_vec_5867 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);
												vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5868);
												mem_vec_5868 = vec_72;
												vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_5869);
												mem_vec_5869 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);
												vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_5870);
												mem_vec_5870 = vec_75;
												vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_5871);
												mem_vec_5871 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);
												vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_5872);
												mem_vec_5872 = vec_78;
												vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_5873);
												mem_vec_5873 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);
												vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_5874);
												mem_vec_5874 = vec_81;
												vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_5875);
												mem_vec_5875 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);
												vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_5876);
												mem_vec_5876 = vec_84;
												vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_5877);
												mem_vec_5877 = vec_86;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);
												vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_5878);
												mem_vec_5878 = vec_87;
												vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_5879);
												mem_vec_5879 = vec_89;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);
												vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_5880);
												mem_vec_5880 = vec_90;
												vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_5881);
												mem_vec_5881 = vec_92;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);
												vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_5882);
												mem_vec_5882 = vec_93;
												vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_5883);
												mem_vec_5883 = vec_95;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5864);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5865);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5866);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5867);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5868);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5869);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5870);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5871);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5872);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5873);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5874);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5875);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5876);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5877);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5878);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5879);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5880);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5881);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5882);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5883);
								}
							}
}
