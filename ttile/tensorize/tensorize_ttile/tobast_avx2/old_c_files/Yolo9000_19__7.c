#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (32, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1038_p_0, cp_1, c1038, f, fp_0, f1384_p_0, f1385_p_0, fp_1, f1384_p_1, fp_2, f1384, f1385, x, xp_0, x1384_p_0, x1385_p_0, xp_1, x1384_p_1, xp_2, x1384, x1385, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y692 = 0;
IND_TYPE x1386 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1039 = 0;
IND_TYPE f1386 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12456 ,mem_vec_12457 ,mem_vec_12458 ,mem_vec_12459 ,mem_vec_12460 ,mem_vec_12461 ,mem_vec_12462 ,mem_vec_12463 ,mem_vec_12464 ,mem_vec_12465 ,mem_vec_12466 ,mem_vec_12467 ,mem_vec_12468 ,mem_vec_12469 ,mem_vec_12470 ,mem_vec_12471 ,mem_vec_12472 ,mem_vec_12473 ,mem_vec_12474 ,mem_vec_12475 ,mem_vec_12476 ,mem_vec_12477 ,mem_vec_12478 ,mem_vec_12479 ,mem_vec_12480 ,mem_vec_12481 ,mem_vec_12482 ,mem_vec_12483 ,mem_vec_12484 ,mem_vec_12485 ,mem_vec_12486 ,mem_vec_12487 ,mem_vec_12488 ,mem_vec_12489 ,mem_vec_12490 ,mem_vec_12491 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1385 = f1386, f1385_p_0 = 0;
	f1385 < f1386 + 512;
	f1385 += 256, f1385_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1385 = x1386, x1385_p_0 = 0;
		x1385 < x1386 + 17;
		x1385 += 1, x1385_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 32) (1024 / 32)
		for (c1038 = c1039, c1038_p_0 = 0;
			c1038 < c1039 + 1024;
			c1038 += 32, c1038_p_0 += 32){
			// y = 17, x = 1, h = 1, w = 1, c = 32, f = 256
			// T (f, 4) (256 / 64)
			for (f1384 = f1385, f1384_p_1 = f1385_p_0, f1384_p_0 = 0;
				f1384 < f1385 + 256;
				f1384 += 64, f1384_p_1 += 64, f1384_p_0 += 64){
					for (y = y692, yp_0 = 0;
						y < y692 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x1384 = x1385, x1384_p_1 = x1385_p_0, x1384_p_0 = 0;
							x1384 < x1385 + 1;
							x1384 += 1, x1384_p_1 += 1, x1384_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1384, fp_2 = f1384_p_1, fp_1 = f1384_p_0, fp_0 = 0;
								f < f1384 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1384, xp_2 = x1384_p_1, xp_1 = x1384_p_0, xp_0 = 0;
									x < x1384 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12456 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12457 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12458 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12459 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1038, cp_1 = c1038_p_0, cp_0 = 0;
												c < c1038 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12456);
												mem_vec_12456 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12457);
												mem_vec_12457 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12458);
												mem_vec_12458 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12459);
												mem_vec_12459 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12460);
												mem_vec_12460 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12461);
												mem_vec_12461 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12462);
												mem_vec_12462 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12463);
												mem_vec_12463 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12464);
												mem_vec_12464 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12465);
												mem_vec_12465 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12466);
												mem_vec_12466 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12467);
												mem_vec_12467 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12468);
												mem_vec_12468 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12469);
												mem_vec_12469 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12470);
												mem_vec_12470 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12471);
												mem_vec_12471 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12456);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12457);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12458);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12459);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12460);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12461);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12462);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12463);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12464);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12465);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12466);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12467);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12468);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12469);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12470);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12471);
								}
							}
						}
					}
					for (y = y692 + 12, yp_0 = 0;
						y < y692 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x1384 = x1385, x1384_p_1 = x1385_p_0, x1384_p_0 = 0;
							x1384 < x1385 + 1;
							x1384 += 1, x1384_p_1 += 1, x1384_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1384, fp_2 = f1384_p_1, fp_1 = f1384_p_0, fp_0 = 0;
								f < f1384 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1384, xp_2 = x1384_p_1, xp_1 = x1384_p_0, xp_0 = 0;
									x < x1384 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12472 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12473 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12474 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12475 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c1038, cp_1 = c1038_p_0, cp_0 = 0;
												c < c1038 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12472);
												mem_vec_12472 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12473);
												mem_vec_12473 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12474);
												mem_vec_12474 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12475);
												mem_vec_12475 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12476);
												mem_vec_12476 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12477);
												mem_vec_12477 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12478);
												mem_vec_12478 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12479);
												mem_vec_12479 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12480);
												mem_vec_12480 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12481);
												mem_vec_12481 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12482);
												mem_vec_12482 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12483);
												mem_vec_12483 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12484);
												mem_vec_12484 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12485);
												mem_vec_12485 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12486);
												mem_vec_12486 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12487);
												mem_vec_12487 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12488);
												mem_vec_12488 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12489);
												mem_vec_12489 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12490);
												mem_vec_12490 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12491);
												mem_vec_12491 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12472);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12473);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12474);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12475);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12479);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12480);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12481);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12482);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12483);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12484);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12485);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12486);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12487);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12488);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12489);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12490);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12491);
								}
							}
						}
					}
			}
		}
	}
}


}