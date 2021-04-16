#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (8, x); T (2, y); T (2, f); T (17, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c420_p_0, cp_1, c420, f, fp_0, x, xp_0, x700_p_0, x701_p_0, x702_p_0, xp_1, x700_p_1, x701_p_1, xp_2, x700_p_2, xp_3, x700, x701, x702, y, yp_0, y560_p_0, y561_p_0, yp_1, y560_p_1, yp_2, y560, y561;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y562 = 0;
IND_TYPE x703 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c421 = 0;
IND_TYPE f280 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4160 ,mem_vec_4161 ,mem_vec_4162 ,mem_vec_4163 ,mem_vec_4164 ,mem_vec_4165 ,mem_vec_4166 ,mem_vec_4167 ,mem_vec_4168 ,mem_vec_4169 ,mem_vec_4170 ,mem_vec_4171 ,mem_vec_4172 ,mem_vec_4173 ,mem_vec_4174 ,mem_vec_4175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y561 = y562, y561_p_0 = 0;
	y561 < y562 + 136;
	y561 += 136, y561_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x702 = x703, x702_p_0 = 0;
		x702 < x703 + 136;
		x702 += 136, x702_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y560 = y561, y560_p_1 = y561_p_0, y560_p_0 = 0;
			y560 < y561 + 136;
			y560 += 8, y560_p_1 += 8, y560_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 17) (136 / 8)
			for (x701 = x702, x701_p_1 = x702_p_0, x701_p_0 = 0;
				x701 < x702 + 136;
				x701 += 8, x701_p_1 += 8, x701_p_0 += 8){
				// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f280, fp_0 = 0;
					f < f280 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y560, yp_2 = y560_p_1, yp_1 = y560_p_0, yp_0 = 0;
						y < y560 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 8, h = 1, w = 1, c = 128, f = 32
						// T (x, 8) (8 / 1)
						for (x700 = x701, x700_p_2 = x701_p_1, x700_p_1 = x701_p_0, x700_p_0 = 0;
							x700 < x701 + 8;
							x700 += 1, x700_p_2 += 1, x700_p_1 += 1, x700_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c420 = c421, c420_p_0 = 0;
								c420 < c421 + 128;
								c420 += 128, c420_p_0 += 128){
								// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x700, xp_3 = x700_p_2, xp_2 = x700_p_1, xp_1 = x700_p_0, xp_0 = 0;
									x < x700 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c420, cp_1 = c420_p_0, cp_0 = 0;
												c < c420 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4160);
												mem_vec_4160 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4161);
												mem_vec_4161 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4162);
												mem_vec_4162 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4163);
												mem_vec_4163 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4164);
												mem_vec_4164 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4165);
												mem_vec_4165 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4166);
												mem_vec_4166 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4167);
												mem_vec_4167 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4168);
												mem_vec_4168 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4169);
												mem_vec_4169 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4170);
												mem_vec_4170 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4171);
												mem_vec_4171 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4172);
												mem_vec_4172 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4173);
												mem_vec_4173 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4174);
												mem_vec_4174 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4175);
												mem_vec_4175 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4161);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4175);
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