
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (28, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, f110_p_0, f111_p_0, fp_1, f110_p_1, fp_2, f110, f111, w, wp_0, x, xp_0, x87_p_0, xp_1, x87, y, yp_0;
IND_TYPE y61 = 0;
IND_TYPE x88 = 0;
IND_TYPE h = 0;
IND_TYPE w58 = 0;
IND_TYPE c88 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,mem_vec_1284 ,mem_vec_1285 ,mem_vec_1286 ,mem_vec_1287 ,mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
f111 = 0;
f111_p_0 = 0;
f110 = 0;
f110_p_1 = 0;
x87 = 0;
x87_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c87 = 0;
c87_p_0 = 0;
							for (w = w58, wp_0 = 0;w < w58 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x87, xp_1 = x87_p_0, xp_0 = 0;x < x87 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1256 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1257 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
											mem_vec_1258 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1259 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
											mem_vec_1260 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1261 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
											mem_vec_1262 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1263 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
											mem_vec_1264 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1265 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
											mem_vec_1266 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1267 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
											mem_vec_1268 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1269 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
											mem_vec_1270 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1271 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
											mem_vec_1272 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1273 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
											mem_vec_1274 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1275 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
											mem_vec_1276 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1277 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8]);
											mem_vec_1278 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1279 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c87, cp_1 = c87_p_0, cp_0 = 0;c < c87 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1256);
												mem_vec_1256 = vec_0;
												vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1257);
												mem_vec_1257 = vec_3;
												vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1258);
												mem_vec_1258 = vec_5;
												vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1259);
												mem_vec_1259 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);
												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1260);
												mem_vec_1260 = vec_9;
												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1261);
												mem_vec_1261 = vec_11;
												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1262);
												mem_vec_1262 = vec_12;
												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1263);
												mem_vec_1263 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);
												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1264);
												mem_vec_1264 = vec_14;
												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1265);
												mem_vec_1265 = vec_16;
												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1266);
												mem_vec_1266 = vec_17;
												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1267);
												mem_vec_1267 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1268);
												mem_vec_1268 = vec_19;
												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1269);
												mem_vec_1269 = vec_21;
												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1270);
												mem_vec_1270 = vec_22;
												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1271);
												mem_vec_1271 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1272);
												mem_vec_1272 = vec_24;
												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1273);
												mem_vec_1273 = vec_26;
												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1274);
												mem_vec_1274 = vec_27;
												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1275);
												mem_vec_1275 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1276);
												mem_vec_1276 = vec_29;
												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1277);
												mem_vec_1277 = vec_31;
												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1278);
												mem_vec_1278 = vec_32;
												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1279);
												mem_vec_1279 = vec_33;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1256);
												mem_vec_1256 = vec_34;
												vec_38 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1257);
												mem_vec_1257 = vec_37;
												vec_40 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1258);
												mem_vec_1258 = vec_39;
												vec_42 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1259);
												mem_vec_1259 = vec_41;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);
												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1260);
												mem_vec_1260 = vec_43;
												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1261);
												mem_vec_1261 = vec_45;
												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1262);
												mem_vec_1262 = vec_46;
												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1263);
												mem_vec_1263 = vec_47;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1264);
												mem_vec_1264 = vec_48;
												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1265);
												mem_vec_1265 = vec_50;
												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1266);
												mem_vec_1266 = vec_51;
												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1267);
												mem_vec_1267 = vec_52;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);
												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1268);
												mem_vec_1268 = vec_53;
												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1269);
												mem_vec_1269 = vec_55;
												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1270);
												mem_vec_1270 = vec_56;
												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1271);
												mem_vec_1271 = vec_57;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1272);
												mem_vec_1272 = vec_58;
												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1273);
												mem_vec_1273 = vec_60;
												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1274);
												mem_vec_1274 = vec_61;
												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1275);
												mem_vec_1275 = vec_62;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);
												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1276);
												mem_vec_1276 = vec_63;
												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1277);
												mem_vec_1277 = vec_65;
												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1278);
												mem_vec_1278 = vec_66;
												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1279);
												mem_vec_1279 = vec_67;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1256);
												mem_vec_1256 = vec_68;
												vec_72 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1257);
												mem_vec_1257 = vec_71;
												vec_74 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1258);
												mem_vec_1258 = vec_73;
												vec_76 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1259);
												mem_vec_1259 = vec_75;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);
												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1260);
												mem_vec_1260 = vec_77;
												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1261);
												mem_vec_1261 = vec_79;
												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1262);
												mem_vec_1262 = vec_80;
												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1263);
												mem_vec_1263 = vec_81;
												scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);
												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1264);
												mem_vec_1264 = vec_82;
												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1265);
												mem_vec_1265 = vec_84;
												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1266);
												mem_vec_1266 = vec_85;
												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1267);
												mem_vec_1267 = vec_86;
												scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);
												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1268);
												mem_vec_1268 = vec_87;
												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1269);
												mem_vec_1269 = vec_89;
												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1270);
												mem_vec_1270 = vec_90;
												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1271);
												mem_vec_1271 = vec_91;
												scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);
												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1272);
												mem_vec_1272 = vec_92;
												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1273);
												mem_vec_1273 = vec_94;
												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1274);
												mem_vec_1274 = vec_95;
												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1275);
												mem_vec_1275 = vec_96;
												scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);
												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1276);
												mem_vec_1276 = vec_97;
												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1277);
												mem_vec_1277 = vec_99;
												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1278);
												mem_vec_1278 = vec_100;
												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1279);
												mem_vec_1279 = vec_101;
											}
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1256);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1257);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1258);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1259);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1260);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1261);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1262);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1263);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1264);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1265);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1266);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1267);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1268);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1269);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1270);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1271);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1272);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1273);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1274);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1275);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1276);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 8], mem_vec_1277);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1278);
										_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 24], mem_vec_1279);
								}
							}
}
