#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (4, f); T (1, f)]
*/
IND_TYPE c, cp_0, c195_p_0, cp_1, c195, f, fp_0, f260_p_0, f261_p_0, fp_1, f260_p_1, fp_2, f260, f261, h, hp_0, w, wp_0, x, xp_0, x195_p_0, xp_1, x195, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y130 = 0;
IND_TYPE x196 = 0;
IND_TYPE h130 = 0;
IND_TYPE w116 = 0;
IND_TYPE c196 = 0;
IND_TYPE f262 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2564 ,mem_vec_2565 ,mem_vec_2566 ,mem_vec_2567 ,mem_vec_2568 ,mem_vec_2569 ,mem_vec_2570 ,mem_vec_2571 ,mem_vec_2572 ,mem_vec_2573 ,mem_vec_2574 ,mem_vec_2575 ,mem_vec_2576 ,mem_vec_2577 ,mem_vec_2578 ,mem_vec_2579 ,mem_vec_2580 ,mem_vec_2581 ,mem_vec_2582 ,mem_vec_2583 ,mem_vec_2584 ,mem_vec_2585 ,mem_vec_2586 ,mem_vec_2587 ,mem_vec_2588 ,mem_vec_2589 ,mem_vec_2590 ,mem_vec_2591 ,mem_vec_2592 ,mem_vec_2593 ,mem_vec_2594 ,mem_vec_2595 ,mem_vec_2596 ,mem_vec_2597 ,mem_vec_2598 ,mem_vec_2599 ,mem_vec_2600 ,mem_vec_2601 ,mem_vec_2602 ,mem_vec_2603 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f261 = f262, f261_p_0 = 0;
	f261 < f262 + 256;
	f261 += 256, f261_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 4) (256 / 64)
	for (f260 = f261, f260_p_1 = f261_p_0, f260_p_0 = 0;
		f260 < f261 + 256;
		f260 += 64, f260_p_1 += 64, f260_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 4) (68 / 17)
		for (x195 = x196, x195_p_0 = 0;
			x195 < x196 + 68;
			x195 += 17, x195_p_0 += 17){
				for (y = y130, yp_0 = 0;
					y < y130 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f260, fp_2 = f260_p_1, fp_1 = f260_p_0, fp_0 = 0;
						f < f260 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c195 = c196, c195_p_0 = 0;
							c195 < c196 + 128;
							c195 += 32, c195_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w116, wp_0 = 0;
								w < w116 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x195, xp_1 = x195_p_0, xp_0 = 0;
									x < x195 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h130, hp_0 = 0;
										h < h130 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2564 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2565 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c195, cp_1 = c195_p_0, cp_0 = 0;
													c < c195 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2564);
													mem_vec_2564 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2565);
													mem_vec_2565 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2566);
													mem_vec_2566 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2567);
													mem_vec_2567 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2568);
													mem_vec_2568 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2569);
													mem_vec_2569 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2570);
													mem_vec_2570 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2571);
													mem_vec_2571 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2572);
													mem_vec_2572 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2573);
													mem_vec_2573 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2574);
													mem_vec_2574 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2575);
													mem_vec_2575 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2576);
													mem_vec_2576 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2577);
													mem_vec_2577 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2578);
													mem_vec_2578 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2579);
													mem_vec_2579 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2564);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2565);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2566);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2567);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2568);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2569);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2570);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2571);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2572);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2573);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2574);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2575);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2576);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2577);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2578);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2579);
									}
								}
							}
						}
					}
				}
				for (y = y130 + 8, yp_0 = 0;
					y < y130 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f260, fp_2 = f260_p_1, fp_1 = f260_p_0, fp_0 = 0;
						f < f260 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c195 = c196, c195_p_0 = 0;
							c195 < c196 + 128;
							c195 += 32, c195_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w116, wp_0 = 0;
								w < w116 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x195, xp_1 = x195_p_0, xp_0 = 0;
									x < x195 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h130, hp_0 = 0;
										h < h130 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2580 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2581 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_2596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_2598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_2600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_2601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_2602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_2603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c195, cp_1 = c195_p_0, cp_0 = 0;
													c < c195 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2580);
													mem_vec_2580 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2581);
													mem_vec_2581 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2582);
													mem_vec_2582 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2583);
													mem_vec_2583 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2584);
													mem_vec_2584 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2585);
													mem_vec_2585 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2586);
													mem_vec_2586 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2587);
													mem_vec_2587 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2588);
													mem_vec_2588 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2589);
													mem_vec_2589 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2590);
													mem_vec_2590 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2591);
													mem_vec_2591 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2592);
													mem_vec_2592 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2593);
													mem_vec_2593 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2594);
													mem_vec_2594 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2595);
													mem_vec_2595 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2596);
													mem_vec_2596 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2597);
													mem_vec_2597 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2598);
													mem_vec_2598 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2599);
													mem_vec_2599 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2600);
													mem_vec_2600 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2601);
													mem_vec_2601 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2602);
													mem_vec_2602 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2603);
													mem_vec_2603 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2580);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2581);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2582);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2583);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2584);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2585);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2586);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2587);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2588);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2589);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2590);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2591);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2592);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2593);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2594);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2595);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2596);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2597);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2598);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2599);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2600);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2601);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2602);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2603);
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