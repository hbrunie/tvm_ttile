#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (68, x); T (17, y);
  T (1, f); T (1, f); T (128, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c162_p_0, cp_1, c162, f, fp_0, f216_p_0, f217_p_0, fp_1, f216_p_1, fp_2, f216, f217, x, xp_0, x162_p_0, xp_1, x162, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y108 = 0;
IND_TYPE x163 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c163 = 0;
IND_TYPE f218 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 4) (128 / 32)
for (f217 = f218, f217_p_0 = 0;
	f217 < f218 + 128;
	f217 += 32, f217_p_0 += 32){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 32
	// T (x, 1) (68 / 68)
	for (x162 = x163, x162_p_0 = 0;
		x162 < x163 + 68;
		x162 += 68, x162_p_0 += 68){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 32
		// T (c, 128) (256 / 2)
		for (c162 = c163, c162_p_0 = 0;
			c162 < c163 + 256;
			c162 += 2, c162_p_0 += 2){
			// y = 68, x = 68, h = 1, w = 1, c = 2, f = 32
			// T (f, 1) (32 / 32)
			for (f216 = f217, f216_p_1 = f217_p_0, f216_p_0 = 0;
				f216 < f217 + 32;
				f216 += 32, f216_p_1 += 32, f216_p_0 += 32){
				// y = 68, x = 68, h = 1, w = 1, c = 2, f = 32
				// T (f, 1) (32 / 32)
				for (f = f216, fp_2 = f216_p_1, fp_1 = f216_p_0, fp_0 = 0;
					f < f216 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 68, h = 1, w = 1, c = 2, f = 32
					// T (y, 17) (68 / 4)
					for (y = y108, yp_0 = 0;
						y < y108 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 68, h = 1, w = 1, c = 2, f = 32
						// T (x, 68) (68 / 1)
						for (x = x162, xp_1 = x162_p_0, xp_0 = 0;
							x < x162 + 68;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_864 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_865 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_866 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_867 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c162, cp_1 = c162_p_0, cp_0 = 0;
										c < c162 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_864);
										mem_vec_864 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_865);
										mem_vec_865 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_866);
										mem_vec_866 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_867);
										mem_vec_867 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_868);
										mem_vec_868 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_869);
										mem_vec_869 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_870);
										mem_vec_870 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_871);
										mem_vec_871 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_872);
										mem_vec_872 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_873);
										mem_vec_873 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_874);
										mem_vec_874 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_875);
										mem_vec_875 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_876);
										mem_vec_876 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_877);
										mem_vec_877 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_878);
										mem_vec_878 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_879);
										mem_vec_879 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_865);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_866);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_867);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_868);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_869);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_870);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_871);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_872);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_873);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_874);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_875);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_876);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_877);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_878);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_879);
						}
					}
				}
			}
		}
	}
}


}