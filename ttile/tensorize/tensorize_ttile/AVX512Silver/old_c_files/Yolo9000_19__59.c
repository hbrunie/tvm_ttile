#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (1, y); T (8, f); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c44_p_0, c45_p_0, cp_1, c44_p_1, cp_2, c44, c45, f, fp_0, x, xp_0, y, yp_0, y33_p_0, yp_1, y33;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y34 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y33 = y34, y33_p_0 = 0;
		y33 < y34 + 3;
		y33 += 3, y33_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 8) (1024 / 128)
		for (c45 = c46, c45_p_0 = 0;
			c45 < c46 + 1024;
			c45 += 128, c45_p_0 += 128){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (f, 8) (512 / 64)
			for (f = f22, fp_0 = 0;
				f < f22 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
					y < y33 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c44 = c45, c44_p_1 = c45_p_0, c44_p_0 = 0;
						c44 < c45 + 128;
						c44 += 16, c44_p_1 += 16, c44_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x22, xp_0 = 0;
							x < x22 + 17;
							x += 1, xp_0 += 1){
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
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c44, cp_2 = c44_p_1, cp_1 = c44_p_0, cp_0 = 0;
										c < c44 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
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
						}
					}
				}
			}
		}
	}
	for (y33 = y34 + 3, y33_p_0 = 0;
		y33 < y34 + 3 + 14;
		y33 += 7, y33_p_0 += 7){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 8) (1024 / 128)
		for (c45 = c46, c45_p_0 = 0;
			c45 < c46 + 1024;
			c45 += 128, c45_p_0 += 128){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (f, 8) (512 / 64)
			for (f = f22, fp_0 = 0;
				f < f22 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y33, yp_1 = y33_p_0, yp_0 = 0;
					y < y33 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c44 = c45, c44_p_1 = c45_p_0, c44_p_0 = 0;
						c44 < c45 + 128;
						c44 += 16, c44_p_1 += 16, c44_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x22, xp_0 = 0;
							x < x22 + 17;
							x += 1, xp_0 += 1){
									mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c44, cp_2 = c44_p_1, cp_1 = c44_p_0, cp_0 = 0;
										c < c44 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_452);
										mem_vec_452 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_453);
										mem_vec_453 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_454);
										mem_vec_454 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_455);
										mem_vec_455 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_456);
										mem_vec_456 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_457);
										mem_vec_457 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_458);
										mem_vec_458 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_459);
										mem_vec_459 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_460);
										mem_vec_460 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_461);
										mem_vec_461 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_462);
										mem_vec_462 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_463);
										mem_vec_463 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_464);
										mem_vec_464 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_465);
										mem_vec_465 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_466);
										mem_vec_466 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_467);
										mem_vec_467 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_468);
										mem_vec_468 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_469);
										mem_vec_469 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_470);
										mem_vec_470 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_471);
										mem_vec_471 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_472);
										mem_vec_472 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_473);
										mem_vec_473 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_474);
										mem_vec_474 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_475);
										mem_vec_475 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_476);
										mem_vec_476 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_477);
										mem_vec_477 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_478);
										mem_vec_478 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_479);
										mem_vec_479 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_452);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_453);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_454);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_455);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_463);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_464);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_465);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_466);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_467);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_468);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_469);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_470);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_471);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_479);
						}
					}
				}
			}
		}
	}


}