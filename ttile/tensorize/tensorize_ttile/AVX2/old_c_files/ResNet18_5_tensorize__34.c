
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (7, x); T (4, f);
  T (1, x); T (7, y); T (4, x); T (1, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0, y102_p_0, yp_1, y102;
IND_TYPE y103 = 0;
IND_TYPE x138 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c68 = 0;
IND_TYPE f68 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 1) (28 / 28)
y102 = 0;
y102_p_0 = 0;
x137 = 0;
x137_p_0 = 0;
y = 0;
yp_1 = 0;
x136 = 0;
x136_p_1 = 0;
f = 0;
fp_0 = 0;
					for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;x < x136 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_544 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_545 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
								mem_vec_546 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_547 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
								mem_vec_548 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_549 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
								mem_vec_550 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_551 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
								mem_vec_552 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_553 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
								mem_vec_554 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_555 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
								mem_vec_556 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_557 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
								mem_vec_558 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_559 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c68, cp_0 = 0;c < c68 + 64;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_544);
									mem_vec_544 = vec_0;
									vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_545);
									mem_vec_545 = vec_3;
									vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_546);
									mem_vec_546 = vec_5;
									vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_547);
									mem_vec_547 = vec_7;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);
									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_548);
									mem_vec_548 = vec_9;
									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_549);
									mem_vec_549 = vec_11;
									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_550);
									mem_vec_550 = vec_12;
									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_551);
									mem_vec_551 = vec_13;
									scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);
									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_552);
									mem_vec_552 = vec_14;
									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_553);
									mem_vec_553 = vec_16;
									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_554);
									mem_vec_554 = vec_17;
									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_555);
									mem_vec_555 = vec_18;
									scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);
									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_556);
									mem_vec_556 = vec_19;
									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_557);
									mem_vec_557 = vec_21;
									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_558);
									mem_vec_558 = vec_22;
									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_559);
									mem_vec_559 = vec_23;
								}
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_544);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_545);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_546);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_547);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_548);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_549);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_550);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_551);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_552);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_553);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_554);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_555);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_556);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_557);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_558);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_559);
					}
}
