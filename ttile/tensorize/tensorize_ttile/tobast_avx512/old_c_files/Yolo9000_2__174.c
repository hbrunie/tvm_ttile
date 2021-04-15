#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (4, x); T (68, y); T (16, c); T (1, x); T (2, x)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, h, hp_0, w, wp_0, x, xp_0, x100_p_0, x101_p_0, x102_p_0, xp_1, x100_p_1, x101_p_1, xp_2, x100_p_2, xp_3, x100, x101, x102, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y40 = 0;
IND_TYPE x103 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c61 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x102 = x103, x102_p_0 = 0;
	x102 < x103 + 272;
	x102 += 136, x102_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 1) (136 / 136)
	for (x101 = x102, x101_p_1 = x102_p_0, x101_p_0 = 0;
		x101 < x102 + 136;
		x101 += 136, x101_p_1 += 136, x101_p_0 += 136){
		// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
		// T (c, 16) (32 / 2)
		for (c60 = c61, c60_p_0 = 0;
			c60 < c61 + 32;
			c60 += 2, c60_p_0 += 2){
			// y = 272, x = 136, h = 3, w = 3, c = 2, f = 64
			// T (y, 68) (272 / 4)
			for (y = y40, yp_0 = 0;
				y < y40 + 272;
				y += 4, yp_0 += 4){
				// y = 4, x = 136, h = 3, w = 3, c = 2, f = 64
				// T (x, 4) (136 / 34)
				for (x100 = x101, x100_p_2 = x101_p_1, x100_p_1 = x101_p_0, x100_p_0 = 0;
					x100 < x101 + 136;
					x100 += 34, x100_p_2 += 34, x100_p_1 += 34, x100_p_0 += 34){
					// y = 4, x = 34, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h40, hp_0 = 0;
						h < h40 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 34, h = 1, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w40, wp_0 = 0;
							w < w40 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 34, h = 1, w = 1, c = 2, f = 64
							// T (x, 34) (34 / 1)
							for (x = x100, xp_3 = x100_p_2, xp_2 = x100_p_1, xp_1 = x100_p_0, xp_0 = 0;
								x < x100 + 34;
								x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
											c < c60 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_320);
											mem_vec_320 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_321);
											mem_vec_321 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_322);
											mem_vec_322 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_323);
											mem_vec_323 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_324);
											mem_vec_324 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_325);
											mem_vec_325 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_326);
											mem_vec_326 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_327);
											mem_vec_327 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_328);
											mem_vec_328 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_329);
											mem_vec_329 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_330);
											mem_vec_330 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_331);
											mem_vec_331 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_332);
											mem_vec_332 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_333);
											mem_vec_333 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_334);
											mem_vec_334 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_335);
											mem_vec_335 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_335);
							}
						}
					}
				}
			}
		}
	}
}


}