#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (68, x);
  T (3, h); T (8, c); T (1, f); T (17, y); T (1, x); T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c378_p_0, cp_1, c378, f, fp_0, f504_p_0, f505_p_0, fp_1, f504_p_1, fp_2, f504, f505, h, hp_0, x, xp_0, x378_p_0, xp_1, x378, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y252 = 0;
IND_TYPE x379 = 0;
IND_TYPE h186 = 0;
IND_TYPE w = 0;
IND_TYPE c379 = 0;
IND_TYPE f506 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5228 ,mem_vec_5229 ,mem_vec_5230 ,mem_vec_5231 ,mem_vec_5232 ,mem_vec_5233 ,mem_vec_5234 ,mem_vec_5235 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f505 = f506, f505_p_0 = 0;
	f505 < f506 + 256;
	f505 += 256, f505_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f504 = f505, f504_p_1 = f505_p_0, f504_p_0 = 0;
		f504 < f505 + 256;
		f504 += 32, f504_p_1 += 32, f504_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 1) (68 / 68)
		for (x378 = x379, x378_p_0 = 0;
			x378 < x379 + 68;
			x378 += 68, x378_p_0 += 68){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (y, 17) (68 / 4)
			for (y = y252, yp_0 = 0;
				y < y252 + 68;
				y += 4, yp_0 += 4){
				// y = 4, x = 68, h = 3, w = 3, c = 128, f = 32
				// T (f, 1) (32 / 32)
				for (f = f504, fp_2 = f504_p_1, fp_1 = f504_p_0, fp_0 = 0;
					f < f504 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c378 = c379, c378_p_0 = 0;
						c378 < c379 + 128;
						c378 += 16, c378_p_0 += 16){
						// y = 4, x = 68, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h186, hp_0 = 0;
							h < h186 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 16, f = 32
							// T (x, 68) (68 / 1)
							for (x = x378, xp_1 = x378_p_0, xp_0 = 0;
								x < x378 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5228 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5229 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c378, cp_1 = c378_p_0, cp_0 = 0;
											c < c378 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5228);
											mem_vec_5228 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5229);
											mem_vec_5229 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5230);
											mem_vec_5230 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5231);
											mem_vec_5231 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5232);
											mem_vec_5232 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5233);
											mem_vec_5233 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5234);
											mem_vec_5234 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5235);
											mem_vec_5235 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_5228);
											mem_vec_5228 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_5229);
											mem_vec_5229 = vec_17;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_20 = _mm512_set1_ps(scal_5);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_5230);
											mem_vec_5230 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_5231);
											mem_vec_5231 = vec_21;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_5232);
											mem_vec_5232 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_5233);
											mem_vec_5233 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_5234);
											mem_vec_5234 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_5235);
											mem_vec_5235 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_5228);
											mem_vec_5228 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_5229);
											mem_vec_5229 = vec_31;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_9);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5230);
											mem_vec_5230 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5231);
											mem_vec_5231 = vec_35;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_37 = _mm512_set1_ps(scal_10);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_5232);
											mem_vec_5232 = vec_36;



											vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_5233);
											mem_vec_5233 = vec_38;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_5234);
											mem_vec_5234 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_5235);
											mem_vec_5235 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5231);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5235);
							}
						}
					}
				}
			}
		}
	}
}


}