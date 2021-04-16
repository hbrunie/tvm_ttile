#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (2, y); T (2, f); T (136, x); T (1, y); T (1, x); T (17, y)]
*/
IND_TYPE c, cp_0, c582_p_0, cp_1, c582, f, fp_0, x, xp_0, x970_p_0, x971_p_0, x972_p_0, xp_1, x970_p_1, x971_p_1, xp_2, x970_p_2, xp_3, x970, x971, x972, y, yp_0, y776_p_0, y777_p_0, yp_1, y776_p_1, yp_2, y776, y777;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y778 = 0;
IND_TYPE x973 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c583 = 0;
IND_TYPE f388 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,mem_vec_5032 ,mem_vec_5033 ,mem_vec_5034 ,mem_vec_5035 ,mem_vec_5036 ,mem_vec_5037 ,mem_vec_5038 ,mem_vec_5039 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y777 = y778, y777_p_0 = 0;
	y777 < y778 + 136;
	y777 += 8, y777_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x972 = x973, x972_p_0 = 0;
		x972 < x973 + 136;
		x972 += 136, x972_p_0 += 136){
		// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (8 / 8)
		for (y776 = y777, y776_p_1 = y777_p_0, y776_p_0 = 0;
			y776 < y777 + 8;
			y776 += 8, y776_p_1 += 8, y776_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x971 = x972, x971_p_1 = x972_p_0, x971_p_0 = 0;
				x971 < x972 + 136;
				x971 += 1, x971_p_1 += 1, x971_p_0 += 1){
				// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f388, fp_0 = 0;
					f < f388 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y776, yp_2 = y776_p_1, yp_1 = y776_p_0, yp_0 = 0;
						y < y776 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x970 = x971, x970_p_2 = x971_p_1, x970_p_1 = x971_p_0, x970_p_0 = 0;
							x970 < x971 + 1;
							x970 += 1, x970_p_2 += 1, x970_p_1 += 1, x970_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 4) (128 / 32)
							for (c582 = c583, c582_p_0 = 0;
								c582 < c583 + 128;
								c582 += 32, c582_p_0 += 32){
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x970, xp_3 = x970_p_2, xp_2 = x970_p_1, xp_1 = x970_p_0, xp_0 = 0;
									x < x970 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5024 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5025 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5026 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5027 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5032 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5033 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5034 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5035 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c582, cp_1 = c582_p_0, cp_0 = 0;
												c < c582 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5024);
												mem_vec_5024 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5025);
												mem_vec_5025 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5026);
												mem_vec_5026 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5027);
												mem_vec_5027 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5028);
												mem_vec_5028 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5029);
												mem_vec_5029 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5030);
												mem_vec_5030 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5031);
												mem_vec_5031 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5032);
												mem_vec_5032 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5033);
												mem_vec_5033 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5034);
												mem_vec_5034 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5035);
												mem_vec_5035 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5036);
												mem_vec_5036 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5037);
												mem_vec_5037 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5038);
												mem_vec_5038 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5039);
												mem_vec_5039 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5024);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5025);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5026);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5027);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5028);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5029);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5030);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5031);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5032);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5033);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5034);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5035);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5036);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5037);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5038);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5039);
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