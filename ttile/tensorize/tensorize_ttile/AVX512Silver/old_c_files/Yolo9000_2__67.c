#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, c); T (1, x); T (17, y); T (1, y); T (272, x); T (8, y)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, h, hp_0, x, xp_0, x312_p_0, x313_p_0, xp_1, x312_p_1, xp_2, x312, x313, y, yp_0, y312_p_0, y313_p_0, yp_1, y312_p_1, yp_2, y312, y313;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y314 = 0;
IND_TYPE x314 = 0;
IND_TYPE h114 = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 8) (272 / 34)
for (y313 = y314, y313_p_0 = 0;
	y313 < y314 + 272;
	y313 += 34, y313_p_0 += 34){
	// y = 34, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x313 = x314, x313_p_0 = 0;
		x313 < x314 + 272;
		x313 += 1, x313_p_0 += 1){
		// y = 34, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 1) (34 / 34)
		for (y312 = y313, y312_p_1 = y313_p_0, y312_p_0 = 0;
			y312 < y313 + 34;
			y312 += 34, y312_p_1 += 34, y312_p_0 += 34){
			// y = 34, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 17) (34 / 2)
			for (y = y312, yp_2 = y312_p_1, yp_1 = y312_p_0, yp_0 = 0;
				y < y312 + 34;
				y += 2, yp_2 += 2, yp_1 += 2, yp_0 += 2){
				// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x312 = x313, x312_p_1 = x313_p_0, x312_p_0 = 0;
					x312 < x313 + 1;
					x312 += 1, x312_p_1 += 1, x312_p_0 += 1){
					// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c234 = c235, c234_p_0 = 0;
						c234 < c235 + 32;
						c234 += 32, c234_p_0 += 32){
						// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h114, hp_0 = 0;
							h < h114 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 1, h = 1, w = 3, c = 32, f = 64
							// T (x, 1) (1 / 1)
							for (x = x312, xp_2 = x312_p_1, xp_1 = x312_p_0, xp_0 = 0;
								x < x312 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
											c < c234 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_624);
											mem_vec_624 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_625);
											mem_vec_625 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_626);
											mem_vec_626 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_627);
											mem_vec_627 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_628);
											mem_vec_628 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_629);
											mem_vec_629 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_630);
											mem_vec_630 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_631);
											mem_vec_631 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_624);
											mem_vec_624 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_625);
											mem_vec_625 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_626);
											mem_vec_626 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_627);
											mem_vec_627 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_628);
											mem_vec_628 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_629);
											mem_vec_629 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_630);
											mem_vec_630 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_631);
											mem_vec_631 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_624);
											mem_vec_624 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_625);
											mem_vec_625 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_626);
											mem_vec_626 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_627);
											mem_vec_627 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_628);
											mem_vec_628 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_629);
											mem_vec_629 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_630);
											mem_vec_630 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_631);
											mem_vec_631 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_624);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_631);
							}
						}
					}
				}
			}
		}
	}
}


}