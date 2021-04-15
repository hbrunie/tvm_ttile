#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (1, f); T (2, f); T (128, c); T (68, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1170_p_0, cp_1, c1170, f, fp_0, f1560_p_0, f1561_p_0, fp_1, f1560_p_1, fp_2, f1560, f1561, x, xp_0, x1170_p_0, xp_1, x1170, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y780 = 0;
IND_TYPE x1171 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1171 = 0;
IND_TYPE f1562 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_6240 ,mem_vec_6241 ,mem_vec_6242 ,mem_vec_6243 ,mem_vec_6244 ,mem_vec_6245 ,mem_vec_6246 ,mem_vec_6247 ,mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,mem_vec_6254 ,mem_vec_6255 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 2) (128 / 64)
for (f1561 = f1562, f1561_p_0 = 0;
	f1561 < f1562 + 128;
	f1561 += 64, f1561_p_0 += 64){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 64
	// T (x, 68) (68 / 1)
	for (x1170 = x1171, x1170_p_0 = 0;
		x1170 < x1171 + 68;
		x1170 += 1, x1170_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 256, f = 64
		// T (c, 128) (256 / 2)
		for (c1170 = c1171, c1170_p_0 = 0;
			c1170 < c1171 + 256;
			c1170 += 2, c1170_p_0 += 2){
			// y = 68, x = 1, h = 1, w = 1, c = 2, f = 64
			// T (f, 2) (64 / 32)
			for (f1560 = f1561, f1560_p_1 = f1561_p_0, f1560_p_0 = 0;
				f1560 < f1561 + 64;
				f1560 += 32, f1560_p_1 += 32, f1560_p_0 += 32){
				// y = 68, x = 1, h = 1, w = 1, c = 2, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1560, fp_2 = f1560_p_1, fp_1 = f1560_p_0, fp_0 = 0;
					f < f1560 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 2, f = 32
					// T (y, 17) (68 / 4)
					for (y = y780, yp_0 = 0;
						y < y780 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1170, xp_1 = x1170_p_0, xp_0 = 0;
							x < x1170 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6240 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6241 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_6242 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6243 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_6244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_6248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_6250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_6252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_6254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
										c < c1170 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6240);
										mem_vec_6240 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6241);
										mem_vec_6241 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6242);
										mem_vec_6242 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6243);
										mem_vec_6243 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6244);
										mem_vec_6244 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6245);
										mem_vec_6245 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6246);
										mem_vec_6246 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6247);
										mem_vec_6247 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6248);
										mem_vec_6248 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6249);
										mem_vec_6249 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6250);
										mem_vec_6250 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6251);
										mem_vec_6251 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6252);
										mem_vec_6252 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6253);
										mem_vec_6253 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6254);
										mem_vec_6254 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6255);
										mem_vec_6255 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6240);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6241);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6242);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6243);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6244);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6245);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6246);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6247);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6248);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6249);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6250);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6251);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6252);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6253);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6254);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6255);
						}
					}
				}
			}
		}
	}
}


}