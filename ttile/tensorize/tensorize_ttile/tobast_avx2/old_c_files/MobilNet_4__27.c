#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (1, x); T (7, y); T (14, x); T (4, f); T (2, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f30_p_0, fp_1, f30, h, hp_0, w, wp_0, x, xp_0, x50_p_0, x51_p_0, x52_p_0, xp_1, x50_p_1, x51_p_1, xp_2, x50_p_2, xp_3, x50, x51, x52, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y20 = 0;
IND_TYPE x53 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c31 = 0;
IND_TYPE f31 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (28 / 28)
for (x52 = x53, x52_p_0 = 0;
	x52 < x53 + 28;
	x52 += 28, x52_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c30 = c31, c30_p_0 = 0;
		c30 < c31 + 128;
		c30 += 64, c30_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f30 = f31, f30_p_0 = 0;
			f30 < f31 + 128;
			f30 += 32, f30_p_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (x, 14) (28 / 2)
			for (x51 = x52, x51_p_1 = x52_p_0, x51_p_0 = 0;
				x51 < x52 + 28;
				x51 += 2, x51_p_1 += 2, x51_p_0 += 2){
				// y = 28, x = 2, h = 3, w = 3, c = 64, f = 32
				// T (y, 7) (28 / 4)
				for (y = y20, yp_0 = 0;
					y < y20 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 64, f = 32
					// T (x, 1) (2 / 2)
					for (x50 = x51, x50_p_2 = x51_p_1, x50_p_1 = x51_p_0, x50_p_0 = 0;
						x50 < x51 + 2;
						x50 += 2, x50_p_2 += 2, x50_p_1 += 2, x50_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f30, fp_1 = f30_p_0, fp_0 = 0;
							f < f30 + 32;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x50, xp_3 = x50_p_2, xp_2 = x50_p_1, xp_1 = x50_p_0, xp_0 = 0;
										x < x50 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_160);
													mem_vec_160 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_161);
													mem_vec_161 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_162);
													mem_vec_162 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_163);
													mem_vec_163 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_164);
													mem_vec_164 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_165);
													mem_vec_165 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_166);
													mem_vec_166 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_167);
													mem_vec_167 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_168);
													mem_vec_168 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_169);
													mem_vec_169 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_170);
													mem_vec_170 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_171);
													mem_vec_171 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_172);
													mem_vec_172 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_173);
													mem_vec_173 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_174);
													mem_vec_174 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_175);
													mem_vec_175 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_167);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_168);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_169);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_170);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_171);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_172);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_173);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_174);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_175);
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