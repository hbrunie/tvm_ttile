#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (1, f);
  T (256, c); T (16, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f40_p_0, f41_p_0, fp_1, f40_p_1, fp_2, f40, f41, h, hp_0, w, wp_0, x, xp_0, x30_p_0, xp_1, x30, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y20 = 0;
IND_TYPE x31 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c31 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f41 = f42, f41_p_0 = 0;
	f41 < f42 + 1024;
	f41 += 64, f41_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 256) (512 / 2)
	for (c30 = c31, c30_p_0 = 0;
		c30 < c31 + 512;
		c30 += 2, c30_p_0 += 2){
		// y = 17, x = 17, h = 3, w = 3, c = 2, f = 64
		// T (f, 1) (64 / 64)
		for (f40 = f41, f40_p_1 = f41_p_0, f40_p_0 = 0;
			f40 < f41 + 64;
			f40 += 64, f40_p_1 += 64, f40_p_0 += 64){
				for (y = y20, yp_0 = 0;
					y < y20 + 9;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
					// T (x, 1) (17 / 17)
					for (x30 = x31, x30_p_0 = 0;
						x30 < x31 + 17;
						x30 += 17, x30_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
						// T (f, 1) (64 / 64)
						for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
							f < f40 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 64
									// T (x, 17) (17 / 1)
									for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
										x < x30 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_340);
													mem_vec_340 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_341);
													mem_vec_341 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_342);
													mem_vec_342 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_343);
													mem_vec_343 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_344);
													mem_vec_344 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_345);
													mem_vec_345 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_346);
													mem_vec_346 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_347);
													mem_vec_347 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_348);
													mem_vec_348 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_349);
													mem_vec_349 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_350);
													mem_vec_350 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_351);
													mem_vec_351 = vec_18;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_351);
									}
								}
							}
						}
					}
				}
				for (y = y20 + 9, yp_0 = 0;
					y < y20 + 9 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
					// T (x, 1) (17 / 17)
					for (x30 = x31, x30_p_0 = 0;
						x30 < x31 + 17;
						x30 += 17, x30_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
						// T (f, 1) (64 / 64)
						for (f = f40, fp_2 = f40_p_1, fp_1 = f40_p_0, fp_0 = 0;
							f < f40 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h20, hp_0 = 0;
								h < h20 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 64
									// T (x, 17) (17 / 1)
									for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
										x < x30 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
													c < c30 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_352);
													mem_vec_352 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_353);
													mem_vec_353 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_354);
													mem_vec_354 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_355);
													mem_vec_355 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_356);
													mem_vec_356 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_357);
													mem_vec_357 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_358);
													mem_vec_358 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_359);
													mem_vec_359 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_360);
													mem_vec_360 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_361);
													mem_vec_361 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_362);
													mem_vec_362 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_363);
													mem_vec_363 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_364);
													mem_vec_364 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_365);
													mem_vec_365 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_366);
													mem_vec_366 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_367);
													mem_vec_367 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_367);
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