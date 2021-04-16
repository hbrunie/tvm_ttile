#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (64, f);
  T (8, c); T (1, y); T (1, c)]
*/
IND_TYPE c, cp_0, c203_p_0, c204_p_0, c205_p_0, cp_1, c203_p_1, c204_p_1, cp_2, c203_p_2, cp_3, c203, c204, c205, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y135_p_0, yp_1, y135;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y136 = 0;
IND_TYPE x134 = 0;
IND_TYPE h = 0;
IND_TYPE w112 = 0;
IND_TYPE c206 = 0;
IND_TYPE f266 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2694 ,mem_vec_2695 ,mem_vec_2696 ,mem_vec_2697 ,mem_vec_2698 ,mem_vec_2699 ,mem_vec_2700 ,mem_vec_2701 ,mem_vec_2702 ,mem_vec_2703 ,mem_vec_2704 ,mem_vec_2705 ,mem_vec_2706 ,mem_vec_2707 ,mem_vec_2708 ,mem_vec_2709 ,mem_vec_2710 ,mem_vec_2711 ,mem_vec_2712 ,mem_vec_2713 ,mem_vec_2714 ,mem_vec_2715 ,mem_vec_2716 ,mem_vec_2717 ,mem_vec_2718 ,mem_vec_2719 ,mem_vec_2720 ,mem_vec_2721 ,mem_vec_2722 ,mem_vec_2723 ,mem_vec_2724 ,mem_vec_2725 ,mem_vec_2726 ,mem_vec_2727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c205 = c206, c205_p_0 = 0;
	c205 < c206 + 512;
	c205 += 512, c205_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (y, 1) (17 / 17)
	for (y135 = y136, y135_p_0 = 0;
		y135 < y136 + 17;
		y135 += 17, y135_p_0 += 17){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (c, 8) (512 / 64)
		for (c204 = c205, c204_p_1 = c205_p_0, c204_p_0 = 0;
			c204 < c205 + 512;
			c204 += 64, c204_p_1 += 64, c204_p_0 += 64){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 1024
			// T (f, 64) (1024 / 16)
			for (f = f266, fp_0 = 0;
				f < f266 + 1024;
				f += 16, fp_0 += 16){
					for (y = y135, yp_1 = y135_p_0, yp_0 = 0;
						y < y135 + 8;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c203 = c204, c203_p_2 = c204_p_1, c203_p_1 = c204_p_0, c203_p_0 = 0;
							c203 < c204 + 64;
							c203 += 32, c203_p_2 += 32, c203_p_1 += 32, c203_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x134, xp_0 = 0;
								x < x134 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w112, wp_0 = 0;
									w < w112 + 3;
									w += 1, wp_0 += 1){
											mem_vec_2694 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2695 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2696 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2697 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2698 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2699 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2700 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2701 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2702 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2703 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2704 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2705 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2706 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2707 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2708 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2709 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c203, cp_3 = c203_p_2, cp_2 = c203_p_1, cp_1 = c203_p_0, cp_0 = 0;
												c < c203 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2694);
												mem_vec_2694 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2695);
												mem_vec_2695 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2696);
												mem_vec_2696 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2697);
												mem_vec_2697 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2698);
												mem_vec_2698 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2699);
												mem_vec_2699 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2700);
												mem_vec_2700 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2701);
												mem_vec_2701 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2702);
												mem_vec_2702 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2703);
												mem_vec_2703 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2704);
												mem_vec_2704 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2705);
												mem_vec_2705 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2706);
												mem_vec_2706 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2707);
												mem_vec_2707 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2708);
												mem_vec_2708 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2709);
												mem_vec_2709 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_2694);
												mem_vec_2694 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_2695);
												mem_vec_2695 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_2696);
												mem_vec_2696 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_2697);
												mem_vec_2697 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_2698);
												mem_vec_2698 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_2699);
												mem_vec_2699 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_2700);
												mem_vec_2700 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_2701);
												mem_vec_2701 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_2702);
												mem_vec_2702 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_2703);
												mem_vec_2703 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2704);
												mem_vec_2704 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2705);
												mem_vec_2705 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_2706);
												mem_vec_2706 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_2707);
												mem_vec_2707 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_2708);
												mem_vec_2708 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_2709);
												mem_vec_2709 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_2694);
												mem_vec_2694 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_2695);
												mem_vec_2695 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2696);
												mem_vec_2696 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2697);
												mem_vec_2697 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_2698);
												mem_vec_2698 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_2699);
												mem_vec_2699 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_2700);
												mem_vec_2700 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_2701);
												mem_vec_2701 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_2702);
												mem_vec_2702 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_2703);
												mem_vec_2703 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_2704);
												mem_vec_2704 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_2705);
												mem_vec_2705 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_2706);
												mem_vec_2706 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_2707);
												mem_vec_2707 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_2708);
												mem_vec_2708 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_2709);
												mem_vec_2709 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2694);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2695);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2696);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2697);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2698);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2699);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2700);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2701);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2702);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2703);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2704);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2705);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2706);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2707);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2708);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2709);
								}
							}
						}
					}
					for (y = y135 + 8, yp_1 = y135_p_0, yp_0 = 0;
						y < y135 + 8 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c203 = c204, c203_p_2 = c204_p_1, c203_p_1 = c204_p_0, c203_p_0 = 0;
							c203 < c204 + 64;
							c203 += 32, c203_p_2 += 32, c203_p_1 += 32, c203_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 16
							// T (x, 17) (17 / 1)
							for (x = x134, xp_0 = 0;
								x < x134 + 17;
								x += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w112, wp_0 = 0;
									w < w112 + 3;
									w += 1, wp_0 += 1){
											mem_vec_2710 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2711 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2712 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2713 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2714 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2715 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2716 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2717 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_2726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c203, cp_3 = c203_p_2, cp_2 = c203_p_1, cp_1 = c203_p_0, cp_0 = 0;
												c < c203 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2710);
												mem_vec_2710 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2711);
												mem_vec_2711 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2712);
												mem_vec_2712 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2713);
												mem_vec_2713 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2714);
												mem_vec_2714 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2715);
												mem_vec_2715 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2716);
												mem_vec_2716 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2717);
												mem_vec_2717 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2718);
												mem_vec_2718 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2719);
												mem_vec_2719 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2720);
												mem_vec_2720 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2721);
												mem_vec_2721 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2722);
												mem_vec_2722 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2723);
												mem_vec_2723 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2724);
												mem_vec_2724 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2725);
												mem_vec_2725 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_2726);
												mem_vec_2726 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_2727);
												mem_vec_2727 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_2710);
												mem_vec_2710 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_2711);
												mem_vec_2711 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_2712);
												mem_vec_2712 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_2713);
												mem_vec_2713 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_2714);
												mem_vec_2714 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_2715);
												mem_vec_2715 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_2716);
												mem_vec_2716 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_2717);
												mem_vec_2717 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_2718);
												mem_vec_2718 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_2719);
												mem_vec_2719 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_2720);
												mem_vec_2720 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_2721);
												mem_vec_2721 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_2722);
												mem_vec_2722 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_2723);
												mem_vec_2723 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_2724);
												mem_vec_2724 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_2725);
												mem_vec_2725 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_2726);
												mem_vec_2726 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_2727);
												mem_vec_2727 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_2710);
												mem_vec_2710 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_2711);
												mem_vec_2711 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_2712);
												mem_vec_2712 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_2713);
												mem_vec_2713 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_2714);
												mem_vec_2714 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_2715);
												mem_vec_2715 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_2716);
												mem_vec_2716 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_2717);
												mem_vec_2717 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_2718);
												mem_vec_2718 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_2719);
												mem_vec_2719 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_2720);
												mem_vec_2720 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_2721);
												mem_vec_2721 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_2722);
												mem_vec_2722 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_2723);
												mem_vec_2723 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_2724);
												mem_vec_2724 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_2725);
												mem_vec_2725 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_2726);
												mem_vec_2726 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_2727);
												mem_vec_2727 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2710);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2711);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2712);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2713);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2714);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2715);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2716);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2717);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2718);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2719);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2720);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2721);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2722);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2723);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2724);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2725);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2726);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_2727);
								}
							}
						}
					}
			}
		}
	}
}


}