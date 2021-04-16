#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (1, y); T (1, f); T (2, c); T (1, f); T (7, y); T (4, f)]
*/
IND_TYPE c, cp_0, c210_p_0, cp_1, c210, f, fp_0, f280_p_0, f281_p_0, fp_1, f280_p_1, fp_2, f280, f281, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y168_p_0, yp_1, y168;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y169 = 0;
IND_TYPE x140 = 0;
IND_TYPE h122 = 0;
IND_TYPE w116 = 0;
IND_TYPE c211 = 0;
IND_TYPE f282 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1648 ,mem_vec_1649 ,mem_vec_1650 ,mem_vec_1651 ,mem_vec_1652 ,mem_vec_1653 ,mem_vec_1654 ,mem_vec_1655 ,mem_vec_1656 ,mem_vec_1657 ,mem_vec_1658 ,mem_vec_1659 ,mem_vec_1660 ,mem_vec_1661 ,mem_vec_1662 ,mem_vec_1663 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f281 = f282, f281_p_0 = 0;
	f281 < f282 + 128;
	f281 += 32, f281_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
	// T (y, 7) (28 / 4)
	for (y168 = y169, y168_p_0 = 0;
		y168 < y169 + 28;
		y168 += 4, y168_p_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
		// T (f, 1) (32 / 32)
		for (f280 = f281, f280_p_1 = f281_p_0, f280_p_0 = 0;
			f280 < f281 + 32;
			f280 += 32, f280_p_1 += 32, f280_p_0 += 32){
			// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (c, 2) (64 / 32)
			for (c210 = c211, c210_p_0 = 0;
				c210 < c211 + 64;
				c210 += 32, c210_p_0 += 32){
				// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
				// T (f, 1) (32 / 32)
				for (f = f280, fp_2 = f280_p_1, fp_1 = f280_p_0, fp_0 = 0;
					f < f280 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (y, 1) (4 / 4)
					for (y = y168, yp_1 = y168_p_0, yp_0 = 0;
						y < y168 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x140, xp_0 = 0;
							x < x140 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h122, hp_0 = 0;
								h < h122 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w116, wp_0 = 0;
									w < w116 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1648 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1649 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1650 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1651 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1654 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1655 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c210, cp_1 = c210_p_0, cp_0 = 0;
												c < c210 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1648);
												mem_vec_1648 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1649);
												mem_vec_1649 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1650);
												mem_vec_1650 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1651);
												mem_vec_1651 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1652);
												mem_vec_1652 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1653);
												mem_vec_1653 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1654);
												mem_vec_1654 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1655);
												mem_vec_1655 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1656);
												mem_vec_1656 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1657);
												mem_vec_1657 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1658);
												mem_vec_1658 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1659);
												mem_vec_1659 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1660);
												mem_vec_1660 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1661);
												mem_vec_1661 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1662);
												mem_vec_1662 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1663);
												mem_vec_1663 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1648);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1649);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1650);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1651);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1652);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1653);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1654);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1655);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1663);
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