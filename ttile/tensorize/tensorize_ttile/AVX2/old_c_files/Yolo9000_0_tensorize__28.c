
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (272, x); T (1, y); T (8, y)]
*/
IND_TYPE c, cp_0, c253_p_0, cp_1, c253, h, hp_0, w, wp_0, x, xp_0, x305_p_0, xp_1, x305, y, yp_0, y346_p_0, y347_p_0, yp_1, y346_p_1, yp_2, y346, y347;
IND_TYPE y348 = 0;
IND_TYPE x306 = 0;
IND_TYPE h143 = 0;
IND_TYPE w169 = 0;
IND_TYPE c254 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2048 ,mem_vec_2049 ,mem_vec_2050 ,mem_vec_2051 ,mem_vec_2052 ,mem_vec_2053 ,mem_vec_2054 ,mem_vec_2055 ,mem_vec_2056 ,mem_vec_2057 ,mem_vec_2058 ,mem_vec_2059 ,mem_vec_2060 ,mem_vec_2061 ,mem_vec_2062 ,mem_vec_2063 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 8) (544 / 68)
y347 = 0;
y347_p_0 = 0;
y346 = 0;
y346_p_1 = 0;
x305 = 0;
x305_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h143, hp_0 = 0;h < h143 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 2, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w169, wp_0 = 0;w < w169 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c253 = c254, c253_p_0 = 0;c253 < c254 + 3;c253 += 3, c253_p_0 += 3){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (x, 2) (2 / 1)
							for (x = x305, xp_1 = x305_p_0, xp_0 = 0;x < x305 + 2;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2048 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2049 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_2050 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2051 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_2052 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2053 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_2054 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2055 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_2056 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2057 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_2058 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2059 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_2060 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2061 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_2062 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2063 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c253, cp_1 = c253_p_0, cp_0 = 0;c < c253 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2048);
											mem_vec_2048 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2049);
											mem_vec_2049 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2050);
											mem_vec_2050 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2051);
											mem_vec_2051 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2052);
											mem_vec_2052 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2053);
											mem_vec_2053 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2054);
											mem_vec_2054 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2055);
											mem_vec_2055 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2056);
											mem_vec_2056 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2057);
											mem_vec_2057 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2058);
											mem_vec_2058 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2059);
											mem_vec_2059 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2060);
											mem_vec_2060 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2061);
											mem_vec_2061 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2062);
											mem_vec_2062 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2063);
											mem_vec_2063 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2048);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2049);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2050);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2051);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2052);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2053);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2054);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2055);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2056);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2057);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2058);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2059);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2060);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2061);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2062);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2063);
							}
						}
					}
				}
}
