void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (16, f); T (8, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, x, xp_0, x9_p_0, xp_1, x9, y, yp_0, y9_p_0, yp_1, y9;
IND_TYPE y10 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f6 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y9 = 0;
y9_p_0 = 0;
x9 = 0;
x9_p_0 = 0;
c9 = 0;
c9_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
						for (x = x9, xp_1 = x9_p_0, xp_0 = 0;x < x9 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_124 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_125 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_126 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_127 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_128 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_129 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_130 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_131 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_132 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_133 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_134 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_135 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_136 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_137 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_138 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_139 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_140 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_141 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_142 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_143 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c9, cp_1 = c9_p_0, cp_0 = 0;c < c9 + 128;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_124);
										mem_vec_124 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_125);
										mem_vec_125 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_126);
										mem_vec_126 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_127);
										mem_vec_127 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_128);
										mem_vec_128 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_129);
										mem_vec_129 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_130);
										mem_vec_130 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_131);
										mem_vec_131 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_132);
										mem_vec_132 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_133);
										mem_vec_133 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_134);
										mem_vec_134 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_135);
										mem_vec_135 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_136);
										mem_vec_136 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_137);
										mem_vec_137 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_138);
										mem_vec_138 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_139);
										mem_vec_139 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_140);
										mem_vec_140 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_141);
										mem_vec_141 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_142);
										mem_vec_142 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_143);
										mem_vec_143 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_124);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_125);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_126);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_127);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_128);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_129);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_130);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_131);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_132);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_133);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_134);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_135);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_136);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_137);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_138);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_139);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_140);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_141);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_142);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_143);
						}
}
