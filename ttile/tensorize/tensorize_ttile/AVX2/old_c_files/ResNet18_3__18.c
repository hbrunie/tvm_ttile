#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (2, x); T (2, f);
  T (14, x); T (7, y); T (2, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y31 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c20 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 2) (56 / 28)
for (y30 = y31, y30_p_0 = 0;
	y30 < y31 + 56;
	y30 += 28, y30_p_0 += 28){
	// y = 28, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 2) (56 / 28)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 56;
		x41 += 28, x41_p_0 += 28){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
			y < y30 + 28;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 14) (28 / 2)
			for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
				x40 < x41 + 28;
				x40 += 2, x40_p_1 += 2, x40_p_0 += 2){
				// y = 4, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f20, fp_0 = 0;
					f < f20 + 64;
					f += 32, fp_0 += 32){
					// y = 4, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (x, 2) (2 / 1)
					for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
						x < x40 + 2;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c20, cp_0 = 0;
									c < c20 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_160);
									mem_vec_160 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_161);
									mem_vec_161 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_162);
									mem_vec_162 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_163);
									mem_vec_163 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_164);
									mem_vec_164 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_165);
									mem_vec_165 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_166);
									mem_vec_166 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_167);
									mem_vec_167 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_168);
									mem_vec_168 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_169);
									mem_vec_169 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_170);
									mem_vec_170 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_171);
									mem_vec_171 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_172);
									mem_vec_172 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_173);
									mem_vec_173 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_174);
									mem_vec_174 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_175);
									mem_vec_175 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_160);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_161);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_162);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_163);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_164);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_165);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_166);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_167);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_168);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_169);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_170);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_171);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_172);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_173);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_174);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_175);
					}
				}
			}
		}
	}
}


}