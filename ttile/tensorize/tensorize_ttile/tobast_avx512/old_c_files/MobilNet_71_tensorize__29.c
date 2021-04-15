
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 8))];
  T (2, f); T (1, c); T (2, f); T (2, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1228_p_0, c1229_p_0, cp_1, c1228_p_1, cp_2, c1228, c1229, f, fp_0, f1088_p_0, f1089_p_0, fp_1, f1088_p_1, fp_2, f1088, f1089, h, hp_0, x, xp_0, x938_p_0, xp_1, x938, y, yp_0;
IND_TYPE y628 = 0;
IND_TYPE x939 = 0;
IND_TYPE h568 = 0;
IND_TYPE w = 0;
IND_TYPE c1230 = 0;
IND_TYPE f1090 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
f1089 = 0;
f1089_p_0 = 0;
x938 = 0;
x938_p_0 = 0;
c1229 = 0;
c1229_p_0 = 0;
f1088 = 0;
f1088_p_1 = 0;
c1228 = 0;
c1228_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
								for (h = h568, hp_0 = 0;h < h568 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 256, f = 32
									// T (x, 14) (14 / 1)
									for (x = x938, xp_1 = x938_p_0, xp_0 = 0;x < x938 + 14;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6756 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_6757 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_6758 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_6759 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_6760 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_6761 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_6762 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_6763 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_6764 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_6765 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_6766 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_6767 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1228, cp_2 = c1228_p_1, cp_1 = c1228_p_0, cp_0 = 0;c < c1228 + 256;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6756);
													mem_vec_6756 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6757);
													mem_vec_6757 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6758);
													mem_vec_6758 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6759);
													mem_vec_6759 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6760);
													mem_vec_6760 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6761);
													mem_vec_6761 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6762);
													mem_vec_6762 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6763);
													mem_vec_6763 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6764);
													mem_vec_6764 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6765);
													mem_vec_6765 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6766);
													mem_vec_6766 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6767);
													mem_vec_6767 = vec_19;
													scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_6756);
													mem_vec_6756 = vec_20;
													vec_24 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_6757);
													mem_vec_6757 = vec_23;
													scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);
													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_6758);
													mem_vec_6758 = vec_25;
													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_6759);
													mem_vec_6759 = vec_27;
													scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_6760);
													mem_vec_6760 = vec_28;
													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_6761);
													mem_vec_6761 = vec_30;
													scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);
													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_6762);
													mem_vec_6762 = vec_31;
													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_6763);
													mem_vec_6763 = vec_33;
													scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_6764);
													mem_vec_6764 = vec_34;
													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_6765);
													mem_vec_6765 = vec_36;
													scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);
													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_6766);
													mem_vec_6766 = vec_37;
													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_6767);
													mem_vec_6767 = vec_39;
													scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_6756);
													mem_vec_6756 = vec_40;
													vec_44 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_6757);
													mem_vec_6757 = vec_43;
													scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);
													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_6758);
													mem_vec_6758 = vec_45;
													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_6759);
													mem_vec_6759 = vec_47;
													scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);
													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6760);
													mem_vec_6760 = vec_48;
													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_6761);
													mem_vec_6761 = vec_50;
													scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);
													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_6762);
													mem_vec_6762 = vec_51;
													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_6763);
													mem_vec_6763 = vec_53;
													scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);
													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_6764);
													mem_vec_6764 = vec_54;
													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_6765);
													mem_vec_6765 = vec_56;
													scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);
													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_6766);
													mem_vec_6766 = vec_57;
													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_6767);
													mem_vec_6767 = vec_59;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6756);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6757);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6758);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6759);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6760);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6761);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6762);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6763);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6764);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6765);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6766);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6767);
									}
								}
}
