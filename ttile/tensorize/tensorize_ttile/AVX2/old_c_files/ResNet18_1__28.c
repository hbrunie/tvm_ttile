#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (56, x); T (1, c);
  T (7, w); T (7, h); T (7, y); T (2, x); T (4, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, f102_p_0, fp_1, f102, h, hp_0, w, wp_0, x, xp_0, x102_p_0, xp_1, x102, y, yp_0, y102_p_0, yp_1, y102;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y103 = 0;
IND_TYPE x103 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c103 = 0;
IND_TYPE f103 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (f, 1) (64 / 64)
for (f102 = f103, f102_p_0 = 0;
	f102 < f103 + 64;
	f102 += 64, f102_p_0 += 64){
	// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f102, fp_1 = f102_p_0, fp_0 = 0;
		f < f102 + 64;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 112, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 4) (112 / 28)
		for (y102 = y103, y102_p_0 = 0;
			y102 < y103 + 112;
			y102 += 28, y102_p_0 += 28){
			// y = 28, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 2) (112 / 56)
			for (x102 = x103, x102_p_0 = 0;
				x102 < x103 + 112;
				x102 += 56, x102_p_0 += 56){
				// y = 28, x = 56, h = 7, w = 7, c = 3, f = 32
				// T (y, 7) (28 / 4)
				for (y = y102, yp_1 = y102_p_0, yp_0 = 0;
					y < y102 + 28;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 56, h = 7, w = 7, c = 3, f = 32
					// T (h, 7) (7 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 7;
						h += 1, hp_0 += 1){
						// y = 4, x = 56, h = 1, w = 7, c = 3, f = 32
						// T (w, 7) (7 / 1)
						for (w = w68, wp_0 = 0;
							w < w68 + 7;
							w += 1, wp_0 += 1){
							// y = 4, x = 56, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c102 = c103, c102_p_0 = 0;
								c102 < c103 + 3;
								c102 += 3, c102_p_0 += 3){
								// y = 4, x = 56, h = 1, w = 1, c = 3, f = 32
								// T (x, 56) (56 / 1)
								for (x = x102, xp_1 = x102_p_0, xp_0 = 0;
									x < x102 + 56;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_584 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_585 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_586 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_587 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
												c < c102 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_584);
												mem_vec_584 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_585);
												mem_vec_585 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_586);
												mem_vec_586 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_587);
												mem_vec_587 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_588);
												mem_vec_588 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_589);
												mem_vec_589 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_590);
												mem_vec_590 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_591);
												mem_vec_591 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_592);
												mem_vec_592 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_593);
												mem_vec_593 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_594);
												mem_vec_594 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_595);
												mem_vec_595 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_596);
												mem_vec_596 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_597);
												mem_vec_597 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_598);
												mem_vec_598 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_599);
												mem_vec_599 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_584);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_585);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_586);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_587);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_588);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_589);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_590);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_591);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_592);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_593);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_594);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_595);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_596);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_597);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_598);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_599);
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