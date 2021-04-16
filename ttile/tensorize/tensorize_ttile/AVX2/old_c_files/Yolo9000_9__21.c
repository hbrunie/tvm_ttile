#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (4, f); T (4, x); T (17, y)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, x, xp_0, x9_p_0, xp_1, x9, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y6 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f6 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 17) (68 / 4)
for (y = y6, yp_0 = 0;
	y < y6 + 68;
	y += 4, yp_0 += 4){
	// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 4) (68 / 17)
	for (x9 = x10, x9_p_0 = 0;
		x9 < x10 + 68;
		x9 += 17, x9_p_0 += 17){
		// y = 4, x = 17, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f6, fp_0 = 0;
			f < f6 + 128;
			f += 32, fp_0 += 32){
			// y = 4, x = 17, h = 1, w = 1, c = 256, f = 32
			// T (c, 8) (256 / 32)
			for (c9 = c10, c9_p_0 = 0;
				c9 < c10 + 256;
				c9 += 32, c9_p_0 += 32){
				// y = 4, x = 17, h = 1, w = 1, c = 32, f = 32
				// T (x, 17) (17 / 1)
				for (x = x9, xp_1 = x9_p_0, xp_0 = 0;
					x < x9 + 17;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_48 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_49 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
							mem_vec_50 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_51 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
							mem_vec_52 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_53 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
							mem_vec_54 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_55 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
							mem_vec_56 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_57 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
							mem_vec_58 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_59 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
							mem_vec_60 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_61 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
							mem_vec_62 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_63 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
							// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
							// T (c, 32) (32 / 1)
							for (c = c9, cp_1 = c9_p_0, cp_0 = 0;
								c < c9 + 32;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm256_set1_ps(scal_0);
								vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_48);
								mem_vec_48 = vec_0;

								vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

								vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_49);
								mem_vec_49 = vec_3;

								vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_50);
								mem_vec_50 = vec_5;

								vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

								vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_51);
								mem_vec_51 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm256_set1_ps(scal_1);


								vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_52);
								mem_vec_52 = vec_9;



								vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_53);
								mem_vec_53 = vec_11;



								vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_54);
								mem_vec_54 = vec_12;



								vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_55);
								mem_vec_55 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm256_set1_ps(scal_2);


								vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_56);
								mem_vec_56 = vec_14;



								vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_57);
								mem_vec_57 = vec_16;



								vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_58);
								mem_vec_58 = vec_17;



								vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_59);
								mem_vec_59 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm256_set1_ps(scal_3);


								vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_60);
								mem_vec_60 = vec_19;



								vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_61);
								mem_vec_61 = vec_21;



								vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_62);
								mem_vec_62 = vec_22;



								vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_63);
								mem_vec_63 = vec_23;
							}
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_48);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_49);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_50);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_51);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_52);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_53);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_54);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_55);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_56);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_57);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_58);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_59);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_60);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_61);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_62);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_63);
				}
			}
		}
	}
}


}