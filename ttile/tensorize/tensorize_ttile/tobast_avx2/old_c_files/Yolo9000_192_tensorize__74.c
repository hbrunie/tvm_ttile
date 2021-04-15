void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (1024, c); T (1, x); T (16, f)]
*/
IND_TYPE c, cp_0, c840_p_0, cp_1, c840, f, fp_0, f1120_p_0, f1121_p_0, fp_1, f1120_p_1, fp_2, f1120, f1121, x, xp_0, x1120_p_0, x1121_p_0, xp_1, x1120_p_1, xp_2, x1120, x1121, y, yp_0;
IND_TYPE y560 = 0;
IND_TYPE x1122 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c841 = 0;
IND_TYPE f1122 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_10080 ,mem_vec_10081 ,mem_vec_10082 ,mem_vec_10083 ,mem_vec_10084 ,mem_vec_10085 ,mem_vec_10086 ,mem_vec_10087 ,mem_vec_10088 ,mem_vec_10089 ,mem_vec_10090 ,mem_vec_10091 ,mem_vec_10092 ,mem_vec_10093 ,mem_vec_10094 ,mem_vec_10095 ,mem_vec_10096 ,mem_vec_10097 ,mem_vec_10098 ,mem_vec_10099 ,mem_vec_10100 ,mem_vec_10101 ,mem_vec_10102 ,mem_vec_10103 ,mem_vec_10104 ,mem_vec_10105 ,mem_vec_10106 ,mem_vec_10107 ,mem_vec_10108 ,mem_vec_10109 ,mem_vec_10110 ,mem_vec_10111 ,mem_vec_10112 ,mem_vec_10113 ,mem_vec_10114 ,mem_vec_10115 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 16) (512 / 32)
f1121 = 0;
f1121_p_0 = 0;
x1121 = 0;
x1121_p_0 = 0;
c840 = 0;
c840_p_0 = 0;
f1120 = 0;
f1120_p_1 = 0;
y = 0;
yp_0 = 0;
x1120 = 0;
x1120_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1120, xp_2 = x1120_p_1, xp_1 = x1120_p_0, xp_0 = 0;x < x1120 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10096 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_10097 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_10098 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_10099 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_10100 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_10101 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_10102 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_10103 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_10104 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_10105 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_10106 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_10107 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_10108 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_10109 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_10110 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_10111 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_10112 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_10113 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_10114 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_10115 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c840, cp_1 = c840_p_0, cp_0 = 0;c < c840 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10096);
												mem_vec_10096 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10097);
												mem_vec_10097 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10098);
												mem_vec_10098 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10099);
												mem_vec_10099 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10100);
												mem_vec_10100 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10101);
												mem_vec_10101 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10102);
												mem_vec_10102 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10103);
												mem_vec_10103 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10104);
												mem_vec_10104 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10105);
												mem_vec_10105 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10106);
												mem_vec_10106 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10107);
												mem_vec_10107 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10108);
												mem_vec_10108 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10109);
												mem_vec_10109 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10110);
												mem_vec_10110 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10111);
												mem_vec_10111 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10112);
												mem_vec_10112 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10113);
												mem_vec_10113 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10114);
												mem_vec_10114 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10115);
												mem_vec_10115 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10096);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10097);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10098);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10099);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10100);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10101);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10102);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10103);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10104);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10105);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10106);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10107);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10108);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10109);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10110);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10111);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_10112);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_10113);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_10114);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_10115);
								}
}
