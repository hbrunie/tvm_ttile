#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (2, x); T (2, y); T (2, f); T (68, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, x, xp_0, x910_p_0, x911_p_0, x912_p_0, xp_1, x910_p_1, x911_p_1, xp_2, x910_p_2, xp_3, x910, x911, x912, y, yp_0, y728_p_0, y729_p_0, yp_1, y728_p_1, yp_2, y728, y729;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y730 = 0;
IND_TYPE x913 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c547 = 0;
IND_TYPE f364 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y729 = y730, y729_p_0 = 0;
	y729 < y730 + 136;
	y729 += 136, y729_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x912 = x913, x912_p_0 = 0;
		x912 < x913 + 136;
		x912 += 136, x912_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y728 = y729, y728_p_1 = y729_p_0, y728_p_0 = 0;
			y728 < y729 + 136;
			y728 += 8, y728_p_1 += 8, y728_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (136 / 2)
			for (x911 = x912, x911_p_1 = x912_p_0, x911_p_0 = 0;
				x911 < x912 + 136;
				x911 += 2, x911_p_1 += 2, x911_p_0 += 2){
				// y = 8, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f364, fp_0 = 0;
					f < f364 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y728, yp_2 = y728_p_1, yp_1 = y728_p_0, yp_0 = 0;
						y < y728 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (2 / 1)
						for (x910 = x911, x910_p_2 = x911_p_1, x910_p_1 = x911_p_0, x910_p_0 = 0;
							x910 < x911 + 2;
							x910 += 1, x910_p_2 += 1, x910_p_1 += 1, x910_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 4) (128 / 32)
							for (c546 = c547, c546_p_0 = 0;
								c546 < c547 + 128;
								c546 += 32, c546_p_0 += 32){
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x910, xp_3 = x910_p_2, xp_2 = x910_p_1, xp_1 = x910_p_0, xp_0 = 0;
									x < x910 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4832 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4833 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4834 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4835 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
												c < c546 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4832);
												mem_vec_4832 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4833);
												mem_vec_4833 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4834);
												mem_vec_4834 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4835);
												mem_vec_4835 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4836);
												mem_vec_4836 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4837);
												mem_vec_4837 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4838);
												mem_vec_4838 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4839);
												mem_vec_4839 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4840);
												mem_vec_4840 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4841);
												mem_vec_4841 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4842);
												mem_vec_4842 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4843);
												mem_vec_4843 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4844);
												mem_vec_4844 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4845);
												mem_vec_4845 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4846);
												mem_vec_4846 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4847);
												mem_vec_4847 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4835);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4836);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4837);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4838);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4839);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4840);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4841);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4842);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4843);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4844);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4845);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4846);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4847);
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