#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (4, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c333_p_0, cp_1, c333, f, fp_0, x, xp_0, x555_p_0, x556_p_0, x557_p_0, xp_1, x555_p_1, x556_p_1, xp_2, x555_p_2, xp_3, x555, x556, x557, y, yp_0, y444_p_0, y445_p_0, yp_1, y444_p_1, yp_2, y444, y445;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y446 = 0;
IND_TYPE x558 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c334 = 0;
IND_TYPE f222 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3596 ,mem_vec_3597 ,mem_vec_3598 ,mem_vec_3599 ,mem_vec_3600 ,mem_vec_3601 ,mem_vec_3602 ,mem_vec_3603 ,mem_vec_3604 ,mem_vec_3605 ,mem_vec_3606 ,mem_vec_3607 ,mem_vec_3608 ,mem_vec_3609 ,mem_vec_3610 ,mem_vec_3611 ,mem_vec_3612 ,mem_vec_3613 ,mem_vec_3614 ,mem_vec_3615 ,mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,mem_vec_3624 ,mem_vec_3625 ,mem_vec_3626 ,mem_vec_3627 ,mem_vec_3628 ,mem_vec_3629 ,mem_vec_3630 ,mem_vec_3631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y445 = y446, y445_p_0 = 0;
		y445 < y446 + 96;
		y445 += 32, y445_p_0 += 32){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x557 = x558, x557_p_0 = 0;
			x557 < x558 + 136;
			x557 += 1, x557_p_0 += 1){
			// y = 4 * (2 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y444 = y445, y444_p_1 = y445_p_0, y444_p_0 = 0;
				y444 < y445 + 32;
				y444 += 8, y444_p_1 += 8, y444_p_0 += 8){
				// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x556 = x557, x556_p_1 = x557_p_0, x556_p_0 = 0;
					x556 < x557 + 1;
					x556 += 1, x556_p_1 += 1, x556_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f222, fp_0 = 0;
						f < f222 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y444, yp_2 = y444_p_1, yp_1 = y444_p_0, yp_0 = 0;
							y < y444 + 8;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x555 = x556, x555_p_2 = x556_p_1, x555_p_1 = x556_p_0, x555_p_0 = 0;
								x555 < x556 + 1;
								x555 += 1, x555_p_2 += 1, x555_p_1 += 1, x555_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c333 = c334, c333_p_0 = 0;
									c333 < c334 + 128;
									c333 += 64, c333_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x555, xp_3 = x555_p_2, xp_2 = x555_p_1, xp_1 = x555_p_0, xp_0 = 0;
										x < x555 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3596 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3597 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3598 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3599 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c333, cp_1 = c333_p_0, cp_0 = 0;
													c < c333 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3596);
													mem_vec_3596 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3597);
													mem_vec_3597 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3598);
													mem_vec_3598 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3599);
													mem_vec_3599 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3600);
													mem_vec_3600 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3601);
													mem_vec_3601 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3602);
													mem_vec_3602 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3603);
													mem_vec_3603 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3604);
													mem_vec_3604 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3605);
													mem_vec_3605 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3606);
													mem_vec_3606 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3607);
													mem_vec_3607 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3608);
													mem_vec_3608 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3609);
													mem_vec_3609 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3610);
													mem_vec_3610 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3611);
													mem_vec_3611 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3599);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3601);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3602);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3603);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3604);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3605);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3606);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3607);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3611);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y445 = y446 + 96, y445_p_0 = 0;
		y445 < y446 + 96 + 40;
		y445 += 40, y445_p_0 += 40){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x557 = x558, x557_p_0 = 0;
			x557 < x558 + 136;
			x557 += 1, x557_p_0 += 1){
			// y = 4 * (2 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y444 = y445, y444_p_1 = y445_p_0, y444_p_0 = 0;
				y444 < y445 + 40;
				y444 += 10, y444_p_1 += 10, y444_p_0 += 10){
				// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x556 = x557, x556_p_1 = x557_p_0, x556_p_0 = 0;
					x556 < x557 + 1;
					x556 += 1, x556_p_1 += 1, x556_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f222, fp_0 = 0;
						f < f222 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y444, yp_2 = y444_p_1, yp_1 = y444_p_0, yp_0 = 0;
							y < y444 + 10;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x555 = x556, x555_p_2 = x556_p_1, x555_p_1 = x556_p_0, x555_p_0 = 0;
								x555 < x556 + 1;
								x555 += 1, x555_p_2 += 1, x555_p_1 += 1, x555_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c333 = c334, c333_p_0 = 0;
									c333 < c334 + 128;
									c333 += 64, c333_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x555, xp_3 = x555_p_2, xp_2 = x555_p_1, xp_1 = x555_p_0, xp_0 = 0;
										x < x555 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3612 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3613 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3614 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3615 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_3628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c333, cp_1 = c333_p_0, cp_0 = 0;
													c < c333 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3612);
													mem_vec_3612 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3613);
													mem_vec_3613 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3614);
													mem_vec_3614 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3615);
													mem_vec_3615 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3616);
													mem_vec_3616 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3617);
													mem_vec_3617 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3618);
													mem_vec_3618 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3619);
													mem_vec_3619 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3620);
													mem_vec_3620 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3621);
													mem_vec_3621 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3622);
													mem_vec_3622 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3623);
													mem_vec_3623 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3624);
													mem_vec_3624 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3625);
													mem_vec_3625 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3626);
													mem_vec_3626 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3627);
													mem_vec_3627 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3628);
													mem_vec_3628 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3629);
													mem_vec_3629 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3630);
													mem_vec_3630 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3631);
													mem_vec_3631 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3615);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3623);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3624);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3625);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3626);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3627);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3628);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3629);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3630);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3631);
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