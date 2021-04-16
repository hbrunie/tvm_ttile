#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (31, f);
  T (1, x); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))];
  T (1, c); T (1, f); T (1, x); T (1, y); T (57, f)]
*/
IND_TYPE c, cp_0, c303_p_0, cp_1, c303, f, fp_0, f404_p_0, f405_p_0, fp_1, f404_p_1, fp_2, f404, f405, x, xp_0, x404_p_0, x405_p_0, xp_1, x404_p_1, xp_2, x404, x405, y, yp_0, y303_p_0, yp_1, y303;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y304 = 0;
IND_TYPE x406 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c304 = 0;
IND_TYPE f406 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1717 ,mem_vec_1718 ,mem_vec_1719 ,mem_vec_1720 ,mem_vec_1721 ,mem_vec_1722 ,mem_vec_1723 ,mem_vec_1724 ,mem_vec_1725 ,mem_vec_1726 ,mem_vec_1727 ,mem_vec_1728 ,mem_vec_1729 ,mem_vec_1730 ,mem_vec_1731 ,mem_vec_1732 ,mem_vec_1733 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 57) (28272 / 496)
for (f405 = f406, f405_p_0 = 0;
	f405 < f406 + 28272;
	f405 += 496, f405_p_0 += 496){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 496
	// T (y, 1) (17 / 17)
	for (y303 = y304, y303_p_0 = 0;
		y303 < y304 + 17;
		y303 += 17, y303_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 496
		// T (x, 1) (17 / 17)
		for (x405 = x406, x405_p_0 = 0;
			x405 < x406 + 17;
			x405 += 17, x405_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 496
			// T (f, 1) (496 / 496)
			for (f404 = f405, f404_p_1 = f405_p_0, f404_p_0 = 0;
				f404 < f405 + 496;
				f404 += 496, f404_p_1 += 496, f404_p_0 += 496){
				// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 496
				// T (c, 1) (1024 / 1024)
				for (c303 = c304, c303_p_0 = 0;
					c303 < c304 + 1024;
					c303 += 1024, c303_p_0 += 1024){
						for (y = y303, yp_1 = y303_p_0, yp_0 = 0;
							y < y303 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
							// T (x, 1) (17 / 17)
							for (x404 = x405, x404_p_1 = x405_p_0, x404_p_0 = 0;
								x404 < x405 + 17;
								x404 += 17, x404_p_1 += 17, x404_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
								// T (f, 31) (496 / 16)
								for (f = f404, fp_2 = f404_p_1, fp_1 = f404_p_0, fp_0 = 0;
									f < f404 + 496;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x404, xp_2 = x404_p_1, xp_1 = x404_p_0, xp_0 = 0;
										x < x404 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c303, cp_1 = c303_p_0, cp_0 = 0;
													c < c303 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1717);
													mem_vec_1717 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1718);
													mem_vec_1718 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1719);
													mem_vec_1719 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1720);
													mem_vec_1720 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1721);
													mem_vec_1721 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1722);
													mem_vec_1722 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1723);
													mem_vec_1723 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1724);
													mem_vec_1724 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1717);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1718);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1719);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1720);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1721);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1722);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1723);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1724);
									}
								}
							}
						}
						for (y = y303 + 8, yp_1 = y303_p_0, yp_0 = 0;
							y < y303 + 8 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
							// T (x, 1) (17 / 17)
							for (x404 = x405, x404_p_1 = x405_p_0, x404_p_0 = 0;
								x404 < x405 + 17;
								x404 += 17, x404_p_1 += 17, x404_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 496
								// T (f, 31) (496 / 16)
								for (f = f404, fp_2 = f404_p_1, fp_1 = f404_p_0, fp_0 = 0;
									f < f404 + 496;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x404, xp_2 = x404_p_1, xp_1 = x404_p_0, xp_0 = 0;
										x < x404 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1725 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c303, cp_1 = c303_p_0, cp_0 = 0;
													c < c303 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1725);
													mem_vec_1725 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1726);
													mem_vec_1726 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1727);
													mem_vec_1727 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1728);
													mem_vec_1728 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1729);
													mem_vec_1729 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1730);
													mem_vec_1730 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1731);
													mem_vec_1731 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1732);
													mem_vec_1732 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1733);
													mem_vec_1733 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1725);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1726);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1727);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1728);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1729);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1730);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1731);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1732);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1733);
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