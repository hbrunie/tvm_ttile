
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (2, f); T (4, x); T (34, y)]
*/
IND_TYPE c, cp_0, c246_p_0, cp_1, c246, f, fp_0, h, hp_0, x, xp_0, x273_p_0, xp_1, x273, y, yp_0;
IND_TYPE y191 = 0;
IND_TYPE x274 = 0;
IND_TYPE h137 = 0;
IND_TYPE w = 0;
IND_TYPE c247 = 0;
IND_TYPE f164 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3125 ,mem_vec_3126 ,mem_vec_3127 ,mem_vec_3128 ,mem_vec_3129 ,mem_vec_3130 ,mem_vec_3131 ,mem_vec_3132 ,mem_vec_3133 ,mem_vec_3134 ,mem_vec_3135 ,mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (y, 34) (136 / 4)
y = 0;
yp_0 = 0;
x273 = 0;
x273_p_0 = 0;
f = 0;
fp_0 = 0;
c246 = 0;
c246_p_0 = 0;
				for (h = h137, hp_0 = 0;h < h137 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 34, h = 1, w = 3, c = 64, f = 64
					// T (x, 34) (34 / 1)
					for (x = x273, xp_1 = x273_p_0, xp_0 = 0;x < x273 + 34;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3125 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_3126 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_3127 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_3128 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_3129 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_3130 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_3131 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_3132 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_3133 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_3134 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_3135 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_3136 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_3137 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_3138 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_3139 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_3140 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c246, cp_1 = c246_p_0, cp_0 = 0;c < c246 + 64;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3125);
									mem_vec_3125 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3126);
									mem_vec_3126 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3127);
									mem_vec_3127 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3128);
									mem_vec_3128 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3129);
									mem_vec_3129 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3130);
									mem_vec_3130 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3131);
									mem_vec_3131 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3132);
									mem_vec_3132 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3133);
									mem_vec_3133 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3134);
									mem_vec_3134 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3135);
									mem_vec_3135 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3136);
									mem_vec_3136 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3137);
									mem_vec_3137 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3138);
									mem_vec_3138 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3139);
									mem_vec_3139 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3140);
									mem_vec_3140 = vec_23;
									scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);
									vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
									vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_3125);
									mem_vec_3125 = vec_24;
									vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
									vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_3126);
									mem_vec_3126 = vec_27;
									vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
									vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_3127);
									mem_vec_3127 = vec_29;
									vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
									vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_3128);
									mem_vec_3128 = vec_31;
									scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
									vec_34 = _mm512_set1_ps(scal_5);
									vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_3129);
									mem_vec_3129 = vec_33;
									vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_3130);
									mem_vec_3130 = vec_35;
									vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_3131);
									mem_vec_3131 = vec_36;
									vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3132);
									mem_vec_3132 = vec_37;
									scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
									vec_39 = _mm512_set1_ps(scal_6);
									vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_3133);
									mem_vec_3133 = vec_38;
									vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_3134);
									mem_vec_3134 = vec_40;
									vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_3135);
									mem_vec_3135 = vec_41;
									vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_3136);
									mem_vec_3136 = vec_42;
									scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
									vec_44 = _mm512_set1_ps(scal_7);
									vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_3137);
									mem_vec_3137 = vec_43;
									vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_3138);
									mem_vec_3138 = vec_45;
									vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_3139);
									mem_vec_3139 = vec_46;
									vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_3140);
									mem_vec_3140 = vec_47;
									scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
									vec_49 = _mm512_set1_ps(scal_8);
									vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
									vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_3125);
									mem_vec_3125 = vec_48;
									vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
									vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_3126);
									mem_vec_3126 = vec_51;
									vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
									vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_3127);
									mem_vec_3127 = vec_53;
									vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
									vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_3128);
									mem_vec_3128 = vec_55;
									scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
									vec_58 = _mm512_set1_ps(scal_9);
									vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_3129);
									mem_vec_3129 = vec_57;
									vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_3130);
									mem_vec_3130 = vec_59;
									vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_3131);
									mem_vec_3131 = vec_60;
									vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3132);
									mem_vec_3132 = vec_61;
									scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
									vec_63 = _mm512_set1_ps(scal_10);
									vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_3133);
									mem_vec_3133 = vec_62;
									vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_3134);
									mem_vec_3134 = vec_64;
									vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_3135);
									mem_vec_3135 = vec_65;
									vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_3136);
									mem_vec_3136 = vec_66;
									scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
									vec_68 = _mm512_set1_ps(scal_11);
									vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_3137);
									mem_vec_3137 = vec_67;
									vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_3138);
									mem_vec_3138 = vec_69;
									vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_3139);
									mem_vec_3139 = vec_70;
									vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_3140);
									mem_vec_3140 = vec_71;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3125);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3126);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3127);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3128);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3129);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3130);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3131);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3132);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3133);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3134);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3135);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3136);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3137);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3138);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_3139);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_3140);
					}
				}
}
