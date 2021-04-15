void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (512, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1170_p_0, cp_1, c1170, f, fp_0, f1560_p_0, f1561_p_0, fp_1, f1560_p_1, fp_2, f1560, f1561, x, xp_0, x1560_p_0, x1561_p_0, xp_1, x1560_p_1, xp_2, x1560, x1561, y, yp_0;
IND_TYPE y780 = 0;
IND_TYPE x1562 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1171 = 0;
IND_TYPE f1562 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_14040 ,mem_vec_14041 ,mem_vec_14042 ,mem_vec_14043 ,mem_vec_14044 ,mem_vec_14045 ,mem_vec_14046 ,mem_vec_14047 ,mem_vec_14048 ,mem_vec_14049 ,mem_vec_14050 ,mem_vec_14051 ,mem_vec_14052 ,mem_vec_14053 ,mem_vec_14054 ,mem_vec_14055 ,mem_vec_14056 ,mem_vec_14057 ,mem_vec_14058 ,mem_vec_14059 ,mem_vec_14060 ,mem_vec_14061 ,mem_vec_14062 ,mem_vec_14063 ,mem_vec_14064 ,mem_vec_14065 ,mem_vec_14066 ,mem_vec_14067 ,mem_vec_14068 ,mem_vec_14069 ,mem_vec_14070 ,mem_vec_14071 ,mem_vec_14072 ,mem_vec_14073 ,mem_vec_14074 ,mem_vec_14075 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
f1561 = 0;
f1561_p_0 = 0;
x1561 = 0;
x1561_p_0 = 0;
c1170 = 0;
c1170_p_0 = 0;
f1560 = 0;
f1560_p_1 = 0;
y = 0;
yp_0 = 0;
x1560 = 0;
x1560_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1560, xp_2 = x1560_p_1, xp_1 = x1560_p_0, xp_0 = 0;x < x1560 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14056 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_14057 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_14058 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_14059 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_14060 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_14061 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_14062 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_14063 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_14064 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_14065 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_14066 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_14067 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_14068 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_14069 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_14070 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_14071 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_14072 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_14073 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_14074 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_14075 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;c < c1170 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14056);
												mem_vec_14056 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14057);
												mem_vec_14057 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14058);
												mem_vec_14058 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14059);
												mem_vec_14059 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14060);
												mem_vec_14060 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14061);
												mem_vec_14061 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14062);
												mem_vec_14062 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14063);
												mem_vec_14063 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14064);
												mem_vec_14064 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14065);
												mem_vec_14065 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14066);
												mem_vec_14066 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14067);
												mem_vec_14067 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14068);
												mem_vec_14068 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14069);
												mem_vec_14069 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14070);
												mem_vec_14070 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14071);
												mem_vec_14071 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14072);
												mem_vec_14072 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14073);
												mem_vec_14073 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14074);
												mem_vec_14074 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14075);
												mem_vec_14075 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14056);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_14057);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14058);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_14059);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14060);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_14061);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14062);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_14063);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14064);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_14065);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14066);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_14067);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14068);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_14069);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14070);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_14071);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14072);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_14073);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14074);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_14075);
								}
}
