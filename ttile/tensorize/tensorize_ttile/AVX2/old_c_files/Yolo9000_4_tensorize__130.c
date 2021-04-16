
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (8, f);
  T (1, x); T (2, y); T (34, x)]
*/
IND_TYPE c, cp_0, c426_p_0, cp_1, c426, f, fp_0, w, wp_0, x, xp_0, x568_p_0, x569_p_0, xp_1, x568_p_1, xp_2, x568, x569, y, yp_0, y399_p_0, yp_1, y399;
IND_TYPE y400 = 0;
IND_TYPE x570 = 0;
IND_TYPE h = 0;
IND_TYPE w275 = 0;
IND_TYPE c427 = 0;
IND_TYPE f311 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5160 ,mem_vec_5161 ,mem_vec_5162 ,mem_vec_5163 ,mem_vec_5164 ,mem_vec_5165 ,mem_vec_5166 ,mem_vec_5167 ,mem_vec_5168 ,mem_vec_5169 ,mem_vec_5170 ,mem_vec_5171 ,mem_vec_5172 ,mem_vec_5173 ,mem_vec_5174 ,mem_vec_5175 ,mem_vec_5176 ,mem_vec_5177 ,mem_vec_5178 ,mem_vec_5179 ,mem_vec_5180 ,mem_vec_5181 ,mem_vec_5182 ,mem_vec_5183 ,mem_vec_5184 ,mem_vec_5185 ,mem_vec_5186 ,mem_vec_5187 ,mem_vec_5188 ,mem_vec_5189 ,mem_vec_5190 ,mem_vec_5191 ,mem_vec_5192 ,mem_vec_5193 ,mem_vec_5194 ,mem_vec_5195 ,mem_vec_5196 ,mem_vec_5197 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
x569 = 0;
x569_p_0 = 0;
y399 = 0;
y399_p_0 = 0;
x568 = 0;
x568_p_1 = 0;
			for (f = f311, fp_0 = 0;f < f311 + 128;f += 16, fp_0 += 16){
					for (y = y399, yp_1 = y399_p_0, yp_0 = 0;y < y399 + 24;y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c426 = c427, c426_p_0 = 0;c426 < c427 + 64;c426 += 32, c426_p_0 += 32){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w275, wp_0 = 0;w < w275 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
								// T (x, 4) (4 / 1)
								for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;x < x568 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5160 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5161 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_5162 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5163 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_5164 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5165 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_5166 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5167 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_5168 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5169 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_5170 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5171 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_5172 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5173 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_5174 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5175 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c426, cp_1 = c426_p_0, cp_0 = 0;c < c426 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5160);
												mem_vec_5160 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5161);
												mem_vec_5161 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5162);
												mem_vec_5162 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5163);
												mem_vec_5163 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5164);
												mem_vec_5164 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5165);
												mem_vec_5165 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5166);
												mem_vec_5166 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5167);
												mem_vec_5167 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5168);
												mem_vec_5168 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5169);
												mem_vec_5169 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5170);
												mem_vec_5170 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5171);
												mem_vec_5171 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5172);
												mem_vec_5172 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5173);
												mem_vec_5173 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5174);
												mem_vec_5174 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5175);
												mem_vec_5175 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_5160);
												mem_vec_5160 = vec_26;
												vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_5161);
												mem_vec_5161 = vec_29;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_5162);
												mem_vec_5162 = vec_31;
												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_5163);
												mem_vec_5163 = vec_33;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_5164);
												mem_vec_5164 = vec_34;
												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_5165);
												mem_vec_5165 = vec_36;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_5166);
												mem_vec_5166 = vec_37;
												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_5167);
												mem_vec_5167 = vec_39;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_5168);
												mem_vec_5168 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_5169);
												mem_vec_5169 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_5170);
												mem_vec_5170 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_5171);
												mem_vec_5171 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_5172);
												mem_vec_5172 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_5173);
												mem_vec_5173 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_5174);
												mem_vec_5174 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_5175);
												mem_vec_5175 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_5160);
												mem_vec_5160 = vec_52;
												vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_5161);
												mem_vec_5161 = vec_55;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);
												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_5162);
												mem_vec_5162 = vec_57;
												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_5163);
												mem_vec_5163 = vec_59;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_5164);
												mem_vec_5164 = vec_60;
												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_5165);
												mem_vec_5165 = vec_62;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_5166);
												mem_vec_5166 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_5167);
												mem_vec_5167 = vec_65;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_5168);
												mem_vec_5168 = vec_66;
												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_5169);
												mem_vec_5169 = vec_68;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);
												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_5170);
												mem_vec_5170 = vec_69;
												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_5171);
												mem_vec_5171 = vec_71;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_5172);
												mem_vec_5172 = vec_72;
												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_5173);
												mem_vec_5173 = vec_74;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_5174);
												mem_vec_5174 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_5175);
												mem_vec_5175 = vec_77;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5160);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5161);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5162);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5163);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5164);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5165);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5166);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5167);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5168);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5169);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5170);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_5171);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5172);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_5173);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5174);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_5175);
								}
							}
						}
					}
					for (y = y399 + 24, yp_1 = y399_p_0, yp_0 = 0;y < y399 + 24 + 44;y += 11, yp_1 += 11, yp_0 += 11){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c426 = c427, c426_p_0 = 0;c426 < c427 + 64;c426 += 32, c426_p_0 += 32){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w275, wp_0 = 0;w < w275 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
								// T (x, 4) (4 / 1)
								for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;x < x568 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5176 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5177 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_5178 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5179 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_5180 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5181 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_5182 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5183 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_5184 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5185 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_5186 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5187 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_5188 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5189 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
											mem_vec_5190 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5191 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
											mem_vec_5192 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_5193 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8]);
											mem_vec_5194 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_5195 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8]);
											mem_vec_5196 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_5197 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c426, cp_1 = c426_p_0, cp_0 = 0;c < c426 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5176);
												mem_vec_5176 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5177);
												mem_vec_5177 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);
												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_5178);
												mem_vec_5178 = vec_5;
												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_5179);
												mem_vec_5179 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);
												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_5180);
												mem_vec_5180 = vec_8;
												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_5181);
												mem_vec_5181 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);
												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_5182);
												mem_vec_5182 = vec_11;
												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_5183);
												mem_vec_5183 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5184);
												mem_vec_5184 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5185);
												mem_vec_5185 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);
												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5186);
												mem_vec_5186 = vec_17;
												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5187);
												mem_vec_5187 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);
												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_5188);
												mem_vec_5188 = vec_20;
												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_5189);
												mem_vec_5189 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);
												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_5190);
												mem_vec_5190 = vec_23;
												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_5191);
												mem_vec_5191 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5192);
												mem_vec_5192 = vec_26;
												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5193);
												mem_vec_5193 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5194);
												mem_vec_5194 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5195);
												mem_vec_5195 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_5196);
												mem_vec_5196 = vec_32;
												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_5197);
												mem_vec_5197 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_5176);
												mem_vec_5176 = vec_35;
												vec_39 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_5177);
												mem_vec_5177 = vec_38;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_5178);
												mem_vec_5178 = vec_40;
												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_5179);
												mem_vec_5179 = vec_42;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_5180);
												mem_vec_5180 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_5181);
												mem_vec_5181 = vec_45;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);
												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_5182);
												mem_vec_5182 = vec_46;
												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_5183);
												mem_vec_5183 = vec_48;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);
												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_5184);
												mem_vec_5184 = vec_49;
												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_5185);
												mem_vec_5185 = vec_51;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_5186);
												mem_vec_5186 = vec_52;
												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_5187);
												mem_vec_5187 = vec_54;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);
												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_5188);
												mem_vec_5188 = vec_55;
												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_5189);
												mem_vec_5189 = vec_57;
												scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_5190);
												mem_vec_5190 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_5191);
												mem_vec_5191 = vec_60;
												scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);
												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_5192);
												mem_vec_5192 = vec_61;
												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_5193);
												mem_vec_5193 = vec_63;
												scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_5194);
												mem_vec_5194 = vec_64;
												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_5195);
												mem_vec_5195 = vec_66;
												scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);
												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_5196);
												mem_vec_5196 = vec_67;
												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_5197);
												mem_vec_5197 = vec_69;
												scal_22 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_5176);
												mem_vec_5176 = vec_70;
												vec_74 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_5177);
												mem_vec_5177 = vec_73;
												scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);
												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_5178);
												mem_vec_5178 = vec_75;
												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_5179);
												mem_vec_5179 = vec_77;
												scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_5180);
												mem_vec_5180 = vec_78;
												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_5181);
												mem_vec_5181 = vec_80;
												scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);
												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_5182);
												mem_vec_5182 = vec_81;
												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_5183);
												mem_vec_5183 = vec_83;
												scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_5184);
												mem_vec_5184 = vec_84;
												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_5185);
												mem_vec_5185 = vec_86;
												scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5186);
												mem_vec_5186 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5187);
												mem_vec_5187 = vec_89;
												scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);
												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_5188);
												mem_vec_5188 = vec_90;
												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_5189);
												mem_vec_5189 = vec_92;
												scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);
												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_5190);
												mem_vec_5190 = vec_93;
												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_5191);
												mem_vec_5191 = vec_95;
												scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);
												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_5192);
												mem_vec_5192 = vec_96;
												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_5193);
												mem_vec_5193 = vec_98;
												scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);
												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_5194);
												mem_vec_5194 = vec_99;
												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_5195);
												mem_vec_5195 = vec_101;
												scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);
												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_5196);
												mem_vec_5196 = vec_102;
												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_5197);
												mem_vec_5197 = vec_104;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5176);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_5177);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5178);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_5179);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5180);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_5181);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5182);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_5183);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5184);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_5185);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5186);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_5187);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5188);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_5189);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5190);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_5191);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5192);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 8], mem_vec_5193);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5194);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 8], mem_vec_5195);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_5196);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 8], mem_vec_5197);
								}
							}
						}
					}
			}
}
