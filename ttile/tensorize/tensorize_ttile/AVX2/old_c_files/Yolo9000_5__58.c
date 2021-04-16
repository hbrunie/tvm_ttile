#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c324_p_0, cp_1, c324, f, fp_0, x, xp_0, x540_p_0, x541_p_0, x542_p_0, xp_1, x540_p_1, x541_p_1, xp_2, x540_p_2, xp_3, x540, x541, x542, y, yp_0, y432_p_0, y433_p_0, yp_1, y432_p_1, yp_2, y432, y433;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y434 = 0;
IND_TYPE x543 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c325 = 0;
IND_TYPE f216 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3488 ,mem_vec_3489 ,mem_vec_3490 ,mem_vec_3491 ,mem_vec_3492 ,mem_vec_3493 ,mem_vec_3494 ,mem_vec_3495 ,mem_vec_3496 ,mem_vec_3497 ,mem_vec_3498 ,mem_vec_3499 ,mem_vec_3500 ,mem_vec_3501 ,mem_vec_3502 ,mem_vec_3503 ,mem_vec_3504 ,mem_vec_3505 ,mem_vec_3506 ,mem_vec_3507 ,mem_vec_3508 ,mem_vec_3509 ,mem_vec_3510 ,mem_vec_3511 ,mem_vec_3512 ,mem_vec_3513 ,mem_vec_3514 ,mem_vec_3515 ,mem_vec_3516 ,mem_vec_3517 ,mem_vec_3518 ,mem_vec_3519 ,mem_vec_3520 ,mem_vec_3521 ,mem_vec_3522 ,mem_vec_3523 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y433 = y434, y433_p_0 = 0;
		y433 < y434 + 96;
		y433 += 32, y433_p_0 += 32){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x542 = x543, x542_p_0 = 0;
			x542 < x543 + 136;
			x542 += 1, x542_p_0 += 1){
			// y = 2 * (4 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y432 = y433, y432_p_1 = y433_p_0, y432_p_0 = 0;
				y432 < y433 + 32;
				y432 += 16, y432_p_1 += 16, y432_p_0 += 16){
				// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x541 = x542, x541_p_1 = x542_p_0, x541_p_0 = 0;
					x541 < x542 + 1;
					x541 += 1, x541_p_1 += 1, x541_p_0 += 1){
					// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f216, fp_0 = 0;
						f < f216 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y432, yp_2 = y432_p_1, yp_1 = y432_p_0, yp_0 = 0;
							y < y432 + 16;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x540 = x541, x540_p_2 = x541_p_1, x540_p_1 = x541_p_0, x540_p_0 = 0;
								x540 < x541 + 1;
								x540 += 1, x540_p_2 += 1, x540_p_1 += 1, x540_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c324 = c325, c324_p_0 = 0;
									c324 < c325 + 128;
									c324 += 64, c324_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x540, xp_3 = x540_p_2, xp_2 = x540_p_1, xp_1 = x540_p_0, xp_0 = 0;
										x < x540 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3488 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3489 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3490 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3491 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c324, cp_1 = c324_p_0, cp_0 = 0;
													c < c324 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3488);
													mem_vec_3488 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3489);
													mem_vec_3489 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3490);
													mem_vec_3490 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3491);
													mem_vec_3491 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3492);
													mem_vec_3492 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3493);
													mem_vec_3493 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3494);
													mem_vec_3494 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3495);
													mem_vec_3495 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3496);
													mem_vec_3496 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3497);
													mem_vec_3497 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3498);
													mem_vec_3498 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3499);
													mem_vec_3499 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3500);
													mem_vec_3500 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3501);
													mem_vec_3501 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3502);
													mem_vec_3502 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3503);
													mem_vec_3503 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3491);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3495);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3496);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3497);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3498);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3499);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3500);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3501);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3502);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3503);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y433 = y434 + 96, y433_p_0 = 0;
		y433 < y434 + 96 + 40;
		y433 += 40, y433_p_0 += 40){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 136) (136 / 1)
		for (x542 = x543, x542_p_0 = 0;
			x542 < x543 + 136;
			x542 += 1, x542_p_0 += 1){
			// y = 2 * (4 * ph_y), x = 1, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y432 = y433, y432_p_1 = y433_p_0, y432_p_0 = 0;
				y432 < y433 + 40;
				y432 += 20, y432_p_1 += 20, y432_p_0 += 20){
				// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (1 / 1)
				for (x541 = x542, x541_p_1 = x542_p_0, x541_p_0 = 0;
					x541 < x542 + 1;
					x541 += 1, x541_p_1 += 1, x541_p_0 += 1){
					// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f216, fp_0 = 0;
						f < f216 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y432, yp_2 = y432_p_1, yp_1 = y432_p_0, yp_0 = 0;
							y < y432 + 20;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x540 = x541, x540_p_2 = x541_p_1, x540_p_1 = x541_p_0, x540_p_0 = 0;
								x540 < x541 + 1;
								x540 += 1, x540_p_2 += 1, x540_p_1 += 1, x540_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c324 = c325, c324_p_0 = 0;
									c324 < c325 + 128;
									c324 += 64, c324_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x540, xp_3 = x540_p_2, xp_2 = x540_p_1, xp_1 = x540_p_0, xp_0 = 0;
										x < x540 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3504 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3505 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3506 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3507 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_3520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c324, cp_1 = c324_p_0, cp_0 = 0;
													c < c324 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3504);
													mem_vec_3504 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3505);
													mem_vec_3505 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3506);
													mem_vec_3506 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3507);
													mem_vec_3507 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3508);
													mem_vec_3508 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3509);
													mem_vec_3509 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3510);
													mem_vec_3510 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3511);
													mem_vec_3511 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3512);
													mem_vec_3512 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3513);
													mem_vec_3513 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3514);
													mem_vec_3514 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3515);
													mem_vec_3515 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3516);
													mem_vec_3516 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3517);
													mem_vec_3517 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3518);
													mem_vec_3518 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3519);
													mem_vec_3519 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3520);
													mem_vec_3520 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3521);
													mem_vec_3521 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3522);
													mem_vec_3522 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3523);
													mem_vec_3523 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3504);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3505);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3506);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3507);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3511);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3519);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3523);
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