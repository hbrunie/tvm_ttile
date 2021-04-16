#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (2, f); T (8, c); T (4, f); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c450_p_0, cp_1, c450, f, fp_0, f446_p_0, f447_p_0, fp_1, f446_p_1, fp_2, f446, f447, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y228_p_0, yp_1, y228;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y229 = 0;
IND_TYPE x226 = 0;
IND_TYPE h164 = 0;
IND_TYPE w177 = 0;
IND_TYPE c451 = 0;
IND_TYPE f448 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2984 ,mem_vec_2985 ,mem_vec_2986 ,mem_vec_2987 ,mem_vec_2988 ,mem_vec_2989 ,mem_vec_2990 ,mem_vec_2991 ,mem_vec_2992 ,mem_vec_2993 ,mem_vec_2994 ,mem_vec_2995 ,mem_vec_2996 ,mem_vec_2997 ,mem_vec_2998 ,mem_vec_2999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f447 = f448, f447_p_0 = 0;
	f447 < f448 + 256;
	f447 += 256, f447_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (y, 1) (28 / 28)
	for (y228 = y229, y228_p_0 = 0;
		y228 < y229 + 28;
		y228 += 28, y228_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 4) (256 / 64)
		for (f446 = f447, f446_p_1 = f447_p_0, f446_p_0 = 0;
			f446 < f447 + 256;
			f446 += 64, f446_p_1 += 64, f446_p_0 += 64){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
			// T (c, 8) (256 / 32)
			for (c450 = c451, c450_p_0 = 0;
				c450 < c451 + 256;
				c450 += 32, c450_p_0 += 32){
				// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f446, fp_2 = f446_p_1, fp_1 = f446_p_0, fp_0 = 0;
					f < f446 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (y, 7) (28 / 4)
					for (y = y228, yp_1 = y228_p_0, yp_0 = 0;
						y < y228 + 28;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x226, xp_0 = 0;
							x < x226 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h164, hp_0 = 0;
								h < h164 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w177, wp_0 = 0;
									w < w177 + 3;
									w += 1, wp_0 += 1){
											mem_vec_2984 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2985 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2986 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2987 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c450, cp_1 = c450_p_0, cp_0 = 0;
												c < c450 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2984);
												mem_vec_2984 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2985);
												mem_vec_2985 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2986);
												mem_vec_2986 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2987);
												mem_vec_2987 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2988);
												mem_vec_2988 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2989);
												mem_vec_2989 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2990);
												mem_vec_2990 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2991);
												mem_vec_2991 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2992);
												mem_vec_2992 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2993);
												mem_vec_2993 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2994);
												mem_vec_2994 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2995);
												mem_vec_2995 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2996);
												mem_vec_2996 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2997);
												mem_vec_2997 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2998);
												mem_vec_2998 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2999);
												mem_vec_2999 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2984);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2985);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2986);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2987);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2988);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2989);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2990);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2991);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2992);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2993);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2994);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2995);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2996);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2997);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2998);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2999);
								}
							}
						}
					}
				}
			}
		}
	}
}


}