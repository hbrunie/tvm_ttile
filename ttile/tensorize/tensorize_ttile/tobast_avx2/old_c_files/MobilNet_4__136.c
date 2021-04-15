#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, f); T (7, x); T (7, y); T (1, x); T (1, f); T (128, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, f54_p_0, fp_1, f54, h, hp_0, w, wp_0, x, xp_0, x90_p_0, x91_p_0, x92_p_0, xp_1, x90_p_1, x91_p_1, xp_2, x90_p_2, xp_3, x90, x91, x92, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y36 = 0;
IND_TYPE x93 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c55 = 0;
IND_TYPE f55 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (28 / 14)
for (x92 = x93, x92_p_0 = 0;
	x92 < x93 + 28;
	x92 += 14, x92_p_0 += 14){
	// y = 28, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 128) (128 / 1)
	for (c54 = c55, c54_p_0 = 0;
		c54 < c55 + 128;
		c54 += 1, c54_p_0 += 1){
		// y = 28, x = 14, h = 3, w = 3, c = 1, f = 128
		// T (f, 1) (128 / 128)
		for (f54 = f55, f54_p_0 = 0;
			f54 < f55 + 128;
			f54 += 128, f54_p_0 += 128){
			// y = 28, x = 14, h = 3, w = 3, c = 1, f = 128
			// T (x, 1) (14 / 14)
			for (x91 = x92, x91_p_1 = x92_p_0, x91_p_0 = 0;
				x91 < x92 + 14;
				x91 += 14, x91_p_1 += 14, x91_p_0 += 14){
				// y = 28, x = 14, h = 3, w = 3, c = 1, f = 128
				// T (y, 7) (28 / 4)
				for (y = y36, yp_0 = 0;
					y < y36 + 28;
					y += 4, yp_0 += 4){
					// y = 4, x = 14, h = 3, w = 3, c = 1, f = 128
					// T (x, 7) (14 / 2)
					for (x90 = x91, x90_p_2 = x91_p_1, x90_p_1 = x91_p_0, x90_p_0 = 0;
						x90 < x91 + 14;
						x90 += 2, x90_p_2 += 2, x90_p_1 += 2, x90_p_0 += 2){
						// y = 4, x = 2, h = 3, w = 3, c = 1, f = 128
						// T (f, 4) (128 / 32)
						for (f = f54, fp_1 = f54_p_0, fp_0 = 0;
							f < f54 + 128;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 4, x = 2, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h36, hp_0 = 0;
								h < h36 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 2, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w36, wp_0 = 0;
									w < w36 + 3;
									w += 1, wp_0 += 1){
									// y = 4, x = 2, h = 1, w = 1, c = 1, f = 32
									// T (x, 2) (2 / 1)
									for (x = x90, xp_3 = x90_p_2, xp_2 = x90_p_1, xp_1 = x90_p_0, xp_0 = 0;
										x < x90 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_290 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_291 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
													c < c54 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_288);
													mem_vec_288 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_289);
													mem_vec_289 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_290);
													mem_vec_290 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_291);
													mem_vec_291 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_292);
													mem_vec_292 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_293);
													mem_vec_293 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_294);
													mem_vec_294 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_295);
													mem_vec_295 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_296);
													mem_vec_296 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_297);
													mem_vec_297 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_298);
													mem_vec_298 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_299);
													mem_vec_299 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_300);
													mem_vec_300 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_301);
													mem_vec_301 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_302);
													mem_vec_302 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_303);
													mem_vec_303 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_291);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_292);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_293);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_294);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_295);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_296);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_297);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_298);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_299);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_301);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_302);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_303);
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