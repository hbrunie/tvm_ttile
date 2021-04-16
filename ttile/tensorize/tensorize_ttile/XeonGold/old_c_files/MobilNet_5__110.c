#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (4, c); T (1, x); T (1, y); T (8, f); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x518_p_0, x519_p_0, xp_1, x518_p_1, xp_2, x518, x519, y, yp_0, y369_p_0, yp_1, y369;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y370 = 0;
IND_TYPE x520 = 0;
IND_TYPE h316 = 0;
IND_TYPE w216 = 0;
IND_TYPE c496 = 0;
IND_TYPE f582 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4634 ,mem_vec_4635 ,mem_vec_4636 ,mem_vec_4637 ,mem_vec_4638 ,mem_vec_4639 ,mem_vec_4640 ,mem_vec_4641 ,mem_vec_4642 ,mem_vec_4643 ,mem_vec_4644 ,mem_vec_4645 ,mem_vec_4646 ,mem_vec_4647 ,mem_vec_4648 ,mem_vec_4649 ,mem_vec_4650 ,mem_vec_4651 ,mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,mem_vec_4668 ,mem_vec_4669 ,mem_vec_4670 ,mem_vec_4671 ,mem_vec_4672 ,mem_vec_4673 ,mem_vec_4674 ,mem_vec_4675 ,mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,mem_vec_4680 ,mem_vec_4681 ,mem_vec_4682 ,mem_vec_4683 ,mem_vec_4684 ,mem_vec_4685 ,mem_vec_4686 ,mem_vec_4687 ,mem_vec_4688 ,mem_vec_4689 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y369 = y370, y369_p_0 = 0;
		y369 < y370 + 13;
		y369 += 13, y369_p_0 += 13){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (x, 4) (28 / 7)
		for (x519 = x520, x519_p_0 = 0;
			x519 < x520 + 28;
			x519 += 7, x519_p_0 += 7){
			// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 256
			// T (f, 8) (256 / 32)
			for (f = f582, fp_0 = 0;
				f < f582 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y369, yp_1 = y369_p_0, yp_0 = 0;
					y < y369 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (7 / 7)
					for (x518 = x519, x518_p_1 = x519_p_0, x518_p_0 = 0;
						x518 < x519 + 7;
						x518 += 7, x518_p_1 += 7, x518_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c495 = c496, c495_p_0 = 0;
							c495 < c496 + 256;
							c495 += 64, c495_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w216, wp_0 = 0;
								w < w216 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x518, xp_2 = x518_p_1, xp_1 = x518_p_0, xp_0 = 0;
									x < x518 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
									// T (h, 3) (3 / 1)
									for (h = h316, hp_0 = 0;
										h < h316 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4634 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4635 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_4650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_4651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_4652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_4653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_4654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_4655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_4656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_4657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_4658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_4659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
													c < c495 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4634);
													mem_vec_4634 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4635);
													mem_vec_4635 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4636);
													mem_vec_4636 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4637);
													mem_vec_4637 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4638);
													mem_vec_4638 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4639);
													mem_vec_4639 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4640);
													mem_vec_4640 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4641);
													mem_vec_4641 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4642);
													mem_vec_4642 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4643);
													mem_vec_4643 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4644);
													mem_vec_4644 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4645);
													mem_vec_4645 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4646);
													mem_vec_4646 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4647);
													mem_vec_4647 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4648);
													mem_vec_4648 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4649);
													mem_vec_4649 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4650);
													mem_vec_4650 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4651);
													mem_vec_4651 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4652);
													mem_vec_4652 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4653);
													mem_vec_4653 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4654);
													mem_vec_4654 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4655);
													mem_vec_4655 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4656);
													mem_vec_4656 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4657);
													mem_vec_4657 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4658);
													mem_vec_4658 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4659);
													mem_vec_4659 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4634);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4635);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4636);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4637);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4638);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4639);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4640);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4641);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4642);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4643);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4644);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4645);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4646);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4647);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4648);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4649);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4650);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4651);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4652);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4653);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4654);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4655);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4656);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4657);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4658);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4659);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y369 = y370 + 13, y369_p_0 = 0;
		y369 < y370 + 13 + 15;
		y369 += 15, y369_p_0 += 15){
		// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (x, 4) (28 / 7)
		for (x519 = x520, x519_p_0 = 0;
			x519 < x520 + 28;
			x519 += 7, x519_p_0 += 7){
			// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 256
			// T (f, 8) (256 / 32)
			for (f = f582, fp_0 = 0;
				f < f582 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y369, yp_1 = y369_p_0, yp_0 = 0;
					y < y369 + 15;
					y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (7 / 7)
					for (x518 = x519, x518_p_1 = x519_p_0, x518_p_0 = 0;
						x518 < x519 + 7;
						x518 += 7, x518_p_1 += 7, x518_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c495 = c496, c495_p_0 = 0;
							c495 < c496 + 256;
							c495 += 64, c495_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w216, wp_0 = 0;
								w < w216 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x518, xp_2 = x518_p_1, xp_1 = x518_p_0, xp_0 = 0;
									x < x518 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
									// T (h, 3) (3 / 1)
									for (h = h316, hp_0 = 0;
										h < h316 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_4676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_4677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_4678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_4679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_4680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_4681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_4682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_4683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_4684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_4685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_4686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_4687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_4688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_4689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
													c < c495 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4660);
													mem_vec_4660 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4661);
													mem_vec_4661 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4662);
													mem_vec_4662 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4663);
													mem_vec_4663 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4664);
													mem_vec_4664 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4665);
													mem_vec_4665 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4666);
													mem_vec_4666 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4667);
													mem_vec_4667 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4668);
													mem_vec_4668 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4669);
													mem_vec_4669 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4670);
													mem_vec_4670 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4671);
													mem_vec_4671 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4672);
													mem_vec_4672 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4673);
													mem_vec_4673 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4674);
													mem_vec_4674 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4675);
													mem_vec_4675 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4676);
													mem_vec_4676 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4677);
													mem_vec_4677 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4678);
													mem_vec_4678 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4679);
													mem_vec_4679 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4680);
													mem_vec_4680 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4681);
													mem_vec_4681 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4682);
													mem_vec_4682 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4683);
													mem_vec_4683 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4684);
													mem_vec_4684 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4685);
													mem_vec_4685 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4686);
													mem_vec_4686 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4687);
													mem_vec_4687 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_4688);
													mem_vec_4688 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_4689);
													mem_vec_4689 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4663);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4664);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4665);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4666);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4667);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4679);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_4686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_4687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_4688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_4689);
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