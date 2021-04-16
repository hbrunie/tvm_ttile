#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (17, y); T (2, f); T (136, x); T (2, y); T (1, x); T (1, y)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, fp_0, x, x0, xp_0, x0_p_0, x1_p_0, x2_p_0, x1, xp_1, x0_p_1, x1_p_1, x2, xp_2, x0_p_2, xp_3, y, y0, yp_0, y0_p_0, y1_p_0, y1, yp_1, y0_p_1, yp_2;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y2 = 0;
IND_TYPE x3 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1 = 0;
IND_TYPE f0 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_2 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y1 = y2, y1_p_0 = 0;
	y1 < y2 + 136;
	y1 += 136, y1_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x2 = x3, x2_p_0 = 0;
		x2 < x3 + 136;
		x2 += 136, x2_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 2) (136 / 68)
		for (y0 = y1, y0_p_1 = y1_p_0, y0_p_0 = 0;
			y0 < y1 + 136;
			y0 += 68, y0_p_1 += 68, y0_p_0 += 68){
			// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x1 = x2, x1_p_1 = x2_p_0, x1_p_0 = 0;
				x1 < x2 + 136;
				x1 += 1, x1_p_1 += 1, x1_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f0, fp_0 = 0;
					f < f0 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y0, yp_2 = y0_p_1, yp_1 = y0_p_0, yp_0 = 0;
						y < y0 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x0 = x1, x0_p_2 = x1_p_1, x0_p_1 = x1_p_0, x0_p_0 = 0;
							x0 < x1 + 1;
							x0 += 1, x0_p_2 += 1, x0_p_1 += 1, x0_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c0 = c1, c0_p_0 = 0;
								c0 < c1 + 128;
								c0 += 128, c0_p_0 += 128){
								// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x0, xp_3 = x0_p_2, xp_2 = x0_p_1, xp_1 = x0_p_0, xp_0 = 0;
									x < x0 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_0 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_15 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
												c < c0 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
												mem_vec_0 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
												mem_vec_1 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2);
												mem_vec_2 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3);
												mem_vec_3 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4);
												mem_vec_4 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5);
												mem_vec_5 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6);
												mem_vec_6 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7);
												mem_vec_7 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8);
												mem_vec_8 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9);
												mem_vec_9 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10);
												mem_vec_10 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11);
												mem_vec_11 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12);
												mem_vec_12 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13);
												mem_vec_13 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14);
												mem_vec_14 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15);
												mem_vec_15 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15);
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