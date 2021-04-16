#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (34, x); T (17, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c447_p_0, cp_1, c447, f, fp_0, x, xp_0, x745_p_0, x746_p_0, x747_p_0, xp_1, x745_p_1, x746_p_1, xp_2, x745_p_2, xp_3, x745, x746, x747, y, yp_0, y596_p_0, y597_p_0, yp_1, y596_p_1, yp_2, y596, y597;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y598 = 0;
IND_TYPE x748 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c448 = 0;
IND_TYPE f298 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_4304 ,mem_vec_4305 ,mem_vec_4306 ,mem_vec_4307 ,mem_vec_4308 ,mem_vec_4309 ,mem_vec_4310 ,mem_vec_4311 ,mem_vec_4312 ,mem_vec_4313 ,mem_vec_4314 ,mem_vec_4315 ,mem_vec_4316 ,mem_vec_4317 ,mem_vec_4318 ,mem_vec_4319 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 1) (136 / 136)
for (y597 = y598, y597_p_0 = 0;
	y597 < y598 + 136;
	y597 += 136, y597_p_0 += 136){
	// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 1) (136 / 136)
	for (x747 = x748, x747_p_0 = 0;
		x747 < x748 + 136;
		x747 += 136, x747_p_0 += 136){
		// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (y, 17) (136 / 8)
		for (y596 = y597, y596_p_1 = y597_p_0, y596_p_0 = 0;
			y596 < y597 + 136;
			y596 += 8, y596_p_1 += 8, y596_p_0 += 8){
			// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (x, 34) (136 / 4)
			for (x746 = x747, x746_p_1 = x747_p_0, x746_p_0 = 0;
				x746 < x747 + 136;
				x746 += 4, x746_p_1 += 4, x746_p_0 += 4){
				// y = 8, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f298, fp_0 = 0;
					f < f298 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (y, 2) (8 / 4)
					for (y = y596, yp_2 = y596_p_1, yp_1 = y596_p_0, yp_0 = 0;
						y < y596 + 8;
						y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
						// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (4 / 4)
						for (x745 = x746, x745_p_2 = x746_p_1, x745_p_1 = x746_p_0, x745_p_0 = 0;
							x745 < x746 + 4;
							x745 += 4, x745_p_2 += 4, x745_p_1 += 4, x745_p_0 += 4){
							// y = 4, x = 4, h = 1, w = 1, c = 128, f = 32
							// T (c, 2) (128 / 64)
							for (c447 = c448, c447_p_0 = 0;
								c447 < c448 + 128;
								c447 += 64, c447_p_0 += 64){
								// y = 4, x = 4, h = 1, w = 1, c = 64, f = 32
								// T (x, 4) (4 / 1)
								for (x = x745, xp_3 = x745_p_2, xp_2 = x745_p_1, xp_1 = x745_p_0, xp_0 = 0;
									x < x745 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4304 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4305 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4306 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4307 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c447, cp_1 = c447_p_0, cp_0 = 0;
												c < c447 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4304);
												mem_vec_4304 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4305);
												mem_vec_4305 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4306);
												mem_vec_4306 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4307);
												mem_vec_4307 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4308);
												mem_vec_4308 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4309);
												mem_vec_4309 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4310);
												mem_vec_4310 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4311);
												mem_vec_4311 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4312);
												mem_vec_4312 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4313);
												mem_vec_4313 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4314);
												mem_vec_4314 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4315);
												mem_vec_4315 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4316);
												mem_vec_4316 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4317);
												mem_vec_4317 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4318);
												mem_vec_4318 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4319);
												mem_vec_4319 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4304);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4305);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4306);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4307);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4308);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4309);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4310);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4311);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4312);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4313);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4314);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4315);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4316);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4317);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4318);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4319);
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