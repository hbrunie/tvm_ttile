#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (1, f);
  T (128, c); T (8, f)]
*/
IND_TYPE c, cp_0, c442_p_0, cp_1, c442, f, fp_0, f482_p_0, f483_p_0, fp_1, f482_p_1, fp_2, f482, f483, w, wp_0, x, xp_0, x396_p_0, xp_1, x396, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y264 = 0;
IND_TYPE x397 = 0;
IND_TYPE h = 0;
IND_TYPE w264 = 0;
IND_TYPE c443 = 0;
IND_TYPE f484 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3814 ,mem_vec_3815 ,mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f483 = f484, f483_p_0 = 0;
	f483 < f484 + 1024;
	f483 += 128, f483_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 128) (512 / 4)
	for (c442 = c443, c442_p_0 = 0;
		c442 < c443 + 512;
		c442 += 4, c442_p_0 += 4){
		// y = 17, x = 17, h = 3, w = 3, c = 4, f = 128
		// T (f, 1) (128 / 128)
		for (f482 = f483, f482_p_1 = f483_p_0, f482_p_0 = 0;
			f482 < f483 + 128;
			f482 += 128, f482_p_1 += 128, f482_p_0 += 128){
				for (y = y264, yp_0 = 0;
					y < y264 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 128
					// T (x, 17) (17 / 1)
					for (x396 = x397, x396_p_0 = 0;
						x396 < x397 + 17;
						x396 += 1, x396_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 128
						// T (f, 2) (128 / 64)
						for (f = f482, fp_2 = f482_p_1, fp_1 = f482_p_0, fp_0 = 0;
							f < f482 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (w, 3) (3 / 1)
							for (w = w264, wp_0 = 0;
								w < w264 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
								// T (x, 1) (1 / 1)
								for (x = x396, xp_1 = x396_p_0, xp_0 = 0;
									x < x396 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3814 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3815 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3816 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_3817 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_3818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_3821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_3822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_3825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c442, cp_1 = c442_p_0, cp_0 = 0;
												c < c442 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3814);
												mem_vec_3814 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3815);
												mem_vec_3815 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3816);
												mem_vec_3816 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3817);
												mem_vec_3817 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3818);
												mem_vec_3818 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3819);
												mem_vec_3819 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3820);
												mem_vec_3820 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3821);
												mem_vec_3821 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3822);
												mem_vec_3822 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3823);
												mem_vec_3823 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3824);
												mem_vec_3824 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3825);
												mem_vec_3825 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_3814);
												mem_vec_3814 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_3815);
												mem_vec_3815 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_3816);
												mem_vec_3816 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_3817);
												mem_vec_3817 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_3818);
												mem_vec_3818 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_3819);
												mem_vec_3819 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_3820);
												mem_vec_3820 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_3821);
												mem_vec_3821 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_3822);
												mem_vec_3822 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_3823);
												mem_vec_3823 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_3824);
												mem_vec_3824 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_3825);
												mem_vec_3825 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_3814);
												mem_vec_3814 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_3815);
												mem_vec_3815 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_3816);
												mem_vec_3816 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_3817);
												mem_vec_3817 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_3818);
												mem_vec_3818 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_3819);
												mem_vec_3819 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_3820);
												mem_vec_3820 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_3821);
												mem_vec_3821 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_3822);
												mem_vec_3822 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_3823);
												mem_vec_3823 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_3824);
												mem_vec_3824 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_3825);
												mem_vec_3825 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3825);
								}
							}
						}
					}
				}
				for (y = y264 + 3, yp_0 = 0;
					y < y264 + 3 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 128
					// T (x, 17) (17 / 1)
					for (x396 = x397, x396_p_0 = 0;
						x396 < x397 + 17;
						x396 += 1, x396_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 128
						// T (f, 2) (128 / 64)
						for (f = f482, fp_2 = f482_p_1, fp_1 = f482_p_0, fp_0 = 0;
							f < f482 + 128;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (w, 3) (3 / 1)
							for (w = w264, wp_0 = 0;
								w < w264 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
								// T (x, 1) (1 / 1)
								for (x = x396, xp_1 = x396_p_0, xp_0 = 0;
									x < x396 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3826 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3827 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_3829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_3830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_3833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_3834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_3837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_3838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_3841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_3842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_3845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_3846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_3849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_3850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_3853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c442, cp_1 = c442_p_0, cp_0 = 0;
												c < c442 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3826);
												mem_vec_3826 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3827);
												mem_vec_3827 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3828);
												mem_vec_3828 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3829);
												mem_vec_3829 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3830);
												mem_vec_3830 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3831);
												mem_vec_3831 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3832);
												mem_vec_3832 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3833);
												mem_vec_3833 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3834);
												mem_vec_3834 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3835);
												mem_vec_3835 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3836);
												mem_vec_3836 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3837);
												mem_vec_3837 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3838);
												mem_vec_3838 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3839);
												mem_vec_3839 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3840);
												mem_vec_3840 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3841);
												mem_vec_3841 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3842);
												mem_vec_3842 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3843);
												mem_vec_3843 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3844);
												mem_vec_3844 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3845);
												mem_vec_3845 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3846);
												mem_vec_3846 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3847);
												mem_vec_3847 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3848);
												mem_vec_3848 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3849);
												mem_vec_3849 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_3850);
												mem_vec_3850 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_3851);
												mem_vec_3851 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_3852);
												mem_vec_3852 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_3853);
												mem_vec_3853 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_3826);
												mem_vec_3826 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_3827);
												mem_vec_3827 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_3828);
												mem_vec_3828 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_3829);
												mem_vec_3829 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_3830);
												mem_vec_3830 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_3831);
												mem_vec_3831 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_3832);
												mem_vec_3832 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_3833);
												mem_vec_3833 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_3834);
												mem_vec_3834 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_3835);
												mem_vec_3835 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_3836);
												mem_vec_3836 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_3837);
												mem_vec_3837 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_3838);
												mem_vec_3838 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_3839);
												mem_vec_3839 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_3840);
												mem_vec_3840 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_3841);
												mem_vec_3841 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_3842);
												mem_vec_3842 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_3843);
												mem_vec_3843 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_3844);
												mem_vec_3844 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_3845);
												mem_vec_3845 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_3846);
												mem_vec_3846 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_3847);
												mem_vec_3847 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_3848);
												mem_vec_3848 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_3849);
												mem_vec_3849 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_3850);
												mem_vec_3850 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_3851);
												mem_vec_3851 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_3852);
												mem_vec_3852 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_3853);
												mem_vec_3853 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_3826);
												mem_vec_3826 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_3827);
												mem_vec_3827 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_3828);
												mem_vec_3828 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_3829);
												mem_vec_3829 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_3830);
												mem_vec_3830 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_3831);
												mem_vec_3831 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_3832);
												mem_vec_3832 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_3833);
												mem_vec_3833 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_3834);
												mem_vec_3834 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_3835);
												mem_vec_3835 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_3836);
												mem_vec_3836 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_3837);
												mem_vec_3837 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_3838);
												mem_vec_3838 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_3839);
												mem_vec_3839 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_3840);
												mem_vec_3840 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_3841);
												mem_vec_3841 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_3842);
												mem_vec_3842 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_3843);
												mem_vec_3843 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_3844);
												mem_vec_3844 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_3845);
												mem_vec_3845 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_3846);
												mem_vec_3846 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_3847);
												mem_vec_3847 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_3848);
												mem_vec_3848 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_3849);
												mem_vec_3849 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_3850);
												mem_vec_3850 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_3851);
												mem_vec_3851 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_3852);
												mem_vec_3852 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_3853);
												mem_vec_3853 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_3852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_3853);
								}
							}
						}
					}
				}
		}
	}
}


}