
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (2, y); T (2, f); T (2, x); T (4, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, x, xp_0, x460_p_0, x461_p_0, x462_p_0, xp_1, x460_p_1, x461_p_1, xp_2, x460_p_2, xp_3, x460, x461, x462, y, yp_0, y368_p_0, y369_p_0, yp_1, y368_p_1, yp_2, y368, y369;
IND_TYPE y370 = 0;
IND_TYPE x463 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c277 = 0;
IND_TYPE f184 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y369 = 0;
y369_p_0 = 0;
x462 = 0;
x462_p_0 = 0;
y368 = 0;
y368_p_1 = 0;
x461 = 0;
x461_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x460 = 0;
x460_p_2 = 0;
c276 = 0;
c276_p_0 = 0;
									for (x = x460, xp_3 = x460_p_2, xp_2 = x460_p_1, xp_1 = x460_p_0, xp_0 = 0;x < x460 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2912 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_2913 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_2914 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_2915 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_2916 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_2917 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_2918 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_2919 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_2920 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_2921 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_2922 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_2923 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_2924 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_2925 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_2926 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_2927 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 128;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2912);
													mem_vec_2912 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2913);
													mem_vec_2913 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2914);
													mem_vec_2914 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2915);
													mem_vec_2915 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2916);
													mem_vec_2916 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2917);
													mem_vec_2917 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2918);
													mem_vec_2918 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2919);
													mem_vec_2919 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2920);
													mem_vec_2920 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2921);
													mem_vec_2921 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2922);
													mem_vec_2922 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2923);
													mem_vec_2923 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2924);
													mem_vec_2924 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2925);
													mem_vec_2925 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2926);
													mem_vec_2926 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2927);
													mem_vec_2927 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2912);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_2913);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2914);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_2915);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2916);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_2917);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2918);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_2919);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2920);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_2921);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2922);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_2923);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2924);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_2925);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2926);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_2927);
									}
}
