
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (8, x);
  Lambda_apply y [((Iter 3), (Arg 7)); ((Iter 7), (Arg 13))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c718_p_0, cp_1, c718, h, hp_0, x, xp_0, x960_p_0, x961_p_0, xp_1, x960_p_1, xp_2, x960, x961, y, yp_0;
IND_TYPE y480 = 0;
IND_TYPE x962 = 0;
IND_TYPE h316 = 0;
IND_TYPE w = 0;
IND_TYPE c719 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6926 ,mem_vec_6927 ,mem_vec_6928 ,mem_vec_6929 ,mem_vec_6930 ,mem_vec_6931 ,mem_vec_6932 ,mem_vec_6933 ,mem_vec_6934 ,mem_vec_6935 ,mem_vec_6936 ,mem_vec_6937 ,mem_vec_6938 ,mem_vec_6939 ,mem_vec_6940 ,mem_vec_6941 ,mem_vec_6942 ,mem_vec_6943 ,mem_vec_6944 ,mem_vec_6945 ,mem_vec_6946 ,mem_vec_6947 ,mem_vec_6948 ,mem_vec_6949 ,mem_vec_6950 ,mem_vec_6951 ,mem_vec_6952 ,mem_vec_6953 ,mem_vec_6954 ,mem_vec_6955 ,mem_vec_6956 ,mem_vec_6957 ,mem_vec_6958 ,mem_vec_6959 ,mem_vec_6960 ,mem_vec_6961 ,mem_vec_6962 ,mem_vec_6963 ,mem_vec_6964 ,mem_vec_6965 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x961 = 0;
x961_p_0 = 0;
c718 = 0;
c718_p_0 = 0;
y = 0;
yp_0 = 0;
x960 = 0;
x960_p_1 = 0;
					for (h = h316, hp_0 = 0;h < h316 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
						// T (x, 2) (2 / 1)
						for (x = x960, xp_2 = x960_p_1, xp_1 = x960_p_0, xp_0 = 0;x < x960 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6926 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_6927 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_6928 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_6929 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_6930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_6931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_6932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_6933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_6934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_6935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_6936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_6937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_6938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_6939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c718, cp_1 = c718_p_0, cp_0 = 0;c < c718 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6926);
										mem_vec_6926 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6927);
										mem_vec_6927 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6928);
										mem_vec_6928 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6929);
										mem_vec_6929 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6930);
										mem_vec_6930 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6931);
										mem_vec_6931 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6932);
										mem_vec_6932 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6933);
										mem_vec_6933 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6934);
										mem_vec_6934 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6935);
										mem_vec_6935 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6936);
										mem_vec_6936 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6937);
										mem_vec_6937 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6938);
										mem_vec_6938 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6939);
										mem_vec_6939 = vec_22;
										scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_6926);
										mem_vec_6926 = vec_23;
										vec_27 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_6927);
										mem_vec_6927 = vec_26;
										scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6928);
										mem_vec_6928 = vec_28;
										vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6929);
										mem_vec_6929 = vec_30;
										scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);
										vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_6930);
										mem_vec_6930 = vec_31;
										vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_6931);
										mem_vec_6931 = vec_33;
										scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_6932);
										mem_vec_6932 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6933);
										mem_vec_6933 = vec_36;
										scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_6934);
										mem_vec_6934 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_6935);
										mem_vec_6935 = vec_39;
										scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_6936);
										mem_vec_6936 = vec_40;
										vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6937);
										mem_vec_6937 = vec_42;
										scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);
										vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_6938);
										mem_vec_6938 = vec_43;
										vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_6939);
										mem_vec_6939 = vec_45;
										scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);
										vec_48 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_6926);
										mem_vec_6926 = vec_46;
										vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_6927);
										mem_vec_6927 = vec_49;
										scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_52 = _mm512_set1_ps(scal_15);
										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_6928);
										mem_vec_6928 = vec_51;
										vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_6929);
										mem_vec_6929 = vec_53;
										scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_55 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_6930);
										mem_vec_6930 = vec_54;
										vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_6931);
										mem_vec_6931 = vec_56;
										scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_6932);
										mem_vec_6932 = vec_57;
										vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_6933);
										mem_vec_6933 = vec_59;
										scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);
										vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_6934);
										mem_vec_6934 = vec_60;
										vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_6935);
										mem_vec_6935 = vec_62;
										scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);
										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_6936);
										mem_vec_6936 = vec_63;
										vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_6937);
										mem_vec_6937 = vec_65;
										scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);
										vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_6938);
										mem_vec_6938 = vec_66;
										vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_6939);
										mem_vec_6939 = vec_68;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6926);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6927);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6928);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6929);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6930);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6931);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6932);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6933);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6934);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6935);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6936);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6937);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6938);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6939);
						}
					}
}
