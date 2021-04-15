#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (68, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (4, f);
  T (8, c); T (2, x)]
*/
IND_TYPE c, cp_0, c732_p_0, cp_1, c732, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x976_p_0, x977_p_0, xp_1, x976_p_1, xp_2, x976, x977, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y488 = 0;
IND_TYPE x978 = 0;
IND_TYPE h488 = 0;
IND_TYPE w458 = 0;
IND_TYPE c733 = 0;
IND_TYPE f488 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9612 ,mem_vec_9613 ,mem_vec_9614 ,mem_vec_9615 ,mem_vec_9616 ,mem_vec_9617 ,mem_vec_9618 ,mem_vec_9619 ,mem_vec_9620 ,mem_vec_9621 ,mem_vec_9622 ,mem_vec_9623 ,mem_vec_9624 ,mem_vec_9625 ,mem_vec_9626 ,mem_vec_9627 ,mem_vec_9628 ,mem_vec_9629 ,mem_vec_9630 ,mem_vec_9631 ,mem_vec_9632 ,mem_vec_9633 ,mem_vec_9634 ,mem_vec_9635 ,mem_vec_9636 ,mem_vec_9637 ,mem_vec_9638 ,mem_vec_9639 ,mem_vec_9640 ,mem_vec_9641 ,mem_vec_9642 ,mem_vec_9643 ,mem_vec_9644 ,mem_vec_9645 ,mem_vec_9646 ,mem_vec_9647 ,mem_vec_9648 ,mem_vec_9649 ,mem_vec_9650 ,mem_vec_9651 ,mem_vec_9652 ,mem_vec_9653 ,mem_vec_9654 ,mem_vec_9655 ,mem_vec_9656 ,mem_vec_9657 ,mem_vec_9658 ,mem_vec_9659 ,mem_vec_9660 ,mem_vec_9661 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x977 = x978, x977_p_0 = 0;
	x977 < x978 + 136;
	x977 += 68, x977_p_0 += 68){
	// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
	// T (c, 8) (64 / 8)
	for (c732 = c733, c732_p_0 = 0;
		c732 < c733 + 64;
		c732 += 8, c732_p_0 += 8){
		// y = 136, x = 68, h = 3, w = 3, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f488, fp_0 = 0;
			f < f488 + 128;
			f += 32, fp_0 += 32){
				for (y = y488, yp_0 = 0;
					y < y488 + 84;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
					// T (x, 68) (68 / 1)
					for (x976 = x977, x976_p_1 = x977_p_0, x976_p_0 = 0;
						x976 < x977 + 68;
						x976 += 1, x976_p_1 += 1, x976_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h488, hp_0 = 0;
							h < h488 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w458, wp_0 = 0;
								w < w458 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x976, xp_2 = x976_p_1, xp_1 = x976_p_0, xp_0 = 0;
									x < x976 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c732, cp_1 = c732_p_0, cp_0 = 0;
												c < c732 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9612);
												mem_vec_9612 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9613);
												mem_vec_9613 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9614);
												mem_vec_9614 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9615);
												mem_vec_9615 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9616);
												mem_vec_9616 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9617);
												mem_vec_9617 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9618);
												mem_vec_9618 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9619);
												mem_vec_9619 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9620);
												mem_vec_9620 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9621);
												mem_vec_9621 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9622);
												mem_vec_9622 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9623);
												mem_vec_9623 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9624);
												mem_vec_9624 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9625);
												mem_vec_9625 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9626);
												mem_vec_9626 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9627);
												mem_vec_9627 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9628);
												mem_vec_9628 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9629);
												mem_vec_9629 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9630);
												mem_vec_9630 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9631);
												mem_vec_9631 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9632);
												mem_vec_9632 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9633);
												mem_vec_9633 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9634);
												mem_vec_9634 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9635);
												mem_vec_9635 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9612);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9613);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9614);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9615);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9629);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9631);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9632);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9633);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9634);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9635);
								}
							}
						}
					}
				}
				for (y = y488 + 84, yp_0 = 0;
					y < y488 + 84 + 52;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 68, h = 3, w = 3, c = 8, f = 32
					// T (x, 68) (68 / 1)
					for (x976 = x977, x976_p_1 = x977_p_0, x976_p_0 = 0;
						x976 < x977 + 68;
						x976 += 1, x976_p_1 += 1, x976_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h488, hp_0 = 0;
							h < h488 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w458, wp_0 = 0;
								w < w458 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x976, xp_2 = x976_p_1, xp_1 = x976_p_0, xp_0 = 0;
									x < x976 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9636 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9637 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_9660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_9661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c732, cp_1 = c732_p_0, cp_0 = 0;
												c < c732 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9636);
												mem_vec_9636 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9637);
												mem_vec_9637 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9638);
												mem_vec_9638 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9639);
												mem_vec_9639 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9640);
												mem_vec_9640 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9641);
												mem_vec_9641 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9642);
												mem_vec_9642 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9643);
												mem_vec_9643 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9644);
												mem_vec_9644 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9645);
												mem_vec_9645 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9646);
												mem_vec_9646 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9647);
												mem_vec_9647 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9648);
												mem_vec_9648 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9649);
												mem_vec_9649 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9650);
												mem_vec_9650 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9651);
												mem_vec_9651 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9652);
												mem_vec_9652 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9653);
												mem_vec_9653 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9654);
												mem_vec_9654 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9655);
												mem_vec_9655 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9656);
												mem_vec_9656 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9657);
												mem_vec_9657 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9658);
												mem_vec_9658 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9659);
												mem_vec_9659 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9660);
												mem_vec_9660 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9661);
												mem_vec_9661 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9636);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9637);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9638);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9639);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9640);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9641);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9642);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9643);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9644);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9645);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9646);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9647);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9648);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9649);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9650);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9651);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9652);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9653);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9655);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9656);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9657);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9658);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9659);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9660);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9661);
								}
							}
						}
					}
				}
		}
	}
}


}