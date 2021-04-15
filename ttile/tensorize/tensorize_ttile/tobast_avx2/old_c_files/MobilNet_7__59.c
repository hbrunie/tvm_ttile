#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (512, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (8, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f);
  T (1, c); T (1, f)]
*/
IND_TYPE c, cp_0, c846_p_0, cp_1, c846, f, fp_0, f1128_p_0, f1129_p_0, fp_1, f1128_p_1, fp_2, f1128, f1129, h, hp_0, x, xp_0, x846_p_0, xp_1, x846, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y564 = 0;
IND_TYPE x847 = 0;
IND_TYPE h378 = 0;
IND_TYPE w = 0;
IND_TYPE c847 = 0;
IND_TYPE f1130 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9656 ,mem_vec_9657 ,mem_vec_9658 ,mem_vec_9659 ,mem_vec_9660 ,mem_vec_9661 ,mem_vec_9662 ,mem_vec_9663 ,mem_vec_9664 ,mem_vec_9665 ,mem_vec_9666 ,mem_vec_9667 ,mem_vec_9668 ,mem_vec_9669 ,mem_vec_9670 ,mem_vec_9671 ,mem_vec_9672 ,mem_vec_9673 ,mem_vec_9674 ,mem_vec_9675 ,mem_vec_9676 ,mem_vec_9677 ,mem_vec_9678 ,mem_vec_9679 ,mem_vec_9680 ,mem_vec_9681 ,mem_vec_9682 ,mem_vec_9683 ,mem_vec_9684 ,mem_vec_9685 ,mem_vec_9686 ,mem_vec_9687 ,mem_vec_9688 ,mem_vec_9689 ,mem_vec_9690 ,mem_vec_9691 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f1129 = f1130, f1129_p_0 = 0;
	f1129 < f1130 + 512;
	f1129 += 512, f1129_p_0 += 512){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
	// T (c, 1) (512 / 512)
	for (c846 = c847, c846_p_0 = 0;
		c846 < c847 + 512;
		c846 += 512, c846_p_0 += 512){
		// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
		// T (f, 2) (512 / 256)
		for (f1128 = f1129, f1128_p_1 = f1129_p_0, f1128_p_0 = 0;
			f1128 < f1129 + 512;
			f1128 += 256, f1128_p_1 += 256, f1128_p_0 += 256){
				for (y = y564, yp_0 = 0;
					y < y564 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 512, f = 256
					// T (x, 2) (14 / 7)
					for (x846 = x847, x846_p_0 = 0;
						x846 < x847 + 14;
						x846 += 7, x846_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 256
						// T (f, 8) (256 / 32)
						for (f = f1128, fp_2 = f1128_p_1, fp_1 = f1128_p_0, fp_0 = 0;
							f < f1128 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h378, hp_0 = 0;
								h < h378 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 512, f = 32
								// T (x, 7) (7 / 1)
								for (x = x846, xp_1 = x846_p_0, xp_0 = 0;
									x < x846 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9656 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9657 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9658 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9659 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c846, cp_1 = c846_p_0, cp_0 = 0;
												c < c846 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9656);
												mem_vec_9656 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9657);
												mem_vec_9657 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9658);
												mem_vec_9658 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9659);
												mem_vec_9659 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9660);
												mem_vec_9660 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9661);
												mem_vec_9661 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9662);
												mem_vec_9662 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9663);
												mem_vec_9663 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9664);
												mem_vec_9664 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9665);
												mem_vec_9665 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9666);
												mem_vec_9666 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9667);
												mem_vec_9667 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9668);
												mem_vec_9668 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9669);
												mem_vec_9669 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9670);
												mem_vec_9670 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9671);
												mem_vec_9671 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_9656);
												mem_vec_9656 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_9657);
												mem_vec_9657 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_9658);
												mem_vec_9658 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_9659);
												mem_vec_9659 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_9660);
												mem_vec_9660 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_9661);
												mem_vec_9661 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_9662);
												mem_vec_9662 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_9663);
												mem_vec_9663 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_9664);
												mem_vec_9664 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_9665);
												mem_vec_9665 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_9666);
												mem_vec_9666 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_9667);
												mem_vec_9667 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_9668);
												mem_vec_9668 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_9669);
												mem_vec_9669 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_9670);
												mem_vec_9670 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_9671);
												mem_vec_9671 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_9656);
												mem_vec_9656 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_9657);
												mem_vec_9657 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_9658);
												mem_vec_9658 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_9659);
												mem_vec_9659 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_9660);
												mem_vec_9660 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_9661);
												mem_vec_9661 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_9662);
												mem_vec_9662 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_9663);
												mem_vec_9663 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_9664);
												mem_vec_9664 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_9665);
												mem_vec_9665 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_9666);
												mem_vec_9666 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_9667);
												mem_vec_9667 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_9668);
												mem_vec_9668 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_9669);
												mem_vec_9669 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_9670);
												mem_vec_9670 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_9671);
												mem_vec_9671 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9663);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9664);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9665);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9666);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9667);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9668);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9669);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9670);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9671);
								}
							}
						}
					}
				}
				for (y = y564 + 4, yp_0 = 0;
					y < y564 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 512, f = 256
					// T (x, 2) (14 / 7)
					for (x846 = x847, x846_p_0 = 0;
						x846 < x847 + 14;
						x846 += 7, x846_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 256
						// T (f, 8) (256 / 32)
						for (f = f1128, fp_2 = f1128_p_1, fp_1 = f1128_p_0, fp_0 = 0;
							f < f1128 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h378, hp_0 = 0;
								h < h378 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 512, f = 32
								// T (x, 7) (7 / 1)
								for (x = x846, xp_1 = x846_p_0, xp_0 = 0;
									x < x846 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9672 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9673 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9674 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9675 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9684 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9685 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9686 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9687 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_9688 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9689 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_9690 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9691 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c846, cp_1 = c846_p_0, cp_0 = 0;
												c < c846 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9672);
												mem_vec_9672 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9673);
												mem_vec_9673 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9674);
												mem_vec_9674 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9675);
												mem_vec_9675 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9676);
												mem_vec_9676 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9677);
												mem_vec_9677 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9678);
												mem_vec_9678 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9679);
												mem_vec_9679 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9680);
												mem_vec_9680 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9681);
												mem_vec_9681 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9682);
												mem_vec_9682 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9683);
												mem_vec_9683 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9684);
												mem_vec_9684 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9685);
												mem_vec_9685 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9686);
												mem_vec_9686 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9687);
												mem_vec_9687 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9688);
												mem_vec_9688 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9689);
												mem_vec_9689 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9690);
												mem_vec_9690 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9691);
												mem_vec_9691 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_9672);
												mem_vec_9672 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_9673);
												mem_vec_9673 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_9674);
												mem_vec_9674 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_9675);
												mem_vec_9675 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_9676);
												mem_vec_9676 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_9677);
												mem_vec_9677 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_9678);
												mem_vec_9678 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_9679);
												mem_vec_9679 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_9680);
												mem_vec_9680 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_9681);
												mem_vec_9681 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_9682);
												mem_vec_9682 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_9683);
												mem_vec_9683 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_9684);
												mem_vec_9684 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_9685);
												mem_vec_9685 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_9686);
												mem_vec_9686 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_9687);
												mem_vec_9687 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_9688);
												mem_vec_9688 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_9689);
												mem_vec_9689 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_9690);
												mem_vec_9690 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_9691);
												mem_vec_9691 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_9672);
												mem_vec_9672 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_9673);
												mem_vec_9673 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_9674);
												mem_vec_9674 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_9675);
												mem_vec_9675 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_9676);
												mem_vec_9676 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_9677);
												mem_vec_9677 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_9678);
												mem_vec_9678 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_9679);
												mem_vec_9679 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_9680);
												mem_vec_9680 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_9681);
												mem_vec_9681 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_9682);
												mem_vec_9682 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9683);
												mem_vec_9683 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_9684);
												mem_vec_9684 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_9685);
												mem_vec_9685 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_9686);
												mem_vec_9686 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_9687);
												mem_vec_9687 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_9688);
												mem_vec_9688 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_9689);
												mem_vec_9689 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_9690);
												mem_vec_9690 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_9691);
												mem_vec_9691 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9672);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9673);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9674);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9675);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9676);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9677);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9678);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9679);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9680);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9681);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9682);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9683);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9684);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9685);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9686);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9687);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9688);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9689);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9690);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9691);
								}
							}
						}
					}
				}
		}
	}
}


}