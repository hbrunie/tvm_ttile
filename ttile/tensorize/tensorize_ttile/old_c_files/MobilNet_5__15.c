#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (4, y); T (1, f); T (8, c); T (1, f); T (4, c); T (7, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c232_p_0, c233_p_0, cp_1, c232_p_1, cp_2, c232, c233, f, fp_0, f220_p_0, f221_p_0, fp_1, f220_p_1, fp_2, f220, f221, h, hp_0, w, wp_0, x, xp_0, x174_p_0, xp_1, x174, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y116 = 0;
IND_TYPE x175 = 0;
IND_TYPE h116 = 0;
IND_TYPE w116 = 0;
IND_TYPE c234 = 0;
IND_TYPE f222 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1624 ,mem_vec_1625 ,mem_vec_1626 ,mem_vec_1627 ,mem_vec_1628 ,mem_vec_1629 ,mem_vec_1630 ,mem_vec_1631 ,mem_vec_1632 ,mem_vec_1633 ,mem_vec_1634 ,mem_vec_1635 ,mem_vec_1636 ,mem_vec_1637 ,mem_vec_1638 ,mem_vec_1639 ,mem_vec_1640 ,mem_vec_1641 ,mem_vec_1642 ,mem_vec_1643 ,mem_vec_1644 ,mem_vec_1645 ,mem_vec_1646 ,mem_vec_1647 ,mem_vec_1648 ,mem_vec_1649 ,mem_vec_1650 ,mem_vec_1651 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f221 = f222, f221_p_0 = 0;
	f221 < f222 + 256;
	f221 += 64, f221_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 7) (28 / 4)
	for (x174 = x175, x174_p_0 = 0;
		x174 < x175 + 28;
		x174 += 4, x174_p_0 += 4){
		// y = 28, x = 4, h = 3, w = 3, c = 256, f = 64
		// T (c, 4) (256 / 64)
		for (c233 = c234, c233_p_0 = 0;
			c233 < c234 + 256;
			c233 += 64, c233_p_0 += 64){
			// y = 28, x = 4, h = 3, w = 3, c = 64, f = 64
			// T (f, 1) (64 / 64)
			for (f220 = f221, f220_p_1 = f221_p_0, f220_p_0 = 0;
				f220 < f221 + 64;
				f220 += 64, f220_p_1 += 64, f220_p_0 += 64){
				// y = 28, x = 4, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c232 = c233, c232_p_1 = c233_p_0, c232_p_0 = 0;
					c232 < c233 + 64;
					c232 += 8, c232_p_1 += 8, c232_p_0 += 8){
					// y = 28, x = 4, h = 3, w = 3, c = 8, f = 64
					// T (f, 1) (64 / 64)
					for (f = f220, fp_2 = f220_p_1, fp_1 = f220_p_0, fp_0 = 0;
						f < f220 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 4, h = 3, w = 3, c = 8, f = 64
						// T (y, 4) (28 / 7)
						for (y = y116, yp_0 = 0;
							y < y116 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 4, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h116, hp_0 = 0;
								h < h116 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 4, h = 1, w = 3, c = 8, f = 64
								// T (w, 3) (3 / 1)
								for (w = w116, wp_0 = 0;
									w < w116 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 4, h = 1, w = 1, c = 8, f = 64
									// T (x, 4) (4 / 1)
									for (x = x174, xp_1 = x174_p_0, xp_0 = 0;
										x < x174 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_1627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_1628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_1631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_1632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_1635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_1636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_1639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_1640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_1643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_1644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_1647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_1648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_1651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
												// T (c, 8) (8 / 1)
												for (c = c232, cp_2 = c232_p_1, cp_1 = c232_p_0, cp_0 = 0;
													c < c232 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1624);
													mem_vec_1624 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1625);
													mem_vec_1625 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1626);
													mem_vec_1626 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1627);
													mem_vec_1627 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1628);
													mem_vec_1628 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1629);
													mem_vec_1629 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1630);
													mem_vec_1630 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1631);
													mem_vec_1631 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1632);
													mem_vec_1632 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1633);
													mem_vec_1633 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1634);
													mem_vec_1634 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1635);
													mem_vec_1635 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1636);
													mem_vec_1636 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1637);
													mem_vec_1637 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1638);
													mem_vec_1638 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1639);
													mem_vec_1639 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1640);
													mem_vec_1640 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1641);
													mem_vec_1641 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1642);
													mem_vec_1642 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1643);
													mem_vec_1643 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1644);
													mem_vec_1644 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1645);
													mem_vec_1645 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1646);
													mem_vec_1646 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1647);
													mem_vec_1647 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1648);
													mem_vec_1648 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1649);
													mem_vec_1649 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1650);
													mem_vec_1650 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1651);
													mem_vec_1651 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1624);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1625);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1626);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1627);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1628);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1629);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1630);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1631);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1632);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1633);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1634);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1635);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1636);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1637);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1638);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1639);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1640);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1641);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1642);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1643);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1644);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1645);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1646);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1647);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1648);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1649);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1650);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1651);
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


}