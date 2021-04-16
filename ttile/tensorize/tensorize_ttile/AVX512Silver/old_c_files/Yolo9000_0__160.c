#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (3, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (1, x); T (2, y); T (34, y); T (544, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, h, hp_0, x, xp_0, x48_p_0, x49_p_0, xp_1, x48_p_1, xp_2, x48, x49, y, yp_0, y44_p_0, y45_p_0, yp_1, y44_p_1, yp_2, y44, y45;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y46 = 0;
IND_TYPE x50 = 0;
IND_TYPE h18 = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y45 = y46, y45_p_0 = 0;
	y45 < y46 + 544;
	y45 += 272, y45_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 544) (544 / 1)
	for (x49 = x50, x49_p_0 = 0;
		x49 < x50 + 544;
		x49 += 1, x49_p_0 += 1){
		// y = 272, x = 1, h = 3, w = 3, c = 3, f = 32
		// T (y, 34) (272 / 8)
		for (y44 = y45, y44_p_1 = y45_p_0, y44_p_0 = 0;
			y44 < y45 + 272;
			y44 += 8, y44_p_1 += 8, y44_p_0 += 8){
			// y = 8, x = 1, h = 3, w = 3, c = 3, f = 32
			// T (y, 2) (8 / 4)
			for (y = y44, yp_2 = y44_p_1, yp_1 = y44_p_0, yp_0 = 0;
				y < y44 + 8;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (x, 1) (1 / 1)
				for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
					x48 < x49 + 1;
					x48 += 1, x48_p_1 += 1, x48_p_0 += 1){
					// y = 4, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (f, 2) (32 / 16)
					for (f = f20, fp_0 = 0;
						f < f20 + 32;
						f += 16, fp_0 += 16){
						// y = 4, x = 1, h = 3, w = 3, c = 3, f = 16
						// T (h, 3) (3 / 1)
						for (h = h18, hp_0 = 0;
							h < h18 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 1, h = 1, w = 3, c = 3, f = 16
							// T (x, 1) (1 / 1)
							for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
								x < x48 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										// y = 4, x = 1, h = 1, w = 3, c = 3, f = 16
										// T (c, 3) (3 / 1)
										for (c = c28, cp_0 = 0;
											c < c28 + 3;
											c += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_112);
											mem_vec_112 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_113);
											mem_vec_113 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_114);
											mem_vec_114 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_115);
											mem_vec_115 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_112);
											mem_vec_112 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_13 = _mm512_set1_ps(scal_5);


											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_113);
											mem_vec_113 = vec_12;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_114);
											mem_vec_114 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_115);
											mem_vec_115 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_112);
											mem_vec_112 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_22 = _mm512_set1_ps(scal_9);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_113);
											mem_vec_113 = vec_21;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_24 = _mm512_set1_ps(scal_10);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_114);
											mem_vec_114 = vec_23;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_115);
											mem_vec_115 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_112);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_113);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_114);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_115);
							}
						}
					}
				}
			}
		}
	}
}


}