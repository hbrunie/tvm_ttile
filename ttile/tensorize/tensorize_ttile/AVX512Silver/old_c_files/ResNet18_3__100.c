#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (1, y); T (2, f); T (1, x); T (8, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, x, xp_0, x100_p_0, x101_p_0, x102_p_0, xp_1, x100_p_1, x101_p_1, xp_2, x100_p_2, xp_3, x100, x101, x102, y, yp_0, y80_p_0, y81_p_0, yp_1, y80_p_1, yp_2, y80, y81;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y82 = 0;
IND_TYPE x103 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y81 = y82, y81_p_0 = 0;
	y81 < y82 + 56;
	y81 += 56, y81_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x102 = x103, x102_p_0 = 0;
		x102 < x103 + 56;
		x102 += 2, x102_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 8) (56 / 7)
		for (y80 = y81, y80_p_1 = y81_p_0, y80_p_0 = 0;
			y80 < y81 + 56;
			y80 += 7, y80_p_1 += 7, y80_p_0 += 7){
			// y = 7, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x101 = x102, x101_p_1 = x102_p_0, x101_p_0 = 0;
				x101 < x102 + 2;
				x101 += 2, x101_p_1 += 2, x101_p_0 += 2){
				// y = 7, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f40, fp_0 = 0;
					f < f40 + 64;
					f += 32, fp_0 += 32){
					// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (7 / 7)
					for (y = y80, yp_2 = y80_p_1, yp_1 = y80_p_0, yp_0 = 0;
						y < y80 + 7;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x100 = x101, x100_p_2 = x101_p_1, x100_p_1 = x101_p_0, x100_p_0 = 0;
							x100 < x101 + 2;
							x100 += 2, x100_p_2 += 2, x100_p_1 += 2, x100_p_0 += 2){
							// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c60 = c61, c60_p_0 = 0;
								c60 < c61 + 64;
								c60 += 16, c60_p_0 += 16){
								// y = 7, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x100, xp_3 = x100_p_2, xp_2 = x100_p_1, xp_1 = x100_p_0, xp_0 = 0;
									x < x100 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
												c < c60 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_280);
												mem_vec_280 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_281);
												mem_vec_281 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_282);
												mem_vec_282 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_283);
												mem_vec_283 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_284);
												mem_vec_284 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_285);
												mem_vec_285 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_286);
												mem_vec_286 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_287);
												mem_vec_287 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_288);
												mem_vec_288 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_289);
												mem_vec_289 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_290);
												mem_vec_290 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_291);
												mem_vec_291 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_292);
												mem_vec_292 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_293);
												mem_vec_293 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_280);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_281);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_282);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_283);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_284);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_285);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_286);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_287);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_288);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_289);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_290);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_291);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_292);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_293);
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