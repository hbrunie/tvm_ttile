#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f);
  T (4, c); T (28, x)]
*/
IND_TYPE c, cp_0, c1086_p_0, c1087_p_0, cp_1, c1086_p_1, cp_2, c1086, c1087, f, fp_0, w, wp_0, x, xp_0, x1312_p_0, x1313_p_0, xp_1, x1312_p_1, xp_2, x1312, x1313, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y648 = 0;
IND_TYPE x1314 = 0;
IND_TYPE h = 0;
IND_TYPE w544 = 0;
IND_TYPE c1088 = 0;
IND_TYPE f1052 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,mem_vec_8501 ,mem_vec_8502 ,mem_vec_8503 ,mem_vec_8504 ,mem_vec_8505 ,mem_vec_8506 ,mem_vec_8507 ,mem_vec_8508 ,mem_vec_8509 ,mem_vec_8510 ,mem_vec_8511 ,mem_vec_8512 ,mem_vec_8513 ,mem_vec_8514 ,mem_vec_8515 ,mem_vec_8516 ,mem_vec_8517 ,mem_vec_8518 ,mem_vec_8519 ,mem_vec_8520 ,mem_vec_8521 ,mem_vec_8522 ,mem_vec_8523 ,mem_vec_8524 ,mem_vec_8525 ,mem_vec_8526 ,mem_vec_8527 ,mem_vec_8528 ,mem_vec_8529 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 28) (28 / 1)
for (x1313 = x1314, x1313_p_0 = 0;
	x1313 < x1314 + 28;
	x1313 += 1, x1313_p_0 += 1){
	// y = 28, x = 1, h = 3, w = 3, c = 128, f = 128
	// T (c, 4) (128 / 32)
	for (c1087 = c1088, c1087_p_0 = 0;
		c1087 < c1088 + 128;
		c1087 += 32, c1087_p_0 += 32){
		// y = 28, x = 1, h = 3, w = 3, c = 32, f = 128
		// T (f, 8) (128 / 16)
		for (f = f1052, fp_0 = 0;
			f < f1052 + 128;
			f += 16, fp_0 += 16){
				for (y = y648, yp_0 = 0;
					y < y648 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (x, 1) (1 / 1)
					for (x1312 = x1313, x1312_p_1 = x1313_p_0, x1312_p_0 = 0;
						x1312 < x1313 + 1;
						x1312 += 1, x1312_p_1 += 1, x1312_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c1086 = c1087, c1086_p_1 = c1087_p_0, c1086_p_0 = 0;
							c1086 < c1087 + 32;
							c1086 += 16, c1086_p_1 += 16, c1086_p_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w544, wp_0 = 0;
								w < w544 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1312, xp_2 = x1312_p_1, xp_1 = x1312_p_0, xp_0 = 0;
									x < x1312 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8492 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8493 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_8506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_8508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c1086, cp_2 = c1086_p_1, cp_1 = c1086_p_0, cp_0 = 0;
												c < c1086 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8492);
												mem_vec_8492 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8493);
												mem_vec_8493 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8494);
												mem_vec_8494 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8495);
												mem_vec_8495 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8496);
												mem_vec_8496 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8497);
												mem_vec_8497 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8498);
												mem_vec_8498 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8499);
												mem_vec_8499 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8500);
												mem_vec_8500 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8501);
												mem_vec_8501 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8502);
												mem_vec_8502 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8503);
												mem_vec_8503 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8504);
												mem_vec_8504 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8505);
												mem_vec_8505 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8506);
												mem_vec_8506 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8507);
												mem_vec_8507 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8508);
												mem_vec_8508 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8509);
												mem_vec_8509 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8492);
												mem_vec_8492 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8493);
												mem_vec_8493 = vec_32;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_8494);
												mem_vec_8494 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_8495);
												mem_vec_8495 = vec_36;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_8496);
												mem_vec_8496 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_8497);
												mem_vec_8497 = vec_39;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_8498);
												mem_vec_8498 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_8499);
												mem_vec_8499 = vec_42;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8500);
												mem_vec_8500 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8501);
												mem_vec_8501 = vec_45;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_8502);
												mem_vec_8502 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_8503);
												mem_vec_8503 = vec_48;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_8504);
												mem_vec_8504 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_8505);
												mem_vec_8505 = vec_51;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_8506);
												mem_vec_8506 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_8507);
												mem_vec_8507 = vec_54;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_8508);
												mem_vec_8508 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_8509);
												mem_vec_8509 = vec_57;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8492);
												mem_vec_8492 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8493);
												mem_vec_8493 = vec_61;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_8494);
												mem_vec_8494 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_8495);
												mem_vec_8495 = vec_65;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_8496);
												mem_vec_8496 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_8497);
												mem_vec_8497 = vec_68;
												scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_8498);
												mem_vec_8498 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_8499);
												mem_vec_8499 = vec_71;
												scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8500);
												mem_vec_8500 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8501);
												mem_vec_8501 = vec_74;
												scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_8502);
												mem_vec_8502 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_8503);
												mem_vec_8503 = vec_77;
												scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_8504);
												mem_vec_8504 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_8505);
												mem_vec_8505 = vec_80;
												scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_8506);
												mem_vec_8506 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_8507);
												mem_vec_8507 = vec_83;
												scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_8508);
												mem_vec_8508 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_8509);
												mem_vec_8509 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8509);
								}
							}
						}
					}
				}
				for (y = y648 + 18, yp_0 = 0;
					y < y648 + 18 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (x, 1) (1 / 1)
					for (x1312 = x1313, x1312_p_1 = x1313_p_0, x1312_p_0 = 0;
						x1312 < x1313 + 1;
						x1312 += 1, x1312_p_1 += 1, x1312_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c1086 = c1087, c1086_p_1 = c1087_p_0, c1086_p_0 = 0;
							c1086 < c1087 + 32;
							c1086 += 16, c1086_p_1 += 16, c1086_p_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w544, wp_0 = 0;
								w < w544 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1312, xp_2 = x1312_p_1, xp_1 = x1312_p_0, xp_0 = 0;
									x < x1312 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8510 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8511 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_8524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_8526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_8528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c1086, cp_2 = c1086_p_1, cp_1 = c1086_p_0, cp_0 = 0;
												c < c1086 + 16;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8510);
												mem_vec_8510 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8511);
												mem_vec_8511 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8512);
												mem_vec_8512 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8513);
												mem_vec_8513 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8514);
												mem_vec_8514 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8515);
												mem_vec_8515 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8516);
												mem_vec_8516 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8517);
												mem_vec_8517 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8518);
												mem_vec_8518 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8519);
												mem_vec_8519 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8520);
												mem_vec_8520 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8521);
												mem_vec_8521 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8522);
												mem_vec_8522 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8523);
												mem_vec_8523 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8524);
												mem_vec_8524 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8525);
												mem_vec_8525 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8526);
												mem_vec_8526 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8527);
												mem_vec_8527 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8528);
												mem_vec_8528 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8529);
												mem_vec_8529 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_8510);
												mem_vec_8510 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_8511);
												mem_vec_8511 = vec_35;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_8512);
												mem_vec_8512 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_8513);
												mem_vec_8513 = vec_39;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_8514);
												mem_vec_8514 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_8515);
												mem_vec_8515 = vec_42;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_8516);
												mem_vec_8516 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8517);
												mem_vec_8517 = vec_45;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_8518);
												mem_vec_8518 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_8519);
												mem_vec_8519 = vec_48;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_8520);
												mem_vec_8520 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_8521);
												mem_vec_8521 = vec_51;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_8522);
												mem_vec_8522 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_8523);
												mem_vec_8523 = vec_54;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_8524);
												mem_vec_8524 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_8525);
												mem_vec_8525 = vec_57;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_8526);
												mem_vec_8526 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8527);
												mem_vec_8527 = vec_60;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_8528);
												mem_vec_8528 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_8529);
												mem_vec_8529 = vec_63;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_8510);
												mem_vec_8510 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_8511);
												mem_vec_8511 = vec_67;
												scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_8512);
												mem_vec_8512 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_8513);
												mem_vec_8513 = vec_71;
												scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8514);
												mem_vec_8514 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_8515);
												mem_vec_8515 = vec_74;
												scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_8516);
												mem_vec_8516 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_8517);
												mem_vec_8517 = vec_77;
												scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_8518);
												mem_vec_8518 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_8519);
												mem_vec_8519 = vec_80;
												scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_8520);
												mem_vec_8520 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_8521);
												mem_vec_8521 = vec_83;
												scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_8522);
												mem_vec_8522 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_8523);
												mem_vec_8523 = vec_86;
												scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_8524);
												mem_vec_8524 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_8525);
												mem_vec_8525 = vec_89;
												scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_8526);
												mem_vec_8526 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_8527);
												mem_vec_8527 = vec_92;
												scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_8528);
												mem_vec_8528 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_8529);
												mem_vec_8529 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8511);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8512);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8513);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8514);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8515);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8516);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8517);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8518);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8519);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8520);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8521);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8522);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8523);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8524);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8525);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8526);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8527);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8528);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8529);
								}
							}
						}
					}
				}
		}
	}
}


}