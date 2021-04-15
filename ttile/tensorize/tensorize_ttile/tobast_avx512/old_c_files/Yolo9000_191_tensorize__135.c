
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (32, c)]
*/
IND_TYPE c, cp_0, c1552_p_0, c1553_p_0, cp_1, c1552_p_1, cp_2, c1552, c1553, f, fp_0, x, xp_0, x1164_p_0, xp_1, x1164, y, yp_0;
IND_TYPE y776 = 0;
IND_TYPE x1165 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1554 = 0;
IND_TYPE f776 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14040 ,mem_vec_14041 ,mem_vec_14042 ,mem_vec_14043 ,mem_vec_14044 ,mem_vec_14045 ,mem_vec_14046 ,mem_vec_14047 ,mem_vec_14048 ,mem_vec_14049 ,mem_vec_14050 ,mem_vec_14051 ,mem_vec_14052 ,mem_vec_14053 ,mem_vec_14054 ,mem_vec_14055 ,mem_vec_14056 ,mem_vec_14057 ,mem_vec_14058 ,mem_vec_14059 ,mem_vec_14060 ,mem_vec_14061 ,mem_vec_14062 ,mem_vec_14063 ,mem_vec_14064 ,mem_vec_14065 ,mem_vec_14066 ,mem_vec_14067 ,mem_vec_14068 ,mem_vec_14069 ,mem_vec_14070 ,mem_vec_14071 ,mem_vec_14072 ,mem_vec_14073 ,mem_vec_14074 ,mem_vec_14075 ,mem_vec_14076 ,mem_vec_14077 ,mem_vec_14078 ,mem_vec_14079 ,mem_vec_14080 ,mem_vec_14081 ,mem_vec_14082 ,mem_vec_14083 ,mem_vec_14084 ,mem_vec_14085 ,mem_vec_14086 ,mem_vec_14087 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 32) (1024 / 32)
c1553 = 0;
c1553_p_0 = 0;
y = 0;
yp_0 = 0;
x1164 = 0;
x1164_p_0 = 0;
f = 0;
fp_0 = 0;
c1552 = 0;
c1552_p_1 = 0;
						for (x = x1164, xp_1 = x1164_p_0, xp_0 = 0;x < x1164 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14040 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_14041 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_14042 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_14043 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_14044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_14045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_14046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_14047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_14048 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_14049 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_14050 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_14051 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_14052 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_14053 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_14054 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_14055 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_14056 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_14057 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_14058 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_14059 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1552, cp_2 = c1552_p_1, cp_1 = c1552_p_0, cp_0 = 0;c < c1552 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14040);
										mem_vec_14040 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14041);
										mem_vec_14041 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14042);
										mem_vec_14042 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14043);
										mem_vec_14043 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14044);
										mem_vec_14044 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14045);
										mem_vec_14045 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14046);
										mem_vec_14046 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14047);
										mem_vec_14047 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14048);
										mem_vec_14048 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14049);
										mem_vec_14049 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14050);
										mem_vec_14050 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14051);
										mem_vec_14051 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14052);
										mem_vec_14052 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14053);
										mem_vec_14053 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14054);
										mem_vec_14054 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14055);
										mem_vec_14055 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14056);
										mem_vec_14056 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14057);
										mem_vec_14057 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14058);
										mem_vec_14058 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14059);
										mem_vec_14059 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14040);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14041);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_14042);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_14043);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14044);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14045);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_14046);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_14047);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14048);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14049);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_14050);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_14051);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14052);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14053);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_14054);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_14055);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14056);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14057);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_14058);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_14059);
						}
}
