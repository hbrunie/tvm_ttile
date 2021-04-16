#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (16, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, x, xp_0, x45_p_0, xp_1, x45, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y45 = y46, y45_p_0 = 0;
		y45 < y46 + 12;
		y45 += 4, y45_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x45 = x46, x45_p_0 = 0;
			x45 < x46 + 17;
			x45 += 17, x45_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 1) (1024 / 1024)
			for (c45 = c46, c45_p_0 = 0;
				c45 < c46 + 1024;
				c45 += 1024, c45_p_0 += 1024){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
				// T (f, 16) (512 / 32)
				for (f = f30, fp_0 = 0;
					f < f30 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
						y < y45 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
						// T (x, 17) (17 / 1)
						for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
							x < x45 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_540 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_541 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_542 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_543 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 1024;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_540);
										mem_vec_540 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_541);
										mem_vec_541 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_542);
										mem_vec_542 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_543);
										mem_vec_543 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_544);
										mem_vec_544 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_545);
										mem_vec_545 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_546);
										mem_vec_546 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_547);
										mem_vec_547 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_548);
										mem_vec_548 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_549);
										mem_vec_549 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_550);
										mem_vec_550 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_551);
										mem_vec_551 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_552);
										mem_vec_552 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_553);
										mem_vec_553 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_554);
										mem_vec_554 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_555);
										mem_vec_555 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_540);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_541);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_542);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_543);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_544);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_545);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_546);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_547);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_548);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_549);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_550);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_551);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_552);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_553);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_554);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_555);
						}
					}
				}
			}
		}
	}
	for (y45 = y46 + 12, y45_p_0 = 0;
		y45 < y46 + 12 + 5;
		y45 += 5, y45_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x45 = x46, x45_p_0 = 0;
			x45 < x46 + 17;
			x45 += 17, x45_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 1) (1024 / 1024)
			for (c45 = c46, c45_p_0 = 0;
				c45 < c46 + 1024;
				c45 += 1024, c45_p_0 += 1024){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
				// T (f, 16) (512 / 32)
				for (f = f30, fp_0 = 0;
					f < f30 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
						y < y45 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
						// T (x, 17) (17 / 1)
						for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
							x < x45 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_556 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_557 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_558 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_559 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 1024;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_556);
										mem_vec_556 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_557);
										mem_vec_557 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_558);
										mem_vec_558 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_559);
										mem_vec_559 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_560);
										mem_vec_560 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_561);
										mem_vec_561 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_562);
										mem_vec_562 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_563);
										mem_vec_563 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_564);
										mem_vec_564 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_565);
										mem_vec_565 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_566);
										mem_vec_566 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_567);
										mem_vec_567 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_568);
										mem_vec_568 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_569);
										mem_vec_569 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_570);
										mem_vec_570 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_571);
										mem_vec_571 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_572);
										mem_vec_572 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_573);
										mem_vec_573 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_574);
										mem_vec_574 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_575);
										mem_vec_575 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_556);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_557);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_558);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_559);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_560);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_561);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_562);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_563);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_564);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_565);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_566);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_567);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_568);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_569);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_570);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_571);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_572);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_573);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_574);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_575);
						}
					}
				}
			}
		}
	}


}