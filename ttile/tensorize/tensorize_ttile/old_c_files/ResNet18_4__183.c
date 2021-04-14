#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (8, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, f); T (8, c); T (4, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f48_p_0, fp_1, f48, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y32 = 0;
IND_TYPE x49 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f49 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f48 = f49, f48_p_0 = 0;
	f48 < f49 + 128;
	f48 += 64, f48_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 2) (28 / 14)
	for (y = y32, yp_0 = 0;
		y < y32 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (x, 4) (28 / 7)
		for (x48 = x49, x48_p_0 = 0;
			x48 < x49 + 28;
			x48 += 7, x48_p_0 += 7){
			// y = 14, x = 7, h = 3, w = 3, c = 64, f = 64
			// T (c, 8) (64 / 8)
			for (c48 = c49, c48_p_0 = 0;
				c48 < c49 + 64;
				c48 += 8, c48_p_0 += 8){
				// y = 14, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (f, 2) (64 / 32)
				for (f = f48, fp_1 = f48_p_0, fp_0 = 0;
					f < f48 + 64;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 7, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h32, hp_0 = 0;
						h < h32 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 7, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w32, wp_0 = 0;
							w < w32 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 7, h = 1, w = 1, c = 8, f = 32
							// T (x, 7) (7 / 1)
							for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
								x < x48 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
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
										mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
											c < c48 + 8;
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
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_464);
											mem_vec_464 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_465);
											mem_vec_465 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_466);
											mem_vec_466 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_467);
											mem_vec_467 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_468);
											mem_vec_468 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_469);
											mem_vec_469 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_470);
											mem_vec_470 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_471);
											mem_vec_471 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_472);
											mem_vec_472 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_473);
											mem_vec_473 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_474);
											mem_vec_474 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_475);
											mem_vec_475 = vec_43;
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
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_475);
							}
						}
					}
				}
			}
		}
	}
}


}