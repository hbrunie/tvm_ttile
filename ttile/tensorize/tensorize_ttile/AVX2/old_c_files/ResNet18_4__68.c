#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (2, f); T (2, c); T (1, f); T (1, y); T (2, f)]
*/
IND_TYPE c, cp_0, c9_p_0, cp_1, c9, f, fp_0, f12_p_0, f13_p_0, fp_1, f12_p_1, fp_2, f12, f13, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y9_p_0, yp_1, y9;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y10 = 0;
IND_TYPE x6 = 0;
IND_TYPE h6 = 0;
IND_TYPE w6 = 0;
IND_TYPE c10 = 0;
IND_TYPE f14 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f13 = f14, f13_p_0 = 0;
	f13 < f14 + 128;
	f13 += 64, f13_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
	// T (y, 1) (28 / 28)
	for (y9 = y10, y9_p_0 = 0;
		y9 < y10 + 28;
		y9 += 28, y9_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (f, 1) (64 / 64)
		for (f12 = f13, f12_p_1 = f13_p_0, f12_p_0 = 0;
			f12 < f13 + 64;
			f12 += 64, f12_p_1 += 64, f12_p_0 += 64){
			// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (c, 2) (64 / 32)
			for (c9 = c10, c9_p_0 = 0;
				c9 < c10 + 64;
				c9 += 32, c9_p_0 += 32){
				// y = 28, x = 28, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f12, fp_2 = f12_p_1, fp_1 = f12_p_0, fp_0 = 0;
					f < f12 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 28, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (y, 7) (28 / 4)
					for (y = y9, yp_1 = y9_p_0, yp_0 = 0;
						y < y9 + 28;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x6, xp_0 = 0;
							x < x6 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h6, hp_0 = 0;
								h < h6 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w6, wp_0 = 0;
									w < w6 + 3;
									w += 1, wp_0 += 1){
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
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
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
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_52);
												mem_vec_52 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_53);
												mem_vec_53 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_54);
												mem_vec_54 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_55);
												mem_vec_55 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_56);
												mem_vec_56 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_57);
												mem_vec_57 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_58);
												mem_vec_58 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_59);
												mem_vec_59 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
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
		}
	}
}


}