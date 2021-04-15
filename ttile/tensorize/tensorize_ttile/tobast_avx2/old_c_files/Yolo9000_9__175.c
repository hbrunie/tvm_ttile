#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (17, x); T (17, y);
  T (1, f); T (1, f); T (256, c); T (4, x); T (4, f)]
*/
IND_TYPE c, cp_0, c564_p_0, cp_1, c564, f, fp_0, f752_p_0, f753_p_0, fp_1, f752_p_1, fp_2, f752, f753, x, xp_0, x564_p_0, xp_1, x564, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y376 = 0;
IND_TYPE x565 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c565 = 0;
IND_TYPE f754 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3008 ,mem_vec_3009 ,mem_vec_3010 ,mem_vec_3011 ,mem_vec_3012 ,mem_vec_3013 ,mem_vec_3014 ,mem_vec_3015 ,mem_vec_3016 ,mem_vec_3017 ,mem_vec_3018 ,mem_vec_3019 ,mem_vec_3020 ,mem_vec_3021 ,mem_vec_3022 ,mem_vec_3023 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 4) (128 / 32)
for (f753 = f754, f753_p_0 = 0;
	f753 < f754 + 128;
	f753 += 32, f753_p_0 += 32){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 32
	// T (x, 4) (68 / 17)
	for (x564 = x565, x564_p_0 = 0;
		x564 < x565 + 68;
		x564 += 17, x564_p_0 += 17){
		// y = 68, x = 17, h = 1, w = 1, c = 256, f = 32
		// T (c, 256) (256 / 1)
		for (c564 = c565, c564_p_0 = 0;
			c564 < c565 + 256;
			c564 += 1, c564_p_0 += 1){
			// y = 68, x = 17, h = 1, w = 1, c = 1, f = 32
			// T (f, 1) (32 / 32)
			for (f752 = f753, f752_p_1 = f753_p_0, f752_p_0 = 0;
				f752 < f753 + 32;
				f752 += 32, f752_p_1 += 32, f752_p_0 += 32){
				// y = 68, x = 17, h = 1, w = 1, c = 1, f = 32
				// T (f, 1) (32 / 32)
				for (f = f752, fp_2 = f752_p_1, fp_1 = f752_p_0, fp_0 = 0;
					f < f752 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 17, h = 1, w = 1, c = 1, f = 32
					// T (y, 17) (68 / 4)
					for (y = y376, yp_0 = 0;
						y < y376 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x564, xp_1 = x564_p_0, xp_0 = 0;
							x < x564 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_3008 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3009 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_3010 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3011 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_3012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_3014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_3016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_3018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_3020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_3022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c564, cp_1 = c564_p_0, cp_0 = 0;
										c < c564 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3008);
										mem_vec_3008 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3009);
										mem_vec_3009 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3010);
										mem_vec_3010 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3011);
										mem_vec_3011 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3012);
										mem_vec_3012 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3013);
										mem_vec_3013 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3014);
										mem_vec_3014 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3015);
										mem_vec_3015 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3016);
										mem_vec_3016 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3017);
										mem_vec_3017 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3018);
										mem_vec_3018 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3019);
										mem_vec_3019 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3020);
										mem_vec_3020 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3021);
										mem_vec_3021 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3022);
										mem_vec_3022 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3023);
										mem_vec_3023 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3008);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3009);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3010);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3011);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3012);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3013);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3014);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3015);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3016);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3017);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3018);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3019);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3020);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3021);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3022);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3023);
						}
					}
				}
			}
		}
	}
}


}