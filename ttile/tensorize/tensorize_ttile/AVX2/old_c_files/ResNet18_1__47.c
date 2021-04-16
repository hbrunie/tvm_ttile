#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (7, w); T (7, h); T (4, y); T (112, x); T (7, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c156_p_0, cp_1, c156, f, fp_0, f156_p_0, fp_1, f156, h, hp_0, w, wp_0, x, xp_0, x156_p_0, xp_1, x156, y, yp_0, y156_p_0, yp_1, y156;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y157 = 0;
IND_TYPE x157 = 0;
IND_TYPE h104 = 0;
IND_TYPE w104 = 0;
IND_TYPE c157 = 0;
IND_TYPE f157 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 1) (64 / 64)
for (f156 = f157, f156_p_0 = 0;
	f156 < f157 + 64;
	f156 += 64, f156_p_0 += 64){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f156, fp_1 = f156_p_0, fp_0 = 0;
		f < f156 + 64;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 7) (112 / 16)
		for (y156 = y157, y156_p_0 = 0;
			y156 < y157 + 112;
			y156 += 16, y156_p_0 += 16){
			// y = 16, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 112) (112 / 1)
			for (x156 = x157, x156_p_0 = 0;
				x156 < x157 + 112;
				x156 += 1, x156_p_0 += 1){
				// y = 16, x = 1, h = 7, w = 7, c = 3, f = 32
				// T (y, 4) (16 / 4)
				for (y = y156, yp_1 = y156_p_0, yp_0 = 0;
					y < y156 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 1, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h104, hp_0 = 0;
						h < h104 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 1, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w104, wp_0 = 0;
							w < w104 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c156 = c157, c156_p_0 = 0;
								c156 < c157 + 3;
								c156 += 3, c156_p_0 += 3){
								// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
								// T (x, 1) (1 / 1)
								for (x = x156, xp_1 = x156_p_0, xp_0 = 0;
									x < x156 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_872 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_873 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_874 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_875 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
												c < c156 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_872);
												mem_vec_872 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_873);
												mem_vec_873 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_874);
												mem_vec_874 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_875);
												mem_vec_875 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_876);
												mem_vec_876 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_877);
												mem_vec_877 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_878);
												mem_vec_878 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_879);
												mem_vec_879 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_880);
												mem_vec_880 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_881);
												mem_vec_881 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_882);
												mem_vec_882 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_883);
												mem_vec_883 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_884);
												mem_vec_884 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_885);
												mem_vec_885 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_886);
												mem_vec_886 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_887);
												mem_vec_887 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_872);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_873);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_874);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_875);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_876);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_877);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_878);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_879);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_880);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_881);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_882);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_883);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_884);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_885);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_886);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_887);
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