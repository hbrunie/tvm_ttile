
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (4, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x56_p_0, x57_p_0, xp_1, x56_p_1, xp_2, x56, x57, y, yp_0, y42_p_0, yp_1, y42;
IND_TYPE y43 = 0;
IND_TYPE x58 = 0;
IND_TYPE h25 = 0;
IND_TYPE w22 = 0;
IND_TYPE c43 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
x57 = 0;
x57_p_0 = 0;
y42 = 0;
y42_p_0 = 0;
x56 = 0;
x56_p_1 = 0;
f = 0;
fp_0 = 0;
c42 = 0;
c42_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_2 = 0;
								for (h = h25, hp_0 = 0;h < h25 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w22, wp_0 = 0;w < w22 + 3;w += 1, wp_0 += 1){
												mem_vec_312 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_313 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_314 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_315 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_316 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_317 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_318 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_319 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_320 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_321 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_322 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_323 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_324 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_325 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_326 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_327 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;c < c42 + 8;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_312);
													mem_vec_312 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_313);
													mem_vec_313 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_314);
													mem_vec_314 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_315);
													mem_vec_315 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_316);
													mem_vec_316 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_317);
													mem_vec_317 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_318);
													mem_vec_318 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_319);
													mem_vec_319 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_320);
													mem_vec_320 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_321);
													mem_vec_321 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_322);
													mem_vec_322 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_323);
													mem_vec_323 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_324);
													mem_vec_324 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_325);
													mem_vec_325 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_326);
													mem_vec_326 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_327);
													mem_vec_327 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_312);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_313);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_314);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_315);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_316);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_317);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_318);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_319);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_320);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_321);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_322);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_323);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_324);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_325);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_326);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_327);
									}
								}
}
