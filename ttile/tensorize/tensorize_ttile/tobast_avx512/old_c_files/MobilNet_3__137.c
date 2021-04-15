#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (14, y); T (2, f); T (16, c); T (2, f); T (2, x); T (2, f)]
*/
IND_TYPE c, cp_0, c234_p_0, cp_1, c234, f, fp_0, f248_p_0, f249_p_0, fp_1, f248_p_1, fp_2, f248, f249, h, hp_0, x, xp_0, x266_p_0, xp_1, x266, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y156 = 0;
IND_TYPE x267 = 0;
IND_TYPE h100 = 0;
IND_TYPE w = 0;
IND_TYPE c235 = 0;
IND_TYPE f250 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1162 ,mem_vec_1163 ,mem_vec_1164 ,mem_vec_1165 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f249 = f250, f249_p_0 = 0;
	f249 < f250 + 128;
	f249 += 64, f249_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (x, 2) (56 / 28)
	for (x266 = x267, x266_p_0 = 0;
		x266 < x267 + 56;
		x266 += 28, x266_p_0 += 28){
		// y = 56, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f248 = f249, f248_p_1 = f249_p_0, f248_p_0 = 0;
			f248 < f249 + 64;
			f248 += 32, f248_p_1 += 32, f248_p_0 += 32){
			// y = 56, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (c, 16) (128 / 8)
			for (c234 = c235, c234_p_0 = 0;
				c234 < c235 + 128;
				c234 += 8, c234_p_0 += 8){
				// y = 56, x = 28, h = 3, w = 3, c = 8, f = 32
				// T (f, 2) (32 / 16)
				for (f = f248, fp_2 = f248_p_1, fp_1 = f248_p_0, fp_0 = 0;
					f < f248 + 32;
					f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
					// y = 56, x = 28, h = 3, w = 3, c = 8, f = 16
					// T (y, 14) (56 / 4)
					for (y = y156, yp_0 = 0;
						y < y156 + 56;
						y += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 8, f = 16
						// T (h, 3) (3 / 1)
						for (h = h100, hp_0 = 0;
							h < h100 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 28, h = 1, w = 3, c = 8, f = 16
							// T (x, 28) (28 / 1)
							for (x = x266, xp_1 = x266_p_0, xp_0 = 0;
								x < x266 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										// y = 4, x = 1, h = 1, w = 3, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c234, cp_1 = c234_p_0, cp_0 = 0;
											c < c234 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1162);
											mem_vec_1162 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1163);
											mem_vec_1163 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1164);
											mem_vec_1164 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1165);
											mem_vec_1165 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_1162);
											mem_vec_1162 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_13 = _mm512_set1_ps(scal_5);


											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_1163);
											mem_vec_1163 = vec_12;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_1164);
											mem_vec_1164 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_1165);
											mem_vec_1165 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_1162);
											mem_vec_1162 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_22 = _mm512_set1_ps(scal_9);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_1163);
											mem_vec_1163 = vec_21;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_24 = _mm512_set1_ps(scal_10);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1164);
											mem_vec_1164 = vec_23;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_1165);
											mem_vec_1165 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1165);
							}
						}
					}
				}
			}
		}
	}
}


}