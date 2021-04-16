#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (17, y); T (2, f); T (68, x); T (2, y); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, x, xp_0, x100_p_0, x101_p_0, x102_p_0, xp_1, x100_p_1, x101_p_1, xp_2, x100_p_2, xp_3, x100, x101, x102, y, yp_0, y80_p_0, y81_p_0, yp_1, y80_p_1, yp_2, y80, y81;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y82 = 0;
IND_TYPE x103 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y81 = y82, y81_p_0 = 0;
	y81 < y82 + 136;
	y81 += 136, y81_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 2) (136 / 68)
	for (x102 = x103, x102_p_0 = 0;
		x102 < x103 + 136;
		x102 += 68, x102_p_0 += 68){
		// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
		// T (y, 2) (136 / 68)
		for (y80 = y81, y80_p_1 = y81_p_0, y80_p_0 = 0;
			y80 < y81 + 136;
			y80 += 68, y80_p_1 += 68, y80_p_0 += 68){
			// y = 68, x = 68, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (68 / 1)
			for (x101 = x102, x101_p_1 = x102_p_0, x101_p_0 = 0;
				x101 < x102 + 68;
				x101 += 1, x101_p_1 += 1, x101_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f40, fp_0 = 0;
					f < f40 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y80, yp_2 = y80_p_1, yp_1 = y80_p_0, yp_0 = 0;
						y < y80 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x100 = x101, x100_p_2 = x101_p_1, x100_p_1 = x101_p_0, x100_p_0 = 0;
							x100 < x101 + 1;
							x100 += 1, x100_p_2 += 1, x100_p_1 += 1, x100_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c60 = c61, c60_p_0 = 0;
								c60 < c61 + 128;
								c60 += 128, c60_p_0 += 128){
								// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x100, xp_3 = x100_p_2, xp_2 = x100_p_1, xp_1 = x100_p_0, xp_0 = 0;
									x < x100 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_440 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_441 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_442 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_443 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
												c < c60 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_440);
												mem_vec_440 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_441);
												mem_vec_441 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_442);
												mem_vec_442 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_443);
												mem_vec_443 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_444);
												mem_vec_444 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_445);
												mem_vec_445 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_446);
												mem_vec_446 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_447);
												mem_vec_447 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_448);
												mem_vec_448 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_449);
												mem_vec_449 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_450);
												mem_vec_450 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_451);
												mem_vec_451 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_452);
												mem_vec_452 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_453);
												mem_vec_453 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_454);
												mem_vec_454 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_455);
												mem_vec_455 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_440);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_441);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_442);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_443);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_444);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_445);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_446);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_447);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_448);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_449);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_450);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_451);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_452);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_453);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_454);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_455);
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