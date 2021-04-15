#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 7)); ((Iter 3), (Arg 11))];
  T (8, f); T (4, c); T (1, f); T (68, x); T (1, f)]
*/
IND_TYPE c, cp_0, c162_p_0, cp_1, c162, f, fp_0, f216_p_0, f217_p_0, fp_1, f216_p_1, fp_2, f216, f217, h, hp_0, w, wp_0, x, xp_0, x180_p_0, xp_1, x180, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y108 = 0;
IND_TYPE x181 = 0;
IND_TYPE h92 = 0;
IND_TYPE w82 = 0;
IND_TYPE c163 = 0;
IND_TYPE f218 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f217 = f218, f217_p_0 = 0;
	f217 < f218 + 256;
	f217 += 256, f217_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 68) (68 / 1)
	for (x180 = x181, x180_p_0 = 0;
		x180 < x181 + 68;
		x180 += 1, x180_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 128, f = 256
		// T (f, 1) (256 / 256)
		for (f216 = f217, f216_p_1 = f217_p_0, f216_p_0 = 0;
			f216 < f217 + 256;
			f216 += 256, f216_p_1 += 256, f216_p_0 += 256){
			// y = 68, x = 1, h = 3, w = 3, c = 128, f = 256
			// T (c, 4) (128 / 32)
			for (c162 = c163, c162_p_0 = 0;
				c162 < c163 + 128;
				c162 += 32, c162_p_0 += 32){
				// y = 68, x = 1, h = 3, w = 3, c = 32, f = 256
				// T (f, 8) (256 / 32)
				for (f = f216, fp_2 = f216_p_1, fp_1 = f216_p_0, fp_0 = 0;
					f < f216 + 256;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y108, yp_0 = 0;
							y < y108 + 35;
							y += 7, yp_0 += 7){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h92, hp_0 = 0;
								h < h92 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w82, wp_0 = 0;
									w < w82 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x180, xp_1 = x180_p_0, xp_0 = 0;
										x < x180 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c162, cp_1 = c162_p_0, cp_0 = 0;
													c < c162 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_700);
													mem_vec_700 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_701);
													mem_vec_701 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_702);
													mem_vec_702 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_703);
													mem_vec_703 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_704);
													mem_vec_704 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_705);
													mem_vec_705 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_706);
													mem_vec_706 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_707);
													mem_vec_707 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_708);
													mem_vec_708 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_709);
													mem_vec_709 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_710);
													mem_vec_710 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_711);
													mem_vec_711 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_712);
													mem_vec_712 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_713);
													mem_vec_713 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_707);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_708);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_709);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_710);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_711);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_712);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_713);
									}
								}
							}
						}
						for (y = y108 + 35, yp_0 = 0;
							y < y108 + 35 + 33;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h92, hp_0 = 0;
								h < h92 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w82, wp_0 = 0;
									w < w82 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x180, xp_1 = x180_p_0, xp_0 = 0;
										x < x180 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c162, cp_1 = c162_p_0, cp_0 = 0;
													c < c162 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_714);
													mem_vec_714 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_715);
													mem_vec_715 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_716);
													mem_vec_716 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_717);
													mem_vec_717 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_718);
													mem_vec_718 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_719);
													mem_vec_719 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_720);
													mem_vec_720 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_721);
													mem_vec_721 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_722);
													mem_vec_722 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_723);
													mem_vec_723 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_724);
													mem_vec_724 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_725);
													mem_vec_725 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_726);
													mem_vec_726 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_727);
													mem_vec_727 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_728);
													mem_vec_728 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_729);
													mem_vec_729 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_730);
													mem_vec_730 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_731);
													mem_vec_731 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_732);
													mem_vec_732 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_733);
													mem_vec_733 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_734);
													mem_vec_734 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_735);
													mem_vec_735 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_714);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_715);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_716);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_717);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_718);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_719);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_720);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_721);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_722);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_723);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_724);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_725);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_726);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_727);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_728);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_729);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_730);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_731);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_732);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_733);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_734);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_735);
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