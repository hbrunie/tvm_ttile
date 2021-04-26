#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (4, x)]
*/
IND_TYPE c, cp_0, c255_p_0, cp_1, c255, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x332_p_0, x333_p_0, xp_1, x332_p_1, xp_2, x332, x333, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y174 = 0;
IND_TYPE x334 = 0;
IND_TYPE h154 = 0;
IND_TYPE w150 = 0;
IND_TYPE c256 = 0;
IND_TYPE f142 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2704 ,mem_vec_2705 ,mem_vec_2706 ,mem_vec_2707 ,mem_vec_2708 ,mem_vec_2709 ,mem_vec_2710 ,mem_vec_2711 ,mem_vec_2712 ,mem_vec_2713 ,mem_vec_2714 ,mem_vec_2715 ,mem_vec_2716 ,mem_vec_2717 ,mem_vec_2718 ,mem_vec_2719 ,mem_vec_2720 ,mem_vec_2721 ,mem_vec_2722 ,mem_vec_2723 ,mem_vec_2724 ,mem_vec_2725 ,mem_vec_2726 ,mem_vec_2727 ,mem_vec_2728 ,mem_vec_2729 ,mem_vec_2730 ,mem_vec_2731 ,mem_vec_2732 ,mem_vec_2733 ,mem_vec_2734 ,mem_vec_2735 ,mem_vec_2736 ,mem_vec_2737 ,mem_vec_2738 ,mem_vec_2739 ,mem_vec_2740 ,mem_vec_2741 ,mem_vec_2742 ,mem_vec_2743 ,mem_vec_2744 ,mem_vec_2745 ,mem_vec_2746 ,mem_vec_2747 ,mem_vec_2748 ,mem_vec_2749 ,mem_vec_2750 ,mem_vec_2751 ,mem_vec_2752 ,mem_vec_2753 ,mem_vec_2754 ,mem_vec_2755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x333 = x334, x333_p_0 = 0;
	x333 < x334 + 56;
	x333 += 14, x333_p_0 += 14){
		for (y = y174, yp_0 = 0;
			y < y174 + 11;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (14 / 14)
			for (x332 = x333, x332_p_1 = x333_p_0, x332_p_0 = 0;
				x332 < x333 + 14;
				x332 += 14, x332_p_1 += 14, x332_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f142, fp_0 = 0;
					f < f142 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c255 = c256, c255_p_0 = 0;
						c255 < c256 + 64;
						c255 += 16, c255_p_0 += 16){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w150, wp_0 = 0;
							w < w150 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x332, xp_2 = x332_p_1, xp_1 = x332_p_0, xp_0 = 0;
								x < x332 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h154, hp_0 = 0;
									h < h154 + 3;
									h += 1, hp_0 += 1){
											mem_vec_2704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c255, cp_1 = c255_p_0, cp_0 = 0;
												c < c255 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2704);
												mem_vec_2704 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2705);
												mem_vec_2705 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2706);
												mem_vec_2706 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2707);
												mem_vec_2707 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2708);
												mem_vec_2708 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2709);
												mem_vec_2709 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2710);
												mem_vec_2710 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2711);
												mem_vec_2711 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2712);
												mem_vec_2712 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2713);
												mem_vec_2713 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2714);
												mem_vec_2714 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2715);
												mem_vec_2715 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2716);
												mem_vec_2716 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2717);
												mem_vec_2717 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2718);
												mem_vec_2718 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2719);
												mem_vec_2719 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2720);
												mem_vec_2720 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2721);
												mem_vec_2721 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2722);
												mem_vec_2722 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2723);
												mem_vec_2723 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2724);
												mem_vec_2724 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2725);
												mem_vec_2725 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2725);
								}
							}
						}
					}
				}
			}
		}
		for (y = y174 + 11, yp_0 = 0;
			y < y174 + 11 + 45;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (14 / 14)
			for (x332 = x333, x332_p_1 = x333_p_0, x332_p_0 = 0;
				x332 < x333 + 14;
				x332 += 14, x332_p_1 += 14, x332_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f142, fp_0 = 0;
					f < f142 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c255 = c256, c255_p_0 = 0;
						c255 < c256 + 64;
						c255 += 16, c255_p_0 += 16){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w150, wp_0 = 0;
							w < w150 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x332, xp_2 = x332_p_1, xp_1 = x332_p_0, xp_0 = 0;
								x < x332 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h154, hp_0 = 0;
									h < h154 + 3;
									h += 1, hp_0 += 1){
											mem_vec_2726 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2727 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_2748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_2750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_2751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_2752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_2753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_2754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_2755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c255, cp_1 = c255_p_0, cp_0 = 0;
												c < c255 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2726);
												mem_vec_2726 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2727);
												mem_vec_2727 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2728);
												mem_vec_2728 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2729);
												mem_vec_2729 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2730);
												mem_vec_2730 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2731);
												mem_vec_2731 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2732);
												mem_vec_2732 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2733);
												mem_vec_2733 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2734);
												mem_vec_2734 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2735);
												mem_vec_2735 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2736);
												mem_vec_2736 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2737);
												mem_vec_2737 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2738);
												mem_vec_2738 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2739);
												mem_vec_2739 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2740);
												mem_vec_2740 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2741);
												mem_vec_2741 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2742);
												mem_vec_2742 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2743);
												mem_vec_2743 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2744);
												mem_vec_2744 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2745);
												mem_vec_2745 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2746);
												mem_vec_2746 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2747);
												mem_vec_2747 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2748);
												mem_vec_2748 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2749);
												mem_vec_2749 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2750);
												mem_vec_2750 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2751);
												mem_vec_2751 = vec_40;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2752);
												mem_vec_2752 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2753);
												mem_vec_2753 = vec_43;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 14) + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_2754);
												mem_vec_2754 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_2755);
												mem_vec_2755 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_2752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_2753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_2754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_2755);
								}
							}
						}
					}
				}
			}
		}
}


}