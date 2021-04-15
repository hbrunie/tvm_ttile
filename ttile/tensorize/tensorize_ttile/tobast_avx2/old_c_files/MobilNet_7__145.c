#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, f); T (14, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (1, f);
  T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c774_p_0, cp_1, c774, f, fp_0, f1032_p_0, f1033_p_0, fp_1, f1032_p_1, fp_2, f1032, f1033, w, wp_0, x, xp_0, x774_p_0, xp_1, x774, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y516 = 0;
IND_TYPE x775 = 0;
IND_TYPE h = 0;
IND_TYPE w470 = 0;
IND_TYPE c775 = 0;
IND_TYPE f1034 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8736 ,mem_vec_8737 ,mem_vec_8738 ,mem_vec_8739 ,mem_vec_8740 ,mem_vec_8741 ,mem_vec_8742 ,mem_vec_8743 ,mem_vec_8744 ,mem_vec_8745 ,mem_vec_8746 ,mem_vec_8747 ,mem_vec_8748 ,mem_vec_8749 ,mem_vec_8750 ,mem_vec_8751 ,mem_vec_8752 ,mem_vec_8753 ,mem_vec_8754 ,mem_vec_8755 ,mem_vec_8756 ,mem_vec_8757 ,mem_vec_8758 ,mem_vec_8759 ,mem_vec_8760 ,mem_vec_8761 ,mem_vec_8762 ,mem_vec_8763 ,mem_vec_8764 ,mem_vec_8765 ,mem_vec_8766 ,mem_vec_8767 ,mem_vec_8768 ,mem_vec_8769 ,mem_vec_8770 ,mem_vec_8771 ,mem_vec_8772 ,mem_vec_8773 ,mem_vec_8774 ,mem_vec_8775 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f1033 = f1034, f1033_p_0 = 0;
	f1033 < f1034 + 512;
	f1033 += 128, f1033_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 128
	// T (c, 2) (512 / 256)
	for (c774 = c775, c774_p_0 = 0;
		c774 < c775 + 512;
		c774 += 256, c774_p_0 += 256){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
		// T (f, 1) (128 / 128)
		for (f1032 = f1033, f1032_p_1 = f1033_p_0, f1032_p_0 = 0;
			f1032 < f1033 + 128;
			f1032 += 128, f1032_p_1 += 128, f1032_p_0 += 128){
				for (y = y516, yp_0 = 0;
					y < y516 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
					// T (x, 14) (14 / 1)
					for (x774 = x775, x774_p_0 = 0;
						x774 < x775 + 14;
						x774 += 1, x774_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1032, fp_2 = f1032_p_1, fp_1 = f1032_p_0, fp_0 = 0;
							f < f1032 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (w, 3) (3 / 1)
							for (w = w470, wp_0 = 0;
								w < w470 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
									x < x774 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8736 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8737 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8738 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8739 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
												c < c774 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8736);
												mem_vec_8736 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8737);
												mem_vec_8737 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8738);
												mem_vec_8738 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8739);
												mem_vec_8739 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8740);
												mem_vec_8740 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8741);
												mem_vec_8741 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8742);
												mem_vec_8742 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8743);
												mem_vec_8743 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8744);
												mem_vec_8744 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8745);
												mem_vec_8745 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8746);
												mem_vec_8746 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8747);
												mem_vec_8747 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8748);
												mem_vec_8748 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8749);
												mem_vec_8749 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8750);
												mem_vec_8750 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8751);
												mem_vec_8751 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_8736);
												mem_vec_8736 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_8737);
												mem_vec_8737 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_8738);
												mem_vec_8738 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_8739);
												mem_vec_8739 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_8740);
												mem_vec_8740 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_8741);
												mem_vec_8741 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_8742);
												mem_vec_8742 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_8743);
												mem_vec_8743 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_8744);
												mem_vec_8744 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_8745);
												mem_vec_8745 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_8746);
												mem_vec_8746 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_8747);
												mem_vec_8747 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_8748);
												mem_vec_8748 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_8749);
												mem_vec_8749 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_8750);
												mem_vec_8750 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_8751);
												mem_vec_8751 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_8736);
												mem_vec_8736 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_8737);
												mem_vec_8737 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_8738);
												mem_vec_8738 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_8739);
												mem_vec_8739 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_8740);
												mem_vec_8740 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_8741);
												mem_vec_8741 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_8742);
												mem_vec_8742 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_8743);
												mem_vec_8743 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_8744);
												mem_vec_8744 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_8745);
												mem_vec_8745 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_8746);
												mem_vec_8746 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_8747);
												mem_vec_8747 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_8748);
												mem_vec_8748 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_8749);
												mem_vec_8749 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_8750);
												mem_vec_8750 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_8751);
												mem_vec_8751 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8736);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8737);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8738);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8739);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8740);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8741);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8742);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8743);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8744);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8745);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8746);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8747);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8748);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8749);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8750);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8751);
								}
							}
						}
					}
				}
				for (y = y516 + 8, yp_0 = 0;
					y < y516 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
					// T (x, 14) (14 / 1)
					for (x774 = x775, x774_p_0 = 0;
						x774 < x775 + 14;
						x774 += 1, x774_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1032, fp_2 = f1032_p_1, fp_1 = f1032_p_0, fp_0 = 0;
							f < f1032 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (w, 3) (3 / 1)
							for (w = w470, wp_0 = 0;
								w < w470 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
									x < x774 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8752 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8753 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8754 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8755 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_8768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_8772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
												c < c774 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8752);
												mem_vec_8752 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8753);
												mem_vec_8753 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8754);
												mem_vec_8754 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8755);
												mem_vec_8755 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8756);
												mem_vec_8756 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8757);
												mem_vec_8757 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8758);
												mem_vec_8758 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8759);
												mem_vec_8759 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8760);
												mem_vec_8760 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8761);
												mem_vec_8761 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8762);
												mem_vec_8762 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8763);
												mem_vec_8763 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8764);
												mem_vec_8764 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8765);
												mem_vec_8765 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8766);
												mem_vec_8766 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8767);
												mem_vec_8767 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8768);
												mem_vec_8768 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8769);
												mem_vec_8769 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8770);
												mem_vec_8770 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8771);
												mem_vec_8771 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8772);
												mem_vec_8772 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8773);
												mem_vec_8773 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8774);
												mem_vec_8774 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8775);
												mem_vec_8775 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_8752);
												mem_vec_8752 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_8753);
												mem_vec_8753 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_8754);
												mem_vec_8754 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_8755);
												mem_vec_8755 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8756);
												mem_vec_8756 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_8757);
												mem_vec_8757 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8758);
												mem_vec_8758 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8759);
												mem_vec_8759 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_8760);
												mem_vec_8760 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_8761);
												mem_vec_8761 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_8762);
												mem_vec_8762 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_8763);
												mem_vec_8763 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_8764);
												mem_vec_8764 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_8765);
												mem_vec_8765 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_8766);
												mem_vec_8766 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_8767);
												mem_vec_8767 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8768);
												mem_vec_8768 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_8769);
												mem_vec_8769 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8770);
												mem_vec_8770 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8771);
												mem_vec_8771 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_8772);
												mem_vec_8772 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_8773);
												mem_vec_8773 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_8774);
												mem_vec_8774 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_8775);
												mem_vec_8775 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_8752);
												mem_vec_8752 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_8753);
												mem_vec_8753 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_8754);
												mem_vec_8754 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_8755);
												mem_vec_8755 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_8756);
												mem_vec_8756 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_8757);
												mem_vec_8757 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_8758);
												mem_vec_8758 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_8759);
												mem_vec_8759 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_8760);
												mem_vec_8760 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_8761);
												mem_vec_8761 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_8762);
												mem_vec_8762 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_8763);
												mem_vec_8763 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_8764);
												mem_vec_8764 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8765);
												mem_vec_8765 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8766);
												mem_vec_8766 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8767);
												mem_vec_8767 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_8768);
												mem_vec_8768 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_8769);
												mem_vec_8769 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_8770);
												mem_vec_8770 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_8771);
												mem_vec_8771 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_8772);
												mem_vec_8772 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_8773);
												mem_vec_8773 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_8774);
												mem_vec_8774 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_8775);
												mem_vec_8775 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8752);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8753);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8754);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8755);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8756);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8757);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8758);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8759);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8765);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8766);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8767);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8775);
								}
							}
						}
					}
				}
		}
	}
}


}