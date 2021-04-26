#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (2, c); T (2, f); T (1, x); T (7, y); T (2, x)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y32 = 0;
IND_TYPE x66 = 0;
IND_TYPE h30 = 0;
IND_TYPE w27 = 0;
IND_TYPE c49 = 0;
IND_TYPE f23 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 2) (56 / 28)
for (x65 = x66, x65_p_0 = 0;
	x65 < x66 + 56;
	x65 += 28, x65_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 7) (56 / 8)
	for (y = y32, yp_0 = 0;
		y < y32 + 56;
		y += 8, yp_0 += 8){
		// y = 8, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (28 / 28)
		for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
			x64 < x65 + 28;
			x64 += 28, x64_p_1 += 28, x64_p_0 += 28){
			// y = 8, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f23, fp_0 = 0;
				f < f23 + 64;
				f += 32, fp_0 += 32){
				// y = 8, x = 28, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c48 = c49, c48_p_0 = 0;
					c48 < c49 + 64;
					c48 += 32, c48_p_0 += 32){
					// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w27, wp_0 = 0;
						w < w27 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 28, h = 3, w = 1, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
							x < x64 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 8, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h30, hp_0 = 0;
								h < h30 + 3;
								h += 1, hp_0 += 1){
										mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
											c < c48 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_448);
											mem_vec_448 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_449);
											mem_vec_449 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_450);
											mem_vec_450 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_451);
											mem_vec_451 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_452);
											mem_vec_452 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_453);
											mem_vec_453 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_454);
											mem_vec_454 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_455);
											mem_vec_455 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_456);
											mem_vec_456 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_457);
											mem_vec_457 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_458);
											mem_vec_458 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_459);
											mem_vec_459 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_460);
											mem_vec_460 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_461);
											mem_vec_461 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_462);
											mem_vec_462 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_463);
											mem_vec_463 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_449);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_450);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_451);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_463);
							}
						}
					}
				}
			}
		}
	}
}


}