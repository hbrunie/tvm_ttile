
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c304_p_0, c305_p_0, cp_1, c304_p_1, cp_2, c304, c305, f, fp_0, x, xp_0, y, yp_0, y228_p_0, yp_1, y228;
IND_TYPE y229 = 0;
IND_TYPE x152 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c306 = 0;
IND_TYPE f152 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_3116 ,mem_vec_3117 ,mem_vec_3118 ,mem_vec_3119 ,mem_vec_3120 ,mem_vec_3121 ,mem_vec_3122 ,mem_vec_3123 ,mem_vec_3124 ,mem_vec_3125 ,mem_vec_3126 ,mem_vec_3127 ,mem_vec_3128 ,mem_vec_3129 ,mem_vec_3130 ,mem_vec_3131 ,mem_vec_3132 ,mem_vec_3133 ,mem_vec_3134 ,mem_vec_3135 ,mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,mem_vec_3148 ,mem_vec_3149 ,mem_vec_3150 ,mem_vec_3151 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y228 = 0;
y228_p_0 = 0;
c305 = 0;
c305_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
c304 = 0;
c304_p_1 = 0;
						for (x = x152, xp_0 = 0;x < x152 + 17;x += 1, xp_0 += 1){
									mem_vec_3116 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_3117 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_3118 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_3119 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_3120 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_3121 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_3122 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_3123 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_3124 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_3125 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_3126 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_3127 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_3128 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_3129 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_3130 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_3131 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c304, cp_2 = c304_p_1, cp_1 = c304_p_0, cp_0 = 0;c < c304 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3116);
										mem_vec_3116 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3117);
										mem_vec_3117 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3118);
										mem_vec_3118 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3119);
										mem_vec_3119 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3120);
										mem_vec_3120 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3121);
										mem_vec_3121 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3122);
										mem_vec_3122 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3123);
										mem_vec_3123 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3124);
										mem_vec_3124 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3125);
										mem_vec_3125 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3126);
										mem_vec_3126 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3127);
										mem_vec_3127 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3128);
										mem_vec_3128 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3129);
										mem_vec_3129 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3130);
										mem_vec_3130 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3131);
										mem_vec_3131 = vec_23;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3116);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3117);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3118);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3119);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3120);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3121);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3122);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3123);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3124);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3125);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3126);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3127);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3128);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3129);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3130);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3131);
						}
}
