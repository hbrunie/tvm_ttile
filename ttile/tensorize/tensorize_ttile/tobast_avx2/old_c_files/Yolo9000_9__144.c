#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (68, x); T (17, y);
  T (4, f); T (1, f); T (64, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, f, fp_0, f160_p_0, f161_p_0, fp_1, f160_p_1, fp_2, f160, f161, x, xp_0, x120_p_0, xp_1, x120, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y80 = 0;
IND_TYPE x121 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c121 = 0;
IND_TYPE f162 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 1) (128 / 128)
for (f161 = f162, f161_p_0 = 0;
	f161 < f162 + 128;
	f161 += 128, f161_p_0 += 128){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x120 = x121, x120_p_0 = 0;
		x120 < x121 + 68;
		x120 += 68, x120_p_0 += 68){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (c, 64) (256 / 4)
		for (c120 = c121, c120_p_0 = 0;
			c120 < c121 + 256;
			c120 += 4, c120_p_0 += 4){
			// y = 68, x = 68, h = 1, w = 1, c = 4, f = 128
			// T (f, 1) (128 / 128)
			for (f160 = f161, f160_p_1 = f161_p_0, f160_p_0 = 0;
				f160 < f161 + 128;
				f160 += 128, f160_p_1 += 128, f160_p_0 += 128){
				// y = 68, x = 68, h = 1, w = 1, c = 4, f = 128
				// T (f, 4) (128 / 32)
				for (f = f160, fp_2 = f160_p_1, fp_1 = f160_p_0, fp_0 = 0;
					f < f160 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (y, 17) (68 / 4)
					for (y = y80, yp_0 = 0;
						y < y80 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 68, h = 1, w = 1, c = 4, f = 32
						// T (x, 68) (68 / 1)
						for (x = x120, xp_1 = x120_p_0, xp_0 = 0;
							x < x120 + 68;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_640 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_641 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_642 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_643 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_640);
										mem_vec_640 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_641);
										mem_vec_641 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_642);
										mem_vec_642 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_643);
										mem_vec_643 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_644);
										mem_vec_644 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_645);
										mem_vec_645 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_646);
										mem_vec_646 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_647);
										mem_vec_647 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_648);
										mem_vec_648 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_649);
										mem_vec_649 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_650);
										mem_vec_650 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_651);
										mem_vec_651 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_652);
										mem_vec_652 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_653);
										mem_vec_653 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_654);
										mem_vec_654 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_655);
										mem_vec_655 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_640);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_641);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_642);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_643);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_644);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_645);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_646);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_647);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_648);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_649);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_650);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_651);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_652);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_653);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_654);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_655);
						}
					}
				}
			}
		}
	}
}


}