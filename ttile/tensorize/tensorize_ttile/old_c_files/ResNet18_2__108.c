#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (4, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (7, x); T (4, y); T (2, f); T (16, c); T (1, x)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y36 = 0;
IND_TYPE x74 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c55 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x73 = x74, x73_p_0 = 0;
	x73 < x74 + 56;
	x73 += 56, x73_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 16) (64 / 4)
	for (c54 = c55, c54_p_0 = 0;
		c54 < c55 + 64;
		c54 += 4, c54_p_0 += 4){
		// y = 56, x = 56, h = 3, w = 3, c = 4, f = 64
		// T (f, 2) (64 / 32)
		for (f = f36, fp_0 = 0;
			f < f36 + 64;
			f += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 4, f = 32
			// T (y, 4) (56 / 14)
			for (y = y36, yp_0 = 0;
				y < y36 + 56;
				y += 14, yp_0 += 14){
				// y = 14, x = 56, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (56 / 8)
				for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
					x72 < x73 + 56;
					x72 += 8, x72_p_1 += 8, x72_p_0 += 8){
					// y = 14, x = 8, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h36, hp_0 = 0;
						h < h36 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 8, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w36, wp_0 = 0;
							w < w36 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 8, h = 1, w = 1, c = 4, f = 32
							// T (x, 8) (8 / 1)
							for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
								x < x72 + 8;
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
										mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 4, f = 32
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
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_304);
											mem_vec_304 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_305);
											mem_vec_305 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_306);
											mem_vec_306 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_307);
											mem_vec_307 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_308);
											mem_vec_308 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_309);
											mem_vec_309 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_310);
											mem_vec_310 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_311);
											mem_vec_311 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_312);
											mem_vec_312 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_313);
											mem_vec_313 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_314);
											mem_vec_314 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_315);
											mem_vec_315 = vec_43;
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
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_315);
							}
						}
					}
				}
			}
		}
	}
}


}