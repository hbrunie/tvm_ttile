#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (8, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (17, y); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, x, xp_0, x985_p_0, x986_p_0, x987_p_0, xp_1, x985_p_1, x986_p_1, xp_2, x985_p_2, xp_3, x985, x986, x987, y, yp_0, y788_p_0, y789_p_0, yp_1, y788_p_1, yp_2, y788, y789;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y790 = 0;
IND_TYPE x988 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c592 = 0;
IND_TYPE f394 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_5072 ,mem_vec_5073 ,mem_vec_5074 ,mem_vec_5075 ,mem_vec_5076 ,mem_vec_5077 ,mem_vec_5078 ,mem_vec_5079 ,mem_vec_5080 ,mem_vec_5081 ,mem_vec_5082 ,mem_vec_5083 ,mem_vec_5084 ,mem_vec_5085 ,mem_vec_5086 ,mem_vec_5087 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y789 = y790, y789_p_0 = 0;
	y789 < y790 + 136;
	y789 += 136, y789_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 17) (136 / 8)
	for (x987 = x988, x987_p_0 = 0;
		x987 < x988 + 136;
		x987 += 8, x987_p_0 += 8){
		// y = 136, x = 8, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y788 = y789, y788_p_1 = y789_p_0, y788_p_0 = 0;
			y788 < y789 + 136;
			y788 += 8, y788_p_1 += 8, y788_p_0 += 8){
			// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
			// T (x, 1) (8 / 8)
			for (x986 = x987, x986_p_1 = x987_p_0, x986_p_0 = 0;
				x986 < x987 + 8;
				x986 += 8, x986_p_1 += 8, x986_p_0 += 8){
				// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f394, fp_0 = 0;
					f < f394 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y788, yp_2 = y788_p_1, yp_1 = y788_p_0, yp_0 = 0;
						y < y788 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 8, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (8 / 8)
						for (x985 = x986, x985_p_2 = x986_p_1, x985_p_1 = x986_p_0, x985_p_0 = 0;
							x985 < x986 + 8;
							x985 += 8, x985_p_2 += 8, x985_p_1 += 8, x985_p_0 += 8){
							// y = 4, x = 8, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c591 = c592, c591_p_0 = 0;
								c591 < c592 + 128;
								c591 += 64, c591_p_0 += 64){
								// y = 4, x = 8, h = 1, w = 1, c = 64, f = 32
								// T (x, 8) (8 / 1)
								for (x = x985, xp_3 = x985_p_2, xp_2 = x985_p_1, xp_1 = x985_p_0, xp_0 = 0;
									x < x985 + 8;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5072 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5073 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5074 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5075 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5080 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5081 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5082 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5083 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5084 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5085 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5086 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5087 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
												c < c591 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5072);
												mem_vec_5072 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5073);
												mem_vec_5073 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5074);
												mem_vec_5074 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5075);
												mem_vec_5075 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5076);
												mem_vec_5076 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5077);
												mem_vec_5077 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5078);
												mem_vec_5078 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5079);
												mem_vec_5079 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5080);
												mem_vec_5080 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5081);
												mem_vec_5081 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5082);
												mem_vec_5082 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5083);
												mem_vec_5083 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5084);
												mem_vec_5084 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5085);
												mem_vec_5085 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5086);
												mem_vec_5086 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5087);
												mem_vec_5087 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5072);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5073);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5074);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5075);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5076);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5077);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5078);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5079);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5080);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5081);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5082);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5083);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5084);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5085);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5086);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5087);
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