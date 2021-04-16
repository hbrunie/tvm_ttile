
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (7, x); T (4, f);
  T (4, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c12 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 4) (28 / 7)
y = 0;
yp_0 = 0;
x18 = 0;
x18_p_0 = 0;
f = 0;
fp_0 = 0;
			for (x = x18, xp_1 = x18_p_0, xp_0 = 0;x < x18 + 7;x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_140 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
						mem_vec_141 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
						mem_vec_142 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
						mem_vec_143 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
						mem_vec_144 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
						mem_vec_145 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
						mem_vec_146 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
						mem_vec_147 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
						mem_vec_148 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
						mem_vec_149 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
						mem_vec_150 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
						mem_vec_151 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
						mem_vec_152 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
						mem_vec_153 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (c, 64) (64 / 1)
						for (c = c12, cp_0 = 0;c < c12 + 64;c += 1, cp_0 += 1){
							scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_140);
							mem_vec_140 = vec_0;
							vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_141);
							mem_vec_141 = vec_3;
							scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);
							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_142);
							mem_vec_142 = vec_5;
							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_143);
							mem_vec_143 = vec_7;
							scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);
							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_144);
							mem_vec_144 = vec_8;
							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_145);
							mem_vec_145 = vec_10;
							scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);
							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_146);
							mem_vec_146 = vec_11;
							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_147);
							mem_vec_147 = vec_13;
							scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);
							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_148);
							mem_vec_148 = vec_14;
							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_149);
							mem_vec_149 = vec_16;
							scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);
							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_150);
							mem_vec_150 = vec_17;
							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_151);
							mem_vec_151 = vec_19;
							scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);
							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_152);
							mem_vec_152 = vec_20;
							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_153);
							mem_vec_153 = vec_22;
						}
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_140);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_141);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_142);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_143);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_144);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_145);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_146);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_147);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_148);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_149);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_150);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_151);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_152);
					_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_153);
			}
}
