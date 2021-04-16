void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (1, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, x, xp_0, x150_p_0, x151_p_0, x152_p_0, xp_1, x150_p_1, x151_p_1, xp_2, x150_p_2, xp_3, x150, x151, x152, y, yp_0, y120_p_0, y121_p_0, yp_1, y120_p_1, yp_2, y120, y121;
IND_TYPE y122 = 0;
IND_TYPE x153 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c91 = 0;
IND_TYPE f60 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y121 = 0;
y121_p_0 = 0;
x152 = 0;
x152_p_0 = 0;
y120 = 0;
y120_p_1 = 0;
x151 = 0;
x151_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x150 = 0;
x150_p_2 = 0;
c90 = 0;
c90_p_0 = 0;
									for (x = x150, xp_3 = x150_p_2, xp_2 = x150_p_1, xp_1 = x150_p_0, xp_0 = 0;x < x150 + 2;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_696 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_697 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_698 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_699 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_700 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_701 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_702 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_703 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_704 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_705 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_706 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_707 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_708 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_709 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_710 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_711 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_712 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_713 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_714 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_715 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c90, cp_1 = c90_p_0, cp_0 = 0;c < c90 + 64;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_696);
													mem_vec_696 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_697);
													mem_vec_697 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_698);
													mem_vec_698 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_699);
													mem_vec_699 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_700);
													mem_vec_700 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_701);
													mem_vec_701 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_702);
													mem_vec_702 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_703);
													mem_vec_703 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_704);
													mem_vec_704 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_705);
													mem_vec_705 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_706);
													mem_vec_706 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_707);
													mem_vec_707 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_708);
													mem_vec_708 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_709);
													mem_vec_709 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_710);
													mem_vec_710 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_711);
													mem_vec_711 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_712);
													mem_vec_712 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_713);
													mem_vec_713 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_714);
													mem_vec_714 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_715);
													mem_vec_715 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_696);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_697);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_698);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_699);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_700);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_701);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_702);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_703);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_704);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_705);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_706);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_707);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_708);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_709);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_710);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_711);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_712);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_713);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_714);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_715);
									}
}
