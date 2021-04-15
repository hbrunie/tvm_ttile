void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (16, f); T (256, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c720_p_0, cp_1, c720, f, fp_0, f960_p_0, f961_p_0, fp_1, f960_p_1, fp_2, f960, f961, x, xp_0, x960_p_0, x961_p_0, xp_1, x960_p_1, xp_2, x960, x961, y, yp_0;
IND_TYPE y480 = 0;
IND_TYPE x962 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c721 = 0;
IND_TYPE f962 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_8640 ,mem_vec_8641 ,mem_vec_8642 ,mem_vec_8643 ,mem_vec_8644 ,mem_vec_8645 ,mem_vec_8646 ,mem_vec_8647 ,mem_vec_8648 ,mem_vec_8649 ,mem_vec_8650 ,mem_vec_8651 ,mem_vec_8652 ,mem_vec_8653 ,mem_vec_8654 ,mem_vec_8655 ,mem_vec_8656 ,mem_vec_8657 ,mem_vec_8658 ,mem_vec_8659 ,mem_vec_8660 ,mem_vec_8661 ,mem_vec_8662 ,mem_vec_8663 ,mem_vec_8664 ,mem_vec_8665 ,mem_vec_8666 ,mem_vec_8667 ,mem_vec_8668 ,mem_vec_8669 ,mem_vec_8670 ,mem_vec_8671 ,mem_vec_8672 ,mem_vec_8673 ,mem_vec_8674 ,mem_vec_8675 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f961 = 0;
f961_p_0 = 0;
x961 = 0;
x961_p_0 = 0;
c720 = 0;
c720_p_0 = 0;
f960 = 0;
f960_p_1 = 0;
y = 0;
yp_0 = 0;
x960 = 0;
x960_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x960, xp_2 = x960_p_1, xp_1 = x960_p_0, xp_0 = 0;x < x960 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8656 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_8657 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_8658 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_8659 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_8660 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_8661 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_8662 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_8663 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_8664 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_8665 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_8666 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_8667 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_8668 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_8669 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_8670 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_8671 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_8672 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_8673 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_8674 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_8675 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c720, cp_1 = c720_p_0, cp_0 = 0;c < c720 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8656);
												mem_vec_8656 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8657);
												mem_vec_8657 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8658);
												mem_vec_8658 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8659);
												mem_vec_8659 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8660);
												mem_vec_8660 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8661);
												mem_vec_8661 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8662);
												mem_vec_8662 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8663);
												mem_vec_8663 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8664);
												mem_vec_8664 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8665);
												mem_vec_8665 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8666);
												mem_vec_8666 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8667);
												mem_vec_8667 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8668);
												mem_vec_8668 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8669);
												mem_vec_8669 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8670);
												mem_vec_8670 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8671);
												mem_vec_8671 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8672);
												mem_vec_8672 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8673);
												mem_vec_8673 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8674);
												mem_vec_8674 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8675);
												mem_vec_8675 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8656);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_8657);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8658);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_8659);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8660);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_8661);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8662);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_8663);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8664);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_8665);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8666);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_8667);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8668);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_8669);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8670);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_8671);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8672);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_8673);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8674);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_8675);
								}
}
