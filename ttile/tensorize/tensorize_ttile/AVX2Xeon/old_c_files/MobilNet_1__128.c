#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (2, x); T (1, y); T (4, c); T (28, y); T (56, x)]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, h, hp_0, w, wp_0, x, xp_0, x51_p_0, xp_1, x51, y, yp_0, y51_p_0, yp_1, y51;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y52 = 0;
IND_TYPE x52 = 0;
IND_TYPE h34 = 0;
IND_TYPE w34 = 0;
IND_TYPE c52 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
for (x51 = x52, x51_p_0 = 0;
	x51 < x52 + 112;
	x51 += 2, x51_p_0 += 2){
	// y = 112, x = 2, h = 3, w = 3, c = 32, f = 32
	// T (y, 28) (112 / 4)
	for (y51 = y52, y51_p_0 = 0;
		y51 < y52 + 112;
		y51 += 4, y51_p_0 += 4){
		// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
		// T (c, 4) (32 / 8)
		for (c51 = c52, c51_p_0 = 0;
			c51 < c52 + 32;
			c51 += 8, c51_p_0 += 8){
			// y = 4, x = 2, h = 3, w = 3, c = 8, f = 32
			// T (y, 1) (4 / 4)
			for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
				y < y51 + 4;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 8, f = 32
				// T (x, 2) (2 / 1)
				for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
					x < x51 + 2;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h34, hp_0 = 0;
						h < h34 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w34, wp_0 = 0;
							w < w34 + 3;
							w += 1, wp_0 += 1){
									mem_vec_272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
										c < c51 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_272);
										mem_vec_272 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_273);
										mem_vec_273 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_274);
										mem_vec_274 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_275);
										mem_vec_275 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_276);
										mem_vec_276 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_277);
										mem_vec_277 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_278);
										mem_vec_278 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_279);
										mem_vec_279 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_280);
										mem_vec_280 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_281);
										mem_vec_281 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_282);
										mem_vec_282 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_283);
										mem_vec_283 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_284);
										mem_vec_284 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_285);
										mem_vec_285 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_286);
										mem_vec_286 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_287);
										mem_vec_287 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_272);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_273);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_274);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_275);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_276);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_277);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_278);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_279);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_280);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_281);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_282);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_283);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_284);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_285);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_286);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_287);
						}
					}
				}
			}
		}
	}
}


}