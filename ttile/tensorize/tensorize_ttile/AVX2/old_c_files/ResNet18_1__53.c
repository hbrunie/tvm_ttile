#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (8, x); T (1, c);
  T (7, w); T (7, h); T (4, y); T (14, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c135_p_0, cp_1, c135, f, fp_0, f135_p_0, fp_1, f135, h, hp_0, w, wp_0, x, xp_0, x135_p_0, xp_1, x135, y, yp_0, y135_p_0, yp_1, y135;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y136 = 0;
IND_TYPE x136 = 0;
IND_TYPE h90 = 0;
IND_TYPE w90 = 0;
IND_TYPE c136 = 0;
IND_TYPE f136 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 2) (64 / 32)
for (f135 = f136, f135_p_0 = 0;
	f135 < f136 + 64;
	f135 += 32, f135_p_0 += 32){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
	// T (f, 1) (32 / 32)
	for (f = f135, fp_1 = f135_p_0, fp_0 = 0;
		f < f135 + 32;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 7) (112 / 16)
		for (y135 = y136, y135_p_0 = 0;
			y135 < y136 + 112;
			y135 += 16, y135_p_0 += 16){
			// y = 16, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 14) (112 / 8)
			for (x135 = x136, x135_p_0 = 0;
				x135 < x136 + 112;
				x135 += 8, x135_p_0 += 8){
				// y = 16, x = 8, h = 7, w = 7, c = 3, f = 32
				// T (y, 4) (16 / 4)
				for (y = y135, yp_1 = y135_p_0, yp_0 = 0;
					y < y135 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 8, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h90, hp_0 = 0;
						h < h90 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 8, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w90, wp_0 = 0;
							w < w90 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c135 = c136, c135_p_0 = 0;
								c135 < c136 + 3;
								c135 += 3, c135_p_0 += 3){
								// y = 4, x = 8, h = 1, w = 1, c = 3, f = 32
								// T (x, 8) (8 / 1)
								for (x = x135, xp_1 = x135_p_0, xp_0 = 0;
									x < x135 + 8;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_760 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_761 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_762 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_763 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c135, cp_1 = c135_p_0, cp_0 = 0;
												c < c135 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_760);
												mem_vec_760 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_761);
												mem_vec_761 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_762);
												mem_vec_762 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_763);
												mem_vec_763 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_764);
												mem_vec_764 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_765);
												mem_vec_765 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_766);
												mem_vec_766 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_767);
												mem_vec_767 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_768);
												mem_vec_768 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_769);
												mem_vec_769 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_770);
												mem_vec_770 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_771);
												mem_vec_771 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_772);
												mem_vec_772 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_773);
												mem_vec_773 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_774);
												mem_vec_774 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_775);
												mem_vec_775 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_765);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_766);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_767);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_775);
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