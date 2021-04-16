#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (4, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c336_p_0, cp_1, c336, f, fp_0, x, xp_0, x560_p_0, x561_p_0, x562_p_0, xp_1, x560_p_1, x561_p_1, xp_2, x560_p_2, xp_3, x560, x561, x562, y, yp_0, y448_p_0, y449_p_0, yp_1, y448_p_1, yp_2, y448, y449;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y450 = 0;
IND_TYPE x563 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c337 = 0;
IND_TYPE f224 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3632 ,mem_vec_3633 ,mem_vec_3634 ,mem_vec_3635 ,mem_vec_3636 ,mem_vec_3637 ,mem_vec_3638 ,mem_vec_3639 ,mem_vec_3640 ,mem_vec_3641 ,mem_vec_3642 ,mem_vec_3643 ,mem_vec_3644 ,mem_vec_3645 ,mem_vec_3646 ,mem_vec_3647 ,mem_vec_3648 ,mem_vec_3649 ,mem_vec_3650 ,mem_vec_3651 ,mem_vec_3652 ,mem_vec_3653 ,mem_vec_3654 ,mem_vec_3655 ,mem_vec_3656 ,mem_vec_3657 ,mem_vec_3658 ,mem_vec_3659 ,mem_vec_3660 ,mem_vec_3661 ,mem_vec_3662 ,mem_vec_3663 ,mem_vec_3664 ,mem_vec_3665 ,mem_vec_3666 ,mem_vec_3667 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y449 = y450, y449_p_0 = 0;
		y449 < y450 + 96;
		y449 += 32, y449_p_0 += 32){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x562 = x563, x562_p_0 = 0;
			x562 < x563 + 136;
			x562 += 1, x562_p_0 += 1){
			// y = 4 * (2 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y448 = y449, y448_p_1 = y449_p_0, y448_p_0 = 0;
				y448 < y449 + 32;
				y448 += 8, y448_p_1 += 8, y448_p_0 += 8){
				// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x561 = x562, x561_p_1 = x562_p_0, x561_p_0 = 0;
					x561 < x562 + 1;
					x561 += 1, x561_p_1 += 1, x561_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f224, fp_0 = 0;
						f < f224 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y448, yp_2 = y448_p_1, yp_1 = y448_p_0, yp_0 = 0;
							y < y448 + 8;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x560 = x561, x560_p_2 = x561_p_1, x560_p_1 = x561_p_0, x560_p_0 = 0;
								x560 < x561 + 1;
								x560 += 1, x560_p_2 += 1, x560_p_1 += 1, x560_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c336 = c337, c336_p_0 = 0;
									c336 < c337 + 128;
									c336 += 32, c336_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x560, xp_3 = x560_p_2, xp_2 = x560_p_1, xp_1 = x560_p_0, xp_0 = 0;
										x < x560 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3632 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3633 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3634 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3635 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c336, cp_1 = c336_p_0, cp_0 = 0;
													c < c336 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3632);
													mem_vec_3632 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3633);
													mem_vec_3633 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3634);
													mem_vec_3634 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3635);
													mem_vec_3635 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3636);
													mem_vec_3636 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3637);
													mem_vec_3637 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3638);
													mem_vec_3638 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3639);
													mem_vec_3639 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3640);
													mem_vec_3640 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3641);
													mem_vec_3641 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3642);
													mem_vec_3642 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3643);
													mem_vec_3643 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3644);
													mem_vec_3644 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3645);
													mem_vec_3645 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3646);
													mem_vec_3646 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3647);
													mem_vec_3647 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3632);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3633);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3634);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3635);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3636);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3637);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3638);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3639);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3640);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3641);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3642);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3643);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3644);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3645);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3646);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3647);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y449 = y450 + 96, y449_p_0 = 0;
		y449 < y450 + 96 + 40;
		y449 += 40, y449_p_0 += 40){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x562 = x563, x562_p_0 = 0;
			x562 < x563 + 136;
			x562 += 1, x562_p_0 += 1){
			// y = 4 * (2 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y448 = y449, y448_p_1 = y449_p_0, y448_p_0 = 0;
				y448 < y449 + 40;
				y448 += 10, y448_p_1 += 10, y448_p_0 += 10){
				// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x561 = x562, x561_p_1 = x562_p_0, x561_p_0 = 0;
					x561 < x562 + 1;
					x561 += 1, x561_p_1 += 1, x561_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f224, fp_0 = 0;
						f < f224 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y448, yp_2 = y448_p_1, yp_1 = y448_p_0, yp_0 = 0;
							y < y448 + 10;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x560 = x561, x560_p_2 = x561_p_1, x560_p_1 = x561_p_0, x560_p_0 = 0;
								x560 < x561 + 1;
								x560 += 1, x560_p_2 += 1, x560_p_1 += 1, x560_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c336 = c337, c336_p_0 = 0;
									c336 < c337 + 128;
									c336 += 32, c336_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x560, xp_3 = x560_p_2, xp_2 = x560_p_1, xp_1 = x560_p_0, xp_0 = 0;
										x < x560 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3648 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3649 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3650 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3651 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_3664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c336, cp_1 = c336_p_0, cp_0 = 0;
													c < c336 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3648);
													mem_vec_3648 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3649);
													mem_vec_3649 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3650);
													mem_vec_3650 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3651);
													mem_vec_3651 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3652);
													mem_vec_3652 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3653);
													mem_vec_3653 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3654);
													mem_vec_3654 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3655);
													mem_vec_3655 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3656);
													mem_vec_3656 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3657);
													mem_vec_3657 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3658);
													mem_vec_3658 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3659);
													mem_vec_3659 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3660);
													mem_vec_3660 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3661);
													mem_vec_3661 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3662);
													mem_vec_3662 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3663);
													mem_vec_3663 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3664);
													mem_vec_3664 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3665);
													mem_vec_3665 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3666);
													mem_vec_3666 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3667);
													mem_vec_3667 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3648);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3649);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3650);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3651);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3652);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3653);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3654);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3655);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3656);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3657);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3658);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3659);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3660);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3661);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3662);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3663);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3664);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3665);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3666);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3667);
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