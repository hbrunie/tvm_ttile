#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (16, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (2, c); T (1, c)]
*/
IND_TYPE c, cp_0, c85_p_0, c86_p_0, c87_p_0, cp_1, c85_p_1, c86_p_1, cp_2, c85_p_2, cp_3, c85, c86, c87, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y34 = 0;
IND_TYPE x34 = 0;
IND_TYPE h28 = 0;
IND_TYPE w28 = 0;
IND_TYPE c88 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c87 = c88, c87_p_0 = 0;
	c87 < c88 + 512;
	c87 += 512, c87_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 2) (512 / 256)
	for (c86 = c87, c86_p_1 = c87_p_0, c86_p_0 = 0;
		c86 < c87 + 512;
		c86 += 256, c86_p_1 += 256, c86_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f34, fp_0 = 0;
			f < f34 + 1024;
			f += 32, fp_0 += 32){
				for (y = y34, yp_0 = 0;
					y < y34 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c85 = c86, c85_p_2 = c86_p_1, c85_p_1 = c86_p_0, c85_p_0 = 0;
						c85 < c86 + 256;
						c85 += 16, c85_p_2 += 16, c85_p_1 += 16, c85_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x34, xp_0 = 0;
							x < x34 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
											mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c85, cp_3 = c85_p_2, cp_2 = c85_p_1, cp_1 = c85_p_0, cp_0 = 0;
												c < c85 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_722);
												mem_vec_722 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_723);
												mem_vec_723 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_724);
												mem_vec_724 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_725);
												mem_vec_725 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_726);
												mem_vec_726 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_727);
												mem_vec_727 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_728);
												mem_vec_728 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_729);
												mem_vec_729 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_730);
												mem_vec_730 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_731);
												mem_vec_731 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_732);
												mem_vec_732 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_733);
												mem_vec_733 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_734);
												mem_vec_734 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_735);
												mem_vec_735 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_736);
												mem_vec_736 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_737);
												mem_vec_737 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_737);
								}
							}
						}
					}
				}
				for (y = y34 + 8, yp_0 = 0;
					y < y34 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c85 = c86, c85_p_2 = c86_p_1, c85_p_1 = c86_p_0, c85_p_0 = 0;
						c85 < c86 + 256;
						c85 += 16, c85_p_2 += 16, c85_p_1 += 16, c85_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x34, xp_0 = 0;
							x < x34 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
											mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c85, cp_3 = c85_p_2, cp_2 = c85_p_1, cp_1 = c85_p_0, cp_0 = 0;
												c < c85 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_738);
												mem_vec_738 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_739);
												mem_vec_739 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_740);
												mem_vec_740 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_741);
												mem_vec_741 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_742);
												mem_vec_742 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_743);
												mem_vec_743 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_744);
												mem_vec_744 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_745);
												mem_vec_745 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_746);
												mem_vec_746 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_747);
												mem_vec_747 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_748);
												mem_vec_748 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_749);
												mem_vec_749 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_750);
												mem_vec_750 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_751);
												mem_vec_751 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_752);
												mem_vec_752 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_753);
												mem_vec_753 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_754);
												mem_vec_754 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_755);
												mem_vec_755 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_755);
								}
							}
						}
					}
				}
		}
	}
}


}