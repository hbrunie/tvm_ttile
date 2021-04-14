
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 3), (Arg 14))]; T (2, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c552_p_0, cp_1, c552, h, hp_0, w, wp_0, x, xp_0, x736_p_0, x737_p_0, xp_1, x736_p_1, xp_2, x736, x737, y, yp_0;
IND_TYPE y368 = 0;
IND_TYPE x738 = 0;
IND_TYPE h348 = 0;
IND_TYPE w368 = 0;
IND_TYPE c553 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,mem_vec_6300 ,mem_vec_6301 ,mem_vec_6302 ,mem_vec_6303 ,mem_vec_6304 ,mem_vec_6305 ,mem_vec_6306 ,mem_vec_6307 ,mem_vec_6308 ,mem_vec_6309 ,mem_vec_6310 ,mem_vec_6311 ,mem_vec_6312 ,mem_vec_6313 ,mem_vec_6314 ,mem_vec_6315 ,mem_vec_6316 ,mem_vec_6317 ,mem_vec_6318 ,mem_vec_6319 ,mem_vec_6320 ,mem_vec_6321 ,mem_vec_6322 ,mem_vec_6323 ,mem_vec_6324 ,mem_vec_6325 ,mem_vec_6326 ,mem_vec_6327 ,mem_vec_6328 ,mem_vec_6329 ,mem_vec_6330 ,mem_vec_6331 ,mem_vec_6332 ,mem_vec_6333 ,mem_vec_6334 ,mem_vec_6335 ,mem_vec_6336 ,mem_vec_6337 ,mem_vec_6338 ,mem_vec_6339 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
x737 = 0;
x737_p_0 = 0;
c552 = 0;
c552_p_0 = 0;
y = 0;
yp_0 = 0;
x736 = 0;
x736_p_1 = 0;
					for (h = h348, hp_0 = 0;h < h348 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w368, wp_0 = 0;w < w368 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 1, c = 16, f = 32
							// T (x, 7) (7 / 1)
							for (x = x736, xp_2 = x736_p_1, xp_1 = x736_p_0, xp_0 = 0;x < x736 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_6308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_6309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_6310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_6311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c552, cp_1 = c552_p_0, cp_0 = 0;c < c552 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6292);
											mem_vec_6292 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6293);
											mem_vec_6293 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6294);
											mem_vec_6294 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6295);
											mem_vec_6295 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6296);
											mem_vec_6296 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6297);
											mem_vec_6297 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6298);
											mem_vec_6298 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6299);
											mem_vec_6299 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6300);
											mem_vec_6300 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6301);
											mem_vec_6301 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6302);
											mem_vec_6302 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6303);
											mem_vec_6303 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6304);
											mem_vec_6304 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6305);
											mem_vec_6305 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6306);
											mem_vec_6306 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6307);
											mem_vec_6307 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6308);
											mem_vec_6308 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6309);
											mem_vec_6309 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6310);
											mem_vec_6310 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6311);
											mem_vec_6311 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6292);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6293);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6294);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6295);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6296);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6297);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6298);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6299);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6300);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6301);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6302);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6303);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6304);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6305);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6306);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6307);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6308);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6309);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6310);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6311);
							}
						}
					}
}
