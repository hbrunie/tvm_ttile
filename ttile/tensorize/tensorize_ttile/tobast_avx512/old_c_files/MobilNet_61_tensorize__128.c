
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 1), (Arg 9))];
  T (2, f); T (1, c); T (2, f); T (256, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1034_p_0, c1035_p_0, cp_1, c1034_p_1, cp_2, c1034, c1035, f, fp_0, f1010_p_0, f1011_p_0, fp_1, f1010_p_1, fp_2, f1010, f1011, h, hp_0, x, xp_0, x838_p_0, xp_1, x838, y, yp_0;
IND_TYPE y560 = 0;
IND_TYPE x839 = 0;
IND_TYPE h502 = 0;
IND_TYPE w = 0;
IND_TYPE c1036 = 0;
IND_TYPE f1012 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,mem_vec_5632 ,mem_vec_5633 ,mem_vec_5634 ,mem_vec_5635 ,mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
f1011 = 0;
f1011_p_0 = 0;
x838 = 0;
x838_p_0 = 0;
c1035 = 0;
c1035_p_0 = 0;
f1010 = 0;
f1010_p_1 = 0;
c1034 = 0;
c1034_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
								for (h = h502, hp_0 = 0;h < h502 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x838, xp_1 = x838_p_0, xp_0 = 0;x < x838 + 14;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_5613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_5614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_5615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_5616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_5617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_5618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_5619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_5620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_5621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1034, cp_2 = c1034_p_1, cp_1 = c1034_p_0, cp_0 = 0;c < c1034 + 1;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5612);
													mem_vec_5612 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5613);
													mem_vec_5613 = vec_3;
													scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5614);
													mem_vec_5614 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5615);
													mem_vec_5615 = vec_7;
													scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5616);
													mem_vec_5616 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5617);
													mem_vec_5617 = vec_10;
													scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5618);
													mem_vec_5618 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5619);
													mem_vec_5619 = vec_13;
													scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5620);
													mem_vec_5620 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5621);
													mem_vec_5621 = vec_16;
													scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_5612);
													mem_vec_5612 = vec_17;
													vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_5613);
													mem_vec_5613 = vec_20;
													scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_5614);
													mem_vec_5614 = vec_22;
													vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_5615);
													mem_vec_5615 = vec_24;
													scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);
													vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_5616);
													mem_vec_5616 = vec_25;
													vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_5617);
													mem_vec_5617 = vec_27;
													scal_8 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_5618);
													mem_vec_5618 = vec_28;
													vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5619);
													mem_vec_5619 = vec_30;
													scal_9 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 4) + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);
													vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_5620);
													mem_vec_5620 = vec_31;
													vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_5621);
													mem_vec_5621 = vec_33;
													scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5612);
													mem_vec_5612 = vec_34;
													vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5613);
													mem_vec_5613 = vec_37;
													scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);
													vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_5614);
													mem_vec_5614 = vec_39;
													vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_5615);
													mem_vec_5615 = vec_41;
													scal_12 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
													vec_43 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_5616);
													mem_vec_5616 = vec_42;
													vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_5617);
													mem_vec_5617 = vec_44;
													scal_13 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);
													vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_5618);
													mem_vec_5618 = vec_45;
													vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_5619);
													mem_vec_5619 = vec_47;
													scal_14 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 4) + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);
													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5620);
													mem_vec_5620 = vec_48;
													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5621);
													mem_vec_5621 = vec_50;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5612);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5613);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5614);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5615);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5616);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5617);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5618);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5619);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5620);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5621);
									}
								}
}
