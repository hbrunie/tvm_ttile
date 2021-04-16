#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (68, x);
  T (3, h); T (4, c); T (17, y); T (1, x); T (1, f); T (1, c); T (8, f)]
*/
IND_TYPE c, cp_0, c248_p_0, c249_p_0, cp_1, c248_p_1, cp_2, c248, c249, f, fp_0, f137_p_0, fp_1, f137, h, hp_0, w, wp_0, x, xp_0, x165_p_0, xp_1, x165, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y110 = 0;
IND_TYPE x166 = 0;
IND_TYPE h82 = 0;
IND_TYPE w86 = 0;
IND_TYPE c250 = 0;
IND_TYPE f138 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_2012 ,mem_vec_2013 ,mem_vec_2014 ,mem_vec_2015 ,mem_vec_2016 ,mem_vec_2017 ,mem_vec_2018 ,mem_vec_2019 ,mem_vec_2020 ,mem_vec_2021 ,mem_vec_2022 ,mem_vec_2023 ,mem_vec_2024 ,mem_vec_2025 ,mem_vec_2026 ,mem_vec_2027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f137 = f138, f137_p_0 = 0;
	f137 < f138 + 256;
	f137 += 32, f137_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (c, 1) (128 / 128)
	for (c249 = c250, c249_p_0 = 0;
		c249 < c250 + 128;
		c249 += 128, c249_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f = f137, fp_1 = f137_p_0, fp_0 = 0;
			f < f137 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (68 / 68)
			for (x165 = x166, x165_p_0 = 0;
				x165 < x166 + 68;
				x165 += 68, x165_p_0 += 68){
				// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
				// T (y, 17) (68 / 4)
				for (y = y110, yp_0 = 0;
					y < y110 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c248 = c249, c248_p_1 = c249_p_0, c248_p_0 = 0;
						c248 < c249 + 128;
						c248 += 32, c248_p_1 += 32, c248_p_0 += 32){
						// y = 4, x = 68, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h82, hp_0 = 0;
							h < h82 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 32, f = 32
							// T (x, 68) (68 / 1)
							for (x = x165, xp_1 = x165_p_0, xp_0 = 0;
								x < x165 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w86, wp_0 = 0;
									w < w86 + 3;
									w += 1, wp_0 += 1){
											mem_vec_2012 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2013 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2014 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2015 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c248, cp_2 = c248_p_1, cp_1 = c248_p_0, cp_0 = 0;
												c < c248 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2012);
												mem_vec_2012 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2013);
												mem_vec_2013 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2014);
												mem_vec_2014 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2015);
												mem_vec_2015 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2016);
												mem_vec_2016 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2017);
												mem_vec_2017 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2018);
												mem_vec_2018 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2019);
												mem_vec_2019 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2020);
												mem_vec_2020 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2021);
												mem_vec_2021 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2022);
												mem_vec_2022 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2023);
												mem_vec_2023 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2024);
												mem_vec_2024 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2025);
												mem_vec_2025 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2026);
												mem_vec_2026 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2027);
												mem_vec_2027 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2012);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2013);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2014);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2015);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2016);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2017);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2018);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2019);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2020);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2021);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2022);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2023);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2024);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2025);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2026);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2027);
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