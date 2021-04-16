#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (2, x); T (2, f);
  T (7, x); T (2, y); T (4, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0, y54_p_0, yp_1, y54;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y55 = 0;
IND_TYPE x74 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c36 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 7) (56 / 8)
for (y54 = y55, y54_p_0 = 0;
	y54 < y55 + 56;
	y54 += 8, y54_p_0 += 8){
	// y = 8, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 4) (56 / 14)
	for (x73 = x74, x73_p_0 = 0;
		x73 < x74 + 56;
		x73 += 14, x73_p_0 += 14){
		// y = 8, x = 14, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (8 / 4)
		for (y = y54, yp_1 = y54_p_0, yp_0 = 0;
			y < y54 + 8;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 14, h = 1, w = 1, c = 64, f = 64
			// T (x, 7) (14 / 2)
			for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
				x72 < x73 + 14;
				x72 += 2, x72_p_1 += 2, x72_p_0 += 2){
				// y = 4, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f36, fp_0 = 0;
					f < f36 + 64;
					f += 32, fp_0 += 32){
					// y = 4, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (x, 2) (2 / 1)
					for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
						x < x72 + 2;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_290 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_291 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c36, cp_0 = 0;
									c < c36 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_288);
									mem_vec_288 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_289);
									mem_vec_289 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_290);
									mem_vec_290 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_291);
									mem_vec_291 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_292);
									mem_vec_292 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_293);
									mem_vec_293 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_294);
									mem_vec_294 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_295);
									mem_vec_295 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_296);
									mem_vec_296 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_297);
									mem_vec_297 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_298);
									mem_vec_298 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_299);
									mem_vec_299 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_300);
									mem_vec_300 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_301);
									mem_vec_301 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_302);
									mem_vec_302 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_303);
									mem_vec_303 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_288);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_289);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_290);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_291);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_292);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_293);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_294);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_295);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_296);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_297);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_298);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_299);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_301);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_302);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_303);
					}
				}
			}
		}
	}
}


}