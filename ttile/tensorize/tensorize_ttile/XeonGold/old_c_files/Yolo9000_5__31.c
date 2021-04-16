#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (2, f);
  T (68, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x123_p_0, xp_1, x123, y, yp_0, y123_p_0, yp_1, y123;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y124 = 0;
IND_TYPE x124 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c82 = 0;
IND_TYPE f82 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1684 ,mem_vec_1685 ,mem_vec_1686 ,mem_vec_1687 ,mem_vec_1688 ,mem_vec_1689 ,mem_vec_1690 ,mem_vec_1691 ,mem_vec_1692 ,mem_vec_1693 ,mem_vec_1694 ,mem_vec_1695 ,mem_vec_1696 ,mem_vec_1697 ,mem_vec_1698 ,mem_vec_1699 ,mem_vec_1700 ,mem_vec_1701 ,mem_vec_1702 ,mem_vec_1703 ,mem_vec_1704 ,mem_vec_1705 ,mem_vec_1706 ,mem_vec_1707 ,mem_vec_1708 ,mem_vec_1709 ,mem_vec_1710 ,mem_vec_1711 ,mem_vec_1712 ,mem_vec_1713 ,mem_vec_1714 ,mem_vec_1715 ,mem_vec_1716 ,mem_vec_1717 ,mem_vec_1718 ,mem_vec_1719 ,mem_vec_1720 ,mem_vec_1721 ,mem_vec_1722 ,mem_vec_1723 ,mem_vec_1724 ,mem_vec_1725 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y123 = y124, y123_p_0 = 0;
	y123 < y124 + 136;
	y123 += 34, y123_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x123 = x124, x123_p_0 = 0;
		x123 < x124 + 136;
		x123 += 2, x123_p_0 += 2){
		// y = 34, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f82, fp_0 = 0;
			f < f82 + 64;
			f += 32, fp_0 += 32){
				for (y = y123, yp_1 = y123_p_0, yp_0 = 0;
					y < y123 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x123, xp_1 = x123_p_0, xp_0 = 0;
						x < x123 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_1699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c82, cp_0 = 0;
									c < c82 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1684);
									mem_vec_1684 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1685);
									mem_vec_1685 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1686);
									mem_vec_1686 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1687);
									mem_vec_1687 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1688);
									mem_vec_1688 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1689);
									mem_vec_1689 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1690);
									mem_vec_1690 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1691);
									mem_vec_1691 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1692);
									mem_vec_1692 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1693);
									mem_vec_1693 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1694);
									mem_vec_1694 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1695);
									mem_vec_1695 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1696);
									mem_vec_1696 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1697);
									mem_vec_1697 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1698);
									mem_vec_1698 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1699);
									mem_vec_1699 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1684);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1685);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1686);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1687);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1688);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1689);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1690);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1691);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1692);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1693);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1694);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1695);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1696);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1697);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1698);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1699);
					}
				}
				for (y = y123 + 8, yp_1 = y123_p_0, yp_0 = 0;
					y < y123 + 8 + 26;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x123, xp_1 = x123_p_0, xp_0 = 0;
						x < x123 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_1714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_1715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_1716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_1717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_1718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_1719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_1720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_1721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_1722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_1723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_1724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_1725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c82, cp_0 = 0;
									c < c82 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1700);
									mem_vec_1700 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1701);
									mem_vec_1701 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1702);
									mem_vec_1702 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1703);
									mem_vec_1703 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1704);
									mem_vec_1704 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1705);
									mem_vec_1705 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1706);
									mem_vec_1706 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1707);
									mem_vec_1707 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1708);
									mem_vec_1708 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1709);
									mem_vec_1709 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1710);
									mem_vec_1710 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1711);
									mem_vec_1711 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1712);
									mem_vec_1712 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1713);
									mem_vec_1713 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1714);
									mem_vec_1714 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1715);
									mem_vec_1715 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1716);
									mem_vec_1716 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1717);
									mem_vec_1717 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1718);
									mem_vec_1718 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1719);
									mem_vec_1719 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1720);
									mem_vec_1720 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1721);
									mem_vec_1721 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1722);
									mem_vec_1722 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1723);
									mem_vec_1723 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1724);
									mem_vec_1724 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1725);
									mem_vec_1725 = vec_40;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1700);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1701);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1702);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1703);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1704);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1705);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1706);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1707);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1708);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1709);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1710);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1711);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1712);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1713);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1714);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1715);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1716);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1717);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1718);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1719);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1720);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1721);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1722);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1723);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1724);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1725);
					}
				}
		}
	}
}


}