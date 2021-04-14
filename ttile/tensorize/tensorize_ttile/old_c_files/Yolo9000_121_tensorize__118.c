
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c498_p_0, cp_1, c498, f, fp_0, f664_p_0, f665_p_0, fp_1, f664_p_1, fp_2, f664, f665, h, hp_0, w, wp_0, x, xp_0, x498_p_0, xp_1, x498, y, yp_0;
IND_TYPE y332 = 0;
IND_TYPE x499 = 0;
IND_TYPE h332 = 0;
IND_TYPE w332 = 0;
IND_TYPE c499 = 0;
IND_TYPE f666 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7288 ,mem_vec_7289 ,mem_vec_7290 ,mem_vec_7291 ,mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,mem_vec_7300 ,mem_vec_7301 ,mem_vec_7302 ,mem_vec_7303 ,mem_vec_7304 ,mem_vec_7305 ,mem_vec_7306 ,mem_vec_7307 ,mem_vec_7308 ,mem_vec_7309 ,mem_vec_7310 ,mem_vec_7311 ,mem_vec_7312 ,mem_vec_7313 ,mem_vec_7314 ,mem_vec_7315 ,mem_vec_7316 ,mem_vec_7317 ,mem_vec_7318 ,mem_vec_7319 ,mem_vec_7320 ,mem_vec_7321 ,mem_vec_7322 ,mem_vec_7323 ,mem_vec_7324 ,mem_vec_7325 ,mem_vec_7326 ,mem_vec_7327 ,mem_vec_7328 ,mem_vec_7329 ,mem_vec_7330 ,mem_vec_7331 ,mem_vec_7332 ,mem_vec_7333 ,mem_vec_7334 ,mem_vec_7335 ,mem_vec_7336 ,mem_vec_7337 ,mem_vec_7338 ,mem_vec_7339 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f665 = 0;
f665_p_0 = 0;
c498 = 0;
c498_p_0 = 0;
f664 = 0;
f664_p_1 = 0;
y = 0;
yp_0 = 0;
x498 = 0;
x498_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h332, hp_0 = 0;h < h332 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
								// T (w, 3) (3 / 1)
								for (w = w332, wp_0 = 0;w < w332 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (x, 1) (1 / 1)
									for (x = x498, xp_1 = x498_p_0, xp_0 = 0;x < x498 + 1;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7288 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_7289 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_7290 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_7291 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_7292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_7293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_7294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_7295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_7296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_7297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_7298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_7299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_7300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_7301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_7302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_7303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_7304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_7305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_7306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_7307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_7308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_7309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_7310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_7311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
												// T (c, 64) (64 / 1)
												for (c = c498, cp_1 = c498_p_0, cp_0 = 0;c < c498 + 64;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7288);
													mem_vec_7288 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7289);
													mem_vec_7289 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7290);
													mem_vec_7290 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7291);
													mem_vec_7291 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7292);
													mem_vec_7292 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7293);
													mem_vec_7293 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7294);
													mem_vec_7294 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7295);
													mem_vec_7295 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7296);
													mem_vec_7296 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7297);
													mem_vec_7297 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7298);
													mem_vec_7298 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7299);
													mem_vec_7299 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7300);
													mem_vec_7300 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7301);
													mem_vec_7301 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7302);
													mem_vec_7302 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7303);
													mem_vec_7303 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7304);
													mem_vec_7304 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7305);
													mem_vec_7305 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7306);
													mem_vec_7306 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7307);
													mem_vec_7307 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7308);
													mem_vec_7308 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7309);
													mem_vec_7309 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7310);
													mem_vec_7310 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7311);
													mem_vec_7311 = vec_33;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7288);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7289);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_7290);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_7291);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7292);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7293);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_7294);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_7295);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7296);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7297);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_7298);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_7299);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7300);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7301);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_7302);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_7303);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7304);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7305);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_7306);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_7307);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7308);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7309);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_7310);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_7311);
									}
								}
							}
}
