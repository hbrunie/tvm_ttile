#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1024, c); T (1, f); T (1, y); T (1, c); T (16, f); T (1, c)]
*/
IND_TYPE c, cp_0, c120_p_0, c121_p_0, c122_p_0, cp_1, c120_p_1, c121_p_1, cp_2, c120_p_2, cp_3, c120, c121, c122, f, fp_0, f72_p_0, fp_1, f72, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y26 = 0;
IND_TYPE x48 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c123 = 0;
IND_TYPE f73 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c122 = c123, c122_p_0 = 0;
	c122 < c123 + 1024;
	c122 += 1024, c122_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (f, 16) (1024 / 64)
	for (f72 = f73, f72_p_0 = 0;
		f72 < f73 + 1024;
		f72 += 64, f72_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
		// T (c, 1) (1024 / 1024)
		for (c121 = c122, c121_p_1 = c122_p_0, c121_p_0 = 0;
			c121 < c122 + 1024;
			c121 += 1024, c121_p_1 += 1024, c121_p_0 += 1024){
			// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
			// T (y, 1) (7 / 7)
			for (y = y26, yp_0 = 0;
				y < y26 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
				// T (f, 1) (64 / 64)
				for (f = f72, fp_1 = f72_p_0, fp_0 = 0;
					f < f72 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
					// T (c, 1024) (1024 / 1)
					for (c120 = c121, c120_p_2 = c121_p_1, c120_p_1 = c121_p_0, c120_p_0 = 0;
						c120 < c121 + 1024;
						c120 += 1, c120_p_2 += 1, c120_p_1 += 1, c120_p_0 += 1){
						// y = 7, x = 7, h = 3, w = 3, c = 1, f = 64
						// T (h, 3) (3 / 1)
						for (h = h48, hp_0 = 0;
							h < h48 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 7, h = 1, w = 3, c = 1, f = 64
							// T (w, 3) (3 / 1)
							for (w = w48, wp_0 = 0;
								w < w48 + 3;
								w += 1, wp_0 += 1){
								// y = 7, x = 7, h = 1, w = 1, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x48, xp_0 = 0;
									x < x48 + 7;
									x += 1, xp_0 += 1){
											mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c120, cp_3 = c120_p_2, cp_2 = c120_p_1, cp_1 = c120_p_0, cp_0 = 0;
												c < c120 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_364);
												mem_vec_364 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_365);
												mem_vec_365 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_366);
												mem_vec_366 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_367);
												mem_vec_367 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_368);
												mem_vec_368 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_369);
												mem_vec_369 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_370);
												mem_vec_370 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_371);
												mem_vec_371 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_372);
												mem_vec_372 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_373);
												mem_vec_373 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_374);
												mem_vec_374 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_375);
												mem_vec_375 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_376);
												mem_vec_376 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_377);
												mem_vec_377 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_378);
												mem_vec_378 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_379);
												mem_vec_379 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_380);
												mem_vec_380 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_381);
												mem_vec_381 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_382);
												mem_vec_382 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_383);
												mem_vec_383 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_384);
												mem_vec_384 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_385);
												mem_vec_385 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_386);
												mem_vec_386 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_387);
												mem_vec_387 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_388);
												mem_vec_388 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_389);
												mem_vec_389 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_390);
												mem_vec_390 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_391);
												mem_vec_391 = vec_38;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_364);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_365);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_366);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_367);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_373);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_374);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_375);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_376);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_377);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_379);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_391);
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