void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (128, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1110_p_0, cp_1, c1110, f, fp_0, f1480_p_0, f1481_p_0, fp_1, f1480_p_1, fp_2, f1480, f1481, x, xp_0, x1480_p_0, x1481_p_0, xp_1, x1480_p_1, xp_2, x1480, x1481, y, yp_0;
IND_TYPE y740 = 0;
IND_TYPE x1482 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1111 = 0;
IND_TYPE f1482 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_13320 ,mem_vec_13321 ,mem_vec_13322 ,mem_vec_13323 ,mem_vec_13324 ,mem_vec_13325 ,mem_vec_13326 ,mem_vec_13327 ,mem_vec_13328 ,mem_vec_13329 ,mem_vec_13330 ,mem_vec_13331 ,mem_vec_13332 ,mem_vec_13333 ,mem_vec_13334 ,mem_vec_13335 ,mem_vec_13336 ,mem_vec_13337 ,mem_vec_13338 ,mem_vec_13339 ,mem_vec_13340 ,mem_vec_13341 ,mem_vec_13342 ,mem_vec_13343 ,mem_vec_13344 ,mem_vec_13345 ,mem_vec_13346 ,mem_vec_13347 ,mem_vec_13348 ,mem_vec_13349 ,mem_vec_13350 ,mem_vec_13351 ,mem_vec_13352 ,mem_vec_13353 ,mem_vec_13354 ,mem_vec_13355 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
f1481 = 0;
f1481_p_0 = 0;
x1481 = 0;
x1481_p_0 = 0;
c1110 = 0;
c1110_p_0 = 0;
f1480 = 0;
f1480_p_1 = 0;
y = 0;
yp_0 = 0;
x1480 = 0;
x1480_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x1480, xp_2 = x1480_p_1, xp_1 = x1480_p_0, xp_0 = 0;x < x1480 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13336 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_13337 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_13338 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_13339 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_13340 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_13341 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_13342 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_13343 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_13344 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_13345 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_13346 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_13347 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_13348 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_13349 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_13350 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_13351 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_13352 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_13353 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_13354 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_13355 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;c < c1110 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13336);
												mem_vec_13336 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13337);
												mem_vec_13337 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13338);
												mem_vec_13338 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13339);
												mem_vec_13339 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13340);
												mem_vec_13340 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13341);
												mem_vec_13341 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13342);
												mem_vec_13342 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13343);
												mem_vec_13343 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13344);
												mem_vec_13344 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13345);
												mem_vec_13345 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13346);
												mem_vec_13346 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13347);
												mem_vec_13347 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13348);
												mem_vec_13348 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13349);
												mem_vec_13349 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13350);
												mem_vec_13350 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13351);
												mem_vec_13351 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13352);
												mem_vec_13352 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13353);
												mem_vec_13353 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13354);
												mem_vec_13354 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13355);
												mem_vec_13355 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13336);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_13337);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13338);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_13339);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13340);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_13341);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13342);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_13343);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13344);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_13345);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13346);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_13347);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13348);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_13349);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13350);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_13351);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13352);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_13353);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13354);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_13355);
								}
}
