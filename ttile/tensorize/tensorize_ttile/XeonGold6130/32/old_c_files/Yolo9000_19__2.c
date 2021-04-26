#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y31 = 0;
IND_TYPE x20 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y30 = y31, y30_p_0 = 0;
		y30 < y31 + 8;
		y30 += 8, y30_p_0 += 8){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 32) (1024 / 32)
				for (c30 = c31, c30_p_0 = 0;
					c30 < c31 + 1024;
					c30 += 32, c30_p_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 32
					// T (x, 17) (17 / 1)
					for (x = x20, xp_0 = 0;
						x < x20 + 17;
						x += 1, xp_0 += 1){
								mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
									c < c30 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_340);
									mem_vec_340 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_341);
									mem_vec_341 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_342);
									mem_vec_342 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_343);
									mem_vec_343 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_344);
									mem_vec_344 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_345);
									mem_vec_345 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_346);
									mem_vec_346 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_347);
									mem_vec_347 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_348);
									mem_vec_348 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_349);
									mem_vec_349 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_350);
									mem_vec_350 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_351);
									mem_vec_351 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_352);
									mem_vec_352 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_353);
									mem_vec_353 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_354);
									mem_vec_354 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_355);
									mem_vec_355 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_340);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_341);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_342);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_343);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_344);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_345);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_346);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_347);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_348);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_349);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_350);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_351);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_352);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_353);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_354);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_355);
					}
				}
			}
		}
	}
	for (y30 = y31 + 8, y30_p_0 = 0;
		y30 < y31 + 8 + 9;
		y30 += 9, y30_p_0 += 9){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 16) (512 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 512;
			f += 32, fp_0 += 32){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
			// T (y, 1) (ph_y / ph_y)
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 32) (1024 / 32)
				for (c30 = c31, c30_p_0 = 0;
					c30 < c31 + 1024;
					c30 += 32, c30_p_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 32
					// T (x, 17) (17 / 1)
					for (x = x20, xp_0 = 0;
						x < x20 + 17;
						x += 1, xp_0 += 1){
								mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
									c < c30 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_356);
									mem_vec_356 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_357);
									mem_vec_357 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_358);
									mem_vec_358 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_359);
									mem_vec_359 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_360);
									mem_vec_360 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_361);
									mem_vec_361 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_362);
									mem_vec_362 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_363);
									mem_vec_363 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_364);
									mem_vec_364 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_365);
									mem_vec_365 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_366);
									mem_vec_366 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_367);
									mem_vec_367 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_368);
									mem_vec_368 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_369);
									mem_vec_369 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_370);
									mem_vec_370 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_371);
									mem_vec_371 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_372);
									mem_vec_372 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_373);
									mem_vec_373 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_356);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_357);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_358);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_359);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_360);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_361);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_362);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_363);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_364);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_365);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_366);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_367);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_368);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_369);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_370);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_371);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_372);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_373);
					}
				}
			}
		}
	}


}