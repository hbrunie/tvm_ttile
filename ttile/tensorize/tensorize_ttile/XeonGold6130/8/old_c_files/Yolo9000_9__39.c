#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, x, xp_0, x16_p_0, x17_p_0, xp_1, x16_p_1, xp_2, x16, x17, y, yp_0, y12_p_0, yp_1, y12;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y13 = 0;
IND_TYPE x18 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c13 = 0;
IND_TYPE f8 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
for (y12 = y13, y12_p_0 = 0;
	y12 < y13 + 68;
	y12 += 34, y12_p_0 += 34){
	// y = 34, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 2) (68 / 34)
	for (x17 = x18, x17_p_0 = 0;
		x17 < x18 + 68;
		x17 += 34, x17_p_0 += 34){
			for (y = y12, yp_1 = y12_p_0, yp_0 = 0;
				y < y12 + 6;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (34 / 34)
				for (x16 = x17, x16_p_1 = x17_p_0, x16_p_0 = 0;
					x16 < x17 + 34;
					x16 += 34, x16_p_1 += 34, x16_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f8, fp_0 = 0;
						f < f8 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c12 = c13, c12_p_0 = 0;
							c12 < c13 + 256;
							c12 += 256, c12_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x16, xp_2 = x16_p_1, xp_1 = x16_p_0, xp_0 = 0;
								x < x16 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_208);
											mem_vec_208 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_209);
											mem_vec_209 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_210);
											mem_vec_210 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_211);
											mem_vec_211 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_212);
											mem_vec_212 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_213);
											mem_vec_213 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_214);
											mem_vec_214 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_215);
											mem_vec_215 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_216);
											mem_vec_216 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_217);
											mem_vec_217 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_218);
											mem_vec_218 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_219);
											mem_vec_219 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_220);
											mem_vec_220 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_221);
											mem_vec_221 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_222);
											mem_vec_222 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_223);
											mem_vec_223 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_224);
											mem_vec_224 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_225);
											mem_vec_225 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_226);
											mem_vec_226 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_227);
											mem_vec_227 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_228);
											mem_vec_228 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_229);
											mem_vec_229 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_230);
											mem_vec_230 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_231);
											mem_vec_231 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_208);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_209);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_210);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_211);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_212);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_213);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_214);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_215);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_216);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_217);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_218);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_219);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_220);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_221);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_222);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_223);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_224);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_231);
							}
						}
					}
				}
			}
			for (y = y12 + 6, yp_1 = y12_p_0, yp_0 = 0;
				y < y12 + 6 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (34 / 34)
				for (x16 = x17, x16_p_1 = x17_p_0, x16_p_0 = 0;
					x16 < x17 + 34;
					x16 += 34, x16_p_1 += 34, x16_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f8, fp_0 = 0;
						f < f8 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c12 = c13, c12_p_0 = 0;
							c12 < c13 + 256;
							c12 += 256, c12_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x16, xp_2 = x16_p_1, xp_1 = x16_p_0, xp_0 = 0;
								x < x16 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_232);
											mem_vec_232 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_233);
											mem_vec_233 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_234);
											mem_vec_234 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_235);
											mem_vec_235 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_236);
											mem_vec_236 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_237);
											mem_vec_237 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_238);
											mem_vec_238 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_239);
											mem_vec_239 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_240);
											mem_vec_240 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_241);
											mem_vec_241 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_242);
											mem_vec_242 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_243);
											mem_vec_243 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_244);
											mem_vec_244 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_245);
											mem_vec_245 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_246);
											mem_vec_246 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_247);
											mem_vec_247 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_248);
											mem_vec_248 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_249);
											mem_vec_249 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_250);
											mem_vec_250 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_251);
											mem_vec_251 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_252);
											mem_vec_252 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_253);
											mem_vec_253 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_254);
											mem_vec_254 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_255);
											mem_vec_255 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_256);
											mem_vec_256 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_257);
											mem_vec_257 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_258);
											mem_vec_258 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_259);
											mem_vec_259 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_239);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_259);
							}
						}
					}
				}
			}
	}
}


}