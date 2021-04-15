#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (128, c); Hoist_vars [c]; T (17, x); T (2, x);
  T (17, y); T (2, f); T (4, x)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x56_p_0, x57_p_0, xp_1, x56_p_1, xp_2, x56, x57, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y28 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 4) (136 / 34)
for (x57 = x58, x57_p_0 = 0;
	x57 < x58 + 136;
	x57 += 34, x57_p_0 += 34){
	// y = 136, x = 34, h = 1, w = 1, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f = f28, fp_0 = 0;
		f < f28 + 64;
		f += 32, fp_0 += 32){
		// y = 136, x = 34, h = 1, w = 1, c = 128, f = 32
		// T (y, 17) (136 / 8)
		for (y = y28, yp_0 = 0;
			y < y28 + 136;
			y += 8, yp_0 += 8){
			// y = 8, x = 34, h = 1, w = 1, c = 128, f = 32
			// T (x, 2) (34 / 17)
			for (x56 = x57, x56_p_1 = x57_p_0, x56_p_0 = 0;
				x56 < x57 + 34;
				x56 += 17, x56_p_1 += 17, x56_p_0 += 17){
				// y = 8, x = 17, h = 1, w = 1, c = 128, f = 32
				// T (x, 17) (17 / 1)
				for (x = x56, xp_2 = x56_p_1, xp_1 = x56_p_0, xp_0 = 0;
					x < x56 + 17;
					x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
							// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 128) (128 / 1)
							for (c = c28, cp_0 = 0;
								c < c28 + 128;
								c += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_224);
								mem_vec_224 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_225);
								mem_vec_225 = vec_3;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_226);
								mem_vec_226 = vec_5;



								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_227);
								mem_vec_227 = vec_7;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);


								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_228);
								mem_vec_228 = vec_8;



								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_229);
								mem_vec_229 = vec_10;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_230);
								mem_vec_230 = vec_11;



								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_231);
								mem_vec_231 = vec_13;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_232);
								mem_vec_232 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_233);
								mem_vec_233 = vec_16;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);


								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_234);
								mem_vec_234 = vec_17;



								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_235);
								mem_vec_235 = vec_19;
								scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_236);
								mem_vec_236 = vec_20;



								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_237);
								mem_vec_237 = vec_22;
								scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
								vec_24 = _mm512_set1_ps(scal_7);


								vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_238);
								mem_vec_238 = vec_23;



								vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_239);
								mem_vec_239 = vec_25;
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
				}
			}
		}
	}
}


}