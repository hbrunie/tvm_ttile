void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (1, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x48_p_0, x49_p_0, xp_1, x48_p_1, xp_2, x48, x49, y, yp_0, y36_p_0, yp_1, y36;
IND_TYPE y37 = 0;
IND_TYPE x50 = 0;
IND_TYPE h21 = 0;
IND_TYPE w18 = 0;
IND_TYPE c37 = 0;
IND_TYPE f21 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
x49 = 0;
x49_p_0 = 0;
y36 = 0;
y36_p_0 = 0;
x48 = 0;
x48_p_1 = 0;
f = 0;
fp_0 = 0;
c36 = 0;
c36_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_2 = 0;
								for (h = h21, hp_0 = 0;h < h21 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w18, wp_0 = 0;w < w18 + 3;w += 1, wp_0 += 1){
												mem_vec_256 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_257 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_258 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_259 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c36, cp_1 = c36_p_0, cp_0 = 0;c < c36 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_256);
													mem_vec_256 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_257);
													mem_vec_257 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_258);
													mem_vec_258 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_259);
													mem_vec_259 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_260);
													mem_vec_260 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_261);
													mem_vec_261 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_262);
													mem_vec_262 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_263);
													mem_vec_263 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_264);
													mem_vec_264 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_265);
													mem_vec_265 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_266);
													mem_vec_266 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_267);
													mem_vec_267 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_268);
													mem_vec_268 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_269);
													mem_vec_269 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_270);
													mem_vec_270 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_271);
													mem_vec_271 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_272);
													mem_vec_272 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_273);
													mem_vec_273 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_274);
													mem_vec_274 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_275);
													mem_vec_275 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_256);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_257);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_258);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_259);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_260);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_261);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_262);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_263);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_264);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_265);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_266);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_267);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_268);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_269);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_270);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_271);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_272);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_273);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_274);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_275);
									}
								}
}
