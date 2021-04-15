#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (7, y); T (2, f); T (1, x); T (1, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, x, xp_0, x140_p_0, x141_p_0, x142_p_0, xp_1, x140_p_1, x141_p_1, xp_2, x140_p_2, xp_3, x140, x141, x142, y, yp_0, y112_p_0, y113_p_0, yp_1, y112_p_1, yp_2, y112, y113;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y114 = 0;
IND_TYPE x143 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c85 = 0;
IND_TYPE f56 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,mem_vec_453 ,mem_vec_454 ,mem_vec_455 ,mem_vec_456 ,mem_vec_457 ,mem_vec_458 ,mem_vec_459 ,mem_vec_460 ,mem_vec_461 ,mem_vec_462 ,mem_vec_463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y113 = y114, y113_p_0 = 0;
	y113 < y114 + 56;
	y113 += 56, y113_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x142 = x143, x142_p_0 = 0;
		x142 < x143 + 56;
		x142 += 1, x142_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y112 = y113, y112_p_1 = y113_p_0, y112_p_0 = 0;
			y112 < y113 + 56;
			y112 += 56, y112_p_1 += 56, y112_p_0 += 56){
			// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x141 = x142, x141_p_1 = x142_p_0, x141_p_0 = 0;
				x141 < x142 + 1;
				x141 += 1, x141_p_1 += 1, x141_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f56, fp_0 = 0;
					f < f56 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y112, yp_2 = y112_p_1, yp_1 = y112_p_0, yp_0 = 0;
						y < y112 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x140 = x141, x140_p_2 = x141_p_1, x140_p_1 = x141_p_0, x140_p_0 = 0;
							x140 < x141 + 1;
							x140 += 1, x140_p_2 += 1, x140_p_1 += 1, x140_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c84 = c85, c84_p_0 = 0;
								c84 < c85 + 64;
								c84 += 32, c84_p_0 += 32){
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x140, xp_3 = x140_p_2, xp_2 = x140_p_1, xp_1 = x140_p_0, xp_0 = 0;
									x < x140 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
												c < c84 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_448);
												mem_vec_448 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_449);
												mem_vec_449 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_450);
												mem_vec_450 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_451);
												mem_vec_451 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_452);
												mem_vec_452 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_453);
												mem_vec_453 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_454);
												mem_vec_454 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_455);
												mem_vec_455 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_456);
												mem_vec_456 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_457);
												mem_vec_457 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_458);
												mem_vec_458 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_459);
												mem_vec_459 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_460);
												mem_vec_460 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_461);
												mem_vec_461 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_462);
												mem_vec_462 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_463);
												mem_vec_463 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_453);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_457);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_459);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_463);
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