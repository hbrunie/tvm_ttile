#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (64, c); T (1, y); T (16, f); T (2, c); T (1, c)]
*/
IND_TYPE c, cp_0, c55_p_0, c56_p_0, c57_p_0, cp_1, c55_p_1, c56_p_1, cp_2, c55_p_2, cp_3, c55, c56, c57, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y22 = 0;
IND_TYPE x22 = 0;
IND_TYPE h19 = 0;
IND_TYPE w19 = 0;
IND_TYPE c58 = 0;
IND_TYPE f22 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c57 = c58, c57_p_0 = 0;
	c57 < c58 + 1024;
	c57 += 1024, c57_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (c, 2) (1024 / 512)
	for (c56 = c57, c56_p_1 = c57_p_0, c56_p_0 = 0;
		c56 < c57 + 1024;
		c56 += 512, c56_p_1 += 512, c56_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f22, fp_0 = 0;
			f < f22 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
			// T (y, 1) (7 / 7)
			for (y = y22, yp_0 = 0;
				y < y22 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 64) (512 / 8)
				for (c55 = c56, c55_p_2 = c56_p_1, c55_p_1 = c56_p_0, c55_p_0 = 0;
					c55 < c56 + 512;
					c55 += 8, c55_p_2 += 8, c55_p_1 += 8, c55_p_0 += 8){
					// y = 7, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (x, 7) (7 / 1)
					for (x = x22, xp_0 = 0;
						x < x22 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h19, hp_0 = 0;
							h < h19 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 8, f = 64
							// T (w, 3) (3 / 1)
							for (w = w19, wp_0 = 0;
								w < w19 + 3;
								w += 1, wp_0 += 1){
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c55, cp_3 = c55_p_2, cp_2 = c55_p_1, cp_1 = c55_p_0, cp_0 = 0;
											c < c55 + 8;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_308);
											mem_vec_308 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_309);
											mem_vec_309 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_310);
											mem_vec_310 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_311);
											mem_vec_311 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_312);
											mem_vec_312 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_313);
											mem_vec_313 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_314);
											mem_vec_314 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_315);
											mem_vec_315 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_316);
											mem_vec_316 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_317);
											mem_vec_317 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_318);
											mem_vec_318 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_319);
											mem_vec_319 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_320);
											mem_vec_320 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_321);
											mem_vec_321 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_322);
											mem_vec_322 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_323);
											mem_vec_323 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_324);
											mem_vec_324 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_325);
											mem_vec_325 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_326);
											mem_vec_326 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_327);
											mem_vec_327 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_328);
											mem_vec_328 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_329);
											mem_vec_329 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_330);
											mem_vec_330 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_331);
											mem_vec_331 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_332);
											mem_vec_332 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_333);
											mem_vec_333 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_334);
											mem_vec_334 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_335);
											mem_vec_335 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_335);
							}
						}
					}
				}
			}
		}
	}
}


}