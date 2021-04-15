#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (2, f); T (1, x); T (7, y); T (1, x); T (2, f); T (16, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, f102_p_0, fp_1, f102, h, hp_0, w, wp_0, x, xp_0, x170_p_0, x171_p_0, x172_p_0, xp_1, x170_p_1, x171_p_1, xp_2, x170_p_2, xp_3, x170, x171, x172, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y68 = 0;
IND_TYPE x173 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c103 = 0;
IND_TYPE f103 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 7) (28 / 4)
for (x172 = x173, x172_p_0 = 0;
	x172 < x173 + 28;
	x172 += 4, x172_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 128, f = 128
	// T (c, 16) (128 / 8)
	for (c102 = c103, c102_p_0 = 0;
		c102 < c103 + 128;
		c102 += 8, c102_p_0 += 8){
		// y = 28, x = 4, h = 3, w = 3, c = 8, f = 128
		// T (f, 2) (128 / 64)
		for (f102 = f103, f102_p_0 = 0;
			f102 < f103 + 128;
			f102 += 64, f102_p_0 += 64){
			// y = 28, x = 4, h = 3, w = 3, c = 8, f = 64
			// T (x, 1) (4 / 4)
			for (x171 = x172, x171_p_1 = x172_p_0, x171_p_0 = 0;
				x171 < x172 + 4;
				x171 += 4, x171_p_1 += 4, x171_p_0 += 4){
				// y = 28, x = 4, h = 3, w = 3, c = 8, f = 64
				// T (y, 7) (28 / 4)
				for (y = y68, yp_0 = 0;
					y < y68 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 4, h = 3, w = 3, c = 8, f = 64
					// T (x, 1) (4 / 4)
					for (x170 = x171, x170_p_2 = x171_p_1, x170_p_1 = x171_p_0, x170_p_0 = 0;
						x170 < x171 + 4;
						x170 += 4, x170_p_2 += 4, x170_p_1 += 4, x170_p_0 += 4){
						// y = 4, x = 4, h = 3, w = 3, c = 8, f = 64
						// T (f, 2) (64 / 32)
						for (f = f102, fp_1 = f102_p_0, fp_0 = 0;
							f < f102 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 4, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h68, hp_0 = 0;
								h < h68 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 4, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w68, wp_0 = 0;
									w < w68 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 4, h = 1, w = 1, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x170, xp_3 = x170_p_2, xp_2 = x170_p_1, xp_1 = x170_p_0, xp_0 = 0;
										x < x170 + 4;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_544 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_545 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_546 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_547 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
													c < c102 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_544);
													mem_vec_544 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_545);
													mem_vec_545 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_546);
													mem_vec_546 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_547);
													mem_vec_547 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_548);
													mem_vec_548 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_549);
													mem_vec_549 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_550);
													mem_vec_550 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_551);
													mem_vec_551 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_552);
													mem_vec_552 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_553);
													mem_vec_553 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_554);
													mem_vec_554 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_555);
													mem_vec_555 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_556);
													mem_vec_556 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_557);
													mem_vec_557 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_558);
													mem_vec_558 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_559);
													mem_vec_559 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_544);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_545);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_546);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_547);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_548);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_549);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_550);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_551);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_552);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_553);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_554);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_555);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_559);
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