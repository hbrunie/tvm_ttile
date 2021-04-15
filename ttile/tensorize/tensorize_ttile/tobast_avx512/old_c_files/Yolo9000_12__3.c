#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (4, f);
  T (64, c); T (1, f)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, f72_p_0, f73_p_0, fp_1, f72_p_1, fp_2, f72, f73, h, hp_0, w, wp_0, x, xp_0, x54_p_0, xp_1, x54, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y36 = 0;
IND_TYPE x55 = 0;
IND_TYPE h28 = 0;
IND_TYPE w34 = 0;
IND_TYPE c55 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f73 = f74, f73_p_0 = 0;
	f73 < f74 + 512;
	f73 += 512, f73_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 64) (256 / 4)
	for (c54 = c55, c54_p_0 = 0;
		c54 < c55 + 256;
		c54 += 4, c54_p_0 += 4){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
		// T (f, 4) (512 / 128)
		for (f72 = f73, f72_p_1 = f73_p_0, f72_p_0 = 0;
			f72 < f73 + 512;
			f72 += 128, f72_p_1 += 128, f72_p_0 += 128){
				for (y = y36, yp_0 = 0;
					y < y36 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 128
					// T (x, 17) (34 / 2)
					for (x54 = x55, x54_p_0 = 0;
						x54 < x55 + 34;
						x54 += 2, x54_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 128
						// T (f, 4) (128 / 32)
						for (f = f72, fp_2 = f72_p_1, fp_1 = f72_p_0, fp_0 = 0;
							f < f72 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w34, wp_0 = 0;
									w < w34 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
										x < x54 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
													c < c54 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_336);
													mem_vec_336 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_337);
													mem_vec_337 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_338);
													mem_vec_338 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_339);
													mem_vec_339 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_340);
													mem_vec_340 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_341);
													mem_vec_341 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_342);
													mem_vec_342 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_343);
													mem_vec_343 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_344);
													mem_vec_344 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_345);
													mem_vec_345 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_346);
													mem_vec_346 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_347);
													mem_vec_347 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_348);
													mem_vec_348 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_349);
													mem_vec_349 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_350);
													mem_vec_350 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_351);
													mem_vec_351 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_337);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_338);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_339);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_340);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_341);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_351);
									}
								}
							}
						}
					}
				}
				for (y = y36 + 24, yp_0 = 0;
					y < y36 + 24 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 128
					// T (x, 17) (34 / 2)
					for (x54 = x55, x54_p_0 = 0;
						x54 < x55 + 34;
						x54 += 2, x54_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 128
						// T (f, 4) (128 / 32)
						for (f = f72, fp_2 = f72_p_1, fp_1 = f72_p_0, fp_0 = 0;
							f < f72 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h28, hp_0 = 0;
								h < h28 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w34, wp_0 = 0;
									w < w34 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
										x < x54 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
													c < c54 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_352);
													mem_vec_352 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_353);
													mem_vec_353 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_354);
													mem_vec_354 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_355);
													mem_vec_355 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_356);
													mem_vec_356 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_357);
													mem_vec_357 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_358);
													mem_vec_358 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_359);
													mem_vec_359 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_360);
													mem_vec_360 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_361);
													mem_vec_361 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_362);
													mem_vec_362 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_363);
													mem_vec_363 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_364);
													mem_vec_364 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_365);
													mem_vec_365 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_366);
													mem_vec_366 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_367);
													mem_vec_367 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_368);
													mem_vec_368 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_369);
													mem_vec_369 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_370);
													mem_vec_370 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_371);
													mem_vec_371 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_369);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_371);
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