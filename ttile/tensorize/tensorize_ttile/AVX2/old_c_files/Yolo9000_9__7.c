#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (68, x); T (128, c);
  T (4, f); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, x, xp_0, x42_p_0, xp_1, x42, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y28 = 0;
IND_TYPE x43 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c43 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 17) (68 / 4)
for (y = y28, yp_0 = 0;
	y < y28 + 68;
	y += 4, yp_0 += 4){
	// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x42 = x43, x42_p_0 = 0;
		x42 < x43 + 68;
		x42 += 68, x42_p_0 += 68){
		// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f28, fp_0 = 0;
			f < f28 + 128;
			f += 32, fp_0 += 32){
			// y = 4, x = 68, h = 1, w = 1, c = 256, f = 32
			// T (c, 128) (256 / 2)
			for (c42 = c43, c42_p_0 = 0;
				c42 < c43 + 256;
				c42 += 2, c42_p_0 += 2){
				// y = 4, x = 68, h = 1, w = 1, c = 2, f = 32
				// T (x, 68) (68 / 1)
				for (x = x42, xp_1 = x42_p_0, xp_0 = 0;
					x < x42 + 68;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_224 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_225 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
							mem_vec_226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
							mem_vec_228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
							mem_vec_230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
							mem_vec_232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
							mem_vec_234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
							mem_vec_236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
							mem_vec_238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
							// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
							// T (c, 2) (2 / 1)
							for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
								c < c42 + 2;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm256_set1_ps(scal_0);
								vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_224);
								mem_vec_224 = vec_0;

								vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

								vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_225);
								mem_vec_225 = vec_3;

								vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_226);
								mem_vec_226 = vec_5;

								vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

								vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_227);
								mem_vec_227 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm256_set1_ps(scal_1);


								vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_228);
								mem_vec_228 = vec_9;



								vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_229);
								mem_vec_229 = vec_11;



								vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_230);
								mem_vec_230 = vec_12;



								vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_231);
								mem_vec_231 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm256_set1_ps(scal_2);


								vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_232);
								mem_vec_232 = vec_14;



								vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_233);
								mem_vec_233 = vec_16;



								vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_234);
								mem_vec_234 = vec_17;



								vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_235);
								mem_vec_235 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm256_set1_ps(scal_3);


								vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_236);
								mem_vec_236 = vec_19;



								vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_237);
								mem_vec_237 = vec_21;



								vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_238);
								mem_vec_238 = vec_22;



								vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_239);
								mem_vec_239 = vec_23;
							}
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_224);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_225);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_226);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_227);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_228);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_229);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_230);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_231);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_232);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_233);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_234);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_235);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_236);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_237);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_238);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_239);
				}
			}
		}
	}
}


}