#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (32, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (1, x); T (1, y); T (136, y); T (8, x); T (1, y)]
*/
IND_TYPE c, cp_0, c135_p_0, cp_1, c135, h, hp_0, x, xp_0, x180_p_0, x181_p_0, xp_1, x180_p_1, xp_2, x180, x181, y, yp_0, y180_p_0, y181_p_0, yp_1, y180_p_1, yp_2, y180, y181;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y182 = 0;
IND_TYPE x182 = 0;
IND_TYPE h48 = 0;
IND_TYPE w = 0;
IND_TYPE c136 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 1) (272 / 272)
for (y181 = y182, y181_p_0 = 0;
	y181 < y182 + 272;
	y181 += 272, y181_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 8) (272 / 34)
	for (x181 = x182, x181_p_0 = 0;
		x181 < x182 + 272;
		x181 += 34, x181_p_0 += 34){
		// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (y, 136) (272 / 2)
		for (y180 = y181, y180_p_1 = y181_p_0, y180_p_0 = 0;
			y180 < y181 + 272;
			y180 += 2, y180_p_1 += 2, y180_p_0 += 2){
			// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
			// T (y, 1) (2 / 2)
			for (y = y180, yp_2 = y180_p_1, yp_1 = y180_p_0, yp_0 = 0;
				y < y180 + 2;
				y += 2, yp_2 += 2, yp_1 += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
				// T (x, 1) (34 / 34)
				for (x180 = x181, x180_p_1 = x181_p_0, x180_p_0 = 0;
					x180 < x181 + 34;
					x180 += 34, x180_p_1 += 34, x180_p_0 += 34){
					// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c135 = c136, c135_p_0 = 0;
						c135 < c136 + 32;
						c135 += 32, c135_p_0 += 32){
						// y = 2, x = 34, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h48, hp_0 = 0;
							h < h48 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 34, h = 1, w = 3, c = 32, f = 64
							// T (x, 34) (34 / 1)
							for (x = x180, xp_2 = x180_p_1, xp_1 = x180_p_0, xp_0 = 0;
								x < x180 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c135, cp_1 = c135_p_0, cp_0 = 0;
											c < c135 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_360);
											mem_vec_360 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_361);
											mem_vec_361 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_362);
											mem_vec_362 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_363);
											mem_vec_363 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_364);
											mem_vec_364 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_365);
											mem_vec_365 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_366);
											mem_vec_366 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_367);
											mem_vec_367 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_360);
											mem_vec_360 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_361);
											mem_vec_361 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_362);
											mem_vec_362 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_363);
											mem_vec_363 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_364);
											mem_vec_364 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_365);
											mem_vec_365 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_366);
											mem_vec_366 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_367);
											mem_vec_367 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_360);
											mem_vec_360 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_361);
											mem_vec_361 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_362);
											mem_vec_362 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_363);
											mem_vec_363 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_364);
											mem_vec_364 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_365);
											mem_vec_365 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_366);
											mem_vec_366 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_367);
											mem_vec_367 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_367);
							}
						}
					}
				}
			}
		}
	}
}


}