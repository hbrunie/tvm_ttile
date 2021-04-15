
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (32, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1086_p_0, cp_1, c1086, f, fp_0, x, xp_0, x1448_p_0, x1449_p_0, xp_1, x1448_p_1, xp_2, x1448, x1449, y, yp_0;
IND_TYPE y724 = 0;
IND_TYPE x1450 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1087 = 0;
IND_TYPE f724 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15104 ,mem_vec_15105 ,mem_vec_15106 ,mem_vec_15107 ,mem_vec_15108 ,mem_vec_15109 ,mem_vec_15110 ,mem_vec_15111 ,mem_vec_15112 ,mem_vec_15113 ,mem_vec_15114 ,mem_vec_15115 ,mem_vec_15116 ,mem_vec_15117 ,mem_vec_15118 ,mem_vec_15119 ,mem_vec_15120 ,mem_vec_15121 ,mem_vec_15122 ,mem_vec_15123 ,mem_vec_15124 ,mem_vec_15125 ,mem_vec_15126 ,mem_vec_15127 ,mem_vec_15128 ,mem_vec_15129 ,mem_vec_15130 ,mem_vec_15131 ,mem_vec_15132 ,mem_vec_15133 ,mem_vec_15134 ,mem_vec_15135 ,mem_vec_15136 ,mem_vec_15137 ,mem_vec_15138 ,mem_vec_15139 ,mem_vec_15140 ,mem_vec_15141 ,mem_vec_15142 ,mem_vec_15143 ,mem_vec_15144 ,mem_vec_15145 ,mem_vec_15146 ,mem_vec_15147 ,mem_vec_15148 ,mem_vec_15149 ,mem_vec_15150 ,mem_vec_15151 ,mem_vec_15152 ,mem_vec_15153 ,mem_vec_15154 ,mem_vec_15155 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
x1449 = 0;
x1449_p_0 = 0;
c1086 = 0;
c1086_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1448 = 0;
x1448_p_1 = 0;
						for (x = x1448, xp_2 = x1448_p_1, xp_1 = x1448_p_0, xp_0 = 0;x < x1448 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15104 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_15105 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_15106 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_15107 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_15108 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_15109 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_15110 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_15111 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_15112 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_15113 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_15114 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_15115 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_15116 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_15117 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_15118 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_15119 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_15120 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_15121 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_15122 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_15123 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_15124 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_15125 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_15126 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_15127 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1086, cp_1 = c1086_p_0, cp_0 = 0;c < c1086 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15104);
										mem_vec_15104 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15105);
										mem_vec_15105 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15106);
										mem_vec_15106 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15107);
										mem_vec_15107 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15108);
										mem_vec_15108 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15109);
										mem_vec_15109 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15110);
										mem_vec_15110 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15111);
										mem_vec_15111 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15112);
										mem_vec_15112 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15113);
										mem_vec_15113 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15114);
										mem_vec_15114 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15115);
										mem_vec_15115 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15116);
										mem_vec_15116 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15117);
										mem_vec_15117 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15118);
										mem_vec_15118 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15119);
										mem_vec_15119 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15120);
										mem_vec_15120 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15121);
										mem_vec_15121 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15122);
										mem_vec_15122 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15123);
										mem_vec_15123 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15124);
										mem_vec_15124 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15125);
										mem_vec_15125 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15126);
										mem_vec_15126 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15127);
										mem_vec_15127 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_15104);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_15105);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_15106);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_15107);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_15108);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_15109);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_15110);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_15111);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_15112);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_15113);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_15114);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_15115);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_15116);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_15117);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_15118);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_15119);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_15120);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_15121);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_15122);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_15123);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_15124);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_15125);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_15126);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_15127);
						}
}
