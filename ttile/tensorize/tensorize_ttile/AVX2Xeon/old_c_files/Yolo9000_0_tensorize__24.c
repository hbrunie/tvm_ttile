
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (3, c); Hoist_vars [c]; T (1, x);
  T (1, c); T (3, h); T (34, y); T (544, x); T (2, y); T (2, y)]
*/
IND_TYPE c, cp_0, c118_p_0, cp_1, c118, h, hp_0, x, xp_0, x134_p_0, xp_1, x134, y, yp_0, y160_p_0, y161_p_0, yp_1, y160_p_1, yp_2, y160, y161;
IND_TYPE y162 = 0;
IND_TYPE x135 = 0;
IND_TYPE h64 = 0;
IND_TYPE w = 0;
IND_TYPE c119 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
y161 = 0;
y161_p_0 = 0;
y160 = 0;
y160_p_1 = 0;
x134 = 0;
x134_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h64, hp_0 = 0;h < h64 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (c, 1) (3 / 3)
					for (c118 = c119, c118_p_0 = 0;c118 < c119 + 3;c118 += 3, c118_p_0 += 3){
						// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (x, 1) (1 / 1)
						for (x = x134, xp_1 = x134_p_0, xp_0 = 0;x < x134 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_690 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_691 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_692 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_693 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_694 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_695 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_696 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_697 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_698 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_699 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_700 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_701 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_702 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_703 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_704 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_705 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c118, cp_1 = c118_p_0, cp_0 = 0;c < c118 + 3;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_690);
										mem_vec_690 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_691);
										mem_vec_691 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_692);
										mem_vec_692 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_693);
										mem_vec_693 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_694);
										mem_vec_694 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_695);
										mem_vec_695 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_696);
										mem_vec_696 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_697);
										mem_vec_697 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_698);
										mem_vec_698 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_699);
										mem_vec_699 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_700);
										mem_vec_700 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_701);
										mem_vec_701 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_702);
										mem_vec_702 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_703);
										mem_vec_703 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_704);
										mem_vec_704 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_705);
										mem_vec_705 = vec_23;
										scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_690);
										mem_vec_690 = vec_24;
										vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_691);
										mem_vec_691 = vec_27;
										vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_692);
										mem_vec_692 = vec_29;
										vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_693);
										mem_vec_693 = vec_31;
										scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_34 = _mm256_set1_ps(scal_5);
										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_694);
										mem_vec_694 = vec_33;
										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_695);
										mem_vec_695 = vec_35;
										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_696);
										mem_vec_696 = vec_36;
										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_697);
										mem_vec_697 = vec_37;
										scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_39 = _mm256_set1_ps(scal_6);
										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_698);
										mem_vec_698 = vec_38;
										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_699);
										mem_vec_699 = vec_40;
										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_700);
										mem_vec_700 = vec_41;
										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_701);
										mem_vec_701 = vec_42;
										scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_44 = _mm256_set1_ps(scal_7);
										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_702);
										mem_vec_702 = vec_43;
										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_703);
										mem_vec_703 = vec_45;
										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_704);
										mem_vec_704 = vec_46;
										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_705);
										mem_vec_705 = vec_47;
										scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_690);
										mem_vec_690 = vec_48;
										vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_691);
										mem_vec_691 = vec_51;
										vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_692);
										mem_vec_692 = vec_53;
										vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_693);
										mem_vec_693 = vec_55;
										scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_58 = _mm256_set1_ps(scal_9);
										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_694);
										mem_vec_694 = vec_57;
										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_695);
										mem_vec_695 = vec_59;
										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_696);
										mem_vec_696 = vec_60;
										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_697);
										mem_vec_697 = vec_61;
										scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_63 = _mm256_set1_ps(scal_10);
										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_698);
										mem_vec_698 = vec_62;
										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_699);
										mem_vec_699 = vec_64;
										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_700);
										mem_vec_700 = vec_65;
										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_701);
										mem_vec_701 = vec_66;
										scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_68 = _mm256_set1_ps(scal_11);
										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_702);
										mem_vec_702 = vec_67;
										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_703);
										mem_vec_703 = vec_69;
										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_704);
										mem_vec_704 = vec_70;
										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_705);
										mem_vec_705 = vec_71;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_690);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_691);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_692);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_693);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_694);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_695);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_696);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_697);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_698);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_699);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_700);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_701);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_702);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_703);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_704);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_705);
						}
					}
				}
}
