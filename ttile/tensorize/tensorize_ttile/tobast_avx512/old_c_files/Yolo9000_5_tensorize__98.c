
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (17, x); T (34, y);
  T (4, c); T (8, x)]
*/
IND_TYPE c, cp_0, c140_p_0, cp_1, c140, x, xp_0, x196_p_0, xp_1, x196, y, yp_0;
IND_TYPE y112 = 0;
IND_TYPE x197 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c141 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 8) (136 / 17)
x196 = 0;
x196_p_0 = 0;
c140 = 0;
c140_p_0 = 0;
y = 0;
yp_0 = 0;
			for (x = x196, xp_1 = x196_p_0, xp_0 = 0;x < x196 + 17;x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_896 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
						mem_vec_897 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
						mem_vec_898 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
						mem_vec_899 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
						mem_vec_900 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
						mem_vec_901 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
						mem_vec_902 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
						mem_vec_903 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
						mem_vec_904 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
						mem_vec_905 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
						mem_vec_906 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
						mem_vec_907 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
						mem_vec_908 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
						mem_vec_909 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
						mem_vec_910 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
						mem_vec_911 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (c, 32) (32 / 1)
						for (c = c140, cp_1 = c140_p_0, cp_0 = 0;c < c140 + 32;c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_896);
							mem_vec_896 = vec_0;
							vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_897);
							mem_vec_897 = vec_3;
							vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_898);
							mem_vec_898 = vec_5;
							vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_899);
							mem_vec_899 = vec_7;
							scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);
							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_900);
							mem_vec_900 = vec_9;
							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_901);
							mem_vec_901 = vec_11;
							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_902);
							mem_vec_902 = vec_12;
							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_903);
							mem_vec_903 = vec_13;
							scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);
							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_904);
							mem_vec_904 = vec_14;
							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_905);
							mem_vec_905 = vec_16;
							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_906);
							mem_vec_906 = vec_17;
							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_907);
							mem_vec_907 = vec_18;
							scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);
							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_908);
							mem_vec_908 = vec_19;
							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_909);
							mem_vec_909 = vec_21;
							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_910);
							mem_vec_910 = vec_22;
							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_911);
							mem_vec_911 = vec_23;
						}
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_896);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_897);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_898);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_899);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_900);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_901);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_902);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_903);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_904);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_905);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_906);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_907);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_908);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_909);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_910);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_911);
			}
}
