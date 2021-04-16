#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (16, c); T (17, y); T (4, x); T (8, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c556_p_0, c557_p_0, cp_1, c556_p_1, cp_2, c556, c557, f, fp_0, f340_p_0, fp_1, f340, h, hp_0, w, wp_0, x, xp_0, x384_p_0, xp_1, x384, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y256 = 0;
IND_TYPE x385 = 0;
IND_TYPE h196 = 0;
IND_TYPE w220 = 0;
IND_TYPE c558 = 0;
IND_TYPE f341 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3532 ,mem_vec_3533 ,mem_vec_3534 ,mem_vec_3535 ,mem_vec_3536 ,mem_vec_3537 ,mem_vec_3538 ,mem_vec_3539 ,mem_vec_3540 ,mem_vec_3541 ,mem_vec_3542 ,mem_vec_3543 ,mem_vec_3544 ,mem_vec_3545 ,mem_vec_3546 ,mem_vec_3547 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f340 = f341, f340_p_0 = 0;
	f340 < f341 + 256;
	f340 += 256, f340_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (c, 2) (128 / 64)
	for (c557 = c558, c557_p_0 = 0;
		c557 < c558 + 128;
		c557 += 64, c557_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 64, f = 256
		// T (f, 8) (256 / 32)
		for (f = f340, fp_1 = f340_p_0, fp_0 = 0;
			f < f340 + 256;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (x, 4) (68 / 17)
			for (x384 = x385, x384_p_0 = 0;
				x384 < x385 + 68;
				x384 += 17, x384_p_0 += 17){
				// y = 68, x = 17, h = 3, w = 3, c = 64, f = 32
				// T (y, 17) (68 / 4)
				for (y = y256, yp_0 = 0;
					y < y256 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 16) (64 / 4)
					for (c556 = c557, c556_p_1 = c557_p_0, c556_p_0 = 0;
						c556 < c557 + 64;
						c556 += 4, c556_p_1 += 4, c556_p_0 += 4){
						// y = 4, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h196, hp_0 = 0;
							h < h196 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 4, f = 32
							// T (x, 17) (17 / 1)
							for (x = x384, xp_1 = x384_p_0, xp_0 = 0;
								x < x384 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w220, wp_0 = 0;
									w < w220 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3532 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3533 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3534 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3535 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c556, cp_2 = c556_p_1, cp_1 = c556_p_0, cp_0 = 0;
												c < c556 + 4;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3532);
												mem_vec_3532 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3533);
												mem_vec_3533 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3534);
												mem_vec_3534 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3535);
												mem_vec_3535 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3536);
												mem_vec_3536 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3537);
												mem_vec_3537 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3538);
												mem_vec_3538 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3539);
												mem_vec_3539 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3540);
												mem_vec_3540 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3541);
												mem_vec_3541 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3542);
												mem_vec_3542 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3543);
												mem_vec_3543 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3544);
												mem_vec_3544 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3545);
												mem_vec_3545 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3546);
												mem_vec_3546 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3547);
												mem_vec_3547 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3535);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3536);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3537);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3538);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3539);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3540);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3541);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3542);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3543);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3544);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3545);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3546);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3547);
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