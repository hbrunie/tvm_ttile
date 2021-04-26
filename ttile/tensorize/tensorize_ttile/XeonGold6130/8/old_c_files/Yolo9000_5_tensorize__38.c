
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0, y57_p_0, yp_1, y57;
IND_TYPE y58 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c38 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
y57 = 0;
y57_p_0 = 0;
x57 = 0;
x57_p_0 = 0;
		for (f = f38, fp_0 = 0;f < f38 + 64;f += 32, fp_0 += 32){
				for (y = y57, yp_1 = y57_p_0, yp_0 = 0;y < y57 + 8;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x57, xp_1 = x57_p_0, xp_0 = 0;x < x57 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_776 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_777 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_778 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_779 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_780 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_781 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_782 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_783 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_784 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_785 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_786 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_787 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_788 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_789 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c38, cp_0 = 0;c < c38 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_776);
									mem_vec_776 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_777);
									mem_vec_777 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_778);
									mem_vec_778 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_779);
									mem_vec_779 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_780);
									mem_vec_780 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_781);
									mem_vec_781 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_782);
									mem_vec_782 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_783);
									mem_vec_783 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_784);
									mem_vec_784 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_785);
									mem_vec_785 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_786);
									mem_vec_786 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_787);
									mem_vec_787 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_788);
									mem_vec_788 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_789);
									mem_vec_789 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_790);
									mem_vec_790 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_791);
									mem_vec_791 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_776);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_777);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_778);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_779);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_780);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_781);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_782);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_783);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_784);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_785);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_786);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_787);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_788);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_789);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_790);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_791);
					}
				}
				for (y = y57 + 8, yp_1 = y57_p_0, yp_0 = 0;y < y57 + 8 + 60;y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x57, xp_1 = x57_p_0, xp_0 = 0;x < x57 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								mem_vec_812 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
								mem_vec_813 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
								mem_vec_814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
								mem_vec_815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
								mem_vec_816 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
								mem_vec_817 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
								mem_vec_818 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
								mem_vec_819 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
								mem_vec_820 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
								mem_vec_821 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c38, cp_0 = 0;c < c38 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_792);
									mem_vec_792 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_793);
									mem_vec_793 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_794);
									mem_vec_794 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_795);
									mem_vec_795 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_796);
									mem_vec_796 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_797);
									mem_vec_797 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_798);
									mem_vec_798 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_799);
									mem_vec_799 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_800);
									mem_vec_800 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_801);
									mem_vec_801 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_802);
									mem_vec_802 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_803);
									mem_vec_803 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_804);
									mem_vec_804 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_805);
									mem_vec_805 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_806);
									mem_vec_806 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_807);
									mem_vec_807 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_808);
									mem_vec_808 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_809);
									mem_vec_809 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_810);
									mem_vec_810 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_811);
									mem_vec_811 = vec_31;
									scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);
									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_812);
									mem_vec_812 = vec_32;
									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_813);
									mem_vec_813 = vec_34;
									scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);
									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_814);
									mem_vec_814 = vec_35;
									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_815);
									mem_vec_815 = vec_37;
									scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);
									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_816);
									mem_vec_816 = vec_38;
									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_817);
									mem_vec_817 = vec_40;
									scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
									vec_42 = _mm512_set1_ps(scal_13);
									vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_818);
									mem_vec_818 = vec_41;
									vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_819);
									mem_vec_819 = vec_43;
									scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
									vec_45 = _mm512_set1_ps(scal_14);
									vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_820);
									mem_vec_820 = vec_44;
									vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_821);
									mem_vec_821 = vec_46;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_792);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_793);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_794);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_795);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_796);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_797);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_798);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_799);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_800);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_801);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_802);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_803);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_804);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_805);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_806);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_807);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_808);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_809);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_810);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_811);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_812);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_813);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_814);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_815);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_816);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_817);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_818);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_819);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_820);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_821);
					}
				}
		}
}
