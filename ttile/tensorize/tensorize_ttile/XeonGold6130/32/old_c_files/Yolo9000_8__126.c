#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (2, x);
  T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, f36_p_0, f37_p_0, fp_1, f36_p_1, fp_2, f36, f37, h, hp_0, w, wp_0, x, xp_0, x27_p_0, xp_1, x27, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y18 = 0;
IND_TYPE x28 = 0;
IND_TYPE h18 = 0;
IND_TYPE w18 = 0;
IND_TYPE c28 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f37 = f38, f37_p_0 = 0;
	f37 < f38 + 256;
	f37 += 256, f37_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f36 = f37, f36_p_1 = f37_p_0, f36_p_0 = 0;
		f36 < f37 + 256;
		f36 += 32, f36_p_1 += 32, f36_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 2) (68 / 34)
		for (x27 = x28, x27_p_0 = 0;
			x27 < x28 + 68;
			x27 += 34, x27_p_0 += 34){
				for (y = y18, yp_0 = 0;
					y < y18 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f36, fp_2 = f36_p_1, fp_1 = f36_p_0, fp_0 = 0;
						f < f36 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c27 = c28, c27_p_0 = 0;
							c27 < c28 + 128;
							c27 += 16, c27_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w18, wp_0 = 0;
								w < w18 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x27, xp_1 = x27_p_0, xp_0 = 0;
									x < x27 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h18, hp_0 = 0;
										h < h18 + 3;
										h += 1, hp_0 += 1){
												mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
													c < c27 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_354);
													mem_vec_354 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_355);
													mem_vec_355 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_356);
													mem_vec_356 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_357);
													mem_vec_357 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_358);
													mem_vec_358 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_359);
													mem_vec_359 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_360);
													mem_vec_360 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_361);
													mem_vec_361 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_362);
													mem_vec_362 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_363);
													mem_vec_363 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_364);
													mem_vec_364 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_365);
													mem_vec_365 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_366);
													mem_vec_366 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_367);
													mem_vec_367 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_368);
													mem_vec_368 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_369);
													mem_vec_369 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_369);
									}
								}
							}
						}
					}
				}
				for (y = y18 + 24, yp_0 = 0;
					y < y18 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f36, fp_2 = f36_p_1, fp_1 = f36_p_0, fp_0 = 0;
						f < f36 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c27 = c28, c27_p_0 = 0;
							c27 < c28 + 128;
							c27 += 16, c27_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w18, wp_0 = 0;
								w < w18 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x27, xp_1 = x27_p_0, xp_0 = 0;
									x < x27 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h18, hp_0 = 0;
										h < h18 + 3;
										h += 1, hp_0 += 1){
												mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
													c < c27 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_370);
													mem_vec_370 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_371);
													mem_vec_371 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_372);
													mem_vec_372 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_373);
													mem_vec_373 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_374);
													mem_vec_374 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_375);
													mem_vec_375 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_376);
													mem_vec_376 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_377);
													mem_vec_377 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_378);
													mem_vec_378 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_379);
													mem_vec_379 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_380);
													mem_vec_380 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_381);
													mem_vec_381 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_382);
													mem_vec_382 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_383);
													mem_vec_383 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_384);
													mem_vec_384 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_385);
													mem_vec_385 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_386);
													mem_vec_386 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_387);
													mem_vec_387 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_388);
													mem_vec_388 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_389);
													mem_vec_389 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_390);
													mem_vec_390 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_391);
													mem_vec_391 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_371);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_372);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_373);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_374);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_375);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_376);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_377);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_378);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_379);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_380);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_381);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_382);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_383);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_384);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_385);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_386);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_387);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_388);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_389);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_390);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_391);
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