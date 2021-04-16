
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (3, c); Hoist_vars [c]; T (1, x);
  T (1, c); T (3, h); T (68, y); T (544, x); T (2, y); T (1, x)]
*/
IND_TYPE c, cp_0, c40_p_0, cp_1, c40, h, hp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0, y68_p_0, yp_1, y68;
IND_TYPE y69 = 0;
IND_TYPE x74 = 0;
IND_TYPE h30 = 0;
IND_TYPE w = 0;
IND_TYPE c41 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 1) (544 / 544)
x73 = 0;
x73_p_0 = 0;
y68 = 0;
y68_p_0 = 0;
x72 = 0;
x72_p_1 = 0;
y = 0;
yp_1 = 0;
				for (h = h30, hp_0 = 0;h < h30 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (c, 1) (3 / 3)
					for (c40 = c41, c40_p_0 = 0;c40 < c41 + 3;c40 += 3, c40_p_0 += 3){
						// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (x, 1) (1 / 1)
						for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;x < x72 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_152 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_153 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_154 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_155 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_156 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_157 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_158 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_159 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c40, cp_1 = c40_p_0, cp_0 = 0;c < c40 + 3;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_152);
										mem_vec_152 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_153);
										mem_vec_153 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_154);
										mem_vec_154 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_155);
										mem_vec_155 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_156);
										mem_vec_156 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_157);
										mem_vec_157 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_158);
										mem_vec_158 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_159);
										mem_vec_159 = vec_13;
										scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_16 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_152);
										mem_vec_152 = vec_14;
										vec_18 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_153);
										mem_vec_153 = vec_17;
										scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_20 = _mm512_set1_ps(scal_5);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_154);
										mem_vec_154 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_155);
										mem_vec_155 = vec_21;
										scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_23 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_156);
										mem_vec_156 = vec_22;
										vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_157);
										mem_vec_157 = vec_24;
										scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_158);
										mem_vec_158 = vec_25;
										vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_159);
										mem_vec_159 = vec_27;
										scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_152);
										mem_vec_152 = vec_28;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_153);
										mem_vec_153 = vec_31;
										scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_9);
										vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_154);
										mem_vec_154 = vec_33;
										vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_155);
										mem_vec_155 = vec_35;
										scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_37 = _mm512_set1_ps(scal_10);
										vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_156);
										mem_vec_156 = vec_36;
										vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_157);
										mem_vec_157 = vec_38;
										scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_40 = _mm512_set1_ps(scal_11);
										vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_158);
										mem_vec_158 = vec_39;
										vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_159);
										mem_vec_159 = vec_41;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_152);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_153);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_154);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_155);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_156);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_157);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_158);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_159);
						}
					}
				}
}
