#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (3, w); T (17, x);
  T (3, h); T (16, c); T (17, y); T (4, x); T (1, f); T (2, c); T (8, f)]
*/
IND_TYPE c, cp_0, c568_p_0, c569_p_0, cp_1, c568_p_1, cp_2, c568, c569, f, fp_0, f349_p_0, fp_1, f349, h, hp_0, w, wp_0, x, xp_0, x393_p_0, xp_1, x393, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y262 = 0;
IND_TYPE x394 = 0;
IND_TYPE h202 = 0;
IND_TYPE w226 = 0;
IND_TYPE c570 = 0;
IND_TYPE f350 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_3580 ,mem_vec_3581 ,mem_vec_3582 ,mem_vec_3583 ,mem_vec_3584 ,mem_vec_3585 ,mem_vec_3586 ,mem_vec_3587 ,mem_vec_3588 ,mem_vec_3589 ,mem_vec_3590 ,mem_vec_3591 ,mem_vec_3592 ,mem_vec_3593 ,mem_vec_3594 ,mem_vec_3595 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f349 = f350, f349_p_0 = 0;
	f349 < f350 + 256;
	f349 += 32, f349_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (c, 2) (128 / 64)
	for (c569 = c570, c569_p_0 = 0;
		c569 < c570 + 128;
		c569 += 64, c569_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
		// T (f, 1) (32 / 32)
		for (f = f349, fp_1 = f349_p_0, fp_0 = 0;
			f < f349 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (x, 4) (68 / 17)
			for (x393 = x394, x393_p_0 = 0;
				x393 < x394 + 68;
				x393 += 17, x393_p_0 += 17){
				// y = 68, x = 17, h = 3, w = 3, c = 64, f = 32
				// T (y, 17) (68 / 4)
				for (y = y262, yp_0 = 0;
					y < y262 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 16) (64 / 4)
					for (c568 = c569, c568_p_1 = c569_p_0, c568_p_0 = 0;
						c568 < c569 + 64;
						c568 += 4, c568_p_1 += 4, c568_p_0 += 4){
						// y = 4, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h202, hp_0 = 0;
							h < h202 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 17, h = 1, w = 3, c = 4, f = 32
							// T (x, 17) (17 / 1)
							for (x = x393, xp_1 = x393_p_0, xp_0 = 0;
								x < x393 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w226, wp_0 = 0;
									w < w226 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3580 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3581 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3582 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3583 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_3584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_3588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_3592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c568, cp_2 = c568_p_1, cp_1 = c568_p_0, cp_0 = 0;
												c < c568 + 4;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3580);
												mem_vec_3580 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3581);
												mem_vec_3581 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3582);
												mem_vec_3582 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3583);
												mem_vec_3583 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3584);
												mem_vec_3584 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3585);
												mem_vec_3585 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3586);
												mem_vec_3586 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3587);
												mem_vec_3587 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3588);
												mem_vec_3588 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3589);
												mem_vec_3589 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3590);
												mem_vec_3590 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3591);
												mem_vec_3591 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3592);
												mem_vec_3592 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3593);
												mem_vec_3593 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3594);
												mem_vec_3594 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3595);
												mem_vec_3595 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3580);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3581);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3582);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3583);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3584);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3585);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3586);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3587);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3588);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3589);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3590);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3591);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3592);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3593);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3594);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3595);
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