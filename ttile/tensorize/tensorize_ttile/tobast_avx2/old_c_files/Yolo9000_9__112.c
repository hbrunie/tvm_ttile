#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (1, f); T (2, f); T (256, c); T (68, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1188_p_0, cp_1, c1188, f, fp_0, f1584_p_0, f1585_p_0, fp_1, f1584_p_1, fp_2, f1584, f1585, x, xp_0, x1188_p_0, xp_1, x1188, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y792 = 0;
IND_TYPE x1189 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1189 = 0;
IND_TYPE f1586 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_6336 ,mem_vec_6337 ,mem_vec_6338 ,mem_vec_6339 ,mem_vec_6340 ,mem_vec_6341 ,mem_vec_6342 ,mem_vec_6343 ,mem_vec_6344 ,mem_vec_6345 ,mem_vec_6346 ,mem_vec_6347 ,mem_vec_6348 ,mem_vec_6349 ,mem_vec_6350 ,mem_vec_6351 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 2) (128 / 64)
for (f1585 = f1586, f1585_p_0 = 0;
	f1585 < f1586 + 128;
	f1585 += 64, f1585_p_0 += 64){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 64
	// T (x, 68) (68 / 1)
	for (x1188 = x1189, x1188_p_0 = 0;
		x1188 < x1189 + 68;
		x1188 += 1, x1188_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 256, f = 64
		// T (c, 256) (256 / 1)
		for (c1188 = c1189, c1188_p_0 = 0;
			c1188 < c1189 + 256;
			c1188 += 1, c1188_p_0 += 1){
			// y = 68, x = 1, h = 1, w = 1, c = 1, f = 64
			// T (f, 2) (64 / 32)
			for (f1584 = f1585, f1584_p_1 = f1585_p_0, f1584_p_0 = 0;
				f1584 < f1585 + 64;
				f1584 += 32, f1584_p_1 += 32, f1584_p_0 += 32){
				// y = 68, x = 1, h = 1, w = 1, c = 1, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1584, fp_2 = f1584_p_1, fp_1 = f1584_p_0, fp_0 = 0;
					f < f1584 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 1, f = 32
					// T (y, 17) (68 / 4)
					for (y = y792, yp_0 = 0;
						y < y792 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1188, xp_1 = x1188_p_0, xp_0 = 0;
							x < x1188 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6336 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6337 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_6338 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6339 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_6340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_6344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_6346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_6348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_6350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c1188, cp_1 = c1188_p_0, cp_0 = 0;
										c < c1188 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6336);
										mem_vec_6336 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6337);
										mem_vec_6337 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6338);
										mem_vec_6338 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6339);
										mem_vec_6339 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6340);
										mem_vec_6340 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6341);
										mem_vec_6341 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6342);
										mem_vec_6342 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6343);
										mem_vec_6343 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6344);
										mem_vec_6344 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6345);
										mem_vec_6345 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6346);
										mem_vec_6346 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6347);
										mem_vec_6347 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6348);
										mem_vec_6348 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6349);
										mem_vec_6349 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6350);
										mem_vec_6350 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6351);
										mem_vec_6351 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6336);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6337);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6338);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6339);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6340);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6341);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6342);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6343);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6344);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6345);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6346);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6347);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6348);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6349);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6350);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6351);
						}
					}
				}
			}
		}
	}
}


}