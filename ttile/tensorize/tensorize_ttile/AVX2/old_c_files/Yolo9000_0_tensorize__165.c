
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (8, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (68, x); T (1, y); T (8, y)]
*/
IND_TYPE c, cp_0, c229_p_0, cp_1, c229, h, hp_0, w, wp_0, x, xp_0, x281_p_0, xp_1, x281, y, yp_0, y314_p_0, y315_p_0, yp_1, y314_p_1, yp_2, y314, y315;
IND_TYPE y316 = 0;
IND_TYPE x282 = 0;
IND_TYPE h127 = 0;
IND_TYPE w153 = 0;
IND_TYPE c230 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1920 ,mem_vec_1921 ,mem_vec_1922 ,mem_vec_1923 ,mem_vec_1924 ,mem_vec_1925 ,mem_vec_1926 ,mem_vec_1927 ,mem_vec_1928 ,mem_vec_1929 ,mem_vec_1930 ,mem_vec_1931 ,mem_vec_1932 ,mem_vec_1933 ,mem_vec_1934 ,mem_vec_1935 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 8) (544 / 68)
y315 = 0;
y315_p_0 = 0;
y314 = 0;
y314_p_1 = 0;
x281 = 0;
x281_p_0 = 0;
y = 0;
yp_2 = 0;
				for (h = h127, hp_0 = 0;h < h127 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 8, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w153, wp_0 = 0;w < w153 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c229 = c230, c229_p_0 = 0;c229 < c230 + 3;c229 += 3, c229_p_0 += 3){
							// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (x, 8) (8 / 1)
							for (x = x281, xp_1 = x281_p_0, xp_0 = 0;x < x281 + 8;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1920 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1921 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_1922 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1923 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_1924 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1925 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_1926 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1927 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_1928 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1929 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_1930 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1931 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_1932 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1933 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_1934 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1935 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c229, cp_1 = c229_p_0, cp_0 = 0;c < c229 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1920);
											mem_vec_1920 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1921);
											mem_vec_1921 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1922);
											mem_vec_1922 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1923);
											mem_vec_1923 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1924);
											mem_vec_1924 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1925);
											mem_vec_1925 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1926);
											mem_vec_1926 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1927);
											mem_vec_1927 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1928);
											mem_vec_1928 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1929);
											mem_vec_1929 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1930);
											mem_vec_1930 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1931);
											mem_vec_1931 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1932);
											mem_vec_1932 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1933);
											mem_vec_1933 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1934);
											mem_vec_1934 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1935);
											mem_vec_1935 = vec_23;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1920);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1921);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1922);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1923);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1924);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1925);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1926);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1927);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1928);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1929);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1930);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1931);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1932);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1933);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1934);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1935);
							}
						}
					}
				}
}
