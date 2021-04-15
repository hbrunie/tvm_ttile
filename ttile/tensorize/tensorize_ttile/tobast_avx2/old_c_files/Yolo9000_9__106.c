#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (2, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (2, f); T (1, f); T (128, c); T (68, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1164_p_0, cp_1, c1164, f, fp_0, f1552_p_0, f1553_p_0, fp_1, f1552_p_1, fp_2, f1552, f1553, x, xp_0, x1164_p_0, xp_1, x1164, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y776 = 0;
IND_TYPE x1165 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1165 = 0;
IND_TYPE f1554 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_6208 ,mem_vec_6209 ,mem_vec_6210 ,mem_vec_6211 ,mem_vec_6212 ,mem_vec_6213 ,mem_vec_6214 ,mem_vec_6215 ,mem_vec_6216 ,mem_vec_6217 ,mem_vec_6218 ,mem_vec_6219 ,mem_vec_6220 ,mem_vec_6221 ,mem_vec_6222 ,mem_vec_6223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 2) (128 / 64)
for (f1553 = f1554, f1553_p_0 = 0;
	f1553 < f1554 + 128;
	f1553 += 64, f1553_p_0 += 64){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 64
	// T (x, 68) (68 / 1)
	for (x1164 = x1165, x1164_p_0 = 0;
		x1164 < x1165 + 68;
		x1164 += 1, x1164_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 256, f = 64
		// T (c, 128) (256 / 2)
		for (c1164 = c1165, c1164_p_0 = 0;
			c1164 < c1165 + 256;
			c1164 += 2, c1164_p_0 += 2){
			// y = 68, x = 1, h = 1, w = 1, c = 2, f = 64
			// T (f, 1) (64 / 64)
			for (f1552 = f1553, f1552_p_1 = f1553_p_0, f1552_p_0 = 0;
				f1552 < f1553 + 64;
				f1552 += 64, f1552_p_1 += 64, f1552_p_0 += 64){
				// y = 68, x = 1, h = 1, w = 1, c = 2, f = 64
				// T (f, 2) (64 / 32)
				for (f = f1552, fp_2 = f1552_p_1, fp_1 = f1552_p_0, fp_0 = 0;
					f < f1552 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 2, f = 32
					// T (y, 17) (68 / 4)
					for (y = y776, yp_0 = 0;
						y < y776 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1164, xp_1 = x1164_p_0, xp_0 = 0;
							x < x1164 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_6208 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6209 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_6210 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6211 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_6212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_6214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_6216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_6218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_6220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_6222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
										c < c1164 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6208);
										mem_vec_6208 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6209);
										mem_vec_6209 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6210);
										mem_vec_6210 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6211);
										mem_vec_6211 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6212);
										mem_vec_6212 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6213);
										mem_vec_6213 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6214);
										mem_vec_6214 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6215);
										mem_vec_6215 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6216);
										mem_vec_6216 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6217);
										mem_vec_6217 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6218);
										mem_vec_6218 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6219);
										mem_vec_6219 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6220);
										mem_vec_6220 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6221);
										mem_vec_6221 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6222);
										mem_vec_6222 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6223);
										mem_vec_6223 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6208);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6209);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6210);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6211);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6212);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6213);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6214);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6215);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6216);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6217);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6218);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6219);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6220);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6221);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6222);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6223);
						}
					}
				}
			}
		}
	}
}


}