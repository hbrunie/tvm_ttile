
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (1, c); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c888_p_0, cp_1, c888, f, fp_0, f1184_p_0, f1185_p_0, fp_1, f1184_p_1, fp_2, f1184, f1185, x, xp_0, x1184_p_0, x1185_p_0, xp_1, x1184_p_1, xp_2, x1184, x1185, y, yp_0;
IND_TYPE y592 = 0;
IND_TYPE x1186 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c889 = 0;
IND_TYPE f1186 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_10656 ,mem_vec_10657 ,mem_vec_10658 ,mem_vec_10659 ,mem_vec_10660 ,mem_vec_10661 ,mem_vec_10662 ,mem_vec_10663 ,mem_vec_10664 ,mem_vec_10665 ,mem_vec_10666 ,mem_vec_10667 ,mem_vec_10668 ,mem_vec_10669 ,mem_vec_10670 ,mem_vec_10671 ,mem_vec_10672 ,mem_vec_10673 ,mem_vec_10674 ,mem_vec_10675 ,mem_vec_10676 ,mem_vec_10677 ,mem_vec_10678 ,mem_vec_10679 ,mem_vec_10680 ,mem_vec_10681 ,mem_vec_10682 ,mem_vec_10683 ,mem_vec_10684 ,mem_vec_10685 ,mem_vec_10686 ,mem_vec_10687 ,mem_vec_10688 ,mem_vec_10689 ,mem_vec_10690 ,mem_vec_10691 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
f1185 = 0;
f1185_p_0 = 0;
x1185 = 0;
x1185_p_0 = 0;
c888 = 0;
c888_p_0 = 0;
f1184 = 0;
f1184_p_1 = 0;
y = 0;
yp_0 = 0;
x1184 = 0;
x1184_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1184, xp_2 = x1184_p_1, xp_1 = x1184_p_0, xp_0 = 0;x < x1184 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10656 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_10657 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_10658 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_10659 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_10660 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_10661 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_10662 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_10663 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_10664 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_10665 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_10666 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_10667 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_10668 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_10669 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_10670 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_10671 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
											// T (c, 1024) (1024 / 1)
											for (c = c888, cp_1 = c888_p_0, cp_0 = 0;c < c888 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10656);
												mem_vec_10656 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10657);
												mem_vec_10657 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10658);
												mem_vec_10658 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10659);
												mem_vec_10659 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10660);
												mem_vec_10660 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10661);
												mem_vec_10661 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10662);
												mem_vec_10662 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10663);
												mem_vec_10663 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10664);
												mem_vec_10664 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10665);
												mem_vec_10665 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10666);
												mem_vec_10666 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10667);
												mem_vec_10667 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10668);
												mem_vec_10668 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10669);
												mem_vec_10669 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10670);
												mem_vec_10670 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10671);
												mem_vec_10671 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10656);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10657);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10658);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10659);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10660);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10661);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10662);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10663);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10664);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10665);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10666);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10667);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10668);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10669);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10670);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10671);
								}
}
