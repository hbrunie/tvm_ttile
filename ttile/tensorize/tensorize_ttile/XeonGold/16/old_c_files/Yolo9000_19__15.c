#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (1024, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c21_p_0, cp_1, c21, f, fp_0, x, xp_0, y, yp_0, y21_p_0, yp_1, y21;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y22 = 0;
IND_TYPE x14 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c22 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y21 = y22, y21_p_0 = 0;
	y21 < y22 + 17;
	y21 += 17, y21_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (f, 16) (512 / 32)
	for (f = f14, fp_0 = 0;
		f < f14 + 512;
		f += 32, fp_0 += 32){
			for (y = y21, yp_1 = y21_p_0, yp_0 = 0;
				y < y21 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1024) (1024 / 1)
				for (c21 = c22, c21_p_0 = 0;
					c21 < c22 + 1024;
					c21 += 1, c21_p_0 += 1){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (17 / 1)
					for (x = x14, xp_0 = 0;
						x < x14 + 17;
						x += 1, xp_0 += 1){
								mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
									c < c21 + 1;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_238);
									mem_vec_238 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_239);
									mem_vec_239 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_240);
									mem_vec_240 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_241);
									mem_vec_241 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_242);
									mem_vec_242 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_243);
									mem_vec_243 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_244);
									mem_vec_244 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_245);
									mem_vec_245 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_246);
									mem_vec_246 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_247);
									mem_vec_247 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_248);
									mem_vec_248 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_249);
									mem_vec_249 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_250);
									mem_vec_250 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_251);
									mem_vec_251 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_252);
									mem_vec_252 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_253);
									mem_vec_253 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_238);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_239);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_240);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_241);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_242);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_243);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_244);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_245);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_246);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_247);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_248);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_249);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_250);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_251);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_252);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_253);
					}
				}
			}
			for (y = y21 + 8, yp_1 = y21_p_0, yp_0 = 0;
				y < y21 + 8 + 9;
				y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 1024) (1024 / 1)
				for (c21 = c22, c21_p_0 = 0;
					c21 < c22 + 1024;
					c21 += 1, c21_p_0 += 1){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (17 / 1)
					for (x = x14, xp_0 = 0;
						x < x14 + 17;
						x += 1, xp_0 += 1){
								mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
									c < c21 + 1;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_254);
									mem_vec_254 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_255);
									mem_vec_255 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_256);
									mem_vec_256 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_257);
									mem_vec_257 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_258);
									mem_vec_258 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_259);
									mem_vec_259 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_260);
									mem_vec_260 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_261);
									mem_vec_261 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_262);
									mem_vec_262 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_263);
									mem_vec_263 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_264);
									mem_vec_264 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_265);
									mem_vec_265 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_266);
									mem_vec_266 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_267);
									mem_vec_267 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_268);
									mem_vec_268 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_269);
									mem_vec_269 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_270);
									mem_vec_270 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_271);
									mem_vec_271 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_254);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_255);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_256);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_257);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_258);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_259);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_260);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_261);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_262);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_263);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_264);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_265);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_266);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_267);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_268);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_269);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_270);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_271);
					}
				}
			}
	}
}


}