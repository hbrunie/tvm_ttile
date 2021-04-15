void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (64, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1062_p_0, cp_1, c1062, f, fp_0, f1416_p_0, f1417_p_0, fp_1, f1416_p_1, fp_2, f1416, f1417, x, xp_0, x1416_p_0, x1417_p_0, xp_1, x1416_p_1, xp_2, x1416, x1417, y, yp_0;
IND_TYPE y708 = 0;
IND_TYPE x1418 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1063 = 0;
IND_TYPE f1418 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12744 ,mem_vec_12745 ,mem_vec_12746 ,mem_vec_12747 ,mem_vec_12748 ,mem_vec_12749 ,mem_vec_12750 ,mem_vec_12751 ,mem_vec_12752 ,mem_vec_12753 ,mem_vec_12754 ,mem_vec_12755 ,mem_vec_12756 ,mem_vec_12757 ,mem_vec_12758 ,mem_vec_12759 ,mem_vec_12760 ,mem_vec_12761 ,mem_vec_12762 ,mem_vec_12763 ,mem_vec_12764 ,mem_vec_12765 ,mem_vec_12766 ,mem_vec_12767 ,mem_vec_12768 ,mem_vec_12769 ,mem_vec_12770 ,mem_vec_12771 ,mem_vec_12772 ,mem_vec_12773 ,mem_vec_12774 ,mem_vec_12775 ,mem_vec_12776 ,mem_vec_12777 ,mem_vec_12778 ,mem_vec_12779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1417 = 0;
f1417_p_0 = 0;
x1417 = 0;
x1417_p_0 = 0;
c1062 = 0;
c1062_p_0 = 0;
f1416 = 0;
f1416_p_1 = 0;
y = 0;
yp_0 = 0;
x1416 = 0;
x1416_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;x < x1416 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12760 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_12761 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_12762 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_12763 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_12764 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_12765 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_12766 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_12767 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_12768 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_12769 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_12770 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_12771 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_12772 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_12773 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_12774 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_12775 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_12776 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_12777 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_12778 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_12779 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;c < c1062 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12760);
												mem_vec_12760 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12761);
												mem_vec_12761 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12762);
												mem_vec_12762 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12763);
												mem_vec_12763 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12764);
												mem_vec_12764 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12765);
												mem_vec_12765 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12766);
												mem_vec_12766 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12767);
												mem_vec_12767 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12768);
												mem_vec_12768 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12769);
												mem_vec_12769 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12770);
												mem_vec_12770 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12771);
												mem_vec_12771 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12772);
												mem_vec_12772 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12773);
												mem_vec_12773 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12774);
												mem_vec_12774 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12775);
												mem_vec_12775 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12776);
												mem_vec_12776 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12777);
												mem_vec_12777 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12778);
												mem_vec_12778 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12779);
												mem_vec_12779 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12760);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_12761);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12762);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_12763);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12764);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_12765);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12766);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_12767);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12768);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_12769);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12770);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_12771);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12772);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_12773);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12774);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_12775);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12776);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_12777);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12778);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_12779);
								}
}
