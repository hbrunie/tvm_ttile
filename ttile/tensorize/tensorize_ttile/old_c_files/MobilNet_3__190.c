#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (4, f);
  T (128, c); T (4, x)]
*/
IND_TYPE c, cp_0, c372_p_0, cp_1, c372, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x464_p_0, x465_p_0, xp_1, x464_p_1, xp_2, x464, x465, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y248 = 0;
IND_TYPE x466 = 0;
IND_TYPE h200 = 0;
IND_TYPE w218 = 0;
IND_TYPE c373 = 0;
IND_TYPE f312 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2808 ,mem_vec_2809 ,mem_vec_2810 ,mem_vec_2811 ,mem_vec_2812 ,mem_vec_2813 ,mem_vec_2814 ,mem_vec_2815 ,mem_vec_2816 ,mem_vec_2817 ,mem_vec_2818 ,mem_vec_2819 ,mem_vec_2820 ,mem_vec_2821 ,mem_vec_2822 ,mem_vec_2823 ,mem_vec_2824 ,mem_vec_2825 ,mem_vec_2826 ,mem_vec_2827 ,mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,mem_vec_2836 ,mem_vec_2837 ,mem_vec_2838 ,mem_vec_2839 ,mem_vec_2840 ,mem_vec_2841 ,mem_vec_2842 ,mem_vec_2843 ,mem_vec_2844 ,mem_vec_2845 ,mem_vec_2846 ,mem_vec_2847 ,mem_vec_2848 ,mem_vec_2849 ,mem_vec_2850 ,mem_vec_2851 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
for (x465 = x466, x465_p_0 = 0;
	x465 < x466 + 56;
	x465 += 14, x465_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 128) (128 / 1)
	for (c372 = c373, c372_p_0 = 0;
		c372 < c373 + 128;
		c372 += 1, c372_p_0 += 1){
		// y = 56, x = 14, h = 3, w = 3, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f312, fp_0 = 0;
			f < f312 + 128;
			f += 32, fp_0 += 32){
				for (y = y248, yp_0 = 0;
					y < y248 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 2) (14 / 7)
					for (x464 = x465, x464_p_1 = x465_p_0, x464_p_0 = 0;
						x464 < x465 + 14;
						x464 += 7, x464_p_1 += 7, x464_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h200, hp_0 = 0;
							h < h200 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w218, wp_0 = 0;
								w < w218 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 32
								// T (x, 7) (7 / 1)
								for (x = x464, xp_2 = x464_p_1, xp_1 = x464_p_0, xp_0 = 0;
									x < x464 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2808 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2809 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c372, cp_1 = c372_p_0, cp_0 = 0;
												c < c372 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2808);
												mem_vec_2808 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2809);
												mem_vec_2809 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2810);
												mem_vec_2810 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2811);
												mem_vec_2811 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2812);
												mem_vec_2812 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2813);
												mem_vec_2813 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2814);
												mem_vec_2814 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2815);
												mem_vec_2815 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2816);
												mem_vec_2816 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2817);
												mem_vec_2817 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2818);
												mem_vec_2818 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2819);
												mem_vec_2819 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2820);
												mem_vec_2820 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2821);
												mem_vec_2821 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2822);
												mem_vec_2822 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2823);
												mem_vec_2823 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2824);
												mem_vec_2824 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2825);
												mem_vec_2825 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2826);
												mem_vec_2826 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2827);
												mem_vec_2827 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2827);
								}
							}
						}
					}
				}
				for (y = y248 + 20, yp_0 = 0;
					y < y248 + 20 + 36;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 2) (14 / 7)
					for (x464 = x465, x464_p_1 = x465_p_0, x464_p_0 = 0;
						x464 < x465 + 14;
						x464 += 7, x464_p_1 += 7, x464_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h200, hp_0 = 0;
							h < h200 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w218, wp_0 = 0;
								w < w218 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 32
								// T (x, 7) (7 / 1)
								for (x = x464, xp_2 = x464_p_1, xp_1 = x464_p_0, xp_0 = 0;
									x < x464 + 7;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_2850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c372, cp_1 = c372_p_0, cp_0 = 0;
												c < c372 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2828);
												mem_vec_2828 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2829);
												mem_vec_2829 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2830);
												mem_vec_2830 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2831);
												mem_vec_2831 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2832);
												mem_vec_2832 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2833);
												mem_vec_2833 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2834);
												mem_vec_2834 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2835);
												mem_vec_2835 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2836);
												mem_vec_2836 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2837);
												mem_vec_2837 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2838);
												mem_vec_2838 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2839);
												mem_vec_2839 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2840);
												mem_vec_2840 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2841);
												mem_vec_2841 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2842);
												mem_vec_2842 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2843);
												mem_vec_2843 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2844);
												mem_vec_2844 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2845);
												mem_vec_2845 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2846);
												mem_vec_2846 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2847);
												mem_vec_2847 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2848);
												mem_vec_2848 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2849);
												mem_vec_2849 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2850);
												mem_vec_2850 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2851);
												mem_vec_2851 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2851);
								}
							}
						}
					}
				}
		}
	}
}


}