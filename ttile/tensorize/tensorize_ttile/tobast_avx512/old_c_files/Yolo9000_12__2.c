#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, f); T (34, x); T (17, y); T (8, f); T (32, c); T (1, f)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, f24_p_0, f25_p_0, fp_1, f24_p_1, fp_2, f24, f25, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f25 = f26, f25_p_0 = 0;
	f25 < f26 + 512;
	f25 += 512, f25_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 32) (256 / 8)
	for (c18 = c19, c18_p_0 = 0;
		c18 < c19 + 256;
		c18 += 8, c18_p_0 += 8){
		// y = 34, x = 34, h = 3, w = 3, c = 8, f = 512
		// T (f, 8) (512 / 64)
		for (f24 = f25, f24_p_1 = f25_p_0, f24_p_0 = 0;
			f24 < f25 + 512;
			f24 += 64, f24_p_1 += 64, f24_p_0 += 64){
			// y = 34, x = 34, h = 3, w = 3, c = 8, f = 64
			// T (y, 17) (34 / 2)
			for (y = y12, yp_0 = 0;
				y < y12 + 34;
				y += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 8, f = 64
				// T (x, 34) (34 / 1)
				for (x18 = x19, x18_p_0 = 0;
					x18 < x19 + 34;
					x18 += 1, x18_p_0 += 1){
					// y = 2, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (f, 1) (64 / 64)
					for (f = f24, fp_2 = f24_p_1, fp_1 = f24_p_0, fp_0 = 0;
						f < f24 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 2, x = 1, h = 3, w = 3, c = 8, f = 64
						// T (w, 3) (3 / 1)
						for (w = w12, wp_0 = 0;
							w < w12 + 3;
							w += 1, wp_0 += 1){
							// y = 2, x = 1, h = 3, w = 1, c = 8, f = 64
							// T (x, 1) (1 / 1)
							for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
								x < x18 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_48 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_49 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_50 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_51 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_52 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_53 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_54 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_55 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 3, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
											c < c18 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_48);
											mem_vec_48 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_49);
											mem_vec_49 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_50);
											mem_vec_50 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_51);
											mem_vec_51 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_52);
											mem_vec_52 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_53);
											mem_vec_53 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_54);
											mem_vec_54 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_55);
											mem_vec_55 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_48);
											mem_vec_48 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_49);
											mem_vec_49 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_50);
											mem_vec_50 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_51);
											mem_vec_51 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_52);
											mem_vec_52 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_53);
											mem_vec_53 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_54);
											mem_vec_54 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_55);
											mem_vec_55 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_48);
											mem_vec_48 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_49);
											mem_vec_49 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_50);
											mem_vec_50 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_51);
											mem_vec_51 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_52);
											mem_vec_52 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_53);
											mem_vec_53 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_54);
											mem_vec_54 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_55);
											mem_vec_55 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_48);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_49);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_50);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_51);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_52);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_53);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_54);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_55);
							}
						}
					}
				}
			}
		}
	}
}


}