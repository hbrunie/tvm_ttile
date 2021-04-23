#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (2, c); T (1, x); T (8, y); T (4, x)]
*/
IND_TYPE c, cp_0, c333_p_0, cp_1, c333, h, hp_0, w, wp_0, x, xp_0, x418_p_0, x419_p_0, xp_1, x418_p_1, xp_2, x418, x419, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y235 = 0;
IND_TYPE x420 = 0;
IND_TYPE h197 = 0;
IND_TYPE w202 = 0;
IND_TYPE c334 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_3408 ,mem_vec_3409 ,mem_vec_3410 ,mem_vec_3411 ,mem_vec_3412 ,mem_vec_3413 ,mem_vec_3414 ,mem_vec_3415 ,mem_vec_3416 ,mem_vec_3417 ,mem_vec_3418 ,mem_vec_3419 ,mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x419 = x420, x419_p_0 = 0;
	x419 < x420 + 56;
	x419 += 14, x419_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
	// T (y, 8) (56 / 7)
	for (y = y235, yp_0 = 0;
		y < y235 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (14 / 14)
		for (x418 = x419, x418_p_1 = x419_p_0, x418_p_0 = 0;
			x418 < x419 + 14;
			x418 += 14, x418_p_1 += 14, x418_p_0 += 14){
			// y = 7, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (c, 2) (64 / 32)
			for (c333 = c334, c333_p_0 = 0;
				c333 < c334 + 64;
				c333 += 32, c333_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
				// T (w, 3) (3 / 1)
				for (w = w202, wp_0 = 0;
					w < w202 + 3;
					w += 1, wp_0 += 1){
					// y = 7, x = 14, h = 3, w = 1, c = 32, f = 64
					// T (x, 14) (14 / 1)
					for (x = x418, xp_2 = x418_p_1, xp_1 = x418_p_0, xp_0 = 0;
						x < x418 + 14;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 1, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h197, hp_0 = 0;
							h < h197 + 3;
							h += 1, hp_0 += 1){
									mem_vec_3408 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3409 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3410 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3411 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_3420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_3423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_3424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_3427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_3428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_3429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_3430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_3431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_3432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_3433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_3434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_3435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c333, cp_1 = c333_p_0, cp_0 = 0;
										c < c333 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3408);
										mem_vec_3408 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3409);
										mem_vec_3409 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3410);
										mem_vec_3410 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3411);
										mem_vec_3411 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3412);
										mem_vec_3412 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3413);
										mem_vec_3413 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3414);
										mem_vec_3414 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3415);
										mem_vec_3415 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3416);
										mem_vec_3416 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3417);
										mem_vec_3417 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3418);
										mem_vec_3418 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3419);
										mem_vec_3419 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3420);
										mem_vec_3420 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3421);
										mem_vec_3421 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3422);
										mem_vec_3422 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3423);
										mem_vec_3423 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3424);
										mem_vec_3424 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3425);
										mem_vec_3425 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3426);
										mem_vec_3426 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3427);
										mem_vec_3427 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3428);
										mem_vec_3428 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3429);
										mem_vec_3429 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3430);
										mem_vec_3430 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3431);
										mem_vec_3431 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3432);
										mem_vec_3432 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3433);
										mem_vec_3433 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3434);
										mem_vec_3434 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3435);
										mem_vec_3435 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3415);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3416);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3417);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3418);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3419);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3420);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3421);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3422);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3423);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3424);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3425);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3426);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3427);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3428);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3429);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3430);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3431);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3432);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3433);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3434);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_3435);
						}
					}
				}
			}
		}
	}
}


}