#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (2, f);
  T (32, c); T (8, f)]
*/
IND_TYPE c, cp_0, c132_p_0, cp_1, c132, f, fp_0, f176_p_0, f177_p_0, fp_1, f176_p_1, fp_2, f176, f177, h, hp_0, w, wp_0, x, xp_0, x132_p_0, xp_1, x132, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y88 = 0;
IND_TYPE x133 = 0;
IND_TYPE h88 = 0;
IND_TYPE w88 = 0;
IND_TYPE c133 = 0;
IND_TYPE f178 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1680 ,mem_vec_1681 ,mem_vec_1682 ,mem_vec_1683 ,mem_vec_1684 ,mem_vec_1685 ,mem_vec_1686 ,mem_vec_1687 ,mem_vec_1688 ,mem_vec_1689 ,mem_vec_1690 ,mem_vec_1691 ,mem_vec_1692 ,mem_vec_1693 ,mem_vec_1694 ,mem_vec_1695 ,mem_vec_1696 ,mem_vec_1697 ,mem_vec_1698 ,mem_vec_1699 ,mem_vec_1700 ,mem_vec_1701 ,mem_vec_1702 ,mem_vec_1703 ,mem_vec_1704 ,mem_vec_1705 ,mem_vec_1706 ,mem_vec_1707 ,mem_vec_1708 ,mem_vec_1709 ,mem_vec_1710 ,mem_vec_1711 ,mem_vec_1712 ,mem_vec_1713 ,mem_vec_1714 ,mem_vec_1715 ,mem_vec_1716 ,mem_vec_1717 ,mem_vec_1718 ,mem_vec_1719 ,mem_vec_1720 ,mem_vec_1721 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f177 = f178, f177_p_0 = 0;
	f177 < f178 + 512;
	f177 += 64, f177_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (c, 32) (256 / 8)
	for (c132 = c133, c132_p_0 = 0;
		c132 < c133 + 256;
		c132 += 8, c132_p_0 += 8){
		// y = 34, x = 34, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f176 = f177, f176_p_1 = f177_p_0, f176_p_0 = 0;
			f176 < f177 + 64;
			f176 += 32, f176_p_1 += 32, f176_p_0 += 32){
				for (y = y88, yp_0 = 0;
					y < y88 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (x, 17) (34 / 2)
					for (x132 = x133, x132_p_0 = 0;
						x132 < x133 + 34;
						x132 += 2, x132_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (f, 1) (32 / 32)
						for (f = f176, fp_2 = f176_p_1, fp_1 = f176_p_0, fp_0 = 0;
							f < f176 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h88, hp_0 = 0;
								h < h88 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w88, wp_0 = 0;
									w < w88 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x132, xp_1 = x132_p_0, xp_0 = 0;
										x < x132 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1680 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1681 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c132, cp_1 = c132_p_0, cp_0 = 0;
													c < c132 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1680);
													mem_vec_1680 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1681);
													mem_vec_1681 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1682);
													mem_vec_1682 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1683);
													mem_vec_1683 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1684);
													mem_vec_1684 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1685);
													mem_vec_1685 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1686);
													mem_vec_1686 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1687);
													mem_vec_1687 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1688);
													mem_vec_1688 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1689);
													mem_vec_1689 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1690);
													mem_vec_1690 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1691);
													mem_vec_1691 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1692);
													mem_vec_1692 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1693);
													mem_vec_1693 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1694);
													mem_vec_1694 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1695);
													mem_vec_1695 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1695);
									}
								}
							}
						}
					}
				}
				for (y = y88 + 8, yp_0 = 0;
					y < y88 + 8 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
					// T (x, 17) (34 / 2)
					for (x132 = x133, x132_p_0 = 0;
						x132 < x133 + 34;
						x132 += 2, x132_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
						// T (f, 1) (32 / 32)
						for (f = f176, fp_2 = f176_p_1, fp_1 = f176_p_0, fp_0 = 0;
							f < f176 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h88, hp_0 = 0;
								h < h88 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w88, wp_0 = 0;
									w < w88 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x132, xp_1 = x132_p_0, xp_0 = 0;
										x < x132 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1696 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1697 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_1720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_1721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c132, cp_1 = c132_p_0, cp_0 = 0;
													c < c132 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1696);
													mem_vec_1696 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1697);
													mem_vec_1697 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1698);
													mem_vec_1698 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1699);
													mem_vec_1699 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1700);
													mem_vec_1700 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1701);
													mem_vec_1701 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1702);
													mem_vec_1702 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1703);
													mem_vec_1703 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1704);
													mem_vec_1704 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1705);
													mem_vec_1705 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1706);
													mem_vec_1706 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1707);
													mem_vec_1707 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1708);
													mem_vec_1708 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1709);
													mem_vec_1709 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1710);
													mem_vec_1710 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1711);
													mem_vec_1711 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1712);
													mem_vec_1712 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1713);
													mem_vec_1713 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1714);
													mem_vec_1714 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1715);
													mem_vec_1715 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1716);
													mem_vec_1716 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1717);
													mem_vec_1717 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1718);
													mem_vec_1718 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1719);
													mem_vec_1719 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1720);
													mem_vec_1720 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1721);
													mem_vec_1721 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1696);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1697);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1698);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1699);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1707);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1708);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1709);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1710);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1711);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1712);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1713);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1714);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1715);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1716);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1717);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1718);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1719);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1720);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1721);
									}
								}
							}
						}
					}
				}
		}
	}
}


}