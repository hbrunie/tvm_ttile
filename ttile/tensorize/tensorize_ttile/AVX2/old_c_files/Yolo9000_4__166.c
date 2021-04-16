#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (1, c); T (2, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (17, x)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, w, wp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0, y39_p_0, yp_1, y39;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y40 = 0;
IND_TYPE x66 = 0;
IND_TYPE h = 0;
IND_TYPE w29 = 0;
IND_TYPE c49 = 0;
IND_TYPE f41 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,mem_vec_516 ,mem_vec_517 ,mem_vec_518 ,mem_vec_519 ,mem_vec_520 ,mem_vec_521 ,mem_vec_522 ,mem_vec_523 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 17) (136 / 8)
for (x65 = x66, x65_p_0 = 0;
	x65 < x66 + 136;
	x65 += 8, x65_p_0 += 8){
		for (y39 = y40, y39_p_0 = 0;
			y39 < y40 + 110;
			y39 += 22, y39_p_0 += 22){
			// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (8 / 8)
			for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
				x64 < x65 + 8;
				x64 += 8, x64_p_1 += 8, x64_p_0 += 8){
				// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f41, fp_0 = 0;
					f < f41 + 128;
					f += 16, fp_0 += 16){
					// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
					// T (y, 2) (2 * ph_y / ph_y)
					for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
						y < y39 + 22;
						y += 11, yp_1 += 11, yp_0 += 11){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 1) (64 / 64)
						for (c48 = c49, c48_p_0 = 0;
							c48 < c49 + 64;
							c48 += 64, c48_p_0 += 64){
							// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
							// T (w, 3) (3 / 1)
							for (w = w29, wp_0 = 0;
								w < w29 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 64, f = 16
								// T (x, 8) (8 / 1)
								for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
									x < x64 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_476 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_477 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
											// T (c, 64) (64 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_476);
												mem_vec_476 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_477);
												mem_vec_477 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_478);
												mem_vec_478 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_479);
												mem_vec_479 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_480);
												mem_vec_480 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_481);
												mem_vec_481 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_482);
												mem_vec_482 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_483);
												mem_vec_483 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_484);
												mem_vec_484 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_485);
												mem_vec_485 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_486);
												mem_vec_486 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_487);
												mem_vec_487 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_488);
												mem_vec_488 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_489);
												mem_vec_489 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_490);
												mem_vec_490 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_491);
												mem_vec_491 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_492);
												mem_vec_492 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_493);
												mem_vec_493 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_494);
												mem_vec_494 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_495);
												mem_vec_495 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_496);
												mem_vec_496 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_497);
												mem_vec_497 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_476);
												mem_vec_476 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_477);
												mem_vec_477 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_478);
												mem_vec_478 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_479);
												mem_vec_479 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_480);
												mem_vec_480 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_481);
												mem_vec_481 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_482);
												mem_vec_482 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_483);
												mem_vec_483 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_484);
												mem_vec_484 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_485);
												mem_vec_485 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_486);
												mem_vec_486 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_487);
												mem_vec_487 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_488);
												mem_vec_488 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_489);
												mem_vec_489 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_490);
												mem_vec_490 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_491);
												mem_vec_491 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_492);
												mem_vec_492 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_493);
												mem_vec_493 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_494);
												mem_vec_494 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_495);
												mem_vec_495 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_496);
												mem_vec_496 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_497);
												mem_vec_497 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_476);
												mem_vec_476 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_477);
												mem_vec_477 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_478);
												mem_vec_478 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_479);
												mem_vec_479 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_480);
												mem_vec_480 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_481);
												mem_vec_481 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_482);
												mem_vec_482 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_483);
												mem_vec_483 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_484);
												mem_vec_484 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_485);
												mem_vec_485 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_486);
												mem_vec_486 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_487);
												mem_vec_487 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_488);
												mem_vec_488 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_489);
												mem_vec_489 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_490);
												mem_vec_490 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_491);
												mem_vec_491 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_492);
												mem_vec_492 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_493);
												mem_vec_493 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_494);
												mem_vec_494 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_495);
												mem_vec_495 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_496);
												mem_vec_496 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_497);
												mem_vec_497 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_479);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_480);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_481);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_482);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_483);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_484);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_485);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_486);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_487);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_488);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_489);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_490);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_491);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_497);
								}
							}
						}
					}
				}
			}
		}
		for (y39 = y40 + 110, y39_p_0 = 0;
			y39 < y40 + 110 + 26;
			y39 += 26, y39_p_0 += 26){
			// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (8 / 8)
			for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
				x64 < x65 + 8;
				x64 += 8, x64_p_1 += 8, x64_p_0 += 8){
				// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f41, fp_0 = 0;
					f < f41 + 128;
					f += 16, fp_0 += 16){
					// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
					// T (y, 2) (2 * ph_y / ph_y)
					for (y = y39, yp_1 = y39_p_0, yp_0 = 0;
						y < y39 + 26;
						y += 13, yp_1 += 13, yp_0 += 13){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 1) (64 / 64)
						for (c48 = c49, c48_p_0 = 0;
							c48 < c49 + 64;
							c48 += 64, c48_p_0 += 64){
							// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
							// T (w, 3) (3 / 1)
							for (w = w29, wp_0 = 0;
								w < w29 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 64, f = 16
								// T (x, 8) (8 / 1)
								for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
									x < x64 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_498 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_499 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											mem_vec_522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
											// T (c, 64) (64 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_498);
												mem_vec_498 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_499);
												mem_vec_499 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_500);
												mem_vec_500 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_501);
												mem_vec_501 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_502);
												mem_vec_502 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_503);
												mem_vec_503 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_504);
												mem_vec_504 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_505);
												mem_vec_505 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_506);
												mem_vec_506 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_507);
												mem_vec_507 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_508);
												mem_vec_508 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_509);
												mem_vec_509 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_510);
												mem_vec_510 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_511);
												mem_vec_511 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_512);
												mem_vec_512 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_513);
												mem_vec_513 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_514);
												mem_vec_514 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_515);
												mem_vec_515 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_516);
												mem_vec_516 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_517);
												mem_vec_517 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_518);
												mem_vec_518 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_519);
												mem_vec_519 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_520);
												mem_vec_520 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_521);
												mem_vec_521 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm256_set1_ps(scal_12);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_522);
												mem_vec_522 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_523);
												mem_vec_523 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_42 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_498);
												mem_vec_498 = vec_41;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_499);
												mem_vec_499 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_500);
												mem_vec_500 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_501);
												mem_vec_501 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_502);
												mem_vec_502 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_503);
												mem_vec_503 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_504);
												mem_vec_504 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_505);
												mem_vec_505 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_506);
												mem_vec_506 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_507);
												mem_vec_507 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_508);
												mem_vec_508 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_509);
												mem_vec_509 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_510);
												mem_vec_510 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_511);
												mem_vec_511 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_512);
												mem_vec_512 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_513);
												mem_vec_513 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_514);
												mem_vec_514 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_515);
												mem_vec_515 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_516);
												mem_vec_516 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_517);
												mem_vec_517 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_518);
												mem_vec_518 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_519);
												mem_vec_519 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_77 = _mm256_set1_ps(scal_24);


												vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_520);
												mem_vec_520 = vec_76;



												vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_521);
												mem_vec_521 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_80 = _mm256_set1_ps(scal_25);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_522);
												mem_vec_522 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_523);
												mem_vec_523 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_498);
												mem_vec_498 = vec_82;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_499);
												mem_vec_499 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_500);
												mem_vec_500 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_501);
												mem_vec_501 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_502);
												mem_vec_502 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_503);
												mem_vec_503 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_504);
												mem_vec_504 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_505);
												mem_vec_505 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_506);
												mem_vec_506 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_507);
												mem_vec_507 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_508);
												mem_vec_508 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_509);
												mem_vec_509 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_510);
												mem_vec_510 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_511);
												mem_vec_511 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_512);
												mem_vec_512 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_513);
												mem_vec_513 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_514);
												mem_vec_514 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_515);
												mem_vec_515 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_516);
												mem_vec_516 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_517);
												mem_vec_517 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_115 = _mm256_set1_ps(scal_36);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_518);
												mem_vec_518 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_519);
												mem_vec_519 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_118 = _mm256_set1_ps(scal_37);


												vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_520);
												mem_vec_520 = vec_117;



												vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_521);
												mem_vec_521 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_121 = _mm256_set1_ps(scal_38);


												vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_522);
												mem_vec_522 = vec_120;



												vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_523);
												mem_vec_523 = vec_122;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_523);
								}
							}
						}
					}
				}
			}
		}
}


}