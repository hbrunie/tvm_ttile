#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (1, f);
  T (4, c); T (4, f)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, f96_p_0, f97_p_0, fp_1, f96_p_1, fp_2, f96, f97, h, hp_0, w, wp_0, x, xp_0, x72_p_0, xp_1, x72, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y48 = 0;
IND_TYPE x73 = 0;
IND_TYPE h40 = 0;
IND_TYPE w46 = 0;
IND_TYPE c73 = 0;
IND_TYPE f98 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f97 = f98, f97_p_0 = 0;
	f97 < f98 + 512;
	f97 += 128, f97_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 4) (256 / 64)
	for (c72 = c73, c72_p_0 = 0;
		c72 < c73 + 256;
		c72 += 64, c72_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 128
		// T (f, 1) (128 / 128)
		for (f96 = f97, f96_p_1 = f97_p_0, f96_p_0 = 0;
			f96 < f97 + 128;
			f96 += 128, f96_p_1 += 128, f96_p_0 += 128){
				for (y = y48, yp_0 = 0;
					y < y48 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
					// T (x, 17) (34 / 2)
					for (x72 = x73, x72_p_0 = 0;
						x72 < x73 + 34;
						x72 += 2, x72_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f96, fp_2 = f96_p_1, fp_1 = f96_p_0, fp_0 = 0;
							f < f96 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w46, wp_0 = 0;
									w < w46 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
										x < x72 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
													c < c72 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_576);
													mem_vec_576 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_577);
													mem_vec_577 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_578);
													mem_vec_578 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_579);
													mem_vec_579 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_580);
													mem_vec_580 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_581);
													mem_vec_581 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_582);
													mem_vec_582 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_583);
													mem_vec_583 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_584);
													mem_vec_584 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_585);
													mem_vec_585 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_586);
													mem_vec_586 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_587);
													mem_vec_587 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_588);
													mem_vec_588 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_589);
													mem_vec_589 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_590);
													mem_vec_590 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_591);
													mem_vec_591 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_576);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_577);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_578);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_579);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_580);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_581);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_582);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_583);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_584);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_585);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_586);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_587);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_588);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_589);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_590);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_591);
									}
								}
							}
						}
					}
				}
				for (y = y48 + 8, yp_0 = 0;
					y < y48 + 8 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
					// T (x, 17) (34 / 2)
					for (x72 = x73, x72_p_0 = 0;
						x72 < x73 + 34;
						x72 += 2, x72_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 128
						// T (f, 4) (128 / 32)
						for (f = f96, fp_2 = f96_p_1, fp_1 = f96_p_0, fp_0 = 0;
							f < f96 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w46, wp_0 = 0;
									w < w46 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
									// T (x, 2) (2 / 1)
									for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
										x < x72 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
													c < c72 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_592);
													mem_vec_592 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_593);
													mem_vec_593 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_594);
													mem_vec_594 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_595);
													mem_vec_595 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_596);
													mem_vec_596 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_597);
													mem_vec_597 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_598);
													mem_vec_598 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_599);
													mem_vec_599 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_600);
													mem_vec_600 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_601);
													mem_vec_601 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_602);
													mem_vec_602 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_603);
													mem_vec_603 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_604);
													mem_vec_604 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_605);
													mem_vec_605 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_606);
													mem_vec_606 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_607);
													mem_vec_607 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_608);
													mem_vec_608 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_609);
													mem_vec_609 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_610);
													mem_vec_610 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_611);
													mem_vec_611 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_612);
													mem_vec_612 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_613);
													mem_vec_613 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_614);
													mem_vec_614 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_615);
													mem_vec_615 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_616);
													mem_vec_616 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_617);
													mem_vec_617 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_592);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_593);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_594);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_595);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_596);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_597);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_598);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_599);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_600);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_601);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_602);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_603);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_604);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_605);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_606);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_607);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_608);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_609);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_610);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_611);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_612);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_613);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_614);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_615);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_616);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_617);
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