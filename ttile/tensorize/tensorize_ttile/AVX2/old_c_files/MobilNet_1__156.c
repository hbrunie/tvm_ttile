#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (14, y); T (2, c); T (2, y); T (112, x)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, h, hp_0, w, wp_0, x, xp_0, x66_p_0, xp_1, x66, y, yp_0, y66_p_0, yp_1, y66;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y67 = 0;
IND_TYPE x67 = 0;
IND_TYPE h44 = 0;
IND_TYPE w44 = 0;
IND_TYPE c67 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 112) (112 / 1)
for (x66 = x67, x66_p_0 = 0;
	x66 < x67 + 112;
	x66 += 1, x66_p_0 += 1){
	// y = 112, x = 1, h = 3, w = 3, c = 32, f = 32
	// T (y, 2) (112 / 56)
	for (y66 = y67, y66_p_0 = 0;
		y66 < y67 + 112;
		y66 += 56, y66_p_0 += 56){
		// y = 56, x = 1, h = 3, w = 3, c = 32, f = 32
		// T (c, 2) (32 / 16)
		for (c66 = c67, c66_p_0 = 0;
			c66 < c67 + 32;
			c66 += 16, c66_p_0 += 16){
			// y = 56, x = 1, h = 3, w = 3, c = 16, f = 32
			// T (y, 14) (56 / 4)
			for (y = y66, yp_1 = y66_p_0, yp_0 = 0;
				y < y66 + 56;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (1 / 1)
				for (x = x66, xp_1 = x66_p_0, xp_0 = 0;
					x < x66 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h44, hp_0 = 0;
						h < h44 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w44, wp_0 = 0;
							w < w44 + 3;
							w += 1, wp_0 += 1){
									mem_vec_352 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_353 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_354 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_355 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
										c < c66 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_352);
										mem_vec_352 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_353);
										mem_vec_353 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_354);
										mem_vec_354 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_355);
										mem_vec_355 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_356);
										mem_vec_356 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_357);
										mem_vec_357 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_358);
										mem_vec_358 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_359);
										mem_vec_359 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_360);
										mem_vec_360 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_361);
										mem_vec_361 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_362);
										mem_vec_362 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_363);
										mem_vec_363 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_364);
										mem_vec_364 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_365);
										mem_vec_365 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_366);
										mem_vec_366 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_367);
										mem_vec_367 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_352);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_353);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_354);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_355);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_356);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_357);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_358);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_359);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_360);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_361);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_362);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_363);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_367);
						}
					}
				}
			}
		}
	}
}


}