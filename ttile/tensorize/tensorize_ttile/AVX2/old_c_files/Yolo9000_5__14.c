#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (2, y); T (2, f); T (68, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c543_p_0, cp_1, c543, f, fp_0, x, xp_0, x905_p_0, x906_p_0, x907_p_0, xp_1, x905_p_1, x906_p_1, xp_2, x905_p_2, xp_3, x905, x906, x907, y, yp_0, y724_p_0, y725_p_0, yp_1, y724_p_1, yp_2, y724, y725;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y726 = 0;
IND_TYPE x908 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c544 = 0;
IND_TYPE f362 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4816 ,mem_vec_4817 ,mem_vec_4818 ,mem_vec_4819 ,mem_vec_4820 ,mem_vec_4821 ,mem_vec_4822 ,mem_vec_4823 ,mem_vec_4824 ,mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y725 = y726, y725_p_0 = 0;
	y725 < y726 + 136;
	y725 += 136, y725_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x907 = x908, x907_p_0 = 0;
		x907 < x908 + 136;
		x907 += 136, x907_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y724 = y725, y724_p_1 = y725_p_0, y724_p_0 = 0;
			y724 < y725 + 136;
			y724 += 8, y724_p_1 += 8, y724_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 68) (136 / 2)
			for (x906 = x907, x906_p_1 = x907_p_0, x906_p_0 = 0;
				x906 < x907 + 136;
				x906 += 2, x906_p_1 += 2, x906_p_0 += 2){
				// y = 8, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f362, fp_0 = 0;
					f < f362 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y724, yp_2 = y724_p_1, yp_1 = y724_p_0, yp_0 = 0;
						y < y724 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (x, 2) (2 / 1)
						for (x905 = x906, x905_p_2 = x906_p_1, x905_p_1 = x906_p_0, x905_p_0 = 0;
							x905 < x906 + 2;
							x905 += 1, x905_p_2 += 1, x905_p_1 += 1, x905_p_0 += 1){
							// y = 4, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c543 = c544, c543_p_0 = 0;
								c543 < c544 + 128;
								c543 += 64, c543_p_0 += 64){
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x905, xp_3 = x905_p_2, xp_2 = x905_p_1, xp_1 = x905_p_0, xp_0 = 0;
									x < x905 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4816 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4817 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4818 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4819 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c543, cp_1 = c543_p_0, cp_0 = 0;
												c < c543 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4816);
												mem_vec_4816 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4817);
												mem_vec_4817 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4818);
												mem_vec_4818 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4819);
												mem_vec_4819 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4820);
												mem_vec_4820 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4821);
												mem_vec_4821 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4822);
												mem_vec_4822 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4823);
												mem_vec_4823 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4824);
												mem_vec_4824 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4825);
												mem_vec_4825 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4826);
												mem_vec_4826 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4827);
												mem_vec_4827 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4828);
												mem_vec_4828 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4829);
												mem_vec_4829 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4830);
												mem_vec_4830 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4831);
												mem_vec_4831 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4819);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4820);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4821);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4822);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4823);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4831);
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