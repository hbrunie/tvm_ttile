#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (4, x); T (2, y); T (2, f); T (34, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, x, xp_0, x825_p_0, x826_p_0, x827_p_0, xp_1, x825_p_1, x826_p_1, xp_2, x825_p_2, xp_3, x825, x826, x827, y, yp_0, y660_p_0, y661_p_0, yp_1, y660_p_1, yp_2, y660, y661;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y662 = 0;
IND_TYPE x828 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c496 = 0;
IND_TYPE f330 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4560 ,mem_vec_4561 ,mem_vec_4562 ,mem_vec_4563 ,mem_vec_4564 ,mem_vec_4565 ,mem_vec_4566 ,mem_vec_4567 ,mem_vec_4568 ,mem_vec_4569 ,mem_vec_4570 ,mem_vec_4571 ,mem_vec_4572 ,mem_vec_4573 ,mem_vec_4574 ,mem_vec_4575 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y661 = y662, y661_p_0 = 0;
	y661 < y662 + 136;
	y661 += 136, y661_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x827 = x828, x827_p_0 = 0;
		x827 < x828 + 136;
		x827 += 136, x827_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y660 = y661, y660_p_1 = y661_p_0, y660_p_0 = 0;
			y660 < y661 + 136;
			y660 += 8, y660_p_1 += 8, y660_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x826 = x827, x826_p_1 = x827_p_0, x826_p_0 = 0;
				x826 < x827 + 136;
				x826 += 4, x826_p_1 += 4, x826_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f330, fp_0 = 0;
					f < f330 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y660, yp_2 = y660_p_1, yp_1 = y660_p_0, yp_0 = 0;
						y < y660 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 4) (4 / 1)
						for (x825 = x826, x825_p_2 = x826_p_1, x825_p_1 = x826_p_0, x825_p_0 = 0;
							x825 < x826 + 4;
							x825 += 1, x825_p_2 += 1, x825_p_1 += 1, x825_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c495 = c496, c495_p_0 = 0;
								c495 < c496 + 128;
								c495 += 64, c495_p_0 += 64){
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x825, xp_3 = x825_p_2, xp_2 = x825_p_1, xp_1 = x825_p_0, xp_0 = 0;
									x < x825 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4560 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4561 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4562 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4563 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
												c < c495 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4560);
												mem_vec_4560 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4561);
												mem_vec_4561 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4562);
												mem_vec_4562 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4563);
												mem_vec_4563 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4564);
												mem_vec_4564 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4565);
												mem_vec_4565 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4566);
												mem_vec_4566 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4567);
												mem_vec_4567 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4568);
												mem_vec_4568 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4569);
												mem_vec_4569 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4570);
												mem_vec_4570 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4571);
												mem_vec_4571 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4572);
												mem_vec_4572 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4573);
												mem_vec_4573 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4574);
												mem_vec_4574 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4575);
												mem_vec_4575 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4560);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4561);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4562);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4563);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4564);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4565);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4566);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4567);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4568);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4569);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4570);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4571);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4572);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4573);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4574);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4575);
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