#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (2, x); T (2, y); T (2, f); T (34, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c468_p_0, cp_1, c468, f, fp_0, x, xp_0, x780_p_0, x781_p_0, x782_p_0, xp_1, x780_p_1, x781_p_1, xp_2, x780_p_2, xp_3, x780, x781, x782, y, yp_0, y624_p_0, y625_p_0, yp_1, y624_p_1, yp_2, y624, y625;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y626 = 0;
IND_TYPE x783 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c469 = 0;
IND_TYPE f312 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4416 ,mem_vec_4417 ,mem_vec_4418 ,mem_vec_4419 ,mem_vec_4420 ,mem_vec_4421 ,mem_vec_4422 ,mem_vec_4423 ,mem_vec_4424 ,mem_vec_4425 ,mem_vec_4426 ,mem_vec_4427 ,mem_vec_4428 ,mem_vec_4429 ,mem_vec_4430 ,mem_vec_4431 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y625 = y626, y625_p_0 = 0;
	y625 < y626 + 136;
	y625 += 136, y625_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x782 = x783, x782_p_0 = 0;
		x782 < x783 + 136;
		x782 += 136, x782_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y624 = y625, y624_p_1 = y625_p_0, y624_p_0 = 0;
			y624 < y625 + 136;
			y624 += 8, y624_p_1 += 8, y624_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x781 = x782, x781_p_1 = x782_p_0, x781_p_0 = 0;
				x781 < x782 + 136;
				x781 += 4, x781_p_1 += 4, x781_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f312, fp_0 = 0;
					f < f312 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y624, yp_2 = y624_p_1, yp_1 = y624_p_0, yp_0 = 0;
						y < y624 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (4 / 2)
						for (x780 = x781, x780_p_2 = x781_p_1, x780_p_1 = x781_p_0, x780_p_0 = 0;
							x780 < x781 + 4;
							x780 += 2, x780_p_2 += 2, x780_p_1 += 2, x780_p_0 += 2){
							// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c468 = c469, c468_p_0 = 0;
								c468 < c469 + 128;
								c468 += 128, c468_p_0 += 128){
								// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (x, 2) (2 / 1)
								for (x = x780, xp_3 = x780_p_2, xp_2 = x780_p_1, xp_1 = x780_p_0, xp_0 = 0;
									x < x780 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4416 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4417 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4418 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4419 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
												c < c468 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4416);
												mem_vec_4416 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4417);
												mem_vec_4417 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4418);
												mem_vec_4418 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4419);
												mem_vec_4419 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4420);
												mem_vec_4420 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4421);
												mem_vec_4421 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4422);
												mem_vec_4422 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4423);
												mem_vec_4423 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4424);
												mem_vec_4424 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4425);
												mem_vec_4425 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4426);
												mem_vec_4426 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4427);
												mem_vec_4427 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4428);
												mem_vec_4428 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4429);
												mem_vec_4429 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4430);
												mem_vec_4430 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4431);
												mem_vec_4431 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4416);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4417);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4418);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4419);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4420);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4421);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4422);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4423);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4424);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4425);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4426);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4427);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4428);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4429);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4430);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4431);
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