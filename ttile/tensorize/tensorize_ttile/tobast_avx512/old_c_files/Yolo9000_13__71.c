#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (2, x); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (1, c); T (1, x)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, x, xp_0, x48_p_0, x49_p_0, xp_1, x48_p_1, xp_2, x48, x49, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y24 = 0;
IND_TYPE x50 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c37 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x49 = x50, x49_p_0 = 0;
	x49 < x50 + 34;
	x49 += 34, x49_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 1) (512 / 512)
	for (c36 = c37, c36_p_0 = 0;
		c36 < c37 + 512;
		c36 += 512, c36_p_0 += 512){
		// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (f, 8) (256 / 32)
		for (f = f24, fp_0 = 0;
			f < f24 + 256;
			f += 32, fp_0 += 32){
				for (y = y24, yp_0 = 0;
					y < y24 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
						x48 < x49 + 34;
						x48 += 2, x48_p_1 += 2, x48_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (x, 2) (2 / 1)
						for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
							x < x48 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_384);
										mem_vec_384 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_385);
										mem_vec_385 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_386);
										mem_vec_386 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_387);
										mem_vec_387 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_388);
										mem_vec_388 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_389);
										mem_vec_389 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_390);
										mem_vec_390 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_391);
										mem_vec_391 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_392);
										mem_vec_392 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_393);
										mem_vec_393 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_394);
										mem_vec_394 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_395);
										mem_vec_395 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_396);
										mem_vec_396 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_397);
										mem_vec_397 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_397);
						}
					}
				}
				for (y = y24 + 7, yp_0 = 0;
					y < y24 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
						x48 < x49 + 34;
						x48 += 2, x48_p_1 += 2, x48_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (x, 2) (2 / 1)
						for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
							x < x48 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_398);
										mem_vec_398 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_399);
										mem_vec_399 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_400);
										mem_vec_400 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_401);
										mem_vec_401 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_402);
										mem_vec_402 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_403);
										mem_vec_403 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_404);
										mem_vec_404 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_405);
										mem_vec_405 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_406);
										mem_vec_406 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_407);
										mem_vec_407 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_408);
										mem_vec_408 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_409);
										mem_vec_409 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_410);
										mem_vec_410 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_411);
										mem_vec_411 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_412);
										mem_vec_412 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_413);
										mem_vec_413 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_414);
										mem_vec_414 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_415);
										mem_vec_415 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_403);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_404);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_405);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_406);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_407);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_413);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_414);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_415);
						}
					}
				}
		}
	}
}


}