#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (4, f);
  T (128, c); T (4, f)]
*/
IND_TYPE c, cp_0, c450_p_0, cp_1, c450, f, fp_0, f600_p_0, f601_p_0, fp_1, f600_p_1, fp_2, f600, f601, h, hp_0, w, wp_0, x, xp_0, x450_p_0, xp_1, x450, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y300 = 0;
IND_TYPE x451 = 0;
IND_TYPE h300 = 0;
IND_TYPE w300 = 0;
IND_TYPE c451 = 0;
IND_TYPE f602 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6516 ,mem_vec_6517 ,mem_vec_6518 ,mem_vec_6519 ,mem_vec_6520 ,mem_vec_6521 ,mem_vec_6522 ,mem_vec_6523 ,mem_vec_6524 ,mem_vec_6525 ,mem_vec_6526 ,mem_vec_6527 ,mem_vec_6528 ,mem_vec_6529 ,mem_vec_6530 ,mem_vec_6531 ,mem_vec_6532 ,mem_vec_6533 ,mem_vec_6534 ,mem_vec_6535 ,mem_vec_6536 ,mem_vec_6537 ,mem_vec_6538 ,mem_vec_6539 ,mem_vec_6540 ,mem_vec_6541 ,mem_vec_6542 ,mem_vec_6543 ,mem_vec_6544 ,mem_vec_6545 ,mem_vec_6546 ,mem_vec_6547 ,mem_vec_6548 ,mem_vec_6549 ,mem_vec_6550 ,mem_vec_6551 ,mem_vec_6552 ,mem_vec_6553 ,mem_vec_6554 ,mem_vec_6555 ,mem_vec_6556 ,mem_vec_6557 ,mem_vec_6558 ,mem_vec_6559 ,mem_vec_6560 ,mem_vec_6561 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f601 = f602, f601_p_0 = 0;
	f601 < f602 + 512;
	f601 += 128, f601_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c450 = c451, c450_p_0 = 0;
		c450 < c451 + 256;
		c450 += 2, c450_p_0 += 2){
		// y = 34, x = 34, h = 3, w = 3, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f600 = f601, f600_p_1 = f601_p_0, f600_p_0 = 0;
			f600 < f601 + 128;
			f600 += 32, f600_p_1 += 32, f600_p_0 += 32){
				for (y = y300, yp_0 = 0;
					y < y300 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (34 / 2)
					for (x450 = x451, x450_p_0 = 0;
						x450 < x451 + 34;
						x450 += 2, x450_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f600, fp_2 = f600_p_1, fp_1 = f600_p_0, fp_0 = 0;
							f < f600 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h300, hp_0 = 0;
								h < h300 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w300, wp_0 = 0;
									w < w300 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
									// T (x, 2) (2 / 1)
									for (x = x450, xp_1 = x450_p_0, xp_0 = 0;
										x < x450 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6516 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6517 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c450, cp_1 = c450_p_0, cp_0 = 0;
													c < c450 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6516);
													mem_vec_6516 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6517);
													mem_vec_6517 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6518);
													mem_vec_6518 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6519);
													mem_vec_6519 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6520);
													mem_vec_6520 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6521);
													mem_vec_6521 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6522);
													mem_vec_6522 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6523);
													mem_vec_6523 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6524);
													mem_vec_6524 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6525);
													mem_vec_6525 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6526);
													mem_vec_6526 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6527);
													mem_vec_6527 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6528);
													mem_vec_6528 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6529);
													mem_vec_6529 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6530);
													mem_vec_6530 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6531);
													mem_vec_6531 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6532);
													mem_vec_6532 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6533);
													mem_vec_6533 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6534);
													mem_vec_6534 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6535);
													mem_vec_6535 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6536);
													mem_vec_6536 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6537);
													mem_vec_6537 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6516);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6517);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6518);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6519);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6520);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6521);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6522);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6523);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6524);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6525);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6526);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6527);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6528);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6529);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6530);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6531);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6532);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6533);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6534);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6535);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6536);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6537);
									}
								}
							}
						}
					}
				}
				for (y = y300 + 22, yp_0 = 0;
					y < y300 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 32
					// T (x, 17) (34 / 2)
					for (x450 = x451, x450_p_0 = 0;
						x450 < x451 + 34;
						x450 += 2, x450_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
						// T (f, 1) (32 / 32)
						for (f = f600, fp_2 = f600_p_1, fp_1 = f600_p_0, fp_0 = 0;
							f < f600 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
							// T (h, 3) (3 / 1)
							for (h = h300, hp_0 = 0;
								h < h300 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w300, wp_0 = 0;
									w < w300 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
									// T (x, 2) (2 / 1)
									for (x = x450, xp_1 = x450_p_0, xp_0 = 0;
										x < x450 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6538 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6539 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c450, cp_1 = c450_p_0, cp_0 = 0;
													c < c450 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6538);
													mem_vec_6538 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6539);
													mem_vec_6539 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6540);
													mem_vec_6540 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6541);
													mem_vec_6541 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6542);
													mem_vec_6542 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6543);
													mem_vec_6543 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6544);
													mem_vec_6544 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6545);
													mem_vec_6545 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6546);
													mem_vec_6546 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6547);
													mem_vec_6547 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6548);
													mem_vec_6548 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6549);
													mem_vec_6549 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6550);
													mem_vec_6550 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6551);
													mem_vec_6551 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6552);
													mem_vec_6552 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6553);
													mem_vec_6553 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6554);
													mem_vec_6554 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6555);
													mem_vec_6555 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6556);
													mem_vec_6556 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6557);
													mem_vec_6557 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6558);
													mem_vec_6558 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6559);
													mem_vec_6559 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6560);
													mem_vec_6560 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6561);
													mem_vec_6561 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6538);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6539);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6540);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6541);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6542);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6543);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6544);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6545);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6546);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6547);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6548);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6549);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6550);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6551);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6552);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6553);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6554);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6555);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6556);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6557);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6558);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6559);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6560);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6561);
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