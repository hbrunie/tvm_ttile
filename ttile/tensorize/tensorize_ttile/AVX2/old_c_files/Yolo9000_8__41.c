#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (3, w); T (68, x);
  T (3, h); T (2, c); T (17, y); T (1, x); T (1, f); T (1, c); T (8, f)]
*/
IND_TYPE c, cp_0, c778_p_0, c779_p_0, cp_1, c778_p_1, cp_2, c778, c779, f, fp_0, f489_p_0, fp_1, f489, h, hp_0, w, wp_0, x, xp_0, x543_p_0, xp_1, x543, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y362 = 0;
IND_TYPE x544 = 0;
IND_TYPE h272 = 0;
IND_TYPE w310 = 0;
IND_TYPE c780 = 0;
IND_TYPE f490 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f489 = f490, f489_p_0 = 0;
	f489 < f490 + 256;
	f489 += 32, f489_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (c, 1) (128 / 128)
	for (c779 = c780, c779_p_0 = 0;
		c779 < c780 + 128;
		c779 += 128, c779_p_0 += 128){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f = f489, fp_1 = f489_p_0, fp_0 = 0;
			f < f489 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (68 / 68)
			for (x543 = x544, x543_p_0 = 0;
				x543 < x544 + 68;
				x543 += 68, x543_p_0 += 68){
				// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
				// T (y, 17) (68 / 4)
				for (y = y362, yp_0 = 0;
					y < y362 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 68, h = 3, w = 3, c = 128, f = 32
					// T (c, 2) (128 / 64)
					for (c778 = c779, c778_p_1 = c779_p_0, c778_p_0 = 0;
						c778 < c779 + 128;
						c778 += 64, c778_p_1 += 64, c778_p_0 += 64){
						// y = 4, x = 68, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h272, hp_0 = 0;
							h < h272 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 64, f = 32
							// T (x, 68) (68 / 1)
							for (x = x543, xp_1 = x543_p_0, xp_0 = 0;
								x < x543 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w310, wp_0 = 0;
									w < w310 + 3;
									w += 1, wp_0 += 1){
											mem_vec_4652 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4653 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4654 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4655 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c778, cp_2 = c778_p_1, cp_1 = c778_p_0, cp_0 = 0;
												c < c778 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4652);
												mem_vec_4652 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4653);
												mem_vec_4653 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4654);
												mem_vec_4654 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4655);
												mem_vec_4655 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4656);
												mem_vec_4656 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4657);
												mem_vec_4657 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4658);
												mem_vec_4658 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4659);
												mem_vec_4659 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4660);
												mem_vec_4660 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4661);
												mem_vec_4661 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4662);
												mem_vec_4662 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4663);
												mem_vec_4663 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4664);
												mem_vec_4664 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4665);
												mem_vec_4665 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4666);
												mem_vec_4666 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4667);
												mem_vec_4667 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4652);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4653);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4654);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4655);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4663);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4664);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4665);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4666);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4667);
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