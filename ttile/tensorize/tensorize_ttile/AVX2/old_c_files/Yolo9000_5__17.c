#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (4, x); T (8, c);
  T (1, x); T (2, y); T (2, f); T (34, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c453_p_0, cp_1, c453, f, fp_0, x, xp_0, x755_p_0, x756_p_0, x757_p_0, xp_1, x755_p_1, x756_p_1, xp_2, x755_p_2, xp_3, x755, x756, x757, y, yp_0, y604_p_0, y605_p_0, yp_1, y604_p_1, yp_2, y604, y605;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y606 = 0;
IND_TYPE x758 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c454 = 0;
IND_TYPE f302 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,mem_vec_4345 ,mem_vec_4346 ,mem_vec_4347 ,mem_vec_4348 ,mem_vec_4349 ,mem_vec_4350 ,mem_vec_4351 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y605 = y606, y605_p_0 = 0;
	y605 < y606 + 136;
	y605 += 136, y605_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x757 = x758, x757_p_0 = 0;
		x757 < x758 + 136;
		x757 += 136, x757_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y604 = y605, y604_p_1 = y605_p_0, y604_p_0 = 0;
			y604 < y605 + 136;
			y604 += 8, y604_p_1 += 8, y604_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x756 = x757, x756_p_1 = x757_p_0, x756_p_0 = 0;
				x756 < x757 + 136;
				x756 += 4, x756_p_1 += 4, x756_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f302, fp_0 = 0;
					f < f302 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y604, yp_2 = y604_p_1, yp_1 = y604_p_0, yp_0 = 0;
						y < y604 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (4 / 4)
						for (x755 = x756, x755_p_2 = x756_p_1, x755_p_1 = x756_p_0, x755_p_0 = 0;
							x755 < x756 + 4;
							x755 += 4, x755_p_2 += 4, x755_p_1 += 4, x755_p_0 += 4){
							// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
							// T (c, 8) (128 / 16)
							for (c453 = c454, c453_p_0 = 0;
								c453 < c454 + 128;
								c453 += 16, c453_p_0 += 16){
								// y = 4, x = 4, h = 1, w = 1, c = 16, f = 32
								// T (x, 4) (4 / 1)
								for (x = x755, xp_3 = x755_p_2, xp_2 = x755_p_1, xp_1 = x755_p_0, xp_0 = 0;
									x < x755 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4336 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4337 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4338 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4339 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c453, cp_1 = c453_p_0, cp_0 = 0;
												c < c453 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4336);
												mem_vec_4336 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4337);
												mem_vec_4337 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4338);
												mem_vec_4338 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4339);
												mem_vec_4339 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4340);
												mem_vec_4340 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4341);
												mem_vec_4341 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4342);
												mem_vec_4342 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4343);
												mem_vec_4343 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4344);
												mem_vec_4344 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4345);
												mem_vec_4345 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4346);
												mem_vec_4346 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4347);
												mem_vec_4347 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4348);
												mem_vec_4348 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4349);
												mem_vec_4349 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4350);
												mem_vec_4350 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4351);
												mem_vec_4351 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4343);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4351);
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