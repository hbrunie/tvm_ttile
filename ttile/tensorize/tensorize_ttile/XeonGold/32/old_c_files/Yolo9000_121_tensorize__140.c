
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
  T (3, h); T (2, c); T (4, f);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c333_p_0, cp_1, c333, f, fp_0, f418_p_0, f419_p_0, fp_1, f418_p_1, fp_2, f418, f419, h, hp_0, x, xp_0, x340_p_0, xp_1, x340, y, yp_0;
IND_TYPE y235 = 0;
IND_TYPE x341 = 0;
IND_TYPE h210 = 0;
IND_TYPE w = 0;
IND_TYPE c334 = 0;
IND_TYPE f420 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5041 ,mem_vec_5042 ,mem_vec_5043 ,mem_vec_5044 ,mem_vec_5045 ,mem_vec_5046 ,mem_vec_5047 ,mem_vec_5048 ,mem_vec_5049 ,mem_vec_5050 ,mem_vec_5051 ,mem_vec_5052 ,mem_vec_5053 ,mem_vec_5054 ,mem_vec_5055 ,mem_vec_5056 ,mem_vec_5057 ,mem_vec_5058 ,mem_vec_5059 ,mem_vec_5060 ,mem_vec_5061 ,mem_vec_5062 ,mem_vec_5063 ,mem_vec_5064 ,mem_vec_5065 ,mem_vec_5066 ,mem_vec_5067 ,mem_vec_5068 ,mem_vec_5069 ,mem_vec_5070 ,mem_vec_5071 ,mem_vec_5072 ,mem_vec_5073 ,mem_vec_5074 ,mem_vec_5075 ,mem_vec_5076 ,mem_vec_5077 ,mem_vec_5078 ,mem_vec_5079 ,mem_vec_5080 ,mem_vec_5081 ,mem_vec_5082 ,mem_vec_5083 ,mem_vec_5084 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f419 = 0;
f419_p_0 = 0;
f418 = 0;
f418_p_1 = 0;
x340 = 0;
x340_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c333 = 0;
c333_p_0 = 0;
							for (h = h210, hp_0 = 0;h < h210 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 64
								// T (x, 34) (34 / 1)
								for (x = x340, xp_1 = x340_p_0, xp_0 = 0;x < x340 + 34;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5041 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5042 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5043 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_5044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_5045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_5048 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_5049 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5050 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5051 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_5052 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_5053 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5054 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5055 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_5056 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c333, cp_1 = c333_p_0, cp_0 = 0;c < c333 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5041);
												mem_vec_5041 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5042);
												mem_vec_5042 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5043);
												mem_vec_5043 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5044);
												mem_vec_5044 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5045);
												mem_vec_5045 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5046);
												mem_vec_5046 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5047);
												mem_vec_5047 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5048);
												mem_vec_5048 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5049);
												mem_vec_5049 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5050);
												mem_vec_5050 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5051);
												mem_vec_5051 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5052);
												mem_vec_5052 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5053);
												mem_vec_5053 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5054);
												mem_vec_5054 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5055);
												mem_vec_5055 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5056);
												mem_vec_5056 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_5041);
												mem_vec_5041 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_5042);
												mem_vec_5042 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_5043);
												mem_vec_5043 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_5044);
												mem_vec_5044 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_5045);
												mem_vec_5045 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_5046);
												mem_vec_5046 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5047);
												mem_vec_5047 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5048);
												mem_vec_5048 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_5049);
												mem_vec_5049 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_5050);
												mem_vec_5050 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_5051);
												mem_vec_5051 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_5052);
												mem_vec_5052 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_5053);
												mem_vec_5053 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5054);
												mem_vec_5054 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5055);
												mem_vec_5055 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_5056);
												mem_vec_5056 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_5041);
												mem_vec_5041 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_5042);
												mem_vec_5042 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_5043);
												mem_vec_5043 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_5044);
												mem_vec_5044 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5045);
												mem_vec_5045 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_5046);
												mem_vec_5046 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5047);
												mem_vec_5047 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5048);
												mem_vec_5048 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_5049);
												mem_vec_5049 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_5050);
												mem_vec_5050 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_5051);
												mem_vec_5051 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_5052);
												mem_vec_5052 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_5053);
												mem_vec_5053 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_5054);
												mem_vec_5054 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_5055);
												mem_vec_5055 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_5056);
												mem_vec_5056 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5041);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5042);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5043);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5044);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5045);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5046);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5047);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5048);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5049);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5050);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5051);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5052);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5053);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5054);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5055);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5056);
								}
							}
}
