
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (2, x); T (128, c);
  T (4, f); T (34, x); T (17, y)]
*/
IND_TYPE c, cp_0, c123_p_0, cp_1, c123, f, fp_0, x, xp_0, x123_p_0, xp_1, x123, y, yp_0;
IND_TYPE y82 = 0;
IND_TYPE x124 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c124 = 0;
IND_TYPE f82 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 17) (68 / 4)
y = 0;
yp_0 = 0;
x123 = 0;
x123_p_0 = 0;
f = 0;
fp_0 = 0;
c123 = 0;
c123_p_0 = 0;
				for (x = x123, xp_1 = x123_p_0, xp_0 = 0;x < x123 + 2;x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_656 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
							mem_vec_657 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
							mem_vec_658 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
							mem_vec_659 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
							mem_vec_660 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
							mem_vec_661 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
							mem_vec_662 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
							mem_vec_663 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
							mem_vec_664 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
							mem_vec_665 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
							mem_vec_666 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
							mem_vec_667 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
							mem_vec_668 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
							mem_vec_669 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
							mem_vec_670 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
							mem_vec_671 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
							// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (c, 2) (2 / 1)
							for (c = c123, cp_1 = c123_p_0, cp_0 = 0;c < c123 + 2;c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
								vec_1 = _mm256_set1_ps(scal_0);
								vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
								vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_656);
								mem_vec_656 = vec_0;
								vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
								vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_657);
								mem_vec_657 = vec_3;
								vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
								vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_658);
								mem_vec_658 = vec_5;
								vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
								vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_659);
								mem_vec_659 = vec_7;
								scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
								vec_10 = _mm256_set1_ps(scal_1);
								vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_660);
								mem_vec_660 = vec_9;
								vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_661);
								mem_vec_661 = vec_11;
								vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_662);
								mem_vec_662 = vec_12;
								vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_663);
								mem_vec_663 = vec_13;
								scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
								vec_15 = _mm256_set1_ps(scal_2);
								vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_664);
								mem_vec_664 = vec_14;
								vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_665);
								mem_vec_665 = vec_16;
								vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_666);
								mem_vec_666 = vec_17;
								vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_667);
								mem_vec_667 = vec_18;
								scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
								vec_20 = _mm256_set1_ps(scal_3);
								vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_668);
								mem_vec_668 = vec_19;
								vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_669);
								mem_vec_669 = vec_21;
								vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_670);
								mem_vec_670 = vec_22;
								vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_671);
								mem_vec_671 = vec_23;
							}
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_656);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_657);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_658);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_659);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_660);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_661);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_662);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_663);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_664);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_665);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_666);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_667);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_668);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_669);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_670);
						_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_671);
				}
}
