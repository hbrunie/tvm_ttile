#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (2, x); T (2, y); T (2, f); T (34, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c486_p_0, cp_1, c486, f, fp_0, x, xp_0, x810_p_0, x811_p_0, x812_p_0, xp_1, x810_p_1, x811_p_1, xp_2, x810_p_2, xp_3, x810, x811, x812, y, yp_0, y648_p_0, y649_p_0, yp_1, y648_p_1, yp_2, y648, y649;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y650 = 0;
IND_TYPE x813 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c487 = 0;
IND_TYPE f324 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4512 ,mem_vec_4513 ,mem_vec_4514 ,mem_vec_4515 ,mem_vec_4516 ,mem_vec_4517 ,mem_vec_4518 ,mem_vec_4519 ,mem_vec_4520 ,mem_vec_4521 ,mem_vec_4522 ,mem_vec_4523 ,mem_vec_4524 ,mem_vec_4525 ,mem_vec_4526 ,mem_vec_4527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y649 = y650, y649_p_0 = 0;
	y649 < y650 + 136;
	y649 += 8, y649_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x812 = x813, x812_p_0 = 0;
		x812 < x813 + 136;
		x812 += 136, x812_p_0 += 136){
		// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (8 / 8)
		for (y648 = y649, y648_p_1 = y649_p_0, y648_p_0 = 0;
			y648 < y649 + 8;
			y648 += 8, y648_p_1 += 8, y648_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x811 = x812, x811_p_1 = x812_p_0, x811_p_0 = 0;
				x811 < x812 + 136;
				x811 += 4, x811_p_1 += 4, x811_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f324, fp_0 = 0;
					f < f324 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y648, yp_2 = y648_p_1, yp_1 = y648_p_0, yp_0 = 0;
						y < y648 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (4 / 2)
						for (x810 = x811, x810_p_2 = x811_p_1, x810_p_1 = x811_p_0, x810_p_0 = 0;
							x810 < x811 + 4;
							x810 += 2, x810_p_2 += 2, x810_p_1 += 2, x810_p_0 += 2){
							// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (c, 4) (128 / 32)
							for (c486 = c487, c486_p_0 = 0;
								c486 < c487 + 128;
								c486 += 32, c486_p_0 += 32){
								// y = 4, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x810, xp_3 = x810_p_2, xp_2 = x810_p_1, xp_1 = x810_p_0, xp_0 = 0;
									x < x810 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c486, cp_1 = c486_p_0, cp_0 = 0;
												c < c486 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4512);
												mem_vec_4512 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4513);
												mem_vec_4513 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4514);
												mem_vec_4514 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4515);
												mem_vec_4515 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4516);
												mem_vec_4516 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4517);
												mem_vec_4517 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4518);
												mem_vec_4518 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4519);
												mem_vec_4519 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4520);
												mem_vec_4520 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4521);
												mem_vec_4521 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4522);
												mem_vec_4522 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4523);
												mem_vec_4523 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4524);
												mem_vec_4524 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4525);
												mem_vec_4525 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4526);
												mem_vec_4526 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4527);
												mem_vec_4527 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4527);
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