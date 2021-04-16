#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, f);
  T (4, c); T (1, y)]
*/
IND_TYPE c, cp_0, c240_p_0, c241_p_0, cp_1, c240_p_1, cp_2, c240, c241, f, fp_0, x, xp_0, y, yp_0, y180_p_0, yp_1, y180;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y181 = 0;
IND_TYPE x120 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c242 = 0;
IND_TYPE f120 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2500 ,mem_vec_2501 ,mem_vec_2502 ,mem_vec_2503 ,mem_vec_2504 ,mem_vec_2505 ,mem_vec_2506 ,mem_vec_2507 ,mem_vec_2508 ,mem_vec_2509 ,mem_vec_2510 ,mem_vec_2511 ,mem_vec_2512 ,mem_vec_2513 ,mem_vec_2514 ,mem_vec_2515 ,mem_vec_2516 ,mem_vec_2517 ,mem_vec_2518 ,mem_vec_2519 ,mem_vec_2520 ,mem_vec_2521 ,mem_vec_2522 ,mem_vec_2523 ,mem_vec_2524 ,mem_vec_2525 ,mem_vec_2526 ,mem_vec_2527 ,mem_vec_2528 ,mem_vec_2529 ,mem_vec_2530 ,mem_vec_2531 ,mem_vec_2532 ,mem_vec_2533 ,mem_vec_2534 ,mem_vec_2535 ,mem_vec_2536 ,mem_vec_2537 ,mem_vec_2538 ,mem_vec_2539 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y180 = y181, y180_p_0 = 0;
	y180 < y181 + 17;
	y180 += 17, y180_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 4) (1024 / 256)
	for (c241 = c242, c241_p_0 = 0;
		c241 < c242 + 1024;
		c241 += 256, c241_p_0 += 256){
		// y = 17, x = 17, h = 1, w = 1, c = 256, f = 512
		// T (f, 8) (512 / 64)
		for (f = f120, fp_0 = 0;
			f < f120 + 512;
			f += 64, fp_0 += 64){
				for (y = y180, yp_1 = y180_p_0, yp_0 = 0;
					y < y180 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c240 = c241, c240_p_1 = c241_p_0, c240_p_0 = 0;
						c240 < c241 + 256;
						c240 += 256, c240_p_1 += 256, c240_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x120, xp_0 = 0;
							x < x120 + 17;
							x += 1, xp_0 += 1){
									mem_vec_2500 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2501 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2502 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2503 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c240, cp_2 = c240_p_1, cp_1 = c240_p_0, cp_0 = 0;
										c < c240 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2500);
										mem_vec_2500 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2501);
										mem_vec_2501 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2502);
										mem_vec_2502 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2503);
										mem_vec_2503 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2504);
										mem_vec_2504 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2505);
										mem_vec_2505 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2506);
										mem_vec_2506 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2507);
										mem_vec_2507 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2508);
										mem_vec_2508 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2509);
										mem_vec_2509 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2510);
										mem_vec_2510 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2511);
										mem_vec_2511 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2507);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2508);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2509);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2510);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2511);
						}
					}
				}
				for (y = y180 + 3, yp_1 = y180_p_0, yp_0 = 0;
					y < y180 + 3 + 14;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c240 = c241, c240_p_1 = c241_p_0, c240_p_0 = 0;
						c240 < c241 + 256;
						c240 += 256, c240_p_1 += 256, c240_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x120, xp_0 = 0;
							x < x120 + 17;
							x += 1, xp_0 += 1){
									mem_vec_2512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2513 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2514 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2515 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_2524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_2527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_2528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_2531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_2532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_2533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_2534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_2535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_2536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_2537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_2538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_2539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c240, cp_2 = c240_p_1, cp_1 = c240_p_0, cp_0 = 0;
										c < c240 + 256;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2512);
										mem_vec_2512 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2513);
										mem_vec_2513 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2514);
										mem_vec_2514 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2515);
										mem_vec_2515 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2516);
										mem_vec_2516 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2517);
										mem_vec_2517 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2518);
										mem_vec_2518 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2519);
										mem_vec_2519 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2520);
										mem_vec_2520 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2521);
										mem_vec_2521 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2522);
										mem_vec_2522 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2523);
										mem_vec_2523 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2524);
										mem_vec_2524 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2525);
										mem_vec_2525 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2526);
										mem_vec_2526 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2527);
										mem_vec_2527 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2528);
										mem_vec_2528 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2529);
										mem_vec_2529 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2530);
										mem_vec_2530 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2531);
										mem_vec_2531 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2532);
										mem_vec_2532 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2533);
										mem_vec_2533 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2534);
										mem_vec_2534 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2535);
										mem_vec_2535 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2536);
										mem_vec_2536 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2537);
										mem_vec_2537 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2538);
										mem_vec_2538 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2539);
										mem_vec_2539 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2512);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2513);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2514);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2515);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2516);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2517);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2518);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2519);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2520);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2521);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2522);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2523);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2524);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2525);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2526);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2527);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2528);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2529);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2530);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2531);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2532);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2533);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2534);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2535);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2536);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2537);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2538);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2539);
						}
					}
				}
		}
	}
}


}