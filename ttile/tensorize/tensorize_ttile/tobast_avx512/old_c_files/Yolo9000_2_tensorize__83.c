
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (68, x); T (68, y); T (4, c); T (1, x); T (2, x)]
*/
IND_TYPE c, cp_0, c282_p_0, cp_1, c282, w, wp_0, x, xp_0, x470_p_0, x471_p_0, x472_p_0, xp_1, x470_p_1, x471_p_1, xp_2, x470_p_2, xp_3, x470, x471, x472, y, yp_0;
IND_TYPE y188 = 0;
IND_TYPE x473 = 0;
IND_TYPE h = 0;
IND_TYPE w188 = 0;
IND_TYPE c283 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1168 ,mem_vec_1169 ,mem_vec_1170 ,mem_vec_1171 ,mem_vec_1172 ,mem_vec_1173 ,mem_vec_1174 ,mem_vec_1175 ,mem_vec_1176 ,mem_vec_1177 ,mem_vec_1178 ,mem_vec_1179 ,mem_vec_1180 ,mem_vec_1181 ,mem_vec_1182 ,mem_vec_1183 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
x472 = 0;
x472_p_0 = 0;
x471 = 0;
x471_p_1 = 0;
c282 = 0;
c282_p_0 = 0;
y = 0;
yp_0 = 0;
x470 = 0;
x470_p_2 = 0;
					for (w = w188, wp_0 = 0;w < w188 + 3;w += 1, wp_0 += 1){
						// y = 4, x = 2, h = 3, w = 1, c = 8, f = 64
						// T (x, 2) (2 / 1)
						for (x = x470, xp_3 = x470_p_2, xp_2 = x470_p_1, xp_1 = x470_p_0, xp_0 = 0;x < x470 + 2;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1168 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1169 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1170 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_1171 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_1172 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1173 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1174 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_1175 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_1176 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1177 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1178 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_1179 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_1180 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1181 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1182 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_1183 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 3, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c282, cp_1 = c282_p_0, cp_0 = 0;c < c282 + 8;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1168);
										mem_vec_1168 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1169);
										mem_vec_1169 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1170);
										mem_vec_1170 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1171);
										mem_vec_1171 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1172);
										mem_vec_1172 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1173);
										mem_vec_1173 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1174);
										mem_vec_1174 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1175);
										mem_vec_1175 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1176);
										mem_vec_1176 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1177);
										mem_vec_1177 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1178);
										mem_vec_1178 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1179);
										mem_vec_1179 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1180);
										mem_vec_1180 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1181);
										mem_vec_1181 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1182);
										mem_vec_1182 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1183);
										mem_vec_1183 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_1168);
										mem_vec_1168 = vec_24;
										vec_28 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_1169);
										mem_vec_1169 = vec_27;
										vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_1170);
										mem_vec_1170 = vec_29;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_1171);
										mem_vec_1171 = vec_31;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);
										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_1172);
										mem_vec_1172 = vec_33;
										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_1173);
										mem_vec_1173 = vec_35;
										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_1174);
										mem_vec_1174 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1175);
										mem_vec_1175 = vec_37;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_1176);
										mem_vec_1176 = vec_38;
										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_1177);
										mem_vec_1177 = vec_40;
										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_1178);
										mem_vec_1178 = vec_41;
										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_1179);
										mem_vec_1179 = vec_42;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);
										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_1180);
										mem_vec_1180 = vec_43;
										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1181);
										mem_vec_1181 = vec_45;
										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1182);
										mem_vec_1182 = vec_46;
										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1183);
										mem_vec_1183 = vec_47;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_1168);
										mem_vec_1168 = vec_48;
										vec_52 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_1169);
										mem_vec_1169 = vec_51;
										vec_54 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_1170);
										mem_vec_1170 = vec_53;
										vec_56 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_1171);
										mem_vec_1171 = vec_55;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_9);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_1172);
										mem_vec_1172 = vec_57;
										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_1173);
										mem_vec_1173 = vec_59;
										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_1174);
										mem_vec_1174 = vec_60;
										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_1175);
										mem_vec_1175 = vec_61;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
										vec_63 = _mm512_set1_ps(scal_10);
										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_1176);
										mem_vec_1176 = vec_62;
										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_1177);
										mem_vec_1177 = vec_64;
										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_1178);
										mem_vec_1178 = vec_65;
										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_1179);
										mem_vec_1179 = vec_66;
										scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);
										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_1180);
										mem_vec_1180 = vec_67;
										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_1181);
										mem_vec_1181 = vec_69;
										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_1182);
										mem_vec_1182 = vec_70;
										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_1183);
										mem_vec_1183 = vec_71;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1168);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1169);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1170);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1171);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1172);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1173);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1174);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1175);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1176);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1177);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1178);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1179);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1180);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1181);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1182);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1183);
						}
					}
}
