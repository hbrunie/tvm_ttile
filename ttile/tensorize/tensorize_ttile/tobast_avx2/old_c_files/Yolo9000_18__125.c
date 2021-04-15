#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (2, f);
  T (8, c); T (8, f)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, f1464_p_0, f1465_p_0, fp_1, f1464_p_1, fp_2, f1464, f1465, h, hp_0, x, xp_0, x1098_p_0, xp_1, x1098, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y732 = 0;
IND_TYPE x1099 = 0;
IND_TYPE h532 = 0;
IND_TYPE w = 0;
IND_TYPE c1099 = 0;
IND_TYPE f1466 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_14756 ,mem_vec_14757 ,mem_vec_14758 ,mem_vec_14759 ,mem_vec_14760 ,mem_vec_14761 ,mem_vec_14762 ,mem_vec_14763 ,mem_vec_14764 ,mem_vec_14765 ,mem_vec_14766 ,mem_vec_14767 ,mem_vec_14768 ,mem_vec_14769 ,mem_vec_14770 ,mem_vec_14771 ,mem_vec_14772 ,mem_vec_14773 ,mem_vec_14774 ,mem_vec_14775 ,mem_vec_14776 ,mem_vec_14777 ,mem_vec_14778 ,mem_vec_14779 ,mem_vec_14780 ,mem_vec_14781 ,mem_vec_14782 ,mem_vec_14783 ,mem_vec_14784 ,mem_vec_14785 ,mem_vec_14786 ,mem_vec_14787 ,mem_vec_14788 ,mem_vec_14789 ,mem_vec_14790 ,mem_vec_14791 ,mem_vec_14792 ,mem_vec_14793 ,mem_vec_14794 ,mem_vec_14795 ,mem_vec_14796 ,mem_vec_14797 ,mem_vec_14798 ,mem_vec_14799 ,mem_vec_14800 ,mem_vec_14801 ,mem_vec_14802 ,mem_vec_14803 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f1465 = f1466, f1465_p_0 = 0;
	f1465 < f1466 + 1024;
	f1465 += 128, f1465_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 8) (512 / 64)
	for (c1098 = c1099, c1098_p_0 = 0;
		c1098 < c1099 + 512;
		c1098 += 64, c1098_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
		// T (f, 2) (128 / 64)
		for (f1464 = f1465, f1464_p_1 = f1465_p_0, f1464_p_0 = 0;
			f1464 < f1465 + 128;
			f1464 += 64, f1464_p_1 += 64, f1464_p_0 += 64){
				for (y = y732, yp_0 = 0;
					y < y732 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
					// T (x, 17) (17 / 1)
					for (x1098 = x1099, x1098_p_0 = 0;
						x1098 < x1099 + 17;
						x1098 += 1, x1098_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1464, fp_2 = f1464_p_1, fp_1 = f1464_p_0, fp_0 = 0;
							f < f1464 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h532, hp_0 = 0;
								h < h532 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
									x < x1098 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14756 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14757 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14758 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14759 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_14772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_14774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
												c < c1098 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14756);
												mem_vec_14756 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14757);
												mem_vec_14757 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14758);
												mem_vec_14758 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14759);
												mem_vec_14759 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14760);
												mem_vec_14760 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14761);
												mem_vec_14761 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14762);
												mem_vec_14762 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14763);
												mem_vec_14763 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14764);
												mem_vec_14764 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14765);
												mem_vec_14765 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14766);
												mem_vec_14766 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14767);
												mem_vec_14767 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14768);
												mem_vec_14768 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14769);
												mem_vec_14769 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14770);
												mem_vec_14770 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14771);
												mem_vec_14771 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14772);
												mem_vec_14772 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14773);
												mem_vec_14773 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14774);
												mem_vec_14774 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14775);
												mem_vec_14775 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_14756);
												mem_vec_14756 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_14757);
												mem_vec_14757 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_14758);
												mem_vec_14758 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_14759);
												mem_vec_14759 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_14760);
												mem_vec_14760 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_14761);
												mem_vec_14761 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_14762);
												mem_vec_14762 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_14763);
												mem_vec_14763 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_14764);
												mem_vec_14764 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_14765);
												mem_vec_14765 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_14766);
												mem_vec_14766 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_14767);
												mem_vec_14767 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_14768);
												mem_vec_14768 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_14769);
												mem_vec_14769 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_14770);
												mem_vec_14770 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_14771);
												mem_vec_14771 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_14772);
												mem_vec_14772 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_14773);
												mem_vec_14773 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_14774);
												mem_vec_14774 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_14775);
												mem_vec_14775 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_14756);
												mem_vec_14756 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_14757);
												mem_vec_14757 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_14758);
												mem_vec_14758 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_14759);
												mem_vec_14759 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_14760);
												mem_vec_14760 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_14761);
												mem_vec_14761 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_14762);
												mem_vec_14762 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_14763);
												mem_vec_14763 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_14764);
												mem_vec_14764 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_14765);
												mem_vec_14765 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_14766);
												mem_vec_14766 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_14767);
												mem_vec_14767 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_14768);
												mem_vec_14768 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_14769);
												mem_vec_14769 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_14770);
												mem_vec_14770 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_14771);
												mem_vec_14771 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_14772);
												mem_vec_14772 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_14773);
												mem_vec_14773 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_14774);
												mem_vec_14774 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_14775);
												mem_vec_14775 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14756);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14757);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14758);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14759);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14765);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14766);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14767);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14775);
								}
							}
						}
					}
				}
				for (y = y732 + 10, yp_0 = 0;
					y < y732 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 64
					// T (x, 17) (17 / 1)
					for (x1098 = x1099, x1098_p_0 = 0;
						x1098 < x1099 + 17;
						x1098 += 1, x1098_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 64
						// T (f, 2) (64 / 32)
						for (f = f1464, fp_2 = f1464_p_1, fp_1 = f1464_p_0, fp_0 = 0;
							f < f1464 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h532, hp_0 = 0;
								h < h532 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
									x < x1098 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14776 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14777 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14778 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14779 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_14780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_14782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_14784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_14786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_14788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_14790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_14792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_14794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_14796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_14798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_14800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_14802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
												c < c1098 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14776);
												mem_vec_14776 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14777);
												mem_vec_14777 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14778);
												mem_vec_14778 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14779);
												mem_vec_14779 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14780);
												mem_vec_14780 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14781);
												mem_vec_14781 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14782);
												mem_vec_14782 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14783);
												mem_vec_14783 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14784);
												mem_vec_14784 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14785);
												mem_vec_14785 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14786);
												mem_vec_14786 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14787);
												mem_vec_14787 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14788);
												mem_vec_14788 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14789);
												mem_vec_14789 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14790);
												mem_vec_14790 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14791);
												mem_vec_14791 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14792);
												mem_vec_14792 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14793);
												mem_vec_14793 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14794);
												mem_vec_14794 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14795);
												mem_vec_14795 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14796);
												mem_vec_14796 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14797);
												mem_vec_14797 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14798);
												mem_vec_14798 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14799);
												mem_vec_14799 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_14800);
												mem_vec_14800 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_14801);
												mem_vec_14801 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_14802);
												mem_vec_14802 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_14803);
												mem_vec_14803 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_14776);
												mem_vec_14776 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_14777);
												mem_vec_14777 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_14778);
												mem_vec_14778 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_14779);
												mem_vec_14779 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_14780);
												mem_vec_14780 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_14781);
												mem_vec_14781 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_14782);
												mem_vec_14782 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_14783);
												mem_vec_14783 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_14784);
												mem_vec_14784 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_14785);
												mem_vec_14785 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_14786);
												mem_vec_14786 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_14787);
												mem_vec_14787 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_14788);
												mem_vec_14788 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_14789);
												mem_vec_14789 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_14790);
												mem_vec_14790 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_14791);
												mem_vec_14791 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_14792);
												mem_vec_14792 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_14793);
												mem_vec_14793 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_14794);
												mem_vec_14794 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_14795);
												mem_vec_14795 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_14796);
												mem_vec_14796 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_14797);
												mem_vec_14797 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_14798);
												mem_vec_14798 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_14799);
												mem_vec_14799 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_14800);
												mem_vec_14800 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_14801);
												mem_vec_14801 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_14802);
												mem_vec_14802 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_14803);
												mem_vec_14803 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_14776);
												mem_vec_14776 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_14777);
												mem_vec_14777 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_14778);
												mem_vec_14778 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_14779);
												mem_vec_14779 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_14780);
												mem_vec_14780 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_14781);
												mem_vec_14781 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_14782);
												mem_vec_14782 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_14783);
												mem_vec_14783 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_14784);
												mem_vec_14784 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_14785);
												mem_vec_14785 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_14786);
												mem_vec_14786 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_14787);
												mem_vec_14787 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_14788);
												mem_vec_14788 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_14789);
												mem_vec_14789 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_14790);
												mem_vec_14790 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_14791);
												mem_vec_14791 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_14792);
												mem_vec_14792 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_14793);
												mem_vec_14793 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_14794);
												mem_vec_14794 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_14795);
												mem_vec_14795 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_14796);
												mem_vec_14796 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_14797);
												mem_vec_14797 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_14798);
												mem_vec_14798 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_14799);
												mem_vec_14799 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_14800);
												mem_vec_14800 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_14801);
												mem_vec_14801 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_14802);
												mem_vec_14802 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_14803);
												mem_vec_14803 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14787);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14788);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14789);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14790);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14791);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14795);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14799);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_14801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_14803);
								}
							}
						}
					}
				}
		}
	}
}


}