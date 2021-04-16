#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (4, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 1), (Arg 11))]; T (2, x)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x104_p_0, x105_p_0, xp_1, x104_p_1, xp_2, x104, x105, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y60 = 0;
IND_TYPE x106 = 0;
IND_TYPE h49 = 0;
IND_TYPE w56 = 0;
IND_TYPE c91 = 0;
IND_TYPE f80 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (56 / 28)
for (x105 = x106, x105_p_0 = 0;
	x105 < x106 + 56;
	x105 += 28, x105_p_0 += 28){
		for (y = y60, yp_0 = 0;
			y < y60 + 45;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x104 = x105, x104_p_1 = x105_p_0, x104_p_0 = 0;
				x104 < x105 + 28;
				x104 += 28, x104_p_1 += 28, x104_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f80, fp_0 = 0;
					f < f80 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c90 = c91, c90_p_0 = 0;
						c90 < c91 + 128;
						c90 += 32, c90_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w56, wp_0 = 0;
							w < w56 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x104, xp_2 = x104_p_1, xp_1 = x104_p_0, xp_0 = 0;
								x < x104 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h49, hp_0 = 0;
									h < h49 + 3;
									h += 1, hp_0 += 1){
											mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_640);
												mem_vec_640 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_641);
												mem_vec_641 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_642);
												mem_vec_642 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_643);
												mem_vec_643 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_644);
												mem_vec_644 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_645);
												mem_vec_645 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_646);
												mem_vec_646 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_647);
												mem_vec_647 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_648);
												mem_vec_648 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_649);
												mem_vec_649 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_650);
												mem_vec_650 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_651);
												mem_vec_651 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_652);
												mem_vec_652 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_653);
												mem_vec_653 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_654);
												mem_vec_654 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_655);
												mem_vec_655 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_656);
												mem_vec_656 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_657);
												mem_vec_657 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_640);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_641);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_642);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_643);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_644);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_645);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_646);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_647);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_648);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_649);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_650);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_651);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_652);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_653);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_655);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_656);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_657);
								}
							}
						}
					}
				}
			}
		}
		for (y = y60 + 45, yp_0 = 0;
			y < y60 + 45 + 11;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 1) (28 / 28)
			for (x104 = x105, x104_p_1 = x105_p_0, x104_p_0 = 0;
				x104 < x105 + 28;
				x104 += 28, x104_p_1 += 28, x104_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f80, fp_0 = 0;
					f < f80 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c90 = c91, c90_p_0 = 0;
						c90 < c91 + 128;
						c90 += 32, c90_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w56, wp_0 = 0;
							w < w56 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x104, xp_2 = x104_p_1, xp_1 = x104_p_0, xp_0 = 0;
								x < x104 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h49, hp_0 = 0;
									h < h49 + 3;
									h += 1, hp_0 += 1){
											mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_658);
												mem_vec_658 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_659);
												mem_vec_659 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_660);
												mem_vec_660 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_661);
												mem_vec_661 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_662);
												mem_vec_662 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_663);
												mem_vec_663 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_664);
												mem_vec_664 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_665);
												mem_vec_665 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_666);
												mem_vec_666 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_667);
												mem_vec_667 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_668);
												mem_vec_668 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_669);
												mem_vec_669 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_670);
												mem_vec_670 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_671);
												mem_vec_671 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_672);
												mem_vec_672 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_673);
												mem_vec_673 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_674);
												mem_vec_674 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_675);
												mem_vec_675 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_676);
												mem_vec_676 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_677);
												mem_vec_677 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_678);
												mem_vec_678 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_679);
												mem_vec_679 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_658);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_659);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_660);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_661);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_662);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_663);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_664);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_665);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_666);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_667);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_668);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_669);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_670);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_671);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_672);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_673);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_674);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_675);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_676);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_677);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_678);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_679);
								}
							}
						}
					}
				}
			}
		}
}


}