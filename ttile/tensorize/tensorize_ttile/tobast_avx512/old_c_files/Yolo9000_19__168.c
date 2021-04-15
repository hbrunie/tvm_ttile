#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (128, c);
  T (16, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (4, c)]
*/
IND_TYPE c, cp_0, c48_p_0, c49_p_0, cp_1, c48_p_1, cp_2, c48, c49, f, fp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c50 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 4) (1024 / 256)
for (c49 = c50, c49_p_0 = 0;
	c49 < c50 + 1024;
	c49 += 256, c49_p_0 += 256){
		for (y = y24, yp_0 = 0;
			y < y24 + 7;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 1) (17 / 17)
			for (x36 = x37, x36_p_0 = 0;
				x36 < x37 + 17;
				x36 += 17, x36_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
				// T (f, 16) (512 / 32)
				for (f = f24, fp_0 = 0;
					f < f24 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (c, 128) (256 / 2)
					for (c48 = c49, c48_p_1 = c49_p_0, c48_p_0 = 0;
						c48 < c49 + 256;
						c48 += 2, c48_p_1 += 2, c48_p_0 += 2){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c48, cp_2 = c48_p_1, cp_1 = c48_p_0, cp_0 = 0;
										c < c48 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_408);
										mem_vec_408 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_409);
										mem_vec_409 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_410);
										mem_vec_410 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_411);
										mem_vec_411 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_412);
										mem_vec_412 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_413);
										mem_vec_413 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_414);
										mem_vec_414 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_415);
										mem_vec_415 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_416);
										mem_vec_416 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_417);
										mem_vec_417 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_418);
										mem_vec_418 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_419);
										mem_vec_419 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_420);
										mem_vec_420 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_421);
										mem_vec_421 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_415);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_416);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_417);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_421);
						}
					}
				}
			}
		}
		for (y = y24 + 7, yp_0 = 0;
			y < y24 + 7 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 1) (17 / 17)
			for (x36 = x37, x36_p_0 = 0;
				x36 < x37 + 17;
				x36 += 17, x36_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
				// T (f, 16) (512 / 32)
				for (f = f24, fp_0 = 0;
					f < f24 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (c, 128) (256 / 2)
					for (c48 = c49, c48_p_1 = c49_p_0, c48_p_0 = 0;
						c48 < c49 + 256;
						c48 += 2, c48_p_1 += 2, c48_p_0 += 2){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c48, cp_2 = c48_p_1, cp_1 = c48_p_0, cp_0 = 0;
										c < c48 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_422);
										mem_vec_422 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_423);
										mem_vec_423 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_424);
										mem_vec_424 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_425);
										mem_vec_425 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_426);
										mem_vec_426 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_427);
										mem_vec_427 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_428);
										mem_vec_428 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_429);
										mem_vec_429 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_430);
										mem_vec_430 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_431);
										mem_vec_431 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_432);
										mem_vec_432 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_433);
										mem_vec_433 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_434);
										mem_vec_434 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_435);
										mem_vec_435 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_436);
										mem_vec_436 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_437);
										mem_vec_437 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_438);
										mem_vec_438 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_439);
										mem_vec_439 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_440);
										mem_vec_440 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_441);
										mem_vec_441 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_428);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_437);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_438);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_439);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_440);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_441);
						}
					}
				}
			}
		}
}


}