void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (32, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1020_p_0, cp_1, c1020, f, fp_0, f1360_p_0, f1361_p_0, fp_1, f1360_p_1, fp_2, f1360, f1361, x, xp_0, x1360_p_0, x1361_p_0, xp_1, x1360_p_1, xp_2, x1360, x1361, y, yp_0;
IND_TYPE y680 = 0;
IND_TYPE x1362 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1021 = 0;
IND_TYPE f1362 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12240 ,mem_vec_12241 ,mem_vec_12242 ,mem_vec_12243 ,mem_vec_12244 ,mem_vec_12245 ,mem_vec_12246 ,mem_vec_12247 ,mem_vec_12248 ,mem_vec_12249 ,mem_vec_12250 ,mem_vec_12251 ,mem_vec_12252 ,mem_vec_12253 ,mem_vec_12254 ,mem_vec_12255 ,mem_vec_12256 ,mem_vec_12257 ,mem_vec_12258 ,mem_vec_12259 ,mem_vec_12260 ,mem_vec_12261 ,mem_vec_12262 ,mem_vec_12263 ,mem_vec_12264 ,mem_vec_12265 ,mem_vec_12266 ,mem_vec_12267 ,mem_vec_12268 ,mem_vec_12269 ,mem_vec_12270 ,mem_vec_12271 ,mem_vec_12272 ,mem_vec_12273 ,mem_vec_12274 ,mem_vec_12275 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1361 = 0;
f1361_p_0 = 0;
x1361 = 0;
x1361_p_0 = 0;
c1020 = 0;
c1020_p_0 = 0;
f1360 = 0;
f1360_p_1 = 0;
y = 0;
yp_0 = 0;
x1360 = 0;
x1360_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1360, xp_2 = x1360_p_1, xp_1 = x1360_p_0, xp_0 = 0;x < x1360 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12256 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_12257 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_12258 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_12259 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_12260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_12261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_12262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_12263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_12264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_12265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_12266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_12267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_12268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_12269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_12270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_12271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_12272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_12273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_12274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_12275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1020, cp_1 = c1020_p_0, cp_0 = 0;c < c1020 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12256);
												mem_vec_12256 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12257);
												mem_vec_12257 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12258);
												mem_vec_12258 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12259);
												mem_vec_12259 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12260);
												mem_vec_12260 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12261);
												mem_vec_12261 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12262);
												mem_vec_12262 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12263);
												mem_vec_12263 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12264);
												mem_vec_12264 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12265);
												mem_vec_12265 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12266);
												mem_vec_12266 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12267);
												mem_vec_12267 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12268);
												mem_vec_12268 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12269);
												mem_vec_12269 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12270);
												mem_vec_12270 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12271);
												mem_vec_12271 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12272);
												mem_vec_12272 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12273);
												mem_vec_12273 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12274);
												mem_vec_12274 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12275);
												mem_vec_12275 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12256);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_12257);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12258);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_12259);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12260);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_12261);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12262);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_12263);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12264);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_12265);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12266);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_12267);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12268);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_12269);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12270);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_12271);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12272);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_12273);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12274);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_12275);
								}
}
