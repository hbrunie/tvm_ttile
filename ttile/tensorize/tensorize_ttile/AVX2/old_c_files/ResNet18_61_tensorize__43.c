
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (2, y); T (2, f); T (16, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, f758_p_0, f759_p_0, fp_1, f758_p_1, fp_2, f758, f759, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y402_p_0, yp_1, y402;
IND_TYPE y403 = 0;
IND_TYPE x388 = 0;
IND_TYPE h307 = 0;
IND_TYPE w289 = 0;
IND_TYPE c763 = 0;
IND_TYPE f760 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4996 ,mem_vec_4997 ,mem_vec_4998 ,mem_vec_4999 ,mem_vec_5000 ,mem_vec_5001 ,mem_vec_5002 ,mem_vec_5003 ,mem_vec_5004 ,mem_vec_5005 ,mem_vec_5006 ,mem_vec_5007 ,mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,mem_vec_5015 ,mem_vec_5016 ,mem_vec_5017 ,mem_vec_5018 ,mem_vec_5019 ,mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f759 = 0;
f759_p_0 = 0;
y402 = 0;
y402_p_0 = 0;
f758 = 0;
f758_p_1 = 0;
c762 = 0;
c762_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
								for (h = h307, hp_0 = 0;h < h307 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w289, wp_0 = 0;w < w289 + 3;w += 1, wp_0 += 1){
												mem_vec_4996 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4997 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_4998 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4999 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_5000 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_5001 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_5002 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_5003 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_5004 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_5005 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_5006 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_5007 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_5008 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_5009 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_5010 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_5011 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c762, cp_1 = c762_p_0, cp_0 = 0;c < c762 + 8;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4996);
													mem_vec_4996 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4997);
													mem_vec_4997 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4998);
													mem_vec_4998 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4999);
													mem_vec_4999 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5000);
													mem_vec_5000 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5001);
													mem_vec_5001 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5002);
													mem_vec_5002 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5003);
													mem_vec_5003 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5004);
													mem_vec_5004 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5005);
													mem_vec_5005 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5006);
													mem_vec_5006 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5007);
													mem_vec_5007 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5008);
													mem_vec_5008 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5009);
													mem_vec_5009 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5010);
													mem_vec_5010 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5011);
													mem_vec_5011 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4996);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4997);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4998);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4999);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5000);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5001);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5002);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_5003);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5004);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5005);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5006);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_5007);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5008);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5009);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5010);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_5011);
									}
								}
}
