
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))];
  T (4, f); T (8, c); T (2, f); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c204_p_0, cp_1, c204, f, fp_0, f272_p_0, f273_p_0, fp_1, f272_p_1, fp_2, f272, f273, h, hp_0, w, wp_0, x, xp_0, x256_p_0, xp_1, x256, y, yp_0;
IND_TYPE y136 = 0;
IND_TYPE x257 = 0;
IND_TYPE h136 = 0;
IND_TYPE w84 = 0;
IND_TYPE c205 = 0;
IND_TYPE f274 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1440 ,mem_vec_1441 ,mem_vec_1442 ,mem_vec_1443 ,mem_vec_1444 ,mem_vec_1445 ,mem_vec_1446 ,mem_vec_1447 ,mem_vec_1448 ,mem_vec_1449 ,mem_vec_1450 ,mem_vec_1451 ,mem_vec_1452 ,mem_vec_1453 ,mem_vec_1454 ,mem_vec_1455 ,mem_vec_1456 ,mem_vec_1457 ,mem_vec_1458 ,mem_vec_1459 ,mem_vec_1460 ,mem_vec_1461 ,mem_vec_1462 ,mem_vec_1463 ,mem_vec_1464 ,mem_vec_1465 ,mem_vec_1466 ,mem_vec_1467 ,mem_vec_1468 ,mem_vec_1469 ,mem_vec_1470 ,mem_vec_1471 ,mem_vec_1472 ,mem_vec_1473 ,mem_vec_1474 ,mem_vec_1475 ,mem_vec_1476 ,mem_vec_1477 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f273 = 0;
f273_p_0 = 0;
x256 = 0;
x256_p_0 = 0;
f272 = 0;
f272_p_1 = 0;
c204 = 0;
c204_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h136, hp_0 = 0;h < h136 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w84, wp_0 = 0;w < w84 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x256, xp_1 = x256_p_0, xp_0 = 0;x < x256 + 4;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_1441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_1442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_1443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_1444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_1445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_1446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_1447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_1448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_1449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_1450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_1451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_1452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_1453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_1454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_1455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c204, cp_1 = c204_p_0, cp_0 = 0;c < c204 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1440);
													mem_vec_1440 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1441);
													mem_vec_1441 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1442);
													mem_vec_1442 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1443);
													mem_vec_1443 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1444);
													mem_vec_1444 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1445);
													mem_vec_1445 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1446);
													mem_vec_1446 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1447);
													mem_vec_1447 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1448);
													mem_vec_1448 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1449);
													mem_vec_1449 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1450);
													mem_vec_1450 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1451);
													mem_vec_1451 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1452);
													mem_vec_1452 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1453);
													mem_vec_1453 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1454);
													mem_vec_1454 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1455);
													mem_vec_1455 = vec_25;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1440);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1441);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1442);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1443);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1444);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1445);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1446);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1447);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1448);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1449);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1450);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1451);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1452);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1453);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1454);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1455);
									}
								}
							}
}
