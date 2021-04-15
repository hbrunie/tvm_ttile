void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (1024, c); T (1, x); T (8, f)]
*/
IND_TYPE c, cp_0, c834_p_0, cp_1, c834, f, fp_0, f1112_p_0, f1113_p_0, fp_1, f1112_p_1, fp_2, f1112, f1113, x, xp_0, x1112_p_0, x1113_p_0, xp_1, x1112_p_1, xp_2, x1112, x1113, y, yp_0;
IND_TYPE y556 = 0;
IND_TYPE x1114 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c835 = 0;
IND_TYPE f1114 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_10008 ,mem_vec_10009 ,mem_vec_10010 ,mem_vec_10011 ,mem_vec_10012 ,mem_vec_10013 ,mem_vec_10014 ,mem_vec_10015 ,mem_vec_10016 ,mem_vec_10017 ,mem_vec_10018 ,mem_vec_10019 ,mem_vec_10020 ,mem_vec_10021 ,mem_vec_10022 ,mem_vec_10023 ,mem_vec_10024 ,mem_vec_10025 ,mem_vec_10026 ,mem_vec_10027 ,mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
f1113 = 0;
f1113_p_0 = 0;
x1113 = 0;
x1113_p_0 = 0;
c834 = 0;
c834_p_0 = 0;
f1112 = 0;
f1112_p_1 = 0;
y = 0;
yp_0 = 0;
x1112 = 0;
x1112_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1112, xp_2 = x1112_p_1, xp_1 = x1112_p_0, xp_0 = 0;x < x1112 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10024 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_10025 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_10026 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_10027 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_10028 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_10029 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_10030 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_10031 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_10032 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_10033 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_10034 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_10035 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_10036 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_10037 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_10038 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_10039 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_10040 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_10041 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_10042 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_10043 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c834, cp_1 = c834_p_0, cp_0 = 0;c < c834 + 1;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10024);
												mem_vec_10024 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10025);
												mem_vec_10025 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10026);
												mem_vec_10026 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10027);
												mem_vec_10027 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10028);
												mem_vec_10028 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10029);
												mem_vec_10029 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10030);
												mem_vec_10030 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10031);
												mem_vec_10031 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10032);
												mem_vec_10032 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10033);
												mem_vec_10033 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10034);
												mem_vec_10034 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10035);
												mem_vec_10035 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10036);
												mem_vec_10036 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10037);
												mem_vec_10037 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10038);
												mem_vec_10038 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10039);
												mem_vec_10039 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10040);
												mem_vec_10040 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10041);
												mem_vec_10041 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10042);
												mem_vec_10042 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10043);
												mem_vec_10043 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10024);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_10025);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10026);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_10027);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10028);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_10029);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10030);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_10031);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10032);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_10033);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10034);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_10035);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10036);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_10037);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10038);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_10039);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_10040);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_10041);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_10042);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_10043);
								}
}
