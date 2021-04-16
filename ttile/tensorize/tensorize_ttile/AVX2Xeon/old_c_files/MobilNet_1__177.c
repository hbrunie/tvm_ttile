#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (2, x); T (1, y); T (1, c); T (28, y); T (56, x)]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, h, hp_0, w, wp_0, x, xp_0, x45_p_0, xp_1, x45, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h30 = 0;
IND_TYPE w30 = 0;
IND_TYPE c46 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
for (x45 = x46, x45_p_0 = 0;
	x45 < x46 + 112;
	x45 += 2, x45_p_0 += 2){
	// y = 112, x = 2, h = 3, w = 3, c = 32, f = 32
	// T (y, 28) (112 / 4)
	for (y45 = y46, y45_p_0 = 0;
		y45 < y46 + 112;
		y45 += 4, y45_p_0 += 4){
		// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c45 = c46, c45_p_0 = 0;
			c45 < c46 + 32;
			c45 += 32, c45_p_0 += 32){
			// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
			// T (y, 1) (4 / 4)
			for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
				y < y45 + 4;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
				// T (x, 2) (2 / 1)
				for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
					x < x45 + 2;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h30, hp_0 = 0;
						h < h30 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w30, wp_0 = 0;
							w < w30 + 3;
							w += 1, wp_0 += 1){
									mem_vec_240 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_241 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_242 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_243 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_240);
										mem_vec_240 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_241);
										mem_vec_241 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_242);
										mem_vec_242 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_243);
										mem_vec_243 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_244);
										mem_vec_244 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_245);
										mem_vec_245 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_246);
										mem_vec_246 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_247);
										mem_vec_247 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_248);
										mem_vec_248 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_249);
										mem_vec_249 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_250);
										mem_vec_250 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_251);
										mem_vec_251 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_252);
										mem_vec_252 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_253);
										mem_vec_253 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_254);
										mem_vec_254 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_255);
										mem_vec_255 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_240);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_241);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_242);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_243);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_244);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_245);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_246);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_247);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_248);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_249);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_250);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_251);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_252);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_253);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_254);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_255);
						}
					}
				}
			}
		}
	}
}


}