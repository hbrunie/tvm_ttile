#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (17, y); T (1, f); T (2, c); T (2, x); T (4, y); T (2, f);
  T (34, x)]
*/
IND_TYPE c, cp_0, c96_p_0, cp_1, c96, f, fp_0, f96_p_0, fp_1, f96, h, hp_0, w, wp_0, x, xp_0, x128_p_0, x129_p_0, xp_1, x128_p_1, xp_2, x128, x129, y, yp_0, y96_p_0, yp_1, y96;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y97 = 0;
IND_TYPE x130 = 0;
IND_TYPE h64 = 0;
IND_TYPE w64 = 0;
IND_TYPE c97 = 0;
IND_TYPE f97 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 34) (272 / 8)
for (x129 = x130, x129_p_0 = 0;
	x129 < x130 + 272;
	x129 += 8, x129_p_0 += 8){
	// y = 272, x = 8, h = 3, w = 3, c = 32, f = 64
	// T (f, 2) (64 / 32)
	for (f96 = f97, f96_p_0 = 0;
		f96 < f97 + 64;
		f96 += 32, f96_p_0 += 32){
		// y = 272, x = 8, h = 3, w = 3, c = 32, f = 32
		// T (y, 4) (272 / 68)
		for (y96 = y97, y96_p_0 = 0;
			y96 < y97 + 272;
			y96 += 68, y96_p_0 += 68){
			// y = 68, x = 8, h = 3, w = 3, c = 32, f = 32
			// T (x, 2) (8 / 4)
			for (x128 = x129, x128_p_1 = x129_p_0, x128_p_0 = 0;
				x128 < x129 + 8;
				x128 += 4, x128_p_1 += 4, x128_p_0 += 4){
				// y = 68, x = 4, h = 3, w = 3, c = 32, f = 32
				// T (c, 2) (32 / 16)
				for (c96 = c97, c96_p_0 = 0;
					c96 < c97 + 32;
					c96 += 16, c96_p_0 += 16){
					// y = 68, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (f, 1) (32 / 32)
					for (f = f96, fp_1 = f96_p_0, fp_0 = 0;
						f < f96 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = 68, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (y, 17) (68 / 4)
						for (y = y96, yp_1 = y96_p_0, yp_0 = 0;
							y < y96 + 68;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = 4, x = 4, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h64, hp_0 = 0;
								h < h64 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 4, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w64, wp_0 = 0;
									w < w64 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 4, h = 1, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x128, xp_2 = x128_p_1, xp_1 = x128_p_0, xp_0 = 0;
										x < x128 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
													c < c96 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_512);
													mem_vec_512 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_513);
													mem_vec_513 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_514);
													mem_vec_514 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_515);
													mem_vec_515 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_516);
													mem_vec_516 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_517);
													mem_vec_517 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_518);
													mem_vec_518 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_519);
													mem_vec_519 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_520);
													mem_vec_520 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_521);
													mem_vec_521 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_522);
													mem_vec_522 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_523);
													mem_vec_523 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_524);
													mem_vec_524 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_525);
													mem_vec_525 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_526);
													mem_vec_526 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_527);
													mem_vec_527 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_519);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_523);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_524);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_525);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_526);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_527);
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