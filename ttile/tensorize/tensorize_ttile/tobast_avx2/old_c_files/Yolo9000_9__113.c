#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (1, f); T (1, f); T (4, c); T (68, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1062_p_0, cp_1, c1062, f, fp_0, f1416_p_0, f1417_p_0, fp_1, f1416_p_1, fp_2, f1416, f1417, x, xp_0, x1062_p_0, xp_1, x1062, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y708 = 0;
IND_TYPE x1063 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1063 = 0;
IND_TYPE f1418 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5664 ,mem_vec_5665 ,mem_vec_5666 ,mem_vec_5667 ,mem_vec_5668 ,mem_vec_5669 ,mem_vec_5670 ,mem_vec_5671 ,mem_vec_5672 ,mem_vec_5673 ,mem_vec_5674 ,mem_vec_5675 ,mem_vec_5676 ,mem_vec_5677 ,mem_vec_5678 ,mem_vec_5679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 4) (128 / 32)
for (f1417 = f1418, f1417_p_0 = 0;
	f1417 < f1418 + 128;
	f1417 += 32, f1417_p_0 += 32){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 32
	// T (x, 68) (68 / 1)
	for (x1062 = x1063, x1062_p_0 = 0;
		x1062 < x1063 + 68;
		x1062 += 1, x1062_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 256, f = 32
		// T (c, 4) (256 / 64)
		for (c1062 = c1063, c1062_p_0 = 0;
			c1062 < c1063 + 256;
			c1062 += 64, c1062_p_0 += 64){
			// y = 68, x = 1, h = 1, w = 1, c = 64, f = 32
			// T (f, 1) (32 / 32)
			for (f1416 = f1417, f1416_p_1 = f1417_p_0, f1416_p_0 = 0;
				f1416 < f1417 + 32;
				f1416 += 32, f1416_p_1 += 32, f1416_p_0 += 32){
				// y = 68, x = 1, h = 1, w = 1, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1416, fp_2 = f1416_p_1, fp_1 = f1416_p_0, fp_0 = 0;
					f < f1416 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 17) (68 / 4)
					for (y = y708, yp_0 = 0;
						y < y708 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1062, xp_1 = x1062_p_0, xp_0 = 0;
							x < x1062 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_5664 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_5665 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_5666 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_5667 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_5668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_5669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_5670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_5671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_5672 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_5673 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_5674 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_5675 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_5676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_5677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_5678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_5679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;
										c < c1062 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5664);
										mem_vec_5664 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5665);
										mem_vec_5665 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5666);
										mem_vec_5666 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5667);
										mem_vec_5667 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5668);
										mem_vec_5668 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5669);
										mem_vec_5669 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5670);
										mem_vec_5670 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5671);
										mem_vec_5671 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5672);
										mem_vec_5672 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5673);
										mem_vec_5673 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5674);
										mem_vec_5674 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5675);
										mem_vec_5675 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5676);
										mem_vec_5676 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5677);
										mem_vec_5677 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5678);
										mem_vec_5678 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5679);
										mem_vec_5679 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5664);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5665);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5666);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5667);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5668);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5669);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5670);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5671);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5672);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5673);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5674);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5675);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5676);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5677);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5678);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5679);
						}
					}
				}
			}
		}
	}
}


}