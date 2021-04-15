#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (8, c); T (68, x); T (16, y); T (2, f); T (2, x)]
*/
IND_TYPE c, cp_0, c438_p_0, cp_1, c438, f, fp_0, f404_p_0, fp_1, f404, h, hp_0, w, wp_0, x, xp_0, x584_p_0, x585_p_0, xp_1, x584_p_1, xp_2, x584, x585, y, yp_0, y438_p_0, yp_1, y438;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y439 = 0;
IND_TYPE x586 = 0;
IND_TYPE h244 = 0;
IND_TYPE w242 = 0;
IND_TYPE c439 = 0;
IND_TYPE f405 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2608 ,mem_vec_2609 ,mem_vec_2610 ,mem_vec_2611 ,mem_vec_2612 ,mem_vec_2613 ,mem_vec_2614 ,mem_vec_2615 ,mem_vec_2616 ,mem_vec_2617 ,mem_vec_2618 ,mem_vec_2619 ,mem_vec_2620 ,mem_vec_2621 ,mem_vec_2622 ,mem_vec_2623 ,mem_vec_2624 ,mem_vec_2625 ,mem_vec_2626 ,mem_vec_2627 ,mem_vec_2628 ,mem_vec_2629 ,mem_vec_2630 ,mem_vec_2631 ,mem_vec_2632 ,mem_vec_2633 ,mem_vec_2634 ,mem_vec_2635 ,mem_vec_2636 ,mem_vec_2637 ,mem_vec_2638 ,mem_vec_2639 ,mem_vec_2640 ,mem_vec_2641 ,mem_vec_2642 ,mem_vec_2643 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x585 = x586, x585_p_0 = 0;
	x585 < x586 + 272;
	x585 += 136, x585_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (f, 2) (64 / 32)
	for (f404 = f405, f404_p_0 = 0;
		f404 < f405 + 64;
		f404 += 32, f404_p_0 += 32){
		// y = 272, x = 136, h = 3, w = 3, c = 32, f = 32
		// T (y, 16) (272 / 17)
		for (y438 = y439, y438_p_0 = 0;
			y438 < y439 + 272;
			y438 += 17, y438_p_0 += 17){
			// y = 17, x = 136, h = 3, w = 3, c = 32, f = 32
			// T (x, 68) (136 / 2)
			for (x584 = x585, x584_p_1 = x585_p_0, x584_p_0 = 0;
				x584 < x585 + 136;
				x584 += 2, x584_p_1 += 2, x584_p_0 += 2){
				// y = 17, x = 2, h = 3, w = 3, c = 32, f = 32
				// T (c, 8) (32 / 4)
				for (c438 = c439, c438_p_0 = 0;
					c438 < c439 + 32;
					c438 += 4, c438_p_0 += 4){
					// y = 17, x = 2, h = 3, w = 3, c = 4, f = 32
					// T (f, 1) (32 / 32)
					for (f = f404, fp_1 = f404_p_0, fp_0 = 0;
						f < f404 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
							for (y = y438, yp_1 = y438_p_0, yp_0 = 0;
								y < y438 + 12;
								y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h244, hp_0 = 0;
									h < h244 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
									// T (w, 3) (3 / 1)
									for (w = w242, wp_0 = 0;
										w < w242 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
										// T (x, 2) (2 / 1)
										for (x = x584, xp_2 = x584_p_1, xp_1 = x584_p_0, xp_0 = 0;
											x < x584 + 2;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2608 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2609 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2610 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2611 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
													// T (c, 4) (4 / 1)
													for (c = c438, cp_1 = c438_p_0, cp_0 = 0;
														c < c438 + 4;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2608);
														mem_vec_2608 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2609);
														mem_vec_2609 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2610);
														mem_vec_2610 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2611);
														mem_vec_2611 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2612);
														mem_vec_2612 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2613);
														mem_vec_2613 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2614);
														mem_vec_2614 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2615);
														mem_vec_2615 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2616);
														mem_vec_2616 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2617);
														mem_vec_2617 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2618);
														mem_vec_2618 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2619);
														mem_vec_2619 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2620);
														mem_vec_2620 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2621);
														mem_vec_2621 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2622);
														mem_vec_2622 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2623);
														mem_vec_2623 = vec_23;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2608);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2609);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2610);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2611);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2612);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2613);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2614);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2615);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2616);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2617);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2618);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2619);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2620);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2621);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2622);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2623);
										}
									}
								}
							}
							for (y = y438 + 12, yp_1 = y438_p_0, yp_0 = 0;
								y < y438 + 12 + 5;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h244, hp_0 = 0;
									h < h244 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
									// T (w, 3) (3 / 1)
									for (w = w242, wp_0 = 0;
										w < w242 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
										// T (x, 2) (2 / 1)
										for (x = x584, xp_2 = x584_p_1, xp_1 = x584_p_0, xp_0 = 0;
											x < x584 + 2;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2624 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2625 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													mem_vec_2640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
													mem_vec_2641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
													mem_vec_2642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
													mem_vec_2643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
													// T (c, 4) (4 / 1)
													for (c = c438, cp_1 = c438_p_0, cp_0 = 0;
														c < c438 + 4;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2624);
														mem_vec_2624 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2625);
														mem_vec_2625 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2626);
														mem_vec_2626 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2627);
														mem_vec_2627 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2628);
														mem_vec_2628 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2629);
														mem_vec_2629 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2630);
														mem_vec_2630 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2631);
														mem_vec_2631 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2632);
														mem_vec_2632 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2633);
														mem_vec_2633 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2634);
														mem_vec_2634 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2635);
														mem_vec_2635 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2636);
														mem_vec_2636 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2637);
														mem_vec_2637 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2638);
														mem_vec_2638 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2639);
														mem_vec_2639 = vec_23;
														scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);


														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2640);
														mem_vec_2640 = vec_24;



														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2641);
														mem_vec_2641 = vec_26;



														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2642);
														mem_vec_2642 = vec_27;



														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2643);
														mem_vec_2643 = vec_28;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2624);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2625);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2626);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2627);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2628);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2629);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2630);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2631);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2632);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2633);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2634);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2635);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2636);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2637);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2638);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2639);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2640);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2641);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2642);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2643);
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