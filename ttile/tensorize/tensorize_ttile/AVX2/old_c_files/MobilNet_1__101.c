#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (14, y); T (1, c); T (2, y); T (112, x)]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, h, hp_0, w, wp_0, x, xp_0, x63_p_0, xp_1, x63, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y64 = 0;
IND_TYPE x64 = 0;
IND_TYPE h42 = 0;
IND_TYPE w42 = 0;
IND_TYPE c64 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 112) (112 / 1)
for (x63 = x64, x63_p_0 = 0;
	x63 < x64 + 112;
	x63 += 1, x63_p_0 += 1){
	// y = 112, x = 1, h = 3, w = 3, c = 32, f = 32
	// T (y, 2) (112 / 56)
	for (y63 = y64, y63_p_0 = 0;
		y63 < y64 + 112;
		y63 += 56, y63_p_0 += 56){
		// y = 56, x = 1, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c63 = c64, c63_p_0 = 0;
			c63 < c64 + 32;
			c63 += 32, c63_p_0 += 32){
			// y = 56, x = 1, h = 3, w = 3, c = 32, f = 32
			// T (y, 14) (56 / 4)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 56;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (1 / 1)
				for (x = x63, xp_1 = x63_p_0, xp_0 = 0;
					x < x63 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h42, hp_0 = 0;
						h < h42 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w42, wp_0 = 0;
							w < w42 + 3;
							w += 1, wp_0 += 1){
									mem_vec_336 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_337 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_338 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_339 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
										c < c63 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_336);
										mem_vec_336 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_337);
										mem_vec_337 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_338);
										mem_vec_338 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_339);
										mem_vec_339 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_340);
										mem_vec_340 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_341);
										mem_vec_341 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_342);
										mem_vec_342 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_343);
										mem_vec_343 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_344);
										mem_vec_344 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_345);
										mem_vec_345 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_346);
										mem_vec_346 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_347);
										mem_vec_347 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_348);
										mem_vec_348 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_349);
										mem_vec_349 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_350);
										mem_vec_350 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_351);
										mem_vec_351 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_336);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_337);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_338);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_339);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_340);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_341);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_342);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_343);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_344);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_345);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_346);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_347);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_348);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_349);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_350);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_351);
						}
					}
				}
			}
		}
	}
}


}