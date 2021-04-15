#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, f); T (1, x); T (7, y); T (1, f); T (16, c); T (14, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c114_p_0, cp_1, c114, f, fp_0, f152_p_0, f153_p_0, fp_1, f152_p_1, fp_2, f152, f153, h, hp_0, w, wp_0, x, xp_0, x152_p_0, x153_p_0, xp_1, x152_p_1, xp_2, x152, x153, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y76 = 0;
IND_TYPE x154 = 0;
IND_TYPE h76 = 0;
IND_TYPE w76 = 0;
IND_TYPE c115 = 0;
IND_TYPE f154 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f153 = f154, f153_p_0 = 0;
	f153 < f154 + 256;
	f153 += 64, f153_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 14) (28 / 2)
	for (x153 = x154, x153_p_0 = 0;
		x153 < x154 + 28;
		x153 += 2, x153_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 64
		// T (c, 16) (256 / 16)
		for (c114 = c115, c114_p_0 = 0;
			c114 < c115 + 256;
			c114 += 16, c114_p_0 += 16){
			// y = 28, x = 2, h = 3, w = 3, c = 16, f = 64
			// T (f, 1) (64 / 64)
			for (f152 = f153, f152_p_1 = f153_p_0, f152_p_0 = 0;
				f152 < f153 + 64;
				f152 += 64, f152_p_1 += 64, f152_p_0 += 64){
				// y = 28, x = 2, h = 3, w = 3, c = 16, f = 64
				// T (y, 7) (28 / 4)
				for (y = y76, yp_0 = 0;
					y < y76 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 16, f = 64
					// T (x, 1) (2 / 2)
					for (x152 = x153, x152_p_1 = x153_p_0, x152_p_0 = 0;
						x152 < x153 + 2;
						x152 += 2, x152_p_1 += 2, x152_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (f, 2) (64 / 32)
						for (f = f152, fp_2 = f152_p_1, fp_1 = f152_p_0, fp_0 = 0;
							f < f152 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h76, hp_0 = 0;
								h < h76 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w76, wp_0 = 0;
									w < w76 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 2, h = 1, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x152, xp_2 = x152_p_1, xp_1 = x152_p_0, xp_0 = 0;
										x < x152 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_608 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_609 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_610 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_611 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c114, cp_1 = c114_p_0, cp_0 = 0;
													c < c114 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_608);
													mem_vec_608 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_609);
													mem_vec_609 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_610);
													mem_vec_610 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_611);
													mem_vec_611 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_612);
													mem_vec_612 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_613);
													mem_vec_613 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_614);
													mem_vec_614 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_615);
													mem_vec_615 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_616);
													mem_vec_616 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_617);
													mem_vec_617 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_618);
													mem_vec_618 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_619);
													mem_vec_619 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_620);
													mem_vec_620 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_621);
													mem_vec_621 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_622);
													mem_vec_622 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_623);
													mem_vec_623 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_611);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_615);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_623);
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