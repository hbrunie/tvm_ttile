
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1472_p_0, c1473_p_0, cp_1, c1472_p_1, cp_2, c1472, c1473, f, fp_0, x, xp_0, x1104_p_0, xp_1, x1104, y, yp_0;
IND_TYPE y736 = 0;
IND_TYPE x1105 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1474 = 0;
IND_TYPE f736 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_13080 ,mem_vec_13081 ,mem_vec_13082 ,mem_vec_13083 ,mem_vec_13084 ,mem_vec_13085 ,mem_vec_13086 ,mem_vec_13087 ,mem_vec_13088 ,mem_vec_13089 ,mem_vec_13090 ,mem_vec_13091 ,mem_vec_13092 ,mem_vec_13093 ,mem_vec_13094 ,mem_vec_13095 ,mem_vec_13096 ,mem_vec_13097 ,mem_vec_13098 ,mem_vec_13099 ,mem_vec_13100 ,mem_vec_13101 ,mem_vec_13102 ,mem_vec_13103 ,mem_vec_13104 ,mem_vec_13105 ,mem_vec_13106 ,mem_vec_13107 ,mem_vec_13108 ,mem_vec_13109 ,mem_vec_13110 ,mem_vec_13111 ,mem_vec_13112 ,mem_vec_13113 ,mem_vec_13114 ,mem_vec_13115 ,mem_vec_13116 ,mem_vec_13117 ,mem_vec_13118 ,mem_vec_13119 ,mem_vec_13120 ,mem_vec_13121 ,mem_vec_13122 ,mem_vec_13123 ,mem_vec_13124 ,mem_vec_13125 ,mem_vec_13126 ,mem_vec_13127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
c1473 = 0;
c1473_p_0 = 0;
y = 0;
yp_0 = 0;
x1104 = 0;
x1104_p_0 = 0;
f = 0;
fp_0 = 0;
c1472 = 0;
c1472_p_1 = 0;
						for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;x < x1104 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13080 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_13081 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_13082 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_13083 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_13084 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_13085 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_13086 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_13087 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_13088 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_13089 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_13090 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_13091 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_13092 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_13093 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_13094 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_13095 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_13096 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_13097 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_13098 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_13099 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1472, cp_2 = c1472_p_1, cp_1 = c1472_p_0, cp_0 = 0;c < c1472 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13080);
										mem_vec_13080 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13081);
										mem_vec_13081 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13082);
										mem_vec_13082 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13083);
										mem_vec_13083 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13084);
										mem_vec_13084 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13085);
										mem_vec_13085 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13086);
										mem_vec_13086 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13087);
										mem_vec_13087 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13088);
										mem_vec_13088 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13089);
										mem_vec_13089 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13090);
										mem_vec_13090 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13091);
										mem_vec_13091 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13092);
										mem_vec_13092 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13093);
										mem_vec_13093 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13094);
										mem_vec_13094 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13095);
										mem_vec_13095 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13096);
										mem_vec_13096 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13097);
										mem_vec_13097 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13098);
										mem_vec_13098 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13099);
										mem_vec_13099 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13080);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13081);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13082);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13083);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13084);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13085);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13086);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13087);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13088);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13089);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13090);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13091);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13092);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13093);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13094);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13095);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13096);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13097);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_13098);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_13099);
						}
}
