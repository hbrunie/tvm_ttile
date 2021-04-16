
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (2, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 5), (Arg 6))]; T (1, x);
  T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c117_p_0, cp_1, c117, f, fp_0, f130_p_0, f131_p_0, fp_1, f130_p_1, fp_2, f130, f131, h, hp_0, x, xp_0, x113_p_0, xp_1, x113, y, yp_0;
IND_TYPE y80 = 0;
IND_TYPE x114 = 0;
IND_TYPE h72 = 0;
IND_TYPE w = 0;
IND_TYPE c118 = 0;
IND_TYPE f132 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,mem_vec_1104 ,mem_vec_1105 ,mem_vec_1106 ,mem_vec_1107 ,mem_vec_1108 ,mem_vec_1109 ,mem_vec_1110 ,mem_vec_1111 ,mem_vec_1112 ,mem_vec_1113 ,mem_vec_1114 ,mem_vec_1115 ,mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,mem_vec_1128 ,mem_vec_1129 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
f131 = 0;
f131_p_0 = 0;
f130 = 0;
f130_p_1 = 0;
x113 = 0;
x113_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c117 = 0;
c117_p_0 = 0;
							for (h = h72, hp_0 = 0;h < h72 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x113, xp_1 = x113_p_0, xp_0 = 0;x < x113 + 34;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1098 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1099 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1100 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_1101 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_1102 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1103 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1104 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_1105 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c117, cp_1 = c117_p_0, cp_0 = 0;c < c117 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1098);
												mem_vec_1098 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1099);
												mem_vec_1099 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1100);
												mem_vec_1100 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1101);
												mem_vec_1101 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1102);
												mem_vec_1102 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1103);
												mem_vec_1103 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1104);
												mem_vec_1104 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1105);
												mem_vec_1105 = vec_13;
												scal_2 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1098);
												mem_vec_1098 = vec_14;
												vec_18 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1099);
												mem_vec_1099 = vec_17;
												vec_20 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_1100);
												mem_vec_1100 = vec_19;
												vec_22 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_1101);
												mem_vec_1101 = vec_21;
												scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_24 = _mm512_set1_ps(scal_3);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_1102);
												mem_vec_1102 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_1103);
												mem_vec_1103 = vec_25;
												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1104);
												mem_vec_1104 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_1105);
												mem_vec_1105 = vec_27;
												scal_4 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1098);
												mem_vec_1098 = vec_28;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1099);
												mem_vec_1099 = vec_31;
												vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_1100);
												mem_vec_1100 = vec_33;
												vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_1101);
												mem_vec_1101 = vec_35;
												scal_5 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_38 = _mm512_set1_ps(scal_5);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1102);
												mem_vec_1102 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1103);
												mem_vec_1103 = vec_39;
												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_1104);
												mem_vec_1104 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_1105);
												mem_vec_1105 = vec_41;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1098);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1099);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1100);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1101);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1102);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1103);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1104);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1105);
								}
							}
}
