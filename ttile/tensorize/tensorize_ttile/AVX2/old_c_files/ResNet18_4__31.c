#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (7, y); T (4, f); T (1, c); T (1, f); T (1, y); T (1, f)]
*/
IND_TYPE c, cp_0, c168_p_0, cp_1, c168, f, fp_0, f224_p_0, f225_p_0, fp_1, f224_p_1, fp_2, f224, f225, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y126_p_0, yp_1, y126;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y127 = 0;
IND_TYPE x112 = 0;
IND_TYPE h94 = 0;
IND_TYPE w88 = 0;
IND_TYPE c169 = 0;
IND_TYPE f226 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1424 ,mem_vec_1425 ,mem_vec_1426 ,mem_vec_1427 ,mem_vec_1428 ,mem_vec_1429 ,mem_vec_1430 ,mem_vec_1431 ,mem_vec_1432 ,mem_vec_1433 ,mem_vec_1434 ,mem_vec_1435 ,mem_vec_1436 ,mem_vec_1437 ,mem_vec_1438 ,mem_vec_1439 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f225 = f226, f225_p_0 = 0;
	f225 < f226 + 128;
	f225 += 128, f225_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
	// T (y, 1) (28 / 28)
	for (y126 = y127, y126_p_0 = 0;
		y126 < y127 + 28;
		y126 += 28, y126_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (f, 1) (128 / 128)
		for (f224 = f225, f224_p_1 = f225_p_0, f224_p_0 = 0;
			f224 < f225 + 128;
			f224 += 128, f224_p_1 += 128, f224_p_0 += 128){
			// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (c, 1) (64 / 64)
			for (c168 = c169, c168_p_0 = 0;
				c168 < c169 + 64;
				c168 += 64, c168_p_0 += 64){
				// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f224, fp_2 = f224_p_1, fp_1 = f224_p_0, fp_0 = 0;
					f < f224 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 28, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (y, 7) (28 / 4)
					for (y = y126, yp_1 = y126_p_0, yp_0 = 0;
						y < y126 + 28;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (x, 28) (28 / 1)
						for (x = x112, xp_0 = 0;
							x < x112 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h94, hp_0 = 0;
								h < h94 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w88, wp_0 = 0;
									w < w88 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1424 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1425 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1426 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1427 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1434 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1435 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c168, cp_1 = c168_p_0, cp_0 = 0;
												c < c168 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1424);
												mem_vec_1424 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1425);
												mem_vec_1425 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1426);
												mem_vec_1426 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1427);
												mem_vec_1427 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1428);
												mem_vec_1428 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1429);
												mem_vec_1429 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1430);
												mem_vec_1430 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1431);
												mem_vec_1431 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1432);
												mem_vec_1432 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1433);
												mem_vec_1433 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1434);
												mem_vec_1434 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1435);
												mem_vec_1435 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1436);
												mem_vec_1436 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1437);
												mem_vec_1437 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1438);
												mem_vec_1438 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1439);
												mem_vec_1439 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1424);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1425);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1426);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1427);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1428);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1429);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1430);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1431);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1432);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1433);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1434);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1435);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1436);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1437);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1438);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1439);
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