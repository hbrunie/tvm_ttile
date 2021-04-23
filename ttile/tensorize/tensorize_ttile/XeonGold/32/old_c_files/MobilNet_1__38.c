#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (4, y); T (1, c);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]]
*/
IND_TYPE c, cp_0, c129_p_0, cp_1, c129, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y129_p_0, yp_1, y129;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y130 = 0;
IND_TYPE x86 = 0;
IND_TYPE h80 = 0;
IND_TYPE w86 = 0;
IND_TYPE c130 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1768 ,mem_vec_1769 ,mem_vec_1770 ,mem_vec_1771 ,mem_vec_1772 ,mem_vec_1773 ,mem_vec_1774 ,mem_vec_1775 ,mem_vec_1776 ,mem_vec_1777 ,mem_vec_1778 ,mem_vec_1779 ,mem_vec_1780 ,mem_vec_1781 ,mem_vec_1782 ,mem_vec_1783 ,mem_vec_1784 ,mem_vec_1785 ,mem_vec_1786 ,mem_vec_1787 ,mem_vec_1788 ,mem_vec_1789 ,mem_vec_1790 ,mem_vec_1791 ,mem_vec_1792 ,mem_vec_1793 ,mem_vec_1794 ,mem_vec_1795 ,mem_vec_1796 ,mem_vec_1797 ,mem_vec_1798 ,mem_vec_1799 ,mem_vec_1800 ,mem_vec_1801 ,mem_vec_1802 ,mem_vec_1803 ,mem_vec_1804 ,mem_vec_1805 ,mem_vec_1806 ,mem_vec_1807 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y129 = y130, y129_p_0 = 0;
		y129 < y130 + 64;
		y129 += 32, y129_p_0 += 32){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c129 = c130, c129_p_0 = 0;
			c129 < c130 + 32;
			c129 += 32, c129_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y129, yp_1 = y129_p_0, yp_0 = 0;
				y < y129 + 32;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x86, xp_0 = 0;
					x < x86 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h80, hp_0 = 0;
						h < h80 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w86, wp_0 = 0;
							w < w86 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c129, cp_1 = c129_p_0, cp_0 = 0;
										c < c129 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1768);
										mem_vec_1768 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1769);
										mem_vec_1769 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1770);
										mem_vec_1770 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1771);
										mem_vec_1771 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1772);
										mem_vec_1772 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1773);
										mem_vec_1773 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1774);
										mem_vec_1774 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1775);
										mem_vec_1775 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1776);
										mem_vec_1776 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1777);
										mem_vec_1777 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1778);
										mem_vec_1778 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1779);
										mem_vec_1779 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1780);
										mem_vec_1780 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1781);
										mem_vec_1781 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1782);
										mem_vec_1782 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1783);
										mem_vec_1783 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1783);
						}
					}
				}
			}
		}
	}
	for (y129 = y130 + 64, y129_p_0 = 0;
		y129 < y130 + 64 + 48;
		y129 += 48, y129_p_0 += 48){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c129 = c130, c129_p_0 = 0;
			c129 < c130 + 32;
			c129 += 32, c129_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y129, yp_1 = y129_p_0, yp_0 = 0;
				y < y129 + 48;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x86, xp_0 = 0;
					x < x86 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h80, hp_0 = 0;
						h < h80 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w86, wp_0 = 0;
							w < w86 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1784 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1785 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_1799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_1800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_1801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_1802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_1803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_1804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_1805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_1806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_1807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c129, cp_1 = c129_p_0, cp_0 = 0;
										c < c129 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1784);
										mem_vec_1784 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1785);
										mem_vec_1785 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1786);
										mem_vec_1786 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1787);
										mem_vec_1787 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1788);
										mem_vec_1788 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1789);
										mem_vec_1789 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1790);
										mem_vec_1790 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1791);
										mem_vec_1791 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1792);
										mem_vec_1792 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1793);
										mem_vec_1793 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1794);
										mem_vec_1794 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1795);
										mem_vec_1795 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1796);
										mem_vec_1796 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1797);
										mem_vec_1797 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1798);
										mem_vec_1798 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1799);
										mem_vec_1799 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1800);
										mem_vec_1800 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1801);
										mem_vec_1801 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1802);
										mem_vec_1802 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1803);
										mem_vec_1803 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1804);
										mem_vec_1804 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1805);
										mem_vec_1805 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1806);
										mem_vec_1806 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1807);
										mem_vec_1807 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1784);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1785);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1786);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1787);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1788);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1789);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1790);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1791);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1795);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1796);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1797);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1798);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1799);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1800);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1801);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1805);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1806);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1807);
						}
					}
				}
			}
		}
	}


}