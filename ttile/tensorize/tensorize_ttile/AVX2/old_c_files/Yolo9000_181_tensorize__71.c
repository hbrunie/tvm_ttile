
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (16, c); T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, f104_p_0, f105_p_0, fp_1, f104_p_1, fp_2, f104, f105, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y52 = 0;
IND_TYPE x52 = 0;
IND_TYPE h40 = 0;
IND_TYPE w44 = 0;
IND_TYPE c79 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_1036 ,mem_vec_1037 ,mem_vec_1038 ,mem_vec_1039 ,mem_vec_1040 ,mem_vec_1041 ,mem_vec_1042 ,mem_vec_1043 ,mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
f105 = 0;
f105_p_0 = 0;
f104 = 0;
f104_p_1 = 0;
c78 = 0;
c78_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (h = h40, hp_0 = 0;h < h40 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w44, wp_0 = 0;w < w44 + 3;w += 1, wp_0 += 1){
											mem_vec_1024 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1025 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_1026 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1027 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_1028 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1029 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_1030 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1031 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_1032 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1033 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_1034 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1035 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_1036 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1037 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_1038 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1039 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c78, cp_1 = c78_p_0, cp_0 = 0;c < c78 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1024);
												mem_vec_1024 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1025);
												mem_vec_1025 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1026);
												mem_vec_1026 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1027);
												mem_vec_1027 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1028);
												mem_vec_1028 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1029);
												mem_vec_1029 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1030);
												mem_vec_1030 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1031);
												mem_vec_1031 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1032);
												mem_vec_1032 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1033);
												mem_vec_1033 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1034);
												mem_vec_1034 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1035);
												mem_vec_1035 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1036);
												mem_vec_1036 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1037);
												mem_vec_1037 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1038);
												mem_vec_1038 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1039);
												mem_vec_1039 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1024);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1025);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1026);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1027);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1028);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1029);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1030);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1031);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1032);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1033);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1034);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1035);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1036);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1037);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1038);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1039);
								}
							}
}
