#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (8, f); T (64, c); T (14, x); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f36_p_0, fp_1, f36, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f37 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f36 = f37, f36_p_0 = 0;
	f36 < f37 + 256;
	f36 += 256, f36_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (y, 1) (14 / 14)
	for (y = y24, yp_0 = 0;
		y < y24 + 14;
		y += 14, yp_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
		// T (x, 14) (14 / 1)
		for (x36 = x37, x36_p_0 = 0;
			x36 < x37 + 14;
			x36 += 1, x36_p_0 += 1){
			// y = 14, x = 1, h = 3, w = 3, c = 128, f = 256
			// T (c, 64) (128 / 2)
			for (c36 = c37, c36_p_0 = 0;
				c36 < c37 + 128;
				c36 += 2, c36_p_0 += 2){
				// y = 14, x = 1, h = 3, w = 3, c = 2, f = 256
				// T (f, 8) (256 / 32)
				for (f = f36, fp_1 = f36_p_0, fp_0 = 0;
					f < f36 + 256;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h24, hp_0 = 0;
						h < h24 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w24, wp_0 = 0;
							w < w24 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (x, 1) (1 / 1)
							for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_308);
											mem_vec_308 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_309);
											mem_vec_309 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_310);
											mem_vec_310 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_311);
											mem_vec_311 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_312);
											mem_vec_312 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_313);
											mem_vec_313 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_314);
											mem_vec_314 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_315);
											mem_vec_315 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_316);
											mem_vec_316 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_317);
											mem_vec_317 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_318);
											mem_vec_318 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_319);
											mem_vec_319 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_320);
											mem_vec_320 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_321);
											mem_vec_321 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_322);
											mem_vec_322 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_323);
											mem_vec_323 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_324);
											mem_vec_324 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_325);
											mem_vec_325 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_326);
											mem_vec_326 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_327);
											mem_vec_327 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_328);
											mem_vec_328 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_329);
											mem_vec_329 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_330);
											mem_vec_330 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_331);
											mem_vec_331 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_332);
											mem_vec_332 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_333);
											mem_vec_333 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_334);
											mem_vec_334 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_335);
											mem_vec_335 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_335);
							}
						}
					}
				}
			}
		}
	}
}


}