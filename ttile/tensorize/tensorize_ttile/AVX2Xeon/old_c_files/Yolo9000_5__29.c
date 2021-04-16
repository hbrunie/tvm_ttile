#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (17, y); T (2, f); T (68, x); T (2, y); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, f, fp_0, x, xp_0, x105_p_0, x106_p_0, x107_p_0, xp_1, x105_p_1, x106_p_1, xp_2, x105_p_2, xp_3, x105, x106, x107, y, yp_0, y84_p_0, y85_p_0, yp_1, y84_p_1, yp_2, y84, y85;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y86 = 0;
IND_TYPE x108 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c64 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y85 = y86, y85_p_0 = 0;
	y85 < y86 + 136;
	y85 += 136, y85_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 2) (136 / 68)
	for (x107 = x108, x107_p_0 = 0;
		x107 < x108 + 136;
		x107 += 68, x107_p_0 += 68){
		// y = 136, x = 68, h = 1, w = 1, c = 128, f = 64
		// T (y, 2) (136 / 68)
		for (y84 = y85, y84_p_1 = y85_p_0, y84_p_0 = 0;
			y84 < y85 + 136;
			y84 += 68, y84_p_1 += 68, y84_p_0 += 68){
			// y = 68, x = 68, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (68 / 1)
			for (x106 = x107, x106_p_1 = x107_p_0, x106_p_0 = 0;
				x106 < x107 + 68;
				x106 += 1, x106_p_1 += 1, x106_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f42, fp_0 = 0;
					f < f42 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y84, yp_2 = y84_p_1, yp_1 = y84_p_0, yp_0 = 0;
						y < y84 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x105 = x106, x105_p_2 = x106_p_1, x105_p_1 = x106_p_0, x105_p_0 = 0;
							x105 < x106 + 1;
							x105 += 1, x105_p_2 += 1, x105_p_1 += 1, x105_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c63 = c64, c63_p_0 = 0;
								c63 < c64 + 128;
								c63 += 64, c63_p_0 += 64){
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x105, xp_3 = x105_p_2, xp_2 = x105_p_1, xp_1 = x105_p_0, xp_0 = 0;
									x < x105 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_456 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_457 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_458 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_459 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
												c < c63 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_456);
												mem_vec_456 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_457);
												mem_vec_457 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_458);
												mem_vec_458 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_459);
												mem_vec_459 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_460);
												mem_vec_460 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_461);
												mem_vec_461 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_462);
												mem_vec_462 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_463);
												mem_vec_463 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_464);
												mem_vec_464 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_465);
												mem_vec_465 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_466);
												mem_vec_466 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_467);
												mem_vec_467 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_468);
												mem_vec_468 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_469);
												mem_vec_469 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_470);
												mem_vec_470 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_471);
												mem_vec_471 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_456);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_457);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_458);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_459);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_460);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_461);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_462);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_463);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_464);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_465);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_466);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_467);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_468);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_469);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_470);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_471);
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