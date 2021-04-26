
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (4, c); T (1, f);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, x);
  T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, f, fp_0, f464_p_0, f465_p_0, fp_1, f464_p_1, fp_2, f464, f465, h, hp_0, x, xp_0, x396_p_0, xp_1, x396, y, yp_0;
IND_TYPE y280 = 0;
IND_TYPE x397 = 0;
IND_TYPE h244 = 0;
IND_TYPE w = 0;
IND_TYPE c385 = 0;
IND_TYPE f466 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3380 ,mem_vec_3381 ,mem_vec_3382 ,mem_vec_3383 ,mem_vec_3384 ,mem_vec_3385 ,mem_vec_3386 ,mem_vec_3387 ,mem_vec_3388 ,mem_vec_3389 ,mem_vec_3390 ,mem_vec_3391 ,mem_vec_3392 ,mem_vec_3393 ,mem_vec_3394 ,mem_vec_3395 ,mem_vec_3396 ,mem_vec_3397 ,mem_vec_3398 ,mem_vec_3399 ,mem_vec_3400 ,mem_vec_3401 ,mem_vec_3402 ,mem_vec_3403 ,mem_vec_3404 ,mem_vec_3405 ,mem_vec_3406 ,mem_vec_3407 ,mem_vec_3408 ,mem_vec_3409 ,mem_vec_3410 ,mem_vec_3411 ,mem_vec_3412 ,mem_vec_3413 ,mem_vec_3414 ,mem_vec_3415 ,mem_vec_3416 ,mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
f465 = 0;
f465_p_0 = 0;
f464 = 0;
f464_p_1 = 0;
x396 = 0;
x396_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c384 = 0;
c384_p_0 = 0;
							for (h = h244, hp_0 = 0;h < h244 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 64
								// T (x, 28) (28 / 1)
								for (x = x396, xp_1 = x396_p_0, xp_0 = 0;x < x396 + 28;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_3383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_3384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_3387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_3388 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3389 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3390 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_3391 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_3392 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3393 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3394 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_3395 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											mem_vec_3396 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3397 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3398 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
											mem_vec_3399 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c384, cp_1 = c384_p_0, cp_0 = 0;c < c384 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3380);
												mem_vec_3380 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3381);
												mem_vec_3381 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3382);
												mem_vec_3382 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3383);
												mem_vec_3383 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3384);
												mem_vec_3384 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3385);
												mem_vec_3385 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3386);
												mem_vec_3386 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3387);
												mem_vec_3387 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3388);
												mem_vec_3388 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3389);
												mem_vec_3389 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3390);
												mem_vec_3390 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3391);
												mem_vec_3391 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3392);
												mem_vec_3392 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3393);
												mem_vec_3393 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3394);
												mem_vec_3394 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3395);
												mem_vec_3395 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3396);
												mem_vec_3396 = vec_24;
												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3397);
												mem_vec_3397 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3398);
												mem_vec_3398 = vec_27;
												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3399);
												mem_vec_3399 = vec_28;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_3380);
												mem_vec_3380 = vec_29;
												vec_33 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_3381);
												mem_vec_3381 = vec_32;
												vec_35 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_3382);
												mem_vec_3382 = vec_34;
												vec_37 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_3383);
												mem_vec_3383 = vec_36;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_3384);
												mem_vec_3384 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_3385);
												mem_vec_3385 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_3386);
												mem_vec_3386 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_3387);
												mem_vec_3387 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_3388);
												mem_vec_3388 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_3389);
												mem_vec_3389 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_3390);
												mem_vec_3390 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_3391);
												mem_vec_3391 = vec_47;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_3392);
												mem_vec_3392 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_3393);
												mem_vec_3393 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_3394);
												mem_vec_3394 = vec_51;
												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_3395);
												mem_vec_3395 = vec_52;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);
												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_3396);
												mem_vec_3396 = vec_53;
												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_3397);
												mem_vec_3397 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_3398);
												mem_vec_3398 = vec_56;
												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_3399);
												mem_vec_3399 = vec_57;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_3380);
												mem_vec_3380 = vec_58;
												vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_3381);
												mem_vec_3381 = vec_61;
												vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_3382);
												mem_vec_3382 = vec_63;
												vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_3383);
												mem_vec_3383 = vec_65;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_3384);
												mem_vec_3384 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_3385);
												mem_vec_3385 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_3386);
												mem_vec_3386 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_3387);
												mem_vec_3387 = vec_71;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_73 = _mm512_set1_ps(scal_12);
												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_3388);
												mem_vec_3388 = vec_72;
												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_3389);
												mem_vec_3389 = vec_74;
												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_3390);
												mem_vec_3390 = vec_75;
												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_3391);
												mem_vec_3391 = vec_76;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);
												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_3392);
												mem_vec_3392 = vec_77;
												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_3393);
												mem_vec_3393 = vec_79;
												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_3394);
												mem_vec_3394 = vec_80;
												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_3395);
												mem_vec_3395 = vec_81;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);
												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_3396);
												mem_vec_3396 = vec_82;
												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_3397);
												mem_vec_3397 = vec_84;
												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_3398);
												mem_vec_3398 = vec_85;
												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_3399);
												mem_vec_3399 = vec_86;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3380);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3381);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3382);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3383);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3384);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3385);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3386);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3387);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3388);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3389);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3390);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3391);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3392);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3393);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3394);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3395);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3396);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3397);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_3398);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_3399);
								}
							}
}
