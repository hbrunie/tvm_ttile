#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (7, x); T (7, w);
  T (7, h); T (16, x); T (14, y); T (2, f); T (1, x)]
*/
IND_TYPE c, cp_0, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y36 = 0;
IND_TYPE x74 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c36 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (x, 1) (112 / 112)
for (x73 = x74, x73_p_0 = 0;
	x73 < x74 + 112;
	x73 += 112, x73_p_0 += 112){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f36, fp_0 = 0;
		f < f36 + 64;
		f += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 14) (112 / 8)
		for (y = y36, yp_0 = 0;
			y < y36 + 112;
			y += 8, yp_0 += 8){
			// y = 8, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 16) (112 / 7)
			for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
				x72 < x73 + 112;
				x72 += 7, x72_p_1 += 7, x72_p_0 += 7){
				// y = 8, x = 7, h = 7, w = 7, c = 3, f = 32
				// T (h, 7) (7 / 1)
				for (h = h36, hp_0 = 0;
					h < h36 + 7;
					h += 1, hp_0 += 1){
					// y = 8, x = 7, h = 1, w = 7, c = 3, f = 32
					// T (w, 7) (7 / 1)
					for (w = w36, wp_0 = 0;
						w < w36 + 7;
						w += 1, wp_0 += 1){
						// y = 8, x = 7, h = 1, w = 1, c = 3, f = 32
						// T (x, 7) (7 / 1)
						for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 7;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c36, cp_0 = 0;
										c < c36 + 3;
										c += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_256);
										mem_vec_256 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_257);
										mem_vec_257 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_258);
										mem_vec_258 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_259);
										mem_vec_259 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_260);
										mem_vec_260 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_261);
										mem_vec_261 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_262);
										mem_vec_262 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_263);
										mem_vec_263 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_264);
										mem_vec_264 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_265);
										mem_vec_265 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_266);
										mem_vec_266 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_267);
										mem_vec_267 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_268);
										mem_vec_268 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_269);
										mem_vec_269 = vec_22;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_270);
										mem_vec_270 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_271);
										mem_vec_271 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_271);
						}
					}
				}
			}
		}
	}
}


}