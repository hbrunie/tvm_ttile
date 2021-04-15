#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (32, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (1, f);
  T (512, c); T (1, f)]
*/
IND_TYPE c, cp_0, c606_p_0, cp_1, c606, f, fp_0, f808_p_0, f809_p_0, fp_1, f808_p_1, fp_2, f808, f809, w, wp_0, x, xp_0, x606_p_0, xp_1, x606, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y404 = 0;
IND_TYPE x607 = 0;
IND_TYPE h = 0;
IND_TYPE w404 = 0;
IND_TYPE c607 = 0;
IND_TYPE f810 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7500 ,mem_vec_7501 ,mem_vec_7502 ,mem_vec_7503 ,mem_vec_7504 ,mem_vec_7505 ,mem_vec_7506 ,mem_vec_7507 ,mem_vec_7508 ,mem_vec_7509 ,mem_vec_7510 ,mem_vec_7511 ,mem_vec_7512 ,mem_vec_7513 ,mem_vec_7514 ,mem_vec_7515 ,mem_vec_7516 ,mem_vec_7517 ,mem_vec_7518 ,mem_vec_7519 ,mem_vec_7520 ,mem_vec_7521 ,mem_vec_7522 ,mem_vec_7523 ,mem_vec_7524 ,mem_vec_7525 ,mem_vec_7526 ,mem_vec_7527 ,mem_vec_7528 ,mem_vec_7529 ,mem_vec_7530 ,mem_vec_7531 ,mem_vec_7532 ,mem_vec_7533 ,mem_vec_7534 ,mem_vec_7535 ,mem_vec_7536 ,mem_vec_7537 ,mem_vec_7538 ,mem_vec_7539 ,mem_vec_7540 ,mem_vec_7541 ,mem_vec_7542 ,mem_vec_7543 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f809 = f810, f809_p_0 = 0;
	f809 < f810 + 1024;
	f809 += 1024, f809_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 512) (512 / 1)
	for (c606 = c607, c606_p_0 = 0;
		c606 < c607 + 512;
		c606 += 1, c606_p_0 += 1){
		// y = 17, x = 17, h = 3, w = 3, c = 1, f = 1024
		// T (f, 1) (1024 / 1024)
		for (f808 = f809, f808_p_1 = f809_p_0, f808_p_0 = 0;
			f808 < f809 + 1024;
			f808 += 1024, f808_p_1 += 1024, f808_p_0 += 1024){
				for (y = y404, yp_0 = 0;
					y < y404 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 1024
					// T (x, 17) (17 / 1)
					for (x606 = x607, x606_p_0 = 0;
						x606 < x607 + 17;
						x606 += 1, x606_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 1024
						// T (f, 32) (1024 / 32)
						for (f = f808, fp_2 = f808_p_1, fp_1 = f808_p_0, fp_0 = 0;
							f < f808 + 1024;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w404, wp_0 = 0;
								w < w404 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x606, xp_1 = x606_p_0, xp_0 = 0;
									x < x606 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7500 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7501 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7502 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7503 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c606, cp_1 = c606_p_0, cp_0 = 0;
												c < c606 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7500);
												mem_vec_7500 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7501);
												mem_vec_7501 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7502);
												mem_vec_7502 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7503);
												mem_vec_7503 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7504);
												mem_vec_7504 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7505);
												mem_vec_7505 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7506);
												mem_vec_7506 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7507);
												mem_vec_7507 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7508);
												mem_vec_7508 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7509);
												mem_vec_7509 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7510);
												mem_vec_7510 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7511);
												mem_vec_7511 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7512);
												mem_vec_7512 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7513);
												mem_vec_7513 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7514);
												mem_vec_7514 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7515);
												mem_vec_7515 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7516);
												mem_vec_7516 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7517);
												mem_vec_7517 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7518);
												mem_vec_7518 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7519);
												mem_vec_7519 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_7500);
												mem_vec_7500 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_7501);
												mem_vec_7501 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_7502);
												mem_vec_7502 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_7503);
												mem_vec_7503 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_7504);
												mem_vec_7504 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_7505);
												mem_vec_7505 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_7506);
												mem_vec_7506 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_7507);
												mem_vec_7507 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_7508);
												mem_vec_7508 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_7509);
												mem_vec_7509 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_7510);
												mem_vec_7510 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_7511);
												mem_vec_7511 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_7512);
												mem_vec_7512 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_7513);
												mem_vec_7513 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_7514);
												mem_vec_7514 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_7515);
												mem_vec_7515 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_7516);
												mem_vec_7516 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_7517);
												mem_vec_7517 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_7518);
												mem_vec_7518 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_7519);
												mem_vec_7519 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_7500);
												mem_vec_7500 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_7501);
												mem_vec_7501 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_7502);
												mem_vec_7502 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_7503);
												mem_vec_7503 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_7504);
												mem_vec_7504 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_7505);
												mem_vec_7505 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_7506);
												mem_vec_7506 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_7507);
												mem_vec_7507 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_7508);
												mem_vec_7508 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_7509);
												mem_vec_7509 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_7510);
												mem_vec_7510 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_7511);
												mem_vec_7511 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_7512);
												mem_vec_7512 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_7513);
												mem_vec_7513 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_7514);
												mem_vec_7514 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_7515);
												mem_vec_7515 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_7516);
												mem_vec_7516 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_7517);
												mem_vec_7517 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_7518);
												mem_vec_7518 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_7519);
												mem_vec_7519 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7519);
								}
							}
						}
					}
				}
				for (y = y404 + 5, yp_0 = 0;
					y < y404 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 1024
					// T (x, 17) (17 / 1)
					for (x606 = x607, x606_p_0 = 0;
						x606 < x607 + 17;
						x606 += 1, x606_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 1024
						// T (f, 32) (1024 / 32)
						for (f = f808, fp_2 = f808_p_1, fp_1 = f808_p_0, fp_0 = 0;
							f < f808 + 1024;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w404, wp_0 = 0;
								w < w404 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x606, xp_1 = x606_p_0, xp_0 = 0;
									x < x606 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7520 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7521 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7522 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7523 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_7540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c606, cp_1 = c606_p_0, cp_0 = 0;
												c < c606 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7520);
												mem_vec_7520 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7521);
												mem_vec_7521 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7522);
												mem_vec_7522 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7523);
												mem_vec_7523 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7524);
												mem_vec_7524 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7525);
												mem_vec_7525 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7526);
												mem_vec_7526 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7527);
												mem_vec_7527 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7528);
												mem_vec_7528 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7529);
												mem_vec_7529 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7530);
												mem_vec_7530 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7531);
												mem_vec_7531 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7532);
												mem_vec_7532 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7533);
												mem_vec_7533 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7534);
												mem_vec_7534 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7535);
												mem_vec_7535 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7536);
												mem_vec_7536 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7537);
												mem_vec_7537 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7538);
												mem_vec_7538 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7539);
												mem_vec_7539 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7540);
												mem_vec_7540 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7541);
												mem_vec_7541 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7542);
												mem_vec_7542 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7543);
												mem_vec_7543 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_7520);
												mem_vec_7520 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_7521);
												mem_vec_7521 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_7522);
												mem_vec_7522 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_7523);
												mem_vec_7523 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_7524);
												mem_vec_7524 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_7525);
												mem_vec_7525 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_7526);
												mem_vec_7526 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_7527);
												mem_vec_7527 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_7528);
												mem_vec_7528 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_7529);
												mem_vec_7529 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_7530);
												mem_vec_7530 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_7531);
												mem_vec_7531 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_7532);
												mem_vec_7532 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_7533);
												mem_vec_7533 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_7534);
												mem_vec_7534 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_7535);
												mem_vec_7535 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_7536);
												mem_vec_7536 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_7537);
												mem_vec_7537 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_7538);
												mem_vec_7538 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_7539);
												mem_vec_7539 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_7540);
												mem_vec_7540 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_7541);
												mem_vec_7541 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_7542);
												mem_vec_7542 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_7543);
												mem_vec_7543 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_7520);
												mem_vec_7520 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_7521);
												mem_vec_7521 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_7522);
												mem_vec_7522 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_7523);
												mem_vec_7523 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_7524);
												mem_vec_7524 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_7525);
												mem_vec_7525 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_7526);
												mem_vec_7526 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_7527);
												mem_vec_7527 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_7528);
												mem_vec_7528 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_7529);
												mem_vec_7529 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_7530);
												mem_vec_7530 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_7531);
												mem_vec_7531 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_7532);
												mem_vec_7532 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_7533);
												mem_vec_7533 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_7534);
												mem_vec_7534 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_7535);
												mem_vec_7535 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_7536);
												mem_vec_7536 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_7537);
												mem_vec_7537 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_7538);
												mem_vec_7538 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_7539);
												mem_vec_7539 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_7540);
												mem_vec_7540 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_7541);
												mem_vec_7541 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_7542);
												mem_vec_7542 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_7543);
												mem_vec_7543 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7529);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7530);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7531);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7532);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7533);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7534);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7535);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7536);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7537);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7538);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7539);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7540);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7541);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7542);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7543);
								}
							}
						}
					}
				}
		}
	}
}


}