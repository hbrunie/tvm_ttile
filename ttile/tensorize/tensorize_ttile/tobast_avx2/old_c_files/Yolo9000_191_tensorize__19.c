
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (16, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (256, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, f936_p_0, f937_p_0, fp_1, f936_p_1, fp_2, f936, f937, x, xp_0, x936_p_0, x937_p_0, xp_1, x936_p_1, xp_2, x936, x937, y, yp_0;
IND_TYPE y468 = 0;
IND_TYPE x938 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c703 = 0;
IND_TYPE f938 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_8424 ,mem_vec_8425 ,mem_vec_8426 ,mem_vec_8427 ,mem_vec_8428 ,mem_vec_8429 ,mem_vec_8430 ,mem_vec_8431 ,mem_vec_8432 ,mem_vec_8433 ,mem_vec_8434 ,mem_vec_8435 ,mem_vec_8436 ,mem_vec_8437 ,mem_vec_8438 ,mem_vec_8439 ,mem_vec_8440 ,mem_vec_8441 ,mem_vec_8442 ,mem_vec_8443 ,mem_vec_8444 ,mem_vec_8445 ,mem_vec_8446 ,mem_vec_8447 ,mem_vec_8448 ,mem_vec_8449 ,mem_vec_8450 ,mem_vec_8451 ,mem_vec_8452 ,mem_vec_8453 ,mem_vec_8454 ,mem_vec_8455 ,mem_vec_8456 ,mem_vec_8457 ,mem_vec_8458 ,mem_vec_8459 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
f937 = 0;
f937_p_0 = 0;
x937 = 0;
x937_p_0 = 0;
c702 = 0;
c702_p_0 = 0;
f936 = 0;
f936_p_1 = 0;
y = 0;
yp_0 = 0;
x936 = 0;
x936_p_1 = 0;
f = 0;
fp_2 = 0;
								for (x = x936, xp_2 = x936_p_1, xp_1 = x936_p_0, xp_0 = 0;x < x936 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8424 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_8425 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_8426 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_8427 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_8428 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_8429 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_8430 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_8431 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_8432 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_8433 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_8434 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_8435 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_8436 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_8437 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_8438 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_8439 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c702, cp_1 = c702_p_0, cp_0 = 0;c < c702 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8424);
												mem_vec_8424 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8425);
												mem_vec_8425 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8426);
												mem_vec_8426 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8427);
												mem_vec_8427 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8428);
												mem_vec_8428 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8429);
												mem_vec_8429 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8430);
												mem_vec_8430 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8431);
												mem_vec_8431 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8432);
												mem_vec_8432 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8433);
												mem_vec_8433 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8434);
												mem_vec_8434 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8435);
												mem_vec_8435 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8436);
												mem_vec_8436 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8437);
												mem_vec_8437 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8438);
												mem_vec_8438 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8439);
												mem_vec_8439 = vec_23;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8424);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_8425);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8426);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_8427);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8428);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_8429);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8430);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_8431);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8432);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_8433);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8434);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_8435);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8436);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_8437);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8438);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_8439);
								}
}
