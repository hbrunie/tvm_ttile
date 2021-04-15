#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 7)); ((Iter 3), (Arg 11))];
  T (1, f); T (32, c); T (1, f); T (4, x); T (8, f)]
*/
IND_TYPE c, cp_0, c156_p_0, cp_1, c156, f, fp_0, f208_p_0, f209_p_0, fp_1, f208_p_1, fp_2, f208, f209, h, hp_0, w, wp_0, x, xp_0, x174_p_0, xp_1, x174, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y104 = 0;
IND_TYPE x175 = 0;
IND_TYPE h88 = 0;
IND_TYPE w78 = 0;
IND_TYPE c157 = 0;
IND_TYPE f210 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f209 = f210, f209_p_0 = 0;
	f209 < f210 + 256;
	f209 += 32, f209_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 4) (68 / 17)
	for (x174 = x175, x174_p_0 = 0;
		x174 < x175 + 68;
		x174 += 17, x174_p_0 += 17){
		// y = 68, x = 17, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f208 = f209, f208_p_1 = f209_p_0, f208_p_0 = 0;
			f208 < f209 + 32;
			f208 += 32, f208_p_1 += 32, f208_p_0 += 32){
			// y = 68, x = 17, h = 3, w = 3, c = 128, f = 32
			// T (c, 32) (128 / 4)
			for (c156 = c157, c156_p_0 = 0;
				c156 < c157 + 128;
				c156 += 4, c156_p_0 += 4){
				// y = 68, x = 17, h = 3, w = 3, c = 4, f = 32
				// T (f, 1) (32 / 32)
				for (f = f208, fp_2 = f208_p_1, fp_1 = f208_p_0, fp_0 = 0;
					f < f208 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y104, yp_0 = 0;
							y < y104 + 35;
							y += 7, yp_0 += 7){
							// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h88, hp_0 = 0;
								h < h88 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w78, wp_0 = 0;
									w < w78 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
									// T (x, 17) (17 / 1)
									for (x = x174, xp_1 = x174_p_0, xp_0 = 0;
										x < x174 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
													c < c156 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_628);
													mem_vec_628 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_629);
													mem_vec_629 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_630);
													mem_vec_630 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_631);
													mem_vec_631 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_632);
													mem_vec_632 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_633);
													mem_vec_633 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_634);
													mem_vec_634 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_635);
													mem_vec_635 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_636);
													mem_vec_636 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_637);
													mem_vec_637 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_638);
													mem_vec_638 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_639);
													mem_vec_639 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_640);
													mem_vec_640 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_641);
													mem_vec_641 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_628);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_629);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_630);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_631);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_632);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_633);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_634);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_635);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_636);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_637);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_638);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_639);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_640);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_641);
									}
								}
							}
						}
						for (y = y104 + 35, yp_0 = 0;
							y < y104 + 35 + 33;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h88, hp_0 = 0;
								h < h88 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w78, wp_0 = 0;
									w < w78 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
									// T (x, 17) (17 / 1)
									for (x = x174, xp_1 = x174_p_0, xp_0 = 0;
										x < x174 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
													c < c156 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_642);
													mem_vec_642 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_643);
													mem_vec_643 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_644);
													mem_vec_644 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_645);
													mem_vec_645 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_646);
													mem_vec_646 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_647);
													mem_vec_647 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_648);
													mem_vec_648 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_649);
													mem_vec_649 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_650);
													mem_vec_650 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_651);
													mem_vec_651 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_652);
													mem_vec_652 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_653);
													mem_vec_653 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_654);
													mem_vec_654 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_655);
													mem_vec_655 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_656);
													mem_vec_656 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_657);
													mem_vec_657 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_658);
													mem_vec_658 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_659);
													mem_vec_659 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_660);
													mem_vec_660 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_661);
													mem_vec_661 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_662);
													mem_vec_662 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_663);
													mem_vec_663 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_642);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_643);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_644);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_645);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_646);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_647);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_648);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_649);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_650);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_651);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_652);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_653);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_654);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_655);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_656);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_657);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_658);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_659);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_663);
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