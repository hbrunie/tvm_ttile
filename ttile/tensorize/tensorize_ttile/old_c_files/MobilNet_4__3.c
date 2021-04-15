#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (8, c); T (2, f); T (2, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, f39_p_0, fp_1, f39, h, hp_0, w, wp_0, x, xp_0, x39_p_0, xp_1, x39, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y26 = 0;
IND_TYPE x40 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c40 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f39 = f40, f39_p_0 = 0;
	f39 < f40 + 128;
	f39 += 64, f39_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 2) (28 / 14)
	for (y = y26, yp_0 = 0;
		y < y26 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (28 / 14)
		for (x39 = x40, x39_p_0 = 0;
			x39 < x40 + 28;
			x39 += 14, x39_p_0 += 14){
			// y = 14, x = 14, h = 3, w = 3, c = 128, f = 64
			// T (f, 2) (64 / 32)
			for (f = f39, fp_1 = f39_p_0, fp_0 = 0;
				f < f39 + 64;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c39 = c40, c39_p_0 = 0;
					c39 < c40 + 128;
					c39 += 16, c39_p_0 += 16){
					// y = 14, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w24, wp_0 = 0;
						w < w24 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 14, h = 3, w = 1, c = 16, f = 32
						// T (x, 14) (14 / 1)
						for (x = x39, xp_1 = x39_p_0, xp_0 = 0;
							x < x39 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h24, hp_0 = 0;
								h < h24 + 3;
								h += 1, hp_0 += 1){
										mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
											c < c39 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_364);
											mem_vec_364 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_365);
											mem_vec_365 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_366);
											mem_vec_366 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_367);
											mem_vec_367 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_368);
											mem_vec_368 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_369);
											mem_vec_369 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_370);
											mem_vec_370 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_371);
											mem_vec_371 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_372);
											mem_vec_372 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_373);
											mem_vec_373 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_374);
											mem_vec_374 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_375);
											mem_vec_375 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_376);
											mem_vec_376 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_377);
											mem_vec_377 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_378);
											mem_vec_378 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_379);
											mem_vec_379 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_380);
											mem_vec_380 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_381);
											mem_vec_381 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_382);
											mem_vec_382 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_383);
											mem_vec_383 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_384);
											mem_vec_384 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_385);
											mem_vec_385 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_386);
											mem_vec_386 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_387);
											mem_vec_387 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_388);
											mem_vec_388 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_389);
											mem_vec_389 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_390);
											mem_vec_390 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_391);
											mem_vec_391 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_391);
							}
						}
					}
				}
			}
		}
	}
}


}