#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (1, c); T (17, y); T (4, x); T (4, f); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c496_p_0, c497_p_0, cp_1, c496_p_1, cp_2, c496, c497, f, fp_0, f295_p_0, fp_1, f295, h, hp_0, w, wp_0, x, xp_0, x339_p_0, xp_1, x339, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y226 = 0;
IND_TYPE x340 = 0;
IND_TYPE h166 = 0;
IND_TYPE w190 = 0;
IND_TYPE c498 = 0;
IND_TYPE f296 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3292 ,mem_vec_3293 ,mem_vec_3294 ,mem_vec_3295 ,mem_vec_3296 ,mem_vec_3297 ,mem_vec_3298 ,mem_vec_3299 ,mem_vec_3300 ,mem_vec_3301 ,mem_vec_3302 ,mem_vec_3303 ,mem_vec_3304 ,mem_vec_3305 ,mem_vec_3306 ,mem_vec_3307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f295 = f296, f295_p_0 = 0;
	f295 < f296 + 256;
	f295 += 128, f295_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c497 = c498, c497_p_0 = 0;
		c497 < c498 + 128;
		c497 += 64, c497_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f295, fp_1 = f295_p_0, fp_0 = 0;
			f < f295 + 128;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (x, 4) (68 / 17)
			for (x339 = x340, x339_p_0 = 0;
				x339 < x340 + 68;
				x339 += 17, x339_p_0 += 17){
				// y = 68, x = 17, h = 3, w = 3, c = 64, f = 32
				// T (y, 17) (68 / 4)
				for (y = y226, yp_0 = 0;
					y < y226 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c496 = c497, c496_p_1 = c497_p_0, c496_p_0 = 0;
						c496 < c497 + 64;
						c496 += 64, c496_p_1 += 64, c496_p_0 += 64){
						// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h166, hp_0 = 0;
							h < h166 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 64, f = 32
							// T (x, 17) (17 / 1)
							for (x = x339, xp_1 = x339_p_0, xp_0 = 0;
								x < x339 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w190, wp_0 = 0;
									w < w190 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3292 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3293 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3294 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3295 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c496, cp_2 = c496_p_1, cp_1 = c496_p_0, cp_0 = 0;
												c < c496 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3292);
												mem_vec_3292 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3293);
												mem_vec_3293 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3294);
												mem_vec_3294 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3295);
												mem_vec_3295 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3296);
												mem_vec_3296 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3297);
												mem_vec_3297 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3298);
												mem_vec_3298 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3299);
												mem_vec_3299 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3300);
												mem_vec_3300 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3301);
												mem_vec_3301 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3302);
												mem_vec_3302 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3303);
												mem_vec_3303 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3304);
												mem_vec_3304 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3305);
												mem_vec_3305 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3306);
												mem_vec_3306 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3307);
												mem_vec_3307 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3295);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3299);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3301);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3302);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3303);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3307);
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