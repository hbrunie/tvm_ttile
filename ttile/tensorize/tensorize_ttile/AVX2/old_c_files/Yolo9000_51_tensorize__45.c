
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
  T (1, x); T (2, y); T (2, f); T (1, x); T (4, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c330_p_0, cp_1, c330, f, fp_0, x, xp_0, x550_p_0, x551_p_0, x552_p_0, xp_1, x550_p_1, x551_p_1, xp_2, x550_p_2, xp_3, x550, x551, x552, y, yp_0, y440_p_0, y441_p_0, yp_1, y440_p_1, yp_2, y440, y441;
IND_TYPE y442 = 0;
IND_TYPE x553 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c331 = 0;
IND_TYPE f220 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3560 ,mem_vec_3561 ,mem_vec_3562 ,mem_vec_3563 ,mem_vec_3564 ,mem_vec_3565 ,mem_vec_3566 ,mem_vec_3567 ,mem_vec_3568 ,mem_vec_3569 ,mem_vec_3570 ,mem_vec_3571 ,mem_vec_3572 ,mem_vec_3573 ,mem_vec_3574 ,mem_vec_3575 ,mem_vec_3576 ,mem_vec_3577 ,mem_vec_3578 ,mem_vec_3579 ,mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y441 = 0;
y441_p_0 = 0;
x552 = 0;
x552_p_0 = 0;
y440 = 0;
y440_p_1 = 0;
x551 = 0;
x551_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x550 = 0;
x550_p_2 = 0;
c330 = 0;
c330_p_0 = 0;
									for (x = x550, xp_3 = x550_p_2, xp_2 = x550_p_1, xp_1 = x550_p_0, xp_0 = 0;x < x550 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3560 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3561 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_3562 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3563 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_3564 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3565 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_3566 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3567 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_3568 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3569 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_3570 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3571 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_3572 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3573 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_3574 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3575 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c330, cp_1 = c330_p_0, cp_0 = 0;c < c330 + 128;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3560);
													mem_vec_3560 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3561);
													mem_vec_3561 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3562);
													mem_vec_3562 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3563);
													mem_vec_3563 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3564);
													mem_vec_3564 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3565);
													mem_vec_3565 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3566);
													mem_vec_3566 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3567);
													mem_vec_3567 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3568);
													mem_vec_3568 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3569);
													mem_vec_3569 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3570);
													mem_vec_3570 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3571);
													mem_vec_3571 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3572);
													mem_vec_3572 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3573);
													mem_vec_3573 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3574);
													mem_vec_3574 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3575);
													mem_vec_3575 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3560);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3561);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3562);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3563);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3564);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3565);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3566);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3567);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3568);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3569);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3570);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3571);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3572);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3573);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3574);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3575);
									}
}
