#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, c); T (17, x); T (1, y); T (136, y); T (8, x); T (1, y)]
*/
IND_TYPE c, cp_0, c171_p_0, cp_1, c171, h, hp_0, x, xp_0, x228_p_0, x229_p_0, xp_1, x228_p_1, xp_2, x228, x229, y, yp_0, y228_p_0, y229_p_0, yp_1, y228_p_1, yp_2, y228, y229;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y230 = 0;
IND_TYPE x230 = 0;
IND_TYPE h72 = 0;
IND_TYPE w = 0;
IND_TYPE c172 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 1) (272 / 272)
for (y229 = y230, y229_p_0 = 0;
	y229 < y230 + 272;
	y229 += 272, y229_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 8) (272 / 34)
	for (x229 = x230, x229_p_0 = 0;
		x229 < x230 + 272;
		x229 += 34, x229_p_0 += 34){
		// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (y, 136) (272 / 2)
		for (y228 = y229, y228_p_1 = y229_p_0, y228_p_0 = 0;
			y228 < y229 + 272;
			y228 += 2, y228_p_1 += 2, y228_p_0 += 2){
			// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (2 / 2)
			for (y = y228, yp_2 = y228_p_1, yp_1 = y228_p_0, yp_0 = 0;
				y < y228 + 2;
				y += 2, yp_2 += 2, yp_1 += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
				// T (x, 17) (34 / 2)
				for (x228 = x229, x228_p_1 = x229_p_0, x228_p_0 = 0;
					x228 < x229 + 34;
					x228 += 2, x228_p_1 += 2, x228_p_0 += 2){
					// y = 2, x = 2, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c171 = c172, c171_p_0 = 0;
						c171 < c172 + 32;
						c171 += 32, c171_p_0 += 32){
						// y = 2, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h72, hp_0 = 0;
							h < h72 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 2, h = 1, w = 3, c = 32, f = 64
							// T (x, 2) (2 / 1)
							for (x = x228, xp_2 = x228_p_1, xp_1 = x228_p_0, xp_0 = 0;
								x < x228 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c171, cp_1 = c171_p_0, cp_0 = 0;
											c < c171 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_456);
											mem_vec_456 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_457);
											mem_vec_457 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_458);
											mem_vec_458 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_459);
											mem_vec_459 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_460);
											mem_vec_460 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_461);
											mem_vec_461 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_462);
											mem_vec_462 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_463);
											mem_vec_463 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_456);
											mem_vec_456 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_457);
											mem_vec_457 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_458);
											mem_vec_458 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_459);
											mem_vec_459 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_460);
											mem_vec_460 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_461);
											mem_vec_461 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_462);
											mem_vec_462 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_463);
											mem_vec_463 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_456);
											mem_vec_456 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_457);
											mem_vec_457 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_458);
											mem_vec_458 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_459);
											mem_vec_459 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_460);
											mem_vec_460 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_461);
											mem_vec_461 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_462);
											mem_vec_462 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_463);
											mem_vec_463 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_463);
							}
						}
					}
				}
			}
		}
	}
}


}