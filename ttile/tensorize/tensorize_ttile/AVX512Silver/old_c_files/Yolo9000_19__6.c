#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c24_p_0, c25_p_0, cp_1, c24_p_1, cp_2, c24, c25, f, fp_0, x, xp_0, y, yp_0, y18_p_0, yp_1, y18;

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
IND_TYPE c26 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y18 = y19, y18_p_0 = 0;
		y18 < y19 + 3;
		y18 += 3, y18_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c25 = c26, c25_p_0 = 0;
			c25 < c26 + 1024;
			c25 += 1024, c25_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f12, fp_0 = 0;
				f < f12 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
					y < y18 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c24 = c25, c24_p_1 = c25_p_0, c24_p_0 = 0;
						c24 < c25 + 1024;
						c24 += 32, c24_p_1 += 32, c24_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x12, xp_0 = 0;
							x < x12 + 17;
							x += 1, xp_0 += 1){
									mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c24, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_240);
										mem_vec_240 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_241);
										mem_vec_241 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_242);
										mem_vec_242 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_243);
										mem_vec_243 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_244);
										mem_vec_244 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_245);
										mem_vec_245 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_246);
										mem_vec_246 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_247);
										mem_vec_247 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_248);
										mem_vec_248 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_249);
										mem_vec_249 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_250);
										mem_vec_250 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_251);
										mem_vec_251 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_251);
						}
					}
				}
			}
		}
	}
	for (y18 = y19 + 3, y18_p_0 = 0;
		y18 < y19 + 3 + 14;
		y18 += 7, y18_p_0 += 7){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c25 = c26, c25_p_0 = 0;
			c25 < c26 + 1024;
			c25 += 1024, c25_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f12, fp_0 = 0;
				f < f12 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
					y < y18 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 32) (1024 / 32)
					for (c24 = c25, c24_p_1 = c25_p_0, c24_p_0 = 0;
						c24 < c25 + 1024;
						c24 += 32, c24_p_1 += 32, c24_p_0 += 32){
						// y = ph_y, x = 17, h = 1, w = 1, c = 32, f = 64
						// T (x, 17) (17 / 1)
						for (x = x12, xp_0 = 0;
							x < x12 + 17;
							x += 1, xp_0 += 1){
									mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c24, cp_2 = c24_p_1, cp_1 = c24_p_0, cp_0 = 0;
										c < c24 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_252);
										mem_vec_252 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_253);
										mem_vec_253 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_254);
										mem_vec_254 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_255);
										mem_vec_255 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_256);
										mem_vec_256 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_257);
										mem_vec_257 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_258);
										mem_vec_258 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_259);
										mem_vec_259 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_260);
										mem_vec_260 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_261);
										mem_vec_261 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_262);
										mem_vec_262 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_263);
										mem_vec_263 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_264);
										mem_vec_264 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_265);
										mem_vec_265 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_266);
										mem_vec_266 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_267);
										mem_vec_267 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_268);
										mem_vec_268 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_269);
										mem_vec_269 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_270);
										mem_vec_270 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_271);
										mem_vec_271 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_272);
										mem_vec_272 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_273);
										mem_vec_273 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_274);
										mem_vec_274 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_275);
										mem_vec_275 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_276);
										mem_vec_276 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_277);
										mem_vec_277 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_278);
										mem_vec_278 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_279);
										mem_vec_279 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_279);
						}
					}
				}
			}
		}
	}


}