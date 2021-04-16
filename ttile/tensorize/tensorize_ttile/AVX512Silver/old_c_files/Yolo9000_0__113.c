#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (1, x); T (544, x); T (2, y)]
*/
IND_TYPE c, cp_0, c3_p_0, cp_1, c3, h, hp_0, w, wp_0, x, xp_0, x4_p_0, x5_p_0, xp_1, x4_p_1, xp_2, x4, x5, y, yp_0, y3_p_0, yp_1, y3;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y4 = 0;
IND_TYPE x6 = 0;
IND_TYPE h2 = 0;
IND_TYPE w2 = 0;
IND_TYPE c4 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_30 ,mem_vec_31 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y3 = y4, y3_p_0 = 0;
	y3 < y4 + 544;
	y3 += 272, y3_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 544) (544 / 1)
	for (x5 = x6, x5_p_0 = 0;
		x5 < x6 + 544;
		x5 += 1, x5_p_0 += 1){
		// y = 272, x = 1, h = 3, w = 3, c = 3, f = 32
		// T (x, 1) (1 / 1)
		for (x4 = x5, x4_p_1 = x5_p_0, x4_p_0 = 0;
			x4 < x5 + 1;
			x4 += 1, x4_p_1 += 1, x4_p_0 += 1){
			// y = 272, x = 1, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (272 / 8)
			for (y = y3, yp_1 = y3_p_0, yp_0 = 0;
				y < y3 + 272;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h2, hp_0 = 0;
					h < h2 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w2, wp_0 = 0;
						w < w2 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c3 = c4, c3_p_0 = 0;
							c3 < c4 + 3;
							c3 += 3, c3_p_0 += 3){
							// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x4, xp_2 = x4_p_1, xp_1 = x4_p_0, xp_0 = 0;
								x < x4 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_16 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_17 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_18 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_19 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_20 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_21 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_22 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_23 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_24 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_25 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_26 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_27 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_28 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_29 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_30 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_31 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c3, cp_1 = c3_p_0, cp_0 = 0;
											c < c3 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16);
											mem_vec_16 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_17);
											mem_vec_17 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_18);
											mem_vec_18 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_19);
											mem_vec_19 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_20);
											mem_vec_20 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_21);
											mem_vec_21 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_22);
											mem_vec_22 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_23);
											mem_vec_23 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_24);
											mem_vec_24 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_25);
											mem_vec_25 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_26);
											mem_vec_26 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_27);
											mem_vec_27 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_28);
											mem_vec_28 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_29);
											mem_vec_29 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_30);
											mem_vec_30 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_31);
											mem_vec_31 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_17);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_18);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_19);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_20);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_21);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_22);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_23);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_24);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_25);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_26);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_27);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_28);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_29);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_30);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_31);
							}
						}
					}
				}
			}
		}
	}
}


}