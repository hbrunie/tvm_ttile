
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (136, x); T (1, c);
  T (3, w); T (3, h); T (136, y); T (4, x); T (1, y); T (1, y)]
*/
IND_TYPE c, cp_0, c22_p_0, cp_1, c22, h, hp_0, w, wp_0, x, xp_0, x26_p_0, xp_1, x26, y, yp_0, y30_p_0, y31_p_0, yp_1, y30_p_1, yp_2, y30, y31;
IND_TYPE y32 = 0;
IND_TYPE x27 = 0;
IND_TYPE h12 = 0;
IND_TYPE w14 = 0;
IND_TYPE c23 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
y31 = 0;
y31_p_0 = 0;
y30 = 0;
y30_p_1 = 0;
x26 = 0;
x26_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h12, hp_0 = 0;h < h12 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 136, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w14, wp_0 = 0;w < w14 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 136, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c22 = c23, c22_p_0 = 0;c22 < c23 + 3;c22 += 3, c22_p_0 += 3){
							// y = 4, x = 136, h = 1, w = 1, c = 3, f = 32
							// T (x, 136) (136 / 1)
							for (x = x26, xp_1 = x26_p_0, xp_0 = 0;x < x26 + 136;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_146 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_147 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_148 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_149 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_150 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_151 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_152 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_153 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_154 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_155 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_156 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_157 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_158 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_159 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_160 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_161 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c22, cp_1 = c22_p_0, cp_0 = 0;c < c22 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_146);
											mem_vec_146 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_147);
											mem_vec_147 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_148);
											mem_vec_148 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_149);
											mem_vec_149 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_150);
											mem_vec_150 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_151);
											mem_vec_151 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_152);
											mem_vec_152 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_153);
											mem_vec_153 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_154);
											mem_vec_154 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_155);
											mem_vec_155 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_156);
											mem_vec_156 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_157);
											mem_vec_157 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_158);
											mem_vec_158 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_159);
											mem_vec_159 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_160);
											mem_vec_160 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_161);
											mem_vec_161 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_146);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_147);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_148);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_149);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_150);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_151);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_152);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_153);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_154);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_155);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_156);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_157);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_158);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_159);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_160);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_161);
							}
						}
					}
				}
}
