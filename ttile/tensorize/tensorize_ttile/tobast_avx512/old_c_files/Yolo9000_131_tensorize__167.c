
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (2, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1140_p_0, cp_1, c1140, f, fp_0, x, xp_0, x1520_p_0, x1521_p_0, xp_1, x1520_p_1, xp_2, x1520, x1521, y, yp_0;
IND_TYPE y760 = 0;
IND_TYPE x1522 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1141 = 0;
IND_TYPE f760 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16040 ,mem_vec_16041 ,mem_vec_16042 ,mem_vec_16043 ,mem_vec_16044 ,mem_vec_16045 ,mem_vec_16046 ,mem_vec_16047 ,mem_vec_16048 ,mem_vec_16049 ,mem_vec_16050 ,mem_vec_16051 ,mem_vec_16052 ,mem_vec_16053 ,mem_vec_16054 ,mem_vec_16055 ,mem_vec_16056 ,mem_vec_16057 ,mem_vec_16058 ,mem_vec_16059 ,mem_vec_16060 ,mem_vec_16061 ,mem_vec_16062 ,mem_vec_16063 ,mem_vec_16064 ,mem_vec_16065 ,mem_vec_16066 ,mem_vec_16067 ,mem_vec_16068 ,mem_vec_16069 ,mem_vec_16070 ,mem_vec_16071 ,mem_vec_16072 ,mem_vec_16073 ,mem_vec_16074 ,mem_vec_16075 ,mem_vec_16076 ,mem_vec_16077 ,mem_vec_16078 ,mem_vec_16079 ,mem_vec_16080 ,mem_vec_16081 ,mem_vec_16082 ,mem_vec_16083 ,mem_vec_16084 ,mem_vec_16085 ,mem_vec_16086 ,mem_vec_16087 ,mem_vec_16088 ,mem_vec_16089 ,mem_vec_16090 ,mem_vec_16091 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
x1521 = 0;
x1521_p_0 = 0;
c1140 = 0;
c1140_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1520 = 0;
x1520_p_1 = 0;
						for (x = x1520, xp_2 = x1520_p_1, xp_1 = x1520_p_0, xp_0 = 0;x < x1520 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16040 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_16041 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_16042 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_16043 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_16044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_16045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_16046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_16047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_16048 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_16049 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_16050 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_16051 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_16052 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_16053 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_16054 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_16055 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_16056 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_16057 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_16058 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_16059 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_16060 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_16061 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_16062 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_16063 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c1140, cp_1 = c1140_p_0, cp_0 = 0;c < c1140 + 256;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16040);
										mem_vec_16040 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16041);
										mem_vec_16041 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16042);
										mem_vec_16042 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16043);
										mem_vec_16043 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16044);
										mem_vec_16044 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16045);
										mem_vec_16045 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16046);
										mem_vec_16046 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16047);
										mem_vec_16047 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16048);
										mem_vec_16048 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16049);
										mem_vec_16049 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16050);
										mem_vec_16050 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16051);
										mem_vec_16051 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16052);
										mem_vec_16052 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16053);
										mem_vec_16053 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16054);
										mem_vec_16054 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16055);
										mem_vec_16055 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16056);
										mem_vec_16056 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16057);
										mem_vec_16057 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16058);
										mem_vec_16058 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16059);
										mem_vec_16059 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16060);
										mem_vec_16060 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16061);
										mem_vec_16061 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16062);
										mem_vec_16062 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16063);
										mem_vec_16063 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_16040);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_16041);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_16042);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_16043);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_16044);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_16045);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_16046);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_16047);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_16048);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_16049);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_16050);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_16051);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_16052);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_16053);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_16054);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_16055);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_16056);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_16057);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_16058);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_16059);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_16060);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_16061);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_16062);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_16063);
						}
}
