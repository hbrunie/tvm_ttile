#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (4, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f);
  T (64, c); T (1, f)]
*/
IND_TYPE c, cp_0, c654_p_0, cp_1, c654, f, fp_0, f872_p_0, f873_p_0, fp_1, f872_p_1, fp_2, f872, f873, w, wp_0, x, xp_0, x654_p_0, xp_1, x654, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y436 = 0;
IND_TYPE x655 = 0;
IND_TYPE h = 0;
IND_TYPE w376 = 0;
IND_TYPE c655 = 0;
IND_TYPE f874 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6776 ,mem_vec_6777 ,mem_vec_6778 ,mem_vec_6779 ,mem_vec_6780 ,mem_vec_6781 ,mem_vec_6782 ,mem_vec_6783 ,mem_vec_6784 ,mem_vec_6785 ,mem_vec_6786 ,mem_vec_6787 ,mem_vec_6788 ,mem_vec_6789 ,mem_vec_6790 ,mem_vec_6791 ,mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,mem_vec_6808 ,mem_vec_6809 ,mem_vec_6810 ,mem_vec_6811 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f873 = f874, f873_p_0 = 0;
	f873 < f874 + 256;
	f873 += 256, f873_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (c, 64) (256 / 4)
	for (c654 = c655, c654_p_0 = 0;
		c654 < c655 + 256;
		c654 += 4, c654_p_0 += 4){
		// y = 14, x = 14, h = 3, w = 3, c = 4, f = 256
		// T (f, 2) (256 / 128)
		for (f872 = f873, f872_p_1 = f873_p_0, f872_p_0 = 0;
			f872 < f873 + 256;
			f872 += 128, f872_p_1 += 128, f872_p_0 += 128){
				for (y = y436, yp_0 = 0;
					y < y436 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 128
					// T (x, 2) (14 / 7)
					for (x654 = x655, x654_p_0 = 0;
						x654 < x655 + 14;
						x654 += 7, x654_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 128
						// T (f, 4) (128 / 32)
						for (f = f872, fp_2 = f872_p_1, fp_1 = f872_p_0, fp_0 = 0;
							f < f872 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w376, wp_0 = 0;
								w < w376 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 32
								// T (x, 7) (7 / 1)
								for (x = x654, xp_1 = x654_p_0, xp_0 = 0;
									x < x654 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6776 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6777 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6778 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6779 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c654, cp_1 = c654_p_0, cp_0 = 0;
												c < c654 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6776);
												mem_vec_6776 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6777);
												mem_vec_6777 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6778);
												mem_vec_6778 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6779);
												mem_vec_6779 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6780);
												mem_vec_6780 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6781);
												mem_vec_6781 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6782);
												mem_vec_6782 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6783);
												mem_vec_6783 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6784);
												mem_vec_6784 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6785);
												mem_vec_6785 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6786);
												mem_vec_6786 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6787);
												mem_vec_6787 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6788);
												mem_vec_6788 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6789);
												mem_vec_6789 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6790);
												mem_vec_6790 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6791);
												mem_vec_6791 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6776);
												mem_vec_6776 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6777);
												mem_vec_6777 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6778);
												mem_vec_6778 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6779);
												mem_vec_6779 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6780);
												mem_vec_6780 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6781);
												mem_vec_6781 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6782);
												mem_vec_6782 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6783);
												mem_vec_6783 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6784);
												mem_vec_6784 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6785);
												mem_vec_6785 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6786);
												mem_vec_6786 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6787);
												mem_vec_6787 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6788);
												mem_vec_6788 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6789);
												mem_vec_6789 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6790);
												mem_vec_6790 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6791);
												mem_vec_6791 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6776);
												mem_vec_6776 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6777);
												mem_vec_6777 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6778);
												mem_vec_6778 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6779);
												mem_vec_6779 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6780);
												mem_vec_6780 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6781);
												mem_vec_6781 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6782);
												mem_vec_6782 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6783);
												mem_vec_6783 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6784);
												mem_vec_6784 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6785);
												mem_vec_6785 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6786);
												mem_vec_6786 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6787);
												mem_vec_6787 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6788);
												mem_vec_6788 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6789);
												mem_vec_6789 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6790);
												mem_vec_6790 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6791);
												mem_vec_6791 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6776);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6777);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6778);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6779);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6787);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6788);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6789);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6790);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6791);
								}
							}
						}
					}
				}
				for (y = y436 + 4, yp_0 = 0;
					y < y436 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 128
					// T (x, 2) (14 / 7)
					for (x654 = x655, x654_p_0 = 0;
						x654 < x655 + 14;
						x654 += 7, x654_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 128
						// T (f, 4) (128 / 32)
						for (f = f872, fp_2 = f872_p_1, fp_1 = f872_p_0, fp_0 = 0;
							f < f872 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w376, wp_0 = 0;
								w < w376 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 32
								// T (x, 7) (7 / 1)
								for (x = x654, xp_1 = x654_p_0, xp_0 = 0;
									x < x654 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6792 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6793 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6794 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6795 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c654, cp_1 = c654_p_0, cp_0 = 0;
												c < c654 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6792);
												mem_vec_6792 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6793);
												mem_vec_6793 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6794);
												mem_vec_6794 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6795);
												mem_vec_6795 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6796);
												mem_vec_6796 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6797);
												mem_vec_6797 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6798);
												mem_vec_6798 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6799);
												mem_vec_6799 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6800);
												mem_vec_6800 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6801);
												mem_vec_6801 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6802);
												mem_vec_6802 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6803);
												mem_vec_6803 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6804);
												mem_vec_6804 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6805);
												mem_vec_6805 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6806);
												mem_vec_6806 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6807);
												mem_vec_6807 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6808);
												mem_vec_6808 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6809);
												mem_vec_6809 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6810);
												mem_vec_6810 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6811);
												mem_vec_6811 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6792);
												mem_vec_6792 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6793);
												mem_vec_6793 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_6794);
												mem_vec_6794 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_6795);
												mem_vec_6795 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_6796);
												mem_vec_6796 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_6797);
												mem_vec_6797 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_6798);
												mem_vec_6798 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_6799);
												mem_vec_6799 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6800);
												mem_vec_6800 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6801);
												mem_vec_6801 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_6802);
												mem_vec_6802 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_6803);
												mem_vec_6803 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_6804);
												mem_vec_6804 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_6805);
												mem_vec_6805 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_6806);
												mem_vec_6806 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_6807);
												mem_vec_6807 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_6808);
												mem_vec_6808 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_6809);
												mem_vec_6809 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_6810);
												mem_vec_6810 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_6811);
												mem_vec_6811 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6792);
												mem_vec_6792 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6793);
												mem_vec_6793 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_6794);
												mem_vec_6794 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_6795);
												mem_vec_6795 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_6796);
												mem_vec_6796 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_6797);
												mem_vec_6797 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_6798);
												mem_vec_6798 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_6799);
												mem_vec_6799 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6800);
												mem_vec_6800 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6801);
												mem_vec_6801 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_6802);
												mem_vec_6802 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6803);
												mem_vec_6803 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_6804);
												mem_vec_6804 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_6805);
												mem_vec_6805 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_6806);
												mem_vec_6806 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_6807);
												mem_vec_6807 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_6808);
												mem_vec_6808 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_6809);
												mem_vec_6809 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_6810);
												mem_vec_6810 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_6811);
												mem_vec_6811 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6795);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6799);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6811);
								}
							}
						}
					}
				}
		}
	}
}


}