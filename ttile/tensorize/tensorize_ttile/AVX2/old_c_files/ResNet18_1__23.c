#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (4, x); T (1, c);
  T (7, w); T (7, h); T (4, y); T (28, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c147_p_0, cp_1, c147, f, fp_0, f147_p_0, fp_1, f147, h, hp_0, w, wp_0, x, xp_0, x147_p_0, xp_1, x147, y, yp_0, y147_p_0, yp_1, y147;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y148 = 0;
IND_TYPE x148 = 0;
IND_TYPE h98 = 0;
IND_TYPE w98 = 0;
IND_TYPE c148 = 0;
IND_TYPE f148 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 2) (64 / 32)
for (f147 = f148, f147_p_0 = 0;
	f147 < f148 + 64;
	f147 += 32, f147_p_0 += 32){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
	// T (f, 1) (32 / 32)
	for (f = f147, fp_1 = f147_p_0, fp_0 = 0;
		f < f147 + 32;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 7) (112 / 16)
		for (y147 = y148, y147_p_0 = 0;
			y147 < y148 + 112;
			y147 += 16, y147_p_0 += 16){
			// y = 16, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 28) (112 / 4)
			for (x147 = x148, x147_p_0 = 0;
				x147 < x148 + 112;
				x147 += 4, x147_p_0 += 4){
				// y = 16, x = 4, h = 7, w = 7, c = 3, f = 32
				// T (y, 4) (16 / 4)
				for (y = y147, yp_1 = y147_p_0, yp_0 = 0;
					y < y147 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 4, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h98, hp_0 = 0;
						h < h98 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 4, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w98, wp_0 = 0;
							w < w98 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c147 = c148, c147_p_0 = 0;
								c147 < c148 + 3;
								c147 += 3, c147_p_0 += 3){
								// y = 4, x = 4, h = 1, w = 1, c = 3, f = 32
								// T (x, 4) (4 / 1)
								for (x = x147, xp_1 = x147_p_0, xp_0 = 0;
									x < x147 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_824 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_825 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_826 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_827 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c147, cp_1 = c147_p_0, cp_0 = 0;
												c < c147 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_824);
												mem_vec_824 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_825);
												mem_vec_825 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_826);
												mem_vec_826 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_827);
												mem_vec_827 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_828);
												mem_vec_828 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_829);
												mem_vec_829 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_830);
												mem_vec_830 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_831);
												mem_vec_831 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_832);
												mem_vec_832 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_833);
												mem_vec_833 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_834);
												mem_vec_834 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_835);
												mem_vec_835 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_836);
												mem_vec_836 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_837);
												mem_vec_837 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_838);
												mem_vec_838 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_839);
												mem_vec_839 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_831);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_835);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_836);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_837);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_838);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_839);
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