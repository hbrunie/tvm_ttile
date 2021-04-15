#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, f); T (16, c); T (14, x); T (4, y); T (1, f)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, f42_p_0, fp_1, f42, h, hp_0, w, wp_0, x, xp_0, x42_p_0, xp_1, x42, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y28 = 0;
IND_TYPE x43 = 0;
IND_TYPE h28 = 0;
IND_TYPE w28 = 0;
IND_TYPE c43 = 0;
IND_TYPE f43 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f42 = f43, f42_p_0 = 0;
	f42 < f43 + 128;
	f42 += 128, f42_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
	// T (y, 4) (28 / 7)
	for (y = y28, yp_0 = 0;
		y < y28 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (x, 14) (28 / 2)
		for (x42 = x43, x42_p_0 = 0;
			x42 < x43 + 28;
			x42 += 2, x42_p_0 += 2){
			// y = 7, x = 2, h = 3, w = 3, c = 64, f = 128
			// T (c, 16) (64 / 4)
			for (c42 = c43, c42_p_0 = 0;
				c42 < c43 + 64;
				c42 += 4, c42_p_0 += 4){
				// y = 7, x = 2, h = 3, w = 3, c = 4, f = 128
				// T (f, 2) (128 / 64)
				for (f = f42, fp_1 = f42_p_0, fp_0 = 0;
					f < f42 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h28, hp_0 = 0;
						h < h28 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 2, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w28, wp_0 = 0;
							w < w28 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 2, h = 1, w = 1, c = 4, f = 64
							// T (x, 2) (2 / 1)
							for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
								x < x42 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
											c < c42 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_284);
											mem_vec_284 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_285);
											mem_vec_285 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_286);
											mem_vec_286 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_287);
											mem_vec_287 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_288);
											mem_vec_288 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_289);
											mem_vec_289 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_290);
											mem_vec_290 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_291);
											mem_vec_291 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_292);
											mem_vec_292 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_293);
											mem_vec_293 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_294);
											mem_vec_294 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_295);
											mem_vec_295 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_296);
											mem_vec_296 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_297);
											mem_vec_297 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_298);
											mem_vec_298 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_299);
											mem_vec_299 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_300);
											mem_vec_300 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_301);
											mem_vec_301 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_302);
											mem_vec_302 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_303);
											mem_vec_303 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_304);
											mem_vec_304 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_305);
											mem_vec_305 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_306);
											mem_vec_306 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_307);
											mem_vec_307 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_308);
											mem_vec_308 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_309);
											mem_vec_309 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_310);
											mem_vec_310 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_311);
											mem_vec_311 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_311);
							}
						}
					}
				}
			}
		}
	}
}


}