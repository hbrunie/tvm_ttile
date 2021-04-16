#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (64, c); Hoist_vars [c]; T (14, x); T (1, c);
  T (2, x); T (4, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c25_p_0, cp_1, c25, f, fp_0, f25_p_0, fp_1, f25, x, xp_0, x30_p_0, xp_1, x30, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y20 = 0;
IND_TYPE x31 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c26 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f25 = f26, f25_p_0 = 0;
	f25 < f26 + 128;
	f25 += 64, f25_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f25, fp_1 = f25_p_0, fp_0 = 0;
		f < f25 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y20, yp_0 = 0;
			y < y20 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (28 / 14)
			for (x30 = x31, x30_p_0 = 0;
				x30 < x31 + 28;
				x30 += 14, x30_p_0 += 14){
				// y = 7, x = 14, h = 1, w = 1, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c25 = c26, c25_p_0 = 0;
					c25 < c26 + 64;
					c25 += 64, c25_p_0 += 64){
					// y = 7, x = 14, h = 1, w = 1, c = 64, f = 64
					// T (x, 14) (14 / 1)
					for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
						x < x30 + 14;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c25, cp_1 = c25_p_0, cp_0 = 0;
									c < c25 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_280);
									mem_vec_280 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_281);
									mem_vec_281 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_282);
									mem_vec_282 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_283);
									mem_vec_283 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_284);
									mem_vec_284 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_285);
									mem_vec_285 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_286);
									mem_vec_286 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_287);
									mem_vec_287 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_288);
									mem_vec_288 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_289);
									mem_vec_289 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_290);
									mem_vec_290 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_291);
									mem_vec_291 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_292);
									mem_vec_292 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_293);
									mem_vec_293 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_294);
									mem_vec_294 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_295);
									mem_vec_295 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_296);
									mem_vec_296 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_297);
									mem_vec_297 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_298);
									mem_vec_298 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_299);
									mem_vec_299 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_300);
									mem_vec_300 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_301);
									mem_vec_301 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_302);
									mem_vec_302 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_303);
									mem_vec_303 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_304);
									mem_vec_304 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_305);
									mem_vec_305 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_306);
									mem_vec_306 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_307);
									mem_vec_307 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_280);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_281);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_282);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_283);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_284);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_285);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_286);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_287);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_288);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_289);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_290);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_291);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_292);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_293);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_294);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_295);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_296);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_297);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_298);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_299);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_300);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_301);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_302);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_303);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_304);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_305);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_306);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_307);
					}
				}
			}
		}
	}
}


}