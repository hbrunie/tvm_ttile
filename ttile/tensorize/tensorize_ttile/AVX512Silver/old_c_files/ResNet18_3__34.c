#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (8, y); T (2, f); T (2, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, x, xp_0, x170_p_0, x171_p_0, x172_p_0, xp_1, x170_p_1, x171_p_1, xp_2, x170_p_2, xp_3, x170, x171, x172, y, yp_0, y136_p_0, y137_p_0, yp_1, y136_p_1, yp_2, y136, y137;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y138 = 0;
IND_TYPE x173 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c103 = 0;
IND_TYPE f68 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y137 = y138, y137_p_0 = 0;
	y137 < y138 + 56;
	y137 += 56, y137_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x172 = x173, x172_p_0 = 0;
		x172 < x173 + 56;
		x172 += 2, x172_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y136 = y137, y136_p_1 = y137_p_0, y136_p_0 = 0;
			y136 < y137 + 56;
			y136 += 56, y136_p_1 += 56, y136_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (2 / 1)
			for (x171 = x172, x171_p_1 = x172_p_0, x171_p_0 = 0;
				x171 < x172 + 2;
				x171 += 1, x171_p_1 += 1, x171_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f68, fp_0 = 0;
					f < f68 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y136, yp_2 = y136_p_1, yp_1 = y136_p_0, yp_0 = 0;
						y < y136 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x170 = x171, x170_p_2 = x171_p_1, x170_p_1 = x171_p_0, x170_p_0 = 0;
							x170 < x171 + 1;
							x170 += 1, x170_p_2 += 1, x170_p_1 += 1, x170_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c102 = c103, c102_p_0 = 0;
								c102 < c103 + 64;
								c102 += 32, c102_p_0 += 32){
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x170, xp_3 = x170_p_2, xp_2 = x170_p_1, xp_1 = x170_p_0, xp_0 = 0;
									x < x170 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
												c < c102 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_476);
												mem_vec_476 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_477);
												mem_vec_477 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_478);
												mem_vec_478 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_479);
												mem_vec_479 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_480);
												mem_vec_480 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_481);
												mem_vec_481 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_482);
												mem_vec_482 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_483);
												mem_vec_483 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_484);
												mem_vec_484 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_485);
												mem_vec_485 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_486);
												mem_vec_486 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_487);
												mem_vec_487 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_488);
												mem_vec_488 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_489);
												mem_vec_489 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_489);
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