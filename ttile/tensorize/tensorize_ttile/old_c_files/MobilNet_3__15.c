#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (4, f);
  T (64, c); T (2, x)]
*/
IND_TYPE c, cp_0, c480_p_0, cp_1, c480, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x608_p_0, x609_p_0, xp_1, x608_p_1, xp_2, x608, x609, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y320 = 0;
IND_TYPE x610 = 0;
IND_TYPE h272 = 0;
IND_TYPE w290 = 0;
IND_TYPE c481 = 0;
IND_TYPE f384 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4500 ,mem_vec_4501 ,mem_vec_4502 ,mem_vec_4503 ,mem_vec_4504 ,mem_vec_4505 ,mem_vec_4506 ,mem_vec_4507 ,mem_vec_4508 ,mem_vec_4509 ,mem_vec_4510 ,mem_vec_4511 ,mem_vec_4512 ,mem_vec_4513 ,mem_vec_4514 ,mem_vec_4515 ,mem_vec_4516 ,mem_vec_4517 ,mem_vec_4518 ,mem_vec_4519 ,mem_vec_4520 ,mem_vec_4521 ,mem_vec_4522 ,mem_vec_4523 ,mem_vec_4524 ,mem_vec_4525 ,mem_vec_4526 ,mem_vec_4527 ,mem_vec_4528 ,mem_vec_4529 ,mem_vec_4530 ,mem_vec_4531 ,mem_vec_4532 ,mem_vec_4533 ,mem_vec_4534 ,mem_vec_4535 ,mem_vec_4536 ,mem_vec_4537 ,mem_vec_4538 ,mem_vec_4539 ,mem_vec_4540 ,mem_vec_4541 ,mem_vec_4542 ,mem_vec_4543 ,mem_vec_4544 ,mem_vec_4545 ,mem_vec_4546 ,mem_vec_4547 ,mem_vec_4548 ,mem_vec_4549 ,mem_vec_4550 ,mem_vec_4551 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (56 / 28)
for (x609 = x610, x609_p_0 = 0;
	x609 < x610 + 56;
	x609 += 28, x609_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (c, 64) (128 / 2)
	for (c480 = c481, c480_p_0 = 0;
		c480 < c481 + 128;
		c480 += 2, c480_p_0 += 2){
		// y = 56, x = 28, h = 3, w = 3, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f384, fp_0 = 0;
			f < f384 + 128;
			f += 32, fp_0 += 32){
				for (y = y320, yp_0 = 0;
					y < y320 + 11;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
					// T (x, 28) (28 / 1)
					for (x608 = x609, x608_p_1 = x609_p_0, x608_p_0 = 0;
						x608 < x609 + 28;
						x608 += 1, x608_p_1 += 1, x608_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (h, 3) (3 / 1)
						for (h = h272, hp_0 = 0;
							h < h272 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w290, wp_0 = 0;
								w < w290 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x608, xp_2 = x608_p_1, xp_1 = x608_p_0, xp_0 = 0;
									x < x608 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4500 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4501 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c480, cp_1 = c480_p_0, cp_0 = 0;
												c < c480 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4500);
												mem_vec_4500 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4501);
												mem_vec_4501 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4502);
												mem_vec_4502 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4503);
												mem_vec_4503 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4504);
												mem_vec_4504 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4505);
												mem_vec_4505 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4506);
												mem_vec_4506 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4507);
												mem_vec_4507 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4508);
												mem_vec_4508 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4509);
												mem_vec_4509 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4510);
												mem_vec_4510 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4511);
												mem_vec_4511 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4512);
												mem_vec_4512 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4513);
												mem_vec_4513 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4514);
												mem_vec_4514 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4515);
												mem_vec_4515 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4516);
												mem_vec_4516 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4517);
												mem_vec_4517 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4518);
												mem_vec_4518 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4519);
												mem_vec_4519 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4520);
												mem_vec_4520 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4521);
												mem_vec_4521 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4500);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4501);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4502);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4503);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4511);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4513);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4514);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4515);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4516);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4517);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4518);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4519);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4520);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4521);
								}
							}
						}
					}
				}
				for (y = y320 + 11, yp_0 = 0;
					y < y320 + 11 + 45;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 28, h = 3, w = 3, c = 2, f = 32
					// T (x, 28) (28 / 1)
					for (x608 = x609, x608_p_1 = x609_p_0, x608_p_0 = 0;
						x608 < x609 + 28;
						x608 += 1, x608_p_1 += 1, x608_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
						// T (h, 3) (3 / 1)
						for (h = h272, hp_0 = 0;
							h < h272 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w290, wp_0 = 0;
								w < w290 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x608, xp_2 = x608_p_1, xp_1 = x608_p_0, xp_0 = 0;
									x < x608 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4522 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4523 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_4544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_4546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_4547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_4548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_4549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_4550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_4551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c480, cp_1 = c480_p_0, cp_0 = 0;
												c < c480 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4522);
												mem_vec_4522 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4523);
												mem_vec_4523 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4524);
												mem_vec_4524 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4525);
												mem_vec_4525 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4526);
												mem_vec_4526 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4527);
												mem_vec_4527 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4528);
												mem_vec_4528 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4529);
												mem_vec_4529 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4530);
												mem_vec_4530 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4531);
												mem_vec_4531 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4532);
												mem_vec_4532 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4533);
												mem_vec_4533 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4534);
												mem_vec_4534 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4535);
												mem_vec_4535 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4536);
												mem_vec_4536 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4537);
												mem_vec_4537 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4538);
												mem_vec_4538 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4539);
												mem_vec_4539 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4540);
												mem_vec_4540 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4541);
												mem_vec_4541 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4542);
												mem_vec_4542 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4543);
												mem_vec_4543 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4544);
												mem_vec_4544 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4545);
												mem_vec_4545 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4546);
												mem_vec_4546 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4547);
												mem_vec_4547 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4548);
												mem_vec_4548 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4549);
												mem_vec_4549 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_4550);
												mem_vec_4550 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_4551);
												mem_vec_4551 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4522);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4523);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4524);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4525);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4526);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4527);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4528);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4529);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4530);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4531);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4532);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4533);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4534);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4535);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4536);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4537);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4538);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4539);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4540);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4541);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4542);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4543);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4544);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4545);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4546);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4547);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_4548);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_4549);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_4550);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_4551);
								}
							}
						}
					}
				}
		}
	}
}


}