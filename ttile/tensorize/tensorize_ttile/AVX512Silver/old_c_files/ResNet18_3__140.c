#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (8, y); T (2, f); T (2, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c99_p_0, cp_1, c99, f, fp_0, x, xp_0, x165_p_0, x166_p_0, x167_p_0, xp_1, x165_p_1, x166_p_1, xp_2, x165_p_2, xp_3, x165, x166, x167, y, yp_0, y132_p_0, y133_p_0, yp_1, y132_p_1, yp_2, y132, y133;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y134 = 0;
IND_TYPE x168 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c100 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_462 ,mem_vec_463 ,mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y133 = y134, y133_p_0 = 0;
	y133 < y134 + 56;
	y133 += 56, y133_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x167 = x168, x167_p_0 = 0;
		x167 < x168 + 56;
		x167 += 2, x167_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y132 = y133, y132_p_1 = y133_p_0, y132_p_0 = 0;
			y132 < y133 + 56;
			y132 += 56, y132_p_1 += 56, y132_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (2 / 1)
			for (x166 = x167, x166_p_1 = x167_p_0, x166_p_0 = 0;
				x166 < x167 + 2;
				x166 += 1, x166_p_1 += 1, x166_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f66, fp_0 = 0;
					f < f66 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y132, yp_2 = y132_p_1, yp_1 = y132_p_0, yp_0 = 0;
						y < y132 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x165 = x166, x165_p_2 = x166_p_1, x165_p_1 = x166_p_0, x165_p_0 = 0;
							x165 < x166 + 1;
							x165 += 1, x165_p_2 += 1, x165_p_1 += 1, x165_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c99 = c100, c99_p_0 = 0;
								c99 < c100 + 64;
								c99 += 64, c99_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x165, xp_3 = x165_p_2, xp_2 = x165_p_1, xp_1 = x165_p_0, xp_0 = 0;
									x < x165 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_462 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c99, cp_1 = c99_p_0, cp_0 = 0;
												c < c99 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_462);
												mem_vec_462 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_463);
												mem_vec_463 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_464);
												mem_vec_464 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_465);
												mem_vec_465 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_466);
												mem_vec_466 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_467);
												mem_vec_467 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_468);
												mem_vec_468 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_469);
												mem_vec_469 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_470);
												mem_vec_470 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_471);
												mem_vec_471 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_472);
												mem_vec_472 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_473);
												mem_vec_473 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_474);
												mem_vec_474 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_475);
												mem_vec_475 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_463);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_475);
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