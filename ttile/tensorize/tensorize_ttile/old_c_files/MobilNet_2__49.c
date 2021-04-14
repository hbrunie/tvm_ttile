#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (56, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]; T (2, f);
  T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c530_p_0, cp_1, c530, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x562_p_0, x563_p_0, xp_1, x562_p_1, xp_2, x562, x563, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y312 = 0;
IND_TYPE x564 = 0;
IND_TYPE h276 = 0;
IND_TYPE w288 = 0;
IND_TYPE c531 = 0;
IND_TYPE f250 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4476 ,mem_vec_4477 ,mem_vec_4478 ,mem_vec_4479 ,mem_vec_4480 ,mem_vec_4481 ,mem_vec_4482 ,mem_vec_4483 ,mem_vec_4484 ,mem_vec_4485 ,mem_vec_4486 ,mem_vec_4487 ,mem_vec_4488 ,mem_vec_4489 ,mem_vec_4490 ,mem_vec_4491 ,mem_vec_4492 ,mem_vec_4493 ,mem_vec_4494 ,mem_vec_4495 ,mem_vec_4496 ,mem_vec_4497 ,mem_vec_4498 ,mem_vec_4499 ,mem_vec_4500 ,mem_vec_4501 ,mem_vec_4502 ,mem_vec_4503 ,mem_vec_4504 ,mem_vec_4505 ,mem_vec_4506 ,mem_vec_4507 ,mem_vec_4508 ,mem_vec_4509 ,mem_vec_4510 ,mem_vec_4511 ,mem_vec_4512 ,mem_vec_4513 ,mem_vec_4514 ,mem_vec_4515 ,mem_vec_4516 ,mem_vec_4517 ,mem_vec_4518 ,mem_vec_4519 ,mem_vec_4520 ,mem_vec_4521 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x563 = x564, x563_p_0 = 0;
	x563 < x564 + 56;
	x563 += 56, x563_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c530 = c531, c530_p_0 = 0;
		c530 < c531 + 64;
		c530 += 8, c530_p_0 += 8){
		// y = 56, x = 56, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f250, fp_0 = 0;
			f < f250 + 64;
			f += 32, fp_0 += 32){
				for (y = y312, yp_0 = 0;
					y < y312 + 30;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (56 / 56)
					for (x562 = x563, x562_p_1 = x563_p_0, x562_p_0 = 0;
						x562 < x563 + 56;
						x562 += 56, x562_p_1 += 56, x562_p_0 += 56){
						// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h276, hp_0 = 0;
							h < h276 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w288, wp_0 = 0;
								w < w288 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 56, h = 1, w = 1, c = 8, f = 32
								// T (x, 56) (56 / 1)
								for (x = x562, xp_2 = x562_p_1, xp_1 = x562_p_0, xp_0 = 0;
									x < x562 + 56;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4476 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4477 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c530, cp_1 = c530_p_0, cp_0 = 0;
												c < c530 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4476);
												mem_vec_4476 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4477);
												mem_vec_4477 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4478);
												mem_vec_4478 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4479);
												mem_vec_4479 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4480);
												mem_vec_4480 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4481);
												mem_vec_4481 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4482);
												mem_vec_4482 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4483);
												mem_vec_4483 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4484);
												mem_vec_4484 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4485);
												mem_vec_4485 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4486);
												mem_vec_4486 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4487);
												mem_vec_4487 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4488);
												mem_vec_4488 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4489);
												mem_vec_4489 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4490);
												mem_vec_4490 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4491);
												mem_vec_4491 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4492);
												mem_vec_4492 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4493);
												mem_vec_4493 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4494);
												mem_vec_4494 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4495);
												mem_vec_4495 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4493);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4495);
								}
							}
						}
					}
				}
				for (y = y312 + 30, yp_0 = 0;
					y < y312 + 30 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 32
					// T (x, 1) (56 / 56)
					for (x562 = x563, x562_p_1 = x563_p_0, x562_p_0 = 0;
						x562 < x563 + 56;
						x562 += 56, x562_p_1 += 56, x562_p_0 += 56){
						// y = ph_y, x = 56, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h276, hp_0 = 0;
							h < h276 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w288, wp_0 = 0;
								w < w288 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 56, h = 1, w = 1, c = 8, f = 32
								// T (x, 56) (56 / 1)
								for (x = x562, xp_2 = x562_p_1, xp_1 = x562_p_0, xp_0 = 0;
									x < x562 + 56;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4496 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4497 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_4518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_4520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_4521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c530, cp_1 = c530_p_0, cp_0 = 0;
												c < c530 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4496);
												mem_vec_4496 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4497);
												mem_vec_4497 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4498);
												mem_vec_4498 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4499);
												mem_vec_4499 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4500);
												mem_vec_4500 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4501);
												mem_vec_4501 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4502);
												mem_vec_4502 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4503);
												mem_vec_4503 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4504);
												mem_vec_4504 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4505);
												mem_vec_4505 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4506);
												mem_vec_4506 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4507);
												mem_vec_4507 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4508);
												mem_vec_4508 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4509);
												mem_vec_4509 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4510);
												mem_vec_4510 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4511);
												mem_vec_4511 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4512);
												mem_vec_4512 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4513);
												mem_vec_4513 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4514);
												mem_vec_4514 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4515);
												mem_vec_4515 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4516);
												mem_vec_4516 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4517);
												mem_vec_4517 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4518);
												mem_vec_4518 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4519);
												mem_vec_4519 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4520);
												mem_vec_4520 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4521);
												mem_vec_4521 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4496);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4497);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4498);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4499);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4500);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4501);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4502);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4503);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4511);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4514);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4515);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4516);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4517);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4518);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4519);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4520);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4521);
								}
							}
						}
					}
				}
		}
	}
}


}