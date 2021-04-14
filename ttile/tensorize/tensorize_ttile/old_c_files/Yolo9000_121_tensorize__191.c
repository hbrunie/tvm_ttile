
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, f);
  T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c1166_p_0, cp_1, c1166, f, fp_0, f1248_p_0, f1249_p_0, fp_1, f1248_p_1, fp_2, f1248, f1249, h, hp_0, x, xp_0, x1166_p_0, xp_1, x1166, y, yp_0;
IND_TYPE y716 = 0;
IND_TYPE x1167 = 0;
IND_TYPE h556 = 0;
IND_TYPE w = 0;
IND_TYPE c1167 = 0;
IND_TYPE f1250 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13942 ,mem_vec_13943 ,mem_vec_13944 ,mem_vec_13945 ,mem_vec_13946 ,mem_vec_13947 ,mem_vec_13948 ,mem_vec_13949 ,mem_vec_13950 ,mem_vec_13951 ,mem_vec_13952 ,mem_vec_13953 ,mem_vec_13954 ,mem_vec_13955 ,mem_vec_13956 ,mem_vec_13957 ,mem_vec_13958 ,mem_vec_13959 ,mem_vec_13960 ,mem_vec_13961 ,mem_vec_13962 ,mem_vec_13963 ,mem_vec_13964 ,mem_vec_13965 ,mem_vec_13966 ,mem_vec_13967 ,mem_vec_13968 ,mem_vec_13969 ,mem_vec_13970 ,mem_vec_13971 ,mem_vec_13972 ,mem_vec_13973 ,mem_vec_13974 ,mem_vec_13975 ,mem_vec_13976 ,mem_vec_13977 ,mem_vec_13978 ,mem_vec_13979 ,mem_vec_13980 ,mem_vec_13981 ,mem_vec_13982 ,mem_vec_13983 ,mem_vec_13984 ,mem_vec_13985 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
f1249 = 0;
f1249_p_0 = 0;
c1166 = 0;
c1166_p_0 = 0;
f1248 = 0;
f1248_p_1 = 0;
y = 0;
yp_0 = 0;
x1166 = 0;
x1166_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h556, hp_0 = 0;h < h556 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1166, xp_1 = x1166_p_0, xp_0 = 0;x < x1166 + 34;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_13943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_13944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_13945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_13946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_13947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_13948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_13949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_13950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_13951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_13952 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_13953 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_13954 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_13955 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_13956 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_13957 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c1166, cp_1 = c1166_p_0, cp_0 = 0;c < c1166 + 128;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13942);
												mem_vec_13942 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13943);
												mem_vec_13943 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13944);
												mem_vec_13944 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13945);
												mem_vec_13945 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13946);
												mem_vec_13946 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13947);
												mem_vec_13947 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13948);
												mem_vec_13948 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13949);
												mem_vec_13949 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13950);
												mem_vec_13950 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13951);
												mem_vec_13951 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13952);
												mem_vec_13952 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13953);
												mem_vec_13953 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13954);
												mem_vec_13954 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13955);
												mem_vec_13955 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13956);
												mem_vec_13956 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13957);
												mem_vec_13957 = vec_23;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_13942);
												mem_vec_13942 = vec_24;
												vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_13943);
												mem_vec_13943 = vec_27;
												vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_13944);
												mem_vec_13944 = vec_29;
												vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_13945);
												mem_vec_13945 = vec_31;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_13946);
												mem_vec_13946 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_13947);
												mem_vec_13947 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_13948);
												mem_vec_13948 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_13949);
												mem_vec_13949 = vec_37;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_13950);
												mem_vec_13950 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_13951);
												mem_vec_13951 = vec_40;
												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_13952);
												mem_vec_13952 = vec_41;
												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_13953);
												mem_vec_13953 = vec_42;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_13954);
												mem_vec_13954 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_13955);
												mem_vec_13955 = vec_45;
												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_13956);
												mem_vec_13956 = vec_46;
												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_13957);
												mem_vec_13957 = vec_47;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_13942);
												mem_vec_13942 = vec_48;
												vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_13943);
												mem_vec_13943 = vec_51;
												vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_13944);
												mem_vec_13944 = vec_53;
												vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_13945);
												mem_vec_13945 = vec_55;
												scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_13946);
												mem_vec_13946 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_13947);
												mem_vec_13947 = vec_59;
												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_13948);
												mem_vec_13948 = vec_60;
												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_13949);
												mem_vec_13949 = vec_61;
												scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);
												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_13950);
												mem_vec_13950 = vec_62;
												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_13951);
												mem_vec_13951 = vec_64;
												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_13952);
												mem_vec_13952 = vec_65;
												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_13953);
												mem_vec_13953 = vec_66;
												scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);
												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_13954);
												mem_vec_13954 = vec_67;
												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_13955);
												mem_vec_13955 = vec_69;
												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_13956);
												mem_vec_13956 = vec_70;
												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_13957);
												mem_vec_13957 = vec_71;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13942);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13943);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13944);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13945);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13946);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13947);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13948);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13949);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13950);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13951);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13952);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13953);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13954);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13955);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13956);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13957);
								}
							}
}
