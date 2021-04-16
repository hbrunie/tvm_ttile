#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (16, c);
  T (4, f); T (34, x); T (17, y)]
*/
IND_TYPE c, cp_0, c114_p_0, cp_1, c114, f, fp_0, x, xp_0, x114_p_0, xp_1, x114, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y76 = 0;
IND_TYPE x115 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c115 = 0;
IND_TYPE f76 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 17) (68 / 4)
for (y = y76, yp_0 = 0;
	y < y76 + 68;
	y += 4, yp_0 += 4){
	// y = 4, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 34) (68 / 2)
	for (x114 = x115, x114_p_0 = 0;
		x114 < x115 + 68;
		x114 += 2, x114_p_0 += 2){
		// y = 4, x = 2, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f76, fp_0 = 0;
			f < f76 + 128;
			f += 32, fp_0 += 32){
			// y = 4, x = 2, h = 1, w = 1, c = 256, f = 32
			// T (c, 16) (256 / 16)
			for (c114 = c115, c114_p_0 = 0;
				c114 < c115 + 256;
				c114 += 16, c114_p_0 += 16){
				// y = 4, x = 2, h = 1, w = 1, c = 16, f = 32
				// T (x, 2) (2 / 1)
				for (x = x114, xp_1 = x114_p_0, xp_0 = 0;
					x < x114 + 2;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_608 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_609 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
							mem_vec_610 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_611 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
							mem_vec_612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
							mem_vec_614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
							mem_vec_616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
							mem_vec_618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
							mem_vec_620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
							mem_vec_622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
							// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
							// T (c, 16) (16 / 1)
							for (c = c114, cp_1 = c114_p_0, cp_0 = 0;
								c < c114 + 16;
								c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm256_set1_ps(scal_0);
								vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_608);
								mem_vec_608 = vec_0;

								vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

								vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_609);
								mem_vec_609 = vec_3;

								vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_610);
								mem_vec_610 = vec_5;

								vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

								vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_611);
								mem_vec_611 = vec_7;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_10 = _mm256_set1_ps(scal_1);


								vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_612);
								mem_vec_612 = vec_9;



								vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_613);
								mem_vec_613 = vec_11;



								vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_614);
								mem_vec_614 = vec_12;



								vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_615);
								mem_vec_615 = vec_13;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_15 = _mm256_set1_ps(scal_2);


								vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_616);
								mem_vec_616 = vec_14;



								vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_617);
								mem_vec_617 = vec_16;



								vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_618);
								mem_vec_618 = vec_17;



								vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_619);
								mem_vec_619 = vec_18;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_20 = _mm256_set1_ps(scal_3);


								vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_620);
								mem_vec_620 = vec_19;



								vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_621);
								mem_vec_621 = vec_21;



								vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_622);
								mem_vec_622 = vec_22;



								vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_623);
								mem_vec_623 = vec_23;
							}
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_609);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_610);
						_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_611);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_612);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_613);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_614);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_615);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_616);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_617);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_618);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_619);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_620);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_621);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_622);
						_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_623);
				}
			}
		}
	}
}


}