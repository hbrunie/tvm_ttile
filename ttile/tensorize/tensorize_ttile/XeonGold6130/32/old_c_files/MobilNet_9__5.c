#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (32, c); T (1, y); T (16, f); T (2, c); T (1, c)]
*/
IND_TYPE c, cp_0, c50_p_0, c51_p_0, c52_p_0, cp_1, c50_p_1, c51_p_1, cp_2, c50_p_2, cp_3, c50, c51, c52, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y20 = 0;
IND_TYPE x20 = 0;
IND_TYPE h17 = 0;
IND_TYPE w17 = 0;
IND_TYPE c53 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c52 = c53, c52_p_0 = 0;
	c52 < c53 + 1024;
	c52 += 1024, c52_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (c, 2) (1024 / 512)
	for (c51 = c52, c51_p_1 = c52_p_0, c51_p_0 = 0;
		c51 < c52 + 1024;
		c51 += 512, c51_p_1 += 512, c51_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f20, fp_0 = 0;
			f < f20 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
			// T (y, 1) (7 / 7)
			for (y = y20, yp_0 = 0;
				y < y20 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 32) (512 / 16)
				for (c50 = c51, c50_p_2 = c51_p_1, c50_p_1 = c51_p_0, c50_p_0 = 0;
					c50 < c51 + 512;
					c50 += 16, c50_p_2 += 16, c50_p_1 += 16, c50_p_0 += 16){
					// y = 7, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (x, 7) (7 / 1)
					for (x = x20, xp_0 = 0;
						x < x20 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h17, hp_0 = 0;
							h < h17 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w17, wp_0 = 0;
								w < w17 + 3;
								w += 1, wp_0 += 1){
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
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c50, cp_3 = c50_p_2, cp_2 = c50_p_1, cp_1 = c50_p_0, cp_0 = 0;
											c < c50 + 16;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
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
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_284);
											mem_vec_284 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_285);
											mem_vec_285 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_286);
											mem_vec_286 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_287);
											mem_vec_287 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_288);
											mem_vec_288 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_289);
											mem_vec_289 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_290);
											mem_vec_290 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_291);
											mem_vec_291 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_292);
											mem_vec_292 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_293);
											mem_vec_293 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_294);
											mem_vec_294 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_295);
											mem_vec_295 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_296);
											mem_vec_296 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_297);
											mem_vec_297 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_298);
											mem_vec_298 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_299);
											mem_vec_299 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_300);
											mem_vec_300 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_301);
											mem_vec_301 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_302);
											mem_vec_302 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_303);
											mem_vec_303 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
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
}


}