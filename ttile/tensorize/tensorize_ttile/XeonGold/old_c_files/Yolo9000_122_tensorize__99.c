void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c219_p_0, cp_1, c219, f, fp_0, f282_p_0, f283_p_0, fp_1, f282_p_1, fp_2, f282, f283, h, hp_0, w, wp_0, x, xp_0, x224_p_0, xp_1, x224, y, yp_0;
IND_TYPE y151 = 0;
IND_TYPE x225 = 0;
IND_TYPE h146 = 0;
IND_TYPE w78 = 0;
IND_TYPE c220 = 0;
IND_TYPE f284 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3282 ,mem_vec_3283 ,mem_vec_3284 ,mem_vec_3285 ,mem_vec_3286 ,mem_vec_3287 ,mem_vec_3288 ,mem_vec_3289 ,mem_vec_3290 ,mem_vec_3291 ,mem_vec_3292 ,mem_vec_3293 ,mem_vec_3294 ,mem_vec_3295 ,mem_vec_3296 ,mem_vec_3297 ,mem_vec_3298 ,mem_vec_3299 ,mem_vec_3300 ,mem_vec_3301 ,mem_vec_3302 ,mem_vec_3303 ,mem_vec_3304 ,mem_vec_3305 ,mem_vec_3306 ,mem_vec_3307 ,mem_vec_3308 ,mem_vec_3309 ,mem_vec_3310 ,mem_vec_3311 ,mem_vec_3312 ,mem_vec_3313 ,mem_vec_3314 ,mem_vec_3315 ,mem_vec_3316 ,mem_vec_3317 ,mem_vec_3318 ,mem_vec_3319 ,mem_vec_3320 ,mem_vec_3321 ,mem_vec_3322 ,mem_vec_3323 ,mem_vec_3324 ,mem_vec_3325 ,mem_vec_3326 ,mem_vec_3327 ,mem_vec_3328 ,mem_vec_3329 ,mem_vec_3330 ,mem_vec_3331 ,mem_vec_3332 ,mem_vec_3333 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f283 = 0;
f283_p_0 = 0;
f282 = 0;
f282_p_1 = 0;
x224 = 0;
x224_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c219 = 0;
c219_p_0 = 0;
							for (w = w78, wp_0 = 0;w < w78 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x224, xp_1 = x224_p_0, xp_0 = 0;x < x224 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (h, 3) (3 / 1)
									for (h = h146, hp_0 = 0;h < h146 + 3;h += 1, hp_0 += 1){
												mem_vec_3306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_3309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_3310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_3313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_3314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3316 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_3317 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_3318 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3319 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3320 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_3321 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_3322 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_3323 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_3324 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_3325 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_3326 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_3327 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_3328 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_3329 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												mem_vec_3330 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_3331 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_3332 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
												mem_vec_3333 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
												// T (c, 32) (32 / 1)
												for (c = c219, cp_1 = c219_p_0, cp_0 = 0;c < c219 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3306);
													mem_vec_3306 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3307);
													mem_vec_3307 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3308);
													mem_vec_3308 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3309);
													mem_vec_3309 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3310);
													mem_vec_3310 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3311);
													mem_vec_3311 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3312);
													mem_vec_3312 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3313);
													mem_vec_3313 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3314);
													mem_vec_3314 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3315);
													mem_vec_3315 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3316);
													mem_vec_3316 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3317);
													mem_vec_3317 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3318);
													mem_vec_3318 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3319);
													mem_vec_3319 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3320);
													mem_vec_3320 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3321);
													mem_vec_3321 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3322);
													mem_vec_3322 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3323);
													mem_vec_3323 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3324);
													mem_vec_3324 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3325);
													mem_vec_3325 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3326);
													mem_vec_3326 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3327);
													mem_vec_3327 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3328);
													mem_vec_3328 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3329);
													mem_vec_3329 = vec_33;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3330);
													mem_vec_3330 = vec_34;
													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3331);
													mem_vec_3331 = vec_36;
													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3332);
													mem_vec_3332 = vec_37;
													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3333);
													mem_vec_3333 = vec_38;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3306);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3307);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3308);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3309);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3310);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3311);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3312);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3313);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3314);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3315);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3316);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3317);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3318);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3319);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3320);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3321);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3322);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3323);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_3324);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_3325);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3326);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3327);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_3328);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_3329);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3330);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3331);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_3332);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_3333);
									}
								}
							}
}
