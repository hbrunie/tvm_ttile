#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (4, x);
  T (3, h); T (4, c); T (1, f); T (34, y); T (2, x); T (4, f); T (17, x)]
*/
IND_TYPE c, cp_0, c567_p_0, cp_1, c567, f, fp_0, f423_p_0, fp_1, f423, h, hp_0, w, wp_0, x, xp_0, x756_p_0, x757_p_0, xp_1, x756_p_1, xp_2, x756, x757, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y522 = 0;
IND_TYPE x758 = 0;
IND_TYPE h221 = 0;
IND_TYPE w363 = 0;
IND_TYPE c568 = 0;
IND_TYPE f424 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_6286 ,mem_vec_6287 ,mem_vec_6288 ,mem_vec_6289 ,mem_vec_6290 ,mem_vec_6291 ,mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,mem_vec_6300 ,mem_vec_6301 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 17) (136 / 8)
for (x757 = x758, x757_p_0 = 0;
	x757 < x758 + 136;
	x757 += 8, x757_p_0 += 8){
	// y = 136, x = 8, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f423 = f424, f423_p_0 = 0;
		f423 < f424 + 128;
		f423 += 32, f423_p_0 += 32){
		// y = 136, x = 8, h = 3, w = 3, c = 64, f = 32
		// T (x, 2) (8 / 4)
		for (x756 = x757, x756_p_1 = x757_p_0, x756_p_0 = 0;
			x756 < x757 + 8;
			x756 += 4, x756_p_1 += 4, x756_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 64, f = 32
			// T (y, 34) (136 / 4)
			for (y = y522, yp_0 = 0;
				y < y522 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f423, fp_1 = f423_p_0, fp_0 = 0;
					f < f423 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c567 = c568, c567_p_0 = 0;
						c567 < c568 + 64;
						c567 += 16, c567_p_0 += 16){
						// y = 4, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h221, hp_0 = 0;
							h < h221 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 4, h = 1, w = 3, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x756, xp_2 = x756_p_1, xp_1 = x756_p_0, xp_0 = 0;
								x < x756 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w363, wp_0 = 0;
									w < w363 + 3;
									w += 1, wp_0 += 1){
											mem_vec_6286 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6287 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c567, cp_1 = c567_p_0, cp_0 = 0;
												c < c567 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6286);
												mem_vec_6286 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6287);
												mem_vec_6287 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6288);
												mem_vec_6288 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6289);
												mem_vec_6289 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6290);
												mem_vec_6290 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6291);
												mem_vec_6291 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6292);
												mem_vec_6292 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6293);
												mem_vec_6293 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6294);
												mem_vec_6294 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6295);
												mem_vec_6295 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6296);
												mem_vec_6296 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6297);
												mem_vec_6297 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6298);
												mem_vec_6298 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6299);
												mem_vec_6299 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6300);
												mem_vec_6300 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6301);
												mem_vec_6301 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6295);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6299);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6301);
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