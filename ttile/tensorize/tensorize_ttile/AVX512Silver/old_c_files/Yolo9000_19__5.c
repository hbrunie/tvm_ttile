#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (1, y); T (8, f); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c40_p_0, c41_p_0, cp_1, c40_p_1, cp_2, c40, c41, f, fp_0, x, xp_0, y, yp_0, y30_p_0, yp_1, y30;

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
IND_TYPE c42 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y30 = y31, y30_p_0 = 0;
		y30 < y31 + 3;
		y30 += 3, y30_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 8) (1024 / 128)
		for (c41 = c42, c41_p_0 = 0;
			c41 < c42 + 1024;
			c41 += 128, c41_p_0 += 128){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (f, 8) (512 / 64)
			for (f = f20, fp_0 = 0;
				f < f20 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
					y < y30 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c40 = c41, c40_p_1 = c41_p_0, c40_p_0 = 0;
						c40 < c41 + 128;
						c40 += 32, c40_p_1 += 32, c40_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x20, xp_0 = 0;
							x < x20 + 17;
							x += 1, xp_0 += 1){
									mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c40, cp_2 = c40_p_1, cp_1 = c40_p_0, cp_0 = 0;
										c < c40 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_400);
										mem_vec_400 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_401);
										mem_vec_401 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_402);
										mem_vec_402 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_403);
										mem_vec_403 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_404);
										mem_vec_404 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_405);
										mem_vec_405 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_406);
										mem_vec_406 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_407);
										mem_vec_407 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_408);
										mem_vec_408 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_409);
										mem_vec_409 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_410);
										mem_vec_410 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_411);
										mem_vec_411 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_403);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_404);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_405);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_406);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_407);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_411);
						}
					}
				}
			}
		}
	}
	for (y30 = y31 + 3, y30_p_0 = 0;
		y30 < y31 + 3 + 14;
		y30 += 7, y30_p_0 += 7){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 8) (1024 / 128)
		for (c41 = c42, c41_p_0 = 0;
			c41 < c42 + 1024;
			c41 += 128, c41_p_0 += 128){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (f, 8) (512 / 64)
			for (f = f20, fp_0 = 0;
				f < f20 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
					y < y30 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c40 = c41, c40_p_1 = c41_p_0, c40_p_0 = 0;
						c40 < c41 + 128;
						c40 += 32, c40_p_1 += 32, c40_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x20, xp_0 = 0;
							x < x20 + 17;
							x += 1, xp_0 += 1){
									mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c40, cp_2 = c40_p_1, cp_1 = c40_p_0, cp_0 = 0;
										c < c40 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_412);
										mem_vec_412 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_413);
										mem_vec_413 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_414);
										mem_vec_414 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_415);
										mem_vec_415 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_416);
										mem_vec_416 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_417);
										mem_vec_417 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_418);
										mem_vec_418 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_419);
										mem_vec_419 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_420);
										mem_vec_420 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_421);
										mem_vec_421 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_422);
										mem_vec_422 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_423);
										mem_vec_423 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_424);
										mem_vec_424 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_425);
										mem_vec_425 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_426);
										mem_vec_426 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_427);
										mem_vec_427 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_428);
										mem_vec_428 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_429);
										mem_vec_429 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_430);
										mem_vec_430 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_431);
										mem_vec_431 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_432);
										mem_vec_432 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_433);
										mem_vec_433 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_434);
										mem_vec_434 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_435);
										mem_vec_435 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_436);
										mem_vec_436 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_437);
										mem_vec_437 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_438);
										mem_vec_438 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_439);
										mem_vec_439 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_415);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_416);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_417);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_421);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_428);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_437);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_438);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_439);
						}
					}
				}
			}
		}
	}


}