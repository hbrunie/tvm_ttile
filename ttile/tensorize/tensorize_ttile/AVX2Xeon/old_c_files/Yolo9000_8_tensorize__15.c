
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (68, x);
  T (3, h); T (16, c); T (17, y); T (1, x); T (2, f); T (1, c); T (4, f)]
*/
IND_TYPE c, cp_0, c404_p_0, c405_p_0, cp_1, c404_p_1, cp_2, c404, c405, f, fp_0, f254_p_0, fp_1, f254, h, hp_0, x, xp_0, x282_p_0, xp_1, x282, y, yp_0;
IND_TYPE y188 = 0;
IND_TYPE x283 = 0;
IND_TYPE h144 = 0;
IND_TYPE w = 0;
IND_TYPE c406 = 0;
IND_TYPE f255 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2636 ,mem_vec_2637 ,mem_vec_2638 ,mem_vec_2639 ,mem_vec_2640 ,mem_vec_2641 ,mem_vec_2642 ,mem_vec_2643 ,mem_vec_2644 ,mem_vec_2645 ,mem_vec_2646 ,mem_vec_2647 ,mem_vec_2648 ,mem_vec_2649 ,mem_vec_2650 ,mem_vec_2651 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
f254 = 0;
f254_p_0 = 0;
c405 = 0;
c405_p_0 = 0;
f = 0;
fp_1 = 0;
x282 = 0;
x282_p_0 = 0;
y = 0;
yp_0 = 0;
c404 = 0;
c404_p_1 = 0;
						for (h = h144, hp_0 = 0;h < h144 + 3;h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 8, f = 32
							// T (x, 68) (68 / 1)
							for (x = x282, xp_1 = x282_p_0, xp_0 = 0;x < x282 + 68;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2636 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2637 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_2638 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2639 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_2640 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2641 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_2642 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2643 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_2644 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2645 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_2646 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2647 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_2648 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2649 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_2650 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2651 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c404, cp_2 = c404_p_1, cp_1 = c404_p_0, cp_0 = 0;c < c404 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2636);
											mem_vec_2636 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2637);
											mem_vec_2637 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2638);
											mem_vec_2638 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2639);
											mem_vec_2639 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2640);
											mem_vec_2640 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2641);
											mem_vec_2641 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2642);
											mem_vec_2642 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2643);
											mem_vec_2643 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2644);
											mem_vec_2644 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2645);
											mem_vec_2645 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2646);
											mem_vec_2646 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2647);
											mem_vec_2647 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2648);
											mem_vec_2648 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2649);
											mem_vec_2649 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2650);
											mem_vec_2650 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2651);
											mem_vec_2651 = vec_23;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_2636);
											mem_vec_2636 = vec_24;
											vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_2637);
											mem_vec_2637 = vec_27;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_2638);
											mem_vec_2638 = vec_29;
											vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_2639);
											mem_vec_2639 = vec_31;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);
											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_2640);
											mem_vec_2640 = vec_33;
											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_2641);
											mem_vec_2641 = vec_35;
											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_2642);
											mem_vec_2642 = vec_36;
											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_2643);
											mem_vec_2643 = vec_37;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_2644);
											mem_vec_2644 = vec_38;
											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_2645);
											mem_vec_2645 = vec_40;
											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_2646);
											mem_vec_2646 = vec_41;
											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_2647);
											mem_vec_2647 = vec_42;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_2648);
											mem_vec_2648 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2649);
											mem_vec_2649 = vec_45;
											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2650);
											mem_vec_2650 = vec_46;
											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_2651);
											mem_vec_2651 = vec_47;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_2636);
											mem_vec_2636 = vec_48;
											vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_2637);
											mem_vec_2637 = vec_51;
											vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_2638);
											mem_vec_2638 = vec_53;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_2639);
											mem_vec_2639 = vec_55;
											scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_2640);
											mem_vec_2640 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_2641);
											mem_vec_2641 = vec_59;
											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2642);
											mem_vec_2642 = vec_60;
											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2643);
											mem_vec_2643 = vec_61;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);
											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_2644);
											mem_vec_2644 = vec_62;
											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_2645);
											mem_vec_2645 = vec_64;
											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_2646);
											mem_vec_2646 = vec_65;
											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_2647);
											mem_vec_2647 = vec_66;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_2648);
											mem_vec_2648 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_2649);
											mem_vec_2649 = vec_69;
											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_2650);
											mem_vec_2650 = vec_70;
											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_2651);
											mem_vec_2651 = vec_71;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2636);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2637);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2638);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2639);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2640);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2641);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2642);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2643);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2644);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2645);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2646);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2647);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2648);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2649);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2650);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2651);
							}
						}
}
