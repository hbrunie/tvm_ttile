#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (1, y); T (4, f); T (1, c); T (1, f); T (7, y); T (1, f)]
*/
IND_TYPE c, cp_0, c186_p_0, cp_1, c186, f, fp_0, f248_p_0, f249_p_0, fp_1, f248_p_1, fp_2, f248, f249, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y144_p_0, yp_1, y144;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y145 = 0;
IND_TYPE x124 = 0;
IND_TYPE h106 = 0;
IND_TYPE w100 = 0;
IND_TYPE c187 = 0;
IND_TYPE f250 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f249 = f250, f249_p_0 = 0;
	f249 < f250 + 128;
	f249 += 128, f249_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
	// T (y, 7) (28 / 4)
	for (y144 = y145, y144_p_0 = 0;
		y144 < y145 + 28;
		y144 += 4, y144_p_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (f, 1) (128 / 128)
		for (f248 = f249, f248_p_1 = f249_p_0, f248_p_0 = 0;
			f248 < f249 + 128;
			f248 += 128, f248_p_1 += 128, f248_p_0 += 128){
			// y = 4, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (c, 1) (64 / 64)
			for (c186 = c187, c186_p_0 = 0;
				c186 < c187 + 64;
				c186 += 64, c186_p_0 += 64){
				// y = 4, x = 28, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f248, fp_2 = f248_p_1, fp_1 = f248_p_0, fp_0 = 0;
					f < f248 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (y, 1) (4 / 4)
					for (y = y144, yp_1 = y144_p_0, yp_0 = 0;
						y < y144 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (x, 28) (28 / 1)
						for (x = x124, xp_0 = 0;
							x < x124 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h106, hp_0 = 0;
								h < h106 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w100, wp_0 = 0;
									w < w100 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c186, cp_1 = c186_p_0, cp_0 = 0;
												c < c186 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1520);
												mem_vec_1520 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1521);
												mem_vec_1521 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1522);
												mem_vec_1522 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1523);
												mem_vec_1523 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1524);
												mem_vec_1524 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1525);
												mem_vec_1525 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1526);
												mem_vec_1526 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1527);
												mem_vec_1527 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1528);
												mem_vec_1528 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1529);
												mem_vec_1529 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1530);
												mem_vec_1530 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1531);
												mem_vec_1531 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1532);
												mem_vec_1532 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1533);
												mem_vec_1533 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1534);
												mem_vec_1534 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1535);
												mem_vec_1535 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1535);
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