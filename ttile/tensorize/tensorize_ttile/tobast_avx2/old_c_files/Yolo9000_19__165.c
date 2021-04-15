#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (8, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (512, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c780_p_0, cp_1, c780, f, fp_0, f1040_p_0, f1041_p_0, fp_1, f1040_p_1, fp_2, f1040, f1041, x, xp_0, x1040_p_0, x1041_p_0, xp_1, x1040_p_1, xp_2, x1040, x1041, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y520 = 0;
IND_TYPE x1042 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c781 = 0;
IND_TYPE f1042 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9360 ,mem_vec_9361 ,mem_vec_9362 ,mem_vec_9363 ,mem_vec_9364 ,mem_vec_9365 ,mem_vec_9366 ,mem_vec_9367 ,mem_vec_9368 ,mem_vec_9369 ,mem_vec_9370 ,mem_vec_9371 ,mem_vec_9372 ,mem_vec_9373 ,mem_vec_9374 ,mem_vec_9375 ,mem_vec_9376 ,mem_vec_9377 ,mem_vec_9378 ,mem_vec_9379 ,mem_vec_9380 ,mem_vec_9381 ,mem_vec_9382 ,mem_vec_9383 ,mem_vec_9384 ,mem_vec_9385 ,mem_vec_9386 ,mem_vec_9387 ,mem_vec_9388 ,mem_vec_9389 ,mem_vec_9390 ,mem_vec_9391 ,mem_vec_9392 ,mem_vec_9393 ,mem_vec_9394 ,mem_vec_9395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1041 = f1042, f1041_p_0 = 0;
	f1041 < f1042 + 512;
	f1041 += 256, f1041_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 1) (17 / 17)
	for (x1041 = x1042, x1041_p_0 = 0;
		x1041 < x1042 + 17;
		x1041 += 17, x1041_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
		// T (c, 512) (1024 / 2)
		for (c780 = c781, c780_p_0 = 0;
			c780 < c781 + 1024;
			c780 += 2, c780_p_0 += 2){
			// y = 17, x = 17, h = 1, w = 1, c = 2, f = 256
			// T (f, 1) (256 / 256)
			for (f1040 = f1041, f1040_p_1 = f1041_p_0, f1040_p_0 = 0;
				f1040 < f1041 + 256;
				f1040 += 256, f1040_p_1 += 256, f1040_p_0 += 256){
					for (y = y520, yp_0 = 0;
						y < y520 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 256
						// T (x, 17) (17 / 1)
						for (x1040 = x1041, x1040_p_1 = x1041_p_0, x1040_p_0 = 0;
							x1040 < x1041 + 17;
							x1040 += 1, x1040_p_1 += 1, x1040_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1040, fp_2 = f1040_p_1, fp_1 = f1040_p_0, fp_0 = 0;
								f < f1040 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1040, xp_2 = x1040_p_1, xp_1 = x1040_p_0, xp_0 = 0;
									x < x1040 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c780, cp_1 = c780_p_0, cp_0 = 0;
												c < c780 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9360);
												mem_vec_9360 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9361);
												mem_vec_9361 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9362);
												mem_vec_9362 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9363);
												mem_vec_9363 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9364);
												mem_vec_9364 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9365);
												mem_vec_9365 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9366);
												mem_vec_9366 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9367);
												mem_vec_9367 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9368);
												mem_vec_9368 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9369);
												mem_vec_9369 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9370);
												mem_vec_9370 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9371);
												mem_vec_9371 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9372);
												mem_vec_9372 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9373);
												mem_vec_9373 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9374);
												mem_vec_9374 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9375);
												mem_vec_9375 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9375);
								}
							}
						}
					}
					for (y = y520 + 12, yp_0 = 0;
						y < y520 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 256
						// T (x, 17) (17 / 1)
						for (x1040 = x1041, x1040_p_1 = x1041_p_0, x1040_p_0 = 0;
							x1040 < x1041 + 17;
							x1040 += 1, x1040_p_1 += 1, x1040_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1040, fp_2 = f1040_p_1, fp_1 = f1040_p_0, fp_0 = 0;
								f < f1040 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1040, xp_2 = x1040_p_1, xp_1 = x1040_p_0, xp_0 = 0;
									x < x1040 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9376 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9377 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9378 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9379 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_9392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_9394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c780, cp_1 = c780_p_0, cp_0 = 0;
												c < c780 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9376);
												mem_vec_9376 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9377);
												mem_vec_9377 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9378);
												mem_vec_9378 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9379);
												mem_vec_9379 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9380);
												mem_vec_9380 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9381);
												mem_vec_9381 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9382);
												mem_vec_9382 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9383);
												mem_vec_9383 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9384);
												mem_vec_9384 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9385);
												mem_vec_9385 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9386);
												mem_vec_9386 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9387);
												mem_vec_9387 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9388);
												mem_vec_9388 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9389);
												mem_vec_9389 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9390);
												mem_vec_9390 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9391);
												mem_vec_9391 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9392);
												mem_vec_9392 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9393);
												mem_vec_9393 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9394);
												mem_vec_9394 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9395);
												mem_vec_9395 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9379);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9380);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9381);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9382);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9383);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9385);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9386);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9387);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9388);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9389);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9390);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9391);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9392);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9393);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9394);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9395);
								}
							}
						}
					}
			}
		}
	}
}


}