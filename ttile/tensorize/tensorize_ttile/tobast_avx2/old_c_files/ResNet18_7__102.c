#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (8, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c636_p_0, cp_1, c636, f, fp_0, f848_p_0, f849_p_0, fp_1, f848_p_1, fp_2, f848, f849, w, wp_0, x, xp_0, x636_p_0, xp_1, x636, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y424 = 0;
IND_TYPE x637 = 0;
IND_TYPE h = 0;
IND_TYPE w360 = 0;
IND_TYPE c637 = 0;
IND_TYPE f850 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6752 ,mem_vec_6753 ,mem_vec_6754 ,mem_vec_6755 ,mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,mem_vec_6760 ,mem_vec_6761 ,mem_vec_6762 ,mem_vec_6763 ,mem_vec_6764 ,mem_vec_6765 ,mem_vec_6766 ,mem_vec_6767 ,mem_vec_6768 ,mem_vec_6769 ,mem_vec_6770 ,mem_vec_6771 ,mem_vec_6772 ,mem_vec_6773 ,mem_vec_6774 ,mem_vec_6775 ,mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,mem_vec_6784 ,mem_vec_6785 ,mem_vec_6786 ,mem_vec_6787 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f849 = f850, f849_p_0 = 0;
	f849 < f850 + 256;
	f849 += 256, f849_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (c, 16) (128 / 8)
	for (c636 = c637, c636_p_0 = 0;
		c636 < c637 + 128;
		c636 += 8, c636_p_0 += 8){
		// y = 14, x = 14, h = 3, w = 3, c = 8, f = 256
		// T (f, 1) (256 / 256)
		for (f848 = f849, f848_p_1 = f849_p_0, f848_p_0 = 0;
			f848 < f849 + 256;
			f848 += 256, f848_p_1 += 256, f848_p_0 += 256){
				for (y = y424, yp_0 = 0;
					y < y424 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 256
					// T (x, 7) (14 / 2)
					for (x636 = x637, x636_p_0 = 0;
						x636 < x637 + 14;
						x636 += 2, x636_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 256
						// T (f, 8) (256 / 32)
						for (f = f848, fp_2 = f848_p_1, fp_1 = f848_p_0, fp_0 = 0;
							f < f848 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w360, wp_0 = 0;
								w < w360 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x636, xp_1 = x636_p_0, xp_0 = 0;
									x < x636 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6752 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6753 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6754 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6755 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
												c < c636 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6752);
												mem_vec_6752 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6753);
												mem_vec_6753 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6754);
												mem_vec_6754 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6755);
												mem_vec_6755 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6756);
												mem_vec_6756 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6757);
												mem_vec_6757 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6758);
												mem_vec_6758 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6759);
												mem_vec_6759 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6760);
												mem_vec_6760 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6761);
												mem_vec_6761 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6762);
												mem_vec_6762 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6763);
												mem_vec_6763 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6764);
												mem_vec_6764 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6765);
												mem_vec_6765 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6766);
												mem_vec_6766 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6767);
												mem_vec_6767 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6752);
												mem_vec_6752 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6753);
												mem_vec_6753 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6754);
												mem_vec_6754 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6755);
												mem_vec_6755 = vec_31;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6756);
												mem_vec_6756 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6757);
												mem_vec_6757 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6758);
												mem_vec_6758 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6759);
												mem_vec_6759 = vec_37;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6760);
												mem_vec_6760 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6761);
												mem_vec_6761 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6762);
												mem_vec_6762 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6763);
												mem_vec_6763 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6764);
												mem_vec_6764 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6765);
												mem_vec_6765 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6766);
												mem_vec_6766 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6767);
												mem_vec_6767 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6752);
												mem_vec_6752 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6753);
												mem_vec_6753 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6754);
												mem_vec_6754 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6755);
												mem_vec_6755 = vec_55;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6756);
												mem_vec_6756 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6757);
												mem_vec_6757 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6758);
												mem_vec_6758 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6759);
												mem_vec_6759 = vec_61;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6760);
												mem_vec_6760 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6761);
												mem_vec_6761 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6762);
												mem_vec_6762 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6763);
												mem_vec_6763 = vec_66;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6764);
												mem_vec_6764 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6765);
												mem_vec_6765 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6766);
												mem_vec_6766 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6767);
												mem_vec_6767 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6752);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6753);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6754);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6755);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6756);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6757);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6758);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6759);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6760);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6761);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6762);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6763);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6764);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6765);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6766);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6767);
								}
							}
						}
					}
				}
				for (y = y424 + 4, yp_0 = 0;
					y < y424 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 256
					// T (x, 7) (14 / 2)
					for (x636 = x637, x636_p_0 = 0;
						x636 < x637 + 14;
						x636 += 2, x636_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 256
						// T (f, 8) (256 / 32)
						for (f = f848, fp_2 = f848_p_1, fp_1 = f848_p_0, fp_0 = 0;
							f < f848 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w360, wp_0 = 0;
								w < w360 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x636, xp_1 = x636_p_0, xp_0 = 0;
									x < x636 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6768 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6769 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6770 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6771 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c636, cp_1 = c636_p_0, cp_0 = 0;
												c < c636 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6768);
												mem_vec_6768 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6769);
												mem_vec_6769 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6770);
												mem_vec_6770 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6771);
												mem_vec_6771 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6772);
												mem_vec_6772 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6773);
												mem_vec_6773 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6774);
												mem_vec_6774 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6775);
												mem_vec_6775 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6776);
												mem_vec_6776 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6777);
												mem_vec_6777 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6778);
												mem_vec_6778 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6779);
												mem_vec_6779 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6780);
												mem_vec_6780 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6781);
												mem_vec_6781 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6782);
												mem_vec_6782 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6783);
												mem_vec_6783 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6784);
												mem_vec_6784 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6785);
												mem_vec_6785 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6786);
												mem_vec_6786 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6787);
												mem_vec_6787 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6768);
												mem_vec_6768 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6769);
												mem_vec_6769 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_6770);
												mem_vec_6770 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_6771);
												mem_vec_6771 = vec_36;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_6772);
												mem_vec_6772 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_6773);
												mem_vec_6773 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_6774);
												mem_vec_6774 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_6775);
												mem_vec_6775 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6776);
												mem_vec_6776 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6777);
												mem_vec_6777 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_6778);
												mem_vec_6778 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_6779);
												mem_vec_6779 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_6780);
												mem_vec_6780 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_6781);
												mem_vec_6781 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_6782);
												mem_vec_6782 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_6783);
												mem_vec_6783 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_6784);
												mem_vec_6784 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_6785);
												mem_vec_6785 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_6786);
												mem_vec_6786 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_6787);
												mem_vec_6787 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6768);
												mem_vec_6768 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6769);
												mem_vec_6769 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_6770);
												mem_vec_6770 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_6771);
												mem_vec_6771 = vec_65;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_6772);
												mem_vec_6772 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_6773);
												mem_vec_6773 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_6774);
												mem_vec_6774 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_6775);
												mem_vec_6775 = vec_71;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6776);
												mem_vec_6776 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6777);
												mem_vec_6777 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_6778);
												mem_vec_6778 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6779);
												mem_vec_6779 = vec_76;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_6780);
												mem_vec_6780 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_6781);
												mem_vec_6781 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_6782);
												mem_vec_6782 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_6783);
												mem_vec_6783 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_6784);
												mem_vec_6784 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_6785);
												mem_vec_6785 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_6786);
												mem_vec_6786 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_6787);
												mem_vec_6787 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6768);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6769);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6770);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6771);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6772);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6773);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6774);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6775);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6787);
								}
							}
						}
					}
				}
		}
	}
}


}