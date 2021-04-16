#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (8, y); T (2, f); T (2, x); T (1, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c246_p_0, cp_1, c246, f, fp_0, x, xp_0, x410_p_0, x411_p_0, x412_p_0, xp_1, x410_p_1, x411_p_1, xp_2, x410_p_2, xp_3, x410, x411, x412, y, yp_0, y328_p_0, y329_p_0, yp_1, y328_p_1, yp_2, y328, y329;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y330 = 0;
IND_TYPE x413 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c247 = 0;
IND_TYPE f164 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2552 ,mem_vec_2553 ,mem_vec_2554 ,mem_vec_2555 ,mem_vec_2556 ,mem_vec_2557 ,mem_vec_2558 ,mem_vec_2559 ,mem_vec_2560 ,mem_vec_2561 ,mem_vec_2562 ,mem_vec_2563 ,mem_vec_2564 ,mem_vec_2565 ,mem_vec_2566 ,mem_vec_2567 ,mem_vec_2568 ,mem_vec_2569 ,mem_vec_2570 ,mem_vec_2571 ,mem_vec_2572 ,mem_vec_2573 ,mem_vec_2574 ,mem_vec_2575 ,mem_vec_2576 ,mem_vec_2577 ,mem_vec_2578 ,mem_vec_2579 ,mem_vec_2580 ,mem_vec_2581 ,mem_vec_2582 ,mem_vec_2583 ,mem_vec_2584 ,mem_vec_2585 ,mem_vec_2586 ,mem_vec_2587 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y329 = y330, y329_p_0 = 0;
		y329 < y330 + 96;
		y329 += 32, y329_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x412 = x413, x412_p_0 = 0;
			x412 < x413 + 136;
			x412 += 2, x412_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y328 = y329, y328_p_1 = y329_p_0, y328_p_0 = 0;
				y328 < y329 + 32;
				y328 += 32, y328_p_1 += 32, y328_p_0 += 32){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x411 = x412, x411_p_1 = x412_p_0, x411_p_0 = 0;
					x411 < x412 + 2;
					x411 += 1, x411_p_1 += 1, x411_p_0 += 1){
					// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f164, fp_0 = 0;
						f < f164 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y328, yp_2 = y328_p_1, yp_1 = y328_p_0, yp_0 = 0;
							y < y328 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x410 = x411, x410_p_2 = x411_p_1, x410_p_1 = x411_p_0, x410_p_0 = 0;
								x410 < x411 + 1;
								x410 += 1, x410_p_2 += 1, x410_p_1 += 1, x410_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c246 = c247, c246_p_0 = 0;
									c246 < c247 + 128;
									c246 += 32, c246_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x410, xp_3 = x410_p_2, xp_2 = x410_p_1, xp_1 = x410_p_0, xp_0 = 0;
										x < x410 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c246, cp_1 = c246_p_0, cp_0 = 0;
													c < c246 + 32;
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
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y329 = y330 + 96, y329_p_0 = 0;
		y329 < y330 + 96 + 40;
		y329 += 40, y329_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x412 = x413, x412_p_0 = 0;
			x412 < x413 + 136;
			x412 += 2, x412_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y328 = y329, y328_p_1 = y329_p_0, y328_p_0 = 0;
				y328 < y329 + 40;
				y328 += 40, y328_p_1 += 40, y328_p_0 += 40){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x411 = x412, x411_p_1 = x412_p_0, x411_p_0 = 0;
					x411 < x412 + 2;
					x411 += 1, x411_p_1 += 1, x411_p_0 += 1){
					// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f164, fp_0 = 0;
						f < f164 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y328, yp_2 = y328_p_1, yp_1 = y328_p_0, yp_0 = 0;
							y < y328 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x410 = x411, x410_p_2 = x411_p_1, x410_p_1 = x411_p_0, x410_p_0 = 0;
								x410 < x411 + 1;
								x410 += 1, x410_p_2 += 1, x410_p_1 += 1, x410_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c246 = c247, c246_p_0 = 0;
									c246 < c247 + 128;
									c246 += 32, c246_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x410, xp_3 = x410_p_2, xp_2 = x410_p_1, xp_1 = x410_p_0, xp_0 = 0;
										x < x410 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2568 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2569 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2570 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2571 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_2584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c246, cp_1 = c246_p_0, cp_0 = 0;
													c < c246 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2568);
													mem_vec_2568 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2569);
													mem_vec_2569 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2570);
													mem_vec_2570 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2571);
													mem_vec_2571 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2572);
													mem_vec_2572 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2573);
													mem_vec_2573 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2574);
													mem_vec_2574 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2575);
													mem_vec_2575 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2576);
													mem_vec_2576 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2577);
													mem_vec_2577 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2578);
													mem_vec_2578 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2579);
													mem_vec_2579 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2580);
													mem_vec_2580 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2581);
													mem_vec_2581 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2582);
													mem_vec_2582 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2583);
													mem_vec_2583 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2584);
													mem_vec_2584 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2585);
													mem_vec_2585 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2586);
													mem_vec_2586 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2587);
													mem_vec_2587 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2575);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2577);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2579);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2587);
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