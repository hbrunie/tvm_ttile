#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (17, y); T (2, f); T (136, x); T (1, y); T (1, x); T (2, y)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, x, xp_0, x20_p_0, x21_p_0, x22_p_0, xp_1, x20_p_1, x21_p_1, xp_2, x20_p_2, xp_3, x20, x21, x22, y, yp_0, y16_p_0, y17_p_0, yp_1, y16_p_1, yp_2, y16, y17;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y18 = 0;
IND_TYPE x23 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c13 = 0;
IND_TYPE f8 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,mem_vec_68 ,mem_vec_69 ,mem_vec_70 ,mem_vec_71 ,mem_vec_72 ,mem_vec_73 ,mem_vec_74 ,mem_vec_75 ,mem_vec_76 ,mem_vec_77 ,mem_vec_78 ,mem_vec_79 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y17 = y18, y17_p_0 = 0;
	y17 < y18 + 136;
	y17 += 68, y17_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x22 = x23, x22_p_0 = 0;
		x22 < x23 + 136;
		x22 += 136, x22_p_0 += 136){
		// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 1) (68 / 68)
		for (y16 = y17, y16_p_1 = y17_p_0, y16_p_0 = 0;
			y16 < y17 + 68;
			y16 += 68, y16_p_1 += 68, y16_p_0 += 68){
			// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 136) (136 / 1)
			for (x21 = x22, x21_p_1 = x22_p_0, x21_p_0 = 0;
				x21 < x22 + 136;
				x21 += 1, x21_p_1 += 1, x21_p_0 += 1){
				// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f8, fp_0 = 0;
					f < f8 + 64;
					f += 32, fp_0 += 32){
					// y = 68, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 17) (68 / 4)
					for (y = y16, yp_2 = y16_p_1, yp_1 = y16_p_0, yp_0 = 0;
						y < y16 + 68;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x20 = x21, x20_p_2 = x21_p_1, x20_p_1 = x21_p_0, x20_p_0 = 0;
							x20 < x21 + 1;
							x20 += 1, x20_p_2 += 1, x20_p_1 += 1, x20_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 1) (128 / 128)
							for (c12 = c13, c12_p_0 = 0;
								c12 < c13 + 128;
								c12 += 128, c12_p_0 += 128){
								// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (x, 1) (1 / 1)
								for (x = x20, xp_3 = x20_p_2, xp_2 = x20_p_1, xp_1 = x20_p_0, xp_0 = 0;
									x < x20 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_64 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_65 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_66 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_67 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_68 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_69 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_70 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_71 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_72 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_73 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_74 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_75 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_76 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_77 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_78 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_79 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
												c < c12 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_64);
												mem_vec_64 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_65);
												mem_vec_65 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_66);
												mem_vec_66 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_67);
												mem_vec_67 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_68);
												mem_vec_68 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_69);
												mem_vec_69 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_70);
												mem_vec_70 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_71);
												mem_vec_71 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_72);
												mem_vec_72 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_73);
												mem_vec_73 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_74);
												mem_vec_74 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_75);
												mem_vec_75 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_76);
												mem_vec_76 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_77);
												mem_vec_77 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_78);
												mem_vec_78 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_79);
												mem_vec_79 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_64);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_65);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_66);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_67);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_68);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_69);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_70);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_71);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_72);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_73);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_74);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_75);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_76);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_77);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_78);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_79);
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