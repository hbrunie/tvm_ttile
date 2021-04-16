#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (4, c);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]; T (8, f);
  T (8, c); T (1, y)]
*/
IND_TYPE c, cp_0, c532_p_0, c533_p_0, cp_1, c532_p_1, cp_2, c532, c533, f, fp_0, x, xp_0, y, yp_0, y399_p_0, yp_1, y399;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y400 = 0;
IND_TYPE x266 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c534 = 0;
IND_TYPE f266 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,mem_vec_5401 ,mem_vec_5402 ,mem_vec_5403 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y399 = y400, y399_p_0 = 0;
	y399 < y400 + 17;
	y399 += 17, y399_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 8) (1024 / 128)
	for (c533 = c534, c533_p_0 = 0;
		c533 < c534 + 1024;
		c533 += 128, c533_p_0 += 128){
		// y = 17, x = 17, h = 1, w = 1, c = 128, f = 512
		// T (f, 8) (512 / 64)
		for (f = f266, fp_0 = 0;
			f < f266 + 512;
			f += 64, fp_0 += 64){
				for (y = y399, yp_1 = y399_p_0, yp_0 = 0;
					y < y399 + 12;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c532 = c533, c532_p_1 = c533_p_0, c532_p_0 = 0;
						c532 < c533 + 128;
						c532 += 32, c532_p_1 += 32, c532_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x266, xp_0 = 0;
							x < x266 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5372 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5373 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5374 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5375 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c532, cp_2 = c532_p_1, cp_1 = c532_p_0, cp_0 = 0;
										c < c532 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5372);
										mem_vec_5372 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5373);
										mem_vec_5373 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5374);
										mem_vec_5374 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5375);
										mem_vec_5375 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5376);
										mem_vec_5376 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5377);
										mem_vec_5377 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5378);
										mem_vec_5378 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5379);
										mem_vec_5379 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5380);
										mem_vec_5380 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5381);
										mem_vec_5381 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5382);
										mem_vec_5382 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5383);
										mem_vec_5383 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5372);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5373);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5374);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5375);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5376);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5377);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5378);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5379);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5380);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5381);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5382);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5383);
						}
					}
				}
				for (y = y399 + 12, yp_1 = y399_p_0, yp_0 = 0;
					y < y399 + 12 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c532 = c533, c532_p_1 = c533_p_0, c532_p_0 = 0;
						c532 < c533 + 128;
						c532 += 32, c532_p_1 += 32, c532_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x266, xp_0 = 0;
							x < x266 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_5400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_5402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_5403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c532, cp_2 = c532_p_1, cp_1 = c532_p_0, cp_0 = 0;
										c < c532 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5384);
										mem_vec_5384 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5385);
										mem_vec_5385 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5386);
										mem_vec_5386 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5387);
										mem_vec_5387 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5388);
										mem_vec_5388 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5389);
										mem_vec_5389 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5390);
										mem_vec_5390 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5391);
										mem_vec_5391 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5392);
										mem_vec_5392 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5393);
										mem_vec_5393 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5394);
										mem_vec_5394 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5395);
										mem_vec_5395 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5396);
										mem_vec_5396 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5397);
										mem_vec_5397 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5398);
										mem_vec_5398 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5399);
										mem_vec_5399 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5400);
										mem_vec_5400 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5401);
										mem_vec_5401 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5402);
										mem_vec_5402 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5403);
										mem_vec_5403 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5403);
						}
					}
				}
		}
	}
}


}