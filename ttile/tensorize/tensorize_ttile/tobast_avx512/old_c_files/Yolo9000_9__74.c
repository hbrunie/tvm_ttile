#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (256, c); Hoist_vars [c]; T (1, x); T (4, x);
  T (17, y); T (2, f); T (1, c); T (17, x)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y40 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x81 = x82, x81_p_0 = 0;
	x81 < x82 + 68;
	x81 += 4, x81_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c60 = c61, c60_p_0 = 0;
		c60 < c61 + 256;
		c60 += 256, c60_p_0 += 256){
		// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
		// T (f, 2) (128 / 64)
		for (f = f40, fp_0 = 0;
			f < f40 + 128;
			f += 64, fp_0 += 64){
			// y = 68, x = 4, h = 1, w = 1, c = 256, f = 64
			// T (y, 17) (68 / 4)
			for (y = y40, yp_0 = 0;
				y < y40 + 68;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 1, w = 1, c = 256, f = 64
				// T (x, 4) (4 / 1)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 4;
					x80 += 1, x80_p_1 += 1, x80_p_0 += 1){
					// y = 4, x = 1, h = 1, w = 1, c = 256, f = 64
					// T (x, 1) (1 / 1)
					for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
						x < x80 + 1;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 256, f = 64
								// T (c, 256) (256 / 1)
								for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
									c < c60 + 256;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_320);
									mem_vec_320 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_321);
									mem_vec_321 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_322);
									mem_vec_322 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_323);
									mem_vec_323 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_324);
									mem_vec_324 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_325);
									mem_vec_325 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_326);
									mem_vec_326 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_327);
									mem_vec_327 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_328);
									mem_vec_328 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_329);
									mem_vec_329 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_330);
									mem_vec_330 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_331);
									mem_vec_331 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_332);
									mem_vec_332 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_333);
									mem_vec_333 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_334);
									mem_vec_334 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_335);
									mem_vec_335 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_320);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_321);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_322);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_323);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_324);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_325);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_326);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_327);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_328);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_329);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_330);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_331);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_332);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_333);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_334);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_335);
					}
				}
			}
		}
	}
}


}