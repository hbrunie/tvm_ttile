#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (68, x); T (17, y);
  T (2, f); T (1, f); T (64, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, f184_p_0, f185_p_0, fp_1, f184_p_1, fp_2, f184, f185, x, xp_0, x138_p_0, xp_1, x138, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y92 = 0;
IND_TYPE x139 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f186 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 2) (128 / 64)
for (f185 = f186, f185_p_0 = 0;
	f185 < f186 + 128;
	f185 += 64, f185_p_0 += 64){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 64
	// T (x, 1) (68 / 68)
	for (x138 = x139, x138_p_0 = 0;
		x138 < x139 + 68;
		x138 += 68, x138_p_0 += 68){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 64
		// T (c, 64) (256 / 4)
		for (c138 = c139, c138_p_0 = 0;
			c138 < c139 + 256;
			c138 += 4, c138_p_0 += 4){
			// y = 68, x = 68, h = 1, w = 1, c = 4, f = 64
			// T (f, 1) (64 / 64)
			for (f184 = f185, f184_p_1 = f185_p_0, f184_p_0 = 0;
				f184 < f185 + 64;
				f184 += 64, f184_p_1 += 64, f184_p_0 += 64){
				// y = 68, x = 68, h = 1, w = 1, c = 4, f = 64
				// T (f, 2) (64 / 32)
				for (f = f184, fp_2 = f184_p_1, fp_1 = f184_p_0, fp_0 = 0;
					f < f184 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (y, 17) (68 / 4)
					for (y = y92, yp_0 = 0;
						y < y92 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 68, h = 1, w = 1, c = 4, f = 32
						// T (x, 68) (68 / 1)
						for (x = x138, xp_1 = x138_p_0, xp_0 = 0;
							x < x138 + 68;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_736 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_737 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_738 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_739 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
										c < c138 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_736);
										mem_vec_736 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_737);
										mem_vec_737 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_738);
										mem_vec_738 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_739);
										mem_vec_739 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_740);
										mem_vec_740 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_741);
										mem_vec_741 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_742);
										mem_vec_742 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_743);
										mem_vec_743 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_744);
										mem_vec_744 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_745);
										mem_vec_745 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_746);
										mem_vec_746 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_747);
										mem_vec_747 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_748);
										mem_vec_748 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_749);
										mem_vec_749 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_750);
										mem_vec_750 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_751);
										mem_vec_751 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_736);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_737);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_738);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_739);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_740);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_741);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_742);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_743);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_744);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_745);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_746);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_747);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_748);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_749);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_750);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_751);
						}
					}
				}
			}
		}
	}
}


}