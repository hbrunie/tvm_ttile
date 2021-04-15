
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (1, y); T (1, f); T (1, c); T (1, x); T (68, y); T (2, f);
  T (68, x)]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, f108_p_0, fp_1, f108, h, hp_0, w, wp_0, x, xp_0, x144_p_0, x145_p_0, xp_1, x144_p_1, xp_2, x144, x145, y, yp_0, y108_p_0, yp_1, y108;
IND_TYPE y109 = 0;
IND_TYPE x146 = 0;
IND_TYPE h72 = 0;
IND_TYPE w72 = 0;
IND_TYPE c109 = 0;
IND_TYPE f109 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 68) (272 / 4)
x145 = 0;
x145_p_0 = 0;
f108 = 0;
f108_p_0 = 0;
y108 = 0;
y108_p_0 = 0;
x144 = 0;
x144_p_1 = 0;
c108 = 0;
c108_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
							for (h = h72, hp_0 = 0;h < h72 + 3;h += 1, hp_0 += 1){
								// y = 4, x = 4, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w72, wp_0 = 0;w < w72 + 3;w += 1, wp_0 += 1){
									// y = 4, x = 4, h = 1, w = 1, c = 32, f = 32
									// T (x, 4) (4 / 1)
									for (x = x144, xp_2 = x144_p_1, xp_1 = x144_p_0, xp_0 = 0;x < x144 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_576 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_577 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_578 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_579 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_580 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_581 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_582 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_583 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_584 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_585 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_586 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_587 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_588 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_589 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_590 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_591 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c108, cp_1 = c108_p_0, cp_0 = 0;c < c108 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_576);
													mem_vec_576 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_577);
													mem_vec_577 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_578);
													mem_vec_578 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_579);
													mem_vec_579 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_580);
													mem_vec_580 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_581);
													mem_vec_581 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_582);
													mem_vec_582 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_583);
													mem_vec_583 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_584);
													mem_vec_584 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_585);
													mem_vec_585 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_586);
													mem_vec_586 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_587);
													mem_vec_587 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_588);
													mem_vec_588 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_589);
													mem_vec_589 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_590);
													mem_vec_590 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_591);
													mem_vec_591 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_576);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_577);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_578);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_579);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_580);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_581);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_582);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_583);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_584);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_585);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_586);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_587);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_588);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_589);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_590);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_591);
									}
								}
							}
}
