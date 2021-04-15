#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (8, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (16, c);
  T (4, f); T (8, c)]
*/
IND_TYPE c, cp_0, c1458_p_0, c1459_p_0, c1460_p_0, cp_1, c1458_p_1, c1459_p_1, cp_2, c1458_p_2, cp_3, c1458, c1459, c1460, f, fp_0, f966_p_0, fp_1, f966, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y644 = 0;
IND_TYPE x644 = 0;
IND_TYPE h570 = 0;
IND_TYPE w = 0;
IND_TYPE c1461 = 0;
IND_TYPE f967 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13776 ,mem_vec_13777 ,mem_vec_13778 ,mem_vec_13779 ,mem_vec_13780 ,mem_vec_13781 ,mem_vec_13782 ,mem_vec_13783 ,mem_vec_13784 ,mem_vec_13785 ,mem_vec_13786 ,mem_vec_13787 ,mem_vec_13788 ,mem_vec_13789 ,mem_vec_13790 ,mem_vec_13791 ,mem_vec_13792 ,mem_vec_13793 ,mem_vec_13794 ,mem_vec_13795 ,mem_vec_13796 ,mem_vec_13797 ,mem_vec_13798 ,mem_vec_13799 ,mem_vec_13800 ,mem_vec_13801 ,mem_vec_13802 ,mem_vec_13803 ,mem_vec_13804 ,mem_vec_13805 ,mem_vec_13806 ,mem_vec_13807 ,mem_vec_13808 ,mem_vec_13809 ,mem_vec_13810 ,mem_vec_13811 ,mem_vec_13812 ,mem_vec_13813 ,mem_vec_13814 ,mem_vec_13815 ,mem_vec_13816 ,mem_vec_13817 ,mem_vec_13818 ,mem_vec_13819 ,mem_vec_13820 ,mem_vec_13821 ,mem_vec_13822 ,mem_vec_13823 ,mem_vec_13824 ,mem_vec_13825 ,mem_vec_13826 ,mem_vec_13827 ,mem_vec_13828 ,mem_vec_13829 ,mem_vec_13830 ,mem_vec_13831 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c1460 = c1461, c1460_p_0 = 0;
	c1460 < c1461 + 1024;
	c1460 += 128, c1460_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 4) (1024 / 256)
	for (f966 = f967, f966_p_0 = 0;
		f966 < f967 + 1024;
		f966 += 256, f966_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 256
		// T (c, 16) (128 / 8)
		for (c1459 = c1460, c1459_p_1 = c1460_p_0, c1459_p_0 = 0;
			c1459 < c1460 + 128;
			c1459 += 8, c1459_p_1 += 8, c1459_p_0 += 8){
				for (y = y644, yp_0 = 0;
					y < y644 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 256
					// T (f, 4) (256 / 64)
					for (f = f966, fp_1 = f966_p_0, fp_0 = 0;
						f < f966 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (c, 8) (8 / 1)
						for (c1458 = c1459, c1458_p_2 = c1459_p_1, c1458_p_1 = c1459_p_0, c1458_p_0 = 0;
							c1458 < c1459 + 8;
							c1458 += 1, c1458_p_2 += 1, c1458_p_1 += 1, c1458_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h570, hp_0 = 0;
								h < h570 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x644, xp_0 = 0;
									x < x644 + 7;
									x += 1, xp_0 += 1){
											mem_vec_13776 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13777 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13778 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13779 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13780 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13781 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_13782 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13783 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_13784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_13790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_13792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_13798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1458, cp_3 = c1458_p_2, cp_2 = c1458_p_1, cp_1 = c1458_p_0, cp_0 = 0;
												c < c1458 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13776);
												mem_vec_13776 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13777);
												mem_vec_13777 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13778);
												mem_vec_13778 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13779);
												mem_vec_13779 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_13780);
												mem_vec_13780 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_13781);
												mem_vec_13781 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_13782);
												mem_vec_13782 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_13783);
												mem_vec_13783 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_13784);
												mem_vec_13784 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_13785);
												mem_vec_13785 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_13786);
												mem_vec_13786 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_13787);
												mem_vec_13787 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_13788);
												mem_vec_13788 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_13789);
												mem_vec_13789 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_13790);
												mem_vec_13790 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_13791);
												mem_vec_13791 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_13792);
												mem_vec_13792 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_13793);
												mem_vec_13793 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_13794);
												mem_vec_13794 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_13795);
												mem_vec_13795 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_13796);
												mem_vec_13796 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_13797);
												mem_vec_13797 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_13798);
												mem_vec_13798 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_13799);
												mem_vec_13799 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_13776);
												mem_vec_13776 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_13777);
												mem_vec_13777 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_13778);
												mem_vec_13778 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_13779);
												mem_vec_13779 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_13780);
												mem_vec_13780 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_13781);
												mem_vec_13781 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_13782);
												mem_vec_13782 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_13783);
												mem_vec_13783 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_13784);
												mem_vec_13784 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_13785);
												mem_vec_13785 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_13786);
												mem_vec_13786 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_13787);
												mem_vec_13787 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_13788);
												mem_vec_13788 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_13789);
												mem_vec_13789 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_13790);
												mem_vec_13790 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_13791);
												mem_vec_13791 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_13792);
												mem_vec_13792 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_13793);
												mem_vec_13793 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_13794);
												mem_vec_13794 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_13795);
												mem_vec_13795 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_13796);
												mem_vec_13796 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_13797);
												mem_vec_13797 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_13798);
												mem_vec_13798 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_13799);
												mem_vec_13799 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_13776);
												mem_vec_13776 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_13777);
												mem_vec_13777 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_13778);
												mem_vec_13778 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_13779);
												mem_vec_13779 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_13780);
												mem_vec_13780 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_13781);
												mem_vec_13781 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_13782);
												mem_vec_13782 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_13783);
												mem_vec_13783 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13784);
												mem_vec_13784 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13785);
												mem_vec_13785 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13786);
												mem_vec_13786 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_13787);
												mem_vec_13787 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_13788);
												mem_vec_13788 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_13789);
												mem_vec_13789 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_13790);
												mem_vec_13790 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_13791);
												mem_vec_13791 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_13792);
												mem_vec_13792 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_13793);
												mem_vec_13793 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_13794);
												mem_vec_13794 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_13795);
												mem_vec_13795 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_13796);
												mem_vec_13796 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_13797);
												mem_vec_13797 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_13798);
												mem_vec_13798 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_13799);
												mem_vec_13799 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_13781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_13783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13787);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13788);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_13789);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13790);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_13791);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13795);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_13797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_13799);
								}
							}
						}
					}
				}
				for (y = y644 + 3, yp_0 = 0;
					y < y644 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 256
					// T (f, 4) (256 / 64)
					for (f = f966, fp_1 = f966_p_0, fp_0 = 0;
						f < f966 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (c, 8) (8 / 1)
						for (c1458 = c1459, c1458_p_2 = c1459_p_1, c1458_p_1 = c1459_p_0, c1458_p_0 = 0;
							c1458 < c1459 + 8;
							c1458 += 1, c1458_p_2 += 1, c1458_p_1 += 1, c1458_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h570, hp_0 = 0;
								h < h570 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x644, xp_0 = 0;
									x < x644 + 7;
									x += 1, xp_0 += 1){
											mem_vec_13800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13804 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13805 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_13806 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13807 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_13808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_13814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_13816 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13817 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13818 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13819 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_13822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_13824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_13829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_13830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_13831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1458, cp_3 = c1458_p_2, cp_2 = c1458_p_1, cp_1 = c1458_p_0, cp_0 = 0;
												c < c1458 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13800);
												mem_vec_13800 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13801);
												mem_vec_13801 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13802);
												mem_vec_13802 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13803);
												mem_vec_13803 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_13804);
												mem_vec_13804 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_13805);
												mem_vec_13805 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_13806);
												mem_vec_13806 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_13807);
												mem_vec_13807 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_13808);
												mem_vec_13808 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_13809);
												mem_vec_13809 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_13810);
												mem_vec_13810 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_13811);
												mem_vec_13811 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_13812);
												mem_vec_13812 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_13813);
												mem_vec_13813 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_13814);
												mem_vec_13814 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_13815);
												mem_vec_13815 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_13816);
												mem_vec_13816 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_13817);
												mem_vec_13817 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_13818);
												mem_vec_13818 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_13819);
												mem_vec_13819 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_13820);
												mem_vec_13820 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_13821);
												mem_vec_13821 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_13822);
												mem_vec_13822 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_13823);
												mem_vec_13823 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_13824);
												mem_vec_13824 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_13825);
												mem_vec_13825 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_13826);
												mem_vec_13826 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_13827);
												mem_vec_13827 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_13828);
												mem_vec_13828 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_13829);
												mem_vec_13829 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_13830);
												mem_vec_13830 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_13831);
												mem_vec_13831 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_13800);
												mem_vec_13800 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_13801);
												mem_vec_13801 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_13802);
												mem_vec_13802 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_13803);
												mem_vec_13803 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_13804);
												mem_vec_13804 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_13805);
												mem_vec_13805 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_13806);
												mem_vec_13806 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_13807);
												mem_vec_13807 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_13808);
												mem_vec_13808 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_13809);
												mem_vec_13809 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_13810);
												mem_vec_13810 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_13811);
												mem_vec_13811 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_13812);
												mem_vec_13812 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_13813);
												mem_vec_13813 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_13814);
												mem_vec_13814 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_13815);
												mem_vec_13815 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_13816);
												mem_vec_13816 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_13817);
												mem_vec_13817 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_13818);
												mem_vec_13818 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_13819);
												mem_vec_13819 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_13820);
												mem_vec_13820 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_13821);
												mem_vec_13821 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_13822);
												mem_vec_13822 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_13823);
												mem_vec_13823 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_13824);
												mem_vec_13824 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_13825);
												mem_vec_13825 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_13826);
												mem_vec_13826 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_13827);
												mem_vec_13827 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_13828);
												mem_vec_13828 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_13829);
												mem_vec_13829 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_13830);
												mem_vec_13830 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_13831);
												mem_vec_13831 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_13800);
												mem_vec_13800 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_13801);
												mem_vec_13801 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_13802);
												mem_vec_13802 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_13803);
												mem_vec_13803 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_13804);
												mem_vec_13804 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_13805);
												mem_vec_13805 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_13806);
												mem_vec_13806 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_13807);
												mem_vec_13807 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_13808);
												mem_vec_13808 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_13809);
												mem_vec_13809 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_13810);
												mem_vec_13810 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_13811);
												mem_vec_13811 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_13812);
												mem_vec_13812 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_13813);
												mem_vec_13813 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_13814);
												mem_vec_13814 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_13815);
												mem_vec_13815 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_13816);
												mem_vec_13816 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_13817);
												mem_vec_13817 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_13818);
												mem_vec_13818 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_13819);
												mem_vec_13819 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_13820);
												mem_vec_13820 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_13821);
												mem_vec_13821 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_13822);
												mem_vec_13822 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_13823);
												mem_vec_13823 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_13824);
												mem_vec_13824 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_13825);
												mem_vec_13825 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_13826);
												mem_vec_13826 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_13827);
												mem_vec_13827 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_13828);
												mem_vec_13828 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_13829);
												mem_vec_13829 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_13830);
												mem_vec_13830 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_13831);
												mem_vec_13831 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_13805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_13807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_13813);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13814);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_13815);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13816);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13817);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13818);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13819);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13820);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_13821);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13822);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_13823);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13824);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13825);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13826);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13827);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13828);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_13829);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13830);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_13831);
								}
							}
						}
					}
				}
		}
	}
}


}