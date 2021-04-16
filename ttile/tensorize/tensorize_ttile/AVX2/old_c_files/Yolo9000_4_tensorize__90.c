
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (4, c);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (8, f);
  T (1, x); T (2, y); T (34, x)]
*/
IND_TYPE c, cp_0, c447_p_0, cp_1, c447, f, fp_0, w, wp_0, x, xp_0, x596_p_0, x597_p_0, xp_1, x596_p_1, xp_2, x596, x597, y, yp_0, y420_p_0, yp_1, y420;
IND_TYPE y421 = 0;
IND_TYPE x598 = 0;
IND_TYPE h = 0;
IND_TYPE w289 = 0;
IND_TYPE c448 = 0;
IND_TYPE f325 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5426 ,mem_vec_5427 ,mem_vec_5428 ,mem_vec_5429 ,mem_vec_5430 ,mem_vec_5431 ,mem_vec_5432 ,mem_vec_5433 ,mem_vec_5434 ,mem_vec_5435 ,mem_vec_5436 ,mem_vec_5437 ,mem_vec_5438 ,mem_vec_5439 ,mem_vec_5440 ,mem_vec_5441 ,mem_vec_5442 ,mem_vec_5443 ,mem_vec_5444 ,mem_vec_5445 ,mem_vec_5446 ,mem_vec_5447 ,mem_vec_5448 ,mem_vec_5449 ,mem_vec_5450 ,mem_vec_5451 ,mem_vec_5452 ,mem_vec_5453 ,mem_vec_5454 ,mem_vec_5455 ,mem_vec_5456 ,mem_vec_5457 ,mem_vec_5458 ,mem_vec_5459 ,mem_vec_5460 ,mem_vec_5461 ,mem_vec_5462 ,mem_vec_5463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
x597 = 0;
x597_p_0 = 0;
y420 = 0;
y420_p_0 = 0;
x596 = 0;
x596_p_1 = 0;
			for (f = f325, fp_0 = 0;f < f325 + 128;f += 16, fp_0 += 16){
					for (y = y420, yp_1 = y420_p_0, yp_0 = 0;y < y420 + 18;y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c447 = c448, c447_p_0 = 0;c447 < c448 + 64;c447 += 16, c447_p_0 += 16){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w289, wp_0 = 0;w < w289 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 16, f = 16
								// T (x, 4) (4 / 1)
								for (x = x596, xp_2 = x596_p_1, xp_1 = x596_p_0, xp_0 = 0;x < x596 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5426 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5427 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_5428 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5429 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_5430 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5431 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_5432 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5433 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_5434 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5435 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_5436 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5437 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_5438 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5439 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_5440 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5441 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_5442 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5443 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c447, cp_1 = c447_p_0, cp_0 = 0;c < c447 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5426);
												mem_vec_5426 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5427);
												mem_vec_5427 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5428);
												mem_vec_5428 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5429);
												mem_vec_5429 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5430);
												mem_vec_5430 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5431);
												mem_vec_5431 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5432);
												mem_vec_5432 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5433);
												mem_vec_5433 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5434);
												mem_vec_5434 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5435);
												mem_vec_5435 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5436);
												mem_vec_5436 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5437);
												mem_vec_5437 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5438);
												mem_vec_5438 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5439);
												mem_vec_5439 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5440);
												mem_vec_5440 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5441);
												mem_vec_5441 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5442);
												mem_vec_5442 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5443);
												mem_vec_5443 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_5426);
												mem_vec_5426 = vec_29;
												vec_33 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_5427);
												mem_vec_5427 = vec_32;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_5428);
												mem_vec_5428 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_5429);
												mem_vec_5429 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_5430);
												mem_vec_5430 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_5431);
												mem_vec_5431 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_5432);
												mem_vec_5432 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_5433);
												mem_vec_5433 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_5434);
												mem_vec_5434 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_5435);
												mem_vec_5435 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_5436);
												mem_vec_5436 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_5437);
												mem_vec_5437 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_5438);
												mem_vec_5438 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_5439);
												mem_vec_5439 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_5440);
												mem_vec_5440 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_5441);
												mem_vec_5441 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_5442);
												mem_vec_5442 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_5443);
												mem_vec_5443 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_5426);
												mem_vec_5426 = vec_58;
												vec_62 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_5427);
												mem_vec_5427 = vec_61;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_5428);
												mem_vec_5428 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_5429);
												mem_vec_5429 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_5430);
												mem_vec_5430 = vec_66;
												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_5431);
												mem_vec_5431 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_5432);
												mem_vec_5432 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_5433);
												mem_vec_5433 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_5434);
												mem_vec_5434 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_5435);
												mem_vec_5435 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_5436);
												mem_vec_5436 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_5437);
												mem_vec_5437 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_5438);
												mem_vec_5438 = vec_78;
												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_5439);
												mem_vec_5439 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_5440);
												mem_vec_5440 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_5441);
												mem_vec_5441 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_5442);
												mem_vec_5442 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_5443);
												mem_vec_5443 = vec_86;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5426);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5427);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5428);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5429);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5430);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5431);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5432);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5433);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5434);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5435);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5436);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_5437);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5438);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_5439);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5440);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_5441);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5442);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_5443);
								}
							}
						}
					}
					for (y = y420 + 18, yp_1 = y420_p_0, yp_0 = 0;y < y420 + 18 + 50;y += 10, yp_1 += 10, yp_0 += 10){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c447 = c448, c447_p_0 = 0;c447 < c448 + 64;c447 += 16, c447_p_0 += 16){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w289, wp_0 = 0;w < w289 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 16, f = 16
								// T (x, 4) (4 / 1)
								for (x = x596, xp_2 = x596_p_1, xp_1 = x596_p_0, xp_0 = 0;x < x596 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5444 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5445 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_5446 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5447 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_5448 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5449 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_5450 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5451 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_5452 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5453 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_5454 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5455 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_5456 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5457 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_5458 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5459 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_5460 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5461 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											mem_vec_5462 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_5463 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c447, cp_1 = c447_p_0, cp_0 = 0;c < c447 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5444);
												mem_vec_5444 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5445);
												mem_vec_5445 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5446);
												mem_vec_5446 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5447);
												mem_vec_5447 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5448);
												mem_vec_5448 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5449);
												mem_vec_5449 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5450);
												mem_vec_5450 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5451);
												mem_vec_5451 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5452);
												mem_vec_5452 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5453);
												mem_vec_5453 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5454);
												mem_vec_5454 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5455);
												mem_vec_5455 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5456);
												mem_vec_5456 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5457);
												mem_vec_5457 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5458);
												mem_vec_5458 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5459);
												mem_vec_5459 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5460);
												mem_vec_5460 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5461);
												mem_vec_5461 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5462);
												mem_vec_5462 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5463);
												mem_vec_5463 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_5444);
												mem_vec_5444 = vec_32;
												vec_36 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_5445);
												mem_vec_5445 = vec_35;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_5446);
												mem_vec_5446 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_5447);
												mem_vec_5447 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_5448);
												mem_vec_5448 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_5449);
												mem_vec_5449 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_5450);
												mem_vec_5450 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5451);
												mem_vec_5451 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_5452);
												mem_vec_5452 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_5453);
												mem_vec_5453 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_5454);
												mem_vec_5454 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_5455);
												mem_vec_5455 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_5456);
												mem_vec_5456 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_5457);
												mem_vec_5457 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_5458);
												mem_vec_5458 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_5459);
												mem_vec_5459 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_5460);
												mem_vec_5460 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5461);
												mem_vec_5461 = vec_60;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);
												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_5462);
												mem_vec_5462 = vec_61;
												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_5463);
												mem_vec_5463 = vec_63;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_5444);
												mem_vec_5444 = vec_64;
												vec_68 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_5445);
												mem_vec_5445 = vec_67;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_5446);
												mem_vec_5446 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_5447);
												mem_vec_5447 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_5448);
												mem_vec_5448 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_5449);
												mem_vec_5449 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_5450);
												mem_vec_5450 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_5451);
												mem_vec_5451 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_5452);
												mem_vec_5452 = vec_78;
												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_5453);
												mem_vec_5453 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_5454);
												mem_vec_5454 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_5455);
												mem_vec_5455 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_5456);
												mem_vec_5456 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_5457);
												mem_vec_5457 = vec_86;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_5458);
												mem_vec_5458 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_5459);
												mem_vec_5459 = vec_89;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);
												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_5460);
												mem_vec_5460 = vec_90;
												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_5461);
												mem_vec_5461 = vec_92;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);
												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_5462);
												mem_vec_5462 = vec_93;
												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_5463);
												mem_vec_5463 = vec_95;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5444);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5445);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5446);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5447);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5448);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5449);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5450);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5451);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5452);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5453);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5454);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_5455);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5456);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_5457);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5458);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_5459);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5460);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_5461);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5462);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_5463);
								}
							}
						}
					}
			}
}
