#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (16, y); T (2, f); T (1, c); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, f);
  T (4, x)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, f, fp_0, f410_p_0, fp_1, f410, h, hp_0, w, wp_0, x, xp_0, x592_p_0, x593_p_0, xp_1, x592_p_1, xp_2, x592, x593, y, yp_0, y444_p_0, yp_1, y444;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y445 = 0;
IND_TYPE x594 = 0;
IND_TYPE h248 = 0;
IND_TYPE w246 = 0;
IND_TYPE c445 = 0;
IND_TYPE f411 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2680 ,mem_vec_2681 ,mem_vec_2682 ,mem_vec_2683 ,mem_vec_2684 ,mem_vec_2685 ,mem_vec_2686 ,mem_vec_2687 ,mem_vec_2688 ,mem_vec_2689 ,mem_vec_2690 ,mem_vec_2691 ,mem_vec_2692 ,mem_vec_2693 ,mem_vec_2694 ,mem_vec_2695 ,mem_vec_2696 ,mem_vec_2697 ,mem_vec_2698 ,mem_vec_2699 ,mem_vec_2700 ,mem_vec_2701 ,mem_vec_2702 ,mem_vec_2703 ,mem_vec_2704 ,mem_vec_2705 ,mem_vec_2706 ,mem_vec_2707 ,mem_vec_2708 ,mem_vec_2709 ,mem_vec_2710 ,mem_vec_2711 ,mem_vec_2712 ,mem_vec_2713 ,mem_vec_2714 ,mem_vec_2715 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 4) (272 / 68)
for (x593 = x594, x593_p_0 = 0;
	x593 < x594 + 272;
	x593 += 68, x593_p_0 += 68){
	// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
	// T (f, 1) (64 / 64)
	for (f410 = f411, f410_p_0 = 0;
		f410 < f411 + 64;
		f410 += 64, f410_p_0 += 64){
			for (y444 = y445, y444_p_0 = 0;
				y444 < y445 + 192;
				y444 += 64, y444_p_0 += 64){
				// y = 16 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 68) (68 / 1)
				for (x592 = x593, x592_p_1 = x593_p_0, x592_p_0 = 0;
					x592 < x593 + 68;
					x592 += 1, x592_p_1 += 1, x592_p_0 += 1){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c444 = c445, c444_p_0 = 0;
						c444 < c445 + 32;
						c444 += 32, c444_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f410, fp_1 = f410_p_0, fp_0 = 0;
							f < f410 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (y, 16) (16 * ph_y / ph_y)
							for (y = y444, yp_1 = y444_p_0, yp_0 = 0;
								y < y444 + 64;
								y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h248, hp_0 = 0;
									h < h248 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w246, wp_0 = 0;
										w < w246 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (x, 1) (1 / 1)
										for (x = x592, xp_2 = x592_p_1, xp_1 = x592_p_0, xp_0 = 0;
											x < x592 + 1;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2680 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2681 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2682 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2683 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2684 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2685 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2686 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2687 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2688 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2689 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2690 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2691 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2692 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2693 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2694 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2695 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
													// T (c, 32) (32 / 1)
													for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
														c < c444 + 32;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2680);
														mem_vec_2680 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2681);
														mem_vec_2681 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2682);
														mem_vec_2682 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2683);
														mem_vec_2683 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2684);
														mem_vec_2684 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2685);
														mem_vec_2685 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2686);
														mem_vec_2686 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2687);
														mem_vec_2687 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2688);
														mem_vec_2688 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2689);
														mem_vec_2689 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2690);
														mem_vec_2690 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2691);
														mem_vec_2691 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2692);
														mem_vec_2692 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2693);
														mem_vec_2693 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2694);
														mem_vec_2694 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2695);
														mem_vec_2695 = vec_23;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2680);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2681);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2682);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2683);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2684);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2685);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2686);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2687);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2688);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2689);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2690);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2691);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2692);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2693);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2694);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2695);
										}
									}
								}
							}
						}
					}
				}
			}
			for (y444 = y445 + 192, y444_p_0 = 0;
				y444 < y445 + 192 + 80;
				y444 += 80, y444_p_0 += 80){
				// y = 16 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 68) (68 / 1)
				for (x592 = x593, x592_p_1 = x593_p_0, x592_p_0 = 0;
					x592 < x593 + 68;
					x592 += 1, x592_p_1 += 1, x592_p_0 += 1){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c444 = c445, c444_p_0 = 0;
						c444 < c445 + 32;
						c444 += 32, c444_p_0 += 32){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f410, fp_1 = f410_p_0, fp_0 = 0;
							f < f410 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (y, 16) (16 * ph_y / ph_y)
							for (y = y444, yp_1 = y444_p_0, yp_0 = 0;
								y < y444 + 80;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h248, hp_0 = 0;
									h < h248 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w246, wp_0 = 0;
										w < w246 + 3;
										w += 1, wp_0 += 1){
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (x, 1) (1 / 1)
										for (x = x592, xp_2 = x592_p_1, xp_1 = x592_p_0, xp_0 = 0;
											x < x592 + 1;
											x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
													mem_vec_2696 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
													mem_vec_2697 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
													mem_vec_2698 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
													mem_vec_2699 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
													mem_vec_2700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
													mem_vec_2701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
													mem_vec_2702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
													mem_vec_2703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
													mem_vec_2704 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
													mem_vec_2705 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
													mem_vec_2706 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
													mem_vec_2707 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
													mem_vec_2708 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
													mem_vec_2709 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
													mem_vec_2710 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
													mem_vec_2711 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
													mem_vec_2712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
													mem_vec_2713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
													mem_vec_2714 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
													mem_vec_2715 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
													// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
													// T (c, 32) (32 / 1)
													for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
														c < c444 + 32;
														c += 1, cp_1 += 1, cp_0 += 1){
														scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
														vec_1 = _mm256_set1_ps(scal_0);
														vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

														vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2696);
														mem_vec_2696 = vec_0;

														vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

														vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2697);
														mem_vec_2697 = vec_3;

														vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

														vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2698);
														mem_vec_2698 = vec_5;

														vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

														vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2699);
														mem_vec_2699 = vec_7;
														scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
														vec_10 = _mm256_set1_ps(scal_1);


														vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2700);
														mem_vec_2700 = vec_9;



														vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2701);
														mem_vec_2701 = vec_11;



														vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2702);
														mem_vec_2702 = vec_12;



														vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2703);
														mem_vec_2703 = vec_13;
														scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
														vec_15 = _mm256_set1_ps(scal_2);


														vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2704);
														mem_vec_2704 = vec_14;



														vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2705);
														mem_vec_2705 = vec_16;



														vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2706);
														mem_vec_2706 = vec_17;



														vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2707);
														mem_vec_2707 = vec_18;
														scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
														vec_20 = _mm256_set1_ps(scal_3);


														vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2708);
														mem_vec_2708 = vec_19;



														vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2709);
														mem_vec_2709 = vec_21;



														vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2710);
														mem_vec_2710 = vec_22;



														vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2711);
														mem_vec_2711 = vec_23;
														scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
														vec_25 = _mm256_set1_ps(scal_4);


														vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2712);
														mem_vec_2712 = vec_24;



														vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2713);
														mem_vec_2713 = vec_26;



														vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2714);
														mem_vec_2714 = vec_27;



														vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2715);
														mem_vec_2715 = vec_28;
													}
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2696);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2697);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2698);
												_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2699);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2700);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2701);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2702);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2703);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2704);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2705);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2706);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2707);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2708);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2709);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2710);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2711);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2712);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2713);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2714);
												_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2715);
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