#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (64, c); T (14, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, f30_p_0, fp_1, f30, h, hp_0, w, wp_0, x, xp_0, x30_p_0, xp_1, x30, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y20 = 0;
IND_TYPE x31 = 0;
IND_TYPE h20 = 0;
IND_TYPE w20 = 0;
IND_TYPE c31 = 0;
IND_TYPE f31 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f30 = f31, f30_p_0 = 0;
	f30 < f31 + 128;
	f30 += 64, f30_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 7) (28 / 4)
	for (y = y20, yp_0 = 0;
		y < y20 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 14) (28 / 2)
		for (x30 = x31, x30_p_0 = 0;
			x30 < x31 + 28;
			x30 += 2, x30_p_0 += 2){
			// y = 4, x = 2, h = 3, w = 3, c = 128, f = 64
			// T (c, 64) (128 / 2)
			for (c30 = c31, c30_p_0 = 0;
				c30 < c31 + 128;
				c30 += 2, c30_p_0 += 2){
				// y = 4, x = 2, h = 3, w = 3, c = 2, f = 64
				// T (f, 1) (64 / 64)
				for (f = f30, fp_1 = f30_p_0, fp_0 = 0;
					f < f30 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 2, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h20, hp_0 = 0;
						h < h20 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 2, h = 1, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w20, wp_0 = 0;
							w < w20 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 2, h = 1, w = 1, c = 2, f = 64
							// T (x, 2) (2 / 1)
							for (x = x30, xp_1 = x30_p_0, xp_0 = 0;
								x < x30 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_200);
											mem_vec_200 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_201);
											mem_vec_201 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_202);
											mem_vec_202 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_203);
											mem_vec_203 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_204);
											mem_vec_204 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_205);
											mem_vec_205 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_206);
											mem_vec_206 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_207);
											mem_vec_207 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_208);
											mem_vec_208 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_209);
											mem_vec_209 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_210);
											mem_vec_210 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_211);
											mem_vec_211 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_212);
											mem_vec_212 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_213);
											mem_vec_213 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_214);
											mem_vec_214 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_215);
											mem_vec_215 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_203);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_204);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_205);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_206);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_207);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_208);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_209);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_210);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_211);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_212);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_213);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_214);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_215);
							}
						}
					}
				}
			}
		}
	}
}


}