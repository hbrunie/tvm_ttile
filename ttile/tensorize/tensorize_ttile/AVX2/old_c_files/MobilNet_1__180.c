#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (8, c); Hoist_vars [c]; T (3, h);
  T (2, x); T (8, y); T (4, c); T (2, y); T (56, x)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, h, hp_0, x, xp_0, x465_p_0, xp_1, x465, y, yp_0, y447_p_0, yp_1, y447;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y448 = 0;
IND_TYPE x466 = 0;
IND_TYPE h229 = 0;
IND_TYPE w = 0;
IND_TYPE c457 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2852 ,mem_vec_2853 ,mem_vec_2854 ,mem_vec_2855 ,mem_vec_2856 ,mem_vec_2857 ,mem_vec_2858 ,mem_vec_2859 ,mem_vec_2860 ,mem_vec_2861 ,mem_vec_2862 ,mem_vec_2863 ,mem_vec_2864 ,mem_vec_2865 ,mem_vec_2866 ,mem_vec_2867 ,mem_vec_2868 ,mem_vec_2869 ,mem_vec_2870 ,mem_vec_2871 ,mem_vec_2872 ,mem_vec_2873 ,mem_vec_2874 ,mem_vec_2875 ,mem_vec_2876 ,mem_vec_2877 ,mem_vec_2878 ,mem_vec_2879 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
for (x465 = x466, x465_p_0 = 0;
	x465 < x466 + 112;
	x465 += 2, x465_p_0 += 2){
	// y = 112, x = 2, h = 3, w = 3, c = 32, f = 32
	// T (y, 2) (112 / 56)
	for (y447 = y448, y447_p_0 = 0;
		y447 < y448 + 112;
		y447 += 56, y447_p_0 += 56){
		// y = 56, x = 2, h = 3, w = 3, c = 32, f = 32
		// T (c, 4) (32 / 8)
		for (c456 = c457, c456_p_0 = 0;
			c456 < c457 + 32;
			c456 += 8, c456_p_0 += 8){
			// y = 56, x = 2, h = 3, w = 3, c = 8, f = 32
			// T (y, 8) (56 / 7)
			for (y = y447, yp_1 = y447_p_0, yp_0 = 0;
				y < y447 + 56;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = 7, x = 2, h = 3, w = 3, c = 8, f = 32
				// T (x, 2) (2 / 1)
				for (x = x465, xp_1 = x465_p_0, xp_0 = 0;
					x < x465 + 2;
					x += 1, xp_1 += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h229, hp_0 = 0;
						h < h229 + 3;
						h += 1, hp_0 += 1){
								mem_vec_2852 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2853 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_2854 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2855 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_2856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_2858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_2860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_2862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_2864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_2866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								mem_vec_2868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
								mem_vec_2870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
								mem_vec_2872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
								mem_vec_2874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
								mem_vec_2876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
								mem_vec_2878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
								// y = 7, x = 1, h = 1, w = 3, c = 8, f = 32
								// T (c, 8) (8 / 1)
								for (c = c456, cp_1 = c456_p_0, cp_0 = 0;
									c < c456 + 8;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2852);
									mem_vec_2852 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2853);
									mem_vec_2853 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2854);
									mem_vec_2854 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2855);
									mem_vec_2855 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2856);
									mem_vec_2856 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2857);
									mem_vec_2857 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2858);
									mem_vec_2858 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2859);
									mem_vec_2859 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2860);
									mem_vec_2860 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2861);
									mem_vec_2861 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2862);
									mem_vec_2862 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2863);
									mem_vec_2863 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2864);
									mem_vec_2864 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2865);
									mem_vec_2865 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2866);
									mem_vec_2866 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2867);
									mem_vec_2867 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm256_set1_ps(scal_4);


									vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2868);
									mem_vec_2868 = vec_24;



									vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2869);
									mem_vec_2869 = vec_26;



									vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2870);
									mem_vec_2870 = vec_27;



									vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2871);
									mem_vec_2871 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm256_set1_ps(scal_5);


									vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2872);
									mem_vec_2872 = vec_29;



									vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2873);
									mem_vec_2873 = vec_31;



									vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_2874);
									mem_vec_2874 = vec_32;



									vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_2875);
									mem_vec_2875 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm256_set1_ps(scal_6);


									vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_2876);
									mem_vec_2876 = vec_34;



									vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_2877);
									mem_vec_2877 = vec_36;



									vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_2878);
									mem_vec_2878 = vec_37;



									vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_2879);
									mem_vec_2879 = vec_38;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_40 = _mm256_set1_ps(scal_7);
									vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_2852);
									mem_vec_2852 = vec_39;

									vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

									vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_2853);
									mem_vec_2853 = vec_42;

									vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_2854);
									mem_vec_2854 = vec_44;

									vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

									vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_2855);
									mem_vec_2855 = vec_46;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_49 = _mm256_set1_ps(scal_8);


									vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_2856);
									mem_vec_2856 = vec_48;



									vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_2857);
									mem_vec_2857 = vec_50;



									vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_2858);
									mem_vec_2858 = vec_51;



									vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_2859);
									mem_vec_2859 = vec_52;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_54 = _mm256_set1_ps(scal_9);


									vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_2860);
									mem_vec_2860 = vec_53;



									vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_2861);
									mem_vec_2861 = vec_55;



									vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_2862);
									mem_vec_2862 = vec_56;



									vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_2863);
									mem_vec_2863 = vec_57;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_59 = _mm256_set1_ps(scal_10);


									vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_2864);
									mem_vec_2864 = vec_58;



									vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_2865);
									mem_vec_2865 = vec_60;



									vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_2866);
									mem_vec_2866 = vec_61;



									vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_2867);
									mem_vec_2867 = vec_62;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
									vec_64 = _mm256_set1_ps(scal_11);


									vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_2868);
									mem_vec_2868 = vec_63;



									vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_2869);
									mem_vec_2869 = vec_65;



									vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_2870);
									mem_vec_2870 = vec_66;



									vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_2871);
									mem_vec_2871 = vec_67;
									scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
									vec_69 = _mm256_set1_ps(scal_12);


									vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_2872);
									mem_vec_2872 = vec_68;



									vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_2873);
									mem_vec_2873 = vec_70;



									vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_2874);
									mem_vec_2874 = vec_71;



									vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_2875);
									mem_vec_2875 = vec_72;
									scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
									vec_74 = _mm256_set1_ps(scal_13);


									vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_2876);
									mem_vec_2876 = vec_73;



									vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_2877);
									mem_vec_2877 = vec_75;



									vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_2878);
									mem_vec_2878 = vec_76;



									vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_2879);
									mem_vec_2879 = vec_77;
									scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_79 = _mm256_set1_ps(scal_14);
									vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_2852);
									mem_vec_2852 = vec_78;

									vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

									vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_2853);
									mem_vec_2853 = vec_81;

									vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_2854);
									mem_vec_2854 = vec_83;

									vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

									vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_2855);
									mem_vec_2855 = vec_85;
									scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_88 = _mm256_set1_ps(scal_15);


									vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_2856);
									mem_vec_2856 = vec_87;



									vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_2857);
									mem_vec_2857 = vec_89;



									vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_2858);
									mem_vec_2858 = vec_90;



									vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_2859);
									mem_vec_2859 = vec_91;
									scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_93 = _mm256_set1_ps(scal_16);


									vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_2860);
									mem_vec_2860 = vec_92;



									vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_2861);
									mem_vec_2861 = vec_94;



									vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_2862);
									mem_vec_2862 = vec_95;



									vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_2863);
									mem_vec_2863 = vec_96;
									scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_98 = _mm256_set1_ps(scal_17);


									vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_2864);
									mem_vec_2864 = vec_97;



									vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_2865);
									mem_vec_2865 = vec_99;



									vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_2866);
									mem_vec_2866 = vec_100;



									vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_2867);
									mem_vec_2867 = vec_101;
									scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
									vec_103 = _mm256_set1_ps(scal_18);


									vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_2868);
									mem_vec_2868 = vec_102;



									vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_2869);
									mem_vec_2869 = vec_104;



									vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_2870);
									mem_vec_2870 = vec_105;



									vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_2871);
									mem_vec_2871 = vec_106;
									scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
									vec_108 = _mm256_set1_ps(scal_19);


									vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_2872);
									mem_vec_2872 = vec_107;



									vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_2873);
									mem_vec_2873 = vec_109;



									vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_2874);
									mem_vec_2874 = vec_110;



									vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_2875);
									mem_vec_2875 = vec_111;
									scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
									vec_113 = _mm256_set1_ps(scal_20);


									vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_2876);
									mem_vec_2876 = vec_112;



									vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_2877);
									mem_vec_2877 = vec_114;



									vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_2878);
									mem_vec_2878 = vec_115;



									vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_2879);
									mem_vec_2879 = vec_116;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2852);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2853);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2854);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2855);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2856);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2857);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2858);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2859);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2860);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2861);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2862);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2863);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2864);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2865);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2866);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2867);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2868);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2869);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2870);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2871);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2872);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2873);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2874);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_2875);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2876);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2877);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2878);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_2879);
					}
				}
			}
		}
	}
}


}