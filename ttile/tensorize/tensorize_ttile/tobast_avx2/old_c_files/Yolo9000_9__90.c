#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (2, x); T (17, y);
  T (4, f); T (1, f); T (256, c); T (34, x); T (1, f)]
*/
IND_TYPE c, cp_0, c960_p_0, cp_1, c960, f, fp_0, f1280_p_0, f1281_p_0, fp_1, f1280_p_1, fp_2, f1280, f1281, x, xp_0, x960_p_0, xp_1, x960, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y640 = 0;
IND_TYPE x961 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c961 = 0;
IND_TYPE f1282 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5120 ,mem_vec_5121 ,mem_vec_5122 ,mem_vec_5123 ,mem_vec_5124 ,mem_vec_5125 ,mem_vec_5126 ,mem_vec_5127 ,mem_vec_5128 ,mem_vec_5129 ,mem_vec_5130 ,mem_vec_5131 ,mem_vec_5132 ,mem_vec_5133 ,mem_vec_5134 ,mem_vec_5135 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 1) (128 / 128)
for (f1281 = f1282, f1281_p_0 = 0;
	f1281 < f1282 + 128;
	f1281 += 128, f1281_p_0 += 128){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 34) (68 / 2)
	for (x960 = x961, x960_p_0 = 0;
		x960 < x961 + 68;
		x960 += 2, x960_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
		// T (c, 256) (256 / 1)
		for (c960 = c961, c960_p_0 = 0;
			c960 < c961 + 256;
			c960 += 1, c960_p_0 += 1){
			// y = 68, x = 2, h = 1, w = 1, c = 1, f = 128
			// T (f, 1) (128 / 128)
			for (f1280 = f1281, f1280_p_1 = f1281_p_0, f1280_p_0 = 0;
				f1280 < f1281 + 128;
				f1280 += 128, f1280_p_1 += 128, f1280_p_0 += 128){
				// y = 68, x = 2, h = 1, w = 1, c = 1, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
					f < f1280 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 2, h = 1, w = 1, c = 1, f = 32
					// T (y, 17) (68 / 4)
					for (y = y640, yp_0 = 0;
						y < y640 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 2, h = 1, w = 1, c = 1, f = 32
						// T (x, 2) (2 / 1)
						for (x = x960, xp_1 = x960_p_0, xp_0 = 0;
							x < x960 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_5120 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5121 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_5122 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5123 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_5124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_5126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_5128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_5130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_5132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_5134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
										c < c960 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5120);
										mem_vec_5120 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5121);
										mem_vec_5121 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5122);
										mem_vec_5122 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5123);
										mem_vec_5123 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5124);
										mem_vec_5124 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5125);
										mem_vec_5125 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5126);
										mem_vec_5126 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5127);
										mem_vec_5127 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5128);
										mem_vec_5128 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5129);
										mem_vec_5129 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5130);
										mem_vec_5130 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5131);
										mem_vec_5131 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5132);
										mem_vec_5132 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5133);
										mem_vec_5133 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5134);
										mem_vec_5134 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5135);
										mem_vec_5135 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5120);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5121);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5122);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5123);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5124);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5125);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5126);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5127);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5128);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5129);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5130);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5131);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5132);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5133);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5134);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5135);
						}
					}
				}
			}
		}
	}
}


}