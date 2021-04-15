#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y20 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x41 = x42, x41_p_0 = 0;
	x41 < x42 + 34;
	x41 += 34, x41_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 256) (512 / 2)
	for (c30 = c31, c30_p_0 = 0;
		c30 < c31 + 512;
		c30 += 2, c30_p_0 += 2){
		// y = 34, x = 34, h = 1, w = 1, c = 2, f = 256
		// T (f, 8) (256 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 256;
			f += 32, fp_0 += 32){
				for (y = y20, yp_0 = 0;
					y < y20 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (34 / 17)
					for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
						x40 < x41 + 34;
						x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
							x < x40 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
										c < c30 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_320);
										mem_vec_320 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_321);
										mem_vec_321 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_322);
										mem_vec_322 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_323);
										mem_vec_323 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_324);
										mem_vec_324 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_325);
										mem_vec_325 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_326);
										mem_vec_326 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_327);
										mem_vec_327 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_328);
										mem_vec_328 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_329);
										mem_vec_329 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_330);
										mem_vec_330 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_331);
										mem_vec_331 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_332);
										mem_vec_332 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_333);
										mem_vec_333 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_320);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_321);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_322);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_323);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_333);
						}
					}
				}
				for (y = y20 + 7, yp_0 = 0;
					y < y20 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (34 / 17)
					for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
						x40 < x41 + 34;
						x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
							x < x40 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
										c < c30 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_334);
										mem_vec_334 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_335);
										mem_vec_335 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_336);
										mem_vec_336 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_337);
										mem_vec_337 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_338);
										mem_vec_338 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_339);
										mem_vec_339 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_340);
										mem_vec_340 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_341);
										mem_vec_341 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_342);
										mem_vec_342 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_343);
										mem_vec_343 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_344);
										mem_vec_344 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_345);
										mem_vec_345 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_346);
										mem_vec_346 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_347);
										mem_vec_347 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_348);
										mem_vec_348 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_349);
										mem_vec_349 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_350);
										mem_vec_350 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_351);
										mem_vec_351 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_334);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_335);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_336);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_337);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_345);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_346);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_347);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_351);
						}
					}
				}
		}
	}
}


}