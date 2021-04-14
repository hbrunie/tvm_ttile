#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))];
  T (4, f); T (16, c); T (1, f); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c906_p_0, cp_1, c906, f, fp_0, f1208_p_0, f1209_p_0, fp_1, f1208_p_1, fp_2, f1208, f1209, h, hp_0, w, wp_0, x, xp_0, x958_p_0, xp_1, x958, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y604 = 0;
IND_TYPE x959 = 0;
IND_TYPE h604 = 0;
IND_TYPE w552 = 0;
IND_TYPE c907 = 0;
IND_TYPE f1210 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11628 ,mem_vec_11629 ,mem_vec_11630 ,mem_vec_11631 ,mem_vec_11632 ,mem_vec_11633 ,mem_vec_11634 ,mem_vec_11635 ,mem_vec_11636 ,mem_vec_11637 ,mem_vec_11638 ,mem_vec_11639 ,mem_vec_11640 ,mem_vec_11641 ,mem_vec_11642 ,mem_vec_11643 ,mem_vec_11644 ,mem_vec_11645 ,mem_vec_11646 ,mem_vec_11647 ,mem_vec_11648 ,mem_vec_11649 ,mem_vec_11650 ,mem_vec_11651 ,mem_vec_11652 ,mem_vec_11653 ,mem_vec_11654 ,mem_vec_11655 ,mem_vec_11656 ,mem_vec_11657 ,mem_vec_11658 ,mem_vec_11659 ,mem_vec_11660 ,mem_vec_11661 ,mem_vec_11662 ,mem_vec_11663 ,mem_vec_11664 ,mem_vec_11665 ,mem_vec_11666 ,mem_vec_11667 ,mem_vec_11668 ,mem_vec_11669 ,mem_vec_11670 ,mem_vec_11671 ,mem_vec_11672 ,mem_vec_11673 ,mem_vec_11674 ,mem_vec_11675 ,mem_vec_11676 ,mem_vec_11677 ,mem_vec_11678 ,mem_vec_11679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1209 = f1210, f1209_p_0 = 0;
	f1209 < f1210 + 256;
	f1209 += 128, f1209_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 17) (68 / 4)
	for (x958 = x959, x958_p_0 = 0;
		x958 < x959 + 68;
		x958 += 4, x958_p_0 += 4){
		// y = 68, x = 4, h = 3, w = 3, c = 128, f = 128
		// T (f, 1) (128 / 128)
		for (f1208 = f1209, f1208_p_1 = f1209_p_0, f1208_p_0 = 0;
			f1208 < f1209 + 128;
			f1208 += 128, f1208_p_1 += 128, f1208_p_0 += 128){
			// y = 68, x = 4, h = 3, w = 3, c = 128, f = 128
			// T (c, 16) (128 / 8)
			for (c906 = c907, c906_p_0 = 0;
				c906 < c907 + 128;
				c906 += 8, c906_p_0 += 8){
				// y = 68, x = 4, h = 3, w = 3, c = 8, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
					f < f1208 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y604, yp_0 = 0;
							y < y604 + 12;
							y += 12, yp_0 += 12){
							// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h604, hp_0 = 0;
								h < h604 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w552, wp_0 = 0;
									w < w552 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x958, xp_1 = x958_p_0, xp_0 = 0;
										x < x958 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11628 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11629 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c906, cp_1 = c906_p_0, cp_0 = 0;
													c < c906 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11628);
													mem_vec_11628 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11629);
													mem_vec_11629 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11630);
													mem_vec_11630 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11631);
													mem_vec_11631 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11632);
													mem_vec_11632 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11633);
													mem_vec_11633 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11634);
													mem_vec_11634 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11635);
													mem_vec_11635 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11636);
													mem_vec_11636 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11637);
													mem_vec_11637 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11638);
													mem_vec_11638 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11639);
													mem_vec_11639 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11640);
													mem_vec_11640 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11641);
													mem_vec_11641 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11642);
													mem_vec_11642 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11643);
													mem_vec_11643 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11644);
													mem_vec_11644 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11645);
													mem_vec_11645 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11646);
													mem_vec_11646 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11647);
													mem_vec_11647 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11648);
													mem_vec_11648 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11649);
													mem_vec_11649 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11650);
													mem_vec_11650 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11651);
													mem_vec_11651 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11628);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11629);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11630);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11631);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11632);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11633);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11634);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11635);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11636);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11637);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11638);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11639);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11640);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11641);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11642);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11643);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11644);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11645);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11646);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11647);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11648);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11649);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11650);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11651);
									}
								}
							}
						}
						for (y = y604 + 12, yp_0 = 0;
							y < y604 + 12 + 56;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h604, hp_0 = 0;
								h < h604 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w552, wp_0 = 0;
									w < w552 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x958, xp_1 = x958_p_0, xp_0 = 0;
										x < x958 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11652 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11653 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_11668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_11670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_11672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_11674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_11676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_11677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_11678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_11679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c906, cp_1 = c906_p_0, cp_0 = 0;
													c < c906 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11652);
													mem_vec_11652 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11653);
													mem_vec_11653 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11654);
													mem_vec_11654 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11655);
													mem_vec_11655 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11656);
													mem_vec_11656 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11657);
													mem_vec_11657 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11658);
													mem_vec_11658 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11659);
													mem_vec_11659 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11660);
													mem_vec_11660 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11661);
													mem_vec_11661 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11662);
													mem_vec_11662 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11663);
													mem_vec_11663 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11664);
													mem_vec_11664 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11665);
													mem_vec_11665 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11666);
													mem_vec_11666 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11667);
													mem_vec_11667 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11668);
													mem_vec_11668 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11669);
													mem_vec_11669 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11670);
													mem_vec_11670 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11671);
													mem_vec_11671 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11672);
													mem_vec_11672 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11673);
													mem_vec_11673 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11674);
													mem_vec_11674 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11675);
													mem_vec_11675 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11676);
													mem_vec_11676 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11677);
													mem_vec_11677 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11678);
													mem_vec_11678 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11679);
													mem_vec_11679 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11652);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11653);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11654);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11655);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11656);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11657);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11658);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11659);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11663);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11664);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11665);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11666);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11667);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_11678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_11679);
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