#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, h); T (56, x);
  T (3, w); T (4, c); T (1, x); T (14, y); T (1, x)]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, h, hp_0, w, wp_0, x, xp_0, x58_p_0, x59_p_0, xp_1, x58_p_1, xp_2, x58, x59, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y32 = 0;
IND_TYPE x60 = 0;
IND_TYPE h20 = 0;
IND_TYPE w21 = 0;
IND_TYPE c46 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x59 = x60, x59_p_0 = 0;
	x59 < x60 + 56;
	x59 += 56, x59_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 14) (56 / 4)
	for (y = y32, yp_0 = 0;
		y < y32 + 56;
		y += 4, yp_0 += 4){
		// y = 4, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (56 / 56)
		for (x58 = x59, x58_p_1 = x59_p_0, x58_p_0 = 0;
			x58 < x59 + 56;
			x58 += 56, x58_p_1 += 56, x58_p_0 += 56){
			// y = 4, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (c, 4) (64 / 16)
			for (c45 = c46, c45_p_0 = 0;
				c45 < c46 + 64;
				c45 += 16, c45_p_0 += 16){
				// y = 4, x = 56, h = 3, w = 3, c = 16, f = 64
				// T (w, 3) (3 / 1)
				for (w = w21, wp_0 = 0;
					w < w21 + 3;
					w += 1, wp_0 += 1){
					// y = 4, x = 56, h = 3, w = 1, c = 16, f = 64
					// T (x, 56) (56 / 1)
					for (x = x58, xp_2 = x58_p_1, xp_1 = x58_p_0, xp_0 = 0;
						x < x58 + 56;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
						// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h20, hp_0 = 0;
							h < h20 + 3;
							h += 1, hp_0 += 1){
									mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_348);
										mem_vec_348 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_349);
										mem_vec_349 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_350);
										mem_vec_350 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_351);
										mem_vec_351 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_352);
										mem_vec_352 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_353);
										mem_vec_353 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_354);
										mem_vec_354 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_355);
										mem_vec_355 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_356);
										mem_vec_356 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_357);
										mem_vec_357 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_358);
										mem_vec_358 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_359);
										mem_vec_359 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_360);
										mem_vec_360 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_361);
										mem_vec_361 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_362);
										mem_vec_362 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_363);
										mem_vec_363 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_348);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_349);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_350);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_351);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_352);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_353);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_354);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_355);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_356);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_357);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_358);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_359);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_360);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_361);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_362);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_363);
						}
					}
				}
			}
		}
	}
}


}