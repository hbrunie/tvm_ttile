#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (1, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, f); T (64, c); T (2, x); T (2, y); T (4, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f30_p_0, fp_1, f30, h, hp_0, w, wp_0, x, xp_0, x30_p_0, xp_1, x30, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y20 = 0;
IND_TYPE x31 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c31 = 0;
IND_TYPE f31 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f30 = f31, f30_p_0 = 0;
	f30 < f31 + 128;
	f30 += 32, f30_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
	// T (y, 2) (28 / 14)
	for (y = y20, yp_0 = 0;
		y < y20 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 64, f = 32
		// T (x, 2) (28 / 14)
		for (x30 = x31, x30_p_0 = 0;
			x30 < x31 + 28;
			x30 += 14, x30_p_0 += 14){
			// y = 14, x = 14, h = 3, w = 3, c = 64, f = 32
			// T (c, 64) (64 / 1)
			for (c30 = c31, c30_p_0 = 0;
				c30 < c31 + 64;
				c30 += 1, c30_p_0 += 1){
				// y = 14, x = 14, h = 3, w = 3, c = 1, f = 32
				// T (f, 1) (32 / 32)
				for (f = f30, fp_1 = f30_p_0, fp_0 = 0;
					f < f30 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h20, hp_0 = 0;
						h < h20 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 14, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w20, wp_0 = 0;
							w < w20 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 14, h = 1, w = 1, c = 1, f = 32
							// T (x, 14) (14 / 1)
							for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
								x < x30 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_280);
											mem_vec_280 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_281);
											mem_vec_281 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_282);
											mem_vec_282 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_283);
											mem_vec_283 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_284);
											mem_vec_284 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_285);
											mem_vec_285 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_286);
											mem_vec_286 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_287);
											mem_vec_287 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_288);
											mem_vec_288 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_289);
											mem_vec_289 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_290);
											mem_vec_290 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_291);
											mem_vec_291 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_292);
											mem_vec_292 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_293);
											mem_vec_293 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_294);
											mem_vec_294 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_295);
											mem_vec_295 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_296);
											mem_vec_296 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_297);
											mem_vec_297 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_298);
											mem_vec_298 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_299);
											mem_vec_299 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_300);
											mem_vec_300 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_301);
											mem_vec_301 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_302);
											mem_vec_302 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_303);
											mem_vec_303 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_304);
											mem_vec_304 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_305);
											mem_vec_305 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_306);
											mem_vec_306 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_307);
											mem_vec_307 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_307);
							}
						}
					}
				}
			}
		}
	}
}


}