#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, f);
  T (136, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x117_p_0, xp_1, x117, y, yp_0, y117_p_0, yp_1, y117;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y118 = 0;
IND_TYPE x118 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c78 = 0;
IND_TYPE f78 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1606 ,mem_vec_1607 ,mem_vec_1608 ,mem_vec_1609 ,mem_vec_1610 ,mem_vec_1611 ,mem_vec_1612 ,mem_vec_1613 ,mem_vec_1614 ,mem_vec_1615 ,mem_vec_1616 ,mem_vec_1617 ,mem_vec_1618 ,mem_vec_1619 ,mem_vec_1620 ,mem_vec_1621 ,mem_vec_1622 ,mem_vec_1623 ,mem_vec_1624 ,mem_vec_1625 ,mem_vec_1626 ,mem_vec_1627 ,mem_vec_1628 ,mem_vec_1629 ,mem_vec_1630 ,mem_vec_1631 ,mem_vec_1632 ,mem_vec_1633 ,mem_vec_1634 ,mem_vec_1635 ,mem_vec_1636 ,mem_vec_1637 ,mem_vec_1638 ,mem_vec_1639 ,mem_vec_1640 ,mem_vec_1641 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y117 = y118, y117_p_0 = 0;
	y117 < y118 + 136;
	y117 += 34, y117_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x117 = x118, x117_p_0 = 0;
		x117 < x118 + 136;
		x117 += 1, x117_p_0 += 1){
		// y = 34, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f78, fp_0 = 0;
			f < f78 + 64;
			f += 32, fp_0 += 32){
				for (y = y117, yp_1 = y117_p_0, yp_0 = 0;
					y < y117 + 24;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x117, xp_1 = x117_p_0, xp_0 = 0;
						x < x117 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1606 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1607 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_1621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c78, cp_0 = 0;
									c < c78 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1606);
									mem_vec_1606 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1607);
									mem_vec_1607 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1608);
									mem_vec_1608 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1609);
									mem_vec_1609 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1610);
									mem_vec_1610 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1611);
									mem_vec_1611 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1612);
									mem_vec_1612 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1613);
									mem_vec_1613 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1614);
									mem_vec_1614 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1615);
									mem_vec_1615 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1616);
									mem_vec_1616 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1617);
									mem_vec_1617 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1618);
									mem_vec_1618 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1619);
									mem_vec_1619 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1620);
									mem_vec_1620 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1621);
									mem_vec_1621 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1606);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1607);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1608);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1609);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1610);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1611);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1612);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1613);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1614);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1615);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1616);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1617);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1618);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1619);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1620);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1621);
					}
				}
				for (y = y117 + 24, yp_1 = y117_p_0, yp_0 = 0;
					y < y117 + 24 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x117, xp_1 = x117_p_0, xp_0 = 0;
						x < x117 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1622 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1623 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_1637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_1638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_1639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_1640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_1641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c78, cp_0 = 0;
									c < c78 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1622);
									mem_vec_1622 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1623);
									mem_vec_1623 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1624);
									mem_vec_1624 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1625);
									mem_vec_1625 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1626);
									mem_vec_1626 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1627);
									mem_vec_1627 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1628);
									mem_vec_1628 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1629);
									mem_vec_1629 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1630);
									mem_vec_1630 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1631);
									mem_vec_1631 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1632);
									mem_vec_1632 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1633);
									mem_vec_1633 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1634);
									mem_vec_1634 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1635);
									mem_vec_1635 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1636);
									mem_vec_1636 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1637);
									mem_vec_1637 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1638);
									mem_vec_1638 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1639);
									mem_vec_1639 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1640);
									mem_vec_1640 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1641);
									mem_vec_1641 = vec_31;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1622);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1623);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1624);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1625);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1626);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1627);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1628);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1629);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1630);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1631);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1632);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1633);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1634);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1635);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1636);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1637);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1638);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1639);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1640);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1641);
					}
				}
		}
	}
}


}