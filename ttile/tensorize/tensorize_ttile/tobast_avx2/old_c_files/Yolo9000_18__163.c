#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (8, f);
  T (32, c); T (1, f)]
*/
IND_TYPE c, cp_0, c960_p_0, cp_1, c960, f, fp_0, f1280_p_0, f1281_p_0, fp_1, f1280_p_1, fp_2, f1280, f1281, h, hp_0, x, xp_0, x960_p_0, xp_1, x960, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y640 = 0;
IND_TYPE x961 = 0;
IND_TYPE h440 = 0;
IND_TYPE w = 0;
IND_TYPE c961 = 0;
IND_TYPE f1282 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12604 ,mem_vec_12605 ,mem_vec_12606 ,mem_vec_12607 ,mem_vec_12608 ,mem_vec_12609 ,mem_vec_12610 ,mem_vec_12611 ,mem_vec_12612 ,mem_vec_12613 ,mem_vec_12614 ,mem_vec_12615 ,mem_vec_12616 ,mem_vec_12617 ,mem_vec_12618 ,mem_vec_12619 ,mem_vec_12620 ,mem_vec_12621 ,mem_vec_12622 ,mem_vec_12623 ,mem_vec_12624 ,mem_vec_12625 ,mem_vec_12626 ,mem_vec_12627 ,mem_vec_12628 ,mem_vec_12629 ,mem_vec_12630 ,mem_vec_12631 ,mem_vec_12632 ,mem_vec_12633 ,mem_vec_12634 ,mem_vec_12635 ,mem_vec_12636 ,mem_vec_12637 ,mem_vec_12638 ,mem_vec_12639 ,mem_vec_12640 ,mem_vec_12641 ,mem_vec_12642 ,mem_vec_12643 ,mem_vec_12644 ,mem_vec_12645 ,mem_vec_12646 ,mem_vec_12647 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f1281 = f1282, f1281_p_0 = 0;
	f1281 < f1282 + 1024;
	f1281 += 1024, f1281_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 32) (512 / 16)
	for (c960 = c961, c960_p_0 = 0;
		c960 < c961 + 512;
		c960 += 16, c960_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 1024
		// T (f, 8) (1024 / 128)
		for (f1280 = f1281, f1280_p_1 = f1281_p_0, f1280_p_0 = 0;
			f1280 < f1281 + 1024;
			f1280 += 128, f1280_p_1 += 128, f1280_p_0 += 128){
				for (y = y640, yp_0 = 0;
					y < y640 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 128
					// T (x, 17) (17 / 1)
					for (x960 = x961, x960_p_0 = 0;
						x960 < x961 + 17;
						x960 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h440, hp_0 = 0;
								h < h440 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x960, xp_1 = x960_p_0, xp_0 = 0;
									x < x960 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12604 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12605 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12606 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12607 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
												c < c960 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12604);
												mem_vec_12604 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12605);
												mem_vec_12605 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12606);
												mem_vec_12606 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12607);
												mem_vec_12607 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12608);
												mem_vec_12608 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12609);
												mem_vec_12609 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12610);
												mem_vec_12610 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12611);
												mem_vec_12611 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12612);
												mem_vec_12612 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12613);
												mem_vec_12613 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12614);
												mem_vec_12614 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12615);
												mem_vec_12615 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12616);
												mem_vec_12616 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12617);
												mem_vec_12617 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12618);
												mem_vec_12618 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12619);
												mem_vec_12619 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12620);
												mem_vec_12620 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12621);
												mem_vec_12621 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12622);
												mem_vec_12622 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12623);
												mem_vec_12623 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12604);
												mem_vec_12604 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_12605);
												mem_vec_12605 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_12606);
												mem_vec_12606 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_12607);
												mem_vec_12607 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_12608);
												mem_vec_12608 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_12609);
												mem_vec_12609 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_12610);
												mem_vec_12610 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_12611);
												mem_vec_12611 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_12612);
												mem_vec_12612 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_12613);
												mem_vec_12613 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_12614);
												mem_vec_12614 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_12615);
												mem_vec_12615 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_12616);
												mem_vec_12616 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_12617);
												mem_vec_12617 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_12618);
												mem_vec_12618 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_12619);
												mem_vec_12619 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_12620);
												mem_vec_12620 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_12621);
												mem_vec_12621 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_12622);
												mem_vec_12622 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_12623);
												mem_vec_12623 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12604);
												mem_vec_12604 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_12605);
												mem_vec_12605 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_12606);
												mem_vec_12606 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_12607);
												mem_vec_12607 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_12608);
												mem_vec_12608 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_12609);
												mem_vec_12609 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_12610);
												mem_vec_12610 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_12611);
												mem_vec_12611 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_12612);
												mem_vec_12612 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_12613);
												mem_vec_12613 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_12614);
												mem_vec_12614 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_12615);
												mem_vec_12615 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_12616);
												mem_vec_12616 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_12617);
												mem_vec_12617 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_12618);
												mem_vec_12618 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_12619);
												mem_vec_12619 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_12620);
												mem_vec_12620 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_12621);
												mem_vec_12621 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_12622);
												mem_vec_12622 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_12623);
												mem_vec_12623 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12604);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12605);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12606);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12607);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12608);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12609);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12610);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12611);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12612);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12613);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12614);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12615);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12616);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12617);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12618);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12619);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12620);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12621);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12622);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12623);
								}
							}
						}
					}
				}
				for (y = y640 + 5, yp_0 = 0;
					y < y640 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 128
					// T (x, 17) (17 / 1)
					for (x960 = x961, x960_p_0 = 0;
						x960 < x961 + 17;
						x960 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h440, hp_0 = 0;
								h < h440 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x960, xp_1 = x960_p_0, xp_0 = 0;
									x < x960 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12624 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12625 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_12644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_12645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_12646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_12647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
												c < c960 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12624);
												mem_vec_12624 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12625);
												mem_vec_12625 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12626);
												mem_vec_12626 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12627);
												mem_vec_12627 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12628);
												mem_vec_12628 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12629);
												mem_vec_12629 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12630);
												mem_vec_12630 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12631);
												mem_vec_12631 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12632);
												mem_vec_12632 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12633);
												mem_vec_12633 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12634);
												mem_vec_12634 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12635);
												mem_vec_12635 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12636);
												mem_vec_12636 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12637);
												mem_vec_12637 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12638);
												mem_vec_12638 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12639);
												mem_vec_12639 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12640);
												mem_vec_12640 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12641);
												mem_vec_12641 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12642);
												mem_vec_12642 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12643);
												mem_vec_12643 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12644);
												mem_vec_12644 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12645);
												mem_vec_12645 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12646);
												mem_vec_12646 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12647);
												mem_vec_12647 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_12624);
												mem_vec_12624 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_12625);
												mem_vec_12625 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_12626);
												mem_vec_12626 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_12627);
												mem_vec_12627 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_12628);
												mem_vec_12628 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_12629);
												mem_vec_12629 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_12630);
												mem_vec_12630 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_12631);
												mem_vec_12631 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_12632);
												mem_vec_12632 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_12633);
												mem_vec_12633 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_12634);
												mem_vec_12634 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_12635);
												mem_vec_12635 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_12636);
												mem_vec_12636 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_12637);
												mem_vec_12637 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_12638);
												mem_vec_12638 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_12639);
												mem_vec_12639 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_12640);
												mem_vec_12640 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_12641);
												mem_vec_12641 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_12642);
												mem_vec_12642 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_12643);
												mem_vec_12643 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_12644);
												mem_vec_12644 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_12645);
												mem_vec_12645 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_12646);
												mem_vec_12646 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_12647);
												mem_vec_12647 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_12624);
												mem_vec_12624 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_12625);
												mem_vec_12625 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_12626);
												mem_vec_12626 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_12627);
												mem_vec_12627 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_12628);
												mem_vec_12628 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_12629);
												mem_vec_12629 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_12630);
												mem_vec_12630 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_12631);
												mem_vec_12631 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_12632);
												mem_vec_12632 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_12633);
												mem_vec_12633 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_12634);
												mem_vec_12634 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_12635);
												mem_vec_12635 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_12636);
												mem_vec_12636 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_12637);
												mem_vec_12637 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_12638);
												mem_vec_12638 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_12639);
												mem_vec_12639 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_12640);
												mem_vec_12640 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_12641);
												mem_vec_12641 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_12642);
												mem_vec_12642 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_12643);
												mem_vec_12643 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_12644);
												mem_vec_12644 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_12645);
												mem_vec_12645 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_12646);
												mem_vec_12646 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_12647);
												mem_vec_12647 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12624);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12625);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12626);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12627);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12628);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12629);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12630);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12631);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12632);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12633);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12634);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12635);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12636);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12637);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12638);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12639);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12640);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12641);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12642);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12643);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12644);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12645);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12646);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12647);
								}
							}
						}
					}
				}
		}
	}
}


}