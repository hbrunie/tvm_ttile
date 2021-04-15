void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (4, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c948_p_0, cp_1, c948, f, fp_0, f1264_p_0, f1265_p_0, fp_1, f1264_p_1, fp_2, f1264, f1265, x, xp_0, x1264_p_0, x1265_p_0, xp_1, x1264_p_1, xp_2, x1264, x1265, y, yp_0;
IND_TYPE y632 = 0;
IND_TYPE x1266 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c949 = 0;
IND_TYPE f1266 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_11376 ,mem_vec_11377 ,mem_vec_11378 ,mem_vec_11379 ,mem_vec_11380 ,mem_vec_11381 ,mem_vec_11382 ,mem_vec_11383 ,mem_vec_11384 ,mem_vec_11385 ,mem_vec_11386 ,mem_vec_11387 ,mem_vec_11388 ,mem_vec_11389 ,mem_vec_11390 ,mem_vec_11391 ,mem_vec_11392 ,mem_vec_11393 ,mem_vec_11394 ,mem_vec_11395 ,mem_vec_11396 ,mem_vec_11397 ,mem_vec_11398 ,mem_vec_11399 ,mem_vec_11400 ,mem_vec_11401 ,mem_vec_11402 ,mem_vec_11403 ,mem_vec_11404 ,mem_vec_11405 ,mem_vec_11406 ,mem_vec_11407 ,mem_vec_11408 ,mem_vec_11409 ,mem_vec_11410 ,mem_vec_11411 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f1265 = 0;
f1265_p_0 = 0;
x1265 = 0;
x1265_p_0 = 0;
c948 = 0;
c948_p_0 = 0;
f1264 = 0;
f1264_p_1 = 0;
y = 0;
yp_0 = 0;
x1264 = 0;
x1264_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1264, xp_2 = x1264_p_1, xp_1 = x1264_p_0, xp_0 = 0;x < x1264 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11392 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_11393 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_11394 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_11395 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_11396 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_11397 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_11398 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_11399 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_11400 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_11401 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_11402 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_11403 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_11404 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_11405 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_11406 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_11407 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_11408 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_11409 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_11410 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_11411 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c948, cp_1 = c948_p_0, cp_0 = 0;c < c948 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11392);
												mem_vec_11392 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11393);
												mem_vec_11393 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11394);
												mem_vec_11394 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11395);
												mem_vec_11395 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11396);
												mem_vec_11396 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11397);
												mem_vec_11397 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11398);
												mem_vec_11398 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11399);
												mem_vec_11399 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11400);
												mem_vec_11400 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11401);
												mem_vec_11401 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11402);
												mem_vec_11402 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11403);
												mem_vec_11403 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11404);
												mem_vec_11404 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11405);
												mem_vec_11405 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11406);
												mem_vec_11406 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11407);
												mem_vec_11407 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11408);
												mem_vec_11408 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11409);
												mem_vec_11409 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11410);
												mem_vec_11410 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11411);
												mem_vec_11411 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_11392);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_11393);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_11394);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_11395);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_11396);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_11397);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_11398);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_11399);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11400);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_11401);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11402);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_11403);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11404);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_11405);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11406);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_11407);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11408);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_11409);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11410);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_11411);
								}
}
