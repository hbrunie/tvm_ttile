
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); T (2, y); T (1, f); T (16, c); T (16, f);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, f8_p_0, f9_p_0, fp_1, f8_p_1, fp_2, f8, f9, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y6_p_0, yp_1, y6;
IND_TYPE y7 = 0;
IND_TYPE x4 = 0;
IND_TYPE h4 = 0;
IND_TYPE w4 = 0;
IND_TYPE c7 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_100 ,mem_vec_101 ,mem_vec_102 ,mem_vec_103 ,mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,mem_vec_76 ,mem_vec_77 ,mem_vec_78 ,mem_vec_79 ,mem_vec_80 ,mem_vec_81 ,mem_vec_82 ,mem_vec_83 ,mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f9 = 0;
f9_p_0 = 0;
y6 = 0;
y6_p_0 = 0;
f8 = 0;
f8_p_1 = 0;
c6 = 0;
c6_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
								for (h = h4, hp_0 = 0;h < h4 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w4, wp_0 = 0;w < w4 + 3;w += 1, wp_0 += 1){
												mem_vec_72 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_73 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_74 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_75 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_76 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_77 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_78 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_79 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_80 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_81 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_82 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_83 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_84 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_85 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_86 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_87 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c6, cp_1 = c6_p_0, cp_0 = 0;c < c6 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_72);
													mem_vec_72 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_73);
													mem_vec_73 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_74);
													mem_vec_74 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_75);
													mem_vec_75 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_76);
													mem_vec_76 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_77);
													mem_vec_77 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_78);
													mem_vec_78 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_79);
													mem_vec_79 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_80);
													mem_vec_80 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_81);
													mem_vec_81 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_82);
													mem_vec_82 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_83);
													mem_vec_83 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_84);
													mem_vec_84 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_85);
													mem_vec_85 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_86);
													mem_vec_86 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_87);
													mem_vec_87 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_72);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_73);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_74);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_75);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_76);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_77);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_78);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_79);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_80);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_81);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_82);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_83);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_84);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_85);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_86);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_87);
									}
								}
}
