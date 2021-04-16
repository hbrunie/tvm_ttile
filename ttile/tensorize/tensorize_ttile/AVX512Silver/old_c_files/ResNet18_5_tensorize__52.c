
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (4, x); T (4, f);
  T (7, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x21_p_0, xp_1, x21, y, yp_0;
IND_TYPE y14 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c14 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 4) (28 / 7)
y = 0;
yp_0 = 0;
x21 = 0;
x21_p_0 = 0;
f = 0;
fp_0 = 0;
			for (x = x21, xp_1 = x21_p_0, xp_0 = 0;x < x21 + 4;x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_154 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
						mem_vec_155 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
						mem_vec_156 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
						mem_vec_157 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
						mem_vec_158 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
						mem_vec_159 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
						mem_vec_160 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
						mem_vec_161 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
						mem_vec_162 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
						mem_vec_163 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
						mem_vec_164 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
						mem_vec_165 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
						mem_vec_166 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
						mem_vec_167 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (c, 64) (64 / 1)
						for (c = c14, cp_0 = 0;c < c14 + 64;c += 1, cp_0 += 1){
							scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_154);
							mem_vec_154 = vec_0;
							vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_155);
							mem_vec_155 = vec_3;
							scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);
							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_156);
							mem_vec_156 = vec_5;
							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_157);
							mem_vec_157 = vec_7;
							scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);
							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_158);
							mem_vec_158 = vec_8;
							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_159);
							mem_vec_159 = vec_10;
							scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);
							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_160);
							mem_vec_160 = vec_11;
							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_161);
							mem_vec_161 = vec_13;
							scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);
							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_162);
							mem_vec_162 = vec_14;
							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_163);
							mem_vec_163 = vec_16;
							scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);
							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_164);
							mem_vec_164 = vec_17;
							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_165);
							mem_vec_165 = vec_19;
							scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);
							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_166);
							mem_vec_166 = vec_20;
							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_167);
							mem_vec_167 = vec_22;
						}
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_154);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_155);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_156);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_157);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_158);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_159);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_160);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_161);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_162);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_163);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_164);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_165);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_166);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_167);
			}
}
