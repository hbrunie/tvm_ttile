#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (4, f);
  T (16, c); T (4, x)]
*/
IND_TYPE c, cp_0, c414_p_0, cp_1, c414, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x520_p_0, x521_p_0, xp_1, x520_p_1, xp_2, x520, x521, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y276 = 0;
IND_TYPE x522 = 0;
IND_TYPE h228 = 0;
IND_TYPE w246 = 0;
IND_TYPE c415 = 0;
IND_TYPE f340 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,mem_vec_3464 ,mem_vec_3465 ,mem_vec_3466 ,mem_vec_3467 ,mem_vec_3468 ,mem_vec_3469 ,mem_vec_3470 ,mem_vec_3471 ,mem_vec_3472 ,mem_vec_3473 ,mem_vec_3474 ,mem_vec_3475 ,mem_vec_3476 ,mem_vec_3477 ,mem_vec_3478 ,mem_vec_3479 ,mem_vec_3480 ,mem_vec_3481 ,mem_vec_3482 ,mem_vec_3483 ,mem_vec_3484 ,mem_vec_3485 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
for (x521 = x522, x521_p_0 = 0;
	x521 < x522 + 56;
	x521 += 14, x521_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 16) (128 / 8)
	for (c414 = c415, c414_p_0 = 0;
		c414 < c415 + 128;
		c414 += 8, c414_p_0 += 8){
		// y = 56, x = 14, h = 3, w = 3, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f340, fp_0 = 0;
			f < f340 + 128;
			f += 32, fp_0 += 32){
				for (y = y276, yp_0 = 0;
					y < y276 + 30;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (x, 2) (14 / 7)
					for (x520 = x521, x520_p_1 = x521_p_0, x520_p_0 = 0;
						x520 < x521 + 14;
						x520 += 7, x520_p_1 += 7, x520_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h228, hp_0 = 0;
							h < h228 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w246, wp_0 = 0;
								w < w246 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 8, f = 32
								// T (x, 7) (7 / 1)
								for (x = x520, xp_2 = x520_p_1, xp_1 = x520_p_0, xp_0 = 0;
									x < x520 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3440 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3441 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
												c < c414 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3440);
												mem_vec_3440 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3441);
												mem_vec_3441 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3442);
												mem_vec_3442 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3443);
												mem_vec_3443 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3444);
												mem_vec_3444 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3445);
												mem_vec_3445 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3446);
												mem_vec_3446 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3447);
												mem_vec_3447 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3448);
												mem_vec_3448 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3449);
												mem_vec_3449 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3450);
												mem_vec_3450 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3451);
												mem_vec_3451 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3452);
												mem_vec_3452 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3453);
												mem_vec_3453 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3454);
												mem_vec_3454 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3455);
												mem_vec_3455 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3456);
												mem_vec_3456 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3457);
												mem_vec_3457 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3458);
												mem_vec_3458 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3459);
												mem_vec_3459 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3453);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3457);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3459);
								}
							}
						}
					}
				}
				for (y = y276 + 30, yp_0 = 0;
					y < y276 + 30 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
					// T (x, 2) (14 / 7)
					for (x520 = x521, x520_p_1 = x521_p_0, x520_p_0 = 0;
						x520 < x521 + 14;
						x520 += 7, x520_p_1 += 7, x520_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h228, hp_0 = 0;
							h < h228 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w246, wp_0 = 0;
								w < w246 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 8, f = 32
								// T (x, 7) (7 / 1)
								for (x = x520, xp_2 = x520_p_1, xp_1 = x520_p_0, xp_0 = 0;
									x < x520 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3460 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3461 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_3484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_3485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
												c < c414 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3460);
												mem_vec_3460 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3461);
												mem_vec_3461 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3462);
												mem_vec_3462 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3463);
												mem_vec_3463 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3464);
												mem_vec_3464 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3465);
												mem_vec_3465 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3466);
												mem_vec_3466 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3467);
												mem_vec_3467 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3468);
												mem_vec_3468 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3469);
												mem_vec_3469 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3470);
												mem_vec_3470 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3471);
												mem_vec_3471 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3472);
												mem_vec_3472 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3473);
												mem_vec_3473 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3474);
												mem_vec_3474 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3475);
												mem_vec_3475 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3476);
												mem_vec_3476 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3477);
												mem_vec_3477 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3478);
												mem_vec_3478 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3479);
												mem_vec_3479 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3480);
												mem_vec_3480 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3481);
												mem_vec_3481 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3482);
												mem_vec_3482 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3483);
												mem_vec_3483 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3484);
												mem_vec_3484 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3485);
												mem_vec_3485 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3463);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3485);
								}
							}
						}
					}
				}
		}
	}
}


}