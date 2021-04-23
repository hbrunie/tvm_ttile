
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, f);
  T (34, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x111_p_0, xp_1, x111, y, yp_0, y111_p_0, yp_1, y111;
IND_TYPE y112 = 0;
IND_TYPE x112 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c74 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,mem_vec_1544 ,mem_vec_1545 ,mem_vec_1546 ,mem_vec_1547 ,mem_vec_1548 ,mem_vec_1549 ,mem_vec_1550 ,mem_vec_1551 ,mem_vec_1552 ,mem_vec_1553 ,mem_vec_1554 ,mem_vec_1555 ,mem_vec_1556 ,mem_vec_1557 ,mem_vec_1558 ,mem_vec_1559 ,mem_vec_1560 ,mem_vec_1561 ,mem_vec_1562 ,mem_vec_1563 ,mem_vec_1564 ,mem_vec_1565 ,mem_vec_1566 ,mem_vec_1567 ,mem_vec_1568 ,mem_vec_1569 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
y111 = 0;
y111_p_0 = 0;
x111 = 0;
x111_p_0 = 0;
		for (f = f74, fp_0 = 0;f < f74 + 64;f += 32, fp_0 += 32){
				for (y = y111, yp_1 = y111_p_0, yp_0 = 0;y < y111 + 24;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x111, xp_1 = x111_p_0, xp_0 = 0;x < x111 + 4;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1534 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_1535 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_1536 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_1537 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_1538 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_1539 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_1540 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_1541 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_1542 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_1543 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_1544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_1545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_1546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_1547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_1548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_1549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c74, cp_0 = 0;c < c74 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1534);
									mem_vec_1534 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1535);
									mem_vec_1535 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1536);
									mem_vec_1536 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1537);
									mem_vec_1537 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1538);
									mem_vec_1538 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1539);
									mem_vec_1539 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1540);
									mem_vec_1540 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1541);
									mem_vec_1541 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1542);
									mem_vec_1542 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1543);
									mem_vec_1543 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1544);
									mem_vec_1544 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1545);
									mem_vec_1545 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1546);
									mem_vec_1546 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1547);
									mem_vec_1547 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1548);
									mem_vec_1548 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1549);
									mem_vec_1549 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1534);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1535);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1536);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1537);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1538);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1539);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1540);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1541);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1542);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1543);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1544);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1545);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1546);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1547);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1548);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1549);
					}
				}
				for (y = y111 + 24, yp_1 = y111_p_0, yp_0 = 0;y < y111 + 24 + 10;y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x111, xp_1 = x111_p_0, xp_0 = 0;x < x111 + 4;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_1551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_1552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_1553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_1554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_1555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_1556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_1557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_1558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_1559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_1560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_1561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_1562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_1563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_1564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_1565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_1566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_1567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								mem_vec_1568 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
								mem_vec_1569 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c74, cp_0 = 0;c < c74 + 128;c += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1550);
									mem_vec_1550 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1551);
									mem_vec_1551 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1552);
									mem_vec_1552 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1553);
									mem_vec_1553 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1554);
									mem_vec_1554 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1555);
									mem_vec_1555 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1556);
									mem_vec_1556 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1557);
									mem_vec_1557 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1558);
									mem_vec_1558 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1559);
									mem_vec_1559 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1560);
									mem_vec_1560 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1561);
									mem_vec_1561 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1562);
									mem_vec_1562 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1563);
									mem_vec_1563 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1564);
									mem_vec_1564 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1565);
									mem_vec_1565 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1566);
									mem_vec_1566 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1567);
									mem_vec_1567 = vec_28;
									scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1568);
									mem_vec_1568 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1569);
									mem_vec_1569 = vec_31;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1550);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1551);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1552);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1553);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1554);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1555);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1556);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1557);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1558);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1559);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1560);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1561);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1562);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1563);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1564);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1565);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1566);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1567);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1568);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1569);
					}
				}
		}
}
