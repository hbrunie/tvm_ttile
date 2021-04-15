#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (1, f);
  T (16, c); T (8, f)]
*/
IND_TYPE c, cp_0, c1164_p_0, cp_1, c1164, f, fp_0, f1552_p_0, f1553_p_0, fp_1, f1552_p_1, fp_2, f1552, f1553, h, hp_0, x, xp_0, x1164_p_0, xp_1, x1164, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y776 = 0;
IND_TYPE x1165 = 0;
IND_TYPE h576 = 0;
IND_TYPE w = 0;
IND_TYPE c1165 = 0;
IND_TYPE f1554 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_15828 ,mem_vec_15829 ,mem_vec_15830 ,mem_vec_15831 ,mem_vec_15832 ,mem_vec_15833 ,mem_vec_15834 ,mem_vec_15835 ,mem_vec_15836 ,mem_vec_15837 ,mem_vec_15838 ,mem_vec_15839 ,mem_vec_15840 ,mem_vec_15841 ,mem_vec_15842 ,mem_vec_15843 ,mem_vec_15844 ,mem_vec_15845 ,mem_vec_15846 ,mem_vec_15847 ,mem_vec_15848 ,mem_vec_15849 ,mem_vec_15850 ,mem_vec_15851 ,mem_vec_15852 ,mem_vec_15853 ,mem_vec_15854 ,mem_vec_15855 ,mem_vec_15856 ,mem_vec_15857 ,mem_vec_15858 ,mem_vec_15859 ,mem_vec_15860 ,mem_vec_15861 ,mem_vec_15862 ,mem_vec_15863 ,mem_vec_15864 ,mem_vec_15865 ,mem_vec_15866 ,mem_vec_15867 ,mem_vec_15868 ,mem_vec_15869 ,mem_vec_15870 ,mem_vec_15871 ,mem_vec_15872 ,mem_vec_15873 ,mem_vec_15874 ,mem_vec_15875 ,mem_vec_15876 ,mem_vec_15877 ,mem_vec_15878 ,mem_vec_15879 ,mem_vec_15880 ,mem_vec_15881 ,mem_vec_15882 ,mem_vec_15883 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f1553 = f1554, f1553_p_0 = 0;
	f1553 < f1554 + 1024;
	f1553 += 128, f1553_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 16) (512 / 32)
	for (c1164 = c1165, c1164_p_0 = 0;
		c1164 < c1165 + 512;
		c1164 += 32, c1164_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 128
		// T (f, 1) (128 / 128)
		for (f1552 = f1553, f1552_p_1 = f1553_p_0, f1552_p_0 = 0;
			f1552 < f1553 + 128;
			f1552 += 128, f1552_p_1 += 128, f1552_p_0 += 128){
				for (y = y776, yp_0 = 0;
					y < y776 + 9;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 128
					// T (x, 1) (17 / 17)
					for (x1164 = x1165, x1164_p_0 = 0;
						x1164 < x1165 + 17;
						x1164 += 17, x1164_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 128
						// T (f, 2) (128 / 64)
						for (f = f1552, fp_2 = f1552_p_1, fp_1 = f1552_p_0, fp_0 = 0;
							f < f1552 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h576, hp_0 = 0;
								h < h576 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x1164, xp_1 = x1164_p_0, xp_0 = 0;
									x < x1164 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_15828 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15829 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_15830 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15831 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_15832 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15833 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_15834 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15835 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_15836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_15838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_15840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_15842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_15844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_15846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_15848 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15849 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_15850 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15851 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
												c < c1164 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15828);
												mem_vec_15828 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15829);
												mem_vec_15829 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15830);
												mem_vec_15830 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15831);
												mem_vec_15831 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_15832);
												mem_vec_15832 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_15833);
												mem_vec_15833 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_15834);
												mem_vec_15834 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_15835);
												mem_vec_15835 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_15836);
												mem_vec_15836 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_15837);
												mem_vec_15837 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_15838);
												mem_vec_15838 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_15839);
												mem_vec_15839 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_15840);
												mem_vec_15840 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_15841);
												mem_vec_15841 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_15842);
												mem_vec_15842 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_15843);
												mem_vec_15843 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_15844);
												mem_vec_15844 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_15845);
												mem_vec_15845 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_15846);
												mem_vec_15846 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_15847);
												mem_vec_15847 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_15848);
												mem_vec_15848 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_15849);
												mem_vec_15849 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_15850);
												mem_vec_15850 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_15851);
												mem_vec_15851 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_15828);
												mem_vec_15828 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_15829);
												mem_vec_15829 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_15830);
												mem_vec_15830 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_15831);
												mem_vec_15831 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_15832);
												mem_vec_15832 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_15833);
												mem_vec_15833 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_15834);
												mem_vec_15834 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_15835);
												mem_vec_15835 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_15836);
												mem_vec_15836 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_15837);
												mem_vec_15837 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_15838);
												mem_vec_15838 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_15839);
												mem_vec_15839 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_15840);
												mem_vec_15840 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_15841);
												mem_vec_15841 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_15842);
												mem_vec_15842 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_15843);
												mem_vec_15843 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_15844);
												mem_vec_15844 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_15845);
												mem_vec_15845 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_15846);
												mem_vec_15846 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_15847);
												mem_vec_15847 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_15848);
												mem_vec_15848 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_15849);
												mem_vec_15849 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_15850);
												mem_vec_15850 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_15851);
												mem_vec_15851 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_15828);
												mem_vec_15828 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_15829);
												mem_vec_15829 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_15830);
												mem_vec_15830 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_15831);
												mem_vec_15831 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_15832);
												mem_vec_15832 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_15833);
												mem_vec_15833 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_15834);
												mem_vec_15834 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_15835);
												mem_vec_15835 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_15836);
												mem_vec_15836 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_15837);
												mem_vec_15837 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_15838);
												mem_vec_15838 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_15839);
												mem_vec_15839 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_15840);
												mem_vec_15840 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_15841);
												mem_vec_15841 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_15842);
												mem_vec_15842 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_15843);
												mem_vec_15843 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_15844);
												mem_vec_15844 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_15845);
												mem_vec_15845 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_15846);
												mem_vec_15846 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_15847);
												mem_vec_15847 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_15848);
												mem_vec_15848 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_15849);
												mem_vec_15849 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_15850);
												mem_vec_15850 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_15851);
												mem_vec_15851 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15831);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_15833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_15835);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15836);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15837);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15838);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15839);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15840);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_15841);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15842);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_15843);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15844);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15845);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15846);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15847);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15848);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_15849);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15850);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_15851);
								}
							}
						}
					}
				}
				for (y = y776 + 9, yp_0 = 0;
					y < y776 + 9 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 128
					// T (x, 1) (17 / 17)
					for (x1164 = x1165, x1164_p_0 = 0;
						x1164 < x1165 + 17;
						x1164 += 17, x1164_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 128
						// T (f, 2) (128 / 64)
						for (f = f1552, fp_2 = f1552_p_1, fp_1 = f1552_p_0, fp_0 = 0;
							f < f1552 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (h, 3) (3 / 1)
							for (h = h576, hp_0 = 0;
								h < h576 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x1164, xp_1 = x1164_p_0, xp_0 = 0;
									x < x1164 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_15852 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_15853 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_15854 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15855 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_15856 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_15857 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_15858 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_15859 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_15860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_15861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_15862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_15863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_15864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_15865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_15866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_15867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_15868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_15869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_15870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_15871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_15872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_15873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_15874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_15875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_15876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_15877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_15878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_15879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_15880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_15881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_15882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_15883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
												c < c1164 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15852);
												mem_vec_15852 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15853);
												mem_vec_15853 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15854);
												mem_vec_15854 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15855);
												mem_vec_15855 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_15856);
												mem_vec_15856 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_15857);
												mem_vec_15857 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_15858);
												mem_vec_15858 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_15859);
												mem_vec_15859 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_15860);
												mem_vec_15860 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_15861);
												mem_vec_15861 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_15862);
												mem_vec_15862 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_15863);
												mem_vec_15863 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_15864);
												mem_vec_15864 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_15865);
												mem_vec_15865 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_15866);
												mem_vec_15866 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_15867);
												mem_vec_15867 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_15868);
												mem_vec_15868 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_15869);
												mem_vec_15869 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_15870);
												mem_vec_15870 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_15871);
												mem_vec_15871 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_15872);
												mem_vec_15872 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_15873);
												mem_vec_15873 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_15874);
												mem_vec_15874 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_15875);
												mem_vec_15875 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_15876);
												mem_vec_15876 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_15877);
												mem_vec_15877 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_15878);
												mem_vec_15878 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_15879);
												mem_vec_15879 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_15880);
												mem_vec_15880 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_15881);
												mem_vec_15881 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_15882);
												mem_vec_15882 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_15883);
												mem_vec_15883 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_15852);
												mem_vec_15852 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_15853);
												mem_vec_15853 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_15854);
												mem_vec_15854 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_15855);
												mem_vec_15855 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_15856);
												mem_vec_15856 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_15857);
												mem_vec_15857 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_15858);
												mem_vec_15858 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_15859);
												mem_vec_15859 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_15860);
												mem_vec_15860 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_15861);
												mem_vec_15861 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_15862);
												mem_vec_15862 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_15863);
												mem_vec_15863 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_15864);
												mem_vec_15864 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_15865);
												mem_vec_15865 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_15866);
												mem_vec_15866 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_15867);
												mem_vec_15867 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_15868);
												mem_vec_15868 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_15869);
												mem_vec_15869 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_15870);
												mem_vec_15870 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_15871);
												mem_vec_15871 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_15872);
												mem_vec_15872 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_15873);
												mem_vec_15873 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_15874);
												mem_vec_15874 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_15875);
												mem_vec_15875 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_15876);
												mem_vec_15876 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_15877);
												mem_vec_15877 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_15878);
												mem_vec_15878 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_15879);
												mem_vec_15879 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_15880);
												mem_vec_15880 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_15881);
												mem_vec_15881 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_15882);
												mem_vec_15882 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_15883);
												mem_vec_15883 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_15852);
												mem_vec_15852 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_15853);
												mem_vec_15853 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_15854);
												mem_vec_15854 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_15855);
												mem_vec_15855 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_15856);
												mem_vec_15856 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_15857);
												mem_vec_15857 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_15858);
												mem_vec_15858 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_15859);
												mem_vec_15859 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_15860);
												mem_vec_15860 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_15861);
												mem_vec_15861 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_15862);
												mem_vec_15862 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_15863);
												mem_vec_15863 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_15864);
												mem_vec_15864 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_15865);
												mem_vec_15865 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_15866);
												mem_vec_15866 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_15867);
												mem_vec_15867 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_15868);
												mem_vec_15868 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_15869);
												mem_vec_15869 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_15870);
												mem_vec_15870 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_15871);
												mem_vec_15871 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_15872);
												mem_vec_15872 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_15873);
												mem_vec_15873 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_15874);
												mem_vec_15874 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_15875);
												mem_vec_15875 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_15876);
												mem_vec_15876 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_15877);
												mem_vec_15877 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_15878);
												mem_vec_15878 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_15879);
												mem_vec_15879 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_15880);
												mem_vec_15880 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_15881);
												mem_vec_15881 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_15882);
												mem_vec_15882 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_15883);
												mem_vec_15883 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15852);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15853);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15854);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15855);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15856);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_15857);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15858);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_15859);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15860);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15861);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15862);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15863);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15864);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_15865);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15866);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_15867);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15868);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15869);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15870);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15871);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15872);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_15873);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15874);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_15875);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15876);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_15877);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15878);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15879);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15880);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_15881);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15882);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_15883);
								}
							}
						}
					}
				}
		}
	}
}


}