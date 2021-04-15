#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, c); T (4, x); T (7, y); T (8, f); T (64, c); T (7, x)]
*/
IND_TYPE c, cp_0, c96_p_0, c97_p_0, cp_1, c96_p_1, cp_2, c96, c97, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x96_p_0, x97_p_0, xp_1, x96_p_1, xp_2, x96, x97, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y48 = 0;
IND_TYPE x98 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c98 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (x, 7) (28 / 4)
for (x97 = x98, x97_p_0 = 0;
	x97 < x98 + 28;
	x97 += 4, x97_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 128, f = 256
	// T (c, 64) (128 / 2)
	for (c97 = c98, c97_p_0 = 0;
		c97 < c98 + 128;
		c97 += 2, c97_p_0 += 2){
		// y = 28, x = 4, h = 3, w = 3, c = 2, f = 256
		// T (f, 8) (256 / 32)
		for (f = f48, fp_0 = 0;
			f < f48 + 256;
			f += 32, fp_0 += 32){
			// y = 28, x = 4, h = 3, w = 3, c = 2, f = 32
			// T (y, 7) (28 / 4)
			for (y = y48, yp_0 = 0;
				y < y48 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 2, f = 32
				// T (x, 4) (4 / 1)
				for (x96 = x97, x96_p_1 = x97_p_0, x96_p_0 = 0;
					x96 < x97 + 4;
					x96 += 1, x96_p_1 += 1, x96_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (c, 1) (2 / 2)
					for (c96 = c97, c96_p_1 = c97_p_0, c96_p_0 = 0;
						c96 < c97 + 2;
						c96 += 2, c96_p_1 += 2, c96_p_0 += 2){
						// y = 4, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (h, 3) (3 / 1)
						for (h = h48, hp_0 = 0;
							h < h48 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 1, h = 1, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
								// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x96, xp_2 = x96_p_1, xp_1 = x96_p_0, xp_0 = 0;
									x < x96 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_384 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_385 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_386 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_387 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c96, cp_2 = c96_p_1, cp_1 = c96_p_0, cp_0 = 0;
												c < c96 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_384);
												mem_vec_384 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_385);
												mem_vec_385 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_386);
												mem_vec_386 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_387);
												mem_vec_387 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_388);
												mem_vec_388 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_389);
												mem_vec_389 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_390);
												mem_vec_390 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_391);
												mem_vec_391 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_392);
												mem_vec_392 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_393);
												mem_vec_393 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_394);
												mem_vec_394 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_395);
												mem_vec_395 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_396);
												mem_vec_396 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_397);
												mem_vec_397 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_398);
												mem_vec_398 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_399);
												mem_vec_399 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_385);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_386);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_387);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_388);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_389);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_390);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_391);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_392);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_393);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_394);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_395);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_396);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_397);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_398);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_399);
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