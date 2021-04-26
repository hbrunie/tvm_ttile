
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (1, x)]
*/
IND_TYPE c, cp_0, c201_p_0, cp_1, c201, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x218_p_0, x219_p_0, xp_1, x218_p_1, xp_2, x218, x219, y, yp_0;
IND_TYPE y134 = 0;
IND_TYPE x220 = 0;
IND_TYPE h89 = 0;
IND_TYPE w128 = 0;
IND_TYPE c202 = 0;
IND_TYPE f218 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,mem_vec_1372 ,mem_vec_1373 ,mem_vec_1374 ,mem_vec_1375 ,mem_vec_1376 ,mem_vec_1377 ,mem_vec_1378 ,mem_vec_1379 ,mem_vec_1380 ,mem_vec_1381 ,mem_vec_1382 ,mem_vec_1383 ,mem_vec_1384 ,mem_vec_1385 ,mem_vec_1386 ,mem_vec_1387 ,mem_vec_1388 ,mem_vec_1389 ,mem_vec_1390 ,mem_vec_1391 ,mem_vec_1392 ,mem_vec_1393 ,mem_vec_1394 ,mem_vec_1395 ,mem_vec_1396 ,mem_vec_1397 ,mem_vec_1398 ,mem_vec_1399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (56 / 56)
x219 = 0;
x219_p_0 = 0;
y = 0;
yp_0 = 0;
x218 = 0;
x218_p_1 = 0;
f = 0;
fp_0 = 0;
c201 = 0;
c201_p_0 = 0;
						for (w = w128, wp_0 = 0;w < w128 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x218, xp_2 = x218_p_1, xp_1 = x218_p_0, xp_0 = 0;x < x218 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h89, hp_0 = 0;h < h89 + 3;h += 1, hp_0 += 1){
											mem_vec_1348 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1349 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1350 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1351 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1352 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1353 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1354 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1355 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1356 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1357 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1358 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1359 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1360 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1361 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_1362 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_1363 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_1364 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_1365 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_1366 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_1367 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_1368 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_1369 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c201, cp_1 = c201_p_0, cp_0 = 0;c < c201 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1348);
												mem_vec_1348 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1349);
												mem_vec_1349 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1350);
												mem_vec_1350 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1351);
												mem_vec_1351 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1352);
												mem_vec_1352 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1353);
												mem_vec_1353 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1354);
												mem_vec_1354 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1355);
												mem_vec_1355 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1356);
												mem_vec_1356 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1357);
												mem_vec_1357 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1358);
												mem_vec_1358 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1359);
												mem_vec_1359 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1360);
												mem_vec_1360 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1361);
												mem_vec_1361 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1362);
												mem_vec_1362 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1363);
												mem_vec_1363 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1364);
												mem_vec_1364 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1365);
												mem_vec_1365 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1366);
												mem_vec_1366 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1367);
												mem_vec_1367 = vec_31;
												scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1368);
												mem_vec_1368 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1369);
												mem_vec_1369 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1348);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1349);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1350);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1351);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1352);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1353);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1354);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1355);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1356);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1357);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1358);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1359);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1360);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1361);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1362);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1363);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1364);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1365);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1366);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1367);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_1368);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_1369);
								}
							}
						}
}
