
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (4, f);
  T (4, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1026_p_0, cp_1, c1026, f, fp_0, x, xp_0, x1368_p_0, x1369_p_0, xp_1, x1368_p_1, xp_2, x1368, x1369, y, yp_0;
IND_TYPE y684 = 0;
IND_TYPE x1370 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1027 = 0;
IND_TYPE f684 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14160 ,mem_vec_14161 ,mem_vec_14162 ,mem_vec_14163 ,mem_vec_14164 ,mem_vec_14165 ,mem_vec_14166 ,mem_vec_14167 ,mem_vec_14168 ,mem_vec_14169 ,mem_vec_14170 ,mem_vec_14171 ,mem_vec_14172 ,mem_vec_14173 ,mem_vec_14174 ,mem_vec_14175 ,mem_vec_14176 ,mem_vec_14177 ,mem_vec_14178 ,mem_vec_14179 ,mem_vec_14180 ,mem_vec_14181 ,mem_vec_14182 ,mem_vec_14183 ,mem_vec_14184 ,mem_vec_14185 ,mem_vec_14186 ,mem_vec_14187 ,mem_vec_14188 ,mem_vec_14189 ,mem_vec_14190 ,mem_vec_14191 ,mem_vec_14192 ,mem_vec_14193 ,mem_vec_14194 ,mem_vec_14195 ,mem_vec_14196 ,mem_vec_14197 ,mem_vec_14198 ,mem_vec_14199 ,mem_vec_14200 ,mem_vec_14201 ,mem_vec_14202 ,mem_vec_14203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
x1369 = 0;
x1369_p_0 = 0;
c1026 = 0;
c1026_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1368 = 0;
x1368_p_1 = 0;
						for (x = x1368, xp_2 = x1368_p_1, xp_1 = x1368_p_0, xp_0 = 0;x < x1368 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14160 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_14161 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_14162 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_14163 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_14164 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_14165 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_14166 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_14167 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_14168 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_14169 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_14170 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_14171 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_14172 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_14173 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_14174 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_14175 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c1026, cp_1 = c1026_p_0, cp_0 = 0;c < c1026 + 128;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14160);
										mem_vec_14160 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14161);
										mem_vec_14161 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14162);
										mem_vec_14162 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14163);
										mem_vec_14163 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14164);
										mem_vec_14164 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14165);
										mem_vec_14165 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14166);
										mem_vec_14166 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14167);
										mem_vec_14167 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14168);
										mem_vec_14168 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14169);
										mem_vec_14169 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14170);
										mem_vec_14170 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14171);
										mem_vec_14171 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14172);
										mem_vec_14172 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14173);
										mem_vec_14173 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14174);
										mem_vec_14174 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14175);
										mem_vec_14175 = vec_23;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14160);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14161);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_14162);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_14163);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14164);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14165);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_14166);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_14167);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14168);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14169);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_14170);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_14171);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14172);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14173);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_14174);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_14175);
						}
}
