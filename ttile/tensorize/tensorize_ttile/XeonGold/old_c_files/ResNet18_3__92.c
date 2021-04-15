#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (7, y); T (2, f); T (1, x); T (1, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, x, xp_0, x145_p_0, x146_p_0, x147_p_0, xp_1, x145_p_1, x146_p_1, xp_2, x145_p_2, xp_3, x145, x146, x147, y, yp_0, y116_p_0, y117_p_0, yp_1, y116_p_1, yp_2, y116, y117;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y118 = 0;
IND_TYPE x148 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c88 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y117 = y118, y117_p_0 = 0;
	y117 < y118 + 56;
	y117 += 56, y117_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x147 = x148, x147_p_0 = 0;
		x147 < x148 + 56;
		x147 += 1, x147_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y116 = y117, y116_p_1 = y117_p_0, y116_p_0 = 0;
			y116 < y117 + 56;
			y116 += 56, y116_p_1 += 56, y116_p_0 += 56){
			// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x146 = x147, x146_p_1 = x147_p_0, x146_p_0 = 0;
				x146 < x147 + 1;
				x146 += 1, x146_p_1 += 1, x146_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f58, fp_0 = 0;
					f < f58 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y116, yp_2 = y116_p_1, yp_1 = y116_p_0, yp_0 = 0;
						y < y116 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x145 = x146, x145_p_2 = x146_p_1, x145_p_1 = x146_p_0, x145_p_0 = 0;
							x145 < x146 + 1;
							x145 += 1, x145_p_2 += 1, x145_p_1 += 1, x145_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c87 = c88, c87_p_0 = 0;
								c87 < c88 + 64;
								c87 += 16, c87_p_0 += 16){
								// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x145, xp_3 = x145_p_2, xp_2 = x145_p_1, xp_1 = x145_p_0, xp_0 = 0;
									x < x145 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
												c < c87 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_464);
												mem_vec_464 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_465);
												mem_vec_465 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_466);
												mem_vec_466 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_467);
												mem_vec_467 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_468);
												mem_vec_468 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_469);
												mem_vec_469 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_470);
												mem_vec_470 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_471);
												mem_vec_471 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_472);
												mem_vec_472 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_473);
												mem_vec_473 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_474);
												mem_vec_474 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_475);
												mem_vec_475 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_476);
												mem_vec_476 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_477);
												mem_vec_477 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_478);
												mem_vec_478 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_479);
												mem_vec_479 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_479);
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