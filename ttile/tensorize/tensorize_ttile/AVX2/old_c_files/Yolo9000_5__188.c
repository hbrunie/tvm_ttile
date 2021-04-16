#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (8, c);
  T (2, x); T (2, y); T (2, f); T (34, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c477_p_0, cp_1, c477, f, fp_0, x, xp_0, x795_p_0, x796_p_0, x797_p_0, xp_1, x795_p_1, x796_p_1, xp_2, x795_p_2, xp_3, x795, x796, x797, y, yp_0, y636_p_0, y637_p_0, yp_1, y636_p_1, yp_2, y636, y637;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y638 = 0;
IND_TYPE x798 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c478 = 0;
IND_TYPE f318 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4464 ,mem_vec_4465 ,mem_vec_4466 ,mem_vec_4467 ,mem_vec_4468 ,mem_vec_4469 ,mem_vec_4470 ,mem_vec_4471 ,mem_vec_4472 ,mem_vec_4473 ,mem_vec_4474 ,mem_vec_4475 ,mem_vec_4476 ,mem_vec_4477 ,mem_vec_4478 ,mem_vec_4479 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y637 = y638, y637_p_0 = 0;
	y637 < y638 + 136;
	y637 += 136, y637_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x797 = x798, x797_p_0 = 0;
		x797 < x798 + 136;
		x797 += 136, x797_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y636 = y637, y636_p_1 = y637_p_0, y636_p_0 = 0;
			y636 < y637 + 136;
			y636 += 8, y636_p_1 += 8, y636_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x796 = x797, x796_p_1 = x797_p_0, x796_p_0 = 0;
				x796 < x797 + 136;
				x796 += 4, x796_p_1 += 4, x796_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f318, fp_0 = 0;
					f < f318 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y636, yp_2 = y636_p_1, yp_1 = y636_p_0, yp_0 = 0;
						y < y636 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (4 / 2)
						for (x795 = x796, x795_p_2 = x796_p_1, x795_p_1 = x796_p_0, x795_p_0 = 0;
							x795 < x796 + 4;
							x795 += 2, x795_p_2 += 2, x795_p_1 += 2, x795_p_0 += 2){
							// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (c, 8) (128 / 16)
							for (c477 = c478, c477_p_0 = 0;
								c477 < c478 + 128;
								c477 += 16, c477_p_0 += 16){
								// y = 4, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x795, xp_3 = x795_p_2, xp_2 = x795_p_1, xp_1 = x795_p_0, xp_0 = 0;
									x < x795 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4464 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4465 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4466 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4467 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c477, cp_1 = c477_p_0, cp_0 = 0;
												c < c477 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4464);
												mem_vec_4464 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4465);
												mem_vec_4465 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4466);
												mem_vec_4466 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4467);
												mem_vec_4467 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4468);
												mem_vec_4468 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4469);
												mem_vec_4469 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4470);
												mem_vec_4470 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4471);
												mem_vec_4471 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4472);
												mem_vec_4472 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4473);
												mem_vec_4473 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4474);
												mem_vec_4474 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4475);
												mem_vec_4475 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4476);
												mem_vec_4476 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4477);
												mem_vec_4477 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4478);
												mem_vec_4478 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4479);
												mem_vec_4479 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4464);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4465);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4466);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4467);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4468);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4469);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4470);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4471);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4472);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4473);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4474);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4475);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4479);
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