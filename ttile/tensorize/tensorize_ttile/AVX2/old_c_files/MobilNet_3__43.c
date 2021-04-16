#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (8, c);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (28, x);
  T (4, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c228_p_0, c229_p_0, cp_1, c228_p_1, cp_2, c228, c229, f, fp_0, f167_p_0, fp_1, f167, h, hp_0, x, xp_0, x171_p_0, xp_1, x171, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y114 = 0;
IND_TYPE x172 = 0;
IND_TYPE h78 = 0;
IND_TYPE w = 0;
IND_TYPE c230 = 0;
IND_TYPE f168 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2492 ,mem_vec_2493 ,mem_vec_2494 ,mem_vec_2495 ,mem_vec_2496 ,mem_vec_2497 ,mem_vec_2498 ,mem_vec_2499 ,mem_vec_2500 ,mem_vec_2501 ,mem_vec_2502 ,mem_vec_2503 ,mem_vec_2504 ,mem_vec_2505 ,mem_vec_2506 ,mem_vec_2507 ,mem_vec_2508 ,mem_vec_2509 ,mem_vec_2510 ,mem_vec_2511 ,mem_vec_2512 ,mem_vec_2513 ,mem_vec_2514 ,mem_vec_2515 ,mem_vec_2516 ,mem_vec_2517 ,mem_vec_2518 ,mem_vec_2519 ,mem_vec_2520 ,mem_vec_2521 ,mem_vec_2522 ,mem_vec_2523 ,mem_vec_2524 ,mem_vec_2525 ,mem_vec_2526 ,mem_vec_2527 ,mem_vec_2528 ,mem_vec_2529 ,mem_vec_2530 ,mem_vec_2531 ,mem_vec_2532 ,mem_vec_2533 ,mem_vec_2534 ,mem_vec_2535 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f167 = f168, f167_p_0 = 0;
	f167 < f168 + 128;
	f167 += 128, f167_p_0 += 128){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c229 = c230, c229_p_0 = 0;
		c229 < c230 + 128;
		c229 += 64, c229_p_0 += 64){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f167, fp_1 = f167_p_0, fp_0 = 0;
			f < f167 + 128;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
			// T (x, 28) (56 / 2)
			for (x171 = x172, x171_p_0 = 0;
				x171 < x172 + 56;
				x171 += 2, x171_p_0 += 2){
					for (y = y114, yp_0 = 0;
						y < y114 + 28;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (c, 8) (64 / 8)
						for (c228 = c229, c228_p_1 = c229_p_0, c228_p_0 = 0;
							c228 < c229 + 64;
							c228 += 8, c228_p_1 += 8, c228_p_0 += 8){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h78, hp_0 = 0;
								h < h78 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x171, xp_1 = x171_p_0, xp_0 = 0;
									x < x171 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2492 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2493 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2494 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2495 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c228, cp_2 = c228_p_1, cp_1 = c228_p_0, cp_0 = 0;
												c < c228 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2492);
												mem_vec_2492 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2493);
												mem_vec_2493 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2494);
												mem_vec_2494 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2495);
												mem_vec_2495 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2496);
												mem_vec_2496 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2497);
												mem_vec_2497 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2498);
												mem_vec_2498 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2499);
												mem_vec_2499 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2500);
												mem_vec_2500 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2501);
												mem_vec_2501 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2502);
												mem_vec_2502 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2503);
												mem_vec_2503 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2504);
												mem_vec_2504 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2505);
												mem_vec_2505 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2506);
												mem_vec_2506 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2507);
												mem_vec_2507 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_2492);
												mem_vec_2492 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_2493);
												mem_vec_2493 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_2494);
												mem_vec_2494 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_2495);
												mem_vec_2495 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_2496);
												mem_vec_2496 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_2497);
												mem_vec_2497 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_2498);
												mem_vec_2498 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_2499);
												mem_vec_2499 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_2500);
												mem_vec_2500 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_2501);
												mem_vec_2501 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_2502);
												mem_vec_2502 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_2503);
												mem_vec_2503 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_2504);
												mem_vec_2504 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2505);
												mem_vec_2505 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2506);
												mem_vec_2506 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_2507);
												mem_vec_2507 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_2492);
												mem_vec_2492 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_2493);
												mem_vec_2493 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_2494);
												mem_vec_2494 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_2495);
												mem_vec_2495 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_2496);
												mem_vec_2496 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_2497);
												mem_vec_2497 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2498);
												mem_vec_2498 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2499);
												mem_vec_2499 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_2500);
												mem_vec_2500 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_2501);
												mem_vec_2501 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_2502);
												mem_vec_2502 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_2503);
												mem_vec_2503 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_2504);
												mem_vec_2504 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_2505);
												mem_vec_2505 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_2506);
												mem_vec_2506 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_2507);
												mem_vec_2507 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2507);
								}
							}
						}
					}
					for (y = y114 + 28, yp_0 = 0;
						y < y114 + 28 + 28;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (c, 8) (64 / 8)
						for (c228 = c229, c228_p_1 = c229_p_0, c228_p_0 = 0;
							c228 < c229 + 64;
							c228 += 8, c228_p_1 += 8, c228_p_0 += 8){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
							// T (h, 3) (3 / 1)
							for (h = h78, hp_0 = 0;
								h < h78 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x171, xp_1 = x171_p_0, xp_0 = 0;
									x < x171 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2508 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2509 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2510 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2511 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_2524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_2528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_2532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c228, cp_2 = c228_p_1, cp_1 = c228_p_0, cp_0 = 0;
												c < c228 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2508);
												mem_vec_2508 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2509);
												mem_vec_2509 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2510);
												mem_vec_2510 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2511);
												mem_vec_2511 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2512);
												mem_vec_2512 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2513);
												mem_vec_2513 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2514);
												mem_vec_2514 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2515);
												mem_vec_2515 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2516);
												mem_vec_2516 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2517);
												mem_vec_2517 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2518);
												mem_vec_2518 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2519);
												mem_vec_2519 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2520);
												mem_vec_2520 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2521);
												mem_vec_2521 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2522);
												mem_vec_2522 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2523);
												mem_vec_2523 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2524);
												mem_vec_2524 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2525);
												mem_vec_2525 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2526);
												mem_vec_2526 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2527);
												mem_vec_2527 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2528);
												mem_vec_2528 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2529);
												mem_vec_2529 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_2530);
												mem_vec_2530 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_2531);
												mem_vec_2531 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_2532);
												mem_vec_2532 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_2533);
												mem_vec_2533 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_2534);
												mem_vec_2534 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_2535);
												mem_vec_2535 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_2508);
												mem_vec_2508 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_2509);
												mem_vec_2509 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_2510);
												mem_vec_2510 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_2511);
												mem_vec_2511 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_2512);
												mem_vec_2512 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_2513);
												mem_vec_2513 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_2514);
												mem_vec_2514 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_2515);
												mem_vec_2515 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_2516);
												mem_vec_2516 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_2517);
												mem_vec_2517 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_2518);
												mem_vec_2518 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_2519);
												mem_vec_2519 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_2520);
												mem_vec_2520 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_2521);
												mem_vec_2521 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_2522);
												mem_vec_2522 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_2523);
												mem_vec_2523 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_2524);
												mem_vec_2524 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_2525);
												mem_vec_2525 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_2526);
												mem_vec_2526 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_2527);
												mem_vec_2527 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_2528);
												mem_vec_2528 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_2529);
												mem_vec_2529 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_2530);
												mem_vec_2530 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_2531);
												mem_vec_2531 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_2532);
												mem_vec_2532 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_2533);
												mem_vec_2533 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_2534);
												mem_vec_2534 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_2535);
												mem_vec_2535 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_2508);
												mem_vec_2508 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_2509);
												mem_vec_2509 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_2510);
												mem_vec_2510 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_2511);
												mem_vec_2511 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_2512);
												mem_vec_2512 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_2513);
												mem_vec_2513 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_2514);
												mem_vec_2514 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_2515);
												mem_vec_2515 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_2516);
												mem_vec_2516 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_2517);
												mem_vec_2517 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_2518);
												mem_vec_2518 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_2519);
												mem_vec_2519 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_2520);
												mem_vec_2520 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_2521);
												mem_vec_2521 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_2522);
												mem_vec_2522 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_2523);
												mem_vec_2523 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_2524);
												mem_vec_2524 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_2525);
												mem_vec_2525 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_2526);
												mem_vec_2526 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_2527);
												mem_vec_2527 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_2528);
												mem_vec_2528 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_2529);
												mem_vec_2529 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_2530);
												mem_vec_2530 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_2531);
												mem_vec_2531 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_2532);
												mem_vec_2532 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_2533);
												mem_vec_2533 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_2534);
												mem_vec_2534 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_2535);
												mem_vec_2535 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_2531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_2535);
								}
							}
						}
					}
			}
		}
	}
}


}