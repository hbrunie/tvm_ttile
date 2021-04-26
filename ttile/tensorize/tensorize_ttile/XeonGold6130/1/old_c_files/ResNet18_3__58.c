#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (2, x); T (7, y); T (2, f); T (28, x); T (1, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, x, xp_0, x25_p_0, x26_p_0, x27_p_0, xp_1, x25_p_1, x26_p_1, xp_2, x25_p_2, xp_3, x25, x26, x27, y, yp_0, y20_p_0, y21_p_0, yp_1, y20_p_1, yp_2, y20, y21;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y22 = 0;
IND_TYPE x28 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c16 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_80 ,mem_vec_81 ,mem_vec_82 ,mem_vec_83 ,mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y21 = y22, y21_p_0 = 0;
	y21 < y22 + 56;
	y21 += 56, y21_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x27 = x28, x27_p_0 = 0;
		x27 < x28 + 56;
		x27 += 56, x27_p_0 += 56){
		// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y20 = y21, y20_p_1 = y21_p_0, y20_p_0 = 0;
			y20 < y21 + 56;
			y20 += 56, y20_p_1 += 56, y20_p_0 += 56){
			// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (56 / 2)
			for (x26 = x27, x26_p_1 = x27_p_0, x26_p_0 = 0;
				x26 < x27 + 56;
				x26 += 2, x26_p_1 += 2, x26_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f10, fp_0 = 0;
					f < f10 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y20, yp_2 = y20_p_1, yp_1 = y20_p_0, yp_0 = 0;
						y < y20 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x25 = x26, x25_p_2 = x26_p_1, x25_p_1 = x26_p_0, x25_p_0 = 0;
							x25 < x26 + 2;
							x25 += 1, x25_p_2 += 1, x25_p_1 += 1, x25_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c15 = c16, c15_p_0 = 0;
								c15 < c16 + 64;
								c15 += 16, c15_p_0 += 16){
								// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x25, xp_3 = x25_p_2, xp_2 = x25_p_1, xp_1 = x25_p_0, xp_0 = 0;
									x < x25 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_80 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_81 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_82 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_83 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_84 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_85 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_86 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_87 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
												c < c15 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_80);
												mem_vec_80 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_81);
												mem_vec_81 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_82);
												mem_vec_82 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_83);
												mem_vec_83 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_84);
												mem_vec_84 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_85);
												mem_vec_85 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_86);
												mem_vec_86 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_87);
												mem_vec_87 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_88);
												mem_vec_88 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_89);
												mem_vec_89 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_90);
												mem_vec_90 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_91);
												mem_vec_91 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_92);
												mem_vec_92 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_93);
												mem_vec_93 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_94);
												mem_vec_94 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_95);
												mem_vec_95 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_80);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_81);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_82);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_83);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_84);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_85);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_86);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_87);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_88);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_89);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_90);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_91);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_92);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_93);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_94);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_95);
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