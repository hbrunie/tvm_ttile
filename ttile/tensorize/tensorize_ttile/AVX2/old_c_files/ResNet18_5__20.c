#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (4, x); T (4, f);
  T (7, x); T (1, y); T (1, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x28_p_0, x29_p_0, xp_1, x28_p_1, xp_2, x28, x29, y, yp_0, y21_p_0, yp_1, y21;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y22 = 0;
IND_TYPE x30 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c14 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 7) (28 / 4)
for (y21 = y22, y21_p_0 = 0;
	y21 < y22 + 28;
	y21 += 4, y21_p_0 += 4){
	// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (x, 1) (28 / 28)
	for (x29 = x30, x29_p_0 = 0;
		x29 < x30 + 28;
		x29 += 28, x29_p_0 += 28){
		// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
		// T (y, 1) (4 / 4)
		for (y = y21, yp_1 = y21_p_0, yp_0 = 0;
			y < y21 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
			// T (x, 7) (28 / 4)
			for (x28 = x29, x28_p_1 = x29_p_0, x28_p_0 = 0;
				x28 < x29 + 28;
				x28 += 4, x28_p_1 += 4, x28_p_0 += 4){
				// y = 4, x = 4, h = 1, w = 1, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f14, fp_0 = 0;
					f < f14 + 128;
					f += 32, fp_0 += 32){
					// y = 4, x = 4, h = 1, w = 1, c = 64, f = 32
					// T (x, 4) (4 / 1)
					for (x = x28, xp_2 = x28_p_1, xp_1 = x28_p_0, xp_0 = 0;
						x < x28 + 4;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c14, cp_0 = 0;
									c < c14 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_112);
									mem_vec_112 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_113);
									mem_vec_113 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_114);
									mem_vec_114 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_115);
									mem_vec_115 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_116);
									mem_vec_116 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_117);
									mem_vec_117 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_118);
									mem_vec_118 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_119);
									mem_vec_119 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_120);
									mem_vec_120 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_121);
									mem_vec_121 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_122);
									mem_vec_122 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_123);
									mem_vec_123 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_124);
									mem_vec_124 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_125);
									mem_vec_125 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_126);
									mem_vec_126 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_127);
									mem_vec_127 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_112);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_113);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_114);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_115);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_116);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_117);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_118);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_119);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_120);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_121);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_122);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_123);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_124);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_125);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_126);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_127);
					}
				}
			}
		}
	}
}


}