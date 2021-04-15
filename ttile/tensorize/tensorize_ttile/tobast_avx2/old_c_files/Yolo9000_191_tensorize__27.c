
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (32, c); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1050_p_0, cp_1, c1050, f, fp_0, f1400_p_0, f1401_p_0, fp_1, f1400_p_1, fp_2, f1400, f1401, x, xp_0, x1400_p_0, x1401_p_0, xp_1, x1400_p_1, xp_2, x1400, x1401, y, yp_0;
IND_TYPE y700 = 0;
IND_TYPE x1402 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1051 = 0;
IND_TYPE f1402 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12600 ,mem_vec_12601 ,mem_vec_12602 ,mem_vec_12603 ,mem_vec_12604 ,mem_vec_12605 ,mem_vec_12606 ,mem_vec_12607 ,mem_vec_12608 ,mem_vec_12609 ,mem_vec_12610 ,mem_vec_12611 ,mem_vec_12612 ,mem_vec_12613 ,mem_vec_12614 ,mem_vec_12615 ,mem_vec_12616 ,mem_vec_12617 ,mem_vec_12618 ,mem_vec_12619 ,mem_vec_12620 ,mem_vec_12621 ,mem_vec_12622 ,mem_vec_12623 ,mem_vec_12624 ,mem_vec_12625 ,mem_vec_12626 ,mem_vec_12627 ,mem_vec_12628 ,mem_vec_12629 ,mem_vec_12630 ,mem_vec_12631 ,mem_vec_12632 ,mem_vec_12633 ,mem_vec_12634 ,mem_vec_12635 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
f1401 = 0;
f1401_p_0 = 0;
x1401 = 0;
x1401_p_0 = 0;
c1050 = 0;
c1050_p_0 = 0;
f1400 = 0;
f1400_p_1 = 0;
y = 0;
yp_0 = 0;
x1400 = 0;
x1400_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1400, xp_2 = x1400_p_1, xp_1 = x1400_p_0, xp_0 = 0;x < x1400 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12600 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_12601 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_12602 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_12603 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_12604 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_12605 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_12606 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_12607 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_12608 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_12609 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_12610 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_12611 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_12612 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_12613 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_12614 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_12615 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;c < c1050 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12600);
												mem_vec_12600 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12601);
												mem_vec_12601 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12602);
												mem_vec_12602 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12603);
												mem_vec_12603 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12604);
												mem_vec_12604 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12605);
												mem_vec_12605 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12606);
												mem_vec_12606 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12607);
												mem_vec_12607 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12608);
												mem_vec_12608 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12609);
												mem_vec_12609 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12610);
												mem_vec_12610 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12611);
												mem_vec_12611 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12612);
												mem_vec_12612 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12613);
												mem_vec_12613 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12614);
												mem_vec_12614 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12615);
												mem_vec_12615 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12600);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_12601);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12602);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_12603);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12604);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_12605);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12606);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_12607);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12608);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_12609);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12610);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_12611);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12612);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_12613);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12614);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_12615);
								}
}
