
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (4, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c327_p_0, cp_1, c327, f, fp_0, f421_p_0, f422_p_0, fp_1, f421_p_1, fp_2, f421, f422, h, hp_0, x, xp_0, x328_p_0, xp_1, x328, y, yp_0;
IND_TYPE y224 = 0;
IND_TYPE x329 = 0;
IND_TYPE h149 = 0;
IND_TYPE w = 0;
IND_TYPE c328 = 0;
IND_TYPE f423 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,mem_vec_4345 ,mem_vec_4346 ,mem_vec_4347 ,mem_vec_4348 ,mem_vec_4349 ,mem_vec_4350 ,mem_vec_4351 ,mem_vec_4352 ,mem_vec_4353 ,mem_vec_4354 ,mem_vec_4355 ,mem_vec_4356 ,mem_vec_4357 ,mem_vec_4358 ,mem_vec_4359 ,mem_vec_4360 ,mem_vec_4361 ,mem_vec_4362 ,mem_vec_4363 ,mem_vec_4364 ,mem_vec_4365 ,mem_vec_4366 ,mem_vec_4367 ,mem_vec_4368 ,mem_vec_4369 ,mem_vec_4370 ,mem_vec_4371 ,mem_vec_4372 ,mem_vec_4373 ,mem_vec_4374 ,mem_vec_4375 ,mem_vec_4376 ,mem_vec_4377 ,mem_vec_4378 ,mem_vec_4379 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
f422 = 0;
f422_p_0 = 0;
f421 = 0;
f421_p_1 = 0;
x328 = 0;
x328_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c327 = 0;
c327_p_0 = 0;
							for (h = h149, hp_0 = 0;h < h149 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x328, xp_1 = x328_p_0, xp_0 = 0;x < x328 + 14;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4336 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4337 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_4338 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4339 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_4340 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4341 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_4342 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4343 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_4344 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4345 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_4346 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4347 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_4348 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4349 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_4350 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4351 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c327, cp_1 = c327_p_0, cp_0 = 0;c < c327 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4336);
												mem_vec_4336 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4337);
												mem_vec_4337 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4338);
												mem_vec_4338 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4339);
												mem_vec_4339 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4340);
												mem_vec_4340 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4341);
												mem_vec_4341 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4342);
												mem_vec_4342 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4343);
												mem_vec_4343 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4344);
												mem_vec_4344 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4345);
												mem_vec_4345 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4346);
												mem_vec_4346 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4347);
												mem_vec_4347 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4348);
												mem_vec_4348 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4349);
												mem_vec_4349 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4350);
												mem_vec_4350 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4351);
												mem_vec_4351 = vec_23;
												scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_4336);
												mem_vec_4336 = vec_24;
												vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_4337);
												mem_vec_4337 = vec_27;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_4338);
												mem_vec_4338 = vec_29;
												vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_4339);
												mem_vec_4339 = vec_31;
												scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);
												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_4340);
												mem_vec_4340 = vec_33;
												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_4341);
												mem_vec_4341 = vec_35;
												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_4342);
												mem_vec_4342 = vec_36;
												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_4343);
												mem_vec_4343 = vec_37;
												scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_4344);
												mem_vec_4344 = vec_38;
												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_4345);
												mem_vec_4345 = vec_40;
												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_4346);
												mem_vec_4346 = vec_41;
												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_4347);
												mem_vec_4347 = vec_42;
												scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_4348);
												mem_vec_4348 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4349);
												mem_vec_4349 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4350);
												mem_vec_4350 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_4351);
												mem_vec_4351 = vec_47;
												scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_4336);
												mem_vec_4336 = vec_48;
												vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_4337);
												mem_vec_4337 = vec_51;
												vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_4338);
												mem_vec_4338 = vec_53;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_4339);
												mem_vec_4339 = vec_55;
												scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_4340);
												mem_vec_4340 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_4341);
												mem_vec_4341 = vec_59;
												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4342);
												mem_vec_4342 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4343);
												mem_vec_4343 = vec_61;
												scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);
												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_4344);
												mem_vec_4344 = vec_62;
												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_4345);
												mem_vec_4345 = vec_64;
												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_4346);
												mem_vec_4346 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_4347);
												mem_vec_4347 = vec_66;
												scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_4348);
												mem_vec_4348 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_4349);
												mem_vec_4349 = vec_69;
												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_4350);
												mem_vec_4350 = vec_70;
												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_4351);
												mem_vec_4351 = vec_71;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4336);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4337);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4338);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4339);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4340);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4341);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4342);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4343);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4344);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4345);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4346);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4347);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4348);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4349);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4350);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4351);
								}
							}
}
