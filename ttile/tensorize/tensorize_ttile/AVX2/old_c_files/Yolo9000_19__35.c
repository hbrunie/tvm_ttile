#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (1, y);
  T (16, f); T (16, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0, y18_p_0, yp_1, y18;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y19 = 0;
IND_TYPE x19 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c19 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_216 ,mem_vec_217 ,mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y18 = y19, y18_p_0 = 0;
		y18 < y19 + 12;
		y18 += 4, y18_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x18 = x19, x18_p_0 = 0;
			x18 < x19 + 17;
			x18 += 17, x18_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 16) (1024 / 64)
			for (c18 = c19, c18_p_0 = 0;
				c18 < c19 + 1024;
				c18 += 64, c18_p_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 512
				// T (f, 16) (512 / 32)
				for (f = f12, fp_0 = 0;
					f < f12 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
						y < y18 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
							x < x18 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_216 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_217 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_218 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_219 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
										c < c18 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_216);
										mem_vec_216 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_217);
										mem_vec_217 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_218);
										mem_vec_218 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_219);
										mem_vec_219 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_220);
										mem_vec_220 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_221);
										mem_vec_221 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_222);
										mem_vec_222 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_223);
										mem_vec_223 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_224);
										mem_vec_224 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_225);
										mem_vec_225 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_226);
										mem_vec_226 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_227);
										mem_vec_227 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_228);
										mem_vec_228 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_229);
										mem_vec_229 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_230);
										mem_vec_230 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_231);
										mem_vec_231 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_216);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_217);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_218);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_219);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_220);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_221);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_222);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_223);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_224);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_225);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_226);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_227);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_228);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_229);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_230);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_231);
						}
					}
				}
			}
		}
	}
	for (y18 = y19 + 12, y18_p_0 = 0;
		y18 < y19 + 12 + 5;
		y18 += 5, y18_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 1) (17 / 17)
		for (x18 = x19, x18_p_0 = 0;
			x18 < x19 + 17;
			x18 += 17, x18_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (c, 16) (1024 / 64)
			for (c18 = c19, c18_p_0 = 0;
				c18 < c19 + 1024;
				c18 += 64, c18_p_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 512
				// T (f, 16) (512 / 32)
				for (f = f12, fp_0 = 0;
					f < f12 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
						y < y18 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
						// T (x, 17) (17 / 1)
						for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
							x < x18 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_232 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_233 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_234 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_235 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
										c < c18 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_232);
										mem_vec_232 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_233);
										mem_vec_233 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_234);
										mem_vec_234 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_235);
										mem_vec_235 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_236);
										mem_vec_236 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_237);
										mem_vec_237 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_238);
										mem_vec_238 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_239);
										mem_vec_239 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_240);
										mem_vec_240 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_241);
										mem_vec_241 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_242);
										mem_vec_242 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_243);
										mem_vec_243 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_244);
										mem_vec_244 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_245);
										mem_vec_245 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_246);
										mem_vec_246 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_247);
										mem_vec_247 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_248);
										mem_vec_248 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_249);
										mem_vec_249 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_250);
										mem_vec_250 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_251);
										mem_vec_251 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_232);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_233);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_234);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_235);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_236);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_237);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_238);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_239);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_240);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_241);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_242);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_243);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_244);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_245);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_246);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_247);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_248);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_249);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_250);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_251);
						}
					}
				}
			}
		}
	}


}