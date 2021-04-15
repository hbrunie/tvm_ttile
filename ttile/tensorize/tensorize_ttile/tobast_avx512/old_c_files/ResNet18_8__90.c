#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, f); T (4, c); T (4, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f36_p_0, fp_1, f36, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f37 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f36 = f37, f36_p_0 = 0;
	f36 < f37 + 256;
	f36 += 128, f36_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (28 / 4)
	for (y = y24, yp_0 = 0;
		y < y24 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 4) (28 / 7)
		for (x36 = x37, x36_p_0 = 0;
			x36 < x37 + 28;
			x36 += 7, x36_p_0 += 7){
			// y = 4, x = 7, h = 3, w = 3, c = 128, f = 128
			// T (c, 4) (128 / 32)
			for (c36 = c37, c36_p_0 = 0;
				c36 < c37 + 128;
				c36 += 32, c36_p_0 += 32){
				// y = 4, x = 7, h = 3, w = 3, c = 32, f = 128
				// T (f, 2) (128 / 64)
				for (f = f36, fp_1 = f36_p_0, fp_0 = 0;
					f < f36 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 7, h = 3, w = 3, c = 32, f = 64
					// T (h, 3) (3 / 1)
					for (h = h24, hp_0 = 0;
						h < h24 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 7, h = 1, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w24, wp_0 = 0;
							w < w24 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 7, h = 1, w = 1, c = 32, f = 64
							// T (x, 7) (7 / 1)
							for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_224);
											mem_vec_224 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_225);
											mem_vec_225 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_226);
											mem_vec_226 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_227);
											mem_vec_227 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_228);
											mem_vec_228 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_229);
											mem_vec_229 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_230);
											mem_vec_230 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_231);
											mem_vec_231 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_232);
											mem_vec_232 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_233);
											mem_vec_233 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_234);
											mem_vec_234 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_235);
											mem_vec_235 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_236);
											mem_vec_236 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_237);
											mem_vec_237 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_238);
											mem_vec_238 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_239);
											mem_vec_239 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_224);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_231);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_239);
							}
						}
					}
				}
			}
		}
	}
}


}