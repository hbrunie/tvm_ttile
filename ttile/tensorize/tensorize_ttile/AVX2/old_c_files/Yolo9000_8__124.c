#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (4, c); T (17, y); T (4, x); T (2, f); T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c532_p_0, c533_p_0, cp_1, c532_p_1, cp_2, c532, c533, f, fp_0, f322_p_0, fp_1, f322, h, hp_0, w, wp_0, x, xp_0, x366_p_0, xp_1, x366, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y244 = 0;
IND_TYPE x367 = 0;
IND_TYPE h184 = 0;
IND_TYPE w208 = 0;
IND_TYPE c534 = 0;
IND_TYPE f323 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f322 = f323, f322_p_0 = 0;
	f322 < f323 + 256;
	f322 += 64, f322_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (c, 2) (128 / 64)
	for (c533 = c534, c533_p_0 = 0;
		c533 < c534 + 128;
		c533 += 64, c533_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 64, f = 64
		// T (f, 2) (64 / 32)
		for (f = f322, fp_1 = f322_p_0, fp_0 = 0;
			f < f322 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (x, 4) (68 / 17)
			for (x366 = x367, x366_p_0 = 0;
				x366 < x367 + 68;
				x366 += 17, x366_p_0 += 17){
				// y = 68, x = 17, h = 3, w = 3, c = 64, f = 32
				// T (y, 17) (68 / 4)
				for (y = y244, yp_0 = 0;
					y < y244 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c532 = c533, c532_p_1 = c533_p_0, c532_p_0 = 0;
						c532 < c533 + 64;
						c532 += 16, c532_p_1 += 16, c532_p_0 += 16){
						// y = 4, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h184, hp_0 = 0;
							h < h184 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 16, f = 32
							// T (x, 17) (17 / 1)
							for (x = x366, xp_1 = x366_p_0, xp_0 = 0;
								x < x366 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w208, wp_0 = 0;
									w < w208 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3436 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3437 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3438 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3439 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c532, cp_2 = c532_p_1, cp_1 = c532_p_0, cp_0 = 0;
												c < c532 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3436);
												mem_vec_3436 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3437);
												mem_vec_3437 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3438);
												mem_vec_3438 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3439);
												mem_vec_3439 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3440);
												mem_vec_3440 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3441);
												mem_vec_3441 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3442);
												mem_vec_3442 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3443);
												mem_vec_3443 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3444);
												mem_vec_3444 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3445);
												mem_vec_3445 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3446);
												mem_vec_3446 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3447);
												mem_vec_3447 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3448);
												mem_vec_3448 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3449);
												mem_vec_3449 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3450);
												mem_vec_3450 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3451);
												mem_vec_3451 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3436);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3437);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3438);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3439);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3440);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3441);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3442);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3443);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3444);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3445);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3446);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3447);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3448);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3449);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3450);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3451);
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