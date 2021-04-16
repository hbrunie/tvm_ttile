#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (28, y); T (2, c); T (1, y); T (112, x)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, h, hp_0, w, wp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0, y57_p_0, yp_1, y57;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y58 = 0;
IND_TYPE x58 = 0;
IND_TYPE h38 = 0;
IND_TYPE w38 = 0;
IND_TYPE c58 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 112) (112 / 1)
for (x57 = x58, x57_p_0 = 0;
	x57 < x58 + 112;
	x57 += 1, x57_p_0 += 1){
	// y = 112, x = 1, h = 3, w = 3, c = 32, f = 32
	// T (y, 1) (112 / 112)
	for (y57 = y58, y57_p_0 = 0;
		y57 < y58 + 112;
		y57 += 112, y57_p_0 += 112){
		// y = 112, x = 1, h = 3, w = 3, c = 32, f = 32
		// T (c, 2) (32 / 16)
		for (c57 = c58, c57_p_0 = 0;
			c57 < c58 + 32;
			c57 += 16, c57_p_0 += 16){
			// y = 112, x = 1, h = 3, w = 3, c = 16, f = 32
			// T (y, 28) (112 / 4)
			for (y = y57, yp_1 = y57_p_0, yp_0 = 0;
				y < y57 + 112;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (1 / 1)
				for (x = x57, xp_1 = x57_p_0, xp_0 = 0;
					x < x57 + 1;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h38, hp_0 = 0;
						h < h38 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w38, wp_0 = 0;
							w < w38 + 3;
							w += 1, wp_0 += 1){
									mem_vec_304 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_305 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_306 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_307 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
										c < c57 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_304);
										mem_vec_304 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_305);
										mem_vec_305 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_306);
										mem_vec_306 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_307);
										mem_vec_307 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_308);
										mem_vec_308 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_309);
										mem_vec_309 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_310);
										mem_vec_310 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_311);
										mem_vec_311 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_312);
										mem_vec_312 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_313);
										mem_vec_313 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_314);
										mem_vec_314 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_315);
										mem_vec_315 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_316);
										mem_vec_316 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_317);
										mem_vec_317 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_318);
										mem_vec_318 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_319);
										mem_vec_319 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_304);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_305);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_306);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_307);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_308);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_309);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_310);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_311);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_312);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_313);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_314);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_315);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_316);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_317);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_318);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_319);
						}
					}
				}
			}
		}
	}
}


}