#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (2, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, f);
  T (8, c); T (1, y)]
*/
IND_TYPE c, cp_0, c544_p_0, c545_p_0, cp_1, c544_p_1, cp_2, c544, c545, f, fp_0, x, xp_0, y, yp_0, y408_p_0, yp_1, y408;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y409 = 0;
IND_TYPE x272 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c546 = 0;
IND_TYPE f272 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_5472 ,mem_vec_5473 ,mem_vec_5474 ,mem_vec_5475 ,mem_vec_5476 ,mem_vec_5477 ,mem_vec_5478 ,mem_vec_5479 ,mem_vec_5480 ,mem_vec_5481 ,mem_vec_5482 ,mem_vec_5483 ,mem_vec_5484 ,mem_vec_5485 ,mem_vec_5486 ,mem_vec_5487 ,mem_vec_5488 ,mem_vec_5489 ,mem_vec_5490 ,mem_vec_5491 ,mem_vec_5492 ,mem_vec_5493 ,mem_vec_5494 ,mem_vec_5495 ,mem_vec_5496 ,mem_vec_5497 ,mem_vec_5498 ,mem_vec_5499 ,mem_vec_5500 ,mem_vec_5501 ,mem_vec_5502 ,mem_vec_5503 ,mem_vec_5504 ,mem_vec_5505 ,mem_vec_5506 ,mem_vec_5507 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y408 = y409, y408_p_0 = 0;
	y408 < y409 + 17;
	y408 += 17, y408_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 8) (1024 / 128)
	for (c545 = c546, c545_p_0 = 0;
		c545 < c546 + 1024;
		c545 += 128, c545_p_0 += 128){
		// y = 17, x = 17, h = 1, w = 1, c = 128, f = 512
		// T (f, 8) (512 / 64)
		for (f = f272, fp_0 = 0;
			f < f272 + 512;
			f += 64, fp_0 += 64){
				for (y = y408, yp_1 = y408_p_0, yp_0 = 0;
					y < y408 + 12;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 2) (128 / 64)
					for (c544 = c545, c544_p_1 = c545_p_0, c544_p_0 = 0;
						c544 < c545 + 128;
						c544 += 64, c544_p_1 += 64, c544_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x272, xp_0 = 0;
							x < x272 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5474 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5475 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c544, cp_2 = c544_p_1, cp_1 = c544_p_0, cp_0 = 0;
										c < c544 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5472);
										mem_vec_5472 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5473);
										mem_vec_5473 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5474);
										mem_vec_5474 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5475);
										mem_vec_5475 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5476);
										mem_vec_5476 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5477);
										mem_vec_5477 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5478);
										mem_vec_5478 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5479);
										mem_vec_5479 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5480);
										mem_vec_5480 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5481);
										mem_vec_5481 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5482);
										mem_vec_5482 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5483);
										mem_vec_5483 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5484);
										mem_vec_5484 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5485);
										mem_vec_5485 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5486);
										mem_vec_5486 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5487);
										mem_vec_5487 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5479);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5487);
						}
					}
				}
				for (y = y408 + 12, yp_1 = y408_p_0, yp_0 = 0;
					y < y408 + 12 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 2) (128 / 64)
					for (c544 = c545, c544_p_1 = c545_p_0, c544_p_0 = 0;
						c544 < c545 + 128;
						c544 += 64, c544_p_1 += 64, c544_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x272, xp_0 = 0;
							x < x272 + 17;
							x += 1, xp_0 += 1){
									mem_vec_5488 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5489 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_5491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_5492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_5495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_5496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_5499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_5500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_5503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_5504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_5505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_5506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_5507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c544, cp_2 = c544_p_1, cp_1 = c544_p_0, cp_0 = 0;
										c < c544 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5488);
										mem_vec_5488 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5489);
										mem_vec_5489 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5490);
										mem_vec_5490 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5491);
										mem_vec_5491 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5492);
										mem_vec_5492 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5493);
										mem_vec_5493 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5494);
										mem_vec_5494 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5495);
										mem_vec_5495 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5496);
										mem_vec_5496 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5497);
										mem_vec_5497 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5498);
										mem_vec_5498 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5499);
										mem_vec_5499 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5500);
										mem_vec_5500 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5501);
										mem_vec_5501 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5502);
										mem_vec_5502 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5503);
										mem_vec_5503 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5504);
										mem_vec_5504 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5505);
										mem_vec_5505 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5506);
										mem_vec_5506 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5507);
										mem_vec_5507 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5507);
						}
					}
				}
		}
	}
}


}