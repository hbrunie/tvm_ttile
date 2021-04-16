#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (4, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 5), (Arg 9)); ((Iter 7), (Arg 13))]; T (1, x)]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x36_p_0, x37_p_0, xp_1, x36_p_1, xp_2, x36, x37, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y18 = 0;
IND_TYPE x38 = 0;
IND_TYPE h18 = 0;
IND_TYPE w18 = 0;
IND_TYPE c28 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x37 = x38, x37_p_0 = 0;
	x37 < x38 + 136;
	x37 += 136, x37_p_0 += 136){
		for (y = y18, yp_0 = 0;
			y < y18 + 45;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
				x36 < x37 + 136;
				x36 += 34, x36_p_1 += 34, x36_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f18, fp_0 = 0;
					f < f18 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c27 = c28, c27_p_0 = 0;
						c27 < c28 + 64;
						c27 += 16, c27_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w18, wp_0 = 0;
							w < w18 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h18, hp_0 = 0;
									h < h18 + 3;
									h += 1, hp_0 += 1){
											mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
												c < c27 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_468);
												mem_vec_468 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_469);
												mem_vec_469 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_470);
												mem_vec_470 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_471);
												mem_vec_471 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_472);
												mem_vec_472 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_473);
												mem_vec_473 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_474);
												mem_vec_474 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_475);
												mem_vec_475 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_476);
												mem_vec_476 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_477);
												mem_vec_477 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_478);
												mem_vec_478 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_479);
												mem_vec_479 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_480);
												mem_vec_480 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_481);
												mem_vec_481 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_482);
												mem_vec_482 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_483);
												mem_vec_483 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_484);
												mem_vec_484 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_485);
												mem_vec_485 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_485);
								}
							}
						}
					}
				}
			}
		}
		for (y = y18 + 45, yp_0 = 0;
			y < y18 + 45 + 91;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x36 = x37, x36_p_1 = x37_p_0, x36_p_0 = 0;
				x36 < x37 + 136;
				x36 += 34, x36_p_1 += 34, x36_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f18, fp_0 = 0;
					f < f18 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c27 = c28, c27_p_0 = 0;
						c27 < c28 + 64;
						c27 += 16, c27_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w18, wp_0 = 0;
							w < w18 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x36, xp_2 = x36_p_1, xp_1 = x36_p_0, xp_0 = 0;
								x < x36 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h18, hp_0 = 0;
									h < h18 + 3;
									h += 1, hp_0 += 1){
											mem_vec_486 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_487 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
												c < c27 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_486);
												mem_vec_486 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_487);
												mem_vec_487 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_488);
												mem_vec_488 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_489);
												mem_vec_489 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_490);
												mem_vec_490 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_491);
												mem_vec_491 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_492);
												mem_vec_492 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_493);
												mem_vec_493 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_494);
												mem_vec_494 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_495);
												mem_vec_495 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_496);
												mem_vec_496 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_497);
												mem_vec_497 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_498);
												mem_vec_498 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_499);
												mem_vec_499 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_500);
												mem_vec_500 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_501);
												mem_vec_501 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_502);
												mem_vec_502 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_503);
												mem_vec_503 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_504);
												mem_vec_504 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_505);
												mem_vec_505 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_506);
												mem_vec_506 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_507);
												mem_vec_507 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_508);
												mem_vec_508 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_509);
												mem_vec_509 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_510);
												mem_vec_510 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_511);
												mem_vec_511 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_493);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_495);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_496);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_497);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_498);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_499);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_500);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_501);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_502);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_503);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_511);
								}
							}
						}
					}
				}
			}
		}
}


}