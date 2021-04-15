#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (4, x); T (7, w);
  T (7, h); T (7, x); T (14, y); T (2, f); T (4, x)]
*/
IND_TYPE c, cp_0, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x120_p_0, x121_p_0, xp_1, x120_p_1, xp_2, x120, x121, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y60 = 0;
IND_TYPE x122 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c60 = 0;
IND_TYPE f60 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (x, 4) (112 / 28)
for (x121 = x122, x121_p_0 = 0;
	x121 < x122 + 112;
	x121 += 28, x121_p_0 += 28){
	// y = 112, x = 28, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f60, fp_0 = 0;
		f < f60 + 64;
		f += 32, fp_0 += 32){
		// y = 112, x = 28, h = 7, w = 7, c = 3, f = 32
		// T (y, 14) (112 / 8)
		for (y = y60, yp_0 = 0;
			y < y60 + 112;
			y += 8, yp_0 += 8){
			// y = 8, x = 28, h = 7, w = 7, c = 3, f = 32
			// T (x, 7) (28 / 4)
			for (x120 = x121, x120_p_1 = x121_p_0, x120_p_0 = 0;
				x120 < x121 + 28;
				x120 += 4, x120_p_1 += 4, x120_p_0 += 4){
				// y = 8, x = 4, h = 7, w = 7, c = 3, f = 32
				// T (h, 7) (7 / 1)
				for (h = h60, hp_0 = 0;
					h < h60 + 7;
					h += 1, hp_0 += 1){
					// y = 8, x = 4, h = 1, w = 7, c = 3, f = 32
					// T (w, 7) (7 / 1)
					for (w = w60, wp_0 = 0;
						w < w60 + 7;
						w += 1, wp_0 += 1){
						// y = 8, x = 4, h = 1, w = 1, c = 3, f = 32
						// T (x, 4) (4 / 1)
						for (x = x120, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
							x < x120 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c60, cp_0 = 0;
										c < c60 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_448);
										mem_vec_448 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_449);
										mem_vec_449 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_450);
										mem_vec_450 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_451);
										mem_vec_451 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_452);
										mem_vec_452 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_453);
										mem_vec_453 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_454);
										mem_vec_454 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_455);
										mem_vec_455 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_456);
										mem_vec_456 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_457);
										mem_vec_457 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_458);
										mem_vec_458 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_459);
										mem_vec_459 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_460);
										mem_vec_460 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_461);
										mem_vec_461 = vec_22;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_462);
										mem_vec_462 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_463);
										mem_vec_463 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_449);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_450);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_451);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_452);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_453);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_454);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_455);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_463);
						}
					}
				}
			}
		}
	}
}


}