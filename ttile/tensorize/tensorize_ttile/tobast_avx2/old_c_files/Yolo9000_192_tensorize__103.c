void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (512, c); T (17, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1176_p_0, cp_1, c1176, f, fp_0, f1568_p_0, f1569_p_0, fp_1, f1568_p_1, fp_2, f1568, f1569, x, xp_0, x1568_p_0, x1569_p_0, xp_1, x1568_p_1, xp_2, x1568, x1569, y, yp_0;
IND_TYPE y784 = 0;
IND_TYPE x1570 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1177 = 0;
IND_TYPE f1570 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_14112 ,mem_vec_14113 ,mem_vec_14114 ,mem_vec_14115 ,mem_vec_14116 ,mem_vec_14117 ,mem_vec_14118 ,mem_vec_14119 ,mem_vec_14120 ,mem_vec_14121 ,mem_vec_14122 ,mem_vec_14123 ,mem_vec_14124 ,mem_vec_14125 ,mem_vec_14126 ,mem_vec_14127 ,mem_vec_14128 ,mem_vec_14129 ,mem_vec_14130 ,mem_vec_14131 ,mem_vec_14132 ,mem_vec_14133 ,mem_vec_14134 ,mem_vec_14135 ,mem_vec_14136 ,mem_vec_14137 ,mem_vec_14138 ,mem_vec_14139 ,mem_vec_14140 ,mem_vec_14141 ,mem_vec_14142 ,mem_vec_14143 ,mem_vec_14144 ,mem_vec_14145 ,mem_vec_14146 ,mem_vec_14147 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 4) (512 / 128)
f1569 = 0;
f1569_p_0 = 0;
x1569 = 0;
x1569_p_0 = 0;
c1176 = 0;
c1176_p_0 = 0;
f1568 = 0;
f1568_p_1 = 0;
y = 0;
yp_0 = 0;
x1568 = 0;
x1568_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1568, xp_2 = x1568_p_1, xp_1 = x1568_p_0, xp_0 = 0;x < x1568 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14128 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_14129 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_14130 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_14131 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_14132 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_14133 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_14134 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_14135 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_14136 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_14137 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_14138 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_14139 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_14140 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_14141 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_14142 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_14143 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_14144 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_14145 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_14146 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_14147 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1176, cp_1 = c1176_p_0, cp_0 = 0;c < c1176 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14128);
												mem_vec_14128 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14129);
												mem_vec_14129 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14130);
												mem_vec_14130 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14131);
												mem_vec_14131 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14132);
												mem_vec_14132 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14133);
												mem_vec_14133 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14134);
												mem_vec_14134 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14135);
												mem_vec_14135 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14136);
												mem_vec_14136 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14137);
												mem_vec_14137 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14138);
												mem_vec_14138 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14139);
												mem_vec_14139 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14140);
												mem_vec_14140 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14141);
												mem_vec_14141 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14142);
												mem_vec_14142 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14143);
												mem_vec_14143 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14144);
												mem_vec_14144 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14145);
												mem_vec_14145 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14146);
												mem_vec_14146 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14147);
												mem_vec_14147 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14128);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_14129);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14130);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_14131);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14132);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_14133);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14134);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_14135);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14136);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_14137);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14138);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_14139);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14140);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_14141);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14142);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_14143);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14144);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_14145);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14146);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_14147);
								}
}
