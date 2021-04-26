#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (3, h); T (4, x);
  T (3, w); T (4, c); T (1, f); T (7, x); T (2, y); T (4, f)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, f24_p_0, fp_1, f24, h, hp_0, w, wp_0, x, xp_0, x24_p_0, xp_1, x24, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y16 = 0;
IND_TYPE x25 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f24 = f25, f24_p_0 = 0;
	f24 < f25 + 128;
	f24 += 32, f24_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
	// T (y, 2) (28 / 14)
	for (y = y16, yp_0 = 0;
		y < y16 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 64, f = 32
		// T (x, 7) (28 / 4)
		for (x24 = x25, x24_p_0 = 0;
			x24 < x25 + 28;
			x24 += 4, x24_p_0 += 4){
			// y = 14, x = 4, h = 3, w = 3, c = 64, f = 32
			// T (f, 1) (32 / 32)
			for (f = f24, fp_1 = f24_p_0, fp_0 = 0;
				f < f24 + 32;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 14, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (c, 4) (64 / 16)
				for (c24 = c25, c24_p_0 = 0;
					c24 < c25 + 64;
					c24 += 16, c24_p_0 += 16){
					// y = 14, x = 4, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w16, wp_0 = 0;
						w < w16 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 4, h = 3, w = 1, c = 16, f = 32
						// T (x, 4) (4 / 1)
						for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
							x < x24 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
										mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
											c < c24 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_224);
											mem_vec_224 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_225);
											mem_vec_225 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_226);
											mem_vec_226 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_227);
											mem_vec_227 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_228);
											mem_vec_228 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_229);
											mem_vec_229 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_230);
											mem_vec_230 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_231);
											mem_vec_231 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_232);
											mem_vec_232 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_233);
											mem_vec_233 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_234);
											mem_vec_234 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_235);
											mem_vec_235 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_236);
											mem_vec_236 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_237);
											mem_vec_237 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_238);
											mem_vec_238 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_239);
											mem_vec_239 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_240);
											mem_vec_240 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_241);
											mem_vec_241 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_242);
											mem_vec_242 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_243);
											mem_vec_243 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_244);
											mem_vec_244 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_245);
											mem_vec_245 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_246);
											mem_vec_246 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_247);
											mem_vec_247 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_248);
											mem_vec_248 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_249);
											mem_vec_249 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_250);
											mem_vec_250 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_251);
											mem_vec_251 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_224);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_231);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_239);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_251);
							}
						}
					}
				}
			}
		}
	}
}


}