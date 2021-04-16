#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (56, x);
  T (1, f); T (2, c); T (4, f)]
*/
IND_TYPE c, cp_0, c484_p_0, c485_p_0, cp_1, c484_p_1, cp_2, c484, c485, f, fp_0, f359_p_0, fp_1, f359, w, wp_0, x, xp_0, x363_p_0, xp_1, x363, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y242 = 0;
IND_TYPE x364 = 0;
IND_TYPE h = 0;
IND_TYPE w190 = 0;
IND_TYPE c486 = 0;
IND_TYPE f360 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5572 ,mem_vec_5573 ,mem_vec_5574 ,mem_vec_5575 ,mem_vec_5576 ,mem_vec_5577 ,mem_vec_5578 ,mem_vec_5579 ,mem_vec_5580 ,mem_vec_5581 ,mem_vec_5582 ,mem_vec_5583 ,mem_vec_5584 ,mem_vec_5585 ,mem_vec_5586 ,mem_vec_5587 ,mem_vec_5588 ,mem_vec_5589 ,mem_vec_5590 ,mem_vec_5591 ,mem_vec_5592 ,mem_vec_5593 ,mem_vec_5594 ,mem_vec_5595 ,mem_vec_5596 ,mem_vec_5597 ,mem_vec_5598 ,mem_vec_5599 ,mem_vec_5600 ,mem_vec_5601 ,mem_vec_5602 ,mem_vec_5603 ,mem_vec_5604 ,mem_vec_5605 ,mem_vec_5606 ,mem_vec_5607 ,mem_vec_5608 ,mem_vec_5609 ,mem_vec_5610 ,mem_vec_5611 ,mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f359 = f360, f359_p_0 = 0;
	f359 < f360 + 128;
	f359 += 32, f359_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
	// T (c, 2) (128 / 64)
	for (c485 = c486, c485_p_0 = 0;
		c485 < c486 + 128;
		c485 += 64, c485_p_0 += 64){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (f, 1) (32 / 32)
		for (f = f359, fp_1 = f359_p_0, fp_0 = 0;
			f < f359 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
			// T (x, 56) (56 / 1)
			for (x363 = x364, x363_p_0 = 0;
				x363 < x364 + 56;
				x363 += 1, x363_p_0 += 1){
					for (y = y242, yp_0 = 0;
						y < y242 + 42;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c484 = c485, c484_p_1 = c485_p_0, c484_p_0 = 0;
							c484 < c485 + 64;
							c484 += 32, c484_p_1 += 32, c484_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w190, wp_0 = 0;
								w < w190 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x363, xp_1 = x363_p_0, xp_0 = 0;
									x < x363 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5572 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5573 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5574 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5575 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_5592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c484, cp_2 = c484_p_1, cp_1 = c484_p_0, cp_0 = 0;
												c < c484 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5572);
												mem_vec_5572 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5573);
												mem_vec_5573 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5574);
												mem_vec_5574 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5575);
												mem_vec_5575 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5576);
												mem_vec_5576 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5577);
												mem_vec_5577 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5578);
												mem_vec_5578 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5579);
												mem_vec_5579 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5580);
												mem_vec_5580 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5581);
												mem_vec_5581 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5582);
												mem_vec_5582 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5583);
												mem_vec_5583 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5584);
												mem_vec_5584 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5585);
												mem_vec_5585 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5586);
												mem_vec_5586 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5587);
												mem_vec_5587 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5588);
												mem_vec_5588 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5589);
												mem_vec_5589 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5590);
												mem_vec_5590 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5591);
												mem_vec_5591 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5592);
												mem_vec_5592 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5593);
												mem_vec_5593 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5594);
												mem_vec_5594 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5595);
												mem_vec_5595 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_5572);
												mem_vec_5572 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_5573);
												mem_vec_5573 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_5574);
												mem_vec_5574 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_5575);
												mem_vec_5575 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5576);
												mem_vec_5576 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_5577);
												mem_vec_5577 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_5578);
												mem_vec_5578 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_5579);
												mem_vec_5579 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_5580);
												mem_vec_5580 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_5581);
												mem_vec_5581 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_5582);
												mem_vec_5582 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_5583);
												mem_vec_5583 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_5584);
												mem_vec_5584 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_5585);
												mem_vec_5585 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_5586);
												mem_vec_5586 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_5587);
												mem_vec_5587 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5588);
												mem_vec_5588 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_5589);
												mem_vec_5589 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_5590);
												mem_vec_5590 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_5591);
												mem_vec_5591 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_5592);
												mem_vec_5592 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_5593);
												mem_vec_5593 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_5594);
												mem_vec_5594 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_5595);
												mem_vec_5595 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_5572);
												mem_vec_5572 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_5573);
												mem_vec_5573 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_5574);
												mem_vec_5574 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_5575);
												mem_vec_5575 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_5576);
												mem_vec_5576 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_5577);
												mem_vec_5577 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_5578);
												mem_vec_5578 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_5579);
												mem_vec_5579 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_5580);
												mem_vec_5580 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_5581);
												mem_vec_5581 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_5582);
												mem_vec_5582 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_5583);
												mem_vec_5583 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_5584);
												mem_vec_5584 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5585);
												mem_vec_5585 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5586);
												mem_vec_5586 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5587);
												mem_vec_5587 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_5588);
												mem_vec_5588 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_5589);
												mem_vec_5589 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_5590);
												mem_vec_5590 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_5591);
												mem_vec_5591 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_5592);
												mem_vec_5592 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_5593);
												mem_vec_5593 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_5594);
												mem_vec_5594 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_5595);
												mem_vec_5595 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5572);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5573);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5574);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5575);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5576);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5577);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5578);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5579);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5580);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5581);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5582);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5583);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5584);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5585);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5586);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5587);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5588);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5589);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5590);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5591);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5592);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5593);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5594);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5595);
								}
							}
						}
					}
					for (y = y242 + 42, yp_0 = 0;
						y < y242 + 42 + 14;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c484 = c485, c484_p_1 = c485_p_0, c484_p_0 = 0;
							c484 < c485 + 64;
							c484 += 32, c484_p_1 += 32, c484_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w190, wp_0 = 0;
								w < w190 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x363, xp_1 = x363_p_0, xp_0 = 0;
									x < x363 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5596 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5597 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5598 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5599 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_5616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_5618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_5620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_5622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c484, cp_2 = c484_p_1, cp_1 = c484_p_0, cp_0 = 0;
												c < c484 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5596);
												mem_vec_5596 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5597);
												mem_vec_5597 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5598);
												mem_vec_5598 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5599);
												mem_vec_5599 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5600);
												mem_vec_5600 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5601);
												mem_vec_5601 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5602);
												mem_vec_5602 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5603);
												mem_vec_5603 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5604);
												mem_vec_5604 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5605);
												mem_vec_5605 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5606);
												mem_vec_5606 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5607);
												mem_vec_5607 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5608);
												mem_vec_5608 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5609);
												mem_vec_5609 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5610);
												mem_vec_5610 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5611);
												mem_vec_5611 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5612);
												mem_vec_5612 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5613);
												mem_vec_5613 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5614);
												mem_vec_5614 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5615);
												mem_vec_5615 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5616);
												mem_vec_5616 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5617);
												mem_vec_5617 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5618);
												mem_vec_5618 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5619);
												mem_vec_5619 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_5620);
												mem_vec_5620 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_5621);
												mem_vec_5621 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_5622);
												mem_vec_5622 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_5623);
												mem_vec_5623 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_5596);
												mem_vec_5596 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_5597);
												mem_vec_5597 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_5598);
												mem_vec_5598 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_5599);
												mem_vec_5599 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_5600);
												mem_vec_5600 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_5601);
												mem_vec_5601 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_5602);
												mem_vec_5602 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_5603);
												mem_vec_5603 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_5604);
												mem_vec_5604 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_5605);
												mem_vec_5605 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_5606);
												mem_vec_5606 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_5607);
												mem_vec_5607 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_5608);
												mem_vec_5608 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_5609);
												mem_vec_5609 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_5610);
												mem_vec_5610 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_5611);
												mem_vec_5611 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_5612);
												mem_vec_5612 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_5613);
												mem_vec_5613 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_5614);
												mem_vec_5614 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_5615);
												mem_vec_5615 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_5616);
												mem_vec_5616 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_5617);
												mem_vec_5617 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_5618);
												mem_vec_5618 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_5619);
												mem_vec_5619 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_5620);
												mem_vec_5620 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_5621);
												mem_vec_5621 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_5622);
												mem_vec_5622 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_5623);
												mem_vec_5623 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_5596);
												mem_vec_5596 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_5597);
												mem_vec_5597 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_5598);
												mem_vec_5598 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_5599);
												mem_vec_5599 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_5600);
												mem_vec_5600 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_5601);
												mem_vec_5601 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_5602);
												mem_vec_5602 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_5603);
												mem_vec_5603 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_5604);
												mem_vec_5604 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_5605);
												mem_vec_5605 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_5606);
												mem_vec_5606 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_5607);
												mem_vec_5607 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_5608);
												mem_vec_5608 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_5609);
												mem_vec_5609 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_5610);
												mem_vec_5610 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_5611);
												mem_vec_5611 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_5612);
												mem_vec_5612 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_5613);
												mem_vec_5613 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_5614);
												mem_vec_5614 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_5615);
												mem_vec_5615 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_5616);
												mem_vec_5616 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_5617);
												mem_vec_5617 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_5618);
												mem_vec_5618 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_5619);
												mem_vec_5619 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_5620);
												mem_vec_5620 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_5621);
												mem_vec_5621 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_5622);
												mem_vec_5622 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_5623);
												mem_vec_5623 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5596);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5597);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5598);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5599);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5600);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5601);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5602);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5603);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5604);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5605);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5606);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5607);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5608);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5609);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5610);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5611);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5612);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5613);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5614);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5615);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5616);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5617);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5618);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5619);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5620);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5621);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5622);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_5623);
								}
							}
						}
					}
			}
		}
	}
}


}