#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c321_p_0, cp_1, c321, f, fp_0, x, xp_0, x535_p_0, x536_p_0, x537_p_0, xp_1, x535_p_1, x536_p_1, xp_2, x535_p_2, xp_3, x535, x536, x537, y, yp_0, y428_p_0, y429_p_0, yp_1, y428_p_1, yp_2, y428, y429;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y430 = 0;
IND_TYPE x538 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c322 = 0;
IND_TYPE f214 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,mem_vec_3464 ,mem_vec_3465 ,mem_vec_3466 ,mem_vec_3467 ,mem_vec_3468 ,mem_vec_3469 ,mem_vec_3470 ,mem_vec_3471 ,mem_vec_3472 ,mem_vec_3473 ,mem_vec_3474 ,mem_vec_3475 ,mem_vec_3476 ,mem_vec_3477 ,mem_vec_3478 ,mem_vec_3479 ,mem_vec_3480 ,mem_vec_3481 ,mem_vec_3482 ,mem_vec_3483 ,mem_vec_3484 ,mem_vec_3485 ,mem_vec_3486 ,mem_vec_3487 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y429 = y430, y429_p_0 = 0;
		y429 < y430 + 96;
		y429 += 32, y429_p_0 += 32){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x537 = x538, x537_p_0 = 0;
			x537 < x538 + 136;
			x537 += 1, x537_p_0 += 1){
			// y = 2 * (4 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y428 = y429, y428_p_1 = y429_p_0, y428_p_0 = 0;
				y428 < y429 + 32;
				y428 += 16, y428_p_1 += 16, y428_p_0 += 16){
				// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x536 = x537, x536_p_1 = x537_p_0, x536_p_0 = 0;
					x536 < x537 + 1;
					x536 += 1, x536_p_1 += 1, x536_p_0 += 1){
					// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f214, fp_0 = 0;
						f < f214 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y428, yp_2 = y428_p_1, yp_1 = y428_p_0, yp_0 = 0;
							y < y428 + 16;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x535 = x536, x535_p_2 = x536_p_1, x535_p_1 = x536_p_0, x535_p_0 = 0;
								x535 < x536 + 1;
								x535 += 1, x535_p_2 += 1, x535_p_1 += 1, x535_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c321 = c322, c321_p_0 = 0;
									c321 < c322 + 128;
									c321 += 128, c321_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x535, xp_3 = x535_p_2, xp_2 = x535_p_1, xp_1 = x535_p_0, xp_0 = 0;
										x < x535 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3452 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3453 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3454 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3455 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c321, cp_1 = c321_p_0, cp_0 = 0;
													c < c321 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3452);
													mem_vec_3452 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3453);
													mem_vec_3453 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3454);
													mem_vec_3454 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3455);
													mem_vec_3455 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3456);
													mem_vec_3456 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3457);
													mem_vec_3457 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3458);
													mem_vec_3458 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3459);
													mem_vec_3459 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3460);
													mem_vec_3460 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3461);
													mem_vec_3461 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3462);
													mem_vec_3462 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3463);
													mem_vec_3463 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3464);
													mem_vec_3464 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3465);
													mem_vec_3465 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3466);
													mem_vec_3466 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3467);
													mem_vec_3467 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3452);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3453);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3454);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3455);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3456);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3457);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3458);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3459);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3460);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3461);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3462);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3463);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3464);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3465);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3466);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3467);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y429 = y430 + 96, y429_p_0 = 0;
		y429 < y430 + 96 + 40;
		y429 += 40, y429_p_0 += 40){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x537 = x538, x537_p_0 = 0;
			x537 < x538 + 136;
			x537 += 1, x537_p_0 += 1){
			// y = 2 * (4 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y428 = y429, y428_p_1 = y429_p_0, y428_p_0 = 0;
				y428 < y429 + 40;
				y428 += 20, y428_p_1 += 20, y428_p_0 += 20){
				// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x536 = x537, x536_p_1 = x537_p_0, x536_p_0 = 0;
					x536 < x537 + 1;
					x536 += 1, x536_p_1 += 1, x536_p_0 += 1){
					// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f214, fp_0 = 0;
						f < f214 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y428, yp_2 = y428_p_1, yp_1 = y428_p_0, yp_0 = 0;
							y < y428 + 20;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x535 = x536, x535_p_2 = x536_p_1, x535_p_1 = x536_p_0, x535_p_0 = 0;
								x535 < x536 + 1;
								x535 += 1, x535_p_2 += 1, x535_p_1 += 1, x535_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c321 = c322, c321_p_0 = 0;
									c321 < c322 + 128;
									c321 += 128, c321_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x535, xp_3 = x535_p_2, xp_2 = x535_p_1, xp_1 = x535_p_0, xp_0 = 0;
										x < x535 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3468 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3469 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3470 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3471 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_3484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c321, cp_1 = c321_p_0, cp_0 = 0;
													c < c321 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3468);
													mem_vec_3468 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3469);
													mem_vec_3469 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3470);
													mem_vec_3470 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3471);
													mem_vec_3471 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3472);
													mem_vec_3472 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3473);
													mem_vec_3473 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3474);
													mem_vec_3474 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3475);
													mem_vec_3475 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3476);
													mem_vec_3476 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3477);
													mem_vec_3477 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3478);
													mem_vec_3478 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3479);
													mem_vec_3479 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3480);
													mem_vec_3480 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3481);
													mem_vec_3481 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3482);
													mem_vec_3482 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3483);
													mem_vec_3483 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3484);
													mem_vec_3484 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3485);
													mem_vec_3485 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3486);
													mem_vec_3486 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3487);
													mem_vec_3487 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3468);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3469);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3470);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3471);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3472);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3473);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3474);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3475);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3476);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3477);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3478);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3479);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3487);
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