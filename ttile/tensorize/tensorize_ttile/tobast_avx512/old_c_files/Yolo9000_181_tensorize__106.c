
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (4, f);
  T (32, c); T (4, f)]
*/
IND_TYPE c, cp_0, c716_p_0, cp_1, c716, f, fp_0, f768_p_0, f769_p_0, fp_1, f768_p_1, fp_2, f768, f769, h, hp_0, x, xp_0, x636_p_0, xp_1, x636, y, yp_0;
IND_TYPE y424 = 0;
IND_TYPE x637 = 0;
IND_TYPE h310 = 0;
IND_TYPE w = 0;
IND_TYPE c717 = 0;
IND_TYPE f770 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5566 ,mem_vec_5567 ,mem_vec_5568 ,mem_vec_5569 ,mem_vec_5570 ,mem_vec_5571 ,mem_vec_5572 ,mem_vec_5573 ,mem_vec_5574 ,mem_vec_5575 ,mem_vec_5576 ,mem_vec_5577 ,mem_vec_5578 ,mem_vec_5579 ,mem_vec_5580 ,mem_vec_5581 ,mem_vec_5582 ,mem_vec_5583 ,mem_vec_5584 ,mem_vec_5585 ,mem_vec_5586 ,mem_vec_5587 ,mem_vec_5588 ,mem_vec_5589 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
f769 = 0;
f769_p_0 = 0;
c716 = 0;
c716_p_0 = 0;
f768 = 0;
f768_p_1 = 0;
y = 0;
yp_0 = 0;
x636 = 0;
x636_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h310, hp_0 = 0;h < h310 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x636, xp_1 = x636_p_0, xp_0 = 0;x < x636 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5568 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5569 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5570 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5571 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5572 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5573 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5574 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5575 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c716, cp_1 = c716_p_0, cp_0 = 0;c < c716 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5566);
												mem_vec_5566 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5567);
												mem_vec_5567 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5568);
												mem_vec_5568 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5569);
												mem_vec_5569 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5570);
												mem_vec_5570 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5571);
												mem_vec_5571 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5572);
												mem_vec_5572 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5573);
												mem_vec_5573 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5574);
												mem_vec_5574 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5575);
												mem_vec_5575 = vec_16;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_19 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_5566);
												mem_vec_5566 = vec_17;
												vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_5567);
												mem_vec_5567 = vec_20;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_23 = _mm512_set1_ps(scal_6);
												vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_5568);
												mem_vec_5568 = vec_22;
												vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_5569);
												mem_vec_5569 = vec_24;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_26 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_5570);
												mem_vec_5570 = vec_25;
												vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_5571);
												mem_vec_5571 = vec_27;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_5572);
												mem_vec_5572 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5573);
												mem_vec_5573 = vec_30;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_5574);
												mem_vec_5574 = vec_31;
												vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_5575);
												mem_vec_5575 = vec_33;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);
												vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5566);
												mem_vec_5566 = vec_34;
												vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5567);
												mem_vec_5567 = vec_37;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_40 = _mm512_set1_ps(scal_11);
												vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_5568);
												mem_vec_5568 = vec_39;
												vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_5569);
												mem_vec_5569 = vec_41;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_43 = _mm512_set1_ps(scal_12);
												vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_5570);
												mem_vec_5570 = vec_42;
												vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_5571);
												mem_vec_5571 = vec_44;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_46 = _mm512_set1_ps(scal_13);
												vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_5572);
												mem_vec_5572 = vec_45;
												vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_5573);
												mem_vec_5573 = vec_47;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_49 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5574);
												mem_vec_5574 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5575);
												mem_vec_5575 = vec_50;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5566);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5567);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5568);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5569);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5570);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5571);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5572);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5573);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5574);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5575);
								}
							}
}
