#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (4, x);
  T (3, h); T (1, c); T (1, f); T (34, y); T (1, x); T (4, f); T (34, x)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, f45_p_0, fp_1, f45, h, hp_0, w, wp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y45 = 0;
IND_TYPE x74 = 0;
IND_TYPE h24 = 0;
IND_TYPE w33 = 0;
IND_TYPE c55 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
for (x73 = x74, x73_p_0 = 0;
	x73 < x74 + 136;
	x73 += 4, x73_p_0 += 4){
	// y = 136, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f45 = f46, f45_p_0 = 0;
		f45 < f46 + 128;
		f45 += 32, f45_p_0 += 32){
		// y = 136, x = 4, h = 3, w = 3, c = 64, f = 32
		// T (x, 1) (4 / 4)
		for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
			x72 < x73 + 4;
			x72 += 4, x72_p_1 += 4, x72_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 64, f = 32
			// T (y, 34) (136 / 4)
			for (y = y45, yp_0 = 0;
				y < y45 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f45, fp_1 = f45_p_0, fp_0 = 0;
					f < f45 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c54 = c55, c54_p_0 = 0;
						c54 < c55 + 64;
						c54 += 64, c54_p_0 += 64){
						// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h24, hp_0 = 0;
							h < h24 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 4, h = 1, w = 3, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
								x < x72 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w33, wp_0 = 0;
									w < w33 + 3;
									w += 1, wp_0 += 1){
											mem_vec_572 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_573 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_574 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_575 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
												c < c54 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_572);
												mem_vec_572 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_573);
												mem_vec_573 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_574);
												mem_vec_574 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_575);
												mem_vec_575 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_576);
												mem_vec_576 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_577);
												mem_vec_577 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_578);
												mem_vec_578 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_579);
												mem_vec_579 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_580);
												mem_vec_580 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_581);
												mem_vec_581 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_582);
												mem_vec_582 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_583);
												mem_vec_583 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_584);
												mem_vec_584 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_585);
												mem_vec_585 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_586);
												mem_vec_586 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_587);
												mem_vec_587 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_572);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_573);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_574);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_575);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_576);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_577);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_578);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_579);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_580);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_581);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_582);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_583);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_584);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_585);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_586);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_587);
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