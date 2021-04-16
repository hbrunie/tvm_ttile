#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (34, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (32, c); T (8, f); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c37_p_0, cp_1, c37, f, fp_0, f40_p_0, f41_p_0, fp_1, f40_p_1, fp_2, f40, f41, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y29_p_0, yp_1, y29;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y30 = 0;
IND_TYPE x22 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c38 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f41 = f42, f41_p_0 = 0;
	f41 < f42 + 512;
	f41 += 256, f41_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (y, 2) (34 / 17)
	for (y29 = y30, y29_p_0 = 0;
		y29 < y30 + 34;
		y29 += 17, y29_p_0 += 17){
		// y = 17, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f40 = f41, f40_p_1 = f41_p_0, f40_p_0 = 0;
			f40 < f41 + 256;
			f40 += 32, f40_p_1 += 32, f40_p_0 += 32){
			// y = 17, x = 34, h = 3, w = 3, c = 256, f = 32
			// T (c, 32) (256 / 8)
			for (c37 = c38, c37_p_0 = 0;
				c37 < c38 + 256;
				c37 += 8, c37_p_0 += 8){
				// y = 17, x = 34, h = 3, w = 3, c = 8, f = 32
				// T (f, 1) (32 / 32)
				for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
					f < f40 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y29, yp_1 = y29_p_0, yp_0 = 0;
							y < y29 + 12;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x22, xp_0 = 0;
								x < x22 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h20, hp_0 = 0;
									h < h20 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w20, wp_0 = 0;
										w < w20 + 3;
										w += 1, wp_0 += 1){
												mem_vec_460 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_461 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_462 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_463 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c37, cp_1 = c37_p_0, cp_0 = 0;
													c < c37 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_460);
													mem_vec_460 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_461);
													mem_vec_461 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_462);
													mem_vec_462 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_463);
													mem_vec_463 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_464);
													mem_vec_464 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_465);
													mem_vec_465 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_466);
													mem_vec_466 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_467);
													mem_vec_467 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_468);
													mem_vec_468 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_469);
													mem_vec_469 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_470);
													mem_vec_470 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_471);
													mem_vec_471 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_472);
													mem_vec_472 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_473);
													mem_vec_473 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_474);
													mem_vec_474 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_475);
													mem_vec_475 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_460);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_461);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_462);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_463);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_464);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_465);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_466);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_467);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_468);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_469);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_470);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_471);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_472);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_473);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_474);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_475);
									}
								}
							}
						}
						for (y = y29 + 12, yp_1 = y29_p_0, yp_0 = 0;
							y < y29 + 12 + 5;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (x, 34) (34 / 1)
							for (x = x22, xp_0 = 0;
								x < x22 + 34;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h20, hp_0 = 0;
									h < h20 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (w, 3) (3 / 1)
									for (w = w20, wp_0 = 0;
										w < w20 + 3;
										w += 1, wp_0 += 1){
												mem_vec_476 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_477 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_478 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_479 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c37, cp_1 = c37_p_0, cp_0 = 0;
													c < c37 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_476);
													mem_vec_476 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_477);
													mem_vec_477 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_478);
													mem_vec_478 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_479);
													mem_vec_479 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_480);
													mem_vec_480 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_481);
													mem_vec_481 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_482);
													mem_vec_482 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_483);
													mem_vec_483 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_484);
													mem_vec_484 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_485);
													mem_vec_485 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_486);
													mem_vec_486 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_487);
													mem_vec_487 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_488);
													mem_vec_488 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_489);
													mem_vec_489 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_490);
													mem_vec_490 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_491);
													mem_vec_491 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_492);
													mem_vec_492 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_493);
													mem_vec_493 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_494);
													mem_vec_494 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_495);
													mem_vec_495 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_476);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_477);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_478);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_479);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_487);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_491);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_495);
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