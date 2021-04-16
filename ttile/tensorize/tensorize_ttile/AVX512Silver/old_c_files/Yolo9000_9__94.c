#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, x, xp_0, x36_p_0, x37_p_0, xp_1, x36_p_1, xp_2, x36, x37, y, yp_0, y27_p_0, yp_1, y27;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y28 = 0;
IND_TYPE x38 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y27 = y28, y27_p_0 = 0;
		y27 < y28 + 8;
		y27 += 8, y27_p_0 += 8){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x37 = x38, x37_p_0 = 0;
			x37 < x38 + 68;
			x37 += 68, x37_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y27, yp_1 = y27_p_0, yp_0 = 0;
				y < y27 + 8;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
					x36 < x37 + 68;
					x36 += 68, x36_p_1 += 68, x36_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f18, fp_0 = 0;
						f < f18 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c27 = c28, c27_p_0 = 0;
							c27 < c28 + 256;
							c27 += 256, c27_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
											c < c27 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_288);
											mem_vec_288 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_289);
											mem_vec_289 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_290);
											mem_vec_290 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_291);
											mem_vec_291 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_292);
											mem_vec_292 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_293);
											mem_vec_293 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_294);
											mem_vec_294 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_295);
											mem_vec_295 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_296);
											mem_vec_296 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_297);
											mem_vec_297 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_298);
											mem_vec_298 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_299);
											mem_vec_299 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_300);
											mem_vec_300 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_301);
											mem_vec_301 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_302);
											mem_vec_302 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_303);
											mem_vec_303 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_303);
							}
						}
					}
				}
			}
		}
	}
	for (y27 = y28 + 8, y27_p_0 = 0;
		y27 < y28 + 8 + 60;
		y27 += 12, y27_p_0 += 12){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x37 = x38, x37_p_0 = 0;
			x37 < x38 + 68;
			x37 += 68, x37_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y27, yp_1 = y27_p_0, yp_0 = 0;
				y < y27 + 12;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
					x36 < x37 + 68;
					x36 += 68, x36_p_1 += 68, x36_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f18, fp_0 = 0;
						f < f18 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c27 = c28, c27_p_0 = 0;
							c27 < c28 + 256;
							c27 += 256, c27_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
											c < c27 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_304);
											mem_vec_304 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_305);
											mem_vec_305 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_306);
											mem_vec_306 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_307);
											mem_vec_307 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_308);
											mem_vec_308 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_309);
											mem_vec_309 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_310);
											mem_vec_310 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_311);
											mem_vec_311 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_312);
											mem_vec_312 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_313);
											mem_vec_313 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_314);
											mem_vec_314 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_315);
											mem_vec_315 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_316);
											mem_vec_316 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_317);
											mem_vec_317 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_318);
											mem_vec_318 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_319);
											mem_vec_319 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_320);
											mem_vec_320 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_321);
											mem_vec_321 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_322);
											mem_vec_322 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_323);
											mem_vec_323 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_324);
											mem_vec_324 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_325);
											mem_vec_325 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_326);
											mem_vec_326 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_327);
											mem_vec_327 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_327);
							}
						}
					}
				}
			}
		}
	}


}