#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, f);
  T (16, c); T (8, f)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, f32_p_0, f33_p_0, fp_1, f32_p_1, fp_2, f32, f33, h, hp_0, w, wp_0, x, xp_0, x24_p_0, xp_1, x24, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y16 = 0;
IND_TYPE x25 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f33 = f34, f33_p_0 = 0;
	f33 < f34 + 512;
	f33 += 64, f33_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (c, 16) (256 / 16)
	for (c24 = c25, c24_p_0 = 0;
		c24 < c25 + 256;
		c24 += 16, c24_p_0 += 16){
		// y = 34, x = 34, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f32 = f33, f32_p_1 = f33_p_0, f32_p_0 = 0;
			f32 < f33 + 64;
			f32 += 32, f32_p_1 += 32, f32_p_0 += 32){
				for (y = y16, yp_0 = 0;
					y < y16 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
					// T (x, 2) (34 / 17)
					for (x24 = x25, x24_p_0 = 0;
						x24 < x25 + 34;
						x24 += 17, x24_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f32, fp_2 = f32_p_1, fp_1 = f32_p_0, fp_0 = 0;
							f < f32 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w16, wp_0 = 0;
									w < w16 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
										x < x24 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
													c < c24 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_288);
													mem_vec_288 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_289);
													mem_vec_289 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_290);
													mem_vec_290 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_291);
													mem_vec_291 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_292);
													mem_vec_292 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_293);
													mem_vec_293 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_294);
													mem_vec_294 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_295);
													mem_vec_295 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_296);
													mem_vec_296 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_297);
													mem_vec_297 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_298);
													mem_vec_298 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_299);
													mem_vec_299 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_300);
													mem_vec_300 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_301);
													mem_vec_301 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_302);
													mem_vec_302 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_303);
													mem_vec_303 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_289);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_290);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_291);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_292);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_293);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_294);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_295);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_296);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_297);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_298);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_299);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_300);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_301);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_302);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_303);
									}
								}
							}
						}
					}
				}
				for (y = y16 + 24, yp_0 = 0;
					y < y16 + 24 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
					// T (x, 2) (34 / 17)
					for (x24 = x25, x24_p_0 = 0;
						x24 < x25 + 34;
						x24 += 17, x24_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f32, fp_2 = f32_p_1, fp_1 = f32_p_0, fp_0 = 0;
							f < f32 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w16, wp_0 = 0;
									w < w16 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
										x < x24 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
													c < c24 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_304);
													mem_vec_304 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_305);
													mem_vec_305 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_306);
													mem_vec_306 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_307);
													mem_vec_307 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_308);
													mem_vec_308 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_309);
													mem_vec_309 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_310);
													mem_vec_310 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_311);
													mem_vec_311 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_312);
													mem_vec_312 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_313);
													mem_vec_313 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_314);
													mem_vec_314 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_315);
													mem_vec_315 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_316);
													mem_vec_316 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_317);
													mem_vec_317 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_318);
													mem_vec_318 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_319);
													mem_vec_319 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_320);
													mem_vec_320 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_321);
													mem_vec_321 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_322);
													mem_vec_322 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_323);
													mem_vec_323 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_304);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_305);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_306);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_307);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_308);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_309);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_310);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_311);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_312);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_313);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_314);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_315);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_316);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_317);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_318);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_319);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_320);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_321);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_322);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_323);
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