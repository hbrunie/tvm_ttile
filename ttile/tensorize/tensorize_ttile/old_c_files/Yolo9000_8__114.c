#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (2, x);
  T (1, f); T (8, f)]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, f60_p_0, f61_p_0, fp_1, f60_p_1, fp_2, f60, f61, h, hp_0, w, wp_0, x, xp_0, x45_p_0, xp_1, x45, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y30 = 0;
IND_TYPE x46 = 0;
IND_TYPE h30 = 0;
IND_TYPE w30 = 0;
IND_TYPE c46 = 0;
IND_TYPE f62 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f61 = f62, f61_p_0 = 0;
	f61 < f62 + 256;
	f61 += 32, f61_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (f, 1) (32 / 32)
	for (f60 = f61, f60_p_1 = f61_p_0, f60_p_0 = 0;
		f60 < f61 + 32;
		f60 += 32, f60_p_1 += 32, f60_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 2) (68 / 34)
		for (x45 = x46, x45_p_0 = 0;
			x45 < x46 + 68;
			x45 += 34, x45_p_0 += 34){
				for (y = y30, yp_0 = 0;
					y < y30 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f60, fp_2 = f60_p_1, fp_1 = f60_p_0, fp_0 = 0;
						f < f60 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 128;
							c45 += 16, c45_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w30, wp_0 = 0;
								w < w30 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
									x < x45 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h30, hp_0 = 0;
										h < h30 + 3;
										h += 1, hp_0 += 1){
												mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
													c < c45 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_582);
													mem_vec_582 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_583);
													mem_vec_583 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_584);
													mem_vec_584 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_585);
													mem_vec_585 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_586);
													mem_vec_586 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_587);
													mem_vec_587 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_588);
													mem_vec_588 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_589);
													mem_vec_589 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_590);
													mem_vec_590 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_591);
													mem_vec_591 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_592);
													mem_vec_592 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_593);
													mem_vec_593 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_594);
													mem_vec_594 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_595);
													mem_vec_595 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_596);
													mem_vec_596 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_597);
													mem_vec_597 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_582);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_583);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_584);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_585);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_586);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_587);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_588);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_589);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_590);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_591);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_592);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_593);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_594);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_595);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_596);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_597);
									}
								}
							}
						}
					}
				}
				for (y = y30 + 24, yp_0 = 0;
					y < y30 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f60, fp_2 = f60_p_1, fp_1 = f60_p_0, fp_0 = 0;
						f < f60 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c45 = c46, c45_p_0 = 0;
							c45 < c46 + 128;
							c45 += 16, c45_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w30, wp_0 = 0;
								w < w30 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
									x < x45 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h30, hp_0 = 0;
										h < h30 + 3;
										h += 1, hp_0 += 1){
												mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
													c < c45 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_598);
													mem_vec_598 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_599);
													mem_vec_599 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_600);
													mem_vec_600 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_601);
													mem_vec_601 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_602);
													mem_vec_602 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_603);
													mem_vec_603 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_604);
													mem_vec_604 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_605);
													mem_vec_605 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_606);
													mem_vec_606 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_607);
													mem_vec_607 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_608);
													mem_vec_608 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_609);
													mem_vec_609 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_610);
													mem_vec_610 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_611);
													mem_vec_611 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_612);
													mem_vec_612 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_613);
													mem_vec_613 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_614);
													mem_vec_614 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_615);
													mem_vec_615 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_616);
													mem_vec_616 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_617);
													mem_vec_617 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_618);
													mem_vec_618 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_619);
													mem_vec_619 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_598);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_599);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_600);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_601);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_602);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_603);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_604);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_605);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_606);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_607);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_608);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_609);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_610);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_611);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_612);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_613);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_614);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_615);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_616);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_617);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_618);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_619);
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