#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (68, x);
  T (3, h); T (1, c); T (4, f); T (34, y); T (1, x); T (1, f); T (2, x)]
*/
IND_TYPE c, cp_0, c459_p_0, cp_1, c459, f, fp_0, f336_p_0, fp_1, f336, h, hp_0, w, wp_0, x, xp_0, x612_p_0, x613_p_0, xp_1, x612_p_1, xp_2, x612, x613, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y429 = 0;
IND_TYPE x614 = 0;
IND_TYPE h174 = 0;
IND_TYPE w297 = 0;
IND_TYPE c460 = 0;
IND_TYPE f337 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5512 ,mem_vec_5513 ,mem_vec_5514 ,mem_vec_5515 ,mem_vec_5516 ,mem_vec_5517 ,mem_vec_5518 ,mem_vec_5519 ,mem_vec_5520 ,mem_vec_5521 ,mem_vec_5522 ,mem_vec_5523 ,mem_vec_5524 ,mem_vec_5525 ,mem_vec_5526 ,mem_vec_5527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x613 = x614, x613_p_0 = 0;
	x613 < x614 + 136;
	x613 += 68, x613_p_0 += 68){
	// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
	// T (f, 1) (128 / 128)
	for (f336 = f337, f336_p_0 = 0;
		f336 < f337 + 128;
		f336 += 128, f336_p_0 += 128){
		// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
		// T (x, 1) (68 / 68)
		for (x612 = x613, x612_p_1 = x613_p_0, x612_p_0 = 0;
			x612 < x613 + 68;
			x612 += 68, x612_p_1 += 68, x612_p_0 += 68){
			// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (y, 34) (136 / 4)
			for (y = y429, yp_0 = 0;
				y < y429 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 68, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f336, fp_1 = f336_p_0, fp_0 = 0;
					f < f336 + 128;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 68, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c459 = c460, c459_p_0 = 0;
						c459 < c460 + 64;
						c459 += 64, c459_p_0 += 64){
						// y = 4, x = 68, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h174, hp_0 = 0;
							h < h174 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x612, xp_2 = x612_p_1, xp_1 = x612_p_0, xp_0 = 0;
								x < x612 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w297, wp_0 = 0;
									w < w297 + 3;
									w += 1, wp_0 += 1){
											mem_vec_5512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c459, cp_1 = c459_p_0, cp_0 = 0;
												c < c459 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5512);
												mem_vec_5512 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5513);
												mem_vec_5513 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5514);
												mem_vec_5514 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5515);
												mem_vec_5515 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5516);
												mem_vec_5516 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5517);
												mem_vec_5517 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5518);
												mem_vec_5518 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5519);
												mem_vec_5519 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5520);
												mem_vec_5520 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5521);
												mem_vec_5521 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5522);
												mem_vec_5522 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5523);
												mem_vec_5523 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5524);
												mem_vec_5524 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5525);
												mem_vec_5525 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5526);
												mem_vec_5526 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5527);
												mem_vec_5527 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5527);
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