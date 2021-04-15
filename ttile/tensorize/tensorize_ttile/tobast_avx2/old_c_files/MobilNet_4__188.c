#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, f); T (2, x); T (7, y); T (14, x); T (4, f); T (16, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, f42_p_0, fp_1, f42, h, hp_0, w, wp_0, x, xp_0, x70_p_0, x71_p_0, x72_p_0, xp_1, x70_p_1, x71_p_1, xp_2, x70_p_2, xp_3, x70, x71, x72, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y28 = 0;
IND_TYPE x73 = 0;
IND_TYPE h28 = 0;
IND_TYPE w28 = 0;
IND_TYPE c43 = 0;
IND_TYPE f43 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (28 / 28)
for (x72 = x73, x72_p_0 = 0;
	x72 < x73 + 28;
	x72 += 28, x72_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (c, 16) (128 / 8)
	for (c42 = c43, c42_p_0 = 0;
		c42 < c43 + 128;
		c42 += 8, c42_p_0 += 8){
		// y = 28, x = 28, h = 3, w = 3, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f42 = f43, f42_p_0 = 0;
			f42 < f43 + 128;
			f42 += 32, f42_p_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 8, f = 32
			// T (x, 14) (28 / 2)
			for (x71 = x72, x71_p_1 = x72_p_0, x71_p_0 = 0;
				x71 < x72 + 28;
				x71 += 2, x71_p_1 += 2, x71_p_0 += 2){
				// y = 28, x = 2, h = 3, w = 3, c = 8, f = 32
				// T (y, 7) (28 / 4)
				for (y = y28, yp_0 = 0;
					y < y28 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 2, h = 3, w = 3, c = 8, f = 32
					// T (x, 2) (2 / 1)
					for (x70 = x71, x70_p_2 = x71_p_1, x70_p_1 = x71_p_0, x70_p_0 = 0;
						x70 < x71 + 2;
						x70 += 1, x70_p_2 += 1, x70_p_1 += 1, x70_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (f, 1) (32 / 32)
						for (f = f42, fp_1 = f42_p_0, fp_0 = 0;
							f < f42 + 32;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x70, xp_3 = x70_p_2, xp_2 = x70_p_1, xp_1 = x70_p_0, xp_0 = 0;
										x < x70 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
													c < c42 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_224);
													mem_vec_224 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_225);
													mem_vec_225 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_226);
													mem_vec_226 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_227);
													mem_vec_227 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_228);
													mem_vec_228 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_229);
													mem_vec_229 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_230);
													mem_vec_230 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_231);
													mem_vec_231 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_232);
													mem_vec_232 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_233);
													mem_vec_233 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_234);
													mem_vec_234 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_235);
													mem_vec_235 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_236);
													mem_vec_236 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_237);
													mem_vec_237 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_238);
													mem_vec_238 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_239);
													mem_vec_239 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_224);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_225);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_226);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_227);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_228);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_229);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_230);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_231);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_232);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_233);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_234);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_235);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_236);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_237);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_238);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_239);
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