#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (2, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c192_p_0, cp_1, c192, f, fp_0, f246_p_0, f247_p_0, fp_1, f246_p_1, fp_2, f246, f247, h, hp_0, x, xp_0, x197_p_0, xp_1, x197, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y133 = 0;
IND_TYPE x198 = 0;
IND_TYPE h128 = 0;
IND_TYPE w = 0;
IND_TYPE c193 = 0;
IND_TYPE f248 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2846 ,mem_vec_2847 ,mem_vec_2848 ,mem_vec_2849 ,mem_vec_2850 ,mem_vec_2851 ,mem_vec_2852 ,mem_vec_2853 ,mem_vec_2854 ,mem_vec_2855 ,mem_vec_2856 ,mem_vec_2857 ,mem_vec_2858 ,mem_vec_2859 ,mem_vec_2860 ,mem_vec_2861 ,mem_vec_2862 ,mem_vec_2863 ,mem_vec_2864 ,mem_vec_2865 ,mem_vec_2866 ,mem_vec_2867 ,mem_vec_2868 ,mem_vec_2869 ,mem_vec_2870 ,mem_vec_2871 ,mem_vec_2872 ,mem_vec_2873 ,mem_vec_2874 ,mem_vec_2875 ,mem_vec_2876 ,mem_vec_2877 ,mem_vec_2878 ,mem_vec_2879 ,mem_vec_2880 ,mem_vec_2881 ,mem_vec_2882 ,mem_vec_2883 ,mem_vec_2884 ,mem_vec_2885 ,mem_vec_2886 ,mem_vec_2887 ,mem_vec_2888 ,mem_vec_2889 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f247 = f248, f247_p_0 = 0;
	f247 < f248 + 512;
	f247 += 256, f247_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (f, 4) (256 / 64)
	for (f246 = f247, f246_p_1 = f247_p_0, f246_p_0 = 0;
		f246 < f247 + 256;
		f246 += 64, f246_p_1 += 64, f246_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
		// T (x, 2) (34 / 17)
		for (x197 = x198, x197_p_0 = 0;
			x197 < x198 + 34;
			x197 += 17, x197_p_0 += 17){
				for (y = y133, yp_0 = 0;
					y < y133 + 20;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f246, fp_2 = f246_p_1, fp_1 = f246_p_0, fp_0 = 0;
						f < f246 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c192 = c193, c192_p_0 = 0;
							c192 < c193 + 256;
							c192 += 256, c192_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h128, hp_0 = 0;
								h < h128 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x197, xp_1 = x197_p_0, xp_0 = 0;
									x < x197 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2846 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2847 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_2849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_2850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_2853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_2854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_2857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_2858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_2861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
												c < c192 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2846);
												mem_vec_2846 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2847);
												mem_vec_2847 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2848);
												mem_vec_2848 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2849);
												mem_vec_2849 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2850);
												mem_vec_2850 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2851);
												mem_vec_2851 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2852);
												mem_vec_2852 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2853);
												mem_vec_2853 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2854);
												mem_vec_2854 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2855);
												mem_vec_2855 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2856);
												mem_vec_2856 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2857);
												mem_vec_2857 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2858);
												mem_vec_2858 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2859);
												mem_vec_2859 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2860);
												mem_vec_2860 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2861);
												mem_vec_2861 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_2846);
												mem_vec_2846 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_2847);
												mem_vec_2847 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_2848);
												mem_vec_2848 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_2849);
												mem_vec_2849 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_2850);
												mem_vec_2850 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2851);
												mem_vec_2851 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2852);
												mem_vec_2852 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2853);
												mem_vec_2853 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_2854);
												mem_vec_2854 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_2855);
												mem_vec_2855 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_2856);
												mem_vec_2856 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_2857);
												mem_vec_2857 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_2858);
												mem_vec_2858 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_2859);
												mem_vec_2859 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_2860);
												mem_vec_2860 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2861);
												mem_vec_2861 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_2846);
												mem_vec_2846 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_2847);
												mem_vec_2847 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_2848);
												mem_vec_2848 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_2849);
												mem_vec_2849 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_2850);
												mem_vec_2850 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_2851);
												mem_vec_2851 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_2852);
												mem_vec_2852 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2853);
												mem_vec_2853 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_2854);
												mem_vec_2854 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_2855);
												mem_vec_2855 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_2856);
												mem_vec_2856 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_2857);
												mem_vec_2857 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_2858);
												mem_vec_2858 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_2859);
												mem_vec_2859 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_2860);
												mem_vec_2860 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2861);
												mem_vec_2861 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2861);
								}
							}
						}
					}
				}
				for (y = y133 + 20, yp_0 = 0;
					y < y133 + 20 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f246, fp_2 = f246_p_1, fp_1 = f246_p_0, fp_0 = 0;
						f < f246 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c192 = c193, c192_p_0 = 0;
							c192 < c193 + 256;
							c192 += 256, c192_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h128, hp_0 = 0;
								h < h128 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x197, xp_1 = x197_p_0, xp_0 = 0;
									x < x197 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2862 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2863 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_2865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_2866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_2869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_2870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_2873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_2874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_2877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_2878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_2881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_2882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_2885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_2886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_2889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
												c < c192 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2862);
												mem_vec_2862 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2863);
												mem_vec_2863 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2864);
												mem_vec_2864 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2865);
												mem_vec_2865 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2866);
												mem_vec_2866 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2867);
												mem_vec_2867 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2868);
												mem_vec_2868 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2869);
												mem_vec_2869 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2870);
												mem_vec_2870 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2871);
												mem_vec_2871 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2872);
												mem_vec_2872 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2873);
												mem_vec_2873 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2874);
												mem_vec_2874 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2875);
												mem_vec_2875 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2876);
												mem_vec_2876 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2877);
												mem_vec_2877 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2878);
												mem_vec_2878 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2879);
												mem_vec_2879 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2880);
												mem_vec_2880 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2881);
												mem_vec_2881 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2882);
												mem_vec_2882 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2883);
												mem_vec_2883 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2884);
												mem_vec_2884 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2885);
												mem_vec_2885 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2886);
												mem_vec_2886 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2887);
												mem_vec_2887 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2888);
												mem_vec_2888 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2889);
												mem_vec_2889 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_2862);
												mem_vec_2862 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_2863);
												mem_vec_2863 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_2864);
												mem_vec_2864 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_2865);
												mem_vec_2865 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_2866);
												mem_vec_2866 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_2867);
												mem_vec_2867 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_2868);
												mem_vec_2868 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_2869);
												mem_vec_2869 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_2870);
												mem_vec_2870 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_2871);
												mem_vec_2871 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_2872);
												mem_vec_2872 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_2873);
												mem_vec_2873 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_2874);
												mem_vec_2874 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_2875);
												mem_vec_2875 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_2876);
												mem_vec_2876 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_2877);
												mem_vec_2877 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_2878);
												mem_vec_2878 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_2879);
												mem_vec_2879 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_2880);
												mem_vec_2880 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_2881);
												mem_vec_2881 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_2882);
												mem_vec_2882 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_2883);
												mem_vec_2883 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_2884);
												mem_vec_2884 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_2885);
												mem_vec_2885 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_2886);
												mem_vec_2886 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_2887);
												mem_vec_2887 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_2888);
												mem_vec_2888 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_2889);
												mem_vec_2889 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_2862);
												mem_vec_2862 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_2863);
												mem_vec_2863 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_2864);
												mem_vec_2864 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_2865);
												mem_vec_2865 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_2866);
												mem_vec_2866 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_2867);
												mem_vec_2867 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_2868);
												mem_vec_2868 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_2869);
												mem_vec_2869 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_2870);
												mem_vec_2870 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_2871);
												mem_vec_2871 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_2872);
												mem_vec_2872 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_2873);
												mem_vec_2873 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_2874);
												mem_vec_2874 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_2875);
												mem_vec_2875 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_2876);
												mem_vec_2876 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_2877);
												mem_vec_2877 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_2878);
												mem_vec_2878 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_2879);
												mem_vec_2879 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_2880);
												mem_vec_2880 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_2881);
												mem_vec_2881 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_2882);
												mem_vec_2882 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_2883);
												mem_vec_2883 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_2884);
												mem_vec_2884 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_2885);
												mem_vec_2885 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_2886);
												mem_vec_2886 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_2887);
												mem_vec_2887 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_2888);
												mem_vec_2888 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_2889);
												mem_vec_2889 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2873);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2875);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2876);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2877);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2878);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2879);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2880);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2881);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2882);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2883);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2884);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2885);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2886);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2889);
								}
							}
						}
					}
				}
		}
	}
}


}