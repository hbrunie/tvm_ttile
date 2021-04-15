#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))];
  T (1, f); T (8, c); T (1, f); T (34, x); T (8, f)]
*/
IND_TYPE c, cp_0, c150_p_0, cp_1, c150, f, fp_0, f200_p_0, f201_p_0, fp_1, f200_p_1, fp_2, f200, f201, h, hp_0, w, wp_0, x, xp_0, x168_p_0, xp_1, x168, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y100 = 0;
IND_TYPE x169 = 0;
IND_TYPE h84 = 0;
IND_TYPE w74 = 0;
IND_TYPE c151 = 0;
IND_TYPE f202 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f201 = f202, f201_p_0 = 0;
	f201 < f202 + 256;
	f201 += 32, f201_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 34) (68 / 2)
	for (x168 = x169, x168_p_0 = 0;
		x168 < x169 + 68;
		x168 += 2, x168_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f200 = f201, f200_p_1 = f201_p_0, f200_p_0 = 0;
			f200 < f201 + 32;
			f200 += 32, f200_p_1 += 32, f200_p_0 += 32){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 32
			// T (c, 8) (128 / 16)
			for (c150 = c151, c150_p_0 = 0;
				c150 < c151 + 128;
				c150 += 16, c150_p_0 += 16){
				// y = 68, x = 2, h = 3, w = 3, c = 16, f = 32
				// T (f, 1) (32 / 32)
				for (f = f200, fp_2 = f200_p_1, fp_1 = f200_p_0, fp_0 = 0;
					f < f200 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y100, yp_0 = 0;
							y < y100 + 28;
							y += 7, yp_0 += 7){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h84, hp_0 = 0;
								h < h84 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w74, wp_0 = 0;
									w < w74 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x168, xp_1 = x168_p_0, xp_0 = 0;
										x < x168 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_568 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_569 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c150, cp_1 = c150_p_0, cp_0 = 0;
													c < c150 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_568);
													mem_vec_568 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_569);
													mem_vec_569 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_570);
													mem_vec_570 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_571);
													mem_vec_571 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_572);
													mem_vec_572 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_573);
													mem_vec_573 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_574);
													mem_vec_574 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_575);
													mem_vec_575 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_576);
													mem_vec_576 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_577);
													mem_vec_577 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_578);
													mem_vec_578 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_579);
													mem_vec_579 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_580);
													mem_vec_580 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_581);
													mem_vec_581 = vec_22;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_568);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_569);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_570);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_571);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_572);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_573);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_574);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_575);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_576);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_577);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_578);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_579);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_580);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_581);
									}
								}
							}
						}
						for (y = y100 + 28, yp_0 = 0;
							y < y100 + 28 + 40;
							y += 8, yp_0 += 8){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h84, hp_0 = 0;
								h < h84 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w74, wp_0 = 0;
									w < w74 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x168, xp_1 = x168_p_0, xp_0 = 0;
										x < x168 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
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
												for (c = c150, cp_1 = c150_p_0, cp_0 = 0;
													c < c150 + 16;
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
		}
	}
}


}