#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, f);
  T (64, c); T (16, f)]
*/
IND_TYPE c, cp_0, c32_p_0, c33_p_0, cp_1, c32_p_1, cp_2, c32, c33, f, fp_0, f24_p_0, fp_1, f24, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y16 = 0;
IND_TYPE x16 = 0;
IND_TYPE h14 = 0;
IND_TYPE w16 = 0;
IND_TYPE c34 = 0;
IND_TYPE f25 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,mem_vec_272 ,mem_vec_273 ,mem_vec_274 ,mem_vec_275 ,mem_vec_276 ,mem_vec_277 ,mem_vec_278 ,mem_vec_279 ,mem_vec_280 ,mem_vec_281 ,mem_vec_282 ,mem_vec_283 ,mem_vec_284 ,mem_vec_285 ,mem_vec_286 ,mem_vec_287 ,mem_vec_288 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f24 = f25, f24_p_0 = 0;
	f24 < f25 + 1024;
	f24 += 64, f24_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 64) (512 / 8)
	for (c33 = c34, c33_p_0 = 0;
		c33 < c34 + 512;
		c33 += 8, c33_p_0 += 8){
		// y = 17, x = 17, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f24, fp_1 = f24_p_0, fp_0 = 0;
			f < f24 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y16, yp_0 = 0;
					y < y16 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
					// T (c, 1) (8 / 8)
					for (c32 = c33, c32_p_1 = c33_p_0, c32_p_0 = 0;
						c32 < c33 + 8;
						c32 += 8, c32_p_1 += 8, c32_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x16, xp_0 = 0;
							x < x16 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h14, hp_0 = 0;
								h < h14 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w16, wp_0 = 0;
									w < w16 + 3;
									w += 1, wp_0 += 1){
											mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c32, cp_2 = c32_p_1, cp_1 = c32_p_0, cp_0 = 0;
												c < c32 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_255);
												mem_vec_255 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_256);
												mem_vec_256 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_257);
												mem_vec_257 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_258);
												mem_vec_258 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_259);
												mem_vec_259 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_260);
												mem_vec_260 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_261);
												mem_vec_261 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_262);
												mem_vec_262 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_263);
												mem_vec_263 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_264);
												mem_vec_264 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_265);
												mem_vec_265 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_266);
												mem_vec_266 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_267);
												mem_vec_267 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_268);
												mem_vec_268 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_269);
												mem_vec_269 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_270);
												mem_vec_270 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_255);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_256);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_257);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_258);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_259);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_260);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_261);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_262);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_263);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_264);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_265);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_266);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_267);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_268);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_269);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_270);
								}
							}
						}
					}
				}
				for (y = y16 + 8, yp_0 = 0;
					y < y16 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
					// T (c, 1) (8 / 8)
					for (c32 = c33, c32_p_1 = c33_p_0, c32_p_0 = 0;
						c32 < c33 + 8;
						c32 += 8, c32_p_1 += 8, c32_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x16, xp_0 = 0;
							x < x16 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h14, hp_0 = 0;
								h < h14 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w16, wp_0 = 0;
									w < w16 + 3;
									w += 1, wp_0 += 1){
											mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_272 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c32, cp_2 = c32_p_1, cp_1 = c32_p_0, cp_0 = 0;
												c < c32 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_271);
												mem_vec_271 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_272);
												mem_vec_272 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_273);
												mem_vec_273 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_274);
												mem_vec_274 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_275);
												mem_vec_275 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_276);
												mem_vec_276 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_277);
												mem_vec_277 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_278);
												mem_vec_278 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_279);
												mem_vec_279 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_280);
												mem_vec_280 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_281);
												mem_vec_281 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_282);
												mem_vec_282 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_283);
												mem_vec_283 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_284);
												mem_vec_284 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_285);
												mem_vec_285 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_286);
												mem_vec_286 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_287);
												mem_vec_287 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_288);
												mem_vec_288 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_271);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_272);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_273);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_274);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_275);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_276);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_277);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_278);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_279);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_280);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_281);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_282);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_283);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_284);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_285);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_286);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_287);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_288);
								}
							}
						}
					}
				}
		}
	}
}


}