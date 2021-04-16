#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (56, x);
  T (3, w); T (8, c); T (4, f); T (1, x); T (8, y); T (1, x)]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x59_p_0, x60_p_0, xp_1, x59_p_1, xp_2, x59, x60, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y42 = 0;
IND_TYPE x61 = 0;
IND_TYPE h26 = 0;
IND_TYPE w28 = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (56 / 56)
for (x60 = x61, x60_p_0 = 0;
	x60 < x61 + 56;
	x60 += 56, x60_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (y, 8) (56 / 7)
	for (y = y42, yp_0 = 0;
		y < y42 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (56 / 56)
		for (x59 = x60, x59_p_1 = x60_p_0, x59_p_0 = 0;
			x59 < x60 + 56;
			x59 += 56, x59_p_1 += 56, x59_p_0 += 56){
			// y = 7, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f34, fp_0 = 0;
				f < f34 + 128;
				f += 32, fp_0 += 32){
				// y = 7, x = 56, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c51 = c52, c51_p_0 = 0;
					c51 < c52 + 128;
					c51 += 16, c51_p_0 += 16){
					// y = 7, x = 56, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w28, wp_0 = 0;
						w < w28 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 56, h = 3, w = 1, c = 16, f = 32
						// T (x, 56) (56 / 1)
						for (x = x59, xp_2 = x59_p_1, xp_1 = x59_p_0, xp_0 = 0;
							x < x59 + 56;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h26, hp_0 = 0;
								h < h26 + 3;
								h += 1, hp_0 += 1){
										mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
											c < c51 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_332);
											mem_vec_332 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_333);
											mem_vec_333 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_334);
											mem_vec_334 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_335);
											mem_vec_335 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_336);
											mem_vec_336 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_337);
											mem_vec_337 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_338);
											mem_vec_338 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_339);
											mem_vec_339 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_340);
											mem_vec_340 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_341);
											mem_vec_341 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_342);
											mem_vec_342 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_343);
											mem_vec_343 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_344);
											mem_vec_344 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_345);
											mem_vec_345 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_335);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_345);
							}
						}
					}
				}
			}
		}
	}
}


}