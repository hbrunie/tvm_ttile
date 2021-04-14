#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (2, f);
  T (4, c); T (1, x)]
*/
IND_TYPE c, cp_0, c398_p_0, cp_1, c398, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x386_p_0, x387_p_0, xp_1, x386_p_1, xp_2, x386, x387, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y224 = 0;
IND_TYPE x388 = 0;
IND_TYPE h188 = 0;
IND_TYPE w200 = 0;
IND_TYPE c399 = 0;
IND_TYPE f162 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2592 ,mem_vec_2593 ,mem_vec_2594 ,mem_vec_2595 ,mem_vec_2596 ,mem_vec_2597 ,mem_vec_2598 ,mem_vec_2599 ,mem_vec_2600 ,mem_vec_2601 ,mem_vec_2602 ,mem_vec_2603 ,mem_vec_2604 ,mem_vec_2605 ,mem_vec_2606 ,mem_vec_2607 ,mem_vec_2608 ,mem_vec_2609 ,mem_vec_2610 ,mem_vec_2611 ,mem_vec_2612 ,mem_vec_2613 ,mem_vec_2614 ,mem_vec_2615 ,mem_vec_2616 ,mem_vec_2617 ,mem_vec_2618 ,mem_vec_2619 ,mem_vec_2620 ,mem_vec_2621 ,mem_vec_2622 ,mem_vec_2623 ,mem_vec_2624 ,mem_vec_2625 ,mem_vec_2626 ,mem_vec_2627 ,mem_vec_2628 ,mem_vec_2629 ,mem_vec_2630 ,mem_vec_2631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x387 = x388, x387_p_0 = 0;
	x387 < x388 + 56;
	x387 += 56, x387_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 4) (64 / 16)
	for (c398 = c399, c398_p_0 = 0;
		c398 < c399 + 64;
		c398 += 16, c398_p_0 += 16){
		// y = 56, x = 56, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f162, fp_0 = 0;
			f < f162 + 64;
			f += 32, fp_0 += 32){
				for (y = y224, yp_0 = 0;
					y < y224 + 45;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
					// T (x, 7) (56 / 8)
					for (x386 = x387, x386_p_1 = x387_p_0, x386_p_0 = 0;
						x386 < x387 + 56;
						x386 += 8, x386_p_1 += 8, x386_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h188, hp_0 = 0;
							h < h188 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w200, wp_0 = 0;
								w < w200 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x386, xp_2 = x386_p_1, xp_1 = x386_p_0, xp_0 = 0;
									x < x386 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2592 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2593 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c398, cp_1 = c398_p_0, cp_0 = 0;
												c < c398 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2592);
												mem_vec_2592 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2593);
												mem_vec_2593 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2594);
												mem_vec_2594 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2595);
												mem_vec_2595 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2596);
												mem_vec_2596 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2597);
												mem_vec_2597 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2598);
												mem_vec_2598 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2599);
												mem_vec_2599 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2600);
												mem_vec_2600 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2601);
												mem_vec_2601 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2602);
												mem_vec_2602 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2603);
												mem_vec_2603 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2604);
												mem_vec_2604 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2605);
												mem_vec_2605 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2606);
												mem_vec_2606 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2607);
												mem_vec_2607 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2608);
												mem_vec_2608 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2609);
												mem_vec_2609 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2592);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2593);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2594);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2595);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2596);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2597);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2598);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2599);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2600);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2601);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2602);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2603);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2604);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2605);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2606);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2607);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2608);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2609);
								}
							}
						}
					}
				}
				for (y = y224 + 45, yp_0 = 0;
					y < y224 + 45 + 11;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
					// T (x, 7) (56 / 8)
					for (x386 = x387, x386_p_1 = x387_p_0, x386_p_0 = 0;
						x386 < x387 + 56;
						x386 += 8, x386_p_1 += 8, x386_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h188, hp_0 = 0;
							h < h188 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w200, wp_0 = 0;
								w < w200 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 16, f = 32
								// T (x, 8) (8 / 1)
								for (x = x386, xp_2 = x386_p_1, xp_1 = x386_p_0, xp_0 = 0;
									x < x386 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2610 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2611 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c398, cp_1 = c398_p_0, cp_0 = 0;
												c < c398 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2610);
												mem_vec_2610 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2611);
												mem_vec_2611 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2612);
												mem_vec_2612 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2613);
												mem_vec_2613 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2614);
												mem_vec_2614 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2615);
												mem_vec_2615 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2616);
												mem_vec_2616 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2617);
												mem_vec_2617 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2618);
												mem_vec_2618 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2619);
												mem_vec_2619 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2620);
												mem_vec_2620 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2621);
												mem_vec_2621 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2622);
												mem_vec_2622 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2623);
												mem_vec_2623 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2624);
												mem_vec_2624 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2625);
												mem_vec_2625 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2626);
												mem_vec_2626 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2627);
												mem_vec_2627 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2628);
												mem_vec_2628 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2629);
												mem_vec_2629 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2630);
												mem_vec_2630 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2631);
												mem_vec_2631 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2610);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2611);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2612);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2613);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2614);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2615);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2629);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2631);
								}
							}
						}
					}
				}
		}
	}
}


}