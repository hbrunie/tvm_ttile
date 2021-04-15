
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (4, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c690_p_0, cp_1, c690, f, fp_0, f920_p_0, f921_p_0, fp_1, f920_p_1, fp_2, f920, f921, w, wp_0, x, xp_0, x690_p_0, xp_1, x690, y, yp_0;
IND_TYPE y460 = 0;
IND_TYPE x691 = 0;
IND_TYPE h = 0;
IND_TYPE w400 = 0;
IND_TYPE c691 = 0;
IND_TYPE f922 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7208 ,mem_vec_7209 ,mem_vec_7210 ,mem_vec_7211 ,mem_vec_7212 ,mem_vec_7213 ,mem_vec_7214 ,mem_vec_7215 ,mem_vec_7216 ,mem_vec_7217 ,mem_vec_7218 ,mem_vec_7219 ,mem_vec_7220 ,mem_vec_7221 ,mem_vec_7222 ,mem_vec_7223 ,mem_vec_7224 ,mem_vec_7225 ,mem_vec_7226 ,mem_vec_7227 ,mem_vec_7228 ,mem_vec_7229 ,mem_vec_7230 ,mem_vec_7231 ,mem_vec_7232 ,mem_vec_7233 ,mem_vec_7234 ,mem_vec_7235 ,mem_vec_7236 ,mem_vec_7237 ,mem_vec_7238 ,mem_vec_7239 ,mem_vec_7240 ,mem_vec_7241 ,mem_vec_7242 ,mem_vec_7243 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
f921 = 0;
f921_p_0 = 0;
c690 = 0;
c690_p_0 = 0;
f920 = 0;
f920_p_1 = 0;
y = 0;
yp_0 = 0;
x690 = 0;
x690_p_0 = 0;
f = 0;
fp_2 = 0;
							for (w = w400, wp_0 = 0;w < w400 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 128, f = 32
								// T (x, 2) (2 / 1)
								for (x = x690, xp_1 = x690_p_0, xp_0 = 0;x < x690 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7208 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_7209 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_7210 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_7211 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_7212 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_7213 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_7214 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_7215 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_7216 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_7217 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_7218 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_7219 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_7220 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_7221 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_7222 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_7223 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c690, cp_1 = c690_p_0, cp_0 = 0;c < c690 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7208);
												mem_vec_7208 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7209);
												mem_vec_7209 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7210);
												mem_vec_7210 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7211);
												mem_vec_7211 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7212);
												mem_vec_7212 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7213);
												mem_vec_7213 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7214);
												mem_vec_7214 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7215);
												mem_vec_7215 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7216);
												mem_vec_7216 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7217);
												mem_vec_7217 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7218);
												mem_vec_7218 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7219);
												mem_vec_7219 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7220);
												mem_vec_7220 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7221);
												mem_vec_7221 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7222);
												mem_vec_7222 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7223);
												mem_vec_7223 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7208);
												mem_vec_7208 = vec_24;
												vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7209);
												mem_vec_7209 = vec_27;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7210);
												mem_vec_7210 = vec_29;
												vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7211);
												mem_vec_7211 = vec_31;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);
												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7212);
												mem_vec_7212 = vec_33;
												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7213);
												mem_vec_7213 = vec_35;
												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7214);
												mem_vec_7214 = vec_36;
												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7215);
												mem_vec_7215 = vec_37;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7216);
												mem_vec_7216 = vec_38;
												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7217);
												mem_vec_7217 = vec_40;
												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7218);
												mem_vec_7218 = vec_41;
												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7219);
												mem_vec_7219 = vec_42;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7220);
												mem_vec_7220 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7221);
												mem_vec_7221 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7222);
												mem_vec_7222 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7223);
												mem_vec_7223 = vec_47;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7208);
												mem_vec_7208 = vec_48;
												vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7209);
												mem_vec_7209 = vec_51;
												vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7210);
												mem_vec_7210 = vec_53;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7211);
												mem_vec_7211 = vec_55;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7212);
												mem_vec_7212 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7213);
												mem_vec_7213 = vec_59;
												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7214);
												mem_vec_7214 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7215);
												mem_vec_7215 = vec_61;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);
												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7216);
												mem_vec_7216 = vec_62;
												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7217);
												mem_vec_7217 = vec_64;
												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7218);
												mem_vec_7218 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7219);
												mem_vec_7219 = vec_66;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7220);
												mem_vec_7220 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7221);
												mem_vec_7221 = vec_69;
												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7222);
												mem_vec_7222 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7223);
												mem_vec_7223 = vec_71;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7208);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7209);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7210);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_7211);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7212);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7213);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7214);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_7215);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7216);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7217);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7218);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_7219);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7220);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7221);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7222);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_7223);
								}
							}
}
