#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (4, x); T (17, y);
  T (2, f); T (2, f); T (256, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, f1016_p_0, f1017_p_0, fp_1, f1016_p_1, fp_2, f1016, f1017, x, xp_0, x762_p_0, xp_1, x762, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y508 = 0;
IND_TYPE x763 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c763 = 0;
IND_TYPE f1018 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4064 ,mem_vec_4065 ,mem_vec_4066 ,mem_vec_4067 ,mem_vec_4068 ,mem_vec_4069 ,mem_vec_4070 ,mem_vec_4071 ,mem_vec_4072 ,mem_vec_4073 ,mem_vec_4074 ,mem_vec_4075 ,mem_vec_4076 ,mem_vec_4077 ,mem_vec_4078 ,mem_vec_4079 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 1) (128 / 128)
for (f1017 = f1018, f1017_p_0 = 0;
	f1017 < f1018 + 128;
	f1017 += 128, f1017_p_0 += 128){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 17) (68 / 4)
	for (x762 = x763, x762_p_0 = 0;
		x762 < x763 + 68;
		x762 += 4, x762_p_0 += 4){
		// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
		// T (c, 256) (256 / 1)
		for (c762 = c763, c762_p_0 = 0;
			c762 < c763 + 256;
			c762 += 1, c762_p_0 += 1){
			// y = 68, x = 4, h = 1, w = 1, c = 1, f = 128
			// T (f, 2) (128 / 64)
			for (f1016 = f1017, f1016_p_1 = f1017_p_0, f1016_p_0 = 0;
				f1016 < f1017 + 128;
				f1016 += 64, f1016_p_1 += 64, f1016_p_0 += 64){
				// y = 68, x = 4, h = 1, w = 1, c = 1, f = 64
				// T (f, 2) (64 / 32)
				for (f = f1016, fp_2 = f1016_p_1, fp_1 = f1016_p_0, fp_0 = 0;
					f < f1016 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 4, h = 1, w = 1, c = 1, f = 32
					// T (y, 17) (68 / 4)
					for (y = y508, yp_0 = 0;
						y < y508 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 1, f = 32
						// T (x, 4) (4 / 1)
						for (x = x762, xp_1 = x762_p_0, xp_0 = 0;
							x < x762 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_4064 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4065 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_4066 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4067 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_4068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_4070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_4072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_4074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_4076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_4078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
										c < c762 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4064);
										mem_vec_4064 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4065);
										mem_vec_4065 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4066);
										mem_vec_4066 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4067);
										mem_vec_4067 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4068);
										mem_vec_4068 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4069);
										mem_vec_4069 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4070);
										mem_vec_4070 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4071);
										mem_vec_4071 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4072);
										mem_vec_4072 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4073);
										mem_vec_4073 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4074);
										mem_vec_4074 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4075);
										mem_vec_4075 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4076);
										mem_vec_4076 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4077);
										mem_vec_4077 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4078);
										mem_vec_4078 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4079);
										mem_vec_4079 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4064);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4065);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4066);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4067);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4068);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4069);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4070);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4071);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4072);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4073);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4074);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4075);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4076);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4077);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4078);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4079);
						}
					}
				}
			}
		}
	}
}


}