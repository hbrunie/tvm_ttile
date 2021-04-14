#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (17, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (8, c); T (8, x); T (2, x)]
*/
IND_TYPE c, cp_0, c972_p_0, cp_1, c972, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1620_p_0, x1621_p_0, x1622_p_0, xp_1, x1620_p_1, x1621_p_1, xp_2, x1620_p_2, xp_3, x1620, x1621, x1622, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y648 = 0;
IND_TYPE x1623 = 0;
IND_TYPE h648 = 0;
IND_TYPE w508 = 0;
IND_TYPE c973 = 0;
IND_TYPE f508 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6528 ,mem_vec_6529 ,mem_vec_6530 ,mem_vec_6531 ,mem_vec_6532 ,mem_vec_6533 ,mem_vec_6534 ,mem_vec_6535 ,mem_vec_6536 ,mem_vec_6537 ,mem_vec_6538 ,mem_vec_6539 ,mem_vec_6540 ,mem_vec_6541 ,mem_vec_6542 ,mem_vec_6543 ,mem_vec_6544 ,mem_vec_6545 ,mem_vec_6546 ,mem_vec_6547 ,mem_vec_6548 ,mem_vec_6549 ,mem_vec_6550 ,mem_vec_6551 ,mem_vec_6552 ,mem_vec_6553 ,mem_vec_6554 ,mem_vec_6555 ,mem_vec_6556 ,mem_vec_6557 ,mem_vec_6558 ,mem_vec_6559 ,mem_vec_6560 ,mem_vec_6561 ,mem_vec_6562 ,mem_vec_6563 ,mem_vec_6564 ,mem_vec_6565 ,mem_vec_6566 ,mem_vec_6567 ,mem_vec_6568 ,mem_vec_6569 ,mem_vec_6570 ,mem_vec_6571 ,mem_vec_6572 ,mem_vec_6573 ,mem_vec_6574 ,mem_vec_6575 ,mem_vec_6576 ,mem_vec_6577 ,mem_vec_6578 ,mem_vec_6579 ,mem_vec_6580 ,mem_vec_6581 ,mem_vec_6582 ,mem_vec_6583 ,mem_vec_6584 ,mem_vec_6585 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x1622 = x1623, x1622_p_0 = 0;
	x1622 < x1623 + 272;
	x1622 += 136, x1622_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 8) (136 / 17)
	for (x1621 = x1622, x1621_p_1 = x1622_p_0, x1621_p_0 = 0;
		x1621 < x1622 + 136;
		x1621 += 17, x1621_p_1 += 17, x1621_p_0 += 17){
		// y = 272, x = 17, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c972 = c973, c972_p_0 = 0;
			c972 < c973 + 32;
			c972 += 4, c972_p_0 += 4){
			// y = 272, x = 17, h = 3, w = 3, c = 4, f = 64
			// T (f, 2) (64 / 32)
			for (f = f508, fp_0 = 0;
				f < f508 + 64;
				f += 32, fp_0 += 32){
					for (y = y648, yp_0 = 0;
						y < y648 + 182;
						y += 14, yp_0 += 14){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x1620 = x1621, x1620_p_2 = x1621_p_1, x1620_p_1 = x1621_p_0, x1620_p_0 = 0;
							x1620 < x1621 + 17;
							x1620 += 1, x1620_p_2 += 1, x1620_p_1 += 1, x1620_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h648, hp_0 = 0;
								h < h648 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w508, wp_0 = 0;
									w < w508 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1620, xp_3 = x1620_p_2, xp_2 = x1620_p_1, xp_1 = x1620_p_0, xp_0 = 0;
										x < x1620 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6528 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6529 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_6552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_6553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_6554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_6555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c972, cp_1 = c972_p_0, cp_0 = 0;
													c < c972 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6528);
													mem_vec_6528 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6529);
													mem_vec_6529 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6530);
													mem_vec_6530 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6531);
													mem_vec_6531 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6532);
													mem_vec_6532 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6533);
													mem_vec_6533 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6534);
													mem_vec_6534 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6535);
													mem_vec_6535 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6536);
													mem_vec_6536 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6537);
													mem_vec_6537 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6538);
													mem_vec_6538 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6539);
													mem_vec_6539 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6540);
													mem_vec_6540 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6541);
													mem_vec_6541 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6542);
													mem_vec_6542 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6543);
													mem_vec_6543 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6544);
													mem_vec_6544 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6545);
													mem_vec_6545 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6546);
													mem_vec_6546 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6547);
													mem_vec_6547 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6548);
													mem_vec_6548 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6549);
													mem_vec_6549 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6550);
													mem_vec_6550 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6551);
													mem_vec_6551 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6552);
													mem_vec_6552 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6553);
													mem_vec_6553 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_6554);
													mem_vec_6554 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_6555);
													mem_vec_6555 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6528);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6529);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6530);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6531);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6532);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6533);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6534);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6535);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6536);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6537);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6538);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6539);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6540);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6541);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6542);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6543);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6544);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6545);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6546);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6547);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6548);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6549);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6550);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6551);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6552);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6553);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6554);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_6555);
									}
								}
							}
						}
					}
					for (y = y648 + 182, yp_0 = 0;
						y < y648 + 182 + 90;
						y += 15, yp_0 += 15){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x1620 = x1621, x1620_p_2 = x1621_p_1, x1620_p_1 = x1621_p_0, x1620_p_0 = 0;
							x1620 < x1621 + 17;
							x1620 += 1, x1620_p_2 += 1, x1620_p_1 += 1, x1620_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h648, hp_0 = 0;
								h < h648 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w508, wp_0 = 0;
									w < w508 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1620, xp_3 = x1620_p_2, xp_2 = x1620_p_1, xp_1 = x1620_p_0, xp_0 = 0;
										x < x1620 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6556 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6557 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_6580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_6581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_6582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_6583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_6584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_6585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c972, cp_1 = c972_p_0, cp_0 = 0;
													c < c972 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6556);
													mem_vec_6556 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6557);
													mem_vec_6557 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6558);
													mem_vec_6558 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6559);
													mem_vec_6559 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6560);
													mem_vec_6560 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6561);
													mem_vec_6561 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6562);
													mem_vec_6562 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6563);
													mem_vec_6563 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6564);
													mem_vec_6564 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6565);
													mem_vec_6565 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6566);
													mem_vec_6566 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6567);
													mem_vec_6567 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6568);
													mem_vec_6568 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6569);
													mem_vec_6569 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6570);
													mem_vec_6570 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6571);
													mem_vec_6571 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6572);
													mem_vec_6572 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6573);
													mem_vec_6573 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6574);
													mem_vec_6574 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6575);
													mem_vec_6575 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6576);
													mem_vec_6576 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6577);
													mem_vec_6577 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6578);
													mem_vec_6578 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6579);
													mem_vec_6579 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6580);
													mem_vec_6580 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6581);
													mem_vec_6581 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_6582);
													mem_vec_6582 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_6583);
													mem_vec_6583 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_6584);
													mem_vec_6584 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_6585);
													mem_vec_6585 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6556);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6557);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6558);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6559);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6560);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6561);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6562);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6563);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6564);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6565);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6566);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6567);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6568);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6569);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6570);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6571);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6572);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6573);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6574);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6575);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6576);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6577);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6578);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6579);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6580);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6581);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_6582);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_6583);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_6584);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_6585);
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