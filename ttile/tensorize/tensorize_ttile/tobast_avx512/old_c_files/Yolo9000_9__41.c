#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (4, x); T (1, x);
  T (17, y); T (2, f); T (32, c); T (17, x)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y32 = 0;
IND_TYPE x66 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c49 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x65 = x66, x65_p_0 = 0;
	x65 < x66 + 68;
	x65 += 4, x65_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 32) (256 / 8)
	for (c48 = c49, c48_p_0 = 0;
		c48 < c49 + 256;
		c48 += 8, c48_p_0 += 8){
		// y = 68, x = 4, h = 1, w = 1, c = 8, f = 128
		// T (f, 2) (128 / 64)
		for (f = f32, fp_0 = 0;
			f < f32 + 128;
			f += 64, fp_0 += 64){
			// y = 68, x = 4, h = 1, w = 1, c = 8, f = 64
			// T (y, 17) (68 / 4)
			for (y = y32, yp_0 = 0;
				y < y32 + 68;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 1, w = 1, c = 8, f = 64
				// T (x, 1) (4 / 4)
				for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
					x64 < x65 + 4;
					x64 += 4, x64_p_1 += 4, x64_p_0 += 4){
					// y = 4, x = 4, h = 1, w = 1, c = 8, f = 64
					// T (x, 4) (4 / 1)
					for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
						x < x64 + 4;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
								// T (c, 8) (8 / 1)
								for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
									c < c48 + 8;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_256);
									mem_vec_256 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_257);
									mem_vec_257 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_258);
									mem_vec_258 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_259);
									mem_vec_259 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_260);
									mem_vec_260 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_261);
									mem_vec_261 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_262);
									mem_vec_262 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_263);
									mem_vec_263 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_264);
									mem_vec_264 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_265);
									mem_vec_265 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_266);
									mem_vec_266 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_267);
									mem_vec_267 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_268);
									mem_vec_268 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_269);
									mem_vec_269 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_270);
									mem_vec_270 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_271);
									mem_vec_271 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_256);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_257);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_258);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_259);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_260);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_261);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_262);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_263);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_264);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_265);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_266);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_267);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_268);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_269);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_270);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_271);
					}
				}
			}
		}
	}
}


}