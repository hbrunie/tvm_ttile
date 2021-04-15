#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (16, c); T (8, x); T (16, y); T (2, f); T (2, x)]
*/
IND_TYPE c, cp_0, c432_p_0, cp_1, c432, f, fp_0, f398_p_0, fp_1, f398, h, hp_0, w, wp_0, x, xp_0, x576_p_0, x577_p_0, xp_1, x576_p_1, xp_2, x576, x577, y, yp_0, y432_p_0, yp_1, y432;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y433 = 0;
IND_TYPE x578 = 0;
IND_TYPE h240 = 0;
IND_TYPE w238 = 0;
IND_TYPE c433 = 0;
IND_TYPE f399 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2536 ,mem_vec_2537 ,mem_vec_2538 ,mem_vec_2539 ,mem_vec_2540 ,mem_vec_2541 ,mem_vec_2542 ,mem_vec_2543 ,mem_vec_2544 ,mem_vec_2545 ,mem_vec_2546 ,mem_vec_2547 ,mem_vec_2548 ,mem_vec_2549 ,mem_vec_2550 ,mem_vec_2551 ,mem_vec_2552 ,mem_vec_2553 ,mem_vec_2554 ,mem_vec_2555 ,mem_vec_2556 ,mem_vec_2557 ,mem_vec_2558 ,mem_vec_2559 ,mem_vec_2560 ,mem_vec_2561 ,mem_vec_2562 ,mem_vec_2563 ,mem_vec_2564 ,mem_vec_2565 ,mem_vec_2566 ,mem_vec_2567 ,mem_vec_2568 ,mem_vec_2569 ,mem_vec_2570 ,mem_vec_2571 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x577 = x578, x577_p_0 = 0;
	x577 < x578 + 272;
	x577 += 136, x577_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (f, 2) (64 / 32)
	for (f398 = f399, f398_p_0 = 0;
		f398 < f399 + 64;
		f398 += 32, f398_p_0 += 32){
		// y = 272, x = 136, h = 3, w = 3, c = 32, f = 32
		// T (y, 16) (272 / 17)
		for (y432 = y433, y432_p_0 = 0;
			y432 < y433 + 272;
			y432 += 17, y432_p_0 += 17){
			// y = 17, x = 136, h = 3, w = 3, c = 32, f = 32
			// T (x, 8) (136 / 17)
			for (x576 = x577, x576_p_1 = x577_p_0, x576_p_0 = 0;
				x576 < x577 + 136;
				x576 += 17, x576_p_1 += 17, x576_p_0 += 17){
				// y = 17, x = 17, h = 3, w = 3, c = 32, f = 32
				// T (c, 16) (32 / 2)
				for (c432 = c433, c432_p_0 = 0;
					c432 < c433 + 32;
					c432 += 2, c432_p_0 += 2){
					// y = 17, x = 17, h = 3, w = 3, c = 2, f = 32
					// T (f, 1) (32 / 32)
					for (f = f398, fp_1 = f398_p_0, fp_0 = 0;
						f < f398 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
							for (y = y432, yp_1 = y432_p_0, yp_0 = 0;
								y < y432 + 12;
								y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h240, hp_0 = 0;
									h < h240 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 32
									// T (w, 3) (3 / 1)
									for (w = w238, wp_0 = 0;
										w < w238 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
										// T (x, 17) (17 / 1)
										for (x = x576, xp_2 = x576_p_1, xp_1 = x576_p_0, xp_0 = 0;
											x < x576 + 17;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2536 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2537 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2538 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2539 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
													// T (c, 2) (2 / 1)
													for (c = c432, cp_1 = c432_p_0, cp_0 = 0;
														c < c432 + 2;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2536);
														mem_vec_2536 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2537);
														mem_vec_2537 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2538);
														mem_vec_2538 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2539);
														mem_vec_2539 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2540);
														mem_vec_2540 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2541);
														mem_vec_2541 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2542);
														mem_vec_2542 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2543);
														mem_vec_2543 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2544);
														mem_vec_2544 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2545);
														mem_vec_2545 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2546);
														mem_vec_2546 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2547);
														mem_vec_2547 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2548);
														mem_vec_2548 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2549);
														mem_vec_2549 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2550);
														mem_vec_2550 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2551);
														mem_vec_2551 = vec_23;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2536);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2537);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2538);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2539);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2540);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2541);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2542);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2543);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2544);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2545);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2546);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2547);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2548);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2549);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2550);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2551);
										}
									}
								}
							}
							for (y = y432 + 12, yp_1 = y432_p_0, yp_0 = 0;
								y < y432 + 12 + 5;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h240, hp_0 = 0;
									h < h240 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 3, c = 2, f = 32
									// T (w, 3) (3 / 1)
									for (w = w238, wp_0 = 0;
										w < w238 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 32
										// T (x, 17) (17 / 1)
										for (x = x576, xp_2 = x576_p_1, xp_1 = x576_p_0, xp_0 = 0;
											x < x576 + 17;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2552 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2553 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2554 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2555 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													mem_vec_2568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
													mem_vec_2569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
													mem_vec_2570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
													mem_vec_2571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
													// T (c, 2) (2 / 1)
													for (c = c432, cp_1 = c432_p_0, cp_0 = 0;
														c < c432 + 2;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2552);
														mem_vec_2552 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2553);
														mem_vec_2553 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2554);
														mem_vec_2554 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2555);
														mem_vec_2555 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2556);
														mem_vec_2556 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2557);
														mem_vec_2557 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2558);
														mem_vec_2558 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2559);
														mem_vec_2559 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2560);
														mem_vec_2560 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2561);
														mem_vec_2561 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2562);
														mem_vec_2562 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2563);
														mem_vec_2563 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2564);
														mem_vec_2564 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2565);
														mem_vec_2565 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2566);
														mem_vec_2566 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2567);
														mem_vec_2567 = vec_23;
														scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);


														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2568);
														mem_vec_2568 = vec_24;



														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2569);
														mem_vec_2569 = vec_26;



														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2570);
														mem_vec_2570 = vec_27;



														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2571);
														mem_vec_2571 = vec_28;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2552);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2553);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2554);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2555);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2556);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2557);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2558);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2559);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2560);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2561);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2562);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2563);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2564);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2565);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2566);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2567);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2568);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2569);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2570);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2571);
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


}