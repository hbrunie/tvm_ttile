#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f);
  T (64, c); T (16, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f64_p_0, f65_p_0, fp_1, f64_p_1, fp_2, f64, f65, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y32 = 0;
IND_TYPE x49 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_524 ,mem_vec_525 ,mem_vec_526 ,mem_vec_527 ,mem_vec_528 ,mem_vec_529 ,mem_vec_530 ,mem_vec_531 ,mem_vec_532 ,mem_vec_533 ,mem_vec_534 ,mem_vec_535 ,mem_vec_536 ,mem_vec_537 ,mem_vec_538 ,mem_vec_539 ,mem_vec_540 ,mem_vec_541 ,mem_vec_542 ,mem_vec_543 ,mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f65 = f66, f65_p_0 = 0;
	f65 < f66 + 1024;
	f65 += 64, f65_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 64) (512 / 8)
	for (c48 = c49, c48_p_0 = 0;
		c48 < c49 + 512;
		c48 += 8, c48_p_0 += 8){
		// y = 17, x = 17, h = 3, w = 3, c = 8, f = 64
		// T (f, 1) (64 / 64)
		for (f64 = f65, f64_p_1 = f65_p_0, f64_p_0 = 0;
			f64 < f65 + 64;
			f64 += 64, f64_p_1 += 64, f64_p_0 += 64){
				for (y = y32, yp_0 = 0;
					y < y32 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
					// T (x, 1) (17 / 17)
					for (x48 = x49, x48_p_0 = 0;
						x48 < x49 + 17;
						x48 += 17, x48_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
						// T (f, 1) (64 / 64)
						for (f = f64, fp_2 = f64_p_1, fp_1 = f64_p_0, fp_0 = 0;
							f < f64 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h32, hp_0 = 0;
								h < h32 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 8, f = 64
								// T (w, 3) (3 / 1)
								for (w = w32, wp_0 = 0;
									w < w32 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
									// T (x, 17) (17 / 1)
									for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
										x < x48 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_524 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_525 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_526 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_527 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
												// T (c, 8) (8 / 1)
												for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
													c < c48 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_524);
													mem_vec_524 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_525);
													mem_vec_525 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_526);
													mem_vec_526 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_527);
													mem_vec_527 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_528);
													mem_vec_528 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_529);
													mem_vec_529 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_530);
													mem_vec_530 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_531);
													mem_vec_531 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_532);
													mem_vec_532 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_533);
													mem_vec_533 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_534);
													mem_vec_534 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_535);
													mem_vec_535 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_536);
													mem_vec_536 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_537);
													mem_vec_537 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_538);
													mem_vec_538 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_539);
													mem_vec_539 = vec_23;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_524);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_525);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_526);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_527);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_528);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_529);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_530);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_531);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_532);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_533);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_534);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_535);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_536);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_537);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_538);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_539);
									}
								}
							}
						}
					}
				}
				for (y = y32 + 12, yp_0 = 0;
					y < y32 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
					// T (x, 1) (17 / 17)
					for (x48 = x49, x48_p_0 = 0;
						x48 < x49 + 17;
						x48 += 17, x48_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
						// T (f, 1) (64 / 64)
						for (f = f64, fp_2 = f64_p_1, fp_1 = f64_p_0, fp_0 = 0;
							f < f64 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h32, hp_0 = 0;
								h < h32 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 8, f = 64
								// T (w, 3) (3 / 1)
								for (w = w32, wp_0 = 0;
									w < w32 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
									// T (x, 17) (17 / 1)
									for (x = x48, xp_1 = x48_p_0, xp_0 = 0;
										x < x48 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_540 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_541 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_542 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_543 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
												// T (c, 8) (8 / 1)
												for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
													c < c48 + 8;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_540);
													mem_vec_540 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_541);
													mem_vec_541 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_542);
													mem_vec_542 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_543);
													mem_vec_543 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_544);
													mem_vec_544 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_545);
													mem_vec_545 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_546);
													mem_vec_546 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_547);
													mem_vec_547 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_548);
													mem_vec_548 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_549);
													mem_vec_549 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_550);
													mem_vec_550 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_551);
													mem_vec_551 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_552);
													mem_vec_552 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_553);
													mem_vec_553 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_554);
													mem_vec_554 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_555);
													mem_vec_555 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_556);
													mem_vec_556 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_557);
													mem_vec_557 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_558);
													mem_vec_558 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_559);
													mem_vec_559 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_540);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_541);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_542);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_543);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_544);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_545);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_546);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_547);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_548);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_549);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_550);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_551);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_552);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_553);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_554);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_555);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_556);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_557);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_558);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_559);
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