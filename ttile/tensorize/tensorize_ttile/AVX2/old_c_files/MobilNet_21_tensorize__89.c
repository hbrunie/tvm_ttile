
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, f633_p_0, f634_p_0, fp_1, f633_p_1, fp_2, f633, f634, h, hp_0, x, xp_0, x496_p_0, xp_1, x496, y, yp_0;
IND_TYPE y342 = 0;
IND_TYPE x497 = 0;
IND_TYPE h231 = 0;
IND_TYPE w = 0;
IND_TYPE c496 = 0;
IND_TYPE f635 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6352 ,mem_vec_6353 ,mem_vec_6354 ,mem_vec_6355 ,mem_vec_6356 ,mem_vec_6357 ,mem_vec_6358 ,mem_vec_6359 ,mem_vec_6360 ,mem_vec_6361 ,mem_vec_6362 ,mem_vec_6363 ,mem_vec_6364 ,mem_vec_6365 ,mem_vec_6366 ,mem_vec_6367 ,mem_vec_6368 ,mem_vec_6369 ,mem_vec_6370 ,mem_vec_6371 ,mem_vec_6372 ,mem_vec_6373 ,mem_vec_6374 ,mem_vec_6375 ,mem_vec_6376 ,mem_vec_6377 ,mem_vec_6378 ,mem_vec_6379 ,mem_vec_6380 ,mem_vec_6381 ,mem_vec_6382 ,mem_vec_6383 ,mem_vec_6384 ,mem_vec_6385 ,mem_vec_6386 ,mem_vec_6387 ,mem_vec_6388 ,mem_vec_6389 ,mem_vec_6390 ,mem_vec_6391 ,mem_vec_6392 ,mem_vec_6393 ,mem_vec_6394 ,mem_vec_6395 ,mem_vec_6396 ,mem_vec_6397 ,mem_vec_6398 ,mem_vec_6399 ,mem_vec_6400 ,mem_vec_6401 ,mem_vec_6402 ,mem_vec_6403 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
f634 = 0;
f634_p_0 = 0;
f633 = 0;
f633_p_1 = 0;
x496 = 0;
x496_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c495 = 0;
c495_p_0 = 0;
							for (h = h231, hp_0 = 0;h < h231 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x496, xp_1 = x496_p_0, xp_0 = 0;x < x496 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6352 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6353 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_6354 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6355 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_6356 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6357 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_6358 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6359 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_6360 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6361 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_6362 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6363 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_6364 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6365 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_6366 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6367 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_6368 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6369 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_6370 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6371 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											mem_vec_6372 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6373 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_6374 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6375 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c495, cp_1 = c495_p_0, cp_0 = 0;c < c495 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6352);
												mem_vec_6352 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6353);
												mem_vec_6353 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6354);
												mem_vec_6354 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6355);
												mem_vec_6355 = vec_7;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6356);
												mem_vec_6356 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6357);
												mem_vec_6357 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6358);
												mem_vec_6358 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6359);
												mem_vec_6359 = vec_13;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6360);
												mem_vec_6360 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6361);
												mem_vec_6361 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6362);
												mem_vec_6362 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6363);
												mem_vec_6363 = vec_18;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6364);
												mem_vec_6364 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6365);
												mem_vec_6365 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6366);
												mem_vec_6366 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6367);
												mem_vec_6367 = vec_23;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6368);
												mem_vec_6368 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6369);
												mem_vec_6369 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6370);
												mem_vec_6370 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6371);
												mem_vec_6371 = vec_28;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6372);
												mem_vec_6372 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6373);
												mem_vec_6373 = vec_31;
												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6374);
												mem_vec_6374 = vec_32;
												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6375);
												mem_vec_6375 = vec_33;
												scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6352);
												mem_vec_6352 = vec_34;
												vec_38 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6353);
												mem_vec_6353 = vec_37;
												vec_40 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6354);
												mem_vec_6354 = vec_39;
												vec_42 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6355);
												mem_vec_6355 = vec_41;
												scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6356);
												mem_vec_6356 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6357);
												mem_vec_6357 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6358);
												mem_vec_6358 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6359);
												mem_vec_6359 = vec_47;
												scal_8 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6360);
												mem_vec_6360 = vec_48;
												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6361);
												mem_vec_6361 = vec_50;
												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6362);
												mem_vec_6362 = vec_51;
												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6363);
												mem_vec_6363 = vec_52;
												scal_9 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);
												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6364);
												mem_vec_6364 = vec_53;
												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6365);
												mem_vec_6365 = vec_55;
												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6366);
												mem_vec_6366 = vec_56;
												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6367);
												mem_vec_6367 = vec_57;
												scal_10 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 4) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6368);
												mem_vec_6368 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6369);
												mem_vec_6369 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6370);
												mem_vec_6370 = vec_61;
												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6371);
												mem_vec_6371 = vec_62;
												scal_11 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 5) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6372);
												mem_vec_6372 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6373);
												mem_vec_6373 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6374);
												mem_vec_6374 = vec_66;
												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6375);
												mem_vec_6375 = vec_67;
												scal_12 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6352);
												mem_vec_6352 = vec_68;
												vec_72 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6353);
												mem_vec_6353 = vec_71;
												vec_74 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6354);
												mem_vec_6354 = vec_73;
												vec_76 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6355);
												mem_vec_6355 = vec_75;
												scal_13 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);
												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6356);
												mem_vec_6356 = vec_77;
												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6357);
												mem_vec_6357 = vec_79;
												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6358);
												mem_vec_6358 = vec_80;
												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6359);
												mem_vec_6359 = vec_81;
												scal_14 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);
												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6360);
												mem_vec_6360 = vec_82;
												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6361);
												mem_vec_6361 = vec_84;
												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6362);
												mem_vec_6362 = vec_85;
												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6363);
												mem_vec_6363 = vec_86;
												scal_15 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6364);
												mem_vec_6364 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6365);
												mem_vec_6365 = vec_89;
												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6366);
												mem_vec_6366 = vec_90;
												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6367);
												mem_vec_6367 = vec_91;
												scal_16 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 4) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);
												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6368);
												mem_vec_6368 = vec_92;
												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6369);
												mem_vec_6369 = vec_94;
												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6370);
												mem_vec_6370 = vec_95;
												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6371);
												mem_vec_6371 = vec_96;
												scal_17 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 5) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);
												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6372);
												mem_vec_6372 = vec_97;
												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6373);
												mem_vec_6373 = vec_99;
												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6374);
												mem_vec_6374 = vec_100;
												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6375);
												mem_vec_6375 = vec_101;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6352);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_6353);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6354);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_6355);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6356);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_6357);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6358);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_6359);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6360);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_6361);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6362);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_6363);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6364);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_6365);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6366);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_6367);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6368);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_6369);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6370);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_6371);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6372);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_6373);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6374);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_6375);
								}
							}
}
