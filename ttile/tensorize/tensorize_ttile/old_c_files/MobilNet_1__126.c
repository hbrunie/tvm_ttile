#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (4, c); Hoist_vars [c]; T (16, x); T (3, w);
  T (3, h); T (1, x); T (14, y); T (8, c); T (7, x)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, h, hp_0, w, wp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y36 = 0;
IND_TYPE x74 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c55 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x73 = x74, x73_p_0 = 0;
	x73 < x74 + 112;
	x73 += 16, x73_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c54 = c55, c54_p_0 = 0;
		c54 < c55 + 32;
		c54 += 4, c54_p_0 += 4){
		// y = 112, x = 16, h = 3, w = 3, c = 4, f = 32
		// T (y, 14) (112 / 8)
		for (y = y36, yp_0 = 0;
			y < y36 + 112;
			y += 8, yp_0 += 8){
			// y = 8, x = 16, h = 3, w = 3, c = 4, f = 32
			// T (x, 1) (16 / 16)
			for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
				x72 < x73 + 16;
				x72 += 16, x72_p_1 += 16, x72_p_0 += 16){
				// y = 8, x = 16, h = 3, w = 3, c = 4, f = 32
				// T (h, 3) (3 / 1)
				for (h = h36, hp_0 = 0;
					h < h36 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 16, h = 1, w = 3, c = 4, f = 32
					// T (w, 3) (3 / 1)
					for (w = w36, wp_0 = 0;
						w < w36 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 16, h = 1, w = 1, c = 4, f = 32
						// T (x, 16) (16 / 1)
						for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 16;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = 8, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
										c < c54 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_288);
										mem_vec_288 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_289);
										mem_vec_289 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_290);
										mem_vec_290 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_291);
										mem_vec_291 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_292);
										mem_vec_292 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_293);
										mem_vec_293 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_294);
										mem_vec_294 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_295);
										mem_vec_295 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_296);
										mem_vec_296 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_297);
										mem_vec_297 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_298);
										mem_vec_298 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_299);
										mem_vec_299 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_300);
										mem_vec_300 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_301);
										mem_vec_301 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_302);
										mem_vec_302 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_303);
										mem_vec_303 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_303);
						}
					}
				}
			}
		}
	}
}


}