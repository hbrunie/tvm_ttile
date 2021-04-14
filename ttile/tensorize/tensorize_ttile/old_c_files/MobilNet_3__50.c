#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (2, f);
  T (2, c); T (28, x)]
*/
IND_TYPE c, cp_0, c534_p_0, cp_1, c534, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x680_p_0, x681_p_0, xp_1, x680_p_1, xp_2, x680, x681, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y356 = 0;
IND_TYPE x682 = 0;
IND_TYPE h308 = 0;
IND_TYPE w326 = 0;
IND_TYPE c535 = 0;
IND_TYPE f420 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_5436 ,mem_vec_5437 ,mem_vec_5438 ,mem_vec_5439 ,mem_vec_5440 ,mem_vec_5441 ,mem_vec_5442 ,mem_vec_5443 ,mem_vec_5444 ,mem_vec_5445 ,mem_vec_5446 ,mem_vec_5447 ,mem_vec_5448 ,mem_vec_5449 ,mem_vec_5450 ,mem_vec_5451 ,mem_vec_5452 ,mem_vec_5453 ,mem_vec_5454 ,mem_vec_5455 ,mem_vec_5456 ,mem_vec_5457 ,mem_vec_5458 ,mem_vec_5459 ,mem_vec_5460 ,mem_vec_5461 ,mem_vec_5462 ,mem_vec_5463 ,mem_vec_5464 ,mem_vec_5465 ,mem_vec_5466 ,mem_vec_5467 ,mem_vec_5468 ,mem_vec_5469 ,mem_vec_5470 ,mem_vec_5471 ,mem_vec_5472 ,mem_vec_5473 ,mem_vec_5474 ,mem_vec_5475 ,mem_vec_5476 ,mem_vec_5477 ,mem_vec_5478 ,mem_vec_5479 ,mem_vec_5480 ,mem_vec_5481 ,mem_vec_5482 ,mem_vec_5483 ,mem_vec_5484 ,mem_vec_5485 ,mem_vec_5486 ,mem_vec_5487 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 28) (56 / 2)
for (x681 = x682, x681_p_0 = 0;
	x681 < x682 + 56;
	x681 += 2, x681_p_0 += 2){
	// y = 56, x = 2, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c534 = c535, c534_p_0 = 0;
		c534 < c535 + 128;
		c534 += 64, c534_p_0 += 64){
		// y = 56, x = 2, h = 3, w = 3, c = 64, f = 128
		// T (f, 2) (128 / 64)
		for (f = f420, fp_0 = 0;
			f < f420 + 128;
			f += 64, fp_0 += 64){
				for (y = y356, yp_0 = 0;
					y < y356 + 42;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
					// T (x, 1) (2 / 2)
					for (x680 = x681, x680_p_1 = x681_p_0, x680_p_0 = 0;
						x680 < x681 + 2;
						x680 += 2, x680_p_1 += 2, x680_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h308, hp_0 = 0;
							h < h308 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 64
							// T (w, 3) (3 / 1)
							for (w = w326, wp_0 = 0;
								w < w326 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 64
								// T (x, 2) (2 / 1)
								for (x = x680, xp_2 = x680_p_1, xp_1 = x680_p_0, xp_0 = 0;
									x < x680 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5436 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5437 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5438 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5439 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_5451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_5452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_5455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_5456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_5459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c534, cp_1 = c534_p_0, cp_0 = 0;
												c < c534 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5436);
												mem_vec_5436 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5437);
												mem_vec_5437 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5438);
												mem_vec_5438 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5439);
												mem_vec_5439 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5440);
												mem_vec_5440 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5441);
												mem_vec_5441 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5442);
												mem_vec_5442 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5443);
												mem_vec_5443 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5444);
												mem_vec_5444 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5445);
												mem_vec_5445 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5446);
												mem_vec_5446 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5447);
												mem_vec_5447 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5448);
												mem_vec_5448 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5449);
												mem_vec_5449 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5450);
												mem_vec_5450 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5451);
												mem_vec_5451 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5452);
												mem_vec_5452 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5453);
												mem_vec_5453 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5454);
												mem_vec_5454 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5455);
												mem_vec_5455 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5456);
												mem_vec_5456 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5457);
												mem_vec_5457 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5458);
												mem_vec_5458 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5459);
												mem_vec_5459 = vec_33;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5437);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5453);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5457);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5459);
								}
							}
						}
					}
				}
				for (y = y356 + 42, yp_0 = 0;
					y < y356 + 42 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
					// T (x, 1) (2 / 2)
					for (x680 = x681, x680_p_1 = x681_p_0, x680_p_0 = 0;
						x680 < x681 + 2;
						x680 += 2, x680_p_1 += 2, x680_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h308, hp_0 = 0;
							h < h308 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 64
							// T (w, 3) (3 / 1)
							for (w = w326, wp_0 = 0;
								w < w326 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 64
								// T (x, 2) (2 / 1)
								for (x = x680, xp_2 = x680_p_1, xp_1 = x680_p_0, xp_0 = 0;
									x < x680 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5460 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5461 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5462 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_5475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_5476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_5479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_5480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_5483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_5484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_5487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c534, cp_1 = c534_p_0, cp_0 = 0;
												c < c534 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5460);
												mem_vec_5460 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5461);
												mem_vec_5461 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5462);
												mem_vec_5462 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5463);
												mem_vec_5463 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5464);
												mem_vec_5464 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5465);
												mem_vec_5465 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5466);
												mem_vec_5466 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5467);
												mem_vec_5467 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5468);
												mem_vec_5468 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5469);
												mem_vec_5469 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5470);
												mem_vec_5470 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5471);
												mem_vec_5471 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5472);
												mem_vec_5472 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5473);
												mem_vec_5473 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5474);
												mem_vec_5474 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5475);
												mem_vec_5475 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5476);
												mem_vec_5476 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5477);
												mem_vec_5477 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5478);
												mem_vec_5478 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5479);
												mem_vec_5479 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5480);
												mem_vec_5480 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5481);
												mem_vec_5481 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5482);
												mem_vec_5482 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5483);
												mem_vec_5483 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5484);
												mem_vec_5484 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5485);
												mem_vec_5485 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5486);
												mem_vec_5486 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5487);
												mem_vec_5487 = vec_38;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5463);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5464);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5465);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5466);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5467);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5468);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5469);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5470);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5471);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5472);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5473);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5474);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5475);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5487);
								}
							}
						}
					}
				}
		}
	}
}


}