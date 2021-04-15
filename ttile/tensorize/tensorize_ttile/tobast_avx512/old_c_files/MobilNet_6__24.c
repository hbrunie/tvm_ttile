#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, f); T (64, c); T (14, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, f24_p_0, fp_1, f24, h, hp_0, w, wp_0, x, xp_0, x24_p_0, xp_1, x24, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y16 = 0;
IND_TYPE x25 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f24 = f25, f24_p_0 = 0;
	f24 < f25 + 256;
	f24 += 128, f24_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
	// T (y, 2) (14 / 7)
	for (y = y16, yp_0 = 0;
		y < y16 + 14;
		y += 7, yp_0 += 7){
		// y = 7, x = 14, h = 3, w = 3, c = 256, f = 128
		// T (x, 14) (14 / 1)
		for (x24 = x25, x24_p_0 = 0;
			x24 < x25 + 14;
			x24 += 1, x24_p_0 += 1){
			// y = 7, x = 1, h = 3, w = 3, c = 256, f = 128
			// T (c, 64) (256 / 4)
			for (c24 = c25, c24_p_0 = 0;
				c24 < c25 + 256;
				c24 += 4, c24_p_0 += 4){
				// y = 7, x = 1, h = 3, w = 3, c = 4, f = 128
				// T (f, 2) (128 / 64)
				for (f = f24, fp_1 = f24_p_0, fp_0 = 0;
					f < f24 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 1, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h16, hp_0 = 0;
						h < h16 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
							// T (x, 1) (1 / 1)
							for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
								x < x24 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
											c < c24 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_196);
											mem_vec_196 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_197);
											mem_vec_197 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_198);
											mem_vec_198 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_199);
											mem_vec_199 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_200);
											mem_vec_200 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_201);
											mem_vec_201 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_202);
											mem_vec_202 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_203);
											mem_vec_203 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_204);
											mem_vec_204 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_205);
											mem_vec_205 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_206);
											mem_vec_206 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_207);
											mem_vec_207 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_208);
											mem_vec_208 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_209);
											mem_vec_209 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_210);
											mem_vec_210 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_211);
											mem_vec_211 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_212);
											mem_vec_212 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_213);
											mem_vec_213 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_214);
											mem_vec_214 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_215);
											mem_vec_215 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_216);
											mem_vec_216 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_217);
											mem_vec_217 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_218);
											mem_vec_218 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_219);
											mem_vec_219 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_220);
											mem_vec_220 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_221);
											mem_vec_221 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_222);
											mem_vec_222 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_223);
											mem_vec_223 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_196);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_197);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_198);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_199);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_203);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_204);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_205);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_206);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_207);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_208);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_209);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_210);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_211);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_212);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_213);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_214);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_215);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_216);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_217);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_218);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_219);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_220);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_221);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_222);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_223);
							}
						}
					}
				}
			}
		}
	}
}


}