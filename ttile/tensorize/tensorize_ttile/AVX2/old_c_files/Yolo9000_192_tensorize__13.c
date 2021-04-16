void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (1, y);
  T (16, f); T (128, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, f, fp_0, x, xp_0, x93_p_0, xp_1, x93, y, yp_0, y93_p_0, yp_1, y93;
IND_TYPE y94 = 0;
IND_TYPE x94 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c94 = 0;
IND_TYPE f62 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1116 ,mem_vec_1117 ,mem_vec_1118 ,mem_vec_1119 ,mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,mem_vec_1128 ,mem_vec_1129 ,mem_vec_1130 ,mem_vec_1131 ,mem_vec_1132 ,mem_vec_1133 ,mem_vec_1134 ,mem_vec_1135 ,mem_vec_1136 ,mem_vec_1137 ,mem_vec_1138 ,mem_vec_1139 ,mem_vec_1140 ,mem_vec_1141 ,mem_vec_1142 ,mem_vec_1143 ,mem_vec_1144 ,mem_vec_1145 ,mem_vec_1146 ,mem_vec_1147 ,mem_vec_1148 ,mem_vec_1149 ,mem_vec_1150 ,mem_vec_1151 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y93 = 0;
y93_p_0 = 0;
x93 = 0;
x93_p_0 = 0;
c93 = 0;
c93_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
						for (x = x93, xp_1 = x93_p_0, xp_0 = 0;x < x93 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1132 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1133 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_1134 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1135 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_1136 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1137 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_1138 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1139 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_1140 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1141 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_1142 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1143 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_1144 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1145 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_1146 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1147 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_1148 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_1149 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_1150 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_1151 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c93, cp_1 = c93_p_0, cp_0 = 0;c < c93 + 8;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1132);
										mem_vec_1132 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1133);
										mem_vec_1133 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1134);
										mem_vec_1134 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1135);
										mem_vec_1135 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1136);
										mem_vec_1136 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1137);
										mem_vec_1137 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1138);
										mem_vec_1138 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1139);
										mem_vec_1139 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1140);
										mem_vec_1140 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1141);
										mem_vec_1141 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1142);
										mem_vec_1142 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1143);
										mem_vec_1143 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1144);
										mem_vec_1144 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1145);
										mem_vec_1145 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1146);
										mem_vec_1146 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1147);
										mem_vec_1147 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1148);
										mem_vec_1148 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1149);
										mem_vec_1149 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1150);
										mem_vec_1150 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1151);
										mem_vec_1151 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1132);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1133);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1134);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1135);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1136);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1137);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1138);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1139);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1140);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1141);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1142);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1143);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1144);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1145);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1146);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1147);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1148);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1149);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1150);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1151);
						}
}
