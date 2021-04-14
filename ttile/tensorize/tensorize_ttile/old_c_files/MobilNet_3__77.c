#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (1, x); T (7, y); T (4, f); T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x8_p_0, x9_p_0, xp_1, x8_p_1, xp_2, x8, x9, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y4 = 0;
IND_TYPE x10 = 0;
IND_TYPE h4 = 0;
IND_TYPE w4 = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (56 / 28)
for (x9 = x10, x9_p_0 = 0;
	x9 < x10 + 56;
	x9 += 28, x9_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (c, 4) (128 / 32)
	for (c6 = c7, c6_p_0 = 0;
		c6 < c7 + 128;
		c6 += 32, c6_p_0 += 32){
		// y = 56, x = 28, h = 3, w = 3, c = 32, f = 128
		// T (f, 4) (128 / 32)
		for (f = f4, fp_0 = 0;
			f < f4 + 128;
			f += 32, fp_0 += 32){
			// y = 56, x = 28, h = 3, w = 3, c = 32, f = 32
			// T (y, 7) (56 / 8)
			for (y = y4, yp_0 = 0;
				y < y4 + 56;
				y += 8, yp_0 += 8){
				// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (28 / 28)
				for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;
					x8 < x9 + 28;
					x8 += 28, x8_p_1 += 28, x8_p_0 += 28){
					// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h4, hp_0 = 0;
						h < h4 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 28, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w4, wp_0 = 0;
							w < w4 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 28, h = 1, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;
								x < x8 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_32 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_33 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_40 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_41 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_42 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_43 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_44 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_45 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_46 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_47 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
											c < c6 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_32);
											mem_vec_32 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_33);
											mem_vec_33 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_34);
											mem_vec_34 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_35);
											mem_vec_35 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_36);
											mem_vec_36 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_37);
											mem_vec_37 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_38);
											mem_vec_38 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_39);
											mem_vec_39 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_40);
											mem_vec_40 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_41);
											mem_vec_41 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_42);
											mem_vec_42 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_43);
											mem_vec_43 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_44);
											mem_vec_44 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_45);
											mem_vec_45 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_46);
											mem_vec_46 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_47);
											mem_vec_47 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_32);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_33);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_34);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_35);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_36);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_37);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_38);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_39);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_40);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_41);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_42);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_43);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_44);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_45);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_46);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_47);
							}
						}
					}
				}
			}
		}
	}
}


}