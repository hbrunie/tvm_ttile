
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (3, w); T (3, h); T (68, y); T (8, x); T (1, y); T (2, y)]
*/
IND_TYPE c, cp_0, c463_p_0, cp_1, c463, h, hp_0, w, wp_0, x, xp_0, x587_p_0, xp_1, x587, y, yp_0, y638_p_0, y639_p_0, yp_1, y638_p_1, yp_2, y638, y639;
IND_TYPE y640 = 0;
IND_TYPE x588 = 0;
IND_TYPE h254 = 0;
IND_TYPE w316 = 0;
IND_TYPE c464 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4236 ,mem_vec_4237 ,mem_vec_4238 ,mem_vec_4239 ,mem_vec_4240 ,mem_vec_4241 ,mem_vec_4242 ,mem_vec_4243 ,mem_vec_4244 ,mem_vec_4245 ,mem_vec_4246 ,mem_vec_4247 ,mem_vec_4248 ,mem_vec_4249 ,mem_vec_4250 ,mem_vec_4251 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
y639 = 0;
y639_p_0 = 0;
y638 = 0;
y638_p_1 = 0;
x587 = 0;
x587_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h254, hp_0 = 0;h < h254 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 68, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w316, wp_0 = 0;w < w316 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 68, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c463 = c464, c463_p_0 = 0;c463 < c464 + 3;c463 += 3, c463_p_0 += 3){
							// y = 4, x = 68, h = 1, w = 1, c = 3, f = 32
							// T (x, 68) (68 / 1)
							for (x = x587, xp_1 = x587_p_0, xp_0 = 0;x < x587 + 68;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4236 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4237 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_4238 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4239 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_4240 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4241 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_4242 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4243 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_4244 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4245 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_4246 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4247 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_4248 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4249 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_4250 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4251 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c463, cp_1 = c463_p_0, cp_0 = 0;c < c463 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4236);
											mem_vec_4236 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4237);
											mem_vec_4237 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4238);
											mem_vec_4238 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4239);
											mem_vec_4239 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4240);
											mem_vec_4240 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4241);
											mem_vec_4241 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4242);
											mem_vec_4242 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4243);
											mem_vec_4243 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4244);
											mem_vec_4244 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4245);
											mem_vec_4245 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4246);
											mem_vec_4246 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4247);
											mem_vec_4247 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4248);
											mem_vec_4248 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4249);
											mem_vec_4249 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4250);
											mem_vec_4250 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4251);
											mem_vec_4251 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4236);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4237);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4238);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4239);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4240);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4241);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4242);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4243);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4244);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4245);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4246);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4247);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4248);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4249);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4250);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4251);
							}
						}
					}
				}
}
