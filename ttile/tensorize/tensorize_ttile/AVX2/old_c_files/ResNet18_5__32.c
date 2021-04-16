#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (28, x); T (4, f);
  T (1, x); T (1, y); T (1, x); T (7, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x4_p_0, x5_p_0, xp_1, x4_p_1, xp_2, x4, x5, y, yp_0, y3_p_0, yp_1, y3;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y4 = 0;
IND_TYPE x6 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c2 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_30 ,mem_vec_31 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 7) (28 / 4)
for (y3 = y4, y3_p_0 = 0;
	y3 < y4 + 28;
	y3 += 4, y3_p_0 += 4){
	// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (x, 1) (28 / 28)
	for (x5 = x6, x5_p_0 = 0;
		x5 < x6 + 28;
		x5 += 28, x5_p_0 += 28){
		// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
		// T (y, 1) (4 / 4)
		for (y = y3, yp_1 = y3_p_0, yp_0 = 0;
			y < y3 + 4;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
			// T (x, 1) (28 / 28)
			for (x4 = x5, x4_p_1 = x5_p_0, x4_p_0 = 0;
				x4 < x5 + 28;
				x4 += 28, x4_p_1 += 28, x4_p_0 += 28){
				// y = 4, x = 28, h = 1, w = 1, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f2, fp_0 = 0;
					f < f2 + 128;
					f += 32, fp_0 += 32){
					// y = 4, x = 28, h = 1, w = 1, c = 64, f = 32
					// T (x, 28) (28 / 1)
					for (x = x4, xp_2 = x4_p_1, xp_1 = x4_p_0, xp_0 = 0;
						x < x4 + 28;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_16 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_17 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_18 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_19 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_20 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_21 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_22 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_23 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_24 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_25 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_26 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_27 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_28 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_29 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_30 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_31 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (c, 64) (64 / 1)
								for (c = c2, cp_0 = 0;
									c < c2 + 64;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_16);
									mem_vec_16 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_17);
									mem_vec_17 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_18);
									mem_vec_18 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_19);
									mem_vec_19 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_20);
									mem_vec_20 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_21);
									mem_vec_21 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_22);
									mem_vec_22 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_23);
									mem_vec_23 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_24);
									mem_vec_24 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_25);
									mem_vec_25 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_26);
									mem_vec_26 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_27);
									mem_vec_27 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_28);
									mem_vec_28 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_29);
									mem_vec_29 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_30);
									mem_vec_30 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_31);
									mem_vec_31 = vec_23;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_17);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_18);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_19);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_20);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_21);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_22);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_23);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_24);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_25);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_26);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_27);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_28);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_29);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_30);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_31);
					}
				}
			}
		}
	}
}


}