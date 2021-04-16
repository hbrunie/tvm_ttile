
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c165_p_0, cp_1, c165, f, fp_0, f210_p_0, f211_p_0, fp_1, f210_p_1, fp_2, f210, f211, h, hp_0, x, xp_0, x170_p_0, xp_1, x170, y, yp_0;
IND_TYPE y115 = 0;
IND_TYPE x171 = 0;
IND_TYPE h110 = 0;
IND_TYPE w = 0;
IND_TYPE c166 = 0;
IND_TYPE f212 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2466 ,mem_vec_2467 ,mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,mem_vec_2490 ,mem_vec_2491 ,mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,mem_vec_2500 ,mem_vec_2501 ,mem_vec_2502 ,mem_vec_2503 ,mem_vec_2504 ,mem_vec_2505 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f211 = 0;
f211_p_0 = 0;
f210 = 0;
f210_p_1 = 0;
x170 = 0;
x170_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c165 = 0;
c165_p_0 = 0;
							for (h = h110, hp_0 = 0;h < h110 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x170, xp_1 = x170_p_0, xp_0 = 0;x < x170 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2466 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2467 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2468 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_2469 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_2470 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2471 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2472 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_2473 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_2474 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2475 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2476 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_2477 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_2478 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2479 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2480 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_2481 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c165, cp_1 = c165_p_0, cp_0 = 0;c < c165 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2466);
												mem_vec_2466 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2467);
												mem_vec_2467 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2468);
												mem_vec_2468 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2469);
												mem_vec_2469 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2470);
												mem_vec_2470 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2471);
												mem_vec_2471 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2472);
												mem_vec_2472 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2473);
												mem_vec_2473 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2474);
												mem_vec_2474 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2475);
												mem_vec_2475 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2476);
												mem_vec_2476 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2477);
												mem_vec_2477 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2478);
												mem_vec_2478 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2479);
												mem_vec_2479 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2480);
												mem_vec_2480 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2481);
												mem_vec_2481 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_2466);
												mem_vec_2466 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_2467);
												mem_vec_2467 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_2468);
												mem_vec_2468 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_2469);
												mem_vec_2469 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_2470);
												mem_vec_2470 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2471);
												mem_vec_2471 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2472);
												mem_vec_2472 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2473);
												mem_vec_2473 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_2474);
												mem_vec_2474 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_2475);
												mem_vec_2475 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_2476);
												mem_vec_2476 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_2477);
												mem_vec_2477 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_2478);
												mem_vec_2478 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2479);
												mem_vec_2479 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2480);
												mem_vec_2480 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2481);
												mem_vec_2481 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_2466);
												mem_vec_2466 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_2467);
												mem_vec_2467 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_2468);
												mem_vec_2468 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_2469);
												mem_vec_2469 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_2470);
												mem_vec_2470 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2471);
												mem_vec_2471 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2472);
												mem_vec_2472 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2473);
												mem_vec_2473 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_2474);
												mem_vec_2474 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_2475);
												mem_vec_2475 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_2476);
												mem_vec_2476 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_2477);
												mem_vec_2477 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_2478);
												mem_vec_2478 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2479);
												mem_vec_2479 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_2480);
												mem_vec_2480 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2481);
												mem_vec_2481 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2466);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2467);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2468);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2469);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2470);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2471);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2472);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2473);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2474);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2475);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2476);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2477);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2478);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2479);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2480);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2481);
								}
							}
}
