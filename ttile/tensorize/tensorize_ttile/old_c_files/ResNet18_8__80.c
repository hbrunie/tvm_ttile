#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (8, f); T (1, c); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (1, f)]
*/
IND_TYPE c, cp_0, c636_p_0, cp_1, c636, f, fp_0, f708_p_0, fp_1, f708, h, hp_0, w, wp_0, x, xp_0, x636_p_0, xp_1, x636, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y424 = 0;
IND_TYPE x637 = 0;
IND_TYPE h350 = 0;
IND_TYPE w374 = 0;
IND_TYPE c637 = 0;
IND_TYPE f709 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5276 ,mem_vec_5277 ,mem_vec_5278 ,mem_vec_5279 ,mem_vec_5280 ,mem_vec_5281 ,mem_vec_5282 ,mem_vec_5283 ,mem_vec_5284 ,mem_vec_5285 ,mem_vec_5286 ,mem_vec_5287 ,mem_vec_5288 ,mem_vec_5289 ,mem_vec_5290 ,mem_vec_5291 ,mem_vec_5292 ,mem_vec_5293 ,mem_vec_5294 ,mem_vec_5295 ,mem_vec_5296 ,mem_vec_5297 ,mem_vec_5298 ,mem_vec_5299 ,mem_vec_5300 ,mem_vec_5301 ,mem_vec_5302 ,mem_vec_5303 ,mem_vec_5304 ,mem_vec_5305 ,mem_vec_5306 ,mem_vec_5307 ,mem_vec_5308 ,mem_vec_5309 ,mem_vec_5310 ,mem_vec_5311 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f708 = f709, f708_p_0 = 0;
	f708 < f709 + 256;
	f708 += 256, f708_p_0 += 256){
		for (y = y424, yp_0 = 0;
			y < y424 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 7) (28 / 4)
			for (x636 = x637, x636_p_0 = 0;
				x636 < x637 + 28;
				x636 += 4, x636_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c636 = c637, c636_p_0 = 0;
					c636 < c637 + 128;
					c636 += 128, c636_p_0 += 128){
					// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f708, fp_1 = f708_p_0, fp_0 = 0;
						f < f708 + 256;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h350, hp_0 = 0;
							h < h350 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w374, wp_0 = 0;
								w < w374 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
								// T (x, 4) (4 / 1)
								for (x = x636, xp_1 = x636_p_0, xp_0 = 0;
									x < x636 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5276 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5277 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
												c < c636 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5276);
												mem_vec_5276 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5277);
												mem_vec_5277 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5278);
												mem_vec_5278 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5279);
												mem_vec_5279 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5280);
												mem_vec_5280 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5281);
												mem_vec_5281 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5282);
												mem_vec_5282 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5283);
												mem_vec_5283 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5284);
												mem_vec_5284 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5285);
												mem_vec_5285 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5286);
												mem_vec_5286 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5287);
												mem_vec_5287 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5288);
												mem_vec_5288 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5289);
												mem_vec_5289 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5290);
												mem_vec_5290 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5291);
												mem_vec_5291 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5276);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5277);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5278);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5279);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5280);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5281);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5282);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5283);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5284);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5285);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5286);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5287);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5288);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5289);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5290);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5291);
								}
							}
						}
					}
				}
			}
		}
		for (y = y424 + 8, yp_0 = 0;
			y < y424 + 8 + 20;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 7) (28 / 4)
			for (x636 = x637, x636_p_0 = 0;
				x636 < x637 + 28;
				x636 += 4, x636_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c636 = c637, c636_p_0 = 0;
					c636 < c637 + 128;
					c636 += 128, c636_p_0 += 128){
					// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f708, fp_1 = f708_p_0, fp_0 = 0;
						f < f708 + 256;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h350, hp_0 = 0;
							h < h350 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w374, wp_0 = 0;
								w < w374 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
								// T (x, 4) (4 / 1)
								for (x = x636, xp_1 = x636_p_0, xp_0 = 0;
									x < x636 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5292 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5293 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
												c < c636 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5292);
												mem_vec_5292 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5293);
												mem_vec_5293 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5294);
												mem_vec_5294 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5295);
												mem_vec_5295 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5296);
												mem_vec_5296 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5297);
												mem_vec_5297 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5298);
												mem_vec_5298 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5299);
												mem_vec_5299 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5300);
												mem_vec_5300 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5301);
												mem_vec_5301 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5302);
												mem_vec_5302 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5303);
												mem_vec_5303 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5304);
												mem_vec_5304 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5305);
												mem_vec_5305 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5306);
												mem_vec_5306 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5307);
												mem_vec_5307 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5308);
												mem_vec_5308 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5309);
												mem_vec_5309 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5310);
												mem_vec_5310 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5311);
												mem_vec_5311 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5292);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5293);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5294);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5295);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5296);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5297);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5298);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5299);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5300);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5301);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5302);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5303);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5307);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5309);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5311);
								}
							}
						}
					}
				}
			}
		}
}


}