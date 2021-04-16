#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (14, x); T (2, c);
  T (2, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c49_p_0, cp_1, c49, f, fp_0, f49_p_0, fp_1, f49, x, xp_0, x60_p_0, xp_1, x60, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y40 = 0;
IND_TYPE x61 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c50 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f49 = f50, f49_p_0 = 0;
	f49 < f50 + 128;
	f49 += 64, f49_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f49, fp_1 = f49_p_0, fp_0 = 0;
		f < f49 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y40, yp_0 = 0;
			y < y40 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x60 = x61, x60_p_0 = 0;
				x60 < x61 + 28;
				x60 += 14, x60_p_0 += 14){
				// y = 4, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c49 = c50, c49_p_0 = 0;
					c49 < c50 + 64;
					c49 += 32, c49_p_0 += 32){
					// y = 4, x = 14, h = 1, w = 1, c = 32, f = 64
					// T (x, 14) (14 / 1)
					for (x = x60, xp_1 = x60_p_0, xp_0 = 0;
						x < x60 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c49, cp_1 = c49_p_0, cp_0 = 0;
									c < c49 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_368);
									mem_vec_368 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_369);
									mem_vec_369 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_370);
									mem_vec_370 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_371);
									mem_vec_371 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_372);
									mem_vec_372 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_373);
									mem_vec_373 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_374);
									mem_vec_374 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_375);
									mem_vec_375 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_376);
									mem_vec_376 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_377);
									mem_vec_377 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_378);
									mem_vec_378 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_379);
									mem_vec_379 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_380);
									mem_vec_380 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_381);
									mem_vec_381 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_382);
									mem_vec_382 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_383);
									mem_vec_383 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_368);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_369);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_370);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_371);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_372);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_373);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_374);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_375);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_376);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_377);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_378);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_379);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_380);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_381);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_382);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_383);
					}
				}
			}
		}
	}
}


}