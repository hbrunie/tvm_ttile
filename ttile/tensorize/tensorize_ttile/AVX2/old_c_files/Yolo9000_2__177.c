#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (2, c); T (2, f); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x)]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x52_p_0, x53_p_0, xp_1, x52_p_1, xp_2, x52, x53, y, yp_0, y39_p_0, yp_1, y39;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y40 = 0;
IND_TYPE x54 = 0;
IND_TYPE h23 = 0;
IND_TYPE w20 = 0;
IND_TYPE c40 = 0;
IND_TYPE f23 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x53 = x54, x53_p_0 = 0;
	x53 < x54 + 272;
	x53 += 272, x53_p_0 += 272){
		for (y39 = y40, y39_p_0 = 0;
			y39 < y40 + 192;
			y39 += 64, y39_p_0 += 64){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x52 = x53, x52_p_1 = x53_p_0, x52_p_0 = 0;
				x52 < x53 + 272;
				x52 += 1, x52_p_1 += 1, x52_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f23, fp_0 = 0;
					f < f23 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c39 = c40, c39_p_0 = 0;
						c39 < c40 + 32;
						c39 += 16, c39_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
							y < y39 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x52, xp_2 = x52_p_1, xp_1 = x52_p_0, xp_0 = 0;
								x < x52 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h23, hp_0 = 0;
									h < h23 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w20, wp_0 = 0;
										w < w20 + 3;
										w += 1, wp_0 += 1){
												mem_vec_276 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_277 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_278 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_279 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
													c < c39 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_276);
													mem_vec_276 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_277);
													mem_vec_277 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_278);
													mem_vec_278 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_279);
													mem_vec_279 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_280);
													mem_vec_280 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_281);
													mem_vec_281 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_282);
													mem_vec_282 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_283);
													mem_vec_283 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_284);
													mem_vec_284 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_285);
													mem_vec_285 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_286);
													mem_vec_286 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_287);
													mem_vec_287 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_288);
													mem_vec_288 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_289);
													mem_vec_289 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_290);
													mem_vec_290 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_291);
													mem_vec_291 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_276);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_277);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_278);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_279);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_280);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_281);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_282);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_283);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_284);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_285);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_286);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_287);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_291);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y39 = y40 + 192, y39_p_0 = 0;
			y39 < y40 + 192 + 80;
			y39 += 80, y39_p_0 += 80){
			// y = 16 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 272) (272 / 1)
			for (x52 = x53, x52_p_1 = x53_p_0, x52_p_0 = 0;
				x52 < x53 + 272;
				x52 += 1, x52_p_1 += 1, x52_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f23, fp_0 = 0;
					f < f23 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c39 = c40, c39_p_0 = 0;
						c39 < c40 + 32;
						c39 += 16, c39_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
							y < y39 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x52, xp_2 = x52_p_1, xp_1 = x52_p_0, xp_0 = 0;
								x < x52 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h23, hp_0 = 0;
									h < h23 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w20, wp_0 = 0;
										w < w20 + 3;
										w += 1, wp_0 += 1){
												mem_vec_292 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_293 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_294 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_295 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
													c < c39 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_292);
													mem_vec_292 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_293);
													mem_vec_293 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_294);
													mem_vec_294 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_295);
													mem_vec_295 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_296);
													mem_vec_296 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_297);
													mem_vec_297 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_298);
													mem_vec_298 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_299);
													mem_vec_299 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_300);
													mem_vec_300 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_301);
													mem_vec_301 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_302);
													mem_vec_302 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_303);
													mem_vec_303 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_304);
													mem_vec_304 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_305);
													mem_vec_305 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_306);
													mem_vec_306 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_307);
													mem_vec_307 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_308);
													mem_vec_308 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_309);
													mem_vec_309 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_310);
													mem_vec_310 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_311);
													mem_vec_311 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_292);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_293);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_294);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_295);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_296);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_297);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_298);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_299);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_300);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_301);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_302);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_303);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_304);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_305);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_306);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_307);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_308);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_309);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_310);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_311);
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