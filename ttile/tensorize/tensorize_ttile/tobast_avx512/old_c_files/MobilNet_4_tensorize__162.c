
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (4, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (16, c); T (2, x); T (14, y); T (2, c)]
*/
IND_TYPE c, cp_0, c210_p_0, c211_p_0, cp_1, c210_p_1, cp_2, c210, c211, h, hp_0, x, xp_0, x210_p_0, xp_1, x210, y, yp_0;
IND_TYPE y140 = 0;
IND_TYPE x211 = 0;
IND_TYPE h116 = 0;
IND_TYPE w = 0;
IND_TYPE c212 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (c, 2) (128 / 64)
c211 = 0;
c211_p_0 = 0;
y = 0;
yp_0 = 0;
x210 = 0;
x210_p_0 = 0;
c210 = 0;
c210_p_1 = 0;
				for (h = h116, hp_0 = 0;h < h116 + 3;h += 1, hp_0 += 1){
					// y = 2, x = 14, h = 1, w = 3, c = 4, f = 128
					// T (x, 14) (14 / 1)
					for (x = x210, xp_1 = x210_p_0, xp_0 = 0;x < x210 + 14;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 64]);
								mem_vec_941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 80]);
								mem_vec_942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 96]);
								mem_vec_943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 112]);
								mem_vec_944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64]);
								mem_vec_949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80]);
								mem_vec_950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96]);
								mem_vec_951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112]);
								// y = 2, x = 1, h = 1, w = 3, c = 4, f = 128
								// T (c, 4) (4 / 1)
								for (c = c210, cp_2 = c210_p_1, cp_1 = c210_p_0, cp_0 = 0;c < c210 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_936);
									mem_vec_936 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_937);
									mem_vec_937 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_938);
									mem_vec_938 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_939);
									mem_vec_939 = vec_7;
									vec_10 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 64]);
									vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_940);
									mem_vec_940 = vec_9;
									vec_12 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 80]);
									vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_941);
									mem_vec_941 = vec_11;
									vec_14 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 96]);
									vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_942);
									mem_vec_942 = vec_13;
									vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 112]);
									vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_943);
									mem_vec_943 = vec_15;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_18 = _mm512_set1_ps(scal_1);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_944);
									mem_vec_944 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_945);
									mem_vec_945 = vec_19;
									vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_946);
									mem_vec_946 = vec_20;
									vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_947);
									mem_vec_947 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_948);
									mem_vec_948 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_949);
									mem_vec_949 = vec_23;
									vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_950);
									mem_vec_950 = vec_24;
									vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_951);
									mem_vec_951 = vec_25;
									scal_2 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
									vec_27 = _mm512_set1_ps(scal_2);
									vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_936);
									mem_vec_936 = vec_26;
									vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
									vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_937);
									mem_vec_937 = vec_29;
									vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
									vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_938);
									mem_vec_938 = vec_31;
									vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
									vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_939);
									mem_vec_939 = vec_33;
									vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 64]);
									vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_940);
									mem_vec_940 = vec_35;
									vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 80]);
									vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_941);
									mem_vec_941 = vec_37;
									vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 96]);
									vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_942);
									mem_vec_942 = vec_39;
									vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 112]);
									vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_943);
									mem_vec_943 = vec_41;
									scal_3 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
									vec_44 = _mm512_set1_ps(scal_3);
									vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_944);
									mem_vec_944 = vec_43;
									vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_945);
									mem_vec_945 = vec_45;
									vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_946);
									mem_vec_946 = vec_46;
									vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_947);
									mem_vec_947 = vec_47;
									vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_948);
									mem_vec_948 = vec_48;
									vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_949);
									mem_vec_949 = vec_49;
									vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_950);
									mem_vec_950 = vec_50;
									vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_951);
									mem_vec_951 = vec_51;
									scal_4 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
									vec_53 = _mm512_set1_ps(scal_4);
									vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
									vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_936);
									mem_vec_936 = vec_52;
									vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
									vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_937);
									mem_vec_937 = vec_55;
									vec_58 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
									vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_938);
									mem_vec_938 = vec_57;
									vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
									vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_939);
									mem_vec_939 = vec_59;
									vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 64]);
									vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_940);
									mem_vec_940 = vec_61;
									vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 80]);
									vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_941);
									mem_vec_941 = vec_63;
									vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 96]);
									vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_942);
									mem_vec_942 = vec_65;
									vec_68 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 112]);
									vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_943);
									mem_vec_943 = vec_67;
									scal_5 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
									vec_70 = _mm512_set1_ps(scal_5);
									vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_944);
									mem_vec_944 = vec_69;
									vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_945);
									mem_vec_945 = vec_71;
									vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_946);
									mem_vec_946 = vec_72;
									vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_947);
									mem_vec_947 = vec_73;
									vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_948);
									mem_vec_948 = vec_74;
									vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_949);
									mem_vec_949 = vec_75;
									vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_950);
									mem_vec_950 = vec_76;
									vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_951);
									mem_vec_951 = vec_77;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_936);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_937);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_938);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_939);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 64], mem_vec_940);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 80], mem_vec_941);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 96], mem_vec_942);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 112], mem_vec_943);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_944);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_945);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_946);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_947);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64], mem_vec_948);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80], mem_vec_949);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96], mem_vec_950);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112], mem_vec_951);
					}
				}
}
