
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (4, f);
  T (1, c); T (17, x)]
*/
IND_TYPE c, cp_0, c888_p_0, cp_1, c888, f, fp_0, x, xp_0, x1184_p_0, x1185_p_0, xp_1, x1184_p_1, xp_2, x1184, x1185, y, yp_0;
IND_TYPE y592 = 0;
IND_TYPE x1186 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c889 = 0;
IND_TYPE f592 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_12216 ,mem_vec_12217 ,mem_vec_12218 ,mem_vec_12219 ,mem_vec_12220 ,mem_vec_12221 ,mem_vec_12222 ,mem_vec_12223 ,mem_vec_12224 ,mem_vec_12225 ,mem_vec_12226 ,mem_vec_12227 ,mem_vec_12228 ,mem_vec_12229 ,mem_vec_12230 ,mem_vec_12231 ,mem_vec_12232 ,mem_vec_12233 ,mem_vec_12234 ,mem_vec_12235 ,mem_vec_12236 ,mem_vec_12237 ,mem_vec_12238 ,mem_vec_12239 ,mem_vec_12240 ,mem_vec_12241 ,mem_vec_12242 ,mem_vec_12243 ,mem_vec_12244 ,mem_vec_12245 ,mem_vec_12246 ,mem_vec_12247 ,mem_vec_12248 ,mem_vec_12249 ,mem_vec_12250 ,mem_vec_12251 ,mem_vec_12252 ,mem_vec_12253 ,mem_vec_12254 ,mem_vec_12255 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
x1185 = 0;
x1185_p_0 = 0;
c888 = 0;
c888_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1184 = 0;
x1184_p_1 = 0;
						for (x = x1184, xp_2 = x1184_p_1, xp_1 = x1184_p_0, xp_0 = 0;x < x1184 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12216 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_12217 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_12218 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_12219 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_12220 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_12221 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_12222 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_12223 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_12224 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_12225 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_12226 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_12227 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_12228 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_12229 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_12230 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_12231 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 64
									// T (c, 512) (512 / 1)
									for (c = c888, cp_1 = c888_p_0, cp_0 = 0;c < c888 + 512;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12216);
										mem_vec_12216 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12217);
										mem_vec_12217 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12218);
										mem_vec_12218 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12219);
										mem_vec_12219 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12220);
										mem_vec_12220 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12221);
										mem_vec_12221 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12222);
										mem_vec_12222 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12223);
										mem_vec_12223 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12224);
										mem_vec_12224 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12225);
										mem_vec_12225 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12226);
										mem_vec_12226 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12227);
										mem_vec_12227 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12228);
										mem_vec_12228 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12229);
										mem_vec_12229 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12230);
										mem_vec_12230 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12231);
										mem_vec_12231 = vec_23;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12216);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12217);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_12218);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_12219);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12220);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12221);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_12222);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_12223);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12224);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12225);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_12226);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_12227);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12228);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12229);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_12230);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_12231);
						}
}
