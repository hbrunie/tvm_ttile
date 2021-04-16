#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (7, w); T (7, h); T (7, y); T (112, x); T (4, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f84_p_0, fp_1, f84, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0, y84_p_0, yp_1, y84;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y85 = 0;
IND_TYPE x85 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 1) (64 / 64)
for (f84 = f85, f84_p_0 = 0;
	f84 < f85 + 64;
	f84 += 64, f84_p_0 += 64){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f84, fp_1 = f84_p_0, fp_0 = 0;
		f < f84 + 64;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 4) (112 / 28)
		for (y84 = y85, y84_p_0 = 0;
			y84 < y85 + 112;
			y84 += 28, y84_p_0 += 28){
			// y = 28, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 112) (112 / 1)
			for (x84 = x85, x84_p_0 = 0;
				x84 < x85 + 112;
				x84 += 1, x84_p_0 += 1){
				// y = 28, x = 1, h = 7, w = 7, c = 3, f = 32
				// T (y, 7) (28 / 4)
				for (y = y84, yp_1 = y84_p_0, yp_0 = 0;
					y < y84 + 28;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 1, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h56, hp_0 = 0;
						h < h56 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w56, wp_0 = 0;
							w < w56 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c84 = c85, c84_p_0 = 0;
								c84 < c85 + 3;
								c84 += 3, c84_p_0 += 3){
								// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
								// T (x, 1) (1 / 1)
								for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
									x < x84 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_448 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_449 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_450 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_451 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
												c < c84 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_448);
												mem_vec_448 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_449);
												mem_vec_449 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_450);
												mem_vec_450 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_451);
												mem_vec_451 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_452);
												mem_vec_452 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_453);
												mem_vec_453 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_454);
												mem_vec_454 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_455);
												mem_vec_455 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_456);
												mem_vec_456 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_457);
												mem_vec_457 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_458);
												mem_vec_458 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_459);
												mem_vec_459 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_460);
												mem_vec_460 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_461);
												mem_vec_461 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_462);
												mem_vec_462 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_463);
												mem_vec_463 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_449);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_450);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_451);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_452);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_453);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_454);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_455);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_456);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_457);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_458);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_459);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_460);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_461);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_462);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_463);
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