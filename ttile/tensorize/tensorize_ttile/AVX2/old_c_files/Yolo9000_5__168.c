#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (2, x); T (2, y); T (2, f); T (17, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c387_p_0, cp_1, c387, f, fp_0, x, xp_0, x645_p_0, x646_p_0, x647_p_0, xp_1, x645_p_1, x646_p_1, xp_2, x645_p_2, xp_3, x645, x646, x647, y, yp_0, y516_p_0, y517_p_0, yp_1, y516_p_1, yp_2, y516, y517;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y518 = 0;
IND_TYPE x648 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c388 = 0;
IND_TYPE f258 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,mem_vec_3988 ,mem_vec_3989 ,mem_vec_3990 ,mem_vec_3991 ,mem_vec_3992 ,mem_vec_3993 ,mem_vec_3994 ,mem_vec_3995 ,mem_vec_3996 ,mem_vec_3997 ,mem_vec_3998 ,mem_vec_3999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y517 = y518, y517_p_0 = 0;
	y517 < y518 + 136;
	y517 += 8, y517_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x647 = x648, x647_p_0 = 0;
		x647 < x648 + 136;
		x647 += 136, x647_p_0 += 136){
		// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (8 / 8)
		for (y516 = y517, y516_p_1 = y517_p_0, y516_p_0 = 0;
			y516 < y517 + 8;
			y516 += 8, y516_p_1 += 8, y516_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 17) (136 / 8)
			for (x646 = x647, x646_p_1 = x647_p_0, x646_p_0 = 0;
				x646 < x647 + 136;
				x646 += 8, x646_p_1 += 8, x646_p_0 += 8){
				// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f258, fp_0 = 0;
					f < f258 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y516, yp_2 = y516_p_1, yp_1 = y516_p_0, yp_0 = 0;
						y < y516 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 8, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (8 / 4)
						for (x645 = x646, x645_p_2 = x646_p_1, x645_p_1 = x646_p_0, x645_p_0 = 0;
							x645 < x646 + 8;
							x645 += 4, x645_p_2 += 4, x645_p_1 += 4, x645_p_0 += 4){
							// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c387 = c388, c387_p_0 = 0;
								c387 < c388 + 128;
								c387 += 64, c387_p_0 += 64){
								// y = 4, x = 4, h = 1, w = 1, c = 64, f = 32
								// T (x, 4) (4 / 1)
								for (x = x645, xp_3 = x645_p_2, xp_2 = x645_p_1, xp_1 = x645_p_0, xp_0 = 0;
									x < x645 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3984 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3985 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3986 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3987 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c387, cp_1 = c387_p_0, cp_0 = 0;
												c < c387 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3984);
												mem_vec_3984 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3985);
												mem_vec_3985 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3986);
												mem_vec_3986 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3987);
												mem_vec_3987 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3988);
												mem_vec_3988 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3989);
												mem_vec_3989 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3990);
												mem_vec_3990 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3991);
												mem_vec_3991 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3992);
												mem_vec_3992 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3993);
												mem_vec_3993 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3994);
												mem_vec_3994 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3995);
												mem_vec_3995 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3996);
												mem_vec_3996 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3997);
												mem_vec_3997 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3998);
												mem_vec_3998 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3999);
												mem_vec_3999 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3984);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3985);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3986);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3987);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3988);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3989);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3990);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3991);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3992);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3993);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3994);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3995);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3996);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3997);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3998);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3999);
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