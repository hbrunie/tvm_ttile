#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (2, c); T (4, y); T (8, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]; T (17, x)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, w, wp_0, x, xp_0, x120_p_0, x121_p_0, xp_1, x120_p_1, xp_2, x120, x121, y, yp_0, y72_p_0, yp_1, y72;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y73 = 0;
IND_TYPE x122 = 0;
IND_TYPE h = 0;
IND_TYPE w54 = 0;
IND_TYPE c91 = 0;
IND_TYPE f78 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 17) (136 / 8)
for (x121 = x122, x121_p_0 = 0;
	x121 < x122 + 136;
	x121 += 8, x121_p_0 += 8){
		for (y72 = y73, y72_p_0 = 0;
			y72 < y73 + 40;
			y72 += 40, y72_p_0 += 40){
			// y = 4 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (8 / 4)
			for (x120 = x121, x120_p_1 = x121_p_0, x120_p_0 = 0;
				x120 < x121 + 8;
				x120 += 4, x120_p_1 += 4, x120_p_0 += 4){
				// y = 4 * ph_y, x = 4, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f78, fp_0 = 0;
					f < f78 + 128;
					f += 16, fp_0 += 16){
					// y = 4 * ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
					// T (y, 4) (4 * ph_y / ph_y)
					for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
						y < y72 + 40;
						y += 10, yp_1 += 10, yp_0 += 10){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c90 = c91, c90_p_0 = 0;
							c90 < c91 + 64;
							c90 += 32, c90_p_0 += 32){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w54, wp_0 = 0;
								w < w54 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
								// T (x, 4) (4 / 1)
								for (x = x120, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
									x < x120 + 4;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_860 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_861 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_860);
												mem_vec_860 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_861);
												mem_vec_861 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_862);
												mem_vec_862 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_863);
												mem_vec_863 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_864);
												mem_vec_864 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_865);
												mem_vec_865 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_866);
												mem_vec_866 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_867);
												mem_vec_867 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_868);
												mem_vec_868 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_869);
												mem_vec_869 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_870);
												mem_vec_870 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_871);
												mem_vec_871 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_872);
												mem_vec_872 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_873);
												mem_vec_873 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_874);
												mem_vec_874 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_875);
												mem_vec_875 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_876);
												mem_vec_876 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_877);
												mem_vec_877 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_878);
												mem_vec_878 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_879);
												mem_vec_879 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_860);
												mem_vec_860 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_861);
												mem_vec_861 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_862);
												mem_vec_862 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_863);
												mem_vec_863 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_864);
												mem_vec_864 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_865);
												mem_vec_865 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_866);
												mem_vec_866 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_867);
												mem_vec_867 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_868);
												mem_vec_868 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_869);
												mem_vec_869 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_870);
												mem_vec_870 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_871);
												mem_vec_871 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_872);
												mem_vec_872 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_873);
												mem_vec_873 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_874);
												mem_vec_874 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_875);
												mem_vec_875 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_876);
												mem_vec_876 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_877);
												mem_vec_877 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_878);
												mem_vec_878 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_879);
												mem_vec_879 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_860);
												mem_vec_860 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_861);
												mem_vec_861 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_862);
												mem_vec_862 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_863);
												mem_vec_863 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_864);
												mem_vec_864 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_865);
												mem_vec_865 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_866);
												mem_vec_866 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_867);
												mem_vec_867 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_868);
												mem_vec_868 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_869);
												mem_vec_869 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_870);
												mem_vec_870 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_871);
												mem_vec_871 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_872);
												mem_vec_872 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_873);
												mem_vec_873 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_874);
												mem_vec_874 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_875);
												mem_vec_875 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_876);
												mem_vec_876 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_877);
												mem_vec_877 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_878);
												mem_vec_878 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_879);
												mem_vec_879 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_860);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_861);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_862);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_863);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_864);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_865);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_866);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_867);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_868);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_869);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_870);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_871);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_872);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_873);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_874);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_875);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_876);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_877);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_878);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_879);
								}
							}
						}
					}
				}
			}
		}
		for (y72 = y73 + 40, y72_p_0 = 0;
			y72 < y73 + 40 + 96;
			y72 += 48, y72_p_0 += 48){
			// y = 4 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (8 / 4)
			for (x120 = x121, x120_p_1 = x121_p_0, x120_p_0 = 0;
				x120 < x121 + 8;
				x120 += 4, x120_p_1 += 4, x120_p_0 += 4){
				// y = 4 * ph_y, x = 4, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f78, fp_0 = 0;
					f < f78 + 128;
					f += 16, fp_0 += 16){
					// y = 4 * ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
					// T (y, 4) (4 * ph_y / ph_y)
					for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
						y < y72 + 48;
						y += 12, yp_1 += 12, yp_0 += 12){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c90 = c91, c90_p_0 = 0;
							c90 < c91 + 64;
							c90 += 32, c90_p_0 += 32){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w54, wp_0 = 0;
								w < w54 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
								// T (x, 4) (4 / 1)
								for (x = x120, xp_2 = x120_p_1, xp_1 = x120_p_0, xp_0 = 0;
									x < x120 + 4;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_880 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_881 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
												c < c90 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_880);
												mem_vec_880 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_881);
												mem_vec_881 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_882);
												mem_vec_882 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_883);
												mem_vec_883 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_884);
												mem_vec_884 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_885);
												mem_vec_885 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_886);
												mem_vec_886 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_887);
												mem_vec_887 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_888);
												mem_vec_888 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_889);
												mem_vec_889 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_890);
												mem_vec_890 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_891);
												mem_vec_891 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_892);
												mem_vec_892 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_893);
												mem_vec_893 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_894);
												mem_vec_894 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_895);
												mem_vec_895 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_896);
												mem_vec_896 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_897);
												mem_vec_897 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_898);
												mem_vec_898 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_899);
												mem_vec_899 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_900);
												mem_vec_900 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_901);
												mem_vec_901 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_902);
												mem_vec_902 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_903);
												mem_vec_903 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_880);
												mem_vec_880 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_881);
												mem_vec_881 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_882);
												mem_vec_882 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_883);
												mem_vec_883 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_884);
												mem_vec_884 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_885);
												mem_vec_885 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_886);
												mem_vec_886 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_887);
												mem_vec_887 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_888);
												mem_vec_888 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_889);
												mem_vec_889 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_890);
												mem_vec_890 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_891);
												mem_vec_891 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_892);
												mem_vec_892 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_893);
												mem_vec_893 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_894);
												mem_vec_894 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_895);
												mem_vec_895 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_896);
												mem_vec_896 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_897);
												mem_vec_897 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_898);
												mem_vec_898 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_899);
												mem_vec_899 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_900);
												mem_vec_900 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_901);
												mem_vec_901 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_902);
												mem_vec_902 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_903);
												mem_vec_903 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_880);
												mem_vec_880 = vec_76;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_881);
												mem_vec_881 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_882);
												mem_vec_882 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_883);
												mem_vec_883 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_884);
												mem_vec_884 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_885);
												mem_vec_885 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_886);
												mem_vec_886 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_887);
												mem_vec_887 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_888);
												mem_vec_888 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_889);
												mem_vec_889 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_890);
												mem_vec_890 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_891);
												mem_vec_891 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_892);
												mem_vec_892 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_893);
												mem_vec_893 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_894);
												mem_vec_894 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_895);
												mem_vec_895 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_896);
												mem_vec_896 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_897);
												mem_vec_897 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_898);
												mem_vec_898 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_899);
												mem_vec_899 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_900);
												mem_vec_900 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_901);
												mem_vec_901 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_902);
												mem_vec_902 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_903);
												mem_vec_903 = vec_113;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_880);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_881);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_882);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_883);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_884);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_885);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_886);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_887);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_888);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_889);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_890);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_891);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_892);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_893);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_894);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_895);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_896);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_897);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_898);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_899);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_900);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_901);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_902);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_903);
								}
							}
						}
					}
				}
			}
		}
}


}