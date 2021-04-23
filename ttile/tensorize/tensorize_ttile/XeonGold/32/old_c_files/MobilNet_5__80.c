#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (4, c); T (2, x); T (2, y); T (8, f); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c294_p_0, cp_1, c294, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x296_p_0, x297_p_0, xp_1, x296_p_1, xp_2, x296, x297, y, yp_0, y210_p_0, yp_1, y210;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y211 = 0;
IND_TYPE x298 = 0;
IND_TYPE h184 = 0;
IND_TYPE w124 = 0;
IND_TYPE c295 = 0;
IND_TYPE f364 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2300 ,mem_vec_2301 ,mem_vec_2302 ,mem_vec_2303 ,mem_vec_2304 ,mem_vec_2305 ,mem_vec_2306 ,mem_vec_2307 ,mem_vec_2308 ,mem_vec_2309 ,mem_vec_2310 ,mem_vec_2311 ,mem_vec_2312 ,mem_vec_2313 ,mem_vec_2314 ,mem_vec_2315 ,mem_vec_2316 ,mem_vec_2317 ,mem_vec_2318 ,mem_vec_2319 ,mem_vec_2320 ,mem_vec_2321 ,mem_vec_2322 ,mem_vec_2323 ,mem_vec_2324 ,mem_vec_2325 ,mem_vec_2326 ,mem_vec_2327 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y210 = y211, y210_p_0 = 0;
	y210 < y211 + 28;
	y210 += 28, y210_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 2) (28 / 14)
	for (x297 = x298, x297_p_0 = 0;
		x297 < x298 + 28;
		x297 += 14, x297_p_0 += 14){
		// y = 28, x = 14, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f364, fp_0 = 0;
			f < f364 + 256;
			f += 32, fp_0 += 32){
			// y = 28, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (y, 2) (28 / 14)
			for (y = y210, yp_1 = y210_p_0, yp_0 = 0;
				y < y210 + 28;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
				// T (x, 2) (14 / 7)
				for (x296 = x297, x296_p_1 = x297_p_0, x296_p_0 = 0;
					x296 < x297 + 14;
					x296 += 7, x296_p_1 += 7, x296_p_0 += 7){
					// y = 14, x = 7, h = 3, w = 3, c = 256, f = 32
					// T (c, 4) (256 / 64)
					for (c294 = c295, c294_p_0 = 0;
						c294 < c295 + 256;
						c294 += 64, c294_p_0 += 64){
						// y = 14, x = 7, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w124, wp_0 = 0;
							w < w124 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 7, h = 3, w = 1, c = 64, f = 32
							// T (x, 7) (7 / 1)
							for (x = x296, xp_2 = x296_p_1, xp_1 = x296_p_0, xp_0 = 0;
								x < x296 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = 14, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h184, hp_0 = 0;
									h < h184 + 3;
									h += 1, hp_0 += 1){
											mem_vec_2300 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2301 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_2322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_2324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_2325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_2326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_2327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c294, cp_1 = c294_p_0, cp_0 = 0;
												c < c294 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2300);
												mem_vec_2300 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2301);
												mem_vec_2301 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2302);
												mem_vec_2302 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2303);
												mem_vec_2303 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2304);
												mem_vec_2304 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2305);
												mem_vec_2305 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2306);
												mem_vec_2306 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2307);
												mem_vec_2307 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2308);
												mem_vec_2308 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2309);
												mem_vec_2309 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2310);
												mem_vec_2310 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2311);
												mem_vec_2311 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2312);
												mem_vec_2312 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2313);
												mem_vec_2313 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2314);
												mem_vec_2314 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2315);
												mem_vec_2315 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2316);
												mem_vec_2316 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2317);
												mem_vec_2317 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2318);
												mem_vec_2318 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2319);
												mem_vec_2319 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2320);
												mem_vec_2320 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2321);
												mem_vec_2321 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2322);
												mem_vec_2322 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2323);
												mem_vec_2323 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2324);
												mem_vec_2324 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2325);
												mem_vec_2325 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2326);
												mem_vec_2326 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2327);
												mem_vec_2327 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2300);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2301);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2302);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2303);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2307);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2309);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2315);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2316);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2317);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2318);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2319);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2320);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2321);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2322);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2323);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2324);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2325);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_2326);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_2327);
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