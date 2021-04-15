#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (8, f);
  T (256, c); T (1, f)]
*/
IND_TYPE c, cp_0, c324_p_0, cp_1, c324, f, fp_0, f432_p_0, f433_p_0, fp_1, f432_p_1, fp_2, f432, f433, w, wp_0, x, xp_0, x324_p_0, xp_1, x324, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y216 = 0;
IND_TYPE x325 = 0;
IND_TYPE h = 0;
IND_TYPE w216 = 0;
IND_TYPE c325 = 0;
IND_TYPE f434 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3780 ,mem_vec_3781 ,mem_vec_3782 ,mem_vec_3783 ,mem_vec_3784 ,mem_vec_3785 ,mem_vec_3786 ,mem_vec_3787 ,mem_vec_3788 ,mem_vec_3789 ,mem_vec_3790 ,mem_vec_3791 ,mem_vec_3792 ,mem_vec_3793 ,mem_vec_3794 ,mem_vec_3795 ,mem_vec_3796 ,mem_vec_3797 ,mem_vec_3798 ,mem_vec_3799 ,mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f433 = f434, f433_p_0 = 0;
	f433 < f434 + 1024;
	f433 += 1024, f433_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 256) (512 / 2)
	for (c324 = c325, c324_p_0 = 0;
		c324 < c325 + 512;
		c324 += 2, c324_p_0 += 2){
		// y = 17, x = 17, h = 3, w = 3, c = 2, f = 1024
		// T (f, 8) (1024 / 128)
		for (f432 = f433, f432_p_1 = f433_p_0, f432_p_0 = 0;
			f432 < f433 + 1024;
			f432 += 128, f432_p_1 += 128, f432_p_0 += 128){
				for (y = y216, yp_0 = 0;
					y < y216 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 128
					// T (x, 17) (17 / 1)
					for (x324 = x325, x324_p_0 = 0;
						x324 < x325 + 17;
						x324 += 1, x324_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 128
						// T (f, 8) (128 / 16)
						for (f = f432, fp_2 = f432_p_1, fp_1 = f432_p_0, fp_0 = 0;
							f < f432 + 128;
							f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (w, 3) (3 / 1)
							for (w = w216, wp_0 = 0;
								w < w216 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
								// T (x, 1) (1 / 1)
								for (x = x324, xp_1 = x324_p_0, xp_0 = 0;
									x < x324 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3780 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3781 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c324, cp_1 = c324_p_0, cp_0 = 0;
												c < c324 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3780);
												mem_vec_3780 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3781);
												mem_vec_3781 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3782);
												mem_vec_3782 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3783);
												mem_vec_3783 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3784);
												mem_vec_3784 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3785);
												mem_vec_3785 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3786);
												mem_vec_3786 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3787);
												mem_vec_3787 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3788);
												mem_vec_3788 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3789);
												mem_vec_3789 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3790);
												mem_vec_3790 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3791);
												mem_vec_3791 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3792);
												mem_vec_3792 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3793);
												mem_vec_3793 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3794);
												mem_vec_3794 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3795);
												mem_vec_3795 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_3780);
												mem_vec_3780 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_3781);
												mem_vec_3781 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_3782);
												mem_vec_3782 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_3783);
												mem_vec_3783 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_3784);
												mem_vec_3784 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_3785);
												mem_vec_3785 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_3786);
												mem_vec_3786 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_3787);
												mem_vec_3787 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_3788);
												mem_vec_3788 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_3789);
												mem_vec_3789 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3790);
												mem_vec_3790 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3791);
												mem_vec_3791 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_3792);
												mem_vec_3792 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_3793);
												mem_vec_3793 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_3794);
												mem_vec_3794 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_3795);
												mem_vec_3795 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_3780);
												mem_vec_3780 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_3781);
												mem_vec_3781 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3782);
												mem_vec_3782 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3783);
												mem_vec_3783 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_3784);
												mem_vec_3784 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_3785);
												mem_vec_3785 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_3786);
												mem_vec_3786 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_3787);
												mem_vec_3787 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_3788);
												mem_vec_3788 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_3789);
												mem_vec_3789 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_3790);
												mem_vec_3790 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_3791);
												mem_vec_3791 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_3792);
												mem_vec_3792 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_3793);
												mem_vec_3793 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_3794);
												mem_vec_3794 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_3795);
												mem_vec_3795 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3780);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3781);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3782);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3783);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3784);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3785);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3786);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3787);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3788);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3789);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3790);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3791);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3792);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3793);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3794);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3795);
								}
							}
						}
					}
				}
				for (y = y216 + 8, yp_0 = 0;
					y < y216 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 128
					// T (x, 17) (17 / 1)
					for (x324 = x325, x324_p_0 = 0;
						x324 < x325 + 17;
						x324 += 1, x324_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 128
						// T (f, 8) (128 / 16)
						for (f = f432, fp_2 = f432_p_1, fp_1 = f432_p_0, fp_0 = 0;
							f < f432 + 128;
							f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (w, 3) (3 / 1)
							for (w = w216, wp_0 = 0;
								w < w216 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
								// T (x, 1) (1 / 1)
								for (x = x324, xp_1 = x324_p_0, xp_0 = 0;
									x < x324 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3796 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3797 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_3812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c324, cp_1 = c324_p_0, cp_0 = 0;
												c < c324 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3796);
												mem_vec_3796 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3797);
												mem_vec_3797 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3798);
												mem_vec_3798 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3799);
												mem_vec_3799 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3800);
												mem_vec_3800 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3801);
												mem_vec_3801 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3802);
												mem_vec_3802 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3803);
												mem_vec_3803 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3804);
												mem_vec_3804 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3805);
												mem_vec_3805 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3806);
												mem_vec_3806 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3807);
												mem_vec_3807 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3808);
												mem_vec_3808 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3809);
												mem_vec_3809 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3810);
												mem_vec_3810 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3811);
												mem_vec_3811 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3812);
												mem_vec_3812 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3813);
												mem_vec_3813 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_3796);
												mem_vec_3796 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_3797);
												mem_vec_3797 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_3798);
												mem_vec_3798 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_3799);
												mem_vec_3799 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_3800);
												mem_vec_3800 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_3801);
												mem_vec_3801 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_3802);
												mem_vec_3802 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_3803);
												mem_vec_3803 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_3804);
												mem_vec_3804 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_3805);
												mem_vec_3805 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_3806);
												mem_vec_3806 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_3807);
												mem_vec_3807 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_3808);
												mem_vec_3808 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_3809);
												mem_vec_3809 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_3810);
												mem_vec_3810 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_3811);
												mem_vec_3811 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_3812);
												mem_vec_3812 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_3813);
												mem_vec_3813 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_3796);
												mem_vec_3796 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_3797);
												mem_vec_3797 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_3798);
												mem_vec_3798 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_3799);
												mem_vec_3799 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_3800);
												mem_vec_3800 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_3801);
												mem_vec_3801 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_3802);
												mem_vec_3802 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_3803);
												mem_vec_3803 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_3804);
												mem_vec_3804 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_3805);
												mem_vec_3805 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_3806);
												mem_vec_3806 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_3807);
												mem_vec_3807 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_3808);
												mem_vec_3808 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_3809);
												mem_vec_3809 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_3810);
												mem_vec_3810 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_3811);
												mem_vec_3811 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_3812);
												mem_vec_3812 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_3813);
												mem_vec_3813 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3796);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3797);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3798);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3799);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3800);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3801);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3802);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3803);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3804);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3805);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3806);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3807);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3808);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3809);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3810);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3811);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3812);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3813);
								}
							}
						}
					}
				}
		}
	}
}


}