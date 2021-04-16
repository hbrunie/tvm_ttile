#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))];
  T (1, c); T (1767, f); T (1, x); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c300_p_0, cp_1, c300, f, fp_0, f400_p_0, f401_p_0, fp_1, f400_p_1, fp_2, f400, f401, x, xp_0, x400_p_0, x401_p_0, xp_1, x400_p_1, xp_2, x400, x401, y, yp_0, y300_p_0, yp_1, y300;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y301 = 0;
IND_TYPE x402 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c301 = 0;
IND_TYPE f402 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1700 ,mem_vec_1701 ,mem_vec_1702 ,mem_vec_1703 ,mem_vec_1704 ,mem_vec_1705 ,mem_vec_1706 ,mem_vec_1707 ,mem_vec_1708 ,mem_vec_1709 ,mem_vec_1710 ,mem_vec_1711 ,mem_vec_1712 ,mem_vec_1713 ,mem_vec_1714 ,mem_vec_1715 ,mem_vec_1716 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 1) (28272 / 28272)
for (f401 = f402, f401_p_0 = 0;
	f401 < f402 + 28272;
	f401 += 28272, f401_p_0 += 28272){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
	// T (y, 1) (17 / 17)
	for (y300 = y301, y300_p_0 = 0;
		y300 < y301 + 17;
		y300 += 17, y300_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
		// T (x, 1) (17 / 17)
		for (x401 = x402, x401_p_0 = 0;
			x401 < x402 + 17;
			x401 += 17, x401_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
			// T (f, 1767) (28272 / 16)
			for (f400 = f401, f400_p_1 = f401_p_0, f400_p_0 = 0;
				f400 < f401 + 28272;
				f400 += 16, f400_p_1 += 16, f400_p_0 += 16){
				// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 16
				// T (c, 1) (1024 / 1024)
				for (c300 = c301, c300_p_0 = 0;
					c300 < c301 + 1024;
					c300 += 1024, c300_p_0 += 1024){
						for (y = y300, yp_1 = y300_p_0, yp_0 = 0;
							y < y300 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
							// T (x, 1) (17 / 17)
							for (x400 = x401, x400_p_1 = x401_p_0, x400_p_0 = 0;
								x400 < x401 + 17;
								x400 += 17, x400_p_1 += 17, x400_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
								// T (f, 1) (16 / 16)
								for (f = f400, fp_2 = f400_p_1, fp_1 = f400_p_0, fp_0 = 0;
									f < f400 + 16;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x400, xp_2 = x400_p_1, xp_1 = x400_p_0, xp_0 = 0;
										x < x400 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c300, cp_1 = c300_p_0, cp_0 = 0;
													c < c300 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1700);
													mem_vec_1700 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1701);
													mem_vec_1701 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1702);
													mem_vec_1702 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1703);
													mem_vec_1703 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1704);
													mem_vec_1704 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1705);
													mem_vec_1705 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1706);
													mem_vec_1706 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1707);
													mem_vec_1707 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1707);
									}
								}
							}
						}
						for (y = y300 + 8, yp_1 = y300_p_0, yp_0 = 0;
							y < y300 + 8 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
							// T (x, 1) (17 / 17)
							for (x400 = x401, x400_p_1 = x401_p_0, x400_p_0 = 0;
								x400 < x401 + 17;
								x400 += 17, x400_p_1 += 17, x400_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
								// T (f, 1) (16 / 16)
								for (f = f400, fp_2 = f400_p_1, fp_1 = f400_p_0, fp_0 = 0;
									f < f400 + 16;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x400, xp_2 = x400_p_1, xp_1 = x400_p_0, xp_0 = 0;
										x < x400 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1708 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c300, cp_1 = c300_p_0, cp_0 = 0;
													c < c300 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1708);
													mem_vec_1708 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1709);
													mem_vec_1709 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1710);
													mem_vec_1710 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1711);
													mem_vec_1711 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1712);
													mem_vec_1712 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1713);
													mem_vec_1713 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1714);
													mem_vec_1714 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_1715);
													mem_vec_1715 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1716);
													mem_vec_1716 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1708);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1709);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1710);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1711);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1712);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1713);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1714);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1715);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1716);
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