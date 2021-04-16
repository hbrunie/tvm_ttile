#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (1, x);
  T (4, y)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y31 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 4) (68 / 17)
for (y30 = y31, y30_p_0 = 0;
	y30 < y31 + 68;
	y30 += 17, y30_p_0 += 17){
	// y = 17, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 68;
		x41 += 68, x41_p_0 += 68){
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 5;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
					x40 < x41 + 68;
					x40 += 68, x40_p_1 += 68, x40_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f20, fp_0 = 0;
						f < f20 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 256;
							c30 += 256, c30_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_328);
											mem_vec_328 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_329);
											mem_vec_329 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_330);
											mem_vec_330 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_331);
											mem_vec_331 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_332);
											mem_vec_332 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_333);
											mem_vec_333 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_334);
											mem_vec_334 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_335);
											mem_vec_335 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_336);
											mem_vec_336 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_337);
											mem_vec_337 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_338);
											mem_vec_338 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_339);
											mem_vec_339 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_340);
											mem_vec_340 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_341);
											mem_vec_341 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_342);
											mem_vec_342 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_343);
											mem_vec_343 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_344);
											mem_vec_344 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_345);
											mem_vec_345 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_346);
											mem_vec_346 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_347);
											mem_vec_347 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_335);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_345);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_346);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_347);
							}
						}
					}
				}
			}
			for (y = y30 + 5, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 5 + 12;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
					x40 < x41 + 68;
					x40 += 68, x40_p_1 += 68, x40_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f20, fp_0 = 0;
						f < f20 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c30 = c31, c30_p_0 = 0;
							c30 < c31 + 256;
							c30 += 256, c30_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
								x < x40 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_348);
											mem_vec_348 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_349);
											mem_vec_349 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_350);
											mem_vec_350 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_351);
											mem_vec_351 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_352);
											mem_vec_352 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_353);
											mem_vec_353 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_354);
											mem_vec_354 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_355);
											mem_vec_355 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_356);
											mem_vec_356 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_357);
											mem_vec_357 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_358);
											mem_vec_358 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_359);
											mem_vec_359 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_360);
											mem_vec_360 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_361);
											mem_vec_361 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_362);
											mem_vec_362 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_363);
											mem_vec_363 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_364);
											mem_vec_364 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_365);
											mem_vec_365 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_366);
											mem_vec_366 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_367);
											mem_vec_367 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_368);
											mem_vec_368 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_369);
											mem_vec_369 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_370);
											mem_vec_370 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_371);
											mem_vec_371 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_348);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_349);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_350);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_351);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_371);
							}
						}
					}
				}
			}
	}
}


}