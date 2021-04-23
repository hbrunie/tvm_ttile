
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))]; T (4, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c543_p_0, cp_1, c543, f, fp_0, f700_p_0, f701_p_0, fp_1, f700_p_1, fp_2, f700, f701, h, hp_0, w, wp_0, x, xp_0, x543_p_0, xp_1, x543, y, yp_0;
IND_TYPE y374 = 0;
IND_TYPE x544 = 0;
IND_TYPE h340 = 0;
IND_TYPE w332 = 0;
IND_TYPE c544 = 0;
IND_TYPE f702 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6726 ,mem_vec_6727 ,mem_vec_6728 ,mem_vec_6729 ,mem_vec_6730 ,mem_vec_6731 ,mem_vec_6732 ,mem_vec_6733 ,mem_vec_6734 ,mem_vec_6735 ,mem_vec_6736 ,mem_vec_6737 ,mem_vec_6738 ,mem_vec_6739 ,mem_vec_6740 ,mem_vec_6741 ,mem_vec_6742 ,mem_vec_6743 ,mem_vec_6744 ,mem_vec_6745 ,mem_vec_6746 ,mem_vec_6747 ,mem_vec_6748 ,mem_vec_6749 ,mem_vec_6750 ,mem_vec_6751 ,mem_vec_6752 ,mem_vec_6753 ,mem_vec_6754 ,mem_vec_6755 ,mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f701 = 0;
f701_p_0 = 0;
f700 = 0;
f700_p_1 = 0;
x543 = 0;
x543_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c543 = 0;
c543_p_0 = 0;
							for (w = w332, wp_0 = 0;w < w332 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x543, xp_1 = x543_p_0, xp_0 = 0;x < x543 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h340, hp_0 = 0;h < h340 + 3;h += 1, hp_0 += 1){
												mem_vec_6726 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_6727 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_6728 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_6729 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_6730 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_6731 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_6732 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_6733 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_6734 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_6735 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_6736 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_6737 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_6738 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_6739 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_6740 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_6741 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_6742 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_6743 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c543, cp_1 = c543_p_0, cp_0 = 0;c < c543 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6726);
													mem_vec_6726 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6727);
													mem_vec_6727 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6728);
													mem_vec_6728 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6729);
													mem_vec_6729 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6730);
													mem_vec_6730 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6731);
													mem_vec_6731 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6732);
													mem_vec_6732 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6733);
													mem_vec_6733 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6734);
													mem_vec_6734 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6735);
													mem_vec_6735 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6736);
													mem_vec_6736 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6737);
													mem_vec_6737 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6738);
													mem_vec_6738 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6739);
													mem_vec_6739 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6740);
													mem_vec_6740 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6741);
													mem_vec_6741 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6742);
													mem_vec_6742 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6743);
													mem_vec_6743 = vec_28;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6726);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6727);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6728);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6729);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6730);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6731);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6732);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6733);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6734);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6735);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6736);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6737);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6738);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6739);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6740);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6741);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6742);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6743);
									}
								}
							}
}
