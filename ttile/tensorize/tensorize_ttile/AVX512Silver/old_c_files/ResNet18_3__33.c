#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, x, xp_0, x230_p_0, x231_p_0, x232_p_0, xp_1, x230_p_1, x231_p_1, xp_2, x230_p_2, xp_3, x230, x231, x232, y, yp_0, y184_p_0, y185_p_0, yp_1, y184_p_1, yp_2, y184, y185;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y186 = 0;
IND_TYPE x233 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y185 = y186, y185_p_0 = 0;
	y185 < y186 + 56;
	y185 += 56, y185_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x232 = x233, x232_p_0 = 0;
		x232 < x233 + 56;
		x232 += 1, x232_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y184 = y185, y184_p_1 = y185_p_0, y184_p_0 = 0;
			y184 < y185 + 56;
			y184 += 56, y184_p_1 += 56, y184_p_0 += 56){
			// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x231 = x232, x231_p_1 = x232_p_0, x231_p_0 = 0;
				x231 < x232 + 1;
				x231 += 1, x231_p_1 += 1, x231_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f92, fp_0 = 0;
					f < f92 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y184, yp_2 = y184_p_1, yp_1 = y184_p_0, yp_0 = 0;
						y < y184 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x230 = x231, x230_p_2 = x231_p_1, x230_p_1 = x231_p_0, x230_p_0 = 0;
							x230 < x231 + 1;
							x230 += 1, x230_p_2 += 1, x230_p_1 += 1, x230_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c138 = c139, c138_p_0 = 0;
								c138 < c139 + 64;
								c138 += 32, c138_p_0 += 32){
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x230, xp_3 = x230_p_2, xp_2 = x230_p_1, xp_1 = x230_p_0, xp_0 = 0;
									x < x230 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
												c < c138 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_644);
												mem_vec_644 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_645);
												mem_vec_645 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_646);
												mem_vec_646 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_647);
												mem_vec_647 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_648);
												mem_vec_648 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_649);
												mem_vec_649 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_650);
												mem_vec_650 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_651);
												mem_vec_651 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_652);
												mem_vec_652 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_653);
												mem_vec_653 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_654);
												mem_vec_654 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_655);
												mem_vec_655 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_656);
												mem_vec_656 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_657);
												mem_vec_657 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_644);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_645);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_646);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_647);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_648);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_649);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_650);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_651);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_652);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_653);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_654);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_655);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_656);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_657);
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