#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, c); T (1, x); T (1, y); T (34, y); T (272, x); T (4, y)]
*/
IND_TYPE c, cp_0, c393_p_0, cp_1, c393, h, hp_0, x, xp_0, x524_p_0, x525_p_0, xp_1, x524_p_1, xp_2, x524, x525, y, yp_0, y518_p_0, y519_p_0, yp_1, y518_p_1, yp_2, y518, y519;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y520 = 0;
IND_TYPE x526 = 0;
IND_TYPE h202 = 0;
IND_TYPE w = 0;
IND_TYPE c394 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1120 ,mem_vec_1121 ,mem_vec_1122 ,mem_vec_1123 ,mem_vec_1124 ,mem_vec_1125 ,mem_vec_1126 ,mem_vec_1127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 4) (272 / 68)
for (y519 = y520, y519_p_0 = 0;
	y519 < y520 + 272;
	y519 += 68, y519_p_0 += 68){
	// y = 68, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x525 = x526, x525_p_0 = 0;
		x525 < x526 + 272;
		x525 += 1, x525_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 32, f = 64
		// T (y, 34) (68 / 2)
		for (y518 = y519, y518_p_1 = y519_p_0, y518_p_0 = 0;
			y518 < y519 + 68;
			y518 += 2, y518_p_1 += 2, y518_p_0 += 2){
			// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (2 / 2)
			for (y = y518, yp_2 = y518_p_1, yp_1 = y518_p_0, yp_0 = 0;
				y < y518 + 2;
				y += 2, yp_2 += 2, yp_1 += 2, yp_0 += 2){
				// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (1 / 1)
				for (x524 = x525, x524_p_1 = x525_p_0, x524_p_0 = 0;
					x524 < x525 + 1;
					x524 += 1, x524_p_1 += 1, x524_p_0 += 1){
					// y = 2, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 4) (32 / 8)
					for (c393 = c394, c393_p_0 = 0;
						c393 < c394 + 32;
						c393 += 8, c393_p_0 += 8){
						// y = 2, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h202, hp_0 = 0;
							h < h202 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 1, h = 1, w = 3, c = 8, f = 64
							// T (x, 1) (1 / 1)
							for (x = x524, xp_2 = x524_p_1, xp_1 = x524_p_0, xp_0 = 0;
								x < x524 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c393, cp_1 = c393_p_0, cp_0 = 0;
											c < c393 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1120);
											mem_vec_1120 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1121);
											mem_vec_1121 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1122);
											mem_vec_1122 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1123);
											mem_vec_1123 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1124);
											mem_vec_1124 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1125);
											mem_vec_1125 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1126);
											mem_vec_1126 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1127);
											mem_vec_1127 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1120);
											mem_vec_1120 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1121);
											mem_vec_1121 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_1122);
											mem_vec_1122 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_1123);
											mem_vec_1123 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_1124);
											mem_vec_1124 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_1125);
											mem_vec_1125 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1126);
											mem_vec_1126 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_1127);
											mem_vec_1127 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1120);
											mem_vec_1120 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1121);
											mem_vec_1121 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_1122);
											mem_vec_1122 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_1123);
											mem_vec_1123 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1124);
											mem_vec_1124 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1125);
											mem_vec_1125 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_1126);
											mem_vec_1126 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_1127);
											mem_vec_1127 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1127);
							}
						}
					}
				}
			}
		}
	}
}


}