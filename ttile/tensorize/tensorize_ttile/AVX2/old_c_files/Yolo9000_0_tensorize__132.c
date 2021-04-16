
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
  T (3, w); T (3, h); T (17, y); T (272, x); T (2, y); T (4, y)]
*/
IND_TYPE c, cp_0, c250_p_0, cp_1, c250, h, hp_0, w, wp_0, x, xp_0, x302_p_0, xp_1, x302, y, yp_0, y342_p_0, y343_p_0, yp_1, y342_p_1, yp_2, y342, y343;
IND_TYPE y344 = 0;
IND_TYPE x303 = 0;
IND_TYPE h141 = 0;
IND_TYPE w167 = 0;
IND_TYPE c251 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2032 ,mem_vec_2033 ,mem_vec_2034 ,mem_vec_2035 ,mem_vec_2036 ,mem_vec_2037 ,mem_vec_2038 ,mem_vec_2039 ,mem_vec_2040 ,mem_vec_2041 ,mem_vec_2042 ,mem_vec_2043 ,mem_vec_2044 ,mem_vec_2045 ,mem_vec_2046 ,mem_vec_2047 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
y343 = 0;
y343_p_0 = 0;
y342 = 0;
y342_p_1 = 0;
x302 = 0;
x302_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h141, hp_0 = 0;h < h141 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 2, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w167, wp_0 = 0;w < w167 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c250 = c251, c250_p_0 = 0;c250 < c251 + 3;c250 += 3, c250_p_0 += 3){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (x, 2) (2 / 1)
							for (x = x302, xp_1 = x302_p_0, xp_0 = 0;x < x302 + 2;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2032 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2033 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_2034 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2035 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_2036 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2037 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_2038 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2039 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_2040 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2041 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_2042 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2043 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_2044 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2045 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_2046 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2047 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c250, cp_1 = c250_p_0, cp_0 = 0;c < c250 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2032);
											mem_vec_2032 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2033);
											mem_vec_2033 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2034);
											mem_vec_2034 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2035);
											mem_vec_2035 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2036);
											mem_vec_2036 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2037);
											mem_vec_2037 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2038);
											mem_vec_2038 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2039);
											mem_vec_2039 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2040);
											mem_vec_2040 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2041);
											mem_vec_2041 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2042);
											mem_vec_2042 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2043);
											mem_vec_2043 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2044);
											mem_vec_2044 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2045);
											mem_vec_2045 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2046);
											mem_vec_2046 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2047);
											mem_vec_2047 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2032);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2033);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2034);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2035);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2036);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2037);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2038);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2039);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2040);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2041);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2042);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2043);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2044);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2045);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2046);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2047);
							}
						}
					}
				}
}
