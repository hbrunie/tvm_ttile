
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (8, f);
  T (1, x); T (4, y); T (17, x)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, f, fp_0, w, wp_0, x, xp_0, x488_p_0, x489_p_0, xp_1, x488_p_1, xp_2, x488, x489, y, yp_0, y339_p_0, yp_1, y339;
IND_TYPE y340 = 0;
IND_TYPE x490 = 0;
IND_TYPE h = 0;
IND_TYPE w235 = 0;
IND_TYPE c367 = 0;
IND_TYPE f271 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4370 ,mem_vec_4371 ,mem_vec_4372 ,mem_vec_4373 ,mem_vec_4374 ,mem_vec_4375 ,mem_vec_4376 ,mem_vec_4377 ,mem_vec_4378 ,mem_vec_4379 ,mem_vec_4380 ,mem_vec_4381 ,mem_vec_4382 ,mem_vec_4383 ,mem_vec_4384 ,mem_vec_4385 ,mem_vec_4386 ,mem_vec_4387 ,mem_vec_4388 ,mem_vec_4389 ,mem_vec_4390 ,mem_vec_4391 ,mem_vec_4392 ,mem_vec_4393 ,mem_vec_4394 ,mem_vec_4395 ,mem_vec_4396 ,mem_vec_4397 ,mem_vec_4398 ,mem_vec_4399 ,mem_vec_4400 ,mem_vec_4401 ,mem_vec_4402 ,mem_vec_4403 ,mem_vec_4404 ,mem_vec_4405 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 17) (136 / 8)
x489 = 0;
x489_p_0 = 0;
y339 = 0;
y339_p_0 = 0;
x488 = 0;
x488_p_1 = 0;
			for (f = f271, fp_0 = 0;f < f271 + 128;f += 16, fp_0 += 16){
					for (y = y339, yp_1 = y339_p_0, yp_0 = 0;y < y339 + 24;y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c366 = c367, c366_p_0 = 0;c366 < c367 + 64;c366 += 32, c366_p_0 += 32){
							// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w235, wp_0 = 0;w < w235 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 32, f = 16
								// T (x, 8) (8 / 1)
								for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;x < x488 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4370 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4371 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_4372 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4373 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_4374 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4375 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_4376 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4377 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_4378 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4379 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_4380 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4381 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_4382 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4383 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_4384 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4385 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c366, cp_1 = c366_p_0, cp_0 = 0;c < c366 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4370);
												mem_vec_4370 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4371);
												mem_vec_4371 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4372);
												mem_vec_4372 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4373);
												mem_vec_4373 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4374);
												mem_vec_4374 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4375);
												mem_vec_4375 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4376);
												mem_vec_4376 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4377);
												mem_vec_4377 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4378);
												mem_vec_4378 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4379);
												mem_vec_4379 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4380);
												mem_vec_4380 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4381);
												mem_vec_4381 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4382);
												mem_vec_4382 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4383);
												mem_vec_4383 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4384);
												mem_vec_4384 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4385);
												mem_vec_4385 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_4370);
												mem_vec_4370 = vec_26;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_4371);
												mem_vec_4371 = vec_29;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_4372);
												mem_vec_4372 = vec_31;
												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_4373);
												mem_vec_4373 = vec_33;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_4374);
												mem_vec_4374 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_4375);
												mem_vec_4375 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_4376);
												mem_vec_4376 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_4377);
												mem_vec_4377 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_4378);
												mem_vec_4378 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_4379);
												mem_vec_4379 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4380);
												mem_vec_4380 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4381);
												mem_vec_4381 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_4382);
												mem_vec_4382 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_4383);
												mem_vec_4383 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_4384);
												mem_vec_4384 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_4385);
												mem_vec_4385 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_4370);
												mem_vec_4370 = vec_52;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_4371);
												mem_vec_4371 = vec_55;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4372);
												mem_vec_4372 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4373);
												mem_vec_4373 = vec_59;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_4374);
												mem_vec_4374 = vec_60;
												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_4375);
												mem_vec_4375 = vec_62;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_4376);
												mem_vec_4376 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_4377);
												mem_vec_4377 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_4378);
												mem_vec_4378 = vec_66;
												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_4379);
												mem_vec_4379 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_4380);
												mem_vec_4380 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_4381);
												mem_vec_4381 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_4382);
												mem_vec_4382 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_4383);
												mem_vec_4383 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_4384);
												mem_vec_4384 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_4385);
												mem_vec_4385 = vec_77;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4370);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4371);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4372);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4373);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4374);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4375);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4376);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4377);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4378);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4379);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4380);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_4381);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4382);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_4383);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4384);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_4385);
								}
							}
						}
					}
					for (y = y339 + 24, yp_1 = y339_p_0, yp_0 = 0;y < y339 + 24 + 10;y += 10, yp_1 += 10, yp_0 += 10){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c366 = c367, c366_p_0 = 0;c366 < c367 + 64;c366 += 32, c366_p_0 += 32){
							// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w235, wp_0 = 0;w < w235 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 32, f = 16
								// T (x, 8) (8 / 1)
								for (x = x488, xp_2 = x488_p_1, xp_1 = x488_p_0, xp_0 = 0;x < x488 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4386 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4387 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_4388 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4389 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_4390 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4391 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_4392 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4393 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_4394 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4395 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_4396 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4397 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_4398 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4399 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_4400 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4401 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_4402 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4403 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											mem_vec_4404 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4405 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c366, cp_1 = c366_p_0, cp_0 = 0;c < c366 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4386);
												mem_vec_4386 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4387);
												mem_vec_4387 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4388);
												mem_vec_4388 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4389);
												mem_vec_4389 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4390);
												mem_vec_4390 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4391);
												mem_vec_4391 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4392);
												mem_vec_4392 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4393);
												mem_vec_4393 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4394);
												mem_vec_4394 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4395);
												mem_vec_4395 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4396);
												mem_vec_4396 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4397);
												mem_vec_4397 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4398);
												mem_vec_4398 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4399);
												mem_vec_4399 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4400);
												mem_vec_4400 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4401);
												mem_vec_4401 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4402);
												mem_vec_4402 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4403);
												mem_vec_4403 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4404);
												mem_vec_4404 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4405);
												mem_vec_4405 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_4386);
												mem_vec_4386 = vec_32;
												vec_36 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_4387);
												mem_vec_4387 = vec_35;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_4388);
												mem_vec_4388 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_4389);
												mem_vec_4389 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_4390);
												mem_vec_4390 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_4391);
												mem_vec_4391 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_4392);
												mem_vec_4392 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_4393);
												mem_vec_4393 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_4394);
												mem_vec_4394 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_4395);
												mem_vec_4395 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_4396);
												mem_vec_4396 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_4397);
												mem_vec_4397 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_4398);
												mem_vec_4398 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_4399);
												mem_vec_4399 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_4400);
												mem_vec_4400 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_4401);
												mem_vec_4401 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_4402);
												mem_vec_4402 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_4403);
												mem_vec_4403 = vec_60;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);
												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_4404);
												mem_vec_4404 = vec_61;
												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_4405);
												mem_vec_4405 = vec_63;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_4386);
												mem_vec_4386 = vec_64;
												vec_68 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_4387);
												mem_vec_4387 = vec_67;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_4388);
												mem_vec_4388 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_4389);
												mem_vec_4389 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4390);
												mem_vec_4390 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_4391);
												mem_vec_4391 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_4392);
												mem_vec_4392 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_4393);
												mem_vec_4393 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_4394);
												mem_vec_4394 = vec_78;
												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_4395);
												mem_vec_4395 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_4396);
												mem_vec_4396 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_4397);
												mem_vec_4397 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_4398);
												mem_vec_4398 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_4399);
												mem_vec_4399 = vec_86;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_4400);
												mem_vec_4400 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_4401);
												mem_vec_4401 = vec_89;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);
												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_4402);
												mem_vec_4402 = vec_90;
												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_4403);
												mem_vec_4403 = vec_92;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);
												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_4404);
												mem_vec_4404 = vec_93;
												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_4405);
												mem_vec_4405 = vec_95;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4386);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4387);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4388);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4389);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4390);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4391);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4392);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4393);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4394);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4395);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4396);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_4397);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4398);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_4399);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4400);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_4401);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4402);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_4403);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4404);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_4405);
								}
							}
						}
					}
			}
}
