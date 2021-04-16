#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (16, c);
  T (1, y); T (8, f); T (4, c);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c236_p_0, c237_p_0, cp_1, c236_p_1, cp_2, c236, c237, f, fp_0, x, xp_0, y, yp_0, y177_p_0, yp_1, y177;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y178 = 0;
IND_TYPE x118 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c238 = 0;
IND_TYPE f118 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_2468 ,mem_vec_2469 ,mem_vec_2470 ,mem_vec_2471 ,mem_vec_2472 ,mem_vec_2473 ,mem_vec_2474 ,mem_vec_2475 ,mem_vec_2476 ,mem_vec_2477 ,mem_vec_2478 ,mem_vec_2479 ,mem_vec_2480 ,mem_vec_2481 ,mem_vec_2482 ,mem_vec_2483 ,mem_vec_2484 ,mem_vec_2485 ,mem_vec_2486 ,mem_vec_2487 ,mem_vec_2488 ,mem_vec_2489 ,mem_vec_2490 ,mem_vec_2491 ,mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y177 = y178, y177_p_0 = 0;
		y177 < y178 + 12;
		y177 += 3, y177_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 4) (1024 / 256)
		for (c237 = c238, c237_p_0 = 0;
			c237 < c238 + 1024;
			c237 += 256, c237_p_0 += 256){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (f, 8) (512 / 64)
			for (f = f118, fp_0 = 0;
				f < f118 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y177, yp_1 = y177_p_0, yp_0 = 0;
					y < y177 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c236 = c237, c236_p_1 = c237_p_0, c236_p_0 = 0;
						c236 < c237 + 256;
						c236 += 16, c236_p_1 += 16, c236_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x118, xp_0 = 0;
							x < x118 + 17;
							x += 1, xp_0 += 1){
									mem_vec_2468 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2469 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2470 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2471 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c236, cp_2 = c236_p_1, cp_1 = c236_p_0, cp_0 = 0;
										c < c236 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2468);
										mem_vec_2468 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2469);
										mem_vec_2469 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2470);
										mem_vec_2470 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2471);
										mem_vec_2471 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2472);
										mem_vec_2472 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2473);
										mem_vec_2473 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2474);
										mem_vec_2474 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2475);
										mem_vec_2475 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2476);
										mem_vec_2476 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2477);
										mem_vec_2477 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2478);
										mem_vec_2478 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2479);
										mem_vec_2479 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2468);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2469);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2470);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2471);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2479);
						}
					}
				}
			}
		}
	}
	for (y177 = y178 + 12, y177_p_0 = 0;
		y177 < y178 + 12 + 5;
		y177 += 5, y177_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 4) (1024 / 256)
		for (c237 = c238, c237_p_0 = 0;
			c237 < c238 + 1024;
			c237 += 256, c237_p_0 += 256){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (f, 8) (512 / 64)
			for (f = f118, fp_0 = 0;
				f < f118 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y177, yp_1 = y177_p_0, yp_0 = 0;
					y < y177 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c236 = c237, c236_p_1 = c237_p_0, c236_p_0 = 0;
						c236 < c237 + 256;
						c236 += 16, c236_p_1 += 16, c236_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x118, xp_0 = 0;
							x < x118 + 17;
							x += 1, xp_0 += 1){
									mem_vec_2480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_2488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_2491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_2492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_2494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_2495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_2496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_2497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_2498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_2499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c236, cp_2 = c236_p_1, cp_1 = c236_p_0, cp_0 = 0;
										c < c236 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2480);
										mem_vec_2480 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2481);
										mem_vec_2481 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2482);
										mem_vec_2482 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2483);
										mem_vec_2483 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2484);
										mem_vec_2484 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2485);
										mem_vec_2485 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2486);
										mem_vec_2486 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2487);
										mem_vec_2487 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2488);
										mem_vec_2488 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2489);
										mem_vec_2489 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2490);
										mem_vec_2490 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2491);
										mem_vec_2491 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2492);
										mem_vec_2492 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2493);
										mem_vec_2493 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2494);
										mem_vec_2494 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2495);
										mem_vec_2495 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2496);
										mem_vec_2496 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2497);
										mem_vec_2497 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2498);
										mem_vec_2498 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2499);
										mem_vec_2499 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2499);
						}
					}
				}
			}
		}
	}


}