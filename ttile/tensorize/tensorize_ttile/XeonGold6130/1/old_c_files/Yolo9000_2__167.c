#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (2, c); T (8, y); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0, y48_p_0, yp_1, y48;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y49 = 0;
IND_TYPE x49 = 0;
IND_TYPE h17 = 0;
IND_TYPE w26 = 0;
IND_TYPE c40 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y48 = y49, y48_p_0 = 0;
		y48 < y49 + 192;
		y48 += 64, y48_p_0 += 64){
		// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x48 = x49, x48_p_0 = 0;
			x48 < x49 + 272;
			x48 += 1, x48_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
				y < y48 + 64;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c39 = c40, c39_p_0 = 0;
					c39 < c40 + 32;
					c39 += 16, c39_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f26, fp_0 = 0;
						f < f26 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
							x < x48 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h17, hp_0 = 0;
								h < h17 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
											mem_vec_381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
												c < c39 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_381);
												mem_vec_381 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_382);
												mem_vec_382 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_383);
												mem_vec_383 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_384);
												mem_vec_384 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_385);
												mem_vec_385 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_386);
												mem_vec_386 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_387);
												mem_vec_387 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_388);
												mem_vec_388 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_389);
												mem_vec_389 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_390);
												mem_vec_390 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_391);
												mem_vec_391 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_392);
												mem_vec_392 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_393);
												mem_vec_393 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_394);
												mem_vec_394 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_395);
												mem_vec_395 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_396);
												mem_vec_396 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_391);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_395);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_396);
								}
							}
						}
					}
				}
			}
		}
	}
	for (y48 = y49 + 192, y48_p_0 = 0;
		y48 < y49 + 192 + 80;
		y48 += 80, y48_p_0 += 80){
		// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x48 = x49, x48_p_0 = 0;
			x48 < x49 + 272;
			x48 += 1, x48_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
				y < y48 + 80;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c39 = c40, c39_p_0 = 0;
					c39 < c40 + 32;
					c39 += 16, c39_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f26, fp_0 = 0;
						f < f26 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
							x < x48 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h17, hp_0 = 0;
								h < h17 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w26, wp_0 = 0;
									w < w26 + 3;
									w += 1, wp_0 += 1){
											mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
												c < c39 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_397);
												mem_vec_397 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_398);
												mem_vec_398 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_399);
												mem_vec_399 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_400);
												mem_vec_400 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_401);
												mem_vec_401 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_402);
												mem_vec_402 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_403);
												mem_vec_403 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_404);
												mem_vec_404 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_405);
												mem_vec_405 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_406);
												mem_vec_406 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_407);
												mem_vec_407 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_408);
												mem_vec_408 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_409);
												mem_vec_409 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_410);
												mem_vec_410 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_411);
												mem_vec_411 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_412);
												mem_vec_412 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_413);
												mem_vec_413 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_414);
												mem_vec_414 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_415);
												mem_vec_415 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_416);
												mem_vec_416 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_397);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_398);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_399);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_400);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_401);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_402);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_403);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_404);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_405);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_406);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_407);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_408);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_409);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_410);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_411);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_412);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_413);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_414);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_415);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_416);
								}
							}
						}
					}
				}
			}
		}
	}


}