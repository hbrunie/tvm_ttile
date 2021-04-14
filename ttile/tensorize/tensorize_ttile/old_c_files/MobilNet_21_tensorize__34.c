
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (2, f);
  T (1, c); T (28, x)]
*/
IND_TYPE c, cp_0, c518_p_0, cp_1, c518, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x546_p_0, x547_p_0, xp_1, x546_p_1, xp_2, x546, x547, y, yp_0;
IND_TYPE y304 = 0;
IND_TYPE x548 = 0;
IND_TYPE h268 = 0;
IND_TYPE w280 = 0;
IND_TYPE c519 = 0;
IND_TYPE f242 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4296 ,mem_vec_4297 ,mem_vec_4298 ,mem_vec_4299 ,mem_vec_4300 ,mem_vec_4301 ,mem_vec_4302 ,mem_vec_4303 ,mem_vec_4304 ,mem_vec_4305 ,mem_vec_4306 ,mem_vec_4307 ,mem_vec_4308 ,mem_vec_4309 ,mem_vec_4310 ,mem_vec_4311 ,mem_vec_4312 ,mem_vec_4313 ,mem_vec_4314 ,mem_vec_4315 ,mem_vec_4316 ,mem_vec_4317 ,mem_vec_4318 ,mem_vec_4319 ,mem_vec_4320 ,mem_vec_4321 ,mem_vec_4322 ,mem_vec_4323 ,mem_vec_4324 ,mem_vec_4325 ,mem_vec_4326 ,mem_vec_4327 ,mem_vec_4328 ,mem_vec_4329 ,mem_vec_4330 ,mem_vec_4331 ,mem_vec_4332 ,mem_vec_4333 ,mem_vec_4334 ,mem_vec_4335 ,mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
x547 = 0;
x547_p_0 = 0;
c518 = 0;
c518_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x546 = 0;
x546_p_1 = 0;
						for (h = h268, hp_0 = 0;h < h268 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w280, wp_0 = 0;w < w280 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x546, xp_2 = x546_p_1, xp_1 = x546_p_0, xp_0 = 0;x < x546 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_4297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_4298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_4299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_4300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_4301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_4302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_4303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_4304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_4305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_4306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_4307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_4308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_4309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_4310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_4311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_4312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_4313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_4314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_4315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c518, cp_1 = c518_p_0, cp_0 = 0;c < c518 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4296);
												mem_vec_4296 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4297);
												mem_vec_4297 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4298);
												mem_vec_4298 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4299);
												mem_vec_4299 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4300);
												mem_vec_4300 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4301);
												mem_vec_4301 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4302);
												mem_vec_4302 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4303);
												mem_vec_4303 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4304);
												mem_vec_4304 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4305);
												mem_vec_4305 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4306);
												mem_vec_4306 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4307);
												mem_vec_4307 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4308);
												mem_vec_4308 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4309);
												mem_vec_4309 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4310);
												mem_vec_4310 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4311);
												mem_vec_4311 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4312);
												mem_vec_4312 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4313);
												mem_vec_4313 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4314);
												mem_vec_4314 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4315);
												mem_vec_4315 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4296);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4297);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4298);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4299);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4300);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4301);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4302);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4303);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4304);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4305);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4306);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4307);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4308);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4309);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4310);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4311);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4312);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4313);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4314);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4315);
								}
							}
						}
}
