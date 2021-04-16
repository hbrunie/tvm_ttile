
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, x);
  T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c330_p_0, cp_1, c330, f, fp_0, f414_p_0, f415_p_0, fp_1, f414_p_1, fp_2, f414, f415, h, hp_0, x, xp_0, x337_p_0, xp_1, x337, y, yp_0;
IND_TYPE y233 = 0;
IND_TYPE x338 = 0;
IND_TYPE h208 = 0;
IND_TYPE w = 0;
IND_TYPE c331 = 0;
IND_TYPE f416 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4997 ,mem_vec_4998 ,mem_vec_4999 ,mem_vec_5000 ,mem_vec_5001 ,mem_vec_5002 ,mem_vec_5003 ,mem_vec_5004 ,mem_vec_5005 ,mem_vec_5006 ,mem_vec_5007 ,mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,mem_vec_5015 ,mem_vec_5016 ,mem_vec_5017 ,mem_vec_5018 ,mem_vec_5019 ,mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,mem_vec_5032 ,mem_vec_5033 ,mem_vec_5034 ,mem_vec_5035 ,mem_vec_5036 ,mem_vec_5037 ,mem_vec_5038 ,mem_vec_5039 ,mem_vec_5040 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f415 = 0;
f415_p_0 = 0;
f414 = 0;
f414_p_1 = 0;
x337 = 0;
x337_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c330 = 0;
c330_p_0 = 0;
							for (h = h208, hp_0 = 0;h < h208 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 64
								// T (x, 34) (34 / 1)
								for (x = x337, xp_1 = x337_p_0, xp_0 = 0;x < x337 + 34;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_5000 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_5001 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_5004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_5005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_5008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_5009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_5012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c330, cp_1 = c330_p_0, cp_0 = 0;c < c330 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4997);
												mem_vec_4997 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4998);
												mem_vec_4998 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4999);
												mem_vec_4999 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5000);
												mem_vec_5000 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5001);
												mem_vec_5001 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5002);
												mem_vec_5002 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5003);
												mem_vec_5003 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5004);
												mem_vec_5004 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5005);
												mem_vec_5005 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5006);
												mem_vec_5006 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5007);
												mem_vec_5007 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5008);
												mem_vec_5008 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5009);
												mem_vec_5009 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5010);
												mem_vec_5010 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5011);
												mem_vec_5011 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5012);
												mem_vec_5012 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_4997);
												mem_vec_4997 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_4998);
												mem_vec_4998 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_4999);
												mem_vec_4999 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_5000);
												mem_vec_5000 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_5001);
												mem_vec_5001 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_5002);
												mem_vec_5002 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5003);
												mem_vec_5003 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5004);
												mem_vec_5004 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_5005);
												mem_vec_5005 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_5006);
												mem_vec_5006 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_5007);
												mem_vec_5007 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_5008);
												mem_vec_5008 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_5009);
												mem_vec_5009 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5010);
												mem_vec_5010 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5011);
												mem_vec_5011 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_5012);
												mem_vec_5012 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_4997);
												mem_vec_4997 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_4998);
												mem_vec_4998 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_4999);
												mem_vec_4999 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_5000);
												mem_vec_5000 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5001);
												mem_vec_5001 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_5002);
												mem_vec_5002 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5003);
												mem_vec_5003 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5004);
												mem_vec_5004 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_5005);
												mem_vec_5005 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_5006);
												mem_vec_5006 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_5007);
												mem_vec_5007 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_5008);
												mem_vec_5008 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_5009);
												mem_vec_5009 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_5010);
												mem_vec_5010 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_5011);
												mem_vec_5011 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_5012);
												mem_vec_5012 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4997);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4998);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4999);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5000);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5001);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5002);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5003);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5004);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5005);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5006);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5007);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5008);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5009);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5010);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5011);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5012);
								}
							}
}
