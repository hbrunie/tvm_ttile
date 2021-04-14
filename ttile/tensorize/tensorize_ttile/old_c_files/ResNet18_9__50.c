#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (8, f); T (4, c); T (14, x); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, f168_p_0, fp_1, f168, h, hp_0, w, wp_0, x, xp_0, x168_p_0, xp_1, x168, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y112 = 0;
IND_TYPE x169 = 0;
IND_TYPE h112 = 0;
IND_TYPE w112 = 0;
IND_TYPE c169 = 0;
IND_TYPE f169 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1568 ,mem_vec_1569 ,mem_vec_1570 ,mem_vec_1571 ,mem_vec_1572 ,mem_vec_1573 ,mem_vec_1574 ,mem_vec_1575 ,mem_vec_1576 ,mem_vec_1577 ,mem_vec_1578 ,mem_vec_1579 ,mem_vec_1580 ,mem_vec_1581 ,mem_vec_1582 ,mem_vec_1583 ,mem_vec_1584 ,mem_vec_1585 ,mem_vec_1586 ,mem_vec_1587 ,mem_vec_1588 ,mem_vec_1589 ,mem_vec_1590 ,mem_vec_1591 ,mem_vec_1592 ,mem_vec_1593 ,mem_vec_1594 ,mem_vec_1595 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f168 = f169, f168_p_0 = 0;
	f168 < f169 + 256;
	f168 += 256, f168_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (y, 1) (14 / 14)
	for (y = y112, yp_0 = 0;
		y < y112 + 14;
		y += 14, yp_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
		// T (x, 14) (14 / 1)
		for (x168 = x169, x168_p_0 = 0;
			x168 < x169 + 14;
			x168 += 1, x168_p_0 += 1){
			// y = 14, x = 1, h = 3, w = 3, c = 256, f = 256
			// T (c, 4) (256 / 64)
			for (c168 = c169, c168_p_0 = 0;
				c168 < c169 + 256;
				c168 += 64, c168_p_0 += 64){
				// y = 14, x = 1, h = 3, w = 3, c = 64, f = 256
				// T (f, 8) (256 / 32)
				for (f = f168, fp_1 = f168_p_0, fp_0 = 0;
					f < f168 + 256;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (h, 3) (3 / 1)
					for (h = h112, hp_0 = 0;
						h < h112 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w112, wp_0 = 0;
							w < w112 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x168, xp_1 = x168_p_0, xp_0 = 0;
								x < x168 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1568 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1569 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_1586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_1587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_1588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_1589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_1590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_1591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_1592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_1593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_1594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_1595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
											c < c168 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1568);
											mem_vec_1568 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1569);
											mem_vec_1569 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1570);
											mem_vec_1570 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1571);
											mem_vec_1571 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1572);
											mem_vec_1572 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1573);
											mem_vec_1573 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1574);
											mem_vec_1574 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1575);
											mem_vec_1575 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1576);
											mem_vec_1576 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1577);
											mem_vec_1577 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1578);
											mem_vec_1578 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1579);
											mem_vec_1579 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1580);
											mem_vec_1580 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1581);
											mem_vec_1581 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1582);
											mem_vec_1582 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1583);
											mem_vec_1583 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1584);
											mem_vec_1584 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1585);
											mem_vec_1585 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1586);
											mem_vec_1586 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1587);
											mem_vec_1587 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1588);
											mem_vec_1588 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1589);
											mem_vec_1589 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1590);
											mem_vec_1590 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1591);
											mem_vec_1591 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1592);
											mem_vec_1592 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1593);
											mem_vec_1593 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1594);
											mem_vec_1594 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1595);
											mem_vec_1595 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1577);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1578);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1579);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1580);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1581);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1582);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1583);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1584);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1585);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1586);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1587);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1588);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1589);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1590);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1591);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1592);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1593);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1594);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1595);
							}
						}
					}
				}
			}
		}
	}
}


}