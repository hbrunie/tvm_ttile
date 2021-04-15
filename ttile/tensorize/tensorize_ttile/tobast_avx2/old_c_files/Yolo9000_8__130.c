#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (1, c);
  T (16, f); T (68, x); T (16, c)]
*/
IND_TYPE c, cp_0, c1106_p_0, c1107_p_0, c1108_p_0, cp_1, c1106_p_1, c1107_p_1, cp_2, c1106_p_2, cp_3, c1106, c1107, c1108, f, fp_0, w, wp_0, x, xp_0, x1240_p_0, xp_1, x1240, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y652 = 0;
IND_TYPE x1241 = 0;
IND_TYPE h = 0;
IND_TYPE w532 = 0;
IND_TYPE c1109 = 0;
IND_TYPE f1176 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7472 ,mem_vec_7473 ,mem_vec_7474 ,mem_vec_7475 ,mem_vec_7476 ,mem_vec_7477 ,mem_vec_7478 ,mem_vec_7479 ,mem_vec_7480 ,mem_vec_7481 ,mem_vec_7482 ,mem_vec_7483 ,mem_vec_7484 ,mem_vec_7485 ,mem_vec_7486 ,mem_vec_7487 ,mem_vec_7488 ,mem_vec_7489 ,mem_vec_7490 ,mem_vec_7491 ,mem_vec_7492 ,mem_vec_7493 ,mem_vec_7494 ,mem_vec_7495 ,mem_vec_7496 ,mem_vec_7497 ,mem_vec_7498 ,mem_vec_7499 ,mem_vec_7500 ,mem_vec_7501 ,mem_vec_7502 ,mem_vec_7503 ,mem_vec_7504 ,mem_vec_7505 ,mem_vec_7506 ,mem_vec_7507 ,mem_vec_7508 ,mem_vec_7509 ,mem_vec_7510 ,mem_vec_7511 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 16) (128 / 8)
for (c1108 = c1109, c1108_p_0 = 0;
	c1108 < c1109 + 128;
	c1108 += 8, c1108_p_0 += 8){
	// y = 68, x = 68, h = 3, w = 3, c = 8, f = 256
	// T (x, 68) (68 / 1)
	for (x1240 = x1241, x1240_p_0 = 0;
		x1240 < x1241 + 68;
		x1240 += 1, x1240_p_0 += 1){
		// y = 68, x = 1, h = 3, w = 3, c = 8, f = 256
		// T (f, 16) (256 / 16)
		for (f = f1176, fp_0 = 0;
			f < f1176 + 256;
			f += 16, fp_0 += 16){
			// y = 68, x = 1, h = 3, w = 3, c = 8, f = 16
			// T (c, 1) (8 / 8)
			for (c1107 = c1108, c1107_p_1 = c1108_p_0, c1107_p_0 = 0;
				c1107 < c1108 + 8;
				c1107 += 8, c1107_p_1 += 8, c1107_p_0 += 8){
					for (y = y652, yp_0 = 0;
						y < y652 + 8;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 1) (8 / 8)
						for (c1106 = c1107, c1106_p_2 = c1107_p_1, c1106_p_1 = c1107_p_0, c1106_p_0 = 0;
							c1106 < c1107 + 8;
							c1106 += 8, c1106_p_2 += 8, c1106_p_1 += 8, c1106_p_0 += 8){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
							// T (w, 3) (3 / 1)
							for (w = w532, wp_0 = 0;
								w < w532 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1240, xp_1 = x1240_p_0, xp_0 = 0;
									x < x1240 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7472 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7473 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_7486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c1106, cp_3 = c1106_p_2, cp_2 = c1106_p_1, cp_1 = c1106_p_0, cp_0 = 0;
												c < c1106 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7472);
												mem_vec_7472 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7473);
												mem_vec_7473 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7474);
												mem_vec_7474 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7475);
												mem_vec_7475 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7476);
												mem_vec_7476 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7477);
												mem_vec_7477 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7478);
												mem_vec_7478 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7479);
												mem_vec_7479 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7480);
												mem_vec_7480 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7481);
												mem_vec_7481 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7482);
												mem_vec_7482 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7483);
												mem_vec_7483 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7484);
												mem_vec_7484 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7485);
												mem_vec_7485 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7486);
												mem_vec_7486 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7487);
												mem_vec_7487 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_7472);
												mem_vec_7472 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_7473);
												mem_vec_7473 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_7474);
												mem_vec_7474 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_7475);
												mem_vec_7475 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_7476);
												mem_vec_7476 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_7477);
												mem_vec_7477 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_7478);
												mem_vec_7478 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_7479);
												mem_vec_7479 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_7480);
												mem_vec_7480 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_7481);
												mem_vec_7481 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7482);
												mem_vec_7482 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7483);
												mem_vec_7483 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_7484);
												mem_vec_7484 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_7485);
												mem_vec_7485 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_7486);
												mem_vec_7486 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_7487);
												mem_vec_7487 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_7472);
												mem_vec_7472 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_7473);
												mem_vec_7473 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7474);
												mem_vec_7474 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7475);
												mem_vec_7475 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_7476);
												mem_vec_7476 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_7477);
												mem_vec_7477 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_7478);
												mem_vec_7478 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_7479);
												mem_vec_7479 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_7480);
												mem_vec_7480 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_7481);
												mem_vec_7481 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_7482);
												mem_vec_7482 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_7483);
												mem_vec_7483 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_7484);
												mem_vec_7484 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_7485);
												mem_vec_7485 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_7486);
												mem_vec_7486 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_7487);
												mem_vec_7487 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7472);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7473);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7474);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7475);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7476);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7477);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7478);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7479);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7480);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7481);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7482);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7483);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7484);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7485);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7486);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_7487);
								}
							}
						}
					}
					for (y = y652 + 8, yp_0 = 0;
						y < y652 + 8 + 60;
						y += 12, yp_0 += 12){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 1) (8 / 8)
						for (c1106 = c1107, c1106_p_2 = c1107_p_1, c1106_p_1 = c1107_p_0, c1106_p_0 = 0;
							c1106 < c1107 + 8;
							c1106 += 8, c1106_p_2 += 8, c1106_p_1 += 8, c1106_p_0 += 8){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
							// T (w, 3) (3 / 1)
							for (w = w532, wp_0 = 0;
								w < w532 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1240, xp_1 = x1240_p_0, xp_0 = 0;
									x < x1240 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7488 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7489 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_7502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_7504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_7506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_7508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_7510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c1106, cp_3 = c1106_p_2, cp_2 = c1106_p_1, cp_1 = c1106_p_0, cp_0 = 0;
												c < c1106 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7488);
												mem_vec_7488 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7489);
												mem_vec_7489 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7490);
												mem_vec_7490 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7491);
												mem_vec_7491 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7492);
												mem_vec_7492 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7493);
												mem_vec_7493 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7494);
												mem_vec_7494 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7495);
												mem_vec_7495 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7496);
												mem_vec_7496 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7497);
												mem_vec_7497 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7498);
												mem_vec_7498 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7499);
												mem_vec_7499 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7500);
												mem_vec_7500 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7501);
												mem_vec_7501 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7502);
												mem_vec_7502 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7503);
												mem_vec_7503 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_7504);
												mem_vec_7504 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_7505);
												mem_vec_7505 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7506);
												mem_vec_7506 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7507);
												mem_vec_7507 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_7508);
												mem_vec_7508 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_7509);
												mem_vec_7509 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_7510);
												mem_vec_7510 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_7511);
												mem_vec_7511 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_7488);
												mem_vec_7488 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_7489);
												mem_vec_7489 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_7490);
												mem_vec_7490 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_7491);
												mem_vec_7491 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_7492);
												mem_vec_7492 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_7493);
												mem_vec_7493 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_7494);
												mem_vec_7494 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_7495);
												mem_vec_7495 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_7496);
												mem_vec_7496 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_7497);
												mem_vec_7497 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_7498);
												mem_vec_7498 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_7499);
												mem_vec_7499 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_7500);
												mem_vec_7500 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_7501);
												mem_vec_7501 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_7502);
												mem_vec_7502 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_7503);
												mem_vec_7503 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_7504);
												mem_vec_7504 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_7505);
												mem_vec_7505 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_7506);
												mem_vec_7506 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_7507);
												mem_vec_7507 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_7508);
												mem_vec_7508 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_7509);
												mem_vec_7509 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_7510);
												mem_vec_7510 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_7511);
												mem_vec_7511 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_7488);
												mem_vec_7488 = vec_76;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_7489);
												mem_vec_7489 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_7490);
												mem_vec_7490 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_7491);
												mem_vec_7491 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_7492);
												mem_vec_7492 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_7493);
												mem_vec_7493 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_7494);
												mem_vec_7494 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_7495);
												mem_vec_7495 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_7496);
												mem_vec_7496 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_7497);
												mem_vec_7497 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_7498);
												mem_vec_7498 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_7499);
												mem_vec_7499 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_7500);
												mem_vec_7500 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_7501);
												mem_vec_7501 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_7502);
												mem_vec_7502 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_7503);
												mem_vec_7503 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_7504);
												mem_vec_7504 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_7505);
												mem_vec_7505 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_7506);
												mem_vec_7506 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_7507);
												mem_vec_7507 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_7508);
												mem_vec_7508 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_7509);
												mem_vec_7509 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_7510);
												mem_vec_7510 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_7511);
												mem_vec_7511 = vec_113;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7488);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7489);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7490);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7491);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7492);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7493);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7494);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7495);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7496);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7497);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7498);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7499);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7500);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7501);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7502);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_7503);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7504);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_7505);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7506);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_7507);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7508);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_7509);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7510);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_7511);
								}
							}
						}
					}
			}
		}
	}
}


}