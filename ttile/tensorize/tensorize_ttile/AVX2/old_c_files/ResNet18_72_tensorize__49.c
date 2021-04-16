void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (16, c); T (8, f); T (1, c)]
*/
IND_TYPE c, cp_0, c148_p_0, c149_p_0, cp_1, c148_p_1, cp_2, c148, c149, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y74 = 0;
IND_TYPE x74 = 0;
IND_TYPE h56 = 0;
IND_TYPE w57 = 0;
IND_TYPE c150 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1136 ,mem_vec_1137 ,mem_vec_1138 ,mem_vec_1139 ,mem_vec_1140 ,mem_vec_1141 ,mem_vec_1142 ,mem_vec_1143 ,mem_vec_1144 ,mem_vec_1145 ,mem_vec_1146 ,mem_vec_1147 ,mem_vec_1148 ,mem_vec_1149 ,mem_vec_1150 ,mem_vec_1151 ,mem_vec_1152 ,mem_vec_1153 ,mem_vec_1154 ,mem_vec_1155 ,mem_vec_1156 ,mem_vec_1157 ,mem_vec_1158 ,mem_vec_1159 ,mem_vec_1160 ,mem_vec_1161 ,mem_vec_1162 ,mem_vec_1163 ,mem_vec_1164 ,mem_vec_1165 ,mem_vec_1166 ,mem_vec_1167 ,mem_vec_1168 ,mem_vec_1169 ,mem_vec_1170 ,mem_vec_1171 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
c149 = 0;
c149_p_0 = 0;
f = 0;
fp_0 = 0;
c148 = 0;
c148_p_1 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
						for (h = h56, hp_0 = 0;h < h56 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w57, wp_0 = 0;w < w57 + 3;w += 1, wp_0 += 1){
										mem_vec_1152 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1153 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_1154 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1155 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_1156 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1157 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_1158 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1159 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_1160 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1161 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_1162 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1163 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_1164 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1165 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_1166 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1167 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										mem_vec_1168 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_1169 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
										mem_vec_1170 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_1171 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c148, cp_2 = c148_p_1, cp_1 = c148_p_0, cp_0 = 0;c < c148 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1152);
											mem_vec_1152 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1153);
											mem_vec_1153 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1154);
											mem_vec_1154 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1155);
											mem_vec_1155 = vec_7;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1156);
											mem_vec_1156 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1157);
											mem_vec_1157 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1158);
											mem_vec_1158 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1159);
											mem_vec_1159 = vec_13;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1160);
											mem_vec_1160 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1161);
											mem_vec_1161 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1162);
											mem_vec_1162 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1163);
											mem_vec_1163 = vec_18;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1164);
											mem_vec_1164 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1165);
											mem_vec_1165 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1166);
											mem_vec_1166 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1167);
											mem_vec_1167 = vec_23;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1168);
											mem_vec_1168 = vec_24;
											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1169);
											mem_vec_1169 = vec_26;
											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1170);
											mem_vec_1170 = vec_27;
											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1171);
											mem_vec_1171 = vec_28;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1152);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1153);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1154);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1155);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1156);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1157);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1158);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1159);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1160);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1161);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1162);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1163);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1164);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1165);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1166);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1167);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1168);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1169);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1170);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1171);
							}
						}
}
