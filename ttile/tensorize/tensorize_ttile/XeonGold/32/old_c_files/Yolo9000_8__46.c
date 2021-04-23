#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c204_p_0, cp_1, c204, f, fp_0, f272_p_0, f273_p_0, fp_1, f272_p_1, fp_2, f272, f273, h, hp_0, w, wp_0, x, xp_0, x204_p_0, xp_1, x204, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y136 = 0;
IND_TYPE x205 = 0;
IND_TYPE h136 = 0;
IND_TYPE w122 = 0;
IND_TYPE c205 = 0;
IND_TYPE f274 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2684 ,mem_vec_2685 ,mem_vec_2686 ,mem_vec_2687 ,mem_vec_2688 ,mem_vec_2689 ,mem_vec_2690 ,mem_vec_2691 ,mem_vec_2692 ,mem_vec_2693 ,mem_vec_2694 ,mem_vec_2695 ,mem_vec_2696 ,mem_vec_2697 ,mem_vec_2698 ,mem_vec_2699 ,mem_vec_2700 ,mem_vec_2701 ,mem_vec_2702 ,mem_vec_2703 ,mem_vec_2704 ,mem_vec_2705 ,mem_vec_2706 ,mem_vec_2707 ,mem_vec_2708 ,mem_vec_2709 ,mem_vec_2710 ,mem_vec_2711 ,mem_vec_2712 ,mem_vec_2713 ,mem_vec_2714 ,mem_vec_2715 ,mem_vec_2716 ,mem_vec_2717 ,mem_vec_2718 ,mem_vec_2719 ,mem_vec_2720 ,mem_vec_2721 ,mem_vec_2722 ,mem_vec_2723 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f273 = f274, f273_p_0 = 0;
	f273 < f274 + 256;
	f273 += 64, f273_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f272 = f273, f272_p_1 = f273_p_0, f272_p_0 = 0;
		f272 < f273 + 64;
		f272 += 32, f272_p_1 += 32, f272_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x204 = x205, x204_p_0 = 0;
			x204 < x205 + 68;
			x204 += 17, x204_p_0 += 17){
				for (y = y136, yp_0 = 0;
					y < y136 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f272, fp_2 = f272_p_1, fp_1 = f272_p_0, fp_0 = 0;
						f < f272 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c204 = c205, c204_p_0 = 0;
							c204 < c205 + 128;
							c204 += 32, c204_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w122, wp_0 = 0;
								w < w122 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x204, xp_1 = x204_p_0, xp_0 = 0;
									x < x204 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h136, hp_0 = 0;
										h < h136 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2684 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2685 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c204, cp_1 = c204_p_0, cp_0 = 0;
													c < c204 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2684);
													mem_vec_2684 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2685);
													mem_vec_2685 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2686);
													mem_vec_2686 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2687);
													mem_vec_2687 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2688);
													mem_vec_2688 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2689);
													mem_vec_2689 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2690);
													mem_vec_2690 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2691);
													mem_vec_2691 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2692);
													mem_vec_2692 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2693);
													mem_vec_2693 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2694);
													mem_vec_2694 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2695);
													mem_vec_2695 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2696);
													mem_vec_2696 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2697);
													mem_vec_2697 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2698);
													mem_vec_2698 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2699);
													mem_vec_2699 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2695);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2696);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2697);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2698);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2699);
									}
								}
							}
						}
					}
				}
				for (y = y136 + 8, yp_0 = 0;
					y < y136 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f272, fp_2 = f272_p_1, fp_1 = f272_p_0, fp_0 = 0;
						f < f272 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c204 = c205, c204_p_0 = 0;
							c204 < c205 + 128;
							c204 += 32, c204_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w122, wp_0 = 0;
								w < w122 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x204, xp_1 = x204_p_0, xp_0 = 0;
									x < x204 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h136, hp_0 = 0;
										h < h136 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_2716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_2718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_2720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_2721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_2722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_2723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c204, cp_1 = c204_p_0, cp_0 = 0;
													c < c204 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2700);
													mem_vec_2700 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2701);
													mem_vec_2701 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2702);
													mem_vec_2702 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2703);
													mem_vec_2703 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2704);
													mem_vec_2704 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2705);
													mem_vec_2705 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2706);
													mem_vec_2706 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2707);
													mem_vec_2707 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2708);
													mem_vec_2708 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2709);
													mem_vec_2709 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2710);
													mem_vec_2710 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2711);
													mem_vec_2711 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2712);
													mem_vec_2712 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2713);
													mem_vec_2713 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2714);
													mem_vec_2714 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2715);
													mem_vec_2715 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2716);
													mem_vec_2716 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2717);
													mem_vec_2717 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2718);
													mem_vec_2718 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2719);
													mem_vec_2719 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2720);
													mem_vec_2720 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2721);
													mem_vec_2721 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2722);
													mem_vec_2722 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2723);
													mem_vec_2723 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2707);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2708);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2709);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2710);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2711);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2712);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2713);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2714);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2715);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2716);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2717);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2718);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2719);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2720);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2721);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2722);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2723);
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