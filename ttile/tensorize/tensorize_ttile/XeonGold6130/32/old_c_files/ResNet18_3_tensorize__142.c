
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (2, x); T (1, y); T (2, f); T (1, x); T (4, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c177_p_0, cp_1, c177, f, fp_0, x, xp_0, x295_p_0, x296_p_0, x297_p_0, xp_1, x295_p_1, x296_p_1, xp_2, x295_p_2, xp_3, x295, x296, x297, y, yp_0, y236_p_0, y237_p_0, yp_1, y236_p_1, yp_2, y236, y237;
IND_TYPE y238 = 0;
IND_TYPE x298 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c178 = 0;
IND_TYPE f118 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
y237 = 0;
y237_p_0 = 0;
x297 = 0;
x297_p_0 = 0;
y236 = 0;
y236_p_1 = 0;
x296 = 0;
x296_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x295 = 0;
x295_p_2 = 0;
c177 = 0;
c177_p_0 = 0;
								for (x = x295, xp_3 = x295_p_2, xp_2 = x295_p_1, xp_1 = x295_p_0, xp_0 = 0;x < x295 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1256 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1257 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1258 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1259 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1260 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1261 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1262 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1263 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1264 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1265 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1266 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1267 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1268 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1269 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_1270 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_1271 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_1272 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_1273 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_1274 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_1275 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_1276 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_1277 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_1278 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_1279 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_1280 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_1281 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											mem_vec_1282 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
											mem_vec_1283 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c177, cp_1 = c177_p_0, cp_0 = 0;c < c177 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1256);
												mem_vec_1256 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1257);
												mem_vec_1257 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1258);
												mem_vec_1258 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1259);
												mem_vec_1259 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1260);
												mem_vec_1260 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1261);
												mem_vec_1261 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1262);
												mem_vec_1262 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1263);
												mem_vec_1263 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1264);
												mem_vec_1264 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1265);
												mem_vec_1265 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1266);
												mem_vec_1266 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1267);
												mem_vec_1267 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1268);
												mem_vec_1268 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1269);
												mem_vec_1269 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1270);
												mem_vec_1270 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1271);
												mem_vec_1271 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1272);
												mem_vec_1272 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1273);
												mem_vec_1273 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1274);
												mem_vec_1274 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1275);
												mem_vec_1275 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1276);
												mem_vec_1276 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1277);
												mem_vec_1277 = vec_34;
												scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1278);
												mem_vec_1278 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1279);
												mem_vec_1279 = vec_37;
												scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1280);
												mem_vec_1280 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1281);
												mem_vec_1281 = vec_40;
												scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1282);
												mem_vec_1282 = vec_41;
												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1283);
												mem_vec_1283 = vec_43;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1256);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1257);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1258);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1259);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1260);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1261);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1262);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1263);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1264);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1265);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1266);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1267);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1268);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1269);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1270);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1271);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1272);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1273);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1274);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1275);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_1276);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_1277);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_1278);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_1279);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_1280);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_1281);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_1282);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_1283);
								}
}
