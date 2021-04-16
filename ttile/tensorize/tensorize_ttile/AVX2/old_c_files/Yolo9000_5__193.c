#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (17, y); T (2, f); T (136, x); T (2, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, x, xp_0, x10_p_0, x11_p_0, x12_p_0, xp_1, x10_p_1, x11_p_1, xp_2, x10_p_2, xp_3, x10, x11, x12, y, yp_0, y8_p_0, y9_p_0, yp_1, y8_p_1, yp_2, y8, y9;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y10 = 0;
IND_TYPE x13 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y9 = y10, y9_p_0 = 0;
	y9 < y10 + 136;
	y9 += 136, y9_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x12 = x13, x12_p_0 = 0;
		x12 < x13 + 136;
		x12 += 136, x12_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 2) (136 / 68)
		for (y8 = y9, y8_p_1 = y9_p_0, y8_p_0 = 0;
			y8 < y9 + 136;
			y8 += 68, y8_p_1 += 68, y8_p_0 += 68){
			// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x11 = x12, x11_p_1 = x12_p_0, x11_p_0 = 0;
				x11 < x12 + 136;
				x11 += 1, x11_p_1 += 1, x11_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f4, fp_0 = 0;
					f < f4 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y8, yp_2 = y8_p_1, yp_1 = y8_p_0, yp_0 = 0;
						y < y8 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x10 = x11, x10_p_2 = x11_p_1, x10_p_1 = x11_p_0, x10_p_0 = 0;
							x10 < x11 + 1;
							x10 += 1, x10_p_2 += 1, x10_p_1 += 1, x10_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 4) (128 / 32)
							for (c6 = c7, c6_p_0 = 0;
								c6 < c7 + 128;
								c6 += 32, c6_p_0 += 32){
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x10, xp_3 = x10_p_2, xp_2 = x10_p_1, xp_1 = x10_p_0, xp_0 = 0;
									x < x10 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_32 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_33 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_34 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_35 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_36 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_37 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_38 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_39 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_40 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_41 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_42 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_43 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_44 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_45 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_46 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_47 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
												c < c6 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_32);
												mem_vec_32 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_33);
												mem_vec_33 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_34);
												mem_vec_34 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_35);
												mem_vec_35 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_36);
												mem_vec_36 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_37);
												mem_vec_37 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_38);
												mem_vec_38 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_39);
												mem_vec_39 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_40);
												mem_vec_40 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_41);
												mem_vec_41 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_42);
												mem_vec_42 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_43);
												mem_vec_43 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_44);
												mem_vec_44 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_45);
												mem_vec_45 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_46);
												mem_vec_46 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_47);
												mem_vec_47 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_32);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_33);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_34);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_35);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_36);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_37);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_38);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_39);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_40);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_41);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_42);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_43);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_44);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_45);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_46);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_47);
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