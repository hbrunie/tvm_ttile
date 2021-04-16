#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (7, x); T (4, f);
  T (4, x); T (1, y); T (1, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x20_p_0, x21_p_0, xp_1, x20_p_1, xp_2, x20, x21, y, yp_0, y15_p_0, yp_1, y15;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y16 = 0;
IND_TYPE x22 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_80 ,mem_vec_81 ,mem_vec_82 ,mem_vec_83 ,mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 7) (28 / 4)
for (y15 = y16, y15_p_0 = 0;
	y15 < y16 + 28;
	y15 += 4, y15_p_0 += 4){
	// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (x, 1) (28 / 28)
	for (x21 = x22, x21_p_0 = 0;
		x21 < x22 + 28;
		x21 += 28, x21_p_0 += 28){
		// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
		// T (y, 1) (4 / 4)
		for (y = y15, yp_1 = y15_p_0, yp_0 = 0;
			y < y15 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
			// T (x, 4) (28 / 7)
			for (x20 = x21, x20_p_1 = x21_p_0, x20_p_0 = 0;
				x20 < x21 + 28;
				x20 += 7, x20_p_1 += 7, x20_p_0 += 7){
				// y = 4, x = 7, h = 1, w = 1, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f10, fp_0 = 0;
					f < f10 + 128;
					f += 32, fp_0 += 32){
					// y = 4, x = 7, h = 1, w = 1, c = 64, f = 32
					// T (x, 7) (7 / 1)
					for (x = x20, xp_2 = x20_p_1, xp_1 = x20_p_0, xp_0 = 0;
						x < x20 + 7;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_80 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_81 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_82 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_83 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_84 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_85 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_86 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_87 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_88 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_89 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_90 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_91 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_92 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_93 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_94 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_95 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c10, cp_0 = 0;
									c < c10 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_80);
									mem_vec_80 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_81);
									mem_vec_81 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_82);
									mem_vec_82 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_83);
									mem_vec_83 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_84);
									mem_vec_84 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_85);
									mem_vec_85 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_86);
									mem_vec_86 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_87);
									mem_vec_87 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_88);
									mem_vec_88 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_89);
									mem_vec_89 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_90);
									mem_vec_90 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_91);
									mem_vec_91 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_92);
									mem_vec_92 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_93);
									mem_vec_93 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_94);
									mem_vec_94 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_95);
									mem_vec_95 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_80);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_81);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_82);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_83);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_84);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_85);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_86);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_87);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_88);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_89);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_90);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_91);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_92);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_93);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_94);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_95);
					}
				}
			}
		}
	}
}


}