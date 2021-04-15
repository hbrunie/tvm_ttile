
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (8, c);
  T (32, f); T (2, x); T (4, c)]
*/
IND_TYPE c, cp_0, c170_p_0, c171_p_0, c172_p_0, cp_1, c170_p_1, c171_p_1, cp_2, c170_p_2, cp_3, c170, c171, c172, f, fp_0, w, wp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0;
IND_TYPE y68 = 0;
IND_TYPE x138 = 0;
IND_TYPE h = 0;
IND_TYPE w68 = 0;
IND_TYPE c173 = 0;
IND_TYPE f68 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,mem_vec_1244 ,mem_vec_1245 ,mem_vec_1246 ,mem_vec_1247 ,mem_vec_1248 ,mem_vec_1249 ,mem_vec_1250 ,mem_vec_1251 ,mem_vec_1252 ,mem_vec_1253 ,mem_vec_1254 ,mem_vec_1255 ,mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 4) (256 / 64)
c172 = 0;
c172_p_0 = 0;
x137 = 0;
x137_p_0 = 0;
f = 0;
fp_0 = 0;
c171 = 0;
c171_p_1 = 0;
y = 0;
yp_0 = 0;
x136 = 0;
x136_p_1 = 0;
c170 = 0;
c170_p_2 = 0;
								for (w = w68, wp_0 = 0;w < w68 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 8, f = 16
									// T (x, 17) (17 / 1)
									for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;x < x136 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1224 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_1225 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_1226 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_1227 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_1228 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_1229 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_1230 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_1231 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_1232 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_1233 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_1234 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_1235 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
												mem_vec_1236 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_1237 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8]);
												mem_vec_1238 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_1239 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
												// T (c, 8) (8 / 1)
												for (c = c170, cp_3 = c170_p_2, cp_2 = c170_p_1, cp_1 = c170_p_0, cp_0 = 0;c < c170 + 8;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1224);
													mem_vec_1224 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1225);
													mem_vec_1225 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);
													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1226);
													mem_vec_1226 = vec_5;
													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1227);
													mem_vec_1227 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);
													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1228);
													mem_vec_1228 = vec_8;
													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1229);
													mem_vec_1229 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);
													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1230);
													mem_vec_1230 = vec_11;
													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1231);
													mem_vec_1231 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1232);
													mem_vec_1232 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1233);
													mem_vec_1233 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);
													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1234);
													mem_vec_1234 = vec_17;
													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1235);
													mem_vec_1235 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);
													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1236);
													mem_vec_1236 = vec_20;
													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1237);
													mem_vec_1237 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);
													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1238);
													mem_vec_1238 = vec_23;
													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1239);
													mem_vec_1239 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_1224);
													mem_vec_1224 = vec_26;
													vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_1225);
													mem_vec_1225 = vec_29;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);
													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_1226);
													mem_vec_1226 = vec_31;
													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_1227);
													mem_vec_1227 = vec_33;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_1228);
													mem_vec_1228 = vec_34;
													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_1229);
													mem_vec_1229 = vec_36;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);
													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_1230);
													mem_vec_1230 = vec_37;
													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_1231);
													mem_vec_1231 = vec_39;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);
													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_1232);
													mem_vec_1232 = vec_40;
													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_1233);
													mem_vec_1233 = vec_42;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);
													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1234);
													mem_vec_1234 = vec_43;
													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1235);
													mem_vec_1235 = vec_45;
													scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);
													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_1236);
													mem_vec_1236 = vec_46;
													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_1237);
													mem_vec_1237 = vec_48;
													scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);
													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_1238);
													mem_vec_1238 = vec_49;
													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_1239);
													mem_vec_1239 = vec_51;
													scal_16 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_1224);
													mem_vec_1224 = vec_52;
													vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_1225);
													mem_vec_1225 = vec_55;
													scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);
													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1226);
													mem_vec_1226 = vec_57;
													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1227);
													mem_vec_1227 = vec_59;
													scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);
													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_1228);
													mem_vec_1228 = vec_60;
													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_1229);
													mem_vec_1229 = vec_62;
													scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);
													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_1230);
													mem_vec_1230 = vec_63;
													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_1231);
													mem_vec_1231 = vec_65;
													scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_1232);
													mem_vec_1232 = vec_66;
													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_1233);
													mem_vec_1233 = vec_68;
													scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);
													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_1234);
													mem_vec_1234 = vec_69;
													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_1235);
													mem_vec_1235 = vec_71;
													scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);
													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_1236);
													mem_vec_1236 = vec_72;
													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_1237);
													mem_vec_1237 = vec_74;
													scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);
													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_1238);
													mem_vec_1238 = vec_75;
													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_1239);
													mem_vec_1239 = vec_77;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1224);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1225);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1226);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1227);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1228);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1229);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1230);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1231);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1232);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1233);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1234);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_1235);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1236);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 8], mem_vec_1237);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1238);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 8], mem_vec_1239);
									}
								}
}
