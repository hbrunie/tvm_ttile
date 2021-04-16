#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (136, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c567_p_0, cp_1, c567, f, fp_0, x, xp_0, x945_p_0, x946_p_0, x947_p_0, xp_1, x945_p_1, x946_p_1, xp_2, x945_p_2, xp_3, x945, x946, x947, y, yp_0, y756_p_0, y757_p_0, yp_1, y756_p_1, yp_2, y756, y757;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y758 = 0;
IND_TYPE x948 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c568 = 0;
IND_TYPE f378 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4944 ,mem_vec_4945 ,mem_vec_4946 ,mem_vec_4947 ,mem_vec_4948 ,mem_vec_4949 ,mem_vec_4950 ,mem_vec_4951 ,mem_vec_4952 ,mem_vec_4953 ,mem_vec_4954 ,mem_vec_4955 ,mem_vec_4956 ,mem_vec_4957 ,mem_vec_4958 ,mem_vec_4959 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y757 = y758, y757_p_0 = 0;
	y757 < y758 + 136;
	y757 += 136, y757_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x947 = x948, x947_p_0 = 0;
		x947 < x948 + 136;
		x947 += 136, x947_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y756 = y757, y756_p_1 = y757_p_0, y756_p_0 = 0;
			y756 < y757 + 136;
			y756 += 8, y756_p_1 += 8, y756_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x946 = x947, x946_p_1 = x947_p_0, x946_p_0 = 0;
				x946 < x947 + 136;
				x946 += 1, x946_p_1 += 1, x946_p_0 += 1){
				// y = 8, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f378, fp_0 = 0;
					f < f378 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y756, yp_2 = y756_p_1, yp_1 = y756_p_0, yp_0 = 0;
						y < y756 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x945 = x946, x945_p_2 = x946_p_1, x945_p_1 = x946_p_0, x945_p_0 = 0;
							x945 < x946 + 1;
							x945 += 1, x945_p_2 += 1, x945_p_1 += 1, x945_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c567 = c568, c567_p_0 = 0;
								c567 < c568 + 128;
								c567 += 64, c567_p_0 += 64){
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x945, xp_3 = x945_p_2, xp_2 = x945_p_1, xp_1 = x945_p_0, xp_0 = 0;
									x < x945 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4944 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4945 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4946 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4947 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c567, cp_1 = c567_p_0, cp_0 = 0;
												c < c567 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4944);
												mem_vec_4944 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4945);
												mem_vec_4945 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4946);
												mem_vec_4946 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4947);
												mem_vec_4947 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4948);
												mem_vec_4948 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4949);
												mem_vec_4949 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4950);
												mem_vec_4950 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4951);
												mem_vec_4951 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4952);
												mem_vec_4952 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4953);
												mem_vec_4953 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4954);
												mem_vec_4954 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4955);
												mem_vec_4955 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4956);
												mem_vec_4956 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4957);
												mem_vec_4957 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4958);
												mem_vec_4958 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4959);
												mem_vec_4959 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4944);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4945);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4946);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4947);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4948);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4949);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4950);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4951);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4952);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4953);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4954);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4955);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4956);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4957);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4958);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4959);
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