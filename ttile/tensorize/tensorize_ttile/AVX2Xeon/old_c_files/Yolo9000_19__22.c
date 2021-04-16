#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (16, f); T (2, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c21_p_0, cp_1, c21, f, fp_0, x, xp_0, x21_p_0, xp_1, x21, y, yp_0, y21_p_0, yp_1, y21;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y22 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c22 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y21 = y22, y21_p_0 = 0;
		y21 < y22 + 12;
		y21 += 4, y21_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x21 = x22, x21_p_0 = 0;
			x21 < x22 + 17;
			x21 += 17, x21_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 2) (1024 / 512)
			for (c21 = c22, c21_p_0 = 0;
				c21 < c22 + 1024;
				c21 += 512, c21_p_0 += 512){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
				// T (f, 16) (512 / 32)
				for (f = f14, fp_0 = 0;
					f < f14 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y21, yp_1 = y21_p_0, yp_0 = 0;
						y < y21 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x21, xp_1 = x21_p_0, xp_0 = 0;
							x < x21 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_252 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_253 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_254 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_255 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
										c < c21 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_252);
										mem_vec_252 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_253);
										mem_vec_253 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_254);
										mem_vec_254 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_255);
										mem_vec_255 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_256);
										mem_vec_256 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_257);
										mem_vec_257 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_258);
										mem_vec_258 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_259);
										mem_vec_259 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_260);
										mem_vec_260 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_261);
										mem_vec_261 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_262);
										mem_vec_262 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_263);
										mem_vec_263 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_264);
										mem_vec_264 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_265);
										mem_vec_265 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_266);
										mem_vec_266 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_267);
										mem_vec_267 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_252);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_253);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_254);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_255);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_256);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_257);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_258);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_259);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_260);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_261);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_262);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_263);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_264);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_265);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_266);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_267);
						}
					}
				}
			}
		}
	}
	for (y21 = y22 + 12, y21_p_0 = 0;
		y21 < y22 + 12 + 5;
		y21 += 5, y21_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x21 = x22, x21_p_0 = 0;
			x21 < x22 + 17;
			x21 += 17, x21_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 2) (1024 / 512)
			for (c21 = c22, c21_p_0 = 0;
				c21 < c22 + 1024;
				c21 += 512, c21_p_0 += 512){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
				// T (f, 16) (512 / 32)
				for (f = f14, fp_0 = 0;
					f < f14 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y21, yp_1 = y21_p_0, yp_0 = 0;
						y < y21 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x21, xp_1 = x21_p_0, xp_0 = 0;
							x < x21 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_268 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_269 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_270 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_271 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
										c < c21 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_268);
										mem_vec_268 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_269);
										mem_vec_269 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_270);
										mem_vec_270 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_271);
										mem_vec_271 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_272);
										mem_vec_272 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_273);
										mem_vec_273 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_274);
										mem_vec_274 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_275);
										mem_vec_275 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_276);
										mem_vec_276 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_277);
										mem_vec_277 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_278);
										mem_vec_278 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_279);
										mem_vec_279 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_280);
										mem_vec_280 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_281);
										mem_vec_281 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_282);
										mem_vec_282 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_283);
										mem_vec_283 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_284);
										mem_vec_284 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_285);
										mem_vec_285 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_286);
										mem_vec_286 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_287);
										mem_vec_287 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_268);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_269);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_270);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_271);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_272);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_273);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_274);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_275);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_276);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_277);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_278);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_279);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_280);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_281);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_282);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_283);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_284);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_285);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_286);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_287);
						}
					}
				}
			}
		}
	}


}