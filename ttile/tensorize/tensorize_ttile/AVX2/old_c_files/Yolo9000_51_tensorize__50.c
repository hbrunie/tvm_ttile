
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
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c294_p_0, cp_1, c294, f, fp_0, x, xp_0, x490_p_0, x491_p_0, x492_p_0, xp_1, x490_p_1, x491_p_1, xp_2, x490_p_2, xp_3, x490, x491, x492, y, yp_0, y392_p_0, y393_p_0, yp_1, y392_p_1, yp_2, y392, y393;
IND_TYPE y394 = 0;
IND_TYPE x493 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c295 = 0;
IND_TYPE f196 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3128 ,mem_vec_3129 ,mem_vec_3130 ,mem_vec_3131 ,mem_vec_3132 ,mem_vec_3133 ,mem_vec_3134 ,mem_vec_3135 ,mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,mem_vec_3148 ,mem_vec_3149 ,mem_vec_3150 ,mem_vec_3151 ,mem_vec_3152 ,mem_vec_3153 ,mem_vec_3154 ,mem_vec_3155 ,mem_vec_3156 ,mem_vec_3157 ,mem_vec_3158 ,mem_vec_3159 ,mem_vec_3160 ,mem_vec_3161 ,mem_vec_3162 ,mem_vec_3163 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y393 = 0;
y393_p_0 = 0;
x492 = 0;
x492_p_0 = 0;
y392 = 0;
y392_p_1 = 0;
x491 = 0;
x491_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x490 = 0;
x490_p_2 = 0;
c294 = 0;
c294_p_0 = 0;
									for (x = x490, xp_3 = x490_p_2, xp_2 = x490_p_1, xp_1 = x490_p_0, xp_0 = 0;x < x490 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3128 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3129 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_3130 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3131 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_3132 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3133 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_3134 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3135 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_3136 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3137 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_3138 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3139 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_3140 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3141 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_3142 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3143 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c294, cp_1 = c294_p_0, cp_0 = 0;c < c294 + 128;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3128);
													mem_vec_3128 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3129);
													mem_vec_3129 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3130);
													mem_vec_3130 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3131);
													mem_vec_3131 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3132);
													mem_vec_3132 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3133);
													mem_vec_3133 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3134);
													mem_vec_3134 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3135);
													mem_vec_3135 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3136);
													mem_vec_3136 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3137);
													mem_vec_3137 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3138);
													mem_vec_3138 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3139);
													mem_vec_3139 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3140);
													mem_vec_3140 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3141);
													mem_vec_3141 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3142);
													mem_vec_3142 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3143);
													mem_vec_3143 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3128);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3129);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3130);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3131);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3132);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3133);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3134);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3135);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3136);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3137);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3138);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3139);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3140);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3141);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3142);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3143);
									}
}
