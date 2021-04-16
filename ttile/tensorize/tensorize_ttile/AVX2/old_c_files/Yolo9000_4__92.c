#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (68, x);
  T (3, h); T (4, c); T (4, f); T (34, y); T (1, x); T (1, f); T (2, x)]
*/
IND_TYPE c, cp_0, c465_p_0, cp_1, c465, f, fp_0, f342_p_0, fp_1, f342, h, hp_0, w, wp_0, x, xp_0, x620_p_0, x621_p_0, xp_1, x620_p_1, xp_2, x620, x621, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y433 = 0;
IND_TYPE x622 = 0;
IND_TYPE h178 = 0;
IND_TYPE w301 = 0;
IND_TYPE c466 = 0;
IND_TYPE f343 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5544 ,mem_vec_5545 ,mem_vec_5546 ,mem_vec_5547 ,mem_vec_5548 ,mem_vec_5549 ,mem_vec_5550 ,mem_vec_5551 ,mem_vec_5552 ,mem_vec_5553 ,mem_vec_5554 ,mem_vec_5555 ,mem_vec_5556 ,mem_vec_5557 ,mem_vec_5558 ,mem_vec_5559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x621 = x622, x621_p_0 = 0;
	x621 < x622 + 136;
	x621 += 68, x621_p_0 += 68){
	// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
	// T (f, 1) (128 / 128)
	for (f342 = f343, f342_p_0 = 0;
		f342 < f343 + 128;
		f342 += 128, f342_p_0 += 128){
		// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
		// T (x, 1) (68 / 68)
		for (x620 = x621, x620_p_1 = x621_p_0, x620_p_0 = 0;
			x620 < x621 + 68;
			x620 += 68, x620_p_1 += 68, x620_p_0 += 68){
			// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (y, 34) (136 / 4)
			for (y = y433, yp_0 = 0;
				y < y433 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 68, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f342, fp_1 = f342_p_0, fp_0 = 0;
					f < f342 + 128;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 68, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c465 = c466, c465_p_0 = 0;
						c465 < c466 + 64;
						c465 += 16, c465_p_0 += 16){
						// y = 4, x = 68, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h178, hp_0 = 0;
							h < h178 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 16, f = 32
							// T (x, 68) (68 / 1)
							for (x = x620, xp_2 = x620_p_1, xp_1 = x620_p_0, xp_0 = 0;
								x < x620 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w301, wp_0 = 0;
									w < w301 + 3;
									w += 1, wp_0 += 1){
											mem_vec_5544 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5545 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5546 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5547 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c465, cp_1 = c465_p_0, cp_0 = 0;
												c < c465 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5544);
												mem_vec_5544 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5545);
												mem_vec_5545 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5546);
												mem_vec_5546 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5547);
												mem_vec_5547 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5548);
												mem_vec_5548 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5549);
												mem_vec_5549 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5550);
												mem_vec_5550 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5551);
												mem_vec_5551 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5552);
												mem_vec_5552 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5553);
												mem_vec_5553 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5554);
												mem_vec_5554 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5555);
												mem_vec_5555 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5556);
												mem_vec_5556 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5557);
												mem_vec_5557 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5558);
												mem_vec_5558 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5559);
												mem_vec_5559 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5544);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5545);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5546);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5547);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5548);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5549);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5550);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5551);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5552);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5553);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5554);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5555);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5556);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5557);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5558);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5559);
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