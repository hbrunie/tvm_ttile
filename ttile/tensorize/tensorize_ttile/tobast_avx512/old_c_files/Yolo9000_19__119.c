#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (16, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 1), (Arg 10))]; T (8, c)]
*/
IND_TYPE c, cp_0, c56_p_0, c57_p_0, cp_1, c56_p_1, cp_2, c56, c57, f, fp_0, x, xp_0, x42_p_0, xp_1, x42, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y28 = 0;
IND_TYPE x43 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c57 = c58, c57_p_0 = 0;
	c57 < c58 + 1024;
	c57 += 128, c57_p_0 += 128){
		for (y = y28, yp_0 = 0;
			y < y28 + 7;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x42 = x43, x42_p_0 = 0;
				x42 < x43 + 17;
				x42 += 17, x42_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 16) (512 / 32)
				for (f = f28, fp_0 = 0;
					f < f28 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c56 = c57, c56_p_1 = c57_p_0, c56_p_0 = 0;
						c56 < c57 + 128;
						c56 += 16, c56_p_1 += 16, c56_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
							x < x42 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c56, cp_2 = c56_p_1, cp_1 = c56_p_0, cp_0 = 0;
										c < c56 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_476);
										mem_vec_476 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_477);
										mem_vec_477 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_478);
										mem_vec_478 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_479);
										mem_vec_479 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_480);
										mem_vec_480 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_481);
										mem_vec_481 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_482);
										mem_vec_482 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_483);
										mem_vec_483 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_484);
										mem_vec_484 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_485);
										mem_vec_485 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_486);
										mem_vec_486 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_487);
										mem_vec_487 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_488);
										mem_vec_488 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_489);
										mem_vec_489 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_479);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_489);
						}
					}
				}
			}
		}
		for (y = y28 + 7, yp_0 = 0;
			y < y28 + 7 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x42 = x43, x42_p_0 = 0;
				x42 < x43 + 17;
				x42 += 17, x42_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 16) (512 / 32)
				for (f = f28, fp_0 = 0;
					f < f28 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c56 = c57, c56_p_1 = c57_p_0, c56_p_0 = 0;
						c56 < c57 + 128;
						c56 += 16, c56_p_1 += 16, c56_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
							x < x42 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c56, cp_2 = c56_p_1, cp_1 = c56_p_0, cp_0 = 0;
										c < c56 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_490);
										mem_vec_490 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_491);
										mem_vec_491 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_492);
										mem_vec_492 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_493);
										mem_vec_493 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_494);
										mem_vec_494 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_495);
										mem_vec_495 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_496);
										mem_vec_496 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_497);
										mem_vec_497 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_498);
										mem_vec_498 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_499);
										mem_vec_499 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_500);
										mem_vec_500 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_501);
										mem_vec_501 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_502);
										mem_vec_502 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_503);
										mem_vec_503 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_504);
										mem_vec_504 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_505);
										mem_vec_505 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_506);
										mem_vec_506 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_507);
										mem_vec_507 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_508);
										mem_vec_508 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_509);
										mem_vec_509 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_507);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_508);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_509);
						}
					}
				}
			}
		}
}


}