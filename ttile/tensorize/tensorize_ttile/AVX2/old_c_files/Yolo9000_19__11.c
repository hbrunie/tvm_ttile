#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (32, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, x, xp_0, x24_p_0, xp_1, x24, y, yp_0, y24_p_0, yp_1, y24;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y25 = 0;
IND_TYPE x25 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c25 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y24 = y25, y24_p_0 = 0;
	y24 < y25 + 17;
	y24 += 17, y24_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x24 = x25, x24_p_0 = 0;
		x24 < x25 + 17;
		x24 += 17, x24_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 32) (1024 / 32)
		for (c24 = c25, c24_p_0 = 0;
			c24 < c25 + 1024;
			c24 += 32, c24_p_0 += 32){
			// y = 17, x = 17, h = 1, w = 1, c = 32, f = 512
			// T (f, 16) (512 / 32)
			for (f = f16, fp_0 = 0;
				f < f16 + 512;
				f += 32, fp_0 += 32){
					for (y = y24, yp_1 = y24_p_0, yp_0 = 0;
						y < y24 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
							x < x24 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_290 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_291 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_288);
										mem_vec_288 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_289);
										mem_vec_289 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_290);
										mem_vec_290 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_291);
										mem_vec_291 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_292);
										mem_vec_292 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_293);
										mem_vec_293 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_294);
										mem_vec_294 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_295);
										mem_vec_295 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_296);
										mem_vec_296 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_297);
										mem_vec_297 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_298);
										mem_vec_298 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_299);
										mem_vec_299 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_300);
										mem_vec_300 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_301);
										mem_vec_301 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_302);
										mem_vec_302 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_303);
										mem_vec_303 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_289);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_290);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_291);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_292);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_293);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_294);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_295);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_296);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_297);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_298);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_299);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_301);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_302);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_303);
						}
					}
					for (y = y24 + 12, yp_1 = y24_p_0, yp_0 = 0;
						y < y24 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
							x < x24 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
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
									mem_vec_320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
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
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_320);
										mem_vec_320 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_321);
										mem_vec_321 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_322);
										mem_vec_322 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_323);
										mem_vec_323 = vec_28;
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
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_320);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_321);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_322);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_323);
						}
					}
			}
		}
	}
}


}