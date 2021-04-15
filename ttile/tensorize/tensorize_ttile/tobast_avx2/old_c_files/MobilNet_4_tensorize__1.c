
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, f); T (1, x); T (7, y); T (4, x); T (4, f); T (1, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, f6_p_0, fp_1, f6, h, hp_0, w, wp_0, x, xp_0, x10_p_0, x11_p_0, x12_p_0, xp_1, x10_p_1, x11_p_1, xp_2, x10_p_2, xp_3, x10, x11, x12, y, yp_0;
IND_TYPE y4 = 0;
IND_TYPE x13 = 0;
IND_TYPE h4 = 0;
IND_TYPE w4 = 0;
IND_TYPE c7 = 0;
IND_TYPE f7 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (28 / 28)
x12 = 0;
x12_p_0 = 0;
c6 = 0;
c6_p_0 = 0;
f6 = 0;
f6_p_0 = 0;
x11 = 0;
x11_p_1 = 0;
y = 0;
yp_0 = 0;
x10 = 0;
x10_p_2 = 0;
f = 0;
fp_1 = 0;
							for (h = h4, hp_0 = 0;h < h4 + 3;h += 1, hp_0 += 1){
								// y = 4, x = 7, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w4, wp_0 = 0;w < w4 + 3;w += 1, wp_0 += 1){
									// y = 4, x = 7, h = 1, w = 1, c = 128, f = 32
									// T (x, 7) (7 / 1)
									for (x = x10, xp_3 = x10_p_2, xp_2 = x10_p_1, xp_1 = x10_p_0, xp_0 = 0;x < x10 + 7;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_32 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_33 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_34 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_35 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_36 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_37 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_38 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_39 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_40 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_41 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_42 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_43 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_44 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_45 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_46 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_47 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c6, cp_1 = c6_p_0, cp_0 = 0;c < c6 + 128;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_32);
													mem_vec_32 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_33);
													mem_vec_33 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_34);
													mem_vec_34 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_35);
													mem_vec_35 = vec_7;
													scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_36);
													mem_vec_36 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_37);
													mem_vec_37 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_38);
													mem_vec_38 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_39);
													mem_vec_39 = vec_13;
													scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_40);
													mem_vec_40 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_41);
													mem_vec_41 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_42);
													mem_vec_42 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_43);
													mem_vec_43 = vec_18;
													scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_44);
													mem_vec_44 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_45);
													mem_vec_45 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_46);
													mem_vec_46 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_47);
													mem_vec_47 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_32);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_33);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_34);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_35);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_36);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_37);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_38);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_39);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_40);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_41);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_42);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_43);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_44);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_45);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_46);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_47);
									}
								}
							}
}
