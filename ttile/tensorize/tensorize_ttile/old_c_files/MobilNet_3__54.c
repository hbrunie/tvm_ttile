#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, x); T (7, y); T (4, f); T (64, c); T (14, x)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x48_p_0, x49_p_0, xp_1, x48_p_1, xp_2, x48, x49, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y24 = 0;
IND_TYPE x50 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 14) (56 / 4)
for (x49 = x50, x49_p_0 = 0;
	x49 < x50 + 56;
	x49 += 4, x49_p_0 += 4){
	// y = 56, x = 4, h = 3, w = 3, c = 128, f = 128
	// T (c, 64) (128 / 2)
	for (c36 = c37, c36_p_0 = 0;
		c36 < c37 + 128;
		c36 += 2, c36_p_0 += 2){
		// y = 56, x = 4, h = 3, w = 3, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f24, fp_0 = 0;
			f < f24 + 128;
			f += 32, fp_0 += 32){
			// y = 56, x = 4, h = 3, w = 3, c = 2, f = 32
			// T (y, 7) (56 / 8)
			for (y = y24, yp_0 = 0;
				y < y24 + 56;
				y += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 2, f = 32
				// T (x, 4) (4 / 1)
				for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
					x48 < x49 + 4;
					x48 += 1, x48_p_1 += 1, x48_p_0 += 1){
					// y = 8, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (h, 3) (3 / 1)
					for (h = h24, hp_0 = 0;
						h < h24 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 1, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w24, wp_0 = 0;
							w < w24 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (x, 1) (1 / 1)
							for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
								x < x48 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_192);
											mem_vec_192 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_193);
											mem_vec_193 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_194);
											mem_vec_194 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_195);
											mem_vec_195 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_196);
											mem_vec_196 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_197);
											mem_vec_197 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_198);
											mem_vec_198 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_199);
											mem_vec_199 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_200);
											mem_vec_200 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_201);
											mem_vec_201 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_202);
											mem_vec_202 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_203);
											mem_vec_203 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_204);
											mem_vec_204 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_205);
											mem_vec_205 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_206);
											mem_vec_206 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_207);
											mem_vec_207 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_192);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_193);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_194);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_195);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_196);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_197);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_198);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_199);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_203);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_204);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_205);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_206);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_207);
							}
						}
					}
				}
			}
		}
	}
}


}