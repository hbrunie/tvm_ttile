#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (2, c);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (272, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x66_p_0, xp_1, x66, y, yp_0, y66_p_0, yp_1, y66;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y67 = 0;
IND_TYPE x67 = 0;
IND_TYPE h29 = 0;
IND_TYPE w38 = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 2) (272 / 136)
for (y66 = y67, y66_p_0 = 0;
	y66 < y67 + 272;
	y66 += 136, y66_p_0 += 136){
	// y = 136, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x66 = x67, x66_p_0 = 0;
		x66 < x67 + 272;
		x66 += 1, x66_p_0 += 1){
			for (y = y66, yp_1 = y66_p_0, yp_0 = 0;
				y < y66 + 70;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c57 = c58, c57_p_0 = 0;
					c57 < c58 + 32;
					c57 += 16, c57_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f38, fp_0 = 0;
						f < f38 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x66, xp_1 = x66_p_0, xp_0 = 0;
							x < x66 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h29, hp_0 = 0;
								h < h29 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w38, wp_0 = 0;
									w < w38 + 3;
									w += 1, wp_0 += 1){
											mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
												c < c57 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_615);
												mem_vec_615 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_616);
												mem_vec_616 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_617);
												mem_vec_617 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_618);
												mem_vec_618 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_619);
												mem_vec_619 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_620);
												mem_vec_620 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_621);
												mem_vec_621 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_622);
												mem_vec_622 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_623);
												mem_vec_623 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_624);
												mem_vec_624 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_625);
												mem_vec_625 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_626);
												mem_vec_626 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_627);
												mem_vec_627 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_628);
												mem_vec_628 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_629);
												mem_vec_629 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_630);
												mem_vec_630 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_631);
												mem_vec_631 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_632);
												mem_vec_632 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_633);
												mem_vec_633 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_634);
												mem_vec_634 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_615);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_629);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_631);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_632);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_633);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_634);
								}
							}
						}
					}
				}
			}
			for (y = y66 + 70, yp_1 = y66_p_0, yp_0 = 0;
				y < y66 + 70 + 66;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c57 = c58, c57_p_0 = 0;
					c57 < c58 + 32;
					c57 += 16, c57_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f38, fp_0 = 0;
						f < f38 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x66, xp_1 = x66_p_0, xp_0 = 0;
							x < x66 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h29, hp_0 = 0;
								h < h29 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w38, wp_0 = 0;
									w < w38 + 3;
									w += 1, wp_0 += 1){
											mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
												c < c57 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_635);
												mem_vec_635 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_636);
												mem_vec_636 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_637);
												mem_vec_637 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_638);
												mem_vec_638 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_639);
												mem_vec_639 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_640);
												mem_vec_640 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_641);
												mem_vec_641 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_642);
												mem_vec_642 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_643);
												mem_vec_643 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_644);
												mem_vec_644 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_645);
												mem_vec_645 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_646);
												mem_vec_646 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_647);
												mem_vec_647 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_648);
												mem_vec_648 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_649);
												mem_vec_649 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_650);
												mem_vec_650 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_651);
												mem_vec_651 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_652);
												mem_vec_652 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_653);
												mem_vec_653 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_654);
												mem_vec_654 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_655);
												mem_vec_655 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_656);
												mem_vec_656 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_635);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_636);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_637);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_638);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_639);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_640);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_641);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_642);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_643);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_644);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_645);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_646);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_647);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_648);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_649);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_650);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_651);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_652);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_653);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_655);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_656);
								}
							}
						}
					}
				}
			}
	}
}


}