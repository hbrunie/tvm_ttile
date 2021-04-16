void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (16, c); T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, f108_p_0, f109_p_0, fp_1, f108_p_1, fp_2, f108, f109, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y54 = 0;
IND_TYPE x54 = 0;
IND_TYPE h42 = 0;
IND_TYPE w46 = 0;
IND_TYPE c82 = 0;
IND_TYPE f110 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,mem_vec_1088 ,mem_vec_1089 ,mem_vec_1090 ,mem_vec_1091 ,mem_vec_1092 ,mem_vec_1093 ,mem_vec_1094 ,mem_vec_1095 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
f109 = 0;
f109_p_0 = 0;
f108 = 0;
f108_p_1 = 0;
c81 = 0;
c81_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (h = h42, hp_0 = 0;h < h42 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w46, wp_0 = 0;w < w46 + 3;w += 1, wp_0 += 1){
											mem_vec_1076 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1077 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_1078 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1079 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_1080 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1081 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_1082 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1083 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_1084 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1085 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_1086 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1087 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_1088 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1089 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_1090 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1091 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_1092 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1093 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_1094 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1095 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;c < c81 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1076);
												mem_vec_1076 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1077);
												mem_vec_1077 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1078);
												mem_vec_1078 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1079);
												mem_vec_1079 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1080);
												mem_vec_1080 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1081);
												mem_vec_1081 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1082);
												mem_vec_1082 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1083);
												mem_vec_1083 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1084);
												mem_vec_1084 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1085);
												mem_vec_1085 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1086);
												mem_vec_1086 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1087);
												mem_vec_1087 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1088);
												mem_vec_1088 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1089);
												mem_vec_1089 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1090);
												mem_vec_1090 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1091);
												mem_vec_1091 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1092);
												mem_vec_1092 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1093);
												mem_vec_1093 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1094);
												mem_vec_1094 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1095);
												mem_vec_1095 = vec_28;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1076);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1077);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1078);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1079);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1080);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1081);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1082);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1083);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1084);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1085);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1086);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1087);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1088);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1089);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1090);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1091);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1092);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1093);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1094);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1095);
								}
							}
}
