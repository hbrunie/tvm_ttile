#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (4, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (17, x); T (68, y); T (2, f); T (8, c); T (2, x); T (2, x)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, f, fp_0, h, hp_0, x, xp_0, x648_p_0, x649_p_0, x650_p_0, xp_1, x648_p_1, x649_p_1, xp_2, x648_p_2, xp_3, x648, x649, x650, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y276 = 0;
IND_TYPE x651 = 0;
IND_TYPE h180 = 0;
IND_TYPE w = 0;
IND_TYPE c385 = 0;
IND_TYPE f206 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1568 ,mem_vec_1569 ,mem_vec_1570 ,mem_vec_1571 ,mem_vec_1572 ,mem_vec_1573 ,mem_vec_1574 ,mem_vec_1575 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x650 = x651, x650_p_0 = 0;
	x650 < x651 + 272;
	x650 += 136, x650_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (136 / 68)
	for (x649 = x650, x649_p_1 = x650_p_0, x649_p_0 = 0;
		x649 < x650 + 136;
		x649 += 68, x649_p_1 += 68, x649_p_0 += 68){
		// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c384 = c385, c384_p_0 = 0;
			c384 < c385 + 32;
			c384 += 4, c384_p_0 += 4){
			// y = 272, x = 68, h = 3, w = 3, c = 4, f = 64
			// T (f, 2) (64 / 32)
			for (f = f206, fp_0 = 0;
				f < f206 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 68, h = 3, w = 3, c = 4, f = 32
				// T (y, 68) (272 / 4)
				for (y = y276, yp_0 = 0;
					y < y276 + 272;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 4, f = 32
					// T (x, 17) (68 / 4)
					for (x648 = x649, x648_p_2 = x649_p_1, x648_p_1 = x649_p_0, x648_p_0 = 0;
						x648 < x649 + 68;
						x648 += 4, x648_p_2 += 4, x648_p_1 += 4, x648_p_0 += 4){
						// y = 4, x = 4, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h180, hp_0 = 0;
							h < h180 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 4, h = 1, w = 3, c = 4, f = 32
							// T (x, 4) (4 / 1)
							for (x = x648, xp_3 = x648_p_2, xp_2 = x648_p_1, xp_1 = x648_p_0, xp_0 = 0;
								x < x648 + 4;
								x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1568 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1569 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										// y = 4, x = 1, h = 1, w = 3, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
											c < c384 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1568);
											mem_vec_1568 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1569);
											mem_vec_1569 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1570);
											mem_vec_1570 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1571);
											mem_vec_1571 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1572);
											mem_vec_1572 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1573);
											mem_vec_1573 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1574);
											mem_vec_1574 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1575);
											mem_vec_1575 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1568);
											mem_vec_1568 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1569);
											mem_vec_1569 = vec_17;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_20 = _mm512_set1_ps(scal_5);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_1570);
											mem_vec_1570 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_1571);
											mem_vec_1571 = vec_21;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_1572);
											mem_vec_1572 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_1573);
											mem_vec_1573 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_1574);
											mem_vec_1574 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_1575);
											mem_vec_1575 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1568);
											mem_vec_1568 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1569);
											mem_vec_1569 = vec_31;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_9);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_1570);
											mem_vec_1570 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1571);
											mem_vec_1571 = vec_35;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_37 = _mm512_set1_ps(scal_10);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_1572);
											mem_vec_1572 = vec_36;



											vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_1573);
											mem_vec_1573 = vec_38;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_1574);
											mem_vec_1574 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_1575);
											mem_vec_1575 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1575);
							}
						}
					}
				}
			}
		}
	}
}


}