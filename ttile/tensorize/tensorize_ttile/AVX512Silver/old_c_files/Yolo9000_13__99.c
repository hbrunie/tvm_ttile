#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (4, f); T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, x, xp_0, x36_p_0, x37_p_0, xp_1, x36_p_1, xp_2, x36, x37, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y18 = 0;
IND_TYPE x38 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y18, yp_0 = 0;
		y < y18 + 4;
		y += 4, yp_0 += 4){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x37 = x38, x37_p_0 = 0;
			x37 < x38 + 34;
			x37 += 34, x37_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
				x36 < x37 + 34;
				x36 += 17, x36_p_1 += 17, x36_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f18, fp_0 = 0;
					f < f18 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 8) (512 / 64)
					for (c27 = c28, c27_p_0 = 0;
						c27 < c28 + 512;
						c27 += 64, c27_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
										c < c27 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_424);
										mem_vec_424 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_425);
										mem_vec_425 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_426);
										mem_vec_426 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_427);
										mem_vec_427 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_428);
										mem_vec_428 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_429);
										mem_vec_429 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_430);
										mem_vec_430 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_431);
										mem_vec_431 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_432);
										mem_vec_432 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_433);
										mem_vec_433 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_434);
										mem_vec_434 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_435);
										mem_vec_435 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_436);
										mem_vec_436 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_437);
										mem_vec_437 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_438);
										mem_vec_438 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_439);
										mem_vec_439 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_428);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_435);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_436);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_437);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_438);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_439);
						}
					}
				}
			}
		}
	}
	for (y = y18 + 4, yp_0 = 0;
		y < y18 + 4 + 30;
		y += 6, yp_0 += 6){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x37 = x38, x37_p_0 = 0;
			x37 < x38 + 34;
			x37 += 34, x37_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
				x36 < x37 + 34;
				x36 += 17, x36_p_1 += 17, x36_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f18, fp_0 = 0;
					f < f18 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 8) (512 / 64)
					for (c27 = c28, c27_p_0 = 0;
						c27 < c28 + 512;
						c27 += 64, c27_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
										c < c27 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_440);
										mem_vec_440 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_441);
										mem_vec_441 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_442);
										mem_vec_442 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_443);
										mem_vec_443 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_444);
										mem_vec_444 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_445);
										mem_vec_445 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_446);
										mem_vec_446 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_447);
										mem_vec_447 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_448);
										mem_vec_448 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_449);
										mem_vec_449 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_450);
										mem_vec_450 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_451);
										mem_vec_451 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_452);
										mem_vec_452 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_453);
										mem_vec_453 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_454);
										mem_vec_454 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_455);
										mem_vec_455 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_456);
										mem_vec_456 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_457);
										mem_vec_457 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_458);
										mem_vec_458 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_459);
										mem_vec_459 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_460);
										mem_vec_460 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_461);
										mem_vec_461 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_462);
										mem_vec_462 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_463);
										mem_vec_463 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_440);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_441);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_442);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_443);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_444);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_445);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_446);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_447);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_448);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_449);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_450);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_451);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_452);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_453);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_454);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_455);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_463);
						}
					}
				}
			}
		}
	}


}