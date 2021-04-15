#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (34, y); T (1, f); T (4, c); T (1, f); T (34, x); T (4, f)]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, f144_p_0, f145_p_0, fp_1, f144_p_1, fp_2, f144, f145, h, hp_0, x, xp_0, x126_p_0, xp_1, x126, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y72 = 0;
IND_TYPE x127 = 0;
IND_TYPE h66 = 0;
IND_TYPE w = 0;
IND_TYPE c109 = 0;
IND_TYPE f146 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f145 = f146, f145_p_0 = 0;
	f145 < f146 + 256;
	f145 += 64, f145_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 34) (68 / 2)
	for (x126 = x127, x126_p_0 = 0;
		x126 < x127 + 68;
		x126 += 2, x126_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f144 = f145, f144_p_1 = f145_p_0, f144_p_0 = 0;
			f144 < f145 + 64;
			f144 += 64, f144_p_1 += 64, f144_p_0 += 64){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
			// T (c, 4) (128 / 32)
			for (c108 = c109, c108_p_0 = 0;
				c108 < c109 + 128;
				c108 += 32, c108_p_0 += 32){
				// y = 68, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (f, 1) (64 / 64)
				for (f = f144, fp_2 = f144_p_1, fp_1 = f144_p_0, fp_0 = 0;
					f < f144 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 68, x = 2, h = 3, w = 3, c = 32, f = 64
					// T (y, 34) (68 / 2)
					for (y = y72, yp_0 = 0;
						y < y72 + 68;
						y += 2, yp_0 += 2){
						// y = 2, x = 2, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h66, hp_0 = 0;
							h < h66 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 2, h = 1, w = 3, c = 32, f = 64
							// T (x, 2) (2 / 1)
							for (x = x126, xp_1 = x126_p_0, xp_0 = 0;
								x < x126 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c108, cp_1 = c108_p_0, cp_0 = 0;
											c < c108 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_480);
											mem_vec_480 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_481);
											mem_vec_481 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_482);
											mem_vec_482 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_483);
											mem_vec_483 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_484);
											mem_vec_484 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_485);
											mem_vec_485 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_486);
											mem_vec_486 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_487);
											mem_vec_487 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_480);
											mem_vec_480 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_481);
											mem_vec_481 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_482);
											mem_vec_482 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_483);
											mem_vec_483 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_484);
											mem_vec_484 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_485);
											mem_vec_485 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_486);
											mem_vec_486 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_487);
											mem_vec_487 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_480);
											mem_vec_480 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_481);
											mem_vec_481 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_482);
											mem_vec_482 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_483);
											mem_vec_483 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_484);
											mem_vec_484 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_485);
											mem_vec_485 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_486);
											mem_vec_486 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_487);
											mem_vec_487 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_487);
							}
						}
					}
				}
			}
		}
	}
}


}