#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (4, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c339_p_0, cp_1, c339, f, fp_0, f437_p_0, f438_p_0, fp_1, f437_p_1, fp_2, f437, f438, h, hp_0, x, xp_0, x340_p_0, xp_1, x340, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y232 = 0;
IND_TYPE x341 = 0;
IND_TYPE h157 = 0;
IND_TYPE w = 0;
IND_TYPE c340 = 0;
IND_TYPE f439 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4520 ,mem_vec_4521 ,mem_vec_4522 ,mem_vec_4523 ,mem_vec_4524 ,mem_vec_4525 ,mem_vec_4526 ,mem_vec_4527 ,mem_vec_4528 ,mem_vec_4529 ,mem_vec_4530 ,mem_vec_4531 ,mem_vec_4532 ,mem_vec_4533 ,mem_vec_4534 ,mem_vec_4535 ,mem_vec_4536 ,mem_vec_4537 ,mem_vec_4538 ,mem_vec_4539 ,mem_vec_4540 ,mem_vec_4541 ,mem_vec_4542 ,mem_vec_4543 ,mem_vec_4544 ,mem_vec_4545 ,mem_vec_4546 ,mem_vec_4547 ,mem_vec_4548 ,mem_vec_4549 ,mem_vec_4550 ,mem_vec_4551 ,mem_vec_4552 ,mem_vec_4553 ,mem_vec_4554 ,mem_vec_4555 ,mem_vec_4556 ,mem_vec_4557 ,mem_vec_4558 ,mem_vec_4559 ,mem_vec_4560 ,mem_vec_4561 ,mem_vec_4562 ,mem_vec_4563 ,mem_vec_4564 ,mem_vec_4565 ,mem_vec_4566 ,mem_vec_4567 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f438 = f439, f438_p_0 = 0;
	f438 < f439 + 64;
	f438 += 64, f438_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f437 = f438, f437_p_1 = f438_p_0, f437_p_0 = 0;
		f437 < f438 + 64;
		f437 += 32, f437_p_1 += 32, f437_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 4) (56 / 14)
		for (x340 = x341, x340_p_0 = 0;
			x340 < x341 + 56;
			x340 += 14, x340_p_0 += 14){
				for (y = y232, yp_0 = 0;
					y < y232 + 35;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f437, fp_2 = f437_p_1, fp_1 = f437_p_0, fp_0 = 0;
						f < f437 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c339 = c340, c339_p_0 = 0;
							c339 < c340 + 64;
							c339 += 32, c339_p_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h157, hp_0 = 0;
								h < h157 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x340, xp_1 = x340_p_0, xp_0 = 0;
									x < x340 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4520 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4521 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4522 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4523 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_4536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_4538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c339, cp_1 = c339_p_0, cp_0 = 0;
												c < c339 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4520);
												mem_vec_4520 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4521);
												mem_vec_4521 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4522);
												mem_vec_4522 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4523);
												mem_vec_4523 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4524);
												mem_vec_4524 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4525);
												mem_vec_4525 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4526);
												mem_vec_4526 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4527);
												mem_vec_4527 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4528);
												mem_vec_4528 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4529);
												mem_vec_4529 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4530);
												mem_vec_4530 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4531);
												mem_vec_4531 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4532);
												mem_vec_4532 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4533);
												mem_vec_4533 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4534);
												mem_vec_4534 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4535);
												mem_vec_4535 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4536);
												mem_vec_4536 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4537);
												mem_vec_4537 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4538);
												mem_vec_4538 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4539);
												mem_vec_4539 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_4520);
												mem_vec_4520 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_4521);
												mem_vec_4521 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_4522);
												mem_vec_4522 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_4523);
												mem_vec_4523 = vec_36;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_4524);
												mem_vec_4524 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_4525);
												mem_vec_4525 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_4526);
												mem_vec_4526 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_4527);
												mem_vec_4527 = vec_42;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_4528);
												mem_vec_4528 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_4529);
												mem_vec_4529 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_4530);
												mem_vec_4530 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_4531);
												mem_vec_4531 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_4532);
												mem_vec_4532 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_4533);
												mem_vec_4533 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_4534);
												mem_vec_4534 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_4535);
												mem_vec_4535 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_4536);
												mem_vec_4536 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_4537);
												mem_vec_4537 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_4538);
												mem_vec_4538 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_4539);
												mem_vec_4539 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_4520);
												mem_vec_4520 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_4521);
												mem_vec_4521 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_4522);
												mem_vec_4522 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_4523);
												mem_vec_4523 = vec_65;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_4524);
												mem_vec_4524 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_4525);
												mem_vec_4525 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_4526);
												mem_vec_4526 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_4527);
												mem_vec_4527 = vec_71;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_4528);
												mem_vec_4528 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_4529);
												mem_vec_4529 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_4530);
												mem_vec_4530 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_4531);
												mem_vec_4531 = vec_76;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_4532);
												mem_vec_4532 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_4533);
												mem_vec_4533 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_4534);
												mem_vec_4534 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_4535);
												mem_vec_4535 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_4536);
												mem_vec_4536 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_4537);
												mem_vec_4537 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_4538);
												mem_vec_4538 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_4539);
												mem_vec_4539 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4535);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4536);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4537);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4538);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4539);
								}
							}
						}
					}
				}
				for (y = y232 + 35, yp_0 = 0;
					y < y232 + 35 + 21;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f437, fp_2 = f437_p_1, fp_1 = f437_p_0, fp_0 = 0;
						f < f437 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c339 = c340, c339_p_0 = 0;
							c339 < c340 + 64;
							c339 += 32, c339_p_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h157, hp_0 = 0;
								h < h157 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x340, xp_1 = x340_p_0, xp_0 = 0;
									x < x340 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4540 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4541 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4542 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4543 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_4548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_4552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_4556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_4558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_4560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_4562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_4564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_4566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c339, cp_1 = c339_p_0, cp_0 = 0;
												c < c339 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4540);
												mem_vec_4540 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4541);
												mem_vec_4541 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4542);
												mem_vec_4542 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4543);
												mem_vec_4543 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4544);
												mem_vec_4544 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4545);
												mem_vec_4545 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4546);
												mem_vec_4546 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4547);
												mem_vec_4547 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4548);
												mem_vec_4548 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4549);
												mem_vec_4549 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4550);
												mem_vec_4550 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4551);
												mem_vec_4551 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4552);
												mem_vec_4552 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4553);
												mem_vec_4553 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4554);
												mem_vec_4554 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4555);
												mem_vec_4555 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4556);
												mem_vec_4556 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4557);
												mem_vec_4557 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4558);
												mem_vec_4558 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4559);
												mem_vec_4559 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4560);
												mem_vec_4560 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4561);
												mem_vec_4561 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_4562);
												mem_vec_4562 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_4563);
												mem_vec_4563 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_4564);
												mem_vec_4564 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_4565);
												mem_vec_4565 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_4566);
												mem_vec_4566 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_4567);
												mem_vec_4567 = vec_38;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_4540);
												mem_vec_4540 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_4541);
												mem_vec_4541 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_4542);
												mem_vec_4542 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_4543);
												mem_vec_4543 = vec_46;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_4544);
												mem_vec_4544 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_4545);
												mem_vec_4545 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_4546);
												mem_vec_4546 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_4547);
												mem_vec_4547 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_4548);
												mem_vec_4548 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_4549);
												mem_vec_4549 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_4550);
												mem_vec_4550 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_4551);
												mem_vec_4551 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_4552);
												mem_vec_4552 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_4553);
												mem_vec_4553 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_4554);
												mem_vec_4554 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_4555);
												mem_vec_4555 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_4556);
												mem_vec_4556 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_4557);
												mem_vec_4557 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_4558);
												mem_vec_4558 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_4559);
												mem_vec_4559 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_4560);
												mem_vec_4560 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_4561);
												mem_vec_4561 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_4562);
												mem_vec_4562 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_4563);
												mem_vec_4563 = vec_72;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_4564);
												mem_vec_4564 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_4565);
												mem_vec_4565 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_4566);
												mem_vec_4566 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_4567);
												mem_vec_4567 = vec_77;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_4540);
												mem_vec_4540 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_4541);
												mem_vec_4541 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_4542);
												mem_vec_4542 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_4543);
												mem_vec_4543 = vec_85;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_4544);
												mem_vec_4544 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_4545);
												mem_vec_4545 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_4546);
												mem_vec_4546 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_4547);
												mem_vec_4547 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_4548);
												mem_vec_4548 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_4549);
												mem_vec_4549 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_4550);
												mem_vec_4550 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_4551);
												mem_vec_4551 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_4552);
												mem_vec_4552 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_4553);
												mem_vec_4553 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_4554);
												mem_vec_4554 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_4555);
												mem_vec_4555 = vec_101;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_4556);
												mem_vec_4556 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_4557);
												mem_vec_4557 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_4558);
												mem_vec_4558 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_4559);
												mem_vec_4559 = vec_106;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_4560);
												mem_vec_4560 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_4561);
												mem_vec_4561 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_4562);
												mem_vec_4562 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_4563);
												mem_vec_4563 = vec_111;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_4564);
												mem_vec_4564 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_4565);
												mem_vec_4565 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_4566);
												mem_vec_4566 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_4567);
												mem_vec_4567 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4540);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4541);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4542);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4543);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4544);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4545);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4546);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4547);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4548);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4549);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4550);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4551);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4552);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4553);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4554);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4555);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4556);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4557);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4558);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4559);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4560);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_4561);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4562);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_4563);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4564);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_4565);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4566);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_4567);
								}
							}
						}
					}
				}
		}
	}
}


}