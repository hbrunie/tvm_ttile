#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (1, x); T (4, y); T (8, f); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x34_p_0, x35_p_0, xp_1, x34_p_1, xp_2, x34, x35, y, yp_0, y30_p_0, yp_1, y30;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y31 = 0;
IND_TYPE x36 = 0;
IND_TYPE h14 = 0;
IND_TYPE w16 = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,mem_vec_289 ,mem_vec_290 ,mem_vec_291 ,mem_vec_292 ,mem_vec_293 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y30 = y31, y30_p_0 = 0;
	y30 < y31 + 28;
	y30 += 28, y30_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x35 = x36, x35_p_0 = 0;
		x35 < x36 + 28;
		x35 += 28, x35_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f20, fp_0 = 0;
			f < f20 + 256;
			f += 32, fp_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 32
			// T (y, 4) (28 / 7)
			for (y = y30, yp_1 = y30_p_0, yp_0 = 0;
				y < y30 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = 7, x = 28, h = 3, w = 3, c = 256, f = 32
				// T (x, 1) (28 / 28)
				for (x34 = x35, x34_p_1 = x35_p_0, x34_p_0 = 0;
					x34 < x35 + 28;
					x34 += 28, x34_p_1 += 28, x34_p_0 += 28){
					// y = 7, x = 28, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c30 = c31, c30_p_0 = 0;
						c30 < c31 + 256;
						c30 += 32, c30_p_0 += 32){
						// y = 7, x = 28, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 28, h = 3, w = 1, c = 32, f = 32
							// T (x, 28) (28 / 1)
							for (x = x34, xp_2 = x34_p_1, xp_1 = x34_p_0, xp_0 = 0;
								x < x34 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h14, hp_0 = 0;
									h < h14 + 3;
									h += 1, hp_0 += 1){
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
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
												c < c30 + 32;
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