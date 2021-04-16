#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (28, x); T (1, y); T (2, f); T (4, c); T (2, f); T (7, y); T (1, f)]
*/
IND_TYPE c, cp_0, c135_p_0, cp_1, c135, f, fp_0, f180_p_0, f181_p_0, fp_1, f180_p_1, fp_2, f180, f181, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y99_p_0, yp_1, y99;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y100 = 0;
IND_TYPE x90 = 0;
IND_TYPE h72 = 0;
IND_TYPE w72 = 0;
IND_TYPE c136 = 0;
IND_TYPE f182 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1152 ,mem_vec_1153 ,mem_vec_1154 ,mem_vec_1155 ,mem_vec_1156 ,mem_vec_1157 ,mem_vec_1158 ,mem_vec_1159 ,mem_vec_1160 ,mem_vec_1161 ,mem_vec_1162 ,mem_vec_1163 ,mem_vec_1164 ,mem_vec_1165 ,mem_vec_1166 ,mem_vec_1167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f181 = f182, f181_p_0 = 0;
	f181 < f182 + 128;
	f181 += 128, f181_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
	// T (y, 7) (28 / 4)
	for (y99 = y100, y99_p_0 = 0;
		y99 < y100 + 28;
		y99 += 4, y99_p_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 64, f = 128
		// T (f, 2) (128 / 64)
		for (f180 = f181, f180_p_1 = f181_p_0, f180_p_0 = 0;
			f180 < f181 + 128;
			f180 += 64, f180_p_1 += 64, f180_p_0 += 64){
			// y = 4, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (c, 4) (64 / 16)
			for (c135 = c136, c135_p_0 = 0;
				c135 < c136 + 64;
				c135 += 16, c135_p_0 += 16){
				// y = 4, x = 28, h = 3, w = 3, c = 16, f = 64
				// T (f, 2) (64 / 32)
				for (f = f180, fp_2 = f180_p_1, fp_1 = f180_p_0, fp_0 = 0;
					f < f180 + 64;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 16, f = 32
					// T (y, 1) (4 / 4)
					for (y = y99, yp_1 = y99_p_0, yp_0 = 0;
						y < y99 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 28, h = 3, w = 3, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x90, xp_0 = 0;
							x < x90 + 28;
							x += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h72, hp_0 = 0;
								h < h72 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w72, wp_0 = 0;
									w < w72 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1152 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1153 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1154 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1155 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c135, cp_1 = c135_p_0, cp_0 = 0;
												c < c135 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1152);
												mem_vec_1152 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1153);
												mem_vec_1153 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1154);
												mem_vec_1154 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1155);
												mem_vec_1155 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1156);
												mem_vec_1156 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1157);
												mem_vec_1157 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1158);
												mem_vec_1158 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1159);
												mem_vec_1159 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1160);
												mem_vec_1160 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1161);
												mem_vec_1161 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1162);
												mem_vec_1162 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1163);
												mem_vec_1163 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1164);
												mem_vec_1164 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1165);
												mem_vec_1165 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1166);
												mem_vec_1166 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1167);
												mem_vec_1167 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1152);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1153);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1154);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1155);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1156);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1157);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1158);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1159);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1161);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1167);
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