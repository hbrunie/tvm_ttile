#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (17, y); T (2, f); T (68, x); T (2, y); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, x, xp_0, x110_p_0, x111_p_0, x112_p_0, xp_1, x110_p_1, x111_p_1, xp_2, x110_p_2, xp_3, x110, x111, x112, y, yp_0, y88_p_0, y89_p_0, yp_1, y88_p_1, yp_2, y88, y89;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y90 = 0;
IND_TYPE x113 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c67 = 0;
IND_TYPE f44 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y89 = y90, y89_p_0 = 0;
	y89 < y90 + 136;
	y89 += 136, y89_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 2) (136 / 68)
	for (x112 = x113, x112_p_0 = 0;
		x112 < x113 + 136;
		x112 += 68, x112_p_0 += 68){
		// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
		// T (y, 2) (136 / 68)
		for (y88 = y89, y88_p_1 = y89_p_0, y88_p_0 = 0;
			y88 < y89 + 136;
			y88 += 68, y88_p_1 += 68, y88_p_0 += 68){
			// y = 68, x = 68, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (68 / 1)
			for (x111 = x112, x111_p_1 = x112_p_0, x111_p_0 = 0;
				x111 < x112 + 68;
				x111 += 1, x111_p_1 += 1, x111_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f44, fp_0 = 0;
					f < f44 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y88, yp_2 = y88_p_1, yp_1 = y88_p_0, yp_0 = 0;
						y < y88 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x110 = x111, x110_p_2 = x111_p_1, x110_p_1 = x111_p_0, x110_p_0 = 0;
							x110 < x111 + 1;
							x110 += 1, x110_p_2 += 1, x110_p_1 += 1, x110_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 4) (128 / 32)
							for (c66 = c67, c66_p_0 = 0;
								c66 < c67 + 128;
								c66 += 32, c66_p_0 += 32){
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x110, xp_3 = x110_p_2, xp_2 = x110_p_1, xp_1 = x110_p_0, xp_0 = 0;
									x < x110 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_472 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_473 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_474 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_475 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
												c < c66 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_472);
												mem_vec_472 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_473);
												mem_vec_473 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_474);
												mem_vec_474 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_475);
												mem_vec_475 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_476);
												mem_vec_476 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_477);
												mem_vec_477 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_478);
												mem_vec_478 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_479);
												mem_vec_479 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_480);
												mem_vec_480 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_481);
												mem_vec_481 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_482);
												mem_vec_482 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_483);
												mem_vec_483 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_484);
												mem_vec_484 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_485);
												mem_vec_485 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_486);
												mem_vec_486 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_487);
												mem_vec_487 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_472);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_473);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_474);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_475);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_479);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_480);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_481);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_482);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_483);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_484);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_485);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_486);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_487);
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