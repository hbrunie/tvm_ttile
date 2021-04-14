
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))];
  T (1, f); T (8, c); T (4, f); T (2, x); T (2, f)]
*/
IND_TYPE c, cp_0, c726_p_0, cp_1, c726, f, fp_0, f968_p_0, f969_p_0, fp_1, f968_p_1, fp_2, f968, f969, h, hp_0, w, wp_0, x, xp_0, x778_p_0, xp_1, x778, y, yp_0;
IND_TYPE y484 = 0;
IND_TYPE x779 = 0;
IND_TYPE h484 = 0;
IND_TYPE w432 = 0;
IND_TYPE c727 = 0;
IND_TYPE f970 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8740 ,mem_vec_8741 ,mem_vec_8742 ,mem_vec_8743 ,mem_vec_8744 ,mem_vec_8745 ,mem_vec_8746 ,mem_vec_8747 ,mem_vec_8748 ,mem_vec_8749 ,mem_vec_8750 ,mem_vec_8751 ,mem_vec_8752 ,mem_vec_8753 ,mem_vec_8754 ,mem_vec_8755 ,mem_vec_8756 ,mem_vec_8757 ,mem_vec_8758 ,mem_vec_8759 ,mem_vec_8760 ,mem_vec_8761 ,mem_vec_8762 ,mem_vec_8763 ,mem_vec_8764 ,mem_vec_8765 ,mem_vec_8766 ,mem_vec_8767 ,mem_vec_8768 ,mem_vec_8769 ,mem_vec_8770 ,mem_vec_8771 ,mem_vec_8772 ,mem_vec_8773 ,mem_vec_8774 ,mem_vec_8775 ,mem_vec_8776 ,mem_vec_8777 ,mem_vec_8778 ,mem_vec_8779 ,mem_vec_8780 ,mem_vec_8781 ,mem_vec_8782 ,mem_vec_8783 ,mem_vec_8784 ,mem_vec_8785 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f969 = 0;
f969_p_0 = 0;
x778 = 0;
x778_p_0 = 0;
f968 = 0;
f968_p_1 = 0;
c726 = 0;
c726_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h484, hp_0 = 0;h < h484 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w432, wp_0 = 0;w < w432 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 16, f = 32
									// T (x, 34) (34 / 1)
									for (x = x778, xp_1 = x778_p_0, xp_0 = 0;x < x778 + 34;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8740 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_8741 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_8742 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_8743 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_8744 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_8745 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_8746 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_8747 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_8748 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_8749 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_8750 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_8751 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_8752 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_8753 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_8754 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_8755 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_8756 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_8757 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c726, cp_1 = c726_p_0, cp_0 = 0;c < c726 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8740);
													mem_vec_8740 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8741);
													mem_vec_8741 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8742);
													mem_vec_8742 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8743);
													mem_vec_8743 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8744);
													mem_vec_8744 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8745);
													mem_vec_8745 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8746);
													mem_vec_8746 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8747);
													mem_vec_8747 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8748);
													mem_vec_8748 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8749);
													mem_vec_8749 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8750);
													mem_vec_8750 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8751);
													mem_vec_8751 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8752);
													mem_vec_8752 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8753);
													mem_vec_8753 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8754);
													mem_vec_8754 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8755);
													mem_vec_8755 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8756);
													mem_vec_8756 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8757);
													mem_vec_8757 = vec_28;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8740);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8741);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8742);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8743);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8744);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8745);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8746);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8747);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8748);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8749);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8750);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8751);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8752);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8753);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8754);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8755);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8756);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8757);
									}
								}
							}
}
