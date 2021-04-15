#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (8, c); T (1, x); T (7, y); T (8, f); T (4, c); T (14, x)]
*/
IND_TYPE c, cp_0, c104_p_0, c105_p_0, cp_1, c104_p_1, cp_2, c104, c105, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x104_p_0, x105_p_0, xp_1, x104_p_1, xp_2, x104, x105, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y52 = 0;
IND_TYPE x106 = 0;
IND_TYPE h52 = 0;
IND_TYPE w52 = 0;
IND_TYPE c106 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (x, 14) (28 / 2)
for (x105 = x106, x105_p_0 = 0;
	x105 < x106 + 28;
	x105 += 2, x105_p_0 += 2){
	// y = 28, x = 2, h = 3, w = 3, c = 128, f = 256
	// T (c, 4) (128 / 32)
	for (c105 = c106, c105_p_0 = 0;
		c105 < c106 + 128;
		c105 += 32, c105_p_0 += 32){
		// y = 28, x = 2, h = 3, w = 3, c = 32, f = 256
		// T (f, 8) (256 / 32)
		for (f = f52, fp_0 = 0;
			f < f52 + 256;
			f += 32, fp_0 += 32){
			// y = 28, x = 2, h = 3, w = 3, c = 32, f = 32
			// T (y, 7) (28 / 4)
			for (y = y52, yp_0 = 0;
				y < y52 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (2 / 2)
				for (x104 = x105, x104_p_1 = x105_p_0, x104_p_0 = 0;
					x104 < x105 + 2;
					x104 += 2, x104_p_1 += 2, x104_p_0 += 2){
					// y = 4, x = 2, h = 3, w = 3, c = 32, f = 32
					// T (c, 8) (32 / 4)
					for (c104 = c105, c104_p_1 = c105_p_0, c104_p_0 = 0;
						c104 < c105 + 32;
						c104 += 4, c104_p_1 += 4, c104_p_0 += 4){
						// y = 4, x = 2, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h52, hp_0 = 0;
							h < h52 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 2, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w52, wp_0 = 0;
								w < w52 + 3;
								w += 1, wp_0 += 1){
								// y = 4, x = 2, h = 1, w = 1, c = 4, f = 32
								// T (x, 2) (2 / 1)
								for (x = x104, xp_2 = x104_p_1, xp_1 = x104_p_0, xp_0 = 0;
									x < x104 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_416 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_417 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_418 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_419 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = 4, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c104, cp_2 = c104_p_1, cp_1 = c104_p_0, cp_0 = 0;
												c < c104 + 4;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_416);
												mem_vec_416 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_417);
												mem_vec_417 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_418);
												mem_vec_418 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_419);
												mem_vec_419 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_420);
												mem_vec_420 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_421);
												mem_vec_421 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_422);
												mem_vec_422 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_423);
												mem_vec_423 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_424);
												mem_vec_424 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_425);
												mem_vec_425 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_426);
												mem_vec_426 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_427);
												mem_vec_427 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_428);
												mem_vec_428 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_429);
												mem_vec_429 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_430);
												mem_vec_430 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_431);
												mem_vec_431 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_416);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_417);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_418);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_419);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_420);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_421);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_422);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_423);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_424);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_425);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_426);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_427);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_428);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_429);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_430);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_431);
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