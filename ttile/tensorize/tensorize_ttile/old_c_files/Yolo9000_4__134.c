#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, x); T (17, y); T (4, f); T (64, c); T (136, x)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x88_p_0, x89_p_0, xp_1, x88_p_1, xp_2, x88, x89, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y44 = 0;
IND_TYPE x90 = 0;
IND_TYPE h44 = 0;
IND_TYPE w44 = 0;
IND_TYPE c67 = 0;
IND_TYPE f44 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 136) (136 / 1)
for (x89 = x90, x89_p_0 = 0;
	x89 < x90 + 136;
	x89 += 1, x89_p_0 += 1){
	// y = 136, x = 1, h = 3, w = 3, c = 64, f = 128
	// T (c, 64) (64 / 1)
	for (c66 = c67, c66_p_0 = 0;
		c66 < c67 + 64;
		c66 += 1, c66_p_0 += 1){
		// y = 136, x = 1, h = 3, w = 3, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f44, fp_0 = 0;
			f < f44 + 128;
			f += 32, fp_0 += 32){
			// y = 136, x = 1, h = 3, w = 3, c = 1, f = 32
			// T (y, 17) (136 / 8)
			for (y = y44, yp_0 = 0;
				y < y44 + 136;
				y += 8, yp_0 += 8){
				// y = 8, x = 1, h = 3, w = 3, c = 1, f = 32
				// T (x, 1) (1 / 1)
				for (x88 = x89, x88_p_1 = x89_p_0, x88_p_0 = 0;
					x88 < x89 + 1;
					x88 += 1, x88_p_1 += 1, x88_p_0 += 1){
					// y = 8, x = 1, h = 3, w = 3, c = 1, f = 32
					// T (h, 3) (3 / 1)
					for (h = h44, hp_0 = 0;
						h < h44 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 1, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w44, wp_0 = 0;
							w < w44 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 1, f = 32
							// T (x, 1) (1 / 1)
							for (x = x88, xp_2 = x88_p_1, xp_1 = x88_p_0, xp_0 = 0;
								x < x88 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
											c < c66 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_352);
											mem_vec_352 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_353);
											mem_vec_353 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_354);
											mem_vec_354 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_355);
											mem_vec_355 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_356);
											mem_vec_356 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_357);
											mem_vec_357 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_358);
											mem_vec_358 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_359);
											mem_vec_359 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_360);
											mem_vec_360 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_361);
											mem_vec_361 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_362);
											mem_vec_362 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_363);
											mem_vec_363 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_364);
											mem_vec_364 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_365);
											mem_vec_365 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_366);
											mem_vec_366 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_367);
											mem_vec_367 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_356);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_367);
							}
						}
					}
				}
			}
		}
	}
}


}