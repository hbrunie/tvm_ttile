
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, f);
  T (32, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1160_p_0, cp_1, c1160, f, fp_0, f1240_p_0, f1241_p_0, fp_1, f1240_p_1, fp_2, f1240, f1241, h, hp_0, x, xp_0, x1160_p_0, xp_1, x1160, y, yp_0;
IND_TYPE y712 = 0;
IND_TYPE x1161 = 0;
IND_TYPE h552 = 0;
IND_TYPE w = 0;
IND_TYPE c1161 = 0;
IND_TYPE f1242 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13862 ,mem_vec_13863 ,mem_vec_13864 ,mem_vec_13865 ,mem_vec_13866 ,mem_vec_13867 ,mem_vec_13868 ,mem_vec_13869 ,mem_vec_13870 ,mem_vec_13871 ,mem_vec_13872 ,mem_vec_13873 ,mem_vec_13874 ,mem_vec_13875 ,mem_vec_13876 ,mem_vec_13877 ,mem_vec_13878 ,mem_vec_13879 ,mem_vec_13880 ,mem_vec_13881 ,mem_vec_13882 ,mem_vec_13883 ,mem_vec_13884 ,mem_vec_13885 ,mem_vec_13886 ,mem_vec_13887 ,mem_vec_13888 ,mem_vec_13889 ,mem_vec_13890 ,mem_vec_13891 ,mem_vec_13892 ,mem_vec_13893 ,mem_vec_13894 ,mem_vec_13895 ,mem_vec_13896 ,mem_vec_13897 ,mem_vec_13898 ,mem_vec_13899 ,mem_vec_13900 ,mem_vec_13901 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
f1241 = 0;
f1241_p_0 = 0;
c1160 = 0;
c1160_p_0 = 0;
f1240 = 0;
f1240_p_1 = 0;
y = 0;
yp_0 = 0;
x1160 = 0;
x1160_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h552, hp_0 = 0;h < h552 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
								// T (x, 1) (1 / 1)
								for (x = x1160, xp_1 = x1160_p_0, xp_0 = 0;x < x1160 + 1;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13862 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_13863 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_13864 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_13865 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_13866 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_13867 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_13868 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_13869 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_13870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_13871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_13872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_13873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_13874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_13875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_13876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_13877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
											// T (c, 8) (8 / 1)
											for (c = c1160, cp_1 = c1160_p_0, cp_0 = 0;c < c1160 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13862);
												mem_vec_13862 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13863);
												mem_vec_13863 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13864);
												mem_vec_13864 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13865);
												mem_vec_13865 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13866);
												mem_vec_13866 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13867);
												mem_vec_13867 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13868);
												mem_vec_13868 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13869);
												mem_vec_13869 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13870);
												mem_vec_13870 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13871);
												mem_vec_13871 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13872);
												mem_vec_13872 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13873);
												mem_vec_13873 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13874);
												mem_vec_13874 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13875);
												mem_vec_13875 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13876);
												mem_vec_13876 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13877);
												mem_vec_13877 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_13862);
												mem_vec_13862 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_13863);
												mem_vec_13863 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_13864);
												mem_vec_13864 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_13865);
												mem_vec_13865 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_13866);
												mem_vec_13866 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_13867);
												mem_vec_13867 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_13868);
												mem_vec_13868 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_13869);
												mem_vec_13869 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_13870);
												mem_vec_13870 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_13871);
												mem_vec_13871 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_13872);
												mem_vec_13872 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_13873);
												mem_vec_13873 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_13874);
												mem_vec_13874 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_13875);
												mem_vec_13875 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_13876);
												mem_vec_13876 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_13877);
												mem_vec_13877 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_13862);
												mem_vec_13862 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_13863);
												mem_vec_13863 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_13864);
												mem_vec_13864 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_13865);
												mem_vec_13865 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_13866);
												mem_vec_13866 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_13867);
												mem_vec_13867 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_13868);
												mem_vec_13868 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_13869);
												mem_vec_13869 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_13870);
												mem_vec_13870 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_13871);
												mem_vec_13871 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_13872);
												mem_vec_13872 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_13873);
												mem_vec_13873 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_13874);
												mem_vec_13874 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_13875);
												mem_vec_13875 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_13876);
												mem_vec_13876 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_13877);
												mem_vec_13877 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13862);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13863);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13864);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13865);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13866);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13867);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13868);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13869);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13870);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13871);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13872);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13873);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13874);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13875);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13876);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13877);
								}
							}
}
