#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (2, y); T (2, f); T (68, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c552_p_0, cp_1, c552, f, fp_0, x, xp_0, x920_p_0, x921_p_0, x922_p_0, xp_1, x920_p_1, x921_p_1, xp_2, x920_p_2, xp_3, x920, x921, x922, y, yp_0, y736_p_0, y737_p_0, yp_1, y736_p_1, yp_2, y736, y737;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y738 = 0;
IND_TYPE x923 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c553 = 0;
IND_TYPE f368 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4864 ,mem_vec_4865 ,mem_vec_4866 ,mem_vec_4867 ,mem_vec_4868 ,mem_vec_4869 ,mem_vec_4870 ,mem_vec_4871 ,mem_vec_4872 ,mem_vec_4873 ,mem_vec_4874 ,mem_vec_4875 ,mem_vec_4876 ,mem_vec_4877 ,mem_vec_4878 ,mem_vec_4879 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y737 = y738, y737_p_0 = 0;
	y737 < y738 + 136;
	y737 += 8, y737_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x922 = x923, x922_p_0 = 0;
		x922 < x923 + 136;
		x922 += 136, x922_p_0 += 136){
		// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (8 / 8)
		for (y736 = y737, y736_p_1 = y737_p_0, y736_p_0 = 0;
			y736 < y737 + 8;
			y736 += 8, y736_p_1 += 8, y736_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (136 / 2)
			for (x921 = x922, x921_p_1 = x922_p_0, x921_p_0 = 0;
				x921 < x922 + 136;
				x921 += 2, x921_p_1 += 2, x921_p_0 += 2){
				// y = 8, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f368, fp_0 = 0;
					f < f368 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y736, yp_2 = y736_p_1, yp_1 = y736_p_0, yp_0 = 0;
						y < y736 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (2 / 1)
						for (x920 = x921, x920_p_2 = x921_p_1, x920_p_1 = x921_p_0, x920_p_0 = 0;
							x920 < x921 + 2;
							x920 += 1, x920_p_2 += 1, x920_p_1 += 1, x920_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c552 = c553, c552_p_0 = 0;
								c552 < c553 + 128;
								c552 += 128, c552_p_0 += 128){
								// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x920, xp_3 = x920_p_2, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
									x < x920 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4864 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4865 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4866 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4867 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c552, cp_1 = c552_p_0, cp_0 = 0;
												c < c552 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4864);
												mem_vec_4864 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4865);
												mem_vec_4865 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4866);
												mem_vec_4866 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4867);
												mem_vec_4867 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4868);
												mem_vec_4868 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4869);
												mem_vec_4869 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4870);
												mem_vec_4870 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4871);
												mem_vec_4871 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4872);
												mem_vec_4872 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4873);
												mem_vec_4873 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4874);
												mem_vec_4874 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4875);
												mem_vec_4875 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4876);
												mem_vec_4876 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4877);
												mem_vec_4877 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4878);
												mem_vec_4878 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4879);
												mem_vec_4879 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4864);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4865);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4866);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4867);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4868);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4869);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4870);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4871);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4872);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4873);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4874);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4875);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4876);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4877);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4878);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4879);
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