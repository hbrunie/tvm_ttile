#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (1, f); T (4, c); T (4, f); T (1, y); T (2, f)]
*/
IND_TYPE c, cp_0, c411_p_0, cp_1, c411, f, fp_0, f414_p_0, f415_p_0, fp_1, f414_p_1, fp_2, f414, f415, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y219_p_0, yp_1, y219;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y220 = 0;
IND_TYPE x210 = 0;
IND_TYPE h165 = 0;
IND_TYPE w159 = 0;
IND_TYPE c412 = 0;
IND_TYPE f416 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2568 ,mem_vec_2569 ,mem_vec_2570 ,mem_vec_2571 ,mem_vec_2572 ,mem_vec_2573 ,mem_vec_2574 ,mem_vec_2575 ,mem_vec_2576 ,mem_vec_2577 ,mem_vec_2578 ,mem_vec_2579 ,mem_vec_2580 ,mem_vec_2581 ,mem_vec_2582 ,mem_vec_2583 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f415 = f416, f415_p_0 = 0;
	f415 < f416 + 256;
	f415 += 128, f415_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 1) (28 / 28)
	for (y219 = y220, y219_p_0 = 0;
		y219 < y220 + 28;
		y219 += 28, y219_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (f, 4) (128 / 32)
		for (f414 = f415, f414_p_1 = f415_p_0, f414_p_0 = 0;
			f414 < f415 + 128;
			f414 += 32, f414_p_1 += 32, f414_p_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (c, 4) (128 / 32)
			for (c411 = c412, c411_p_0 = 0;
				c411 < c412 + 128;
				c411 += 32, c411_p_0 += 32){
				// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f414, fp_2 = f414_p_1, fp_1 = f414_p_0, fp_0 = 0;
					f < f414 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (y, 7) (28 / 4)
					for (y = y219, yp_1 = y219_p_0, yp_0 = 0;
						y < y219 + 28;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x210, xp_0 = 0;
							x < x210 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h165, hp_0 = 0;
								h < h165 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w159, wp_0 = 0;
									w < w159 + 3;
									w += 1, wp_0 += 1){
											mem_vec_2568 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2569 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2570 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2571 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c411, cp_1 = c411_p_0, cp_0 = 0;
												c < c411 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2568);
												mem_vec_2568 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2569);
												mem_vec_2569 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2570);
												mem_vec_2570 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2571);
												mem_vec_2571 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2572);
												mem_vec_2572 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2573);
												mem_vec_2573 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2574);
												mem_vec_2574 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2575);
												mem_vec_2575 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2576);
												mem_vec_2576 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2577);
												mem_vec_2577 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2578);
												mem_vec_2578 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2579);
												mem_vec_2579 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2580);
												mem_vec_2580 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2581);
												mem_vec_2581 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2582);
												mem_vec_2582 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2583);
												mem_vec_2583 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2568);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2569);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2570);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2571);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2572);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2573);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2574);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2575);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2576);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2577);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2578);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2579);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2580);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2581);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2582);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2583);
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