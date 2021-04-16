void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (16, c); T (16, f); T (2, f)]
*/
IND_TYPE c, cp_0, c486_p_0, cp_1, c486, f, fp_0, f508_p_0, f509_p_0, fp_1, f508_p_1, fp_2, f508, f509, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y314 = 0;
IND_TYPE x284 = 0;
IND_TYPE h192 = 0;
IND_TYPE w252 = 0;
IND_TYPE c487 = 0;
IND_TYPE f510 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_5648 ,mem_vec_5649 ,mem_vec_5650 ,mem_vec_5651 ,mem_vec_5652 ,mem_vec_5653 ,mem_vec_5654 ,mem_vec_5655 ,mem_vec_5656 ,mem_vec_5657 ,mem_vec_5658 ,mem_vec_5659 ,mem_vec_5660 ,mem_vec_5661 ,mem_vec_5662 ,mem_vec_5663 ,mem_vec_5664 ,mem_vec_5665 ,mem_vec_5666 ,mem_vec_5667 ,mem_vec_5668 ,mem_vec_5669 ,mem_vec_5670 ,mem_vec_5671 ,mem_vec_5672 ,mem_vec_5673 ,mem_vec_5674 ,mem_vec_5675 ,mem_vec_5676 ,mem_vec_5677 ,mem_vec_5678 ,mem_vec_5679 ,mem_vec_5680 ,mem_vec_5681 ,mem_vec_5682 ,mem_vec_5683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
f509 = 0;
f509_p_0 = 0;
f508 = 0;
f508_p_1 = 0;
c486 = 0;
c486_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (h = h192, hp_0 = 0;h < h192 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w252, wp_0 = 0;w < w252 + 3;w += 1, wp_0 += 1){
											mem_vec_5664 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5665 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_5666 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5667 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_5668 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5669 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_5670 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5671 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_5672 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5673 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_5674 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5675 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_5676 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5677 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_5678 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5679 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_5680 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5681 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_5682 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5683 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c486, cp_1 = c486_p_0, cp_0 = 0;c < c486 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5664);
												mem_vec_5664 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5665);
												mem_vec_5665 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5666);
												mem_vec_5666 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5667);
												mem_vec_5667 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5668);
												mem_vec_5668 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5669);
												mem_vec_5669 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5670);
												mem_vec_5670 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5671);
												mem_vec_5671 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5672);
												mem_vec_5672 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5673);
												mem_vec_5673 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5674);
												mem_vec_5674 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5675);
												mem_vec_5675 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5676);
												mem_vec_5676 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5677);
												mem_vec_5677 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5678);
												mem_vec_5678 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5679);
												mem_vec_5679 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5680);
												mem_vec_5680 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5681);
												mem_vec_5681 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5682);
												mem_vec_5682 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5683);
												mem_vec_5683 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5664);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5665);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5666);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_5667);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5668);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5669);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5670);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_5671);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5672);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5673);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5674);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_5675);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5676);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5677);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5678);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_5679);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5680);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5681);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5682);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_5683);
								}
							}
}
