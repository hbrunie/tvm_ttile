#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (4, y); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y33_p_0, yp_1, y33;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y34 = 0;
IND_TYPE x22 = 0;
IND_TYPE h22 = 0;
IND_TYPE w22 = 0;
IND_TYPE c34 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y33 = y34, y33_p_0 = 0;
		y33 < y34 + 52;
		y33 += 52, y33_p_0 += 52){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c33 = c34, c33_p_0 = 0;
			c33 < c34 + 32;
			c33 += 32, c33_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
				y < y33 + 52;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x22, xp_0 = 0;
					x < x22 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h22, hp_0 = 0;
						h < h22 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w22, wp_0 = 0;
							w < w22 + 3;
							w += 1, wp_0 += 1){
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
									mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
										c < c33 + 32;
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
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_352);
										mem_vec_352 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_353);
										mem_vec_353 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_354);
										mem_vec_354 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_355);
										mem_vec_355 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_356);
										mem_vec_356 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_357);
										mem_vec_357 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_358);
										mem_vec_358 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_359);
										mem_vec_359 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_360);
										mem_vec_360 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_361);
										mem_vec_361 = vec_40;
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
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_361);
						}
					}
				}
			}
		}
	}
	for (y33 = y34 + 52, y33_p_0 = 0;
		y33 < y34 + 52 + 60;
		y33 += 60, y33_p_0 += 60){
		// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c33 = c34, c33_p_0 = 0;
			c33 < c34 + 32;
			c33 += 32, c33_p_0 += 32){
			// y = 4 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
				y < y33 + 60;
				y += 15, yp_1 += 15, yp_0 += 15){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x22, xp_0 = 0;
					x < x22 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h22, hp_0 = 0;
						h < h22 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w22, wp_0 = 0;
							w < w22 + 3;
							w += 1, wp_0 += 1){
									mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
									mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
										c < c33 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_362);
										mem_vec_362 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_363);
										mem_vec_363 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_364);
										mem_vec_364 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_365);
										mem_vec_365 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_366);
										mem_vec_366 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_367);
										mem_vec_367 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_368);
										mem_vec_368 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_369);
										mem_vec_369 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_370);
										mem_vec_370 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_371);
										mem_vec_371 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_372);
										mem_vec_372 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_373);
										mem_vec_373 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_374);
										mem_vec_374 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_375);
										mem_vec_375 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_376);
										mem_vec_376 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_377);
										mem_vec_377 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_378);
										mem_vec_378 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_379);
										mem_vec_379 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_380);
										mem_vec_380 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_381);
										mem_vec_381 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_382);
										mem_vec_382 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_383);
										mem_vec_383 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_384);
										mem_vec_384 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_385);
										mem_vec_385 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_386);
										mem_vec_386 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_387);
										mem_vec_387 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_388);
										mem_vec_388 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_389);
										mem_vec_389 = vec_43;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
										vec_45 = _mm512_set1_ps(scal_14);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_390);
										mem_vec_390 = vec_44;



										vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_391);
										mem_vec_391 = vec_46;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_362);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_363);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_364);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_365);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_366);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_367);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_368);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_369);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_370);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_371);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_372);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_373);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_374);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_375);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_376);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_377);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_378);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_379);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_391);
						}
					}
				}
			}
		}
	}


}