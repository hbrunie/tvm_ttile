
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (8, x); T (1, c);
  T (7, w); T (7, h); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 8), (Arg 13))]; T (2, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c129_p_0, cp_1, c129, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x124_p_0, xp_1, x124, y, yp_0, y129_p_0, yp_1, y129;
IND_TYPE y130 = 0;
IND_TYPE x125 = 0;
IND_TYPE h86 = 0;
IND_TYPE w86 = 0;
IND_TYPE c130 = 0;
IND_TYPE f81 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,mem_vec_1312 ,mem_vec_1313 ,mem_vec_1314 ,mem_vec_1315 ,mem_vec_1316 ,mem_vec_1317 ,mem_vec_1318 ,mem_vec_1319 ,mem_vec_1320 ,mem_vec_1321 ,mem_vec_1322 ,mem_vec_1323 ,mem_vec_1324 ,mem_vec_1325 ,mem_vec_1326 ,mem_vec_1327 ,mem_vec_1328 ,mem_vec_1329 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (y, 1) (112 / 112)
y129 = 0;
y129_p_0 = 0;
	for (f = f81, fp_0 = 0;f < f81 + 64;f += 32, fp_0 += 32){
			for (y = y129, yp_1 = y129_p_0, yp_0 = 0;y < y129 + 8;y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 112, h = 7, w = 7, c = 3, f = 32
				// T (x, 14) (112 / 8)
				for (x124 = x125, x124_p_0 = 0;x124 < x125 + 112;x124 += 8, x124_p_0 += 8){
					// y = ph_y, x = 8, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h86, hp_0 = 0;h < h86 + 7;h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w86, wp_0 = 0;w < w86 + 7;w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c129 = c130, c129_p_0 = 0;c129 < c130 + 3;c129 += 3, c129_p_0 += 3){
								// y = ph_y, x = 8, h = 1, w = 1, c = 3, f = 32
								// T (x, 8) (8 / 1)
								for (x = x124, xp_1 = x124_p_0, xp_0 = 0;x < x124 + 8;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1288 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1289 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1290 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1291 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_1302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_1303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c129, cp_1 = c129_p_0, cp_0 = 0;c < c129 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1288);
												mem_vec_1288 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1289);
												mem_vec_1289 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1290);
												mem_vec_1290 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1291);
												mem_vec_1291 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1292);
												mem_vec_1292 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1293);
												mem_vec_1293 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1294);
												mem_vec_1294 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1295);
												mem_vec_1295 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1296);
												mem_vec_1296 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1297);
												mem_vec_1297 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1298);
												mem_vec_1298 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1299);
												mem_vec_1299 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1300);
												mem_vec_1300 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1301);
												mem_vec_1301 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1302);
												mem_vec_1302 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1303);
												mem_vec_1303 = vec_25;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1288);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1289);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1290);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1291);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1292);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1293);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1294);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1295);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1296);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1297);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1298);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1299);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1300);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1301);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1302);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1303);
								}
							}
						}
					}
				}
			}
			for (y = y129 + 8, yp_1 = y129_p_0, yp_0 = 0;y < y129 + 8 + 104;y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 7, w = 7, c = 3, f = 32
				// T (x, 14) (112 / 8)
				for (x124 = x125, x124_p_0 = 0;x124 < x125 + 112;x124 += 8, x124_p_0 += 8){
					// y = ph_y, x = 8, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h86, hp_0 = 0;h < h86 + 7;h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w86, wp_0 = 0;w < w86 + 7;w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c129 = c130, c129_p_0 = 0;c129 < c130 + 3;c129 += 3, c129_p_0 += 3){
								// y = ph_y, x = 8, h = 1, w = 1, c = 3, f = 32
								// T (x, 8) (8 / 1)
								for (x = x124, xp_1 = x124_p_0, xp_0 = 0;x < x124 + 8;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1314 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1315 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1316 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1317 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_1318 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_1319 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_1320 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_1321 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_1322 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_1323 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_1324 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_1325 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_1326 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_1327 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_1328 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_1329 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c129, cp_1 = c129_p_0, cp_0 = 0;c < c129 + 3;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1304);
												mem_vec_1304 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1305);
												mem_vec_1305 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1306);
												mem_vec_1306 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1307);
												mem_vec_1307 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1308);
												mem_vec_1308 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1309);
												mem_vec_1309 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1310);
												mem_vec_1310 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1311);
												mem_vec_1311 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1312);
												mem_vec_1312 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1313);
												mem_vec_1313 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1314);
												mem_vec_1314 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1315);
												mem_vec_1315 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1316);
												mem_vec_1316 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1317);
												mem_vec_1317 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1318);
												mem_vec_1318 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1319);
												mem_vec_1319 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1320);
												mem_vec_1320 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1321);
												mem_vec_1321 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1322);
												mem_vec_1322 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1323);
												mem_vec_1323 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1324);
												mem_vec_1324 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1325);
												mem_vec_1325 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1326);
												mem_vec_1326 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1327);
												mem_vec_1327 = vec_37;
												scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1328);
												mem_vec_1328 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1329);
												mem_vec_1329 = vec_40;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1304);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1305);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1306);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1307);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1308);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1309);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1310);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1311);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1312);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1313);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1314);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1315);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1316);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1317);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1318);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1319);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1320);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1321);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1322);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1323);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_1324);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_1325);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_1326);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_1327);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_1328);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_1329);
								}
							}
						}
					}
				}
			}
	}
}
