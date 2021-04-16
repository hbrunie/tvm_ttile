#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (8, y); T (2, f); T (28, x); T (1, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, x, xp_0, x10_p_0, x11_p_0, x12_p_0, xp_1, x10_p_1, x11_p_1, xp_2, x10_p_2, xp_3, x10, x11, x12, y, yp_0, y8_p_0, y9_p_0, yp_1, y8_p_1, yp_2, y8, y9;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y10 = 0;
IND_TYPE x13 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_28 ,mem_vec_29 ,mem_vec_30 ,mem_vec_31 ,mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_40 ,mem_vec_41 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y9 = y10, y9_p_0 = 0;
	y9 < y10 + 56;
	y9 += 56, y9_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x12 = x13, x12_p_0 = 0;
		x12 < x13 + 56;
		x12 += 56, x12_p_0 += 56){
		// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y8 = y9, y8_p_1 = y9_p_0, y8_p_0 = 0;
			y8 < y9 + 56;
			y8 += 56, y8_p_1 += 56, y8_p_0 += 56){
			// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (56 / 2)
			for (x11 = x12, x11_p_1 = x12_p_0, x11_p_0 = 0;
				x11 < x12 + 56;
				x11 += 2, x11_p_1 += 2, x11_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f4, fp_0 = 0;
					f < f4 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y8, yp_2 = y8_p_1, yp_1 = y8_p_0, yp_0 = 0;
						y < y8 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x10 = x11, x10_p_2 = x11_p_1, x10_p_1 = x11_p_0, x10_p_0 = 0;
							x10 < x11 + 2;
							x10 += 2, x10_p_2 += 2, x10_p_1 += 2, x10_p_0 += 2){
							// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c6 = c7, c6_p_0 = 0;
								c6 < c7 + 64;
								c6 += 16, c6_p_0 += 16){
								// y = 7, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x10, xp_3 = x10_p_2, xp_2 = x10_p_1, xp_1 = x10_p_0, xp_0 = 0;
									x < x10 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_28 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_29 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_30 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_31 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_32 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_33 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_40 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_41 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c6, cp_1 = c6_p_0, cp_0 = 0;
												c < c6 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_28);
												mem_vec_28 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_29);
												mem_vec_29 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_30);
												mem_vec_30 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_31);
												mem_vec_31 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_32);
												mem_vec_32 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_33);
												mem_vec_33 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_34);
												mem_vec_34 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_35);
												mem_vec_35 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_36);
												mem_vec_36 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_37);
												mem_vec_37 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_38);
												mem_vec_38 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_39);
												mem_vec_39 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_40);
												mem_vec_40 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_41);
												mem_vec_41 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_28);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_29);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_30);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_31);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_32);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_33);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_34);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_35);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_36);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_37);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_38);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_39);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_40);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_41);
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