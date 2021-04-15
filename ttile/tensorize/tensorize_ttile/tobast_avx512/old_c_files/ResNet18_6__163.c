#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, f); T (64, c); T (4, x); T (4, y); T (2, f)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, f36_p_0, fp_1, f36, h, hp_0, w, wp_0, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h24 = 0;
IND_TYPE w24 = 0;
IND_TYPE c37 = 0;
IND_TYPE f37 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f36 = f37, f36_p_0 = 0;
	f36 < f37 + 128;
	f36 += 64, f36_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 4) (28 / 7)
	for (y = y24, yp_0 = 0;
		y < y24 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 4) (28 / 7)
		for (x36 = x37, x36_p_0 = 0;
			x36 < x37 + 28;
			x36 += 7, x36_p_0 += 7){
			// y = 7, x = 7, h = 3, w = 3, c = 128, f = 64
			// T (c, 64) (128 / 2)
			for (c36 = c37, c36_p_0 = 0;
				c36 < c37 + 128;
				c36 += 2, c36_p_0 += 2){
				// y = 7, x = 7, h = 3, w = 3, c = 2, f = 64
				// T (f, 1) (64 / 64)
				for (f = f36, fp_1 = f36_p_0, fp_0 = 0;
					f < f36 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (h, 3) (3 / 1)
					for (h = h24, hp_0 = 0;
						h < h24 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w24, wp_0 = 0;
							w < w24 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 2, f = 64
							// T (x, 7) (7 / 1)
							for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_236);
											mem_vec_236 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_237);
											mem_vec_237 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_238);
											mem_vec_238 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_239);
											mem_vec_239 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_240);
											mem_vec_240 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_241);
											mem_vec_241 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_242);
											mem_vec_242 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_243);
											mem_vec_243 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_244);
											mem_vec_244 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_245);
											mem_vec_245 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_246);
											mem_vec_246 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_247);
											mem_vec_247 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_248);
											mem_vec_248 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_249);
											mem_vec_249 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_250);
											mem_vec_250 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_251);
											mem_vec_251 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_252);
											mem_vec_252 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_253);
											mem_vec_253 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_254);
											mem_vec_254 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_255);
											mem_vec_255 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_256);
											mem_vec_256 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_257);
											mem_vec_257 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_258);
											mem_vec_258 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_259);
											mem_vec_259 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_260);
											mem_vec_260 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_261);
											mem_vec_261 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_262);
											mem_vec_262 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_263);
											mem_vec_263 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_239);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_263);
							}
						}
					}
				}
			}
		}
	}
}


}