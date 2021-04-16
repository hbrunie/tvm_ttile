void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (2, y); T (2, f); T (16, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c759_p_0, cp_1, c759, f, fp_0, f754_p_0, f755_p_0, fp_1, f754_p_1, fp_2, f754, f755, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y399_p_0, yp_1, y399;
IND_TYPE y400 = 0;
IND_TYPE x386 = 0;
IND_TYPE h305 = 0;
IND_TYPE w287 = 0;
IND_TYPE c760 = 0;
IND_TYPE f756 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4960 ,mem_vec_4961 ,mem_vec_4962 ,mem_vec_4963 ,mem_vec_4964 ,mem_vec_4965 ,mem_vec_4966 ,mem_vec_4967 ,mem_vec_4968 ,mem_vec_4969 ,mem_vec_4970 ,mem_vec_4971 ,mem_vec_4972 ,mem_vec_4973 ,mem_vec_4974 ,mem_vec_4975 ,mem_vec_4976 ,mem_vec_4977 ,mem_vec_4978 ,mem_vec_4979 ,mem_vec_4980 ,mem_vec_4981 ,mem_vec_4982 ,mem_vec_4983 ,mem_vec_4984 ,mem_vec_4985 ,mem_vec_4986 ,mem_vec_4987 ,mem_vec_4988 ,mem_vec_4989 ,mem_vec_4990 ,mem_vec_4991 ,mem_vec_4992 ,mem_vec_4993 ,mem_vec_4994 ,mem_vec_4995 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f755 = 0;
f755_p_0 = 0;
y399 = 0;
y399_p_0 = 0;
f754 = 0;
f754_p_1 = 0;
c759 = 0;
c759_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
								for (h = h305, hp_0 = 0;h < h305 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w287, wp_0 = 0;w < w287 + 3;w += 1, wp_0 += 1){
												mem_vec_4976 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4977 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_4978 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4979 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_4980 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4981 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_4982 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4983 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_4984 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4985 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_4986 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4987 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_4988 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4989 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_4990 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_4991 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_4992 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_4993 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_4994 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_4995 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c759, cp_1 = c759_p_0, cp_0 = 0;c < c759 + 8;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4976);
													mem_vec_4976 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4977);
													mem_vec_4977 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4978);
													mem_vec_4978 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4979);
													mem_vec_4979 = vec_7;
													scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4980);
													mem_vec_4980 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4981);
													mem_vec_4981 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4982);
													mem_vec_4982 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4983);
													mem_vec_4983 = vec_13;
													scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4984);
													mem_vec_4984 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4985);
													mem_vec_4985 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4986);
													mem_vec_4986 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4987);
													mem_vec_4987 = vec_18;
													scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4988);
													mem_vec_4988 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4989);
													mem_vec_4989 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4990);
													mem_vec_4990 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4991);
													mem_vec_4991 = vec_23;
													scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4992);
													mem_vec_4992 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4993);
													mem_vec_4993 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4994);
													mem_vec_4994 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4995);
													mem_vec_4995 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4976);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4977);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4978);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4979);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4980);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4981);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4982);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4983);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4984);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4985);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4986);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4987);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4988);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4989);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4990);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4991);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4992);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4993);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4994);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_4995);
									}
								}
}
