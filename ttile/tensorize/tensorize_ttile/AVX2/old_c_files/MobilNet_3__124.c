#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, c);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, x);
  T (2, f); T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c596_p_0, c597_p_0, cp_1, c596_p_1, cp_2, c596, c597, f, fp_0, f440_p_0, fp_1, f440, w, wp_0, x, xp_0, x447_p_0, xp_1, x447, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y298 = 0;
IND_TYPE x448 = 0;
IND_TYPE h = 0;
IND_TYPE w230 = 0;
IND_TYPE c598 = 0;
IND_TYPE f441 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6600 ,mem_vec_6601 ,mem_vec_6602 ,mem_vec_6603 ,mem_vec_6604 ,mem_vec_6605 ,mem_vec_6606 ,mem_vec_6607 ,mem_vec_6608 ,mem_vec_6609 ,mem_vec_6610 ,mem_vec_6611 ,mem_vec_6612 ,mem_vec_6613 ,mem_vec_6614 ,mem_vec_6615 ,mem_vec_6616 ,mem_vec_6617 ,mem_vec_6618 ,mem_vec_6619 ,mem_vec_6620 ,mem_vec_6621 ,mem_vec_6622 ,mem_vec_6623 ,mem_vec_6624 ,mem_vec_6625 ,mem_vec_6626 ,mem_vec_6627 ,mem_vec_6628 ,mem_vec_6629 ,mem_vec_6630 ,mem_vec_6631 ,mem_vec_6632 ,mem_vec_6633 ,mem_vec_6634 ,mem_vec_6635 ,mem_vec_6636 ,mem_vec_6637 ,mem_vec_6638 ,mem_vec_6639 ,mem_vec_6640 ,mem_vec_6641 ,mem_vec_6642 ,mem_vec_6643 ,mem_vec_6644 ,mem_vec_6645 ,mem_vec_6646 ,mem_vec_6647 ,mem_vec_6648 ,mem_vec_6649 ,mem_vec_6650 ,mem_vec_6651 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f440 = f441, f440_p_0 = 0;
	f440 < f441 + 128;
	f440 += 64, f440_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (c, 4) (128 / 32)
	for (c597 = c598, c597_p_0 = 0;
		c597 < c598 + 128;
		c597 += 32, c597_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 32, f = 64
		// T (f, 2) (64 / 32)
		for (f = f440, fp_1 = f440_p_0, fp_0 = 0;
			f < f440 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 32, f = 32
			// T (x, 8) (56 / 7)
			for (x447 = x448, x447_p_0 = 0;
				x447 < x448 + 56;
				x447 += 7, x447_p_0 += 7){
					for (y = y298, yp_0 = 0;
						y < y298 + 42;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (c, 1) (32 / 32)
						for (c596 = c597, c596_p_1 = c597_p_0, c596_p_0 = 0;
							c596 < c597 + 32;
							c596 += 32, c596_p_1 += 32, c596_p_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w230, wp_0 = 0;
								w < w230 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 32, f = 32
								// T (x, 7) (7 / 1)
								for (x = x447, xp_1 = x447_p_0, xp_0 = 0;
									x < x447 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6600 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6601 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6602 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6603 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_6620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c596, cp_2 = c596_p_1, cp_1 = c596_p_0, cp_0 = 0;
												c < c596 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6600);
												mem_vec_6600 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6601);
												mem_vec_6601 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6602);
												mem_vec_6602 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6603);
												mem_vec_6603 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6604);
												mem_vec_6604 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6605);
												mem_vec_6605 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6606);
												mem_vec_6606 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6607);
												mem_vec_6607 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6608);
												mem_vec_6608 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6609);
												mem_vec_6609 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6610);
												mem_vec_6610 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6611);
												mem_vec_6611 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6612);
												mem_vec_6612 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6613);
												mem_vec_6613 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6614);
												mem_vec_6614 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6615);
												mem_vec_6615 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6616);
												mem_vec_6616 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6617);
												mem_vec_6617 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6618);
												mem_vec_6618 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6619);
												mem_vec_6619 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6620);
												mem_vec_6620 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6621);
												mem_vec_6621 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6622);
												mem_vec_6622 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6623);
												mem_vec_6623 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_6600);
												mem_vec_6600 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_6601);
												mem_vec_6601 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_6602);
												mem_vec_6602 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_6603);
												mem_vec_6603 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6604);
												mem_vec_6604 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_6605);
												mem_vec_6605 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_6606);
												mem_vec_6606 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_6607);
												mem_vec_6607 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_6608);
												mem_vec_6608 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_6609);
												mem_vec_6609 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_6610);
												mem_vec_6610 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_6611);
												mem_vec_6611 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_6612);
												mem_vec_6612 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_6613);
												mem_vec_6613 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_6614);
												mem_vec_6614 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_6615);
												mem_vec_6615 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6616);
												mem_vec_6616 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_6617);
												mem_vec_6617 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_6618);
												mem_vec_6618 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_6619);
												mem_vec_6619 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_6620);
												mem_vec_6620 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_6621);
												mem_vec_6621 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_6622);
												mem_vec_6622 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_6623);
												mem_vec_6623 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_6600);
												mem_vec_6600 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_6601);
												mem_vec_6601 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_6602);
												mem_vec_6602 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_6603);
												mem_vec_6603 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_6604);
												mem_vec_6604 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_6605);
												mem_vec_6605 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_6606);
												mem_vec_6606 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_6607);
												mem_vec_6607 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_6608);
												mem_vec_6608 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_6609);
												mem_vec_6609 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_6610);
												mem_vec_6610 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_6611);
												mem_vec_6611 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_6612);
												mem_vec_6612 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_6613);
												mem_vec_6613 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_6614);
												mem_vec_6614 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_6615);
												mem_vec_6615 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_6616);
												mem_vec_6616 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_6617);
												mem_vec_6617 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_6618);
												mem_vec_6618 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_6619);
												mem_vec_6619 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_6620);
												mem_vec_6620 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_6621);
												mem_vec_6621 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_6622);
												mem_vec_6622 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_6623);
												mem_vec_6623 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6600);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6601);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6602);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6603);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6604);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6605);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6606);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6607);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6608);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6609);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6610);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6611);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6612);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6613);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6614);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6615);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6616);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6617);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6618);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6619);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6620);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6621);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6622);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6623);
								}
							}
						}
					}
					for (y = y298 + 42, yp_0 = 0;
						y < y298 + 42 + 14;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
						// T (c, 1) (32 / 32)
						for (c596 = c597, c596_p_1 = c597_p_0, c596_p_0 = 0;
							c596 < c597 + 32;
							c596 += 32, c596_p_1 += 32, c596_p_0 += 32){
							// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w230, wp_0 = 0;
								w < w230 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 32, f = 32
								// T (x, 7) (7 / 1)
								for (x = x447, xp_1 = x447_p_0, xp_0 = 0;
									x < x447 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6624 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6625 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_6644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_6648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c596, cp_2 = c596_p_1, cp_1 = c596_p_0, cp_0 = 0;
												c < c596 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6624);
												mem_vec_6624 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6625);
												mem_vec_6625 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6626);
												mem_vec_6626 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6627);
												mem_vec_6627 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6628);
												mem_vec_6628 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6629);
												mem_vec_6629 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6630);
												mem_vec_6630 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6631);
												mem_vec_6631 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6632);
												mem_vec_6632 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6633);
												mem_vec_6633 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6634);
												mem_vec_6634 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6635);
												mem_vec_6635 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6636);
												mem_vec_6636 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6637);
												mem_vec_6637 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6638);
												mem_vec_6638 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6639);
												mem_vec_6639 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6640);
												mem_vec_6640 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6641);
												mem_vec_6641 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6642);
												mem_vec_6642 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6643);
												mem_vec_6643 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6644);
												mem_vec_6644 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6645);
												mem_vec_6645 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6646);
												mem_vec_6646 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6647);
												mem_vec_6647 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6648);
												mem_vec_6648 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6649);
												mem_vec_6649 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6650);
												mem_vec_6650 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6651);
												mem_vec_6651 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6624);
												mem_vec_6624 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6625);
												mem_vec_6625 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6626);
												mem_vec_6626 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6627);
												mem_vec_6627 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6628);
												mem_vec_6628 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6629);
												mem_vec_6629 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6630);
												mem_vec_6630 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6631);
												mem_vec_6631 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6632);
												mem_vec_6632 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6633);
												mem_vec_6633 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6634);
												mem_vec_6634 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6635);
												mem_vec_6635 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6636);
												mem_vec_6636 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6637);
												mem_vec_6637 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6638);
												mem_vec_6638 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6639);
												mem_vec_6639 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6640);
												mem_vec_6640 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6641);
												mem_vec_6641 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6642);
												mem_vec_6642 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6643);
												mem_vec_6643 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6644);
												mem_vec_6644 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6645);
												mem_vec_6645 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6646);
												mem_vec_6646 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6647);
												mem_vec_6647 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6648);
												mem_vec_6648 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6649);
												mem_vec_6649 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6650);
												mem_vec_6650 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6651);
												mem_vec_6651 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6624);
												mem_vec_6624 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6625);
												mem_vec_6625 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6626);
												mem_vec_6626 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6627);
												mem_vec_6627 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6628);
												mem_vec_6628 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6629);
												mem_vec_6629 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6630);
												mem_vec_6630 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6631);
												mem_vec_6631 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6632);
												mem_vec_6632 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6633);
												mem_vec_6633 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6634);
												mem_vec_6634 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6635);
												mem_vec_6635 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6636);
												mem_vec_6636 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6637);
												mem_vec_6637 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6638);
												mem_vec_6638 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6639);
												mem_vec_6639 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6640);
												mem_vec_6640 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6641);
												mem_vec_6641 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6642);
												mem_vec_6642 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6643);
												mem_vec_6643 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6644);
												mem_vec_6644 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6645);
												mem_vec_6645 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6646);
												mem_vec_6646 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6647);
												mem_vec_6647 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6648);
												mem_vec_6648 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6649);
												mem_vec_6649 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6650);
												mem_vec_6650 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6651);
												mem_vec_6651 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6624);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6625);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6626);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6627);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6628);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6629);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6630);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6631);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6632);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6633);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6634);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6635);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6636);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6637);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6638);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6639);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6640);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6641);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6642);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6643);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6644);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6645);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6646);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6647);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6648);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6649);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6650);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6651);
								}
							}
						}
					}
			}
		}
	}
}


}