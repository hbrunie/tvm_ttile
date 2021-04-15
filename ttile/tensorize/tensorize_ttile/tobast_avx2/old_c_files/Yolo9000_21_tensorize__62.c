
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (16, y); T (1, f); T (4, c); T (4, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, f);
  T (68, x)]
*/
IND_TYPE c, cp_0, c768_p_0, cp_1, c768, f, fp_0, f640_p_0, fp_1, f640, w, wp_0, x, xp_0, x1024_p_0, x1025_p_0, xp_1, x1024_p_1, xp_2, x1024, x1025, y, yp_0, y768_p_0, yp_1, y768;
IND_TYPE y769 = 0;
IND_TYPE x1026 = 0;
IND_TYPE h = 0;
IND_TYPE w462 = 0;
IND_TYPE c769 = 0;
IND_TYPE f641 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7160 ,mem_vec_7161 ,mem_vec_7162 ,mem_vec_7163 ,mem_vec_7164 ,mem_vec_7165 ,mem_vec_7166 ,mem_vec_7167 ,mem_vec_7168 ,mem_vec_7169 ,mem_vec_7170 ,mem_vec_7171 ,mem_vec_7172 ,mem_vec_7173 ,mem_vec_7174 ,mem_vec_7175 ,mem_vec_7176 ,mem_vec_7177 ,mem_vec_7178 ,mem_vec_7179 ,mem_vec_7180 ,mem_vec_7181 ,mem_vec_7182 ,mem_vec_7183 ,mem_vec_7184 ,mem_vec_7185 ,mem_vec_7186 ,mem_vec_7187 ,mem_vec_7188 ,mem_vec_7189 ,mem_vec_7190 ,mem_vec_7191 ,mem_vec_7192 ,mem_vec_7193 ,mem_vec_7194 ,mem_vec_7195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 68) (272 / 4)
x1025 = 0;
x1025_p_0 = 0;
f640 = 0;
f640_p_0 = 0;
y768 = 0;
y768_p_0 = 0;
x1024 = 0;
x1024_p_1 = 0;
c768 = 0;
c768_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_1 = 0;
								for (w = w462, wp_0 = 0;w < w462 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1024, xp_2 = x1024_p_1, xp_1 = x1024_p_0, xp_0 = 0;x < x1024 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7160 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_7161 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_7162 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_7163 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_7164 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_7165 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_7166 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_7167 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_7168 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_7169 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_7170 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_7171 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_7172 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_7173 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_7174 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_7175 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c768, cp_1 = c768_p_0, cp_0 = 0;c < c768 + 8;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7160);
													mem_vec_7160 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7161);
													mem_vec_7161 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7162);
													mem_vec_7162 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7163);
													mem_vec_7163 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7164);
													mem_vec_7164 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7165);
													mem_vec_7165 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7166);
													mem_vec_7166 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7167);
													mem_vec_7167 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7168);
													mem_vec_7168 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7169);
													mem_vec_7169 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7170);
													mem_vec_7170 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7171);
													mem_vec_7171 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7172);
													mem_vec_7172 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7173);
													mem_vec_7173 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7174);
													mem_vec_7174 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7175);
													mem_vec_7175 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7160);
													mem_vec_7160 = vec_24;
													vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7161);
													mem_vec_7161 = vec_27;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7162);
													mem_vec_7162 = vec_29;
													vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7163);
													mem_vec_7163 = vec_31;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);
													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7164);
													mem_vec_7164 = vec_33;
													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7165);
													mem_vec_7165 = vec_35;
													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7166);
													mem_vec_7166 = vec_36;
													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7167);
													mem_vec_7167 = vec_37;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);
													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7168);
													mem_vec_7168 = vec_38;
													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7169);
													mem_vec_7169 = vec_40;
													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7170);
													mem_vec_7170 = vec_41;
													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7171);
													mem_vec_7171 = vec_42;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7172);
													mem_vec_7172 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7173);
													mem_vec_7173 = vec_45;
													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7174);
													mem_vec_7174 = vec_46;
													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7175);
													mem_vec_7175 = vec_47;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7160);
													mem_vec_7160 = vec_48;
													vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7161);
													mem_vec_7161 = vec_51;
													vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7162);
													mem_vec_7162 = vec_53;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7163);
													mem_vec_7163 = vec_55;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7164);
													mem_vec_7164 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7165);
													mem_vec_7165 = vec_59;
													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7166);
													mem_vec_7166 = vec_60;
													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7167);
													mem_vec_7167 = vec_61;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);
													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7168);
													mem_vec_7168 = vec_62;
													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7169);
													mem_vec_7169 = vec_64;
													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7170);
													mem_vec_7170 = vec_65;
													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7171);
													mem_vec_7171 = vec_66;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);
													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7172);
													mem_vec_7172 = vec_67;
													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7173);
													mem_vec_7173 = vec_69;
													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7174);
													mem_vec_7174 = vec_70;
													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7175);
													mem_vec_7175 = vec_71;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7160);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_7161);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7162);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_7163);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7164);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_7165);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7166);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_7167);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7168);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_7169);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7170);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_7171);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7172);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_7173);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7174);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_7175);
									}
								}
}
