void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (16, f); T (16, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1002_p_0, cp_1, c1002, f, fp_0, f1336_p_0, f1337_p_0, fp_1, f1336_p_1, fp_2, f1336, f1337, x, xp_0, x1336_p_0, x1337_p_0, xp_1, x1336_p_1, xp_2, x1336, x1337, y, yp_0;
IND_TYPE y668 = 0;
IND_TYPE x1338 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1003 = 0;
IND_TYPE f1338 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12024 ,mem_vec_12025 ,mem_vec_12026 ,mem_vec_12027 ,mem_vec_12028 ,mem_vec_12029 ,mem_vec_12030 ,mem_vec_12031 ,mem_vec_12032 ,mem_vec_12033 ,mem_vec_12034 ,mem_vec_12035 ,mem_vec_12036 ,mem_vec_12037 ,mem_vec_12038 ,mem_vec_12039 ,mem_vec_12040 ,mem_vec_12041 ,mem_vec_12042 ,mem_vec_12043 ,mem_vec_12044 ,mem_vec_12045 ,mem_vec_12046 ,mem_vec_12047 ,mem_vec_12048 ,mem_vec_12049 ,mem_vec_12050 ,mem_vec_12051 ,mem_vec_12052 ,mem_vec_12053 ,mem_vec_12054 ,mem_vec_12055 ,mem_vec_12056 ,mem_vec_12057 ,mem_vec_12058 ,mem_vec_12059 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1337 = 0;
f1337_p_0 = 0;
x1337 = 0;
x1337_p_0 = 0;
c1002 = 0;
c1002_p_0 = 0;
f1336 = 0;
f1336_p_1 = 0;
y = 0;
yp_0 = 0;
x1336 = 0;
x1336_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1336, xp_2 = x1336_p_1, xp_1 = x1336_p_0, xp_0 = 0;x < x1336 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12040 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_12041 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_12042 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_12043 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_12044 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_12045 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_12046 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_12047 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_12048 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_12049 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_12050 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_12051 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_12052 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_12053 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_12054 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_12055 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_12056 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_12057 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_12058 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_12059 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1002, cp_1 = c1002_p_0, cp_0 = 0;c < c1002 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12040);
												mem_vec_12040 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12041);
												mem_vec_12041 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12042);
												mem_vec_12042 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12043);
												mem_vec_12043 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12044);
												mem_vec_12044 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12045);
												mem_vec_12045 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12046);
												mem_vec_12046 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12047);
												mem_vec_12047 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12048);
												mem_vec_12048 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12049);
												mem_vec_12049 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12050);
												mem_vec_12050 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12051);
												mem_vec_12051 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12052);
												mem_vec_12052 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12053);
												mem_vec_12053 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12054);
												mem_vec_12054 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12055);
												mem_vec_12055 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12056);
												mem_vec_12056 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12057);
												mem_vec_12057 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12058);
												mem_vec_12058 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12059);
												mem_vec_12059 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12040);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_12041);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12042);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_12043);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12044);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_12045);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12046);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_12047);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12048);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_12049);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12050);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_12051);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12052);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_12053);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12054);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_12055);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12056);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_12057);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12058);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_12059);
								}
}
