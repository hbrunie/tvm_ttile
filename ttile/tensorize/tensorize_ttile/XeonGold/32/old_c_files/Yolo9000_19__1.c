#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (512, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, x, xp_0, y, yp_0, y18_p_0, yp_1, y18;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y19 = 0;
IND_TYPE x12 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c19 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,mem_vec_208 ,mem_vec_209 ,mem_vec_210 ,mem_vec_211 ,mem_vec_212 ,mem_vec_213 ,mem_vec_214 ,mem_vec_215 ,mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y18 = y19, y18_p_0 = 0;
	y18 < y19 + 17;
	y18 += 17, y18_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (f, 16) (512 / 32)
	for (f = f12, fp_0 = 0;
		f < f12 + 512;
		f += 32, fp_0 += 32){
			for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
				y < y18 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 512) (1024 / 2)
				for (c18 = c19, c18_p_0 = 0;
					c18 < c19 + 1024;
					c18 += 2, c18_p_0 += 2){
					// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x = x12, xp_0 = 0;
						x < x12 + 17;
						x += 1, xp_0 += 1){
								mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (c, 2) (2 / 1)
								for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
									c < c18 + 2;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_204);
									mem_vec_204 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_205);
									mem_vec_205 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_206);
									mem_vec_206 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_207);
									mem_vec_207 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_208);
									mem_vec_208 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_209);
									mem_vec_209 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_210);
									mem_vec_210 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_211);
									mem_vec_211 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_212);
									mem_vec_212 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_213);
									mem_vec_213 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_214);
									mem_vec_214 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_215);
									mem_vec_215 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_216);
									mem_vec_216 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_217);
									mem_vec_217 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_218);
									mem_vec_218 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_219);
									mem_vec_219 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_204);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_205);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_206);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_207);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_208);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_209);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_210);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_211);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_212);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_213);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_214);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_215);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_216);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_217);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_218);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_219);
					}
				}
			}
			for (y = y18 + 8, yp_1 = y18_p_0, yp_0 = 0;
				y < y18 + 8 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 512) (1024 / 2)
				for (c18 = c19, c18_p_0 = 0;
					c18 < c19 + 1024;
					c18 += 2, c18_p_0 += 2){
					// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
					// T (x, 17) (17 / 1)
					for (x = x12, xp_0 = 0;
						x < x12 + 17;
						x += 1, xp_0 += 1){
								mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (c, 2) (2 / 1)
								for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
									c < c18 + 2;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_220);
									mem_vec_220 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_221);
									mem_vec_221 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_222);
									mem_vec_222 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_223);
									mem_vec_223 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_224);
									mem_vec_224 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_225);
									mem_vec_225 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_226);
									mem_vec_226 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_227);
									mem_vec_227 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_228);
									mem_vec_228 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_229);
									mem_vec_229 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_230);
									mem_vec_230 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_231);
									mem_vec_231 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_232);
									mem_vec_232 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_233);
									mem_vec_233 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_234);
									mem_vec_234 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_235);
									mem_vec_235 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_236);
									mem_vec_236 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_237);
									mem_vec_237 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_220);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_221);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_222);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_223);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_224);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_225);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_226);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_227);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_228);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_229);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_230);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_231);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_232);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_233);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_234);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_235);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_236);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_237);
					}
				}
			}
	}
}


}