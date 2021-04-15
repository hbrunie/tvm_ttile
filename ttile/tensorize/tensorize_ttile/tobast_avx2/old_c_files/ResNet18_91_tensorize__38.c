
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f);
  T (64, c); T (4, f)]
*/
IND_TYPE c, cp_0, c714_p_0, cp_1, c714, f, fp_0, f952_p_0, f953_p_0, fp_1, f952_p_1, fp_2, f952, f953, w, wp_0, x, xp_0, x714_p_0, xp_1, x714, y, yp_0;
IND_TYPE y476 = 0;
IND_TYPE x715 = 0;
IND_TYPE h = 0;
IND_TYPE w416 = 0;
IND_TYPE c715 = 0;
IND_TYPE f954 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7496 ,mem_vec_7497 ,mem_vec_7498 ,mem_vec_7499 ,mem_vec_7500 ,mem_vec_7501 ,mem_vec_7502 ,mem_vec_7503 ,mem_vec_7504 ,mem_vec_7505 ,mem_vec_7506 ,mem_vec_7507 ,mem_vec_7508 ,mem_vec_7509 ,mem_vec_7510 ,mem_vec_7511 ,mem_vec_7512 ,mem_vec_7513 ,mem_vec_7514 ,mem_vec_7515 ,mem_vec_7516 ,mem_vec_7517 ,mem_vec_7518 ,mem_vec_7519 ,mem_vec_7520 ,mem_vec_7521 ,mem_vec_7522 ,mem_vec_7523 ,mem_vec_7524 ,mem_vec_7525 ,mem_vec_7526 ,mem_vec_7527 ,mem_vec_7528 ,mem_vec_7529 ,mem_vec_7530 ,mem_vec_7531 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
f953 = 0;
f953_p_0 = 0;
c714 = 0;
c714_p_0 = 0;
f952 = 0;
f952_p_1 = 0;
y = 0;
yp_0 = 0;
x714 = 0;
x714_p_0 = 0;
f = 0;
fp_2 = 0;
							for (w = w416, wp_0 = 0;w < w416 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 32
								// T (x, 2) (2 / 1)
								for (x = x714, xp_1 = x714_p_0, xp_0 = 0;x < x714 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7496 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_7497 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_7498 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_7499 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_7500 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_7501 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_7502 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_7503 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_7504 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_7505 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_7506 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_7507 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_7508 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_7509 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_7510 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_7511 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c714, cp_1 = c714_p_0, cp_0 = 0;c < c714 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7496);
												mem_vec_7496 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7497);
												mem_vec_7497 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7498);
												mem_vec_7498 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7499);
												mem_vec_7499 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7500);
												mem_vec_7500 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7501);
												mem_vec_7501 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7502);
												mem_vec_7502 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7503);
												mem_vec_7503 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7504);
												mem_vec_7504 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7505);
												mem_vec_7505 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7506);
												mem_vec_7506 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7507);
												mem_vec_7507 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7508);
												mem_vec_7508 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7509);
												mem_vec_7509 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7510);
												mem_vec_7510 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7511);
												mem_vec_7511 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7496);
												mem_vec_7496 = vec_24;
												vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7497);
												mem_vec_7497 = vec_27;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7498);
												mem_vec_7498 = vec_29;
												vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7499);
												mem_vec_7499 = vec_31;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);
												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7500);
												mem_vec_7500 = vec_33;
												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7501);
												mem_vec_7501 = vec_35;
												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7502);
												mem_vec_7502 = vec_36;
												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7503);
												mem_vec_7503 = vec_37;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7504);
												mem_vec_7504 = vec_38;
												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7505);
												mem_vec_7505 = vec_40;
												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7506);
												mem_vec_7506 = vec_41;
												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7507);
												mem_vec_7507 = vec_42;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7508);
												mem_vec_7508 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7509);
												mem_vec_7509 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7510);
												mem_vec_7510 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7511);
												mem_vec_7511 = vec_47;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7496);
												mem_vec_7496 = vec_48;
												vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7497);
												mem_vec_7497 = vec_51;
												vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7498);
												mem_vec_7498 = vec_53;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7499);
												mem_vec_7499 = vec_55;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7500);
												mem_vec_7500 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7501);
												mem_vec_7501 = vec_59;
												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7502);
												mem_vec_7502 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7503);
												mem_vec_7503 = vec_61;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);
												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7504);
												mem_vec_7504 = vec_62;
												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7505);
												mem_vec_7505 = vec_64;
												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7506);
												mem_vec_7506 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7507);
												mem_vec_7507 = vec_66;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7508);
												mem_vec_7508 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7509);
												mem_vec_7509 = vec_69;
												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7510);
												mem_vec_7510 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7511);
												mem_vec_7511 = vec_71;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7496);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7497);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7498);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_7499);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7500);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7501);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7502);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_7503);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7504);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7505);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7506);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_7507);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7508);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7509);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7510);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_7511);
								}
							}
}
