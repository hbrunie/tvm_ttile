#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (256, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (4, c);
  T (8, f); T (1, c)]
*/
IND_TYPE c, cp_0, c748_p_0, c749_p_0, c750_p_0, cp_1, c748_p_1, c749_p_1, cp_2, c748_p_2, cp_3, c748, c749, c750, f, fp_0, f540_p_0, fp_1, f540, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y360 = 0;
IND_TYPE x360 = 0;
IND_TYPE h286 = 0;
IND_TYPE w = 0;
IND_TYPE c751 = 0;
IND_TYPE f541 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5824 ,mem_vec_5825 ,mem_vec_5826 ,mem_vec_5827 ,mem_vec_5828 ,mem_vec_5829 ,mem_vec_5830 ,mem_vec_5831 ,mem_vec_5832 ,mem_vec_5833 ,mem_vec_5834 ,mem_vec_5835 ,mem_vec_5836 ,mem_vec_5837 ,mem_vec_5838 ,mem_vec_5839 ,mem_vec_5840 ,mem_vec_5841 ,mem_vec_5842 ,mem_vec_5843 ,mem_vec_5844 ,mem_vec_5845 ,mem_vec_5846 ,mem_vec_5847 ,mem_vec_5848 ,mem_vec_5849 ,mem_vec_5850 ,mem_vec_5851 ,mem_vec_5852 ,mem_vec_5853 ,mem_vec_5854 ,mem_vec_5855 ,mem_vec_5856 ,mem_vec_5857 ,mem_vec_5858 ,mem_vec_5859 ,mem_vec_5860 ,mem_vec_5861 ,mem_vec_5862 ,mem_vec_5863 ,mem_vec_5864 ,mem_vec_5865 ,mem_vec_5866 ,mem_vec_5867 ,mem_vec_5868 ,mem_vec_5869 ,mem_vec_5870 ,mem_vec_5871 ,mem_vec_5872 ,mem_vec_5873 ,mem_vec_5874 ,mem_vec_5875 ,mem_vec_5876 ,mem_vec_5877 ,mem_vec_5878 ,mem_vec_5879 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c750 = c751, c750_p_0 = 0;
	c750 < c751 + 1024;
	c750 += 1024, c750_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (f, 8) (1024 / 128)
	for (f540 = f541, f540_p_0 = 0;
		f540 < f541 + 1024;
		f540 += 128, f540_p_0 += 128){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 128
		// T (c, 4) (1024 / 256)
		for (c749 = c750, c749_p_1 = c750_p_0, c749_p_0 = 0;
			c749 < c750 + 1024;
			c749 += 256, c749_p_1 += 256, c749_p_0 += 256){
				for (y = y360, yp_0 = 0;
					y < y360 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
						f < f540 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (c, 256) (256 / 1)
						for (c748 = c749, c748_p_2 = c749_p_1, c748_p_1 = c749_p_0, c748_p_0 = 0;
							c748 < c749 + 256;
							c748 += 1, c748_p_2 += 1, c748_p_1 += 1, c748_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h286, hp_0 = 0;
								h < h286 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x360, xp_0 = 0;
									x < x360 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5824 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5825 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5826 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5827 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5828 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5829 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_5830 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5831 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_5832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_5838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_5840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_5846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c748, cp_3 = c748_p_2, cp_2 = c748_p_1, cp_1 = c748_p_0, cp_0 = 0;
												c < c748 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5824);
												mem_vec_5824 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5825);
												mem_vec_5825 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5826);
												mem_vec_5826 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5827);
												mem_vec_5827 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_5828);
												mem_vec_5828 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_5829);
												mem_vec_5829 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_5830);
												mem_vec_5830 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_5831);
												mem_vec_5831 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5832);
												mem_vec_5832 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5833);
												mem_vec_5833 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_5834);
												mem_vec_5834 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_5835);
												mem_vec_5835 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_5836);
												mem_vec_5836 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_5837);
												mem_vec_5837 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_5838);
												mem_vec_5838 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_5839);
												mem_vec_5839 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5840);
												mem_vec_5840 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5841);
												mem_vec_5841 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_5842);
												mem_vec_5842 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_5843);
												mem_vec_5843 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_5844);
												mem_vec_5844 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_5845);
												mem_vec_5845 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_5846);
												mem_vec_5846 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_5847);
												mem_vec_5847 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_5824);
												mem_vec_5824 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_5825);
												mem_vec_5825 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_5826);
												mem_vec_5826 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_5827);
												mem_vec_5827 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_5828);
												mem_vec_5828 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_5829);
												mem_vec_5829 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_5830);
												mem_vec_5830 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_5831);
												mem_vec_5831 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_5832);
												mem_vec_5832 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_5833);
												mem_vec_5833 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_5834);
												mem_vec_5834 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_5835);
												mem_vec_5835 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_5836);
												mem_vec_5836 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_5837);
												mem_vec_5837 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_5838);
												mem_vec_5838 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_5839);
												mem_vec_5839 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_5840);
												mem_vec_5840 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_5841);
												mem_vec_5841 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_5842);
												mem_vec_5842 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_5843);
												mem_vec_5843 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_5844);
												mem_vec_5844 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_5845);
												mem_vec_5845 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_5846);
												mem_vec_5846 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_5847);
												mem_vec_5847 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_5824);
												mem_vec_5824 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_5825);
												mem_vec_5825 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_5826);
												mem_vec_5826 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_5827);
												mem_vec_5827 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_5828);
												mem_vec_5828 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_5829);
												mem_vec_5829 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_5830);
												mem_vec_5830 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_5831);
												mem_vec_5831 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5832);
												mem_vec_5832 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5833);
												mem_vec_5833 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5834);
												mem_vec_5834 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_5835);
												mem_vec_5835 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_5836);
												mem_vec_5836 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_5837);
												mem_vec_5837 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_5838);
												mem_vec_5838 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_5839);
												mem_vec_5839 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_5840);
												mem_vec_5840 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_5841);
												mem_vec_5841 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_5842);
												mem_vec_5842 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_5843);
												mem_vec_5843 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_5844);
												mem_vec_5844 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_5845);
												mem_vec_5845 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_5846);
												mem_vec_5846 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_5847);
												mem_vec_5847 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_5829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_5831);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5832);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5833);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5834);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5835);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5836);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_5837);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5838);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_5839);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5840);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5841);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5842);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5843);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5844);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_5845);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5846);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_5847);
								}
							}
						}
					}
				}
				for (y = y360 + 3, yp_0 = 0;
					y < y360 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
						f < f540 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
						// T (c, 256) (256 / 1)
						for (c748 = c749, c748_p_2 = c749_p_1, c748_p_1 = c749_p_0, c748_p_0 = 0;
							c748 < c749 + 256;
							c748 += 1, c748_p_2 += 1, c748_p_1 += 1, c748_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h286, hp_0 = 0;
								h < h286 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x360, xp_0 = 0;
									x < x360 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5848 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5849 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5850 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5851 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5852 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5853 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_5854 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5855 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_5856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_5862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_5864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_5870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_5872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_5877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_5878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_5879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c748, cp_3 = c748_p_2, cp_2 = c748_p_1, cp_1 = c748_p_0, cp_0 = 0;
												c < c748 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5848);
												mem_vec_5848 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5849);
												mem_vec_5849 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5850);
												mem_vec_5850 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5851);
												mem_vec_5851 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_5852);
												mem_vec_5852 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_5853);
												mem_vec_5853 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_5854);
												mem_vec_5854 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_5855);
												mem_vec_5855 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_5856);
												mem_vec_5856 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_5857);
												mem_vec_5857 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_5858);
												mem_vec_5858 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_5859);
												mem_vec_5859 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_5860);
												mem_vec_5860 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_5861);
												mem_vec_5861 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_5862);
												mem_vec_5862 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_5863);
												mem_vec_5863 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_5864);
												mem_vec_5864 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_5865);
												mem_vec_5865 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_5866);
												mem_vec_5866 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_5867);
												mem_vec_5867 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_5868);
												mem_vec_5868 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_5869);
												mem_vec_5869 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_5870);
												mem_vec_5870 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_5871);
												mem_vec_5871 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_5872);
												mem_vec_5872 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_5873);
												mem_vec_5873 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_5874);
												mem_vec_5874 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_5875);
												mem_vec_5875 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_5876);
												mem_vec_5876 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_5877);
												mem_vec_5877 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_5878);
												mem_vec_5878 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_5879);
												mem_vec_5879 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_5848);
												mem_vec_5848 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_5849);
												mem_vec_5849 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_5850);
												mem_vec_5850 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_5851);
												mem_vec_5851 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_5852);
												mem_vec_5852 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_5853);
												mem_vec_5853 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_5854);
												mem_vec_5854 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_5855);
												mem_vec_5855 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_5856);
												mem_vec_5856 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_5857);
												mem_vec_5857 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_5858);
												mem_vec_5858 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_5859);
												mem_vec_5859 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_5860);
												mem_vec_5860 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_5861);
												mem_vec_5861 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_5862);
												mem_vec_5862 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_5863);
												mem_vec_5863 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_5864);
												mem_vec_5864 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_5865);
												mem_vec_5865 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_5866);
												mem_vec_5866 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_5867);
												mem_vec_5867 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_5868);
												mem_vec_5868 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_5869);
												mem_vec_5869 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_5870);
												mem_vec_5870 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_5871);
												mem_vec_5871 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_5872);
												mem_vec_5872 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_5873);
												mem_vec_5873 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_5874);
												mem_vec_5874 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_5875);
												mem_vec_5875 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_5876);
												mem_vec_5876 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_5877);
												mem_vec_5877 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_5878);
												mem_vec_5878 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_5879);
												mem_vec_5879 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_5848);
												mem_vec_5848 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_5849);
												mem_vec_5849 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_5850);
												mem_vec_5850 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_5851);
												mem_vec_5851 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_5852);
												mem_vec_5852 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_5853);
												mem_vec_5853 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_5854);
												mem_vec_5854 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_5855);
												mem_vec_5855 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_5856);
												mem_vec_5856 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_5857);
												mem_vec_5857 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_5858);
												mem_vec_5858 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_5859);
												mem_vec_5859 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_5860);
												mem_vec_5860 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_5861);
												mem_vec_5861 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_5862);
												mem_vec_5862 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_5863);
												mem_vec_5863 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_5864);
												mem_vec_5864 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_5865);
												mem_vec_5865 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_5866);
												mem_vec_5866 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_5867);
												mem_vec_5867 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_5868);
												mem_vec_5868 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_5869);
												mem_vec_5869 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_5870);
												mem_vec_5870 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_5871);
												mem_vec_5871 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_5872);
												mem_vec_5872 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_5873);
												mem_vec_5873 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_5874);
												mem_vec_5874 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_5875);
												mem_vec_5875 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_5876);
												mem_vec_5876 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_5877);
												mem_vec_5877 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_5878);
												mem_vec_5878 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_5879);
												mem_vec_5879 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5848);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5849);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5850);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5851);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5852);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_5853);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5854);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_5855);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5856);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5857);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5858);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5859);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5860);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_5861);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5862);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_5863);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5864);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5865);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5866);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5867);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5868);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_5869);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5870);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_5871);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5872);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5873);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5874);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5875);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5876);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_5877);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5878);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_5879);
								}
							}
						}
					}
				}
		}
	}
}


}