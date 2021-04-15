#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, y); T (1, f); T (1, c); T (17, x); T (34, y); T (2, f);
  T (16, x)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f84_p_0, fp_1, f84, h, hp_0, w, wp_0, x, xp_0, x112_p_0, x113_p_0, xp_1, x112_p_1, xp_2, x112, x113, y, yp_0, y84_p_0, yp_1, y84;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y85 = 0;
IND_TYPE x114 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 16) (272 / 17)
for (x113 = x114, x113_p_0 = 0;
	x113 < x114 + 272;
	x113 += 17, x113_p_0 += 17){
	// y = 272, x = 17, h = 3, w = 3, c = 32, f = 64
	// T (f, 2) (64 / 32)
	for (f84 = f85, f84_p_0 = 0;
		f84 < f85 + 64;
		f84 += 32, f84_p_0 += 32){
		// y = 272, x = 17, h = 3, w = 3, c = 32, f = 32
		// T (y, 34) (272 / 8)
		for (y84 = y85, y84_p_0 = 0;
			y84 < y85 + 272;
			y84 += 8, y84_p_0 += 8){
			// y = 8, x = 17, h = 3, w = 3, c = 32, f = 32
			// T (x, 17) (17 / 1)
			for (x112 = x113, x112_p_1 = x113_p_0, x112_p_0 = 0;
				x112 < x113 + 17;
				x112 += 1, x112_p_1 += 1, x112_p_0 += 1){
				// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (c, 1) (32 / 32)
				for (c84 = c85, c84_p_0 = 0;
					c84 < c85 + 32;
					c84 += 32, c84_p_0 += 32){
					// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f84, fp_1 = f84_p_0, fp_0 = 0;
						f < f84 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = 8, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (y, 2) (8 / 4)
						for (y = y84, yp_1 = y84_p_0, yp_0 = 0;
							y < y84 + 8;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h56, hp_0 = 0;
								h < h56 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w56, wp_0 = 0;
									w < w56 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x112, xp_2 = x112_p_1, xp_1 = x112_p_0, xp_0 = 0;
										x < x112 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_448 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_449 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_450 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_451 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
													c < c84 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_448);
													mem_vec_448 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_449);
													mem_vec_449 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_450);
													mem_vec_450 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_451);
													mem_vec_451 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_452);
													mem_vec_452 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_453);
													mem_vec_453 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_454);
													mem_vec_454 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_455);
													mem_vec_455 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_456);
													mem_vec_456 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_457);
													mem_vec_457 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_458);
													mem_vec_458 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_459);
													mem_vec_459 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_460);
													mem_vec_460 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_461);
													mem_vec_461 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_462);
													mem_vec_462 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_463);
													mem_vec_463 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_449);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_450);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_451);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_452);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_453);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_454);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_455);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_456);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_457);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_458);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_459);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_460);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_461);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_462);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_463);
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


}