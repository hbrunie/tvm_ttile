
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (4, c); T (2, f); T (4, x); T (8, y);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c396_p_0, cp_1, c396, f, fp_0, w, wp_0, x, xp_0, x513_p_0, xp_1, x513, y, yp_0, y279_p_0, yp_1, y279;
IND_TYPE y280 = 0;
IND_TYPE x514 = 0;
IND_TYPE h = 0;
IND_TYPE w187 = 0;
IND_TYPE c397 = 0;
IND_TYPE f264 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6058 ,mem_vec_6059 ,mem_vec_6060 ,mem_vec_6061 ,mem_vec_6062 ,mem_vec_6063 ,mem_vec_6064 ,mem_vec_6065 ,mem_vec_6066 ,mem_vec_6067 ,mem_vec_6068 ,mem_vec_6069 ,mem_vec_6070 ,mem_vec_6071 ,mem_vec_6072 ,mem_vec_6073 ,mem_vec_6074 ,mem_vec_6075 ,mem_vec_6076 ,mem_vec_6077 ,mem_vec_6078 ,mem_vec_6079 ,mem_vec_6080 ,mem_vec_6081 ,mem_vec_6082 ,mem_vec_6083 ,mem_vec_6084 ,mem_vec_6085 ,mem_vec_6086 ,mem_vec_6087 ,mem_vec_6088 ,mem_vec_6089 ,mem_vec_6090 ,mem_vec_6091 ,mem_vec_6092 ,mem_vec_6093 ,mem_vec_6094 ,mem_vec_6095 ,mem_vec_6096 ,mem_vec_6097 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
y279 = 0;
y279_p_0 = 0;
y = 0;
yp_1 = 0;
x513 = 0;
x513_p_0 = 0;
f = 0;
fp_0 = 0;
c396 = 0;
c396_p_0 = 0;
						for (w = w187, wp_0 = 0;w < w187 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x513, xp_1 = x513_p_0, xp_0 = 0;x < x513 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6058 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6059 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6060 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_6061 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_6062 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6063 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6064 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_6065 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_6066 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6067 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6068 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_6069 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c396, cp_1 = c396_p_0, cp_0 = 0;c < c396 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6058);
											mem_vec_6058 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6059);
											mem_vec_6059 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6060);
											mem_vec_6060 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6061);
											mem_vec_6061 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6062);
											mem_vec_6062 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6063);
											mem_vec_6063 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6064);
											mem_vec_6064 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6065);
											mem_vec_6065 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6066);
											mem_vec_6066 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6067);
											mem_vec_6067 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6068);
											mem_vec_6068 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6069);
											mem_vec_6069 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6058);
											mem_vec_6058 = vec_19;
											vec_23 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6059);
											mem_vec_6059 = vec_22;
											vec_25 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6060);
											mem_vec_6060 = vec_24;
											vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6061);
											mem_vec_6061 = vec_26;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6062);
											mem_vec_6062 = vec_28;
											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6063);
											mem_vec_6063 = vec_30;
											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6064);
											mem_vec_6064 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6065);
											mem_vec_6065 = vec_32;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6066);
											mem_vec_6066 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6067);
											mem_vec_6067 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6068);
											mem_vec_6068 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6069);
											mem_vec_6069 = vec_37;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6058);
											mem_vec_6058 = vec_38;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6059);
											mem_vec_6059 = vec_41;
											vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6060);
											mem_vec_6060 = vec_43;
											vec_46 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6061);
											mem_vec_6061 = vec_45;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_7);
											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6062);
											mem_vec_6062 = vec_47;
											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6063);
											mem_vec_6063 = vec_49;
											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6064);
											mem_vec_6064 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6065);
											mem_vec_6065 = vec_51;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_8);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6066);
											mem_vec_6066 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6067);
											mem_vec_6067 = vec_54;
											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6068);
											mem_vec_6068 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6069);
											mem_vec_6069 = vec_56;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6058);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6059);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6060);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6061);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6062);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6063);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6064);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6065);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6066);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6067);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6068);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6069);
							}
						}
}
