void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (512, c); T (1, x); T (8, f)]
*/
IND_TYPE c, cp_0, c804_p_0, cp_1, c804, f, fp_0, f1072_p_0, f1073_p_0, fp_1, f1072_p_1, fp_2, f1072, f1073, x, xp_0, x1072_p_0, x1073_p_0, xp_1, x1072_p_1, xp_2, x1072, x1073, y, yp_0;
IND_TYPE y536 = 0;
IND_TYPE x1074 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c805 = 0;
IND_TYPE f1074 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9648 ,mem_vec_9649 ,mem_vec_9650 ,mem_vec_9651 ,mem_vec_9652 ,mem_vec_9653 ,mem_vec_9654 ,mem_vec_9655 ,mem_vec_9656 ,mem_vec_9657 ,mem_vec_9658 ,mem_vec_9659 ,mem_vec_9660 ,mem_vec_9661 ,mem_vec_9662 ,mem_vec_9663 ,mem_vec_9664 ,mem_vec_9665 ,mem_vec_9666 ,mem_vec_9667 ,mem_vec_9668 ,mem_vec_9669 ,mem_vec_9670 ,mem_vec_9671 ,mem_vec_9672 ,mem_vec_9673 ,mem_vec_9674 ,mem_vec_9675 ,mem_vec_9676 ,mem_vec_9677 ,mem_vec_9678 ,mem_vec_9679 ,mem_vec_9680 ,mem_vec_9681 ,mem_vec_9682 ,mem_vec_9683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
f1073 = 0;
f1073_p_0 = 0;
x1073 = 0;
x1073_p_0 = 0;
c804 = 0;
c804_p_0 = 0;
f1072 = 0;
f1072_p_1 = 0;
y = 0;
yp_0 = 0;
x1072 = 0;
x1072_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1072, xp_2 = x1072_p_1, xp_1 = x1072_p_0, xp_0 = 0;x < x1072 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9664 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_9665 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_9666 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_9667 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_9668 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_9669 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_9670 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_9671 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_9672 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_9673 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_9674 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_9675 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_9676 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_9677 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_9678 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_9679 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_9680 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_9681 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_9682 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_9683 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c804, cp_1 = c804_p_0, cp_0 = 0;c < c804 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9664);
												mem_vec_9664 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9665);
												mem_vec_9665 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9666);
												mem_vec_9666 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9667);
												mem_vec_9667 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9668);
												mem_vec_9668 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9669);
												mem_vec_9669 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9670);
												mem_vec_9670 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9671);
												mem_vec_9671 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9672);
												mem_vec_9672 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9673);
												mem_vec_9673 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9674);
												mem_vec_9674 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9675);
												mem_vec_9675 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9676);
												mem_vec_9676 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9677);
												mem_vec_9677 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9678);
												mem_vec_9678 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9679);
												mem_vec_9679 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9680);
												mem_vec_9680 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9681);
												mem_vec_9681 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9682);
												mem_vec_9682 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9683);
												mem_vec_9683 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_9664);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_9665);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_9666);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_9667);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_9668);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_9669);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_9670);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_9671);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9672);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_9673);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_9674);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_9675);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9676);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_9677);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_9678);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_9679);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_9680);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_9681);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_9682);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_9683);
								}
}
