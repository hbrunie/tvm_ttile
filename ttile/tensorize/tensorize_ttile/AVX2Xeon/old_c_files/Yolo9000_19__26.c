#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (16, f); T (64, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c33_p_0, cp_1, c33, f, fp_0, x, xp_0, x33_p_0, xp_1, x33, y, yp_0, y33_p_0, yp_1, y33;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y34 = 0;
IND_TYPE x34 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c34 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y33 = y34, y33_p_0 = 0;
		y33 < y34 + 12;
		y33 += 4, y33_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x33 = x34, x33_p_0 = 0;
			x33 < x34 + 17;
			x33 += 17, x33_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 64) (1024 / 16)
			for (c33 = c34, c33_p_0 = 0;
				c33 < c34 + 1024;
				c33 += 16, c33_p_0 += 16){
				// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
				// T (f, 16) (512 / 32)
				for (f = f22, fp_0 = 0;
					f < f22 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
						y < y33 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
							x < x33 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_396 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_397 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_398 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_399 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
										c < c33 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_396);
										mem_vec_396 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_397);
										mem_vec_397 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_398);
										mem_vec_398 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_399);
										mem_vec_399 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_400);
										mem_vec_400 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_401);
										mem_vec_401 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_402);
										mem_vec_402 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_403);
										mem_vec_403 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_404);
										mem_vec_404 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_405);
										mem_vec_405 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_406);
										mem_vec_406 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_407);
										mem_vec_407 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_408);
										mem_vec_408 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_409);
										mem_vec_409 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_410);
										mem_vec_410 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_411);
										mem_vec_411 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_396);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_397);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_398);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_399);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_400);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_401);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_402);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_403);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_404);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_405);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_406);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_407);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_408);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_409);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_410);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_411);
						}
					}
				}
			}
		}
	}
	for (y33 = y34 + 12, y33_p_0 = 0;
		y33 < y34 + 12 + 5;
		y33 += 5, y33_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x33 = x34, x33_p_0 = 0;
			x33 < x34 + 17;
			x33 += 17, x33_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 64) (1024 / 16)
			for (c33 = c34, c33_p_0 = 0;
				c33 < c34 + 1024;
				c33 += 16, c33_p_0 += 16){
				// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
				// T (f, 16) (512 / 32)
				for (f = f22, fp_0 = 0;
					f < f22 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
						y < y33 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x33, xp_1 = x33_p_0, xp_0 = 0;
							x < x33 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_412 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_413 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_414 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_415 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c33, cp_1 = c33_p_0, cp_0 = 0;
										c < c33 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_412);
										mem_vec_412 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_413);
										mem_vec_413 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_414);
										mem_vec_414 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_415);
										mem_vec_415 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_416);
										mem_vec_416 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_417);
										mem_vec_417 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_418);
										mem_vec_418 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_419);
										mem_vec_419 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_420);
										mem_vec_420 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_421);
										mem_vec_421 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_422);
										mem_vec_422 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_423);
										mem_vec_423 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_424);
										mem_vec_424 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_425);
										mem_vec_425 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_426);
										mem_vec_426 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_427);
										mem_vec_427 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_428);
										mem_vec_428 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_429);
										mem_vec_429 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_430);
										mem_vec_430 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_431);
										mem_vec_431 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_412);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_413);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_414);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_415);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_416);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_417);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_418);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_419);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_420);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_421);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_422);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_423);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_424);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_425);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_426);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_427);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_428);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_429);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_430);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_431);
						}
					}
				}
			}
		}
	}


}