
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (8, c); T (4, f); T (1, y); T (2, f)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, f24_p_0, fp_1, f24, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y16 = 0;
IND_TYPE x16 = 0;
IND_TYPE h16 = 0;
IND_TYPE w13 = 0;
IND_TYPE c25 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f24 = 0;
f24_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_1 = 0;
c24 = 0;
c24_p_0 = 0;
x = 0;
xp_0 = 0;
					for (h = h16, hp_0 = 0;h < h16 + 3;h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w13, wp_0 = 0;w < w13 + 3;w += 1, wp_0 += 1){
									mem_vec_161 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_162 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_163 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_164 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_165 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_166 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_167 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_168 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_169 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_170 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_171 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_172 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_173 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_174 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_175 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_176 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									mem_vec_177 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_178 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
									mem_vec_179 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_180 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
									mem_vec_181 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
									mem_vec_182 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
									mem_vec_183 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
									mem_vec_184 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
									mem_vec_185 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
									mem_vec_186 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
									mem_vec_187 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
									mem_vec_188 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c24, cp_1 = c24_p_0, cp_0 = 0;c < c24 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_161);
										mem_vec_161 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_162);
										mem_vec_162 = vec_3;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_163);
										mem_vec_163 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_164);
										mem_vec_164 = vec_7;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_165);
										mem_vec_165 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_166);
										mem_vec_166 = vec_10;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_167);
										mem_vec_167 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_168);
										mem_vec_168 = vec_13;
										scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_169);
										mem_vec_169 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_170);
										mem_vec_170 = vec_16;
										scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_171);
										mem_vec_171 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_172);
										mem_vec_172 = vec_19;
										scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_173);
										mem_vec_173 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_174);
										mem_vec_174 = vec_22;
										scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_175);
										mem_vec_175 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_176);
										mem_vec_176 = vec_25;
										scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_177);
										mem_vec_177 = vec_26;
										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_178);
										mem_vec_178 = vec_28;
										scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_179);
										mem_vec_179 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_180);
										mem_vec_180 = vec_31;
										scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);
										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_181);
										mem_vec_181 = vec_32;
										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_182);
										mem_vec_182 = vec_34;
										scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);
										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_183);
										mem_vec_183 = vec_35;
										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_184);
										mem_vec_184 = vec_37;
										scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);
										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_185);
										mem_vec_185 = vec_38;
										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_186);
										mem_vec_186 = vec_40;
										scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 13) + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);
										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_187);
										mem_vec_187 = vec_41;
										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_188);
										mem_vec_188 = vec_43;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_161);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_162);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_163);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_164);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_165);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_166);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_167);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_168);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_169);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_170);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_171);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_172);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_173);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_174);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_175);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_176);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_177);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_178);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_179);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_180);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_181);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_182);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_183);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_184);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_185);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_186);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_187);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_188);
						}
					}
}
