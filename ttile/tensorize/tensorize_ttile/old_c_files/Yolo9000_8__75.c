#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (2, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (2, x);
  T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, f52_p_0, f53_p_0, fp_1, f52_p_1, fp_2, f52, f53, h, hp_0, w, wp_0, x, xp_0, x39_p_0, xp_1, x39, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y26 = 0;
IND_TYPE x40 = 0;
IND_TYPE h26 = 0;
IND_TYPE w26 = 0;
IND_TYPE c40 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f53 = f54, f53_p_0 = 0;
	f53 < f54 + 256;
	f53 += 64, f53_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 1) (64 / 64)
	for (f52 = f53, f52_p_1 = f53_p_0, f52_p_0 = 0;
		f52 < f53 + 64;
		f52 += 64, f52_p_1 += 64, f52_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (68 / 34)
		for (x39 = x40, x39_p_0 = 0;
			x39 < x40 + 68;
			x39 += 34, x39_p_0 += 34){
				for (y = y26, yp_0 = 0;
					y < y26 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f52, fp_2 = f52_p_1, fp_1 = f52_p_0, fp_0 = 0;
						f < f52 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c39 = c40, c39_p_0 = 0;
							c39 < c40 + 128;
							c39 += 16, c39_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w26, wp_0 = 0;
								w < w26 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x39, xp_1 = x39_p_0, xp_0 = 0;
									x < x39 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h26, hp_0 = 0;
										h < h26 + 3;
										h += 1, hp_0 += 1){
												mem_vec_506 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_507 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
													c < c39 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_506);
													mem_vec_506 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_507);
													mem_vec_507 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_508);
													mem_vec_508 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_509);
													mem_vec_509 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_510);
													mem_vec_510 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_511);
													mem_vec_511 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_512);
													mem_vec_512 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_513);
													mem_vec_513 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_514);
													mem_vec_514 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_515);
													mem_vec_515 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_516);
													mem_vec_516 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_517);
													mem_vec_517 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_518);
													mem_vec_518 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_519);
													mem_vec_519 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_520);
													mem_vec_520 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_521);
													mem_vec_521 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_506);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_507);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_508);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_509);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_510);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_511);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_512);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_513);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_514);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_515);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_516);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_517);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_518);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_519);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_520);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_521);
									}
								}
							}
						}
					}
				}
				for (y = y26 + 24, yp_0 = 0;
					y < y26 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f52, fp_2 = f52_p_1, fp_1 = f52_p_0, fp_0 = 0;
						f < f52 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c39 = c40, c39_p_0 = 0;
							c39 < c40 + 128;
							c39 += 16, c39_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w26, wp_0 = 0;
								w < w26 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x39, xp_1 = x39_p_0, xp_0 = 0;
									x < x39 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h26, hp_0 = 0;
										h < h26 + 3;
										h += 1, hp_0 += 1){
												mem_vec_522 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_523 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c39, cp_1 = c39_p_0, cp_0 = 0;
													c < c39 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_522);
													mem_vec_522 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_523);
													mem_vec_523 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_524);
													mem_vec_524 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_525);
													mem_vec_525 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_526);
													mem_vec_526 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_527);
													mem_vec_527 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_528);
													mem_vec_528 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_529);
													mem_vec_529 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_530);
													mem_vec_530 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_531);
													mem_vec_531 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_532);
													mem_vec_532 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_533);
													mem_vec_533 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_534);
													mem_vec_534 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_535);
													mem_vec_535 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_536);
													mem_vec_536 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_537);
													mem_vec_537 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_538);
													mem_vec_538 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_539);
													mem_vec_539 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_540);
													mem_vec_540 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_541);
													mem_vec_541 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_542);
													mem_vec_542 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_543);
													mem_vec_543 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_522);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_523);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_524);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_525);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_526);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_527);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_528);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_529);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_530);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_531);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_532);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_533);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_534);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_535);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_536);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_537);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_538);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_539);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_540);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_541);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_542);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_543);
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