#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (8, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, x, xp_0, x110_p_0, x111_p_0, x112_p_0, xp_1, x110_p_1, x111_p_1, xp_2, x110_p_2, xp_3, x110, x111, x112, y, yp_0, y88_p_0, y89_p_0, yp_1, y88_p_1, yp_2, y88, y89;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y90 = 0;
IND_TYPE x113 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c67 = 0;
IND_TYPE f44 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y89 = y90, y89_p_0 = 0;
	y89 < y90 + 56;
	y89 += 56, y89_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x112 = x113, x112_p_0 = 0;
		x112 < x113 + 56;
		x112 += 2, x112_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y88 = y89, y88_p_1 = y89_p_0, y88_p_0 = 0;
			y88 < y89 + 56;
			y88 += 56, y88_p_1 += 56, y88_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x111 = x112, x111_p_1 = x112_p_0, x111_p_0 = 0;
				x111 < x112 + 2;
				x111 += 2, x111_p_1 += 2, x111_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f44, fp_0 = 0;
					f < f44 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y88, yp_2 = y88_p_1, yp_1 = y88_p_0, yp_0 = 0;
						y < y88 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x110 = x111, x110_p_2 = x111_p_1, x110_p_1 = x111_p_0, x110_p_0 = 0;
							x110 < x111 + 2;
							x110 += 1, x110_p_2 += 1, x110_p_1 += 1, x110_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c66 = c67, c66_p_0 = 0;
								c66 < c67 + 64;
								c66 += 32, c66_p_0 += 32){
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x110, xp_3 = x110_p_2, xp_2 = x110_p_1, xp_1 = x110_p_0, xp_0 = 0;
									x < x110 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
												c < c66 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_308);
												mem_vec_308 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_309);
												mem_vec_309 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_310);
												mem_vec_310 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_311);
												mem_vec_311 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_312);
												mem_vec_312 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_313);
												mem_vec_313 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_314);
												mem_vec_314 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_315);
												mem_vec_315 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_316);
												mem_vec_316 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_317);
												mem_vec_317 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_318);
												mem_vec_318 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_319);
												mem_vec_319 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_320);
												mem_vec_320 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_321);
												mem_vec_321 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_309);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_315);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_316);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_317);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_318);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_319);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_320);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_321);
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