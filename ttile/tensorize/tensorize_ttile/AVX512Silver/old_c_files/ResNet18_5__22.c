#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (14, x); T (1, c);
  T (2, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c43_p_0, cp_1, c43, f, fp_0, f43_p_0, fp_1, f43, x, xp_0, x54_p_0, xp_1, x54, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y36 = 0;
IND_TYPE x55 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c44 = 0;
IND_TYPE f44 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f43 = f44, f43_p_0 = 0;
	f43 < f44 + 128;
	f43 += 64, f43_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f43, fp_1 = f43_p_0, fp_0 = 0;
		f < f43 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y36, yp_0 = 0;
			y < y36 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x54 = x55, x54_p_0 = 0;
				x54 < x55 + 28;
				x54 += 14, x54_p_0 += 14){
				// y = 4, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c43 = c44, c43_p_0 = 0;
					c43 < c44 + 64;
					c43 += 64, c43_p_0 += 64){
					// y = 4, x = 14, h = 1, w = 1, c = 64, f = 64
					// T (x, 14) (14 / 1)
					for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
						x < x54 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c43, cp_1 = c43_p_0, cp_0 = 0;
									c < c43 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_336);
									mem_vec_336 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_337);
									mem_vec_337 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_338);
									mem_vec_338 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_339);
									mem_vec_339 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_340);
									mem_vec_340 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_341);
									mem_vec_341 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_342);
									mem_vec_342 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_343);
									mem_vec_343 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_344);
									mem_vec_344 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_345);
									mem_vec_345 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_346);
									mem_vec_346 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_347);
									mem_vec_347 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_348);
									mem_vec_348 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_349);
									mem_vec_349 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_350);
									mem_vec_350 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_351);
									mem_vec_351 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_337);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_338);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_339);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_340);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_341);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_342);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_343);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_344);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_345);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_346);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_347);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_348);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_349);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_350);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_351);
					}
				}
			}
		}
	}
}


}