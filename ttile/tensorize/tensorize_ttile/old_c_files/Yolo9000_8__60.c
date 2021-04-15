#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (8, f); T (16, c); T (1, f); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c960_p_0, cp_1, c960, f, fp_0, f1280_p_0, f1281_p_0, fp_1, f1280_p_1, fp_2, f1280, f1281, h, hp_0, w, wp_0, x, xp_0, x1012_p_0, xp_1, x1012, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y640 = 0;
IND_TYPE x1013 = 0;
IND_TYPE h640 = 0;
IND_TYPE w588 = 0;
IND_TYPE c961 = 0;
IND_TYPE f1282 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12572 ,mem_vec_12573 ,mem_vec_12574 ,mem_vec_12575 ,mem_vec_12576 ,mem_vec_12577 ,mem_vec_12578 ,mem_vec_12579 ,mem_vec_12580 ,mem_vec_12581 ,mem_vec_12582 ,mem_vec_12583 ,mem_vec_12584 ,mem_vec_12585 ,mem_vec_12586 ,mem_vec_12587 ,mem_vec_12588 ,mem_vec_12589 ,mem_vec_12590 ,mem_vec_12591 ,mem_vec_12592 ,mem_vec_12593 ,mem_vec_12594 ,mem_vec_12595 ,mem_vec_12596 ,mem_vec_12597 ,mem_vec_12598 ,mem_vec_12599 ,mem_vec_12600 ,mem_vec_12601 ,mem_vec_12602 ,mem_vec_12603 ,mem_vec_12604 ,mem_vec_12605 ,mem_vec_12606 ,mem_vec_12607 ,mem_vec_12608 ,mem_vec_12609 ,mem_vec_12610 ,mem_vec_12611 ,mem_vec_12612 ,mem_vec_12613 ,mem_vec_12614 ,mem_vec_12615 ,mem_vec_12616 ,mem_vec_12617 ,mem_vec_12618 ,mem_vec_12619 ,mem_vec_12620 ,mem_vec_12621 ,mem_vec_12622 ,mem_vec_12623 ,mem_vec_12624 ,mem_vec_12625 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1281 = f1282, f1281_p_0 = 0;
	f1281 < f1282 + 256;
	f1281 += 256, f1281_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 2) (68 / 34)
	for (x1012 = x1013, x1012_p_0 = 0;
		x1012 < x1013 + 68;
		x1012 += 34, x1012_p_0 += 34){
		// y = 68, x = 34, h = 3, w = 3, c = 128, f = 256
		// T (f, 1) (256 / 256)
		for (f1280 = f1281, f1280_p_1 = f1281_p_0, f1280_p_0 = 0;
			f1280 < f1281 + 256;
			f1280 += 256, f1280_p_1 += 256, f1280_p_0 += 256){
			// y = 68, x = 34, h = 3, w = 3, c = 128, f = 256
			// T (c, 16) (128 / 8)
			for (c960 = c961, c960_p_0 = 0;
				c960 < c961 + 128;
				c960 += 8, c960_p_0 += 8){
				// y = 68, x = 34, h = 3, w = 3, c = 8, f = 256
				// T (f, 8) (256 / 32)
				for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
					f < f1280 + 256;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y640, yp_0 = 0;
							y < y640 + 26;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h640, hp_0 = 0;
								h < h640 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w588, wp_0 = 0;
									w < w588 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
									// T (x, 34) (34 / 1)
									for (x = x1012, xp_1 = x1012_p_0, xp_0 = 0;
										x < x1012 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12572 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12573 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_12596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_12597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
													c < c960 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12572);
													mem_vec_12572 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12573);
													mem_vec_12573 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12574);
													mem_vec_12574 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12575);
													mem_vec_12575 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12576);
													mem_vec_12576 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12577);
													mem_vec_12577 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12578);
													mem_vec_12578 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12579);
													mem_vec_12579 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12580);
													mem_vec_12580 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12581);
													mem_vec_12581 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12582);
													mem_vec_12582 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12583);
													mem_vec_12583 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12584);
													mem_vec_12584 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12585);
													mem_vec_12585 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12586);
													mem_vec_12586 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12587);
													mem_vec_12587 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12588);
													mem_vec_12588 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12589);
													mem_vec_12589 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12590);
													mem_vec_12590 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12591);
													mem_vec_12591 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12592);
													mem_vec_12592 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12593);
													mem_vec_12593 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12594);
													mem_vec_12594 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12595);
													mem_vec_12595 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12596);
													mem_vec_12596 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12597);
													mem_vec_12597 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12572);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12573);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12574);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12575);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12576);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12577);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12578);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12579);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12580);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12581);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12582);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12583);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12584);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12585);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12586);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12587);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12588);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12589);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12590);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12591);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12592);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12593);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12594);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12595);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12596);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12597);
									}
								}
							}
						}
						for (y = y640 + 26, yp_0 = 0;
							y < y640 + 26 + 42;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h640, hp_0 = 0;
								h < h640 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w588, wp_0 = 0;
									w < w588 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
									// T (x, 34) (34 / 1)
									for (x = x1012, xp_1 = x1012_p_0, xp_0 = 0;
										x < x1012 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12598 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12599 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_12613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_12614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_12615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_12616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_12617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_12618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_12619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_12620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_12621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_12622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_12623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_12624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_12625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
													c < c960 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12598);
													mem_vec_12598 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12599);
													mem_vec_12599 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12600);
													mem_vec_12600 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12601);
													mem_vec_12601 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12602);
													mem_vec_12602 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12603);
													mem_vec_12603 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12604);
													mem_vec_12604 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12605);
													mem_vec_12605 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12606);
													mem_vec_12606 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12607);
													mem_vec_12607 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12608);
													mem_vec_12608 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12609);
													mem_vec_12609 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12610);
													mem_vec_12610 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12611);
													mem_vec_12611 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12612);
													mem_vec_12612 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12613);
													mem_vec_12613 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12614);
													mem_vec_12614 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12615);
													mem_vec_12615 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12616);
													mem_vec_12616 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12617);
													mem_vec_12617 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12618);
													mem_vec_12618 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12619);
													mem_vec_12619 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12620);
													mem_vec_12620 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12621);
													mem_vec_12621 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12622);
													mem_vec_12622 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12623);
													mem_vec_12623 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_12624);
													mem_vec_12624 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_12625);
													mem_vec_12625 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12598);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12599);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12600);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12601);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12602);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12603);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12604);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12605);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12606);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12607);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12608);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12609);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12610);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12611);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12612);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12613);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12614);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12615);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12616);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12617);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12618);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12619);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12620);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12621);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12622);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12623);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_12624);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_12625);
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