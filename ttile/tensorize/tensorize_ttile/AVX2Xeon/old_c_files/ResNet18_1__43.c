#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (7, w); T (7, h); T (14, y); T (56, x); T (2, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, f69_p_0, fp_1, f69, h, hp_0, w, wp_0, x, xp_0, x69_p_0, xp_1, x69, y, yp_0, y69_p_0, yp_1, y69;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y70 = 0;
IND_TYPE x70 = 0;
IND_TYPE h46 = 0;
IND_TYPE w46 = 0;
IND_TYPE c70 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 2) (64 / 32)
for (f69 = f70, f69_p_0 = 0;
	f69 < f70 + 64;
	f69 += 32, f69_p_0 += 32){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
	// T (f, 1) (32 / 32)
	for (f = f69, fp_1 = f69_p_0, fp_0 = 0;
		f < f69 + 32;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 2) (112 / 56)
		for (y69 = y70, y69_p_0 = 0;
			y69 < y70 + 112;
			y69 += 56, y69_p_0 += 56){
			// y = 56, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 56) (112 / 2)
			for (x69 = x70, x69_p_0 = 0;
				x69 < x70 + 112;
				x69 += 2, x69_p_0 += 2){
				// y = 56, x = 2, h = 7, w = 7, c = 3, f = 32
				// T (y, 14) (56 / 4)
				for (y = y69, yp_1 = y69_p_0, yp_0 = 0;
					y < y69 + 56;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 2, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h46, hp_0 = 0;
						h < h46 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 2, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w46, wp_0 = 0;
							w < w46 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c69 = c70, c69_p_0 = 0;
								c69 < c70 + 3;
								c69 += 3, c69_p_0 += 3){
								// y = 4, x = 2, h = 1, w = 1, c = 3, f = 32
								// T (x, 2) (2 / 1)
								for (x = x69, xp_1 = x69_p_0, xp_0 = 0;
									x < x69 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_368 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_369 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_370 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_371 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
												c < c69 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_368);
												mem_vec_368 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_369);
												mem_vec_369 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_370);
												mem_vec_370 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_371);
												mem_vec_371 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_372);
												mem_vec_372 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_373);
												mem_vec_373 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_374);
												mem_vec_374 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_375);
												mem_vec_375 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_376);
												mem_vec_376 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_377);
												mem_vec_377 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_378);
												mem_vec_378 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_379);
												mem_vec_379 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_380);
												mem_vec_380 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_381);
												mem_vec_381 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_382);
												mem_vec_382 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_383);
												mem_vec_383 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_379);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_380);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_381);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_382);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_383);
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