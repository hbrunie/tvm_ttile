#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (4, c); T (8, y); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x51_p_0, xp_1, x51, y, yp_0, y51_p_0, yp_1, y51;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y52 = 0;
IND_TYPE x52 = 0;
IND_TYPE h19 = 0;
IND_TYPE w28 = 0;
IND_TYPE c43 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,mem_vec_432 ,mem_vec_433 ,mem_vec_434 ,mem_vec_435 ,mem_vec_436 ,mem_vec_437 ,mem_vec_438 ,mem_vec_439 ,mem_vec_440 ,mem_vec_441 ,mem_vec_442 ,mem_vec_443 ,mem_vec_444 ,mem_vec_445 ,mem_vec_446 ,mem_vec_447 ,mem_vec_448 ,mem_vec_449 ,mem_vec_450 ,mem_vec_451 ,mem_vec_452 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y51 = y52, y51_p_0 = 0;
		y51 < y52 + 192;
		y51 += 64, y51_p_0 += 64){
		// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x51 = x52, x51_p_0 = 0;
			x51 < x52 + 272;
			x51 += 1, x51_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
				y < y51 + 64;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c42 = c43, c42_p_0 = 0;
					c42 < c43 + 32;
					c42 += 8, c42_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f28, fp_0 = 0;
						f < f28 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
							x < x51 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h19, hp_0 = 0;
								h < h19 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
											mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
												c < c42 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_417);
												mem_vec_417 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_418);
												mem_vec_418 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_419);
												mem_vec_419 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_420);
												mem_vec_420 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_421);
												mem_vec_421 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_422);
												mem_vec_422 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_423);
												mem_vec_423 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_424);
												mem_vec_424 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_425);
												mem_vec_425 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_426);
												mem_vec_426 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_427);
												mem_vec_427 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_428);
												mem_vec_428 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_429);
												mem_vec_429 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_430);
												mem_vec_430 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_431);
												mem_vec_431 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_432);
												mem_vec_432 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_417);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_418);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_419);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_420);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_421);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_422);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_423);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_424);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_425);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_426);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_427);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_428);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_429);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_431);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_432);
								}
							}
						}
					}
				}
			}
		}
	}
	for (y51 = y52 + 192, y51_p_0 = 0;
		y51 < y52 + 192 + 80;
		y51 += 80, y51_p_0 += 80){
		// y = 8 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x51 = x52, x51_p_0 = 0;
			x51 < x52 + 272;
			x51 += 1, x51_p_0 += 1){
			// y = 8 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
				y < y51 + 80;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c42 = c43, c42_p_0 = 0;
					c42 < c43 + 32;
					c42 += 8, c42_p_0 += 8){
					// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f28, fp_0 = 0;
						f < f28 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (x, 1) (1 / 1)
						for (x = x51, xp_1 = x51_p_0, xp_0 = 0;
							x < x51 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h19, hp_0 = 0;
								h < h19 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w28, wp_0 = 0;
									w < w28 + 3;
									w += 1, wp_0 += 1){
											mem_vec_433 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_434 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c42, cp_1 = c42_p_0, cp_0 = 0;
												c < c42 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_433);
												mem_vec_433 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_434);
												mem_vec_434 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_435);
												mem_vec_435 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_436);
												mem_vec_436 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_437);
												mem_vec_437 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_438);
												mem_vec_438 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_439);
												mem_vec_439 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_440);
												mem_vec_440 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_441);
												mem_vec_441 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_442);
												mem_vec_442 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_443);
												mem_vec_443 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_444);
												mem_vec_444 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_445);
												mem_vec_445 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_446);
												mem_vec_446 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_447);
												mem_vec_447 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_448);
												mem_vec_448 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_449);
												mem_vec_449 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_450);
												mem_vec_450 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_451);
												mem_vec_451 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_452);
												mem_vec_452 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_433);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_434);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_435);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_437);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_452);
								}
							}
						}
					}
				}
			}
		}
	}


}