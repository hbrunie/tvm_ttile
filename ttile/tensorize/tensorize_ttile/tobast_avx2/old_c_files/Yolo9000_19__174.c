#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (32, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c606_p_0, cp_1, c606, f, fp_0, f808_p_0, f809_p_0, fp_1, f808_p_1, fp_2, f808, f809, x, xp_0, x808_p_0, x809_p_0, xp_1, x808_p_1, xp_2, x808, x809, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y404 = 0;
IND_TYPE x810 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c607 = 0;
IND_TYPE f810 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_7272 ,mem_vec_7273 ,mem_vec_7274 ,mem_vec_7275 ,mem_vec_7276 ,mem_vec_7277 ,mem_vec_7278 ,mem_vec_7279 ,mem_vec_7280 ,mem_vec_7281 ,mem_vec_7282 ,mem_vec_7283 ,mem_vec_7284 ,mem_vec_7285 ,mem_vec_7286 ,mem_vec_7287 ,mem_vec_7288 ,mem_vec_7289 ,mem_vec_7290 ,mem_vec_7291 ,mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,mem_vec_7300 ,mem_vec_7301 ,mem_vec_7302 ,mem_vec_7303 ,mem_vec_7304 ,mem_vec_7305 ,mem_vec_7306 ,mem_vec_7307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 4) (512 / 128)
for (f809 = f810, f809_p_0 = 0;
	f809 < f810 + 512;
	f809 += 128, f809_p_0 += 128){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
	// T (x, 1) (17 / 17)
	for (x809 = x810, x809_p_0 = 0;
		x809 < x810 + 17;
		x809 += 17, x809_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 128
		// T (c, 32) (1024 / 32)
		for (c606 = c607, c606_p_0 = 0;
			c606 < c607 + 1024;
			c606 += 32, c606_p_0 += 32){
			// y = 17, x = 17, h = 1, w = 1, c = 32, f = 128
			// T (f, 2) (128 / 64)
			for (f808 = f809, f808_p_1 = f809_p_0, f808_p_0 = 0;
				f808 < f809 + 128;
				f808 += 64, f808_p_1 += 64, f808_p_0 += 64){
					for (y = y404, yp_0 = 0;
						y < y404 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x808 = x809, x808_p_1 = x809_p_0, x808_p_0 = 0;
							x808 < x809 + 17;
							x808 += 1, x808_p_1 += 1, x808_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f808, fp_2 = f808_p_1, fp_1 = f808_p_0, fp_0 = 0;
								f < f808 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x808, xp_2 = x808_p_1, xp_1 = x808_p_0, xp_0 = 0;
									x < x808 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c606, cp_1 = c606_p_0, cp_0 = 0;
												c < c606 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7272);
												mem_vec_7272 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7273);
												mem_vec_7273 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7274);
												mem_vec_7274 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7275);
												mem_vec_7275 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7276);
												mem_vec_7276 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7277);
												mem_vec_7277 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7278);
												mem_vec_7278 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7279);
												mem_vec_7279 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7280);
												mem_vec_7280 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7281);
												mem_vec_7281 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7282);
												mem_vec_7282 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7283);
												mem_vec_7283 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7284);
												mem_vec_7284 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7285);
												mem_vec_7285 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7286);
												mem_vec_7286 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7287);
												mem_vec_7287 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7272);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7273);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7274);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7275);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7277);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7287);
								}
							}
						}
					}
					for (y = y404 + 12, yp_0 = 0;
						y < y404 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x808 = x809, x808_p_1 = x809_p_0, x808_p_0 = 0;
							x808 < x809 + 17;
							x808 += 1, x808_p_1 += 1, x808_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f808, fp_2 = f808_p_1, fp_1 = f808_p_0, fp_0 = 0;
								f < f808 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x808, xp_2 = x808_p_1, xp_1 = x808_p_0, xp_0 = 0;
									x < x808 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7290 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7291 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c606, cp_1 = c606_p_0, cp_0 = 0;
												c < c606 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7288);
												mem_vec_7288 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7289);
												mem_vec_7289 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7290);
												mem_vec_7290 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7291);
												mem_vec_7291 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7292);
												mem_vec_7292 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7293);
												mem_vec_7293 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7294);
												mem_vec_7294 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7295);
												mem_vec_7295 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7296);
												mem_vec_7296 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7297);
												mem_vec_7297 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7298);
												mem_vec_7298 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7299);
												mem_vec_7299 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7300);
												mem_vec_7300 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7301);
												mem_vec_7301 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7302);
												mem_vec_7302 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7303);
												mem_vec_7303 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7304);
												mem_vec_7304 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7305);
												mem_vec_7305 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7306);
												mem_vec_7306 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7307);
												mem_vec_7307 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7291);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7292);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7293);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7294);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7295);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7296);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7297);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7298);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7299);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7300);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7301);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7302);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7303);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7307);
								}
							}
						}
					}
			}
		}
	}
}


}