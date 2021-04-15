#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, c); T (4, x); T (14, y); T (8, c)]
*/
IND_TYPE c, cp_0, c36_p_0, c37_p_0, cp_1, c36_p_1, cp_2, c36, c37, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y24 = 0;
IND_TYPE x49 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c38 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
for (c37 = c38, c37_p_0 = 0;
	c37 < c38 + 64;
	c37 += 8, c37_p_0 += 8){
	// y = 56, x = 56, h = 3, w = 3, c = 8, f = 64
	// T (y, 14) (56 / 4)
	for (y = y24, yp_0 = 0;
		y < y24 + 56;
		y += 4, yp_0 += 4){
		// y = 4, x = 56, h = 3, w = 3, c = 8, f = 64
		// T (x, 4) (56 / 14)
		for (x48 = x49, x48_p_0 = 0;
			x48 < x49 + 56;
			x48 += 14, x48_p_0 += 14){
			// y = 4, x = 14, h = 3, w = 3, c = 8, f = 64
			// T (c, 1) (8 / 8)
			for (c36 = c37, c36_p_1 = c37_p_0, c36_p_0 = 0;
				c36 < c37 + 8;
				c36 += 8, c36_p_1 += 8, c36_p_0 += 8){
				// y = 4, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (h, 3) (3 / 1)
				for (h = h24, hp_0 = 0;
					h < h24 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 14, h = 1, w = 3, c = 8, f = 64
					// T (w, 3) (3 / 1)
					for (w = w24, wp_0 = 0;
						w < w24 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 14, h = 1, w = 1, c = 8, f = 64
						// T (x, 14) (14 / 1)
						for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
							x < x48 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c36, cp_2 = c36_p_1, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_236);
										mem_vec_236 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_237);
										mem_vec_237 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_238);
										mem_vec_238 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_239);
										mem_vec_239 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_240);
										mem_vec_240 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_241);
										mem_vec_241 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_242);
										mem_vec_242 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_243);
										mem_vec_243 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_244);
										mem_vec_244 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_245);
										mem_vec_245 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_246);
										mem_vec_246 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_247);
										mem_vec_247 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_248);
										mem_vec_248 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_249);
										mem_vec_249 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_250);
										mem_vec_250 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_251);
										mem_vec_251 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_236);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_237);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_238);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_239);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_251);
						}
					}
				}
			}
		}
	}
}


}