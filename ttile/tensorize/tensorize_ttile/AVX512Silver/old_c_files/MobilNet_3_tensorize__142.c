
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (128, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (1, c); T (1, x); T (1, y); T (28, y)]
*/
IND_TYPE c, cp_0, c114_p_0, cp_1, c114, h, hp_0, x, xp_0, x129_p_0, xp_1, x129, y, yp_0, y97_p_0, yp_1, y97;
IND_TYPE y98 = 0;
IND_TYPE x130 = 0;
IND_TYPE h59 = 0;
IND_TYPE w = 0;
IND_TYPE c115 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 28) (56 / 2)
y97 = 0;
y97_p_0 = 0;
y = 0;
yp_1 = 0;
x129 = 0;
x129_p_0 = 0;
c114 = 0;
c114_p_0 = 0;
				for (h = h59, hp_0 = 0;h < h59 + 3;h += 1, hp_0 += 1){
					// y = 2, x = 56, h = 1, w = 3, c = 128, f = 128
					// T (x, 56) (56 / 1)
					for (x = x129, xp_1 = x129_p_0, xp_0 = 0;x < x129 + 56;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 64]);
								mem_vec_797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 80]);
								mem_vec_798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 96]);
								mem_vec_799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 112]);
								mem_vec_800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64]);
								mem_vec_805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80]);
								mem_vec_806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96]);
								mem_vec_807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112]);
								// y = 2, x = 1, h = 1, w = 3, c = 128, f = 128
								// T (c, 128) (128 / 1)
								for (c = c114, cp_1 = c114_p_0, cp_0 = 0;c < c114 + 128;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_792);
									mem_vec_792 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_793);
									mem_vec_793 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_794);
									mem_vec_794 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_795);
									mem_vec_795 = vec_7;
									vec_10 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 64]);
									vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_796);
									mem_vec_796 = vec_9;
									vec_12 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 80]);
									vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_797);
									mem_vec_797 = vec_11;
									vec_14 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 96]);
									vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_798);
									mem_vec_798 = vec_13;
									vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 112]);
									vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_799);
									mem_vec_799 = vec_15;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_18 = _mm512_set1_ps(scal_1);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_800);
									mem_vec_800 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_801);
									mem_vec_801 = vec_19;
									vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_802);
									mem_vec_802 = vec_20;
									vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_803);
									mem_vec_803 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_804);
									mem_vec_804 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_805);
									mem_vec_805 = vec_23;
									vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_806);
									mem_vec_806 = vec_24;
									vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_807);
									mem_vec_807 = vec_25;
									scal_2 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
									vec_27 = _mm512_set1_ps(scal_2);
									vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_792);
									mem_vec_792 = vec_26;
									vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
									vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_793);
									mem_vec_793 = vec_29;
									vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
									vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_794);
									mem_vec_794 = vec_31;
									vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
									vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_795);
									mem_vec_795 = vec_33;
									vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 64]);
									vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_796);
									mem_vec_796 = vec_35;
									vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 80]);
									vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_797);
									mem_vec_797 = vec_37;
									vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 96]);
									vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_798);
									mem_vec_798 = vec_39;
									vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 112]);
									vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_799);
									mem_vec_799 = vec_41;
									scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
									vec_44 = _mm512_set1_ps(scal_3);
									vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_800);
									mem_vec_800 = vec_43;
									vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_801);
									mem_vec_801 = vec_45;
									vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_802);
									mem_vec_802 = vec_46;
									vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_803);
									mem_vec_803 = vec_47;
									vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_804);
									mem_vec_804 = vec_48;
									vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_805);
									mem_vec_805 = vec_49;
									vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_806);
									mem_vec_806 = vec_50;
									vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_807);
									mem_vec_807 = vec_51;
									scal_4 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
									vec_53 = _mm512_set1_ps(scal_4);
									vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
									vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_792);
									mem_vec_792 = vec_52;
									vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
									vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_793);
									mem_vec_793 = vec_55;
									vec_58 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
									vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_794);
									mem_vec_794 = vec_57;
									vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
									vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_795);
									mem_vec_795 = vec_59;
									vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 64]);
									vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_796);
									mem_vec_796 = vec_61;
									vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 80]);
									vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_797);
									mem_vec_797 = vec_63;
									vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 96]);
									vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_798);
									mem_vec_798 = vec_65;
									vec_68 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 112]);
									vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_799);
									mem_vec_799 = vec_67;
									scal_5 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
									vec_70 = _mm512_set1_ps(scal_5);
									vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_800);
									mem_vec_800 = vec_69;
									vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_801);
									mem_vec_801 = vec_71;
									vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_802);
									mem_vec_802 = vec_72;
									vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_803);
									mem_vec_803 = vec_73;
									vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_804);
									mem_vec_804 = vec_74;
									vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_805);
									mem_vec_805 = vec_75;
									vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_806);
									mem_vec_806 = vec_76;
									vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_807);
									mem_vec_807 = vec_77;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_792);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_793);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_794);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_795);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 64], mem_vec_796);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 80], mem_vec_797);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 96], mem_vec_798);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 112], mem_vec_799);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_800);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_801);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_802);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_803);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64], mem_vec_804);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80], mem_vec_805);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96], mem_vec_806);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112], mem_vec_807);
					}
				}
}
