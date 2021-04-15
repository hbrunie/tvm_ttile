#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (1, c); T (1, x); T (8, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f40_p_0, f41_p_0, fp_1, f40_p_1, fp_2, f40, f41, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y20 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
for (f41 = f42, f41_p_0 = 0;
	f41 < f42 + 512;
	f41 += 64, f41_p_0 += 64){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
	// T (x, 1) (17 / 17)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 17;
		x41 += 17, x41_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
		// T (c, 1) (1024 / 1024)
		for (c30 = c31, c30_p_0 = 0;
			c30 < c31 + 1024;
			c30 += 1024, c30_p_0 += 1024){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
			// T (f, 1) (64 / 64)
			for (f40 = f41, f40_p_1 = f41_p_0, f40_p_0 = 0;
				f40 < f41 + 64;
				f40 += 64, f40_p_1 += 64, f40_p_0 += 64){
					for (y = y20, yp_0 = 0;
						y < y20 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
						// T (x, 1) (17 / 17)
						for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
							x40 < x41 + 17;
							x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
							// T (f, 2) (64 / 32)
							for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
								f < f40 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
								// T (x, 17) (17 / 1)
								for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
									x < x40 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
											// T (c, 1024) (1024 / 1)
											for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
												c < c30 + 1024;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_360);
												mem_vec_360 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_361);
												mem_vec_361 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_362);
												mem_vec_362 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_363);
												mem_vec_363 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_364);
												mem_vec_364 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_365);
												mem_vec_365 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_366);
												mem_vec_366 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_367);
												mem_vec_367 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_368);
												mem_vec_368 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_369);
												mem_vec_369 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_370);
												mem_vec_370 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_371);
												mem_vec_371 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_372);
												mem_vec_372 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_373);
												mem_vec_373 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_374);
												mem_vec_374 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_375);
												mem_vec_375 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_375);
								}
							}
						}
					}
					for (y = y20 + 12, yp_0 = 0;
						y < y20 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
						// T (x, 1) (17 / 17)
						for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
							x40 < x41 + 17;
							x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
							// T (f, 2) (64 / 32)
							for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
								f < f40 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
								// T (x, 17) (17 / 1)
								for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
									x < x40 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_376 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_377 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_378 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_379 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
											// T (c, 1024) (1024 / 1)
											for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
												c < c30 + 1024;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_376);
												mem_vec_376 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_377);
												mem_vec_377 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_378);
												mem_vec_378 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_379);
												mem_vec_379 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_380);
												mem_vec_380 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_381);
												mem_vec_381 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_382);
												mem_vec_382 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_383);
												mem_vec_383 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_384);
												mem_vec_384 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_385);
												mem_vec_385 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_386);
												mem_vec_386 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_387);
												mem_vec_387 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_388);
												mem_vec_388 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_389);
												mem_vec_389 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_390);
												mem_vec_390 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_391);
												mem_vec_391 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_392);
												mem_vec_392 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_393);
												mem_vec_393 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_394);
												mem_vec_394 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_395);
												mem_vec_395 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_379);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_380);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_381);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_382);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_383);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_385);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_386);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_387);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_388);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_389);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_390);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_391);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_392);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_393);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_394);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_395);
								}
							}
						}
					}
			}
		}
	}
}


}