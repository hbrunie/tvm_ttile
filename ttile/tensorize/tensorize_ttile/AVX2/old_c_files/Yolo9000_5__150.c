#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (136, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c579_p_0, cp_1, c579, f, fp_0, x, xp_0, x965_p_0, x966_p_0, x967_p_0, xp_1, x965_p_1, x966_p_1, xp_2, x965_p_2, xp_3, x965, x966, x967, y, yp_0, y772_p_0, y773_p_0, yp_1, y772_p_1, yp_2, y772, y773;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y774 = 0;
IND_TYPE x968 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c580 = 0;
IND_TYPE f386 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5008 ,mem_vec_5009 ,mem_vec_5010 ,mem_vec_5011 ,mem_vec_5012 ,mem_vec_5013 ,mem_vec_5014 ,mem_vec_5015 ,mem_vec_5016 ,mem_vec_5017 ,mem_vec_5018 ,mem_vec_5019 ,mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y773 = y774, y773_p_0 = 0;
	y773 < y774 + 136;
	y773 += 8, y773_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x967 = x968, x967_p_0 = 0;
		x967 < x968 + 136;
		x967 += 136, x967_p_0 += 136){
		// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (8 / 8)
		for (y772 = y773, y772_p_1 = y773_p_0, y772_p_0 = 0;
			y772 < y773 + 8;
			y772 += 8, y772_p_1 += 8, y772_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x966 = x967, x966_p_1 = x967_p_0, x966_p_0 = 0;
				x966 < x967 + 136;
				x966 += 1, x966_p_1 += 1, x966_p_0 += 1){
				// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f386, fp_0 = 0;
					f < f386 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y772, yp_2 = y772_p_1, yp_1 = y772_p_0, yp_0 = 0;
						y < y772 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x965 = x966, x965_p_2 = x966_p_1, x965_p_1 = x966_p_0, x965_p_0 = 0;
							x965 < x966 + 1;
							x965 += 1, x965_p_2 += 1, x965_p_1 += 1, x965_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c579 = c580, c579_p_0 = 0;
								c579 < c580 + 128;
								c579 += 64, c579_p_0 += 64){
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x965, xp_3 = x965_p_2, xp_2 = x965_p_1, xp_1 = x965_p_0, xp_0 = 0;
									x < x965 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5008 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5009 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5010 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5011 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c579, cp_1 = c579_p_0, cp_0 = 0;
												c < c579 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5008);
												mem_vec_5008 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5009);
												mem_vec_5009 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5010);
												mem_vec_5010 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5011);
												mem_vec_5011 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5012);
												mem_vec_5012 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5013);
												mem_vec_5013 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5014);
												mem_vec_5014 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5015);
												mem_vec_5015 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5016);
												mem_vec_5016 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5017);
												mem_vec_5017 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5018);
												mem_vec_5018 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5019);
												mem_vec_5019 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5020);
												mem_vec_5020 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5021);
												mem_vec_5021 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5022);
												mem_vec_5022 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5023);
												mem_vec_5023 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5008);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5009);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5010);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5011);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5012);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5013);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5014);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5015);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5016);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5017);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5018);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5019);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5020);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5021);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5022);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5023);
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