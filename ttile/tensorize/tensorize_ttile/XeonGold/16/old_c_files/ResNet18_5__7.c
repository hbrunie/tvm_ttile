#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (14, x); T (2, c);
  T (2, x); T (4, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c31_p_0, cp_1, c31, f, fp_0, f31_p_0, fp_1, f31, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c32 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f31 = f32, f31_p_0 = 0;
	f31 < f32 + 128;
	f31 += 64, f31_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f31, fp_1 = f31_p_0, fp_0 = 0;
		f < f31 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y24, yp_0 = 0;
			y < y24 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x36 = x37, x36_p_0 = 0;
				x36 < x37 + 28;
				x36 += 14, x36_p_0 += 14){
				// y = 7, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c31 = c32, c31_p_0 = 0;
					c31 < c32 + 64;
					c31 += 32, c31_p_0 += 32){
					// y = 7, x = 14, h = 1, w = 1, c = 32, f = 64
					// T (x, 14) (14 / 1)
					for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
						x < x36 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c31, cp_1 = c31_p_0, cp_0 = 0;
									c < c31 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_336);
									mem_vec_336 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_337);
									mem_vec_337 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_338);
									mem_vec_338 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_339);
									mem_vec_339 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_340);
									mem_vec_340 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_341);
									mem_vec_341 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_342);
									mem_vec_342 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_343);
									mem_vec_343 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_344);
									mem_vec_344 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_345);
									mem_vec_345 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_346);
									mem_vec_346 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_347);
									mem_vec_347 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_348);
									mem_vec_348 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_349);
									mem_vec_349 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_350);
									mem_vec_350 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_351);
									mem_vec_351 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_352);
									mem_vec_352 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_353);
									mem_vec_353 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_354);
									mem_vec_354 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_355);
									mem_vec_355 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_356);
									mem_vec_356 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_357);
									mem_vec_357 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_358);
									mem_vec_358 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_359);
									mem_vec_359 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_360);
									mem_vec_360 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_361);
									mem_vec_361 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_362);
									mem_vec_362 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_363);
									mem_vec_363 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_337);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_338);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_339);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_340);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_341);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_342);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_343);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_344);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_345);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_346);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_347);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_348);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_349);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_350);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_351);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_352);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_353);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_354);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_355);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_356);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_357);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_358);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_359);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_360);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_361);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_362);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_363);
					}
				}
			}
		}
	}
}


}