void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (256, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c732_p_0, cp_1, c732, f, fp_0, f976_p_0, f977_p_0, fp_1, f976_p_1, fp_2, f976, f977, x, xp_0, x976_p_0, x977_p_0, xp_1, x976_p_1, xp_2, x976, x977, y, yp_0;
IND_TYPE y488 = 0;
IND_TYPE x978 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c733 = 0;
IND_TYPE f978 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_8784 ,mem_vec_8785 ,mem_vec_8786 ,mem_vec_8787 ,mem_vec_8788 ,mem_vec_8789 ,mem_vec_8790 ,mem_vec_8791 ,mem_vec_8792 ,mem_vec_8793 ,mem_vec_8794 ,mem_vec_8795 ,mem_vec_8796 ,mem_vec_8797 ,mem_vec_8798 ,mem_vec_8799 ,mem_vec_8800 ,mem_vec_8801 ,mem_vec_8802 ,mem_vec_8803 ,mem_vec_8804 ,mem_vec_8805 ,mem_vec_8806 ,mem_vec_8807 ,mem_vec_8808 ,mem_vec_8809 ,mem_vec_8810 ,mem_vec_8811 ,mem_vec_8812 ,mem_vec_8813 ,mem_vec_8814 ,mem_vec_8815 ,mem_vec_8816 ,mem_vec_8817 ,mem_vec_8818 ,mem_vec_8819 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
f977 = 0;
f977_p_0 = 0;
x977 = 0;
x977_p_0 = 0;
c732 = 0;
c732_p_0 = 0;
f976 = 0;
f976_p_1 = 0;
y = 0;
yp_0 = 0;
x976 = 0;
x976_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x976, xp_2 = x976_p_1, xp_1 = x976_p_0, xp_0 = 0;x < x976 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8800 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_8801 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_8802 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_8803 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_8804 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_8805 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_8806 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_8807 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_8808 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_8809 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_8810 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_8811 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_8812 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_8813 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_8814 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_8815 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_8816 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_8817 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_8818 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_8819 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c732, cp_1 = c732_p_0, cp_0 = 0;c < c732 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8800);
												mem_vec_8800 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8801);
												mem_vec_8801 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8802);
												mem_vec_8802 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8803);
												mem_vec_8803 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8804);
												mem_vec_8804 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8805);
												mem_vec_8805 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8806);
												mem_vec_8806 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8807);
												mem_vec_8807 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8808);
												mem_vec_8808 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8809);
												mem_vec_8809 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8810);
												mem_vec_8810 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8811);
												mem_vec_8811 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8812);
												mem_vec_8812 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8813);
												mem_vec_8813 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8814);
												mem_vec_8814 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8815);
												mem_vec_8815 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8816);
												mem_vec_8816 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8817);
												mem_vec_8817 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8818);
												mem_vec_8818 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8819);
												mem_vec_8819 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8800);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_8801);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8802);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_8803);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8804);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_8805);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8806);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_8807);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8808);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_8809);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8810);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_8811);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8812);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_8813);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8814);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_8815);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8816);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_8817);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8818);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_8819);
								}
}
