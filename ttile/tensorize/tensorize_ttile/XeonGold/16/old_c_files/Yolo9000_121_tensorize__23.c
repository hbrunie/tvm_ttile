
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
  T (3, h); T (1, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c171_p_0, cp_1, c171, f, fp_0, f218_p_0, f219_p_0, fp_1, f218_p_1, fp_2, f218, f219, h, hp_0, x, xp_0, x176_p_0, xp_1, x176, y, yp_0;
IND_TYPE y119 = 0;
IND_TYPE x177 = 0;
IND_TYPE h114 = 0;
IND_TYPE w = 0;
IND_TYPE c172 = 0;
IND_TYPE f220 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2546 ,mem_vec_2547 ,mem_vec_2548 ,mem_vec_2549 ,mem_vec_2550 ,mem_vec_2551 ,mem_vec_2552 ,mem_vec_2553 ,mem_vec_2554 ,mem_vec_2555 ,mem_vec_2556 ,mem_vec_2557 ,mem_vec_2558 ,mem_vec_2559 ,mem_vec_2560 ,mem_vec_2561 ,mem_vec_2562 ,mem_vec_2563 ,mem_vec_2564 ,mem_vec_2565 ,mem_vec_2566 ,mem_vec_2567 ,mem_vec_2568 ,mem_vec_2569 ,mem_vec_2570 ,mem_vec_2571 ,mem_vec_2572 ,mem_vec_2573 ,mem_vec_2574 ,mem_vec_2575 ,mem_vec_2576 ,mem_vec_2577 ,mem_vec_2578 ,mem_vec_2579 ,mem_vec_2580 ,mem_vec_2581 ,mem_vec_2582 ,mem_vec_2583 ,mem_vec_2584 ,mem_vec_2585 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f219 = 0;
f219_p_0 = 0;
f218 = 0;
f218_p_1 = 0;
x176 = 0;
x176_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c171 = 0;
c171_p_0 = 0;
							for (h = h114, hp_0 = 0;h < h114 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x176, xp_1 = x176_p_0, xp_0 = 0;x < x176 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_2547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_2548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_2549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_2550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_2551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_2552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_2553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_2554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_2555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_2556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_2557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_2558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_2559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_2560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_2561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c171, cp_1 = c171_p_0, cp_0 = 0;c < c171 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2546);
												mem_vec_2546 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2547);
												mem_vec_2547 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2548);
												mem_vec_2548 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2549);
												mem_vec_2549 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2550);
												mem_vec_2550 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2551);
												mem_vec_2551 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2552);
												mem_vec_2552 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2553);
												mem_vec_2553 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2554);
												mem_vec_2554 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2555);
												mem_vec_2555 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2556);
												mem_vec_2556 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2557);
												mem_vec_2557 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2558);
												mem_vec_2558 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2559);
												mem_vec_2559 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2560);
												mem_vec_2560 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2561);
												mem_vec_2561 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_2546);
												mem_vec_2546 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_2547);
												mem_vec_2547 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_2548);
												mem_vec_2548 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_2549);
												mem_vec_2549 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_2550);
												mem_vec_2550 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2551);
												mem_vec_2551 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2552);
												mem_vec_2552 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2553);
												mem_vec_2553 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_2554);
												mem_vec_2554 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_2555);
												mem_vec_2555 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_2556);
												mem_vec_2556 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_2557);
												mem_vec_2557 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_2558);
												mem_vec_2558 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2559);
												mem_vec_2559 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2560);
												mem_vec_2560 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2561);
												mem_vec_2561 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_2546);
												mem_vec_2546 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_2547);
												mem_vec_2547 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_2548);
												mem_vec_2548 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_2549);
												mem_vec_2549 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_2550);
												mem_vec_2550 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2551);
												mem_vec_2551 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2552);
												mem_vec_2552 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2553);
												mem_vec_2553 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_2554);
												mem_vec_2554 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_2555);
												mem_vec_2555 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_2556);
												mem_vec_2556 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_2557);
												mem_vec_2557 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_2558);
												mem_vec_2558 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2559);
												mem_vec_2559 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_2560);
												mem_vec_2560 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2561);
												mem_vec_2561 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2546);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2547);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2548);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2549);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2550);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2551);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2552);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2553);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2554);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2555);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2556);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2557);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2558);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2559);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2560);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2561);
								}
							}
}
