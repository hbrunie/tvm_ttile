#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (4, x); T (2, y); T (2, f); T (17, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c399_p_0, cp_1, c399, f, fp_0, x, xp_0, x665_p_0, x666_p_0, x667_p_0, xp_1, x665_p_1, x666_p_1, xp_2, x665_p_2, xp_3, x665, x666, x667, y, yp_0, y532_p_0, y533_p_0, yp_1, y532_p_1, yp_2, y532, y533;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y534 = 0;
IND_TYPE x668 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c400 = 0;
IND_TYPE f266 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4048 ,mem_vec_4049 ,mem_vec_4050 ,mem_vec_4051 ,mem_vec_4052 ,mem_vec_4053 ,mem_vec_4054 ,mem_vec_4055 ,mem_vec_4056 ,mem_vec_4057 ,mem_vec_4058 ,mem_vec_4059 ,mem_vec_4060 ,mem_vec_4061 ,mem_vec_4062 ,mem_vec_4063 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y533 = y534, y533_p_0 = 0;
	y533 < y534 + 136;
	y533 += 136, y533_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x667 = x668, x667_p_0 = 0;
		x667 < x668 + 136;
		x667 += 136, x667_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y532 = y533, y532_p_1 = y533_p_0, y532_p_0 = 0;
			y532 < y533 + 136;
			y532 += 8, y532_p_1 += 8, y532_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 17) (136 / 8)
			for (x666 = x667, x666_p_1 = x667_p_0, x666_p_0 = 0;
				x666 < x667 + 136;
				x666 += 8, x666_p_1 += 8, x666_p_0 += 8){
				// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f266, fp_0 = 0;
					f < f266 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y532, yp_2 = y532_p_1, yp_1 = y532_p_0, yp_0 = 0;
						y < y532 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 8, h = 1, w = 1, c = 128, f = 32
						// T (x, 4) (8 / 2)
						for (x665 = x666, x665_p_2 = x666_p_1, x665_p_1 = x666_p_0, x665_p_0 = 0;
							x665 < x666 + 8;
							x665 += 2, x665_p_2 += 2, x665_p_1 += 2, x665_p_0 += 2){
							// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c399 = c400, c399_p_0 = 0;
								c399 < c400 + 128;
								c399 += 64, c399_p_0 += 64){
								// y = 4, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x665, xp_3 = x665_p_2, xp_2 = x665_p_1, xp_1 = x665_p_0, xp_0 = 0;
									x < x665 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4048 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4049 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4050 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4051 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c399, cp_1 = c399_p_0, cp_0 = 0;
												c < c399 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4048);
												mem_vec_4048 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4049);
												mem_vec_4049 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4050);
												mem_vec_4050 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4051);
												mem_vec_4051 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4052);
												mem_vec_4052 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4053);
												mem_vec_4053 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4054);
												mem_vec_4054 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4055);
												mem_vec_4055 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4056);
												mem_vec_4056 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4057);
												mem_vec_4057 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4058);
												mem_vec_4058 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4059);
												mem_vec_4059 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4060);
												mem_vec_4060 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4061);
												mem_vec_4061 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4062);
												mem_vec_4062 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4063);
												mem_vec_4063 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4048);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4049);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4050);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4051);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4052);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4053);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4054);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4055);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4059);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4063);
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