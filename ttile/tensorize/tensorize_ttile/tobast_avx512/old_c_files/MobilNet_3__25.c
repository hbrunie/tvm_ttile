#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (128, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, x); T (8, y); T (2, f); T (1, c); T (4, x)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y40 = 0;
IND_TYPE x82 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
for (x81 = x82, x81_p_0 = 0;
	x81 < x82 + 56;
	x81 += 14, x81_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 1) (128 / 128)
	for (c60 = c61, c60_p_0 = 0;
		c60 < c61 + 128;
		c60 += 128, c60_p_0 += 128){
		// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
		// T (f, 2) (128 / 64)
		for (f = f40, fp_0 = 0;
			f < f40 + 128;
			f += 64, fp_0 += 64){
			// y = 56, x = 14, h = 3, w = 3, c = 128, f = 64
			// T (y, 8) (56 / 7)
			for (y = y40, yp_0 = 0;
				y < y40 + 56;
				y += 7, yp_0 += 7){
				// y = 7, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (x, 1) (14 / 14)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 14;
					x80 += 14, x80_p_1 += 14, x80_p_0 += 14){
					// y = 7, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (h, 3) (3 / 1)
					for (h = h40, hp_0 = 0;
						h < h40 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 14, h = 1, w = 3, c = 128, f = 64
						// T (w, 3) (3 / 1)
						for (w = w40, wp_0 = 0;
							w < w40 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 1, w = 1, c = 128, f = 64
							// T (x, 14) (14 / 1)
							for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
								x < x80 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
											c < c60 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_436);
											mem_vec_436 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_437);
											mem_vec_437 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_438);
											mem_vec_438 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_439);
											mem_vec_439 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_440);
											mem_vec_440 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_441);
											mem_vec_441 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_442);
											mem_vec_442 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_443);
											mem_vec_443 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_444);
											mem_vec_444 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_445);
											mem_vec_445 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_446);
											mem_vec_446 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_447);
											mem_vec_447 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_448);
											mem_vec_448 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_449);
											mem_vec_449 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_450);
											mem_vec_450 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_451);
											mem_vec_451 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_452);
											mem_vec_452 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_453);
											mem_vec_453 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_454);
											mem_vec_454 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_455);
											mem_vec_455 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_456);
											mem_vec_456 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_457);
											mem_vec_457 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_458);
											mem_vec_458 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_459);
											mem_vec_459 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_460);
											mem_vec_460 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_461);
											mem_vec_461 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_462);
											mem_vec_462 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_463);
											mem_vec_463 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_436);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_437);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_438);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_439);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_440);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_441);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_442);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_443);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_444);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_445);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_446);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_447);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_449);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_450);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_451);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_463);
							}
						}
					}
				}
			}
		}
	}
}


}