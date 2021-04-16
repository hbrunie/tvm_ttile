#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (7, x); T (4, f);
  T (1, x); T (1, y); T (4, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0, y48_p_0, yp_1, y48;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y49 = 0;
IND_TYPE x66 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c32 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 7) (28 / 4)
for (y48 = y49, y48_p_0 = 0;
	y48 < y49 + 28;
	y48 += 4, y48_p_0 += 4){
	// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (x, 4) (28 / 7)
	for (x65 = x66, x65_p_0 = 0;
		x65 < x66 + 28;
		x65 += 7, x65_p_0 += 7){
		// y = 4, x = 7, h = 1, w = 1, c = 64, f = 128
		// T (y, 1) (4 / 4)
		for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
			y < y48 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 7, h = 1, w = 1, c = 64, f = 128
			// T (x, 1) (7 / 7)
			for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
				x64 < x65 + 7;
				x64 += 7, x64_p_1 += 7, x64_p_0 += 7){
				// y = 4, x = 7, h = 1, w = 1, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f32, fp_0 = 0;
					f < f32 + 128;
					f += 32, fp_0 += 32){
					// y = 4, x = 7, h = 1, w = 1, c = 64, f = 32
					// T (x, 7) (7 / 1)
					for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
						x < x64 + 7;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_256 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_257 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_258 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_259 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c32, cp_0 = 0;
									c < c32 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_256);
									mem_vec_256 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_257);
									mem_vec_257 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_258);
									mem_vec_258 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_259);
									mem_vec_259 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_260);
									mem_vec_260 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_261);
									mem_vec_261 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_262);
									mem_vec_262 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_263);
									mem_vec_263 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_264);
									mem_vec_264 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_265);
									mem_vec_265 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_266);
									mem_vec_266 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_267);
									mem_vec_267 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_268);
									mem_vec_268 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_269);
									mem_vec_269 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_270);
									mem_vec_270 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_271);
									mem_vec_271 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_256);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_257);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_258);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_259);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_260);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_261);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_262);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_263);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_264);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_265);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_266);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_267);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_268);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_269);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_270);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_271);
					}
				}
			}
		}
	}
}


}