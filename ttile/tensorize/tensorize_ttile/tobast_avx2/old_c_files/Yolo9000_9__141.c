#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (1, f); T (1, f); T (8, c); T (68, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1080_p_0, cp_1, c1080, f, fp_0, f1440_p_0, f1441_p_0, fp_1, f1440_p_1, fp_2, f1440, f1441, x, xp_0, x1080_p_0, xp_1, x1080, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y720 = 0;
IND_TYPE x1081 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1081 = 0;
IND_TYPE f1442 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5760 ,mem_vec_5761 ,mem_vec_5762 ,mem_vec_5763 ,mem_vec_5764 ,mem_vec_5765 ,mem_vec_5766 ,mem_vec_5767 ,mem_vec_5768 ,mem_vec_5769 ,mem_vec_5770 ,mem_vec_5771 ,mem_vec_5772 ,mem_vec_5773 ,mem_vec_5774 ,mem_vec_5775 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 4) (128 / 32)
for (f1441 = f1442, f1441_p_0 = 0;
	f1441 < f1442 + 128;
	f1441 += 32, f1441_p_0 += 32){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 32
	// T (x, 68) (68 / 1)
	for (x1080 = x1081, x1080_p_0 = 0;
		x1080 < x1081 + 68;
		x1080 += 1, x1080_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 256, f = 32
		// T (c, 8) (256 / 32)
		for (c1080 = c1081, c1080_p_0 = 0;
			c1080 < c1081 + 256;
			c1080 += 32, c1080_p_0 += 32){
			// y = 68, x = 1, h = 1, w = 1, c = 32, f = 32
			// T (f, 1) (32 / 32)
			for (f1440 = f1441, f1440_p_1 = f1441_p_0, f1440_p_0 = 0;
				f1440 < f1441 + 32;
				f1440 += 32, f1440_p_1 += 32, f1440_p_0 += 32){
				// y = 68, x = 1, h = 1, w = 1, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1440, fp_2 = f1440_p_1, fp_1 = f1440_p_0, fp_0 = 0;
					f < f1440 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 32, f = 32
					// T (y, 17) (68 / 4)
					for (y = y720, yp_0 = 0;
						y < y720 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1080, xp_1 = x1080_p_0, xp_0 = 0;
							x < x1080 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_5760 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5761 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_5762 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5763 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_5764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_5766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_5768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_5770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_5772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_5774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c1080, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5760);
										mem_vec_5760 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5761);
										mem_vec_5761 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5762);
										mem_vec_5762 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5763);
										mem_vec_5763 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5764);
										mem_vec_5764 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5765);
										mem_vec_5765 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5766);
										mem_vec_5766 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5767);
										mem_vec_5767 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5768);
										mem_vec_5768 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5769);
										mem_vec_5769 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5770);
										mem_vec_5770 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5771);
										mem_vec_5771 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5772);
										mem_vec_5772 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5773);
										mem_vec_5773 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5774);
										mem_vec_5774 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5775);
										mem_vec_5775 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5760);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5761);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5762);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5763);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5764);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5765);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5766);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5767);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5768);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5769);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5770);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5771);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5772);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5773);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5774);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5775);
						}
					}
				}
			}
		}
	}
}


}