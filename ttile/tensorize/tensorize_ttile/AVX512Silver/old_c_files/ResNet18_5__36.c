#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (28, x); T (1, c);
  T (1, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c25_p_0, cp_1, c25, f, fp_0, f25_p_0, fp_1, f25, x, xp_0, x36_p_0, xp_1, x36, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y24 = 0;
IND_TYPE x37 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c26 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,mem_vec_250 ,mem_vec_251 ,mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f25 = f26, f25_p_0 = 0;
	f25 < f26 + 128;
	f25 += 64, f25_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f25, fp_1 = f25_p_0, fp_0 = 0;
		f < f25 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y24, yp_0 = 0;
			y < y24 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (28 / 28)
			for (x36 = x37, x36_p_0 = 0;
				x36 < x37 + 28;
				x36 += 28, x36_p_0 += 28){
				// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
				// T (c, 1) (64 / 64)
				for (c25 = c26, c25_p_0 = 0;
					c25 < c26 + 64;
					c25 += 64, c25_p_0 += 64){
					// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
					// T (x, 28) (28 / 1)
					for (x = x36, xp_1 = x36_p_0, xp_0 = 0;
						x < x36 + 28;
						x += 1, xp_1 += 1, xp_0 += 1){
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
								mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c25, cp_1 = c25_p_0, cp_0 = 0;
									c < c25 + 64;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
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
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_244);
									mem_vec_244 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_245);
									mem_vec_245 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_246);
									mem_vec_246 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_247);
									mem_vec_247 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_248);
									mem_vec_248 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_249);
									mem_vec_249 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_250);
									mem_vec_250 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_251);
									mem_vec_251 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_252);
									mem_vec_252 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_253);
									mem_vec_253 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_254);
									mem_vec_254 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_255);
									mem_vec_255 = vec_23;
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
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_252);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_253);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_254);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_255);
					}
				}
			}
		}
	}
}


}