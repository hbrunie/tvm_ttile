
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (2, f); T (4, x); T (8, y);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c405_p_0, cp_1, c405, f, fp_0, h, hp_0, x, xp_0, x522_p_0, xp_1, x522, y, yp_0, y288_p_0, yp_1, y288;
IND_TYPE y289 = 0;
IND_TYPE x523 = 0;
IND_TYPE h182 = 0;
IND_TYPE w = 0;
IND_TYPE c406 = 0;
IND_TYPE f270 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6190 ,mem_vec_6191 ,mem_vec_6192 ,mem_vec_6193 ,mem_vec_6194 ,mem_vec_6195 ,mem_vec_6196 ,mem_vec_6197 ,mem_vec_6198 ,mem_vec_6199 ,mem_vec_6200 ,mem_vec_6201 ,mem_vec_6202 ,mem_vec_6203 ,mem_vec_6204 ,mem_vec_6205 ,mem_vec_6206 ,mem_vec_6207 ,mem_vec_6208 ,mem_vec_6209 ,mem_vec_6210 ,mem_vec_6211 ,mem_vec_6212 ,mem_vec_6213 ,mem_vec_6214 ,mem_vec_6215 ,mem_vec_6216 ,mem_vec_6217 ,mem_vec_6218 ,mem_vec_6219 ,mem_vec_6220 ,mem_vec_6221 ,mem_vec_6222 ,mem_vec_6223 ,mem_vec_6224 ,mem_vec_6225 ,mem_vec_6226 ,mem_vec_6227 ,mem_vec_6228 ,mem_vec_6229 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
y288 = 0;
y288_p_0 = 0;
y = 0;
yp_1 = 0;
x522 = 0;
x522_p_0 = 0;
f = 0;
fp_0 = 0;
c405 = 0;
c405_p_0 = 0;
						for (h = h182, hp_0 = 0;h < h182 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x522, xp_1 = x522_p_0, xp_0 = 0;x < x522 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6190 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6191 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6192 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_6193 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_6194 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6195 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6196 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_6197 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_6198 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6199 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6200 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_6201 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c405, cp_1 = c405_p_0, cp_0 = 0;c < c405 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6190);
											mem_vec_6190 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6191);
											mem_vec_6191 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6192);
											mem_vec_6192 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6193);
											mem_vec_6193 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6194);
											mem_vec_6194 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6195);
											mem_vec_6195 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6196);
											mem_vec_6196 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6197);
											mem_vec_6197 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6198);
											mem_vec_6198 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6199);
											mem_vec_6199 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6200);
											mem_vec_6200 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6201);
											mem_vec_6201 = vec_18;
											scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6190);
											mem_vec_6190 = vec_19;
											vec_23 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6191);
											mem_vec_6191 = vec_22;
											vec_25 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6192);
											mem_vec_6192 = vec_24;
											vec_27 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6193);
											mem_vec_6193 = vec_26;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6194);
											mem_vec_6194 = vec_28;
											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6195);
											mem_vec_6195 = vec_30;
											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6196);
											mem_vec_6196 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6197);
											mem_vec_6197 = vec_32;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6198);
											mem_vec_6198 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6199);
											mem_vec_6199 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6200);
											mem_vec_6200 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6201);
											mem_vec_6201 = vec_37;
											scal_6 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6190);
											mem_vec_6190 = vec_38;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6191);
											mem_vec_6191 = vec_41;
											vec_44 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6192);
											mem_vec_6192 = vec_43;
											vec_46 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6193);
											mem_vec_6193 = vec_45;
											scal_7 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_48 = _mm512_set1_ps(scal_7);
											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6194);
											mem_vec_6194 = vec_47;
											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6195);
											mem_vec_6195 = vec_49;
											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6196);
											mem_vec_6196 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6197);
											mem_vec_6197 = vec_51;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_53 = _mm512_set1_ps(scal_8);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6198);
											mem_vec_6198 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6199);
											mem_vec_6199 = vec_54;
											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6200);
											mem_vec_6200 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6201);
											mem_vec_6201 = vec_56;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6190);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6191);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6192);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6193);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6194);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6195);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6196);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6197);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6198);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6199);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6200);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6201);
							}
						}
}
