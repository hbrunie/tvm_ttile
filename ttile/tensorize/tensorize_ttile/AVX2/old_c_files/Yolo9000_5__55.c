#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (4, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c174_p_0, cp_1, c174, f, fp_0, x, xp_0, x290_p_0, x291_p_0, x292_p_0, xp_1, x290_p_1, x291_p_1, xp_2, x290_p_2, xp_3, x290, x291, x292, y, yp_0, y232_p_0, y233_p_0, yp_1, y232_p_1, yp_2, y232, y233;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y234 = 0;
IND_TYPE x293 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c175 = 0;
IND_TYPE f116 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1688 ,mem_vec_1689 ,mem_vec_1690 ,mem_vec_1691 ,mem_vec_1692 ,mem_vec_1693 ,mem_vec_1694 ,mem_vec_1695 ,mem_vec_1696 ,mem_vec_1697 ,mem_vec_1698 ,mem_vec_1699 ,mem_vec_1700 ,mem_vec_1701 ,mem_vec_1702 ,mem_vec_1703 ,mem_vec_1704 ,mem_vec_1705 ,mem_vec_1706 ,mem_vec_1707 ,mem_vec_1708 ,mem_vec_1709 ,mem_vec_1710 ,mem_vec_1711 ,mem_vec_1712 ,mem_vec_1713 ,mem_vec_1714 ,mem_vec_1715 ,mem_vec_1716 ,mem_vec_1717 ,mem_vec_1718 ,mem_vec_1719 ,mem_vec_1720 ,mem_vec_1721 ,mem_vec_1722 ,mem_vec_1723 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y233 = y234, y233_p_0 = 0;
		y233 < y234 + 96;
		y233 += 32, y233_p_0 += 32){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x292 = x293, x292_p_0 = 0;
			x292 < x293 + 136;
			x292 += 2, x292_p_0 += 2){
			// y = 4 * (2 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y232 = y233, y232_p_1 = y233_p_0, y232_p_0 = 0;
				y232 < y233 + 32;
				y232 += 8, y232_p_1 += 8, y232_p_0 += 8){
				// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x291 = x292, x291_p_1 = x292_p_0, x291_p_0 = 0;
					x291 < x292 + 2;
					x291 += 2, x291_p_1 += 2, x291_p_0 += 2){
					// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f116, fp_0 = 0;
						f < f116 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y232, yp_2 = y232_p_1, yp_1 = y232_p_0, yp_0 = 0;
							y < y232 + 8;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x290 = x291, x290_p_2 = x291_p_1, x290_p_1 = x291_p_0, x290_p_0 = 0;
								x290 < x291 + 2;
								x290 += 2, x290_p_2 += 2, x290_p_1 += 2, x290_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c174 = c175, c174_p_0 = 0;
									c174 < c175 + 128;
									c174 += 32, c174_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x290, xp_3 = x290_p_2, xp_2 = x290_p_1, xp_1 = x290_p_0, xp_0 = 0;
										x < x290 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1688 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1689 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1690 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1691 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1692 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1693 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1694 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1695 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c174, cp_1 = c174_p_0, cp_0 = 0;
													c < c174 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1688);
													mem_vec_1688 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1689);
													mem_vec_1689 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1690);
													mem_vec_1690 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1691);
													mem_vec_1691 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1692);
													mem_vec_1692 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1693);
													mem_vec_1693 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1694);
													mem_vec_1694 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1695);
													mem_vec_1695 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1696);
													mem_vec_1696 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1697);
													mem_vec_1697 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1698);
													mem_vec_1698 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1699);
													mem_vec_1699 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1700);
													mem_vec_1700 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1701);
													mem_vec_1701 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1702);
													mem_vec_1702 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1703);
													mem_vec_1703 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1688);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1689);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1690);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1691);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1692);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1693);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1694);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1695);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1696);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1697);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1698);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1699);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1700);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1701);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1702);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1703);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y233 = y234 + 96, y233_p_0 = 0;
		y233 < y234 + 96 + 40;
		y233 += 40, y233_p_0 += 40){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x292 = x293, x292_p_0 = 0;
			x292 < x293 + 136;
			x292 += 2, x292_p_0 += 2){
			// y = 4 * (2 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y232 = y233, y232_p_1 = y233_p_0, y232_p_0 = 0;
				y232 < y233 + 40;
				y232 += 10, y232_p_1 += 10, y232_p_0 += 10){
				// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x291 = x292, x291_p_1 = x292_p_0, x291_p_0 = 0;
					x291 < x292 + 2;
					x291 += 2, x291_p_1 += 2, x291_p_0 += 2){
					// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f116, fp_0 = 0;
						f < f116 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y232, yp_2 = y232_p_1, yp_1 = y232_p_0, yp_0 = 0;
							y < y232 + 10;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x290 = x291, x290_p_2 = x291_p_1, x290_p_1 = x291_p_0, x290_p_0 = 0;
								x290 < x291 + 2;
								x290 += 2, x290_p_2 += 2, x290_p_1 += 2, x290_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c174 = c175, c174_p_0 = 0;
									c174 < c175 + 128;
									c174 += 32, c174_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x290, xp_3 = x290_p_2, xp_2 = x290_p_1, xp_1 = x290_p_0, xp_0 = 0;
										x < x290 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1704 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1705 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1706 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1707 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1708 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1709 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1710 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1711 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1714 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1715 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1716 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1717 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_1720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c174, cp_1 = c174_p_0, cp_0 = 0;
													c < c174 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1704);
													mem_vec_1704 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1705);
													mem_vec_1705 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1706);
													mem_vec_1706 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1707);
													mem_vec_1707 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1708);
													mem_vec_1708 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1709);
													mem_vec_1709 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1710);
													mem_vec_1710 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1711);
													mem_vec_1711 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1712);
													mem_vec_1712 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1713);
													mem_vec_1713 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1714);
													mem_vec_1714 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1715);
													mem_vec_1715 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1716);
													mem_vec_1716 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1717);
													mem_vec_1717 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1718);
													mem_vec_1718 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1719);
													mem_vec_1719 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1720);
													mem_vec_1720 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1721);
													mem_vec_1721 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1722);
													mem_vec_1722 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1723);
													mem_vec_1723 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1704);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1705);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1706);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1707);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1708);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1709);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1710);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1711);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1712);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1713);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1714);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1715);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1716);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1717);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1718);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1719);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1720);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1721);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1722);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1723);
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