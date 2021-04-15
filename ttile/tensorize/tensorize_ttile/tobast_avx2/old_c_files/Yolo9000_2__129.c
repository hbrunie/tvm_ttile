#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (68, y); T (2, f); T (8, c); T (1, x); T (1, y); T (1, f);
  T (34, x)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, f90_p_0, fp_1, f90, h, hp_0, w, wp_0, x, xp_0, x120_p_0, x121_p_0, xp_1, x120_p_1, xp_2, x120, x121, y, yp_0, y90_p_0, yp_1, y90;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y91 = 0;
IND_TYPE x122 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c91 = 0;
IND_TYPE f91 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 34) (272 / 8)
for (x121 = x122, x121_p_0 = 0;
	x121 < x122 + 272;
	x121 += 8, x121_p_0 += 8){
	// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
	// T (f, 1) (64 / 64)
	for (f90 = f91, f90_p_0 = 0;
		f90 < f91 + 64;
		f90 += 64, f90_p_0 += 64){
		// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
		// T (y, 1) (272 / 272)
		for (y90 = y91, y90_p_0 = 0;
			y90 < y91 + 272;
			y90 += 272, y90_p_0 += 272){
			// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
			// T (x, 1) (8 / 8)
			for (x120 = x121, x120_p_1 = x121_p_0, x120_p_0 = 0;
				x120 < x121 + 8;
				x120 += 8, x120_p_1 += 8, x120_p_0 += 8){
				// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
				// T (c, 8) (32 / 4)
				for (c90 = c91, c90_p_0 = 0;
					c90 < c91 + 32;
					c90 += 4, c90_p_0 += 4){
					// y = 272, x = 8, h = 3, w = 3, c = 4, f = 64
					// T (f, 2) (64 / 32)
					for (f = f90, fp_1 = f90_p_0, fp_0 = 0;
						f < f90 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = 272, x = 8, h = 3, w = 3, c = 4, f = 32
						// T (y, 68) (272 / 4)
						for (y = y90, yp_1 = y90_p_0, yp_0 = 0;
							y < y90 + 272;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = 4, x = 8, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h60, hp_0 = 0;
								h < h60 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 8, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w60, wp_0 = 0;
									w < w60 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 8, h = 1, w = 1, c = 4, f = 32
									// T (x, 8) (8 / 1)
									for (x = x120, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
										x < x120 + 8;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_480 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_481 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_482 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_483 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
													c < c90 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_480);
													mem_vec_480 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_481);
													mem_vec_481 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_482);
													mem_vec_482 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_483);
													mem_vec_483 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_484);
													mem_vec_484 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_485);
													mem_vec_485 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_486);
													mem_vec_486 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_487);
													mem_vec_487 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_488);
													mem_vec_488 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_489);
													mem_vec_489 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_490);
													mem_vec_490 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_491);
													mem_vec_491 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_492);
													mem_vec_492 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_493);
													mem_vec_493 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_494);
													mem_vec_494 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_495);
													mem_vec_495 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_487);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_491);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_495);
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