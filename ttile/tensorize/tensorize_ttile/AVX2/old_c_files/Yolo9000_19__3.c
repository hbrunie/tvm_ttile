#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (128, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0, y36_p_0, yp_1, y36;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y37 = 0;
IND_TYPE x37 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c37 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y36 = y37, y36_p_0 = 0;
	y36 < y37 + 17;
	y36 += 17, y36_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x36 = x37, x36_p_0 = 0;
		x36 < x37 + 17;
		x36 += 17, x36_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 128) (1024 / 8)
		for (c36 = c37, c36_p_0 = 0;
			c36 < c37 + 1024;
			c36 += 8, c36_p_0 += 8){
			// y = 17, x = 17, h = 1, w = 1, c = 8, f = 512
			// T (f, 16) (512 / 32)
			for (f = f24, fp_0 = 0;
				f < f24 + 512;
				f += 32, fp_0 += 32){
					for (y = y36, yp_1 = y36_p_0, yp_0 = 0;
						y < y36 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_432 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_433 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_434 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_435 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_432);
										mem_vec_432 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_433);
										mem_vec_433 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_434);
										mem_vec_434 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_435);
										mem_vec_435 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_436);
										mem_vec_436 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_437);
										mem_vec_437 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_438);
										mem_vec_438 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_439);
										mem_vec_439 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_440);
										mem_vec_440 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_441);
										mem_vec_441 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_442);
										mem_vec_442 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_443);
										mem_vec_443 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_444);
										mem_vec_444 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_445);
										mem_vec_445 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_446);
										mem_vec_446 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_447);
										mem_vec_447 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_432);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_433);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_434);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_435);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_436);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_437);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_438);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_439);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_440);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_441);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_442);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_443);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_444);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_445);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_446);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_447);
						}
					}
					for (y = y36 + 12, yp_1 = y36_p_0, yp_0 = 0;
						y < y36 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
							x < x36 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_448 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_449 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_450 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_451 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_448);
										mem_vec_448 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_449);
										mem_vec_449 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_450);
										mem_vec_450 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_451);
										mem_vec_451 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_452);
										mem_vec_452 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_453);
										mem_vec_453 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_454);
										mem_vec_454 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_455);
										mem_vec_455 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_456);
										mem_vec_456 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_457);
										mem_vec_457 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_458);
										mem_vec_458 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_459);
										mem_vec_459 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_460);
										mem_vec_460 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_461);
										mem_vec_461 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_462);
										mem_vec_462 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_463);
										mem_vec_463 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_464);
										mem_vec_464 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_465);
										mem_vec_465 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_466);
										mem_vec_466 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_467);
										mem_vec_467 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_449);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_450);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_451);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_452);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_453);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_454);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_455);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_456);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_457);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_458);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_459);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_460);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_461);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_462);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_463);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_464);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_465);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_466);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_467);
						}
					}
			}
		}
	}
}


}