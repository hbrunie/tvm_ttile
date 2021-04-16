
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (1, y); T (2, f); T (1, x); T (8, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c342_p_0, cp_1, c342, f, fp_0, x, xp_0, x570_p_0, x571_p_0, x572_p_0, xp_1, x570_p_1, x571_p_1, xp_2, x570_p_2, xp_3, x570, x571, x572, y, yp_0, y456_p_0, y457_p_0, yp_1, y456_p_1, yp_2, y456, y457;
IND_TYPE y458 = 0;
IND_TYPE x573 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c343 = 0;
IND_TYPE f228 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3704 ,mem_vec_3705 ,mem_vec_3706 ,mem_vec_3707 ,mem_vec_3708 ,mem_vec_3709 ,mem_vec_3710 ,mem_vec_3711 ,mem_vec_3712 ,mem_vec_3713 ,mem_vec_3714 ,mem_vec_3715 ,mem_vec_3716 ,mem_vec_3717 ,mem_vec_3718 ,mem_vec_3719 ,mem_vec_3720 ,mem_vec_3721 ,mem_vec_3722 ,mem_vec_3723 ,mem_vec_3724 ,mem_vec_3725 ,mem_vec_3726 ,mem_vec_3727 ,mem_vec_3728 ,mem_vec_3729 ,mem_vec_3730 ,mem_vec_3731 ,mem_vec_3732 ,mem_vec_3733 ,mem_vec_3734 ,mem_vec_3735 ,mem_vec_3736 ,mem_vec_3737 ,mem_vec_3738 ,mem_vec_3739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y457 = 0;
y457_p_0 = 0;
x572 = 0;
x572_p_0 = 0;
y456 = 0;
y456_p_1 = 0;
x571 = 0;
x571_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x570 = 0;
x570_p_2 = 0;
c342 = 0;
c342_p_0 = 0;
									for (x = x570, xp_3 = x570_p_2, xp_2 = x570_p_1, xp_1 = x570_p_0, xp_0 = 0;x < x570 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3704 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_3705 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_3706 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_3707 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_3708 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_3709 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_3710 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_3711 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_3712 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_3713 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_3714 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_3715 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_3716 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_3717 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_3718 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_3719 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c342, cp_1 = c342_p_0, cp_0 = 0;c < c342 + 64;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3704);
													mem_vec_3704 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3705);
													mem_vec_3705 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3706);
													mem_vec_3706 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3707);
													mem_vec_3707 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3708);
													mem_vec_3708 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3709);
													mem_vec_3709 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3710);
													mem_vec_3710 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3711);
													mem_vec_3711 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3712);
													mem_vec_3712 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3713);
													mem_vec_3713 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3714);
													mem_vec_3714 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3715);
													mem_vec_3715 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3716);
													mem_vec_3716 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3717);
													mem_vec_3717 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3718);
													mem_vec_3718 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3719);
													mem_vec_3719 = vec_23;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3704);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3705);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3706);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3707);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3708);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3709);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3710);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3711);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3712);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3713);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3714);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3715);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3716);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3717);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3718);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3719);
									}
}
