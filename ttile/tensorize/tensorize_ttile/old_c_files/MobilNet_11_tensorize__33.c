
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, h, hp_0, w, wp_0, x, xp_0, x368_p_0, x369_p_0, xp_1, x368_p_1, xp_2, x368, x369, y, yp_0;
IND_TYPE y184 = 0;
IND_TYPE x370 = 0;
IND_TYPE h164 = 0;
IND_TYPE w184 = 0;
IND_TYPE c277 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2300 ,mem_vec_2301 ,mem_vec_2302 ,mem_vec_2303 ,mem_vec_2304 ,mem_vec_2305 ,mem_vec_2306 ,mem_vec_2307 ,mem_vec_2308 ,mem_vec_2309 ,mem_vec_2310 ,mem_vec_2311 ,mem_vec_2312 ,mem_vec_2313 ,mem_vec_2314 ,mem_vec_2315 ,mem_vec_2316 ,mem_vec_2317 ,mem_vec_2318 ,mem_vec_2319 ,mem_vec_2320 ,mem_vec_2321 ,mem_vec_2322 ,mem_vec_2323 ,mem_vec_2324 ,mem_vec_2325 ,mem_vec_2326 ,mem_vec_2327 ,mem_vec_2328 ,mem_vec_2329 ,mem_vec_2330 ,mem_vec_2331 ,mem_vec_2332 ,mem_vec_2333 ,mem_vec_2334 ,mem_vec_2335 ,mem_vec_2336 ,mem_vec_2337 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x369 = 0;
x369_p_0 = 0;
c276 = 0;
c276_p_0 = 0;
y = 0;
yp_0 = 0;
x368 = 0;
x368_p_1 = 0;
					for (h = h164, hp_0 = 0;h < h164 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w184, wp_0 = 0;w < w184 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x368, xp_2 = x368_p_1, xp_1 = x368_p_0, xp_0 = 0;x < x368 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_2309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_2310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_2311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_2312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_2313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_2314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_2315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2300);
											mem_vec_2300 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2301);
											mem_vec_2301 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2302);
											mem_vec_2302 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2303);
											mem_vec_2303 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2304);
											mem_vec_2304 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2305);
											mem_vec_2305 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2306);
											mem_vec_2306 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2307);
											mem_vec_2307 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2308);
											mem_vec_2308 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2309);
											mem_vec_2309 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2310);
											mem_vec_2310 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2311);
											mem_vec_2311 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2312);
											mem_vec_2312 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2313);
											mem_vec_2313 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2314);
											mem_vec_2314 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2315);
											mem_vec_2315 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2300);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2301);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2302);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2303);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2304);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2305);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2306);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2307);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2308);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2309);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2310);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2311);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2312);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2313);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_2314);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_2315);
							}
						}
					}
}
