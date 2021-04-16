#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (2, f); T (2, x); T (8, y)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x71_p_0, xp_1, x71, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y48 = 0;
IND_TYPE x72 = 0;
IND_TYPE h31 = 0;
IND_TYPE w33 = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 8) (56 / 7)
for (y = y48, yp_0 = 0;
	y < y48 + 56;
	y += 7, yp_0 += 7){
	// y = 7, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (x, 2) (56 / 28)
	for (x71 = x72, x71_p_0 = 0;
		x71 < x72 + 56;
		x71 += 28, x71_p_0 += 28){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (f, 2) (128 / 64)
		for (f = f40, fp_0 = 0;
			f < f40 + 128;
			f += 64, fp_0 += 64){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (c, 8) (128 / 16)
			for (c60 = c61, c60_p_0 = 0;
				c60 < c61 + 128;
				c60 += 16, c60_p_0 += 16){
				// y = 7, x = 28, h = 3, w = 3, c = 16, f = 64
				// T (w, 3) (3 / 1)
				for (w = w33, wp_0 = 0;
					w < w33 + 3;
					w += 1, wp_0 += 1){
					// y = 7, x = 28, h = 3, w = 1, c = 16, f = 64
					// T (x, 28) (28 / 1)
					for (x = x71, xp_1 = x71_p_0, xp_0 = 0;
						x < x71 + 28;
						x += 1, xp_1 += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h31, hp_0 = 0;
							h < h31 + 3;
							h += 1, hp_0 += 1){
									mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
										c < c60 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_374);
										mem_vec_374 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_375);
										mem_vec_375 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_376);
										mem_vec_376 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_377);
										mem_vec_377 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_378);
										mem_vec_378 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_379);
										mem_vec_379 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_380);
										mem_vec_380 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_381);
										mem_vec_381 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_382);
										mem_vec_382 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_383);
										mem_vec_383 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_384);
										mem_vec_384 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_385);
										mem_vec_385 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_386);
										mem_vec_386 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_387);
										mem_vec_387 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_388);
										mem_vec_388 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_389);
										mem_vec_389 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_390);
										mem_vec_390 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_391);
										mem_vec_391 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_392);
										mem_vec_392 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_393);
										mem_vec_393 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_394);
										mem_vec_394 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_395);
										mem_vec_395 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_396);
										mem_vec_396 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_397);
										mem_vec_397 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_398);
										mem_vec_398 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_399);
										mem_vec_399 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_400);
										mem_vec_400 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_401);
										mem_vec_401 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_374);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_375);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_376);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_377);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_378);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_379);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_383);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_401);
						}
					}
				}
			}
		}
	}
}


}