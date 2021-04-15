#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 6)); ((Iter 2), (Arg 8))]; T (1, f);
  T (64, c); T (2, f)]
*/
IND_TYPE c, cp_0, c344_p_0, cp_1, c344, f, fp_0, f312_p_0, f313_p_0, fp_1, f312_p_1, fp_2, f312, f313, w, wp_0, x, xp_0, x344_p_0, xp_1, x344, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y200 = 0;
IND_TYPE x345 = 0;
IND_TYPE h = 0;
IND_TYPE w198 = 0;
IND_TYPE c345 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2810 ,mem_vec_2811 ,mem_vec_2812 ,mem_vec_2813 ,mem_vec_2814 ,mem_vec_2815 ,mem_vec_2816 ,mem_vec_2817 ,mem_vec_2818 ,mem_vec_2819 ,mem_vec_2820 ,mem_vec_2821 ,mem_vec_2822 ,mem_vec_2823 ,mem_vec_2824 ,mem_vec_2825 ,mem_vec_2826 ,mem_vec_2827 ,mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,mem_vec_2836 ,mem_vec_2837 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f313 = f314, f313_p_0 = 0;
	f313 < f314 + 512;
	f313 += 256, f313_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 64) (256 / 4)
	for (c344 = c345, c344_p_0 = 0;
		c344 < c345 + 256;
		c344 += 4, c344_p_0 += 4){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 256
		// T (f, 1) (256 / 256)
		for (f312 = f313, f312_p_1 = f313_p_0, f312_p_0 = 0;
			f312 < f313 + 256;
			f312 += 256, f312_p_1 += 256, f312_p_0 += 256){
				for (y = y200, yp_0 = 0;
					y < y200 + 18;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 17) (34 / 2)
					for (x344 = x345, x344_p_0 = 0;
						x344 < x345 + 34;
						x344 += 2, x344_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
							f < f312 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w198, wp_0 = 0;
								w < w198 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 32
								// T (x, 2) (2 / 1)
								for (x = x344, xp_1 = x344_p_0, xp_0 = 0;
									x < x344 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2810 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2811 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c344, cp_1 = c344_p_0, cp_0 = 0;
												c < c344 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2810);
												mem_vec_2810 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2811);
												mem_vec_2811 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2812);
												mem_vec_2812 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2813);
												mem_vec_2813 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2814);
												mem_vec_2814 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2815);
												mem_vec_2815 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2816);
												mem_vec_2816 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2817);
												mem_vec_2817 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2818);
												mem_vec_2818 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2819);
												mem_vec_2819 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2820);
												mem_vec_2820 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2821);
												mem_vec_2821 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_2810);
												mem_vec_2810 = vec_20;

												vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_2811);
												mem_vec_2811 = vec_23;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_26 = _mm512_set1_ps(scal_7);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_2812);
												mem_vec_2812 = vec_25;



												vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_2813);
												mem_vec_2813 = vec_27;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_8);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_2814);
												mem_vec_2814 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_2815);
												mem_vec_2815 = vec_30;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_2816);
												mem_vec_2816 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_2817);
												mem_vec_2817 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_2818);
												mem_vec_2818 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_2819);
												mem_vec_2819 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_2820);
												mem_vec_2820 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_2821);
												mem_vec_2821 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_2810);
												mem_vec_2810 = vec_40;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_2811);
												mem_vec_2811 = vec_43;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_46 = _mm512_set1_ps(scal_13);


												vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_2812);
												mem_vec_2812 = vec_45;



												vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_2813);
												mem_vec_2813 = vec_47;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_49 = _mm512_set1_ps(scal_14);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_2814);
												mem_vec_2814 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_2815);
												mem_vec_2815 = vec_50;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_52 = _mm512_set1_ps(scal_15);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_2816);
												mem_vec_2816 = vec_51;



												vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_2817);
												mem_vec_2817 = vec_53;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_55 = _mm512_set1_ps(scal_16);


												vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_2818);
												mem_vec_2818 = vec_54;



												vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_2819);
												mem_vec_2819 = vec_56;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_2820);
												mem_vec_2820 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_2821);
												mem_vec_2821 = vec_59;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2821);
								}
							}
						}
					}
				}
				for (y = y200 + 18, yp_0 = 0;
					y < y200 + 18 + 16;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 17) (34 / 2)
					for (x344 = x345, x344_p_0 = 0;
						x344 < x345 + 34;
						x344 += 2, x344_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f312, fp_2 = f312_p_1, fp_1 = f312_p_0, fp_0 = 0;
							f < f312 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w198, wp_0 = 0;
								w < w198 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 32
								// T (x, 2) (2 / 1)
								for (x = x344, xp_1 = x344_p_0, xp_0 = 0;
									x < x344 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2822 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2823 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c344, cp_1 = c344_p_0, cp_0 = 0;
												c < c344 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2822);
												mem_vec_2822 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2823);
												mem_vec_2823 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2824);
												mem_vec_2824 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2825);
												mem_vec_2825 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2826);
												mem_vec_2826 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2827);
												mem_vec_2827 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2828);
												mem_vec_2828 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2829);
												mem_vec_2829 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2830);
												mem_vec_2830 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2831);
												mem_vec_2831 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2832);
												mem_vec_2832 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2833);
												mem_vec_2833 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2834);
												mem_vec_2834 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2835);
												mem_vec_2835 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2836);
												mem_vec_2836 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2837);
												mem_vec_2837 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_2822);
												mem_vec_2822 = vec_26;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_2823);
												mem_vec_2823 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_2824);
												mem_vec_2824 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_2825);
												mem_vec_2825 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_2826);
												mem_vec_2826 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_2827);
												mem_vec_2827 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_2828);
												mem_vec_2828 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_2829);
												mem_vec_2829 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_2830);
												mem_vec_2830 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_2831);
												mem_vec_2831 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2832);
												mem_vec_2832 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2833);
												mem_vec_2833 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_2834);
												mem_vec_2834 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_2835);
												mem_vec_2835 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_2836);
												mem_vec_2836 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_2837);
												mem_vec_2837 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_16);
												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_2822);
												mem_vec_2822 = vec_52;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_2823);
												mem_vec_2823 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2824);
												mem_vec_2824 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2825);
												mem_vec_2825 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm512_set1_ps(scal_18);


												vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_2826);
												mem_vec_2826 = vec_60;



												vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_2827);
												mem_vec_2827 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_2828);
												mem_vec_2828 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_2829);
												mem_vec_2829 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_2830);
												mem_vec_2830 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_2831);
												mem_vec_2831 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_2832);
												mem_vec_2832 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_2833);
												mem_vec_2833 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_2834);
												mem_vec_2834 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_2835);
												mem_vec_2835 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_2836);
												mem_vec_2836 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_2837);
												mem_vec_2837 = vec_77;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2837);
								}
							}
						}
					}
				}
		}
	}
}


}