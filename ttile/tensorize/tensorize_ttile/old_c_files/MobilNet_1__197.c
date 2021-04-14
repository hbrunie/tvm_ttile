#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (14, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))]; T (2, c);
  T (8, x)]
*/
IND_TYPE c, cp_0, c216_p_0, cp_1, c216, h, hp_0, w, wp_0, x, xp_0, x288_p_0, x289_p_0, xp_1, x288_p_1, xp_2, x288, x289, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y144 = 0;
IND_TYPE x290 = 0;
IND_TYPE h124 = 0;
IND_TYPE w144 = 0;
IND_TYPE c217 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1556 ,mem_vec_1557 ,mem_vec_1558 ,mem_vec_1559 ,mem_vec_1560 ,mem_vec_1561 ,mem_vec_1562 ,mem_vec_1563 ,mem_vec_1564 ,mem_vec_1565 ,mem_vec_1566 ,mem_vec_1567 ,mem_vec_1568 ,mem_vec_1569 ,mem_vec_1570 ,mem_vec_1571 ,mem_vec_1572 ,mem_vec_1573 ,mem_vec_1574 ,mem_vec_1575 ,mem_vec_1576 ,mem_vec_1577 ,mem_vec_1578 ,mem_vec_1579 ,mem_vec_1580 ,mem_vec_1581 ,mem_vec_1582 ,mem_vec_1583 ,mem_vec_1584 ,mem_vec_1585 ,mem_vec_1586 ,mem_vec_1587 ,mem_vec_1588 ,mem_vec_1589 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 8) (112 / 14)
for (x289 = x290, x289_p_0 = 0;
	x289 < x290 + 112;
	x289 += 14, x289_p_0 += 14){
	// y = 112, x = 14, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c216 = c217, c216_p_0 = 0;
		c216 < c217 + 32;
		c216 += 16, c216_p_0 += 16){
			for (y = y144, yp_0 = 0;
				y < y144 + 40;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
				// T (x, 14) (14 / 1)
				for (x288 = x289, x288_p_1 = x289_p_0, x288_p_0 = 0;
					x288 < x289 + 14;
					x288 += 1, x288_p_1 += 1, x288_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h124, hp_0 = 0;
						h < h124 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w144, wp_0 = 0;
							w < w144 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x288, xp_2 = x288_p_1, xp_1 = x288_p_0, xp_0 = 0;
								x < x288 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1556 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1557 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c216, cp_1 = c216_p_0, cp_0 = 0;
											c < c216 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1556);
											mem_vec_1556 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1557);
											mem_vec_1557 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1558);
											mem_vec_1558 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1559);
											mem_vec_1559 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1560);
											mem_vec_1560 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1561);
											mem_vec_1561 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1562);
											mem_vec_1562 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1563);
											mem_vec_1563 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1564);
											mem_vec_1564 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1565);
											mem_vec_1565 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1566);
											mem_vec_1566 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1567);
											mem_vec_1567 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1568);
											mem_vec_1568 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1569);
											mem_vec_1569 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1570);
											mem_vec_1570 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1571);
											mem_vec_1571 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1571);
							}
						}
					}
				}
			}
			for (y = y144 + 40, yp_0 = 0;
				y < y144 + 40 + 72;
				y += 9, yp_0 += 9){
				// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
				// T (x, 14) (14 / 1)
				for (x288 = x289, x288_p_1 = x289_p_0, x288_p_0 = 0;
					x288 < x289 + 14;
					x288 += 1, x288_p_1 += 1, x288_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h124, hp_0 = 0;
						h < h124 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w144, wp_0 = 0;
							w < w144 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x288, xp_2 = x288_p_1, xp_1 = x288_p_0, xp_0 = 0;
								x < x288 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1572 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1573 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c216, cp_1 = c216_p_0, cp_0 = 0;
											c < c216 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1572);
											mem_vec_1572 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1573);
											mem_vec_1573 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1574);
											mem_vec_1574 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1575);
											mem_vec_1575 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1576);
											mem_vec_1576 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1577);
											mem_vec_1577 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1578);
											mem_vec_1578 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1579);
											mem_vec_1579 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1580);
											mem_vec_1580 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1581);
											mem_vec_1581 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1582);
											mem_vec_1582 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1583);
											mem_vec_1583 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1584);
											mem_vec_1584 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1585);
											mem_vec_1585 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1586);
											mem_vec_1586 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1587);
											mem_vec_1587 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1588);
											mem_vec_1588 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1589);
											mem_vec_1589 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1577);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1578);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1579);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1580);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1581);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1582);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1583);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1584);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1585);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1586);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1587);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1588);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1589);
							}
						}
					}
				}
			}
	}
}


}