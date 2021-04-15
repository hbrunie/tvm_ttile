#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (17, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))];
  T (8, f); T (16, c); T (1, f); T (4, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1134_p_0, cp_1, c1134, f, fp_0, f1436_p_0, f1437_p_0, fp_1, f1436_p_1, fp_2, f1436, f1437, w, wp_0, x, xp_0, x1224_p_0, xp_1, x1224, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y756 = 0;
IND_TYPE x1225 = 0;
IND_TYPE h = 0;
IND_TYPE w704 = 0;
IND_TYPE c1135 = 0;
IND_TYPE f1438 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14476 ,mem_vec_14477 ,mem_vec_14478 ,mem_vec_14479 ,mem_vec_14480 ,mem_vec_14481 ,mem_vec_14482 ,mem_vec_14483 ,mem_vec_14484 ,mem_vec_14485 ,mem_vec_14486 ,mem_vec_14487 ,mem_vec_14488 ,mem_vec_14489 ,mem_vec_14490 ,mem_vec_14491 ,mem_vec_14492 ,mem_vec_14493 ,mem_vec_14494 ,mem_vec_14495 ,mem_vec_14496 ,mem_vec_14497 ,mem_vec_14498 ,mem_vec_14499 ,mem_vec_14500 ,mem_vec_14501 ,mem_vec_14502 ,mem_vec_14503 ,mem_vec_14504 ,mem_vec_14505 ,mem_vec_14506 ,mem_vec_14507 ,mem_vec_14508 ,mem_vec_14509 ,mem_vec_14510 ,mem_vec_14511 ,mem_vec_14512 ,mem_vec_14513 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1437 = f1438, f1437_p_0 = 0;
	f1437 < f1438 + 256;
	f1437 += 256, f1437_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 4) (68 / 17)
	for (x1224 = x1225, x1224_p_0 = 0;
		x1224 < x1225 + 68;
		x1224 += 17, x1224_p_0 += 17){
		// y = 68, x = 17, h = 3, w = 3, c = 128, f = 256
		// T (f, 1) (256 / 256)
		for (f1436 = f1437, f1436_p_1 = f1437_p_0, f1436_p_0 = 0;
			f1436 < f1437 + 256;
			f1436 += 256, f1436_p_1 += 256, f1436_p_0 += 256){
			// y = 68, x = 17, h = 3, w = 3, c = 128, f = 256
			// T (c, 16) (128 / 8)
			for (c1134 = c1135, c1134_p_0 = 0;
				c1134 < c1135 + 128;
				c1134 += 8, c1134_p_0 += 8){
				// y = 68, x = 17, h = 3, w = 3, c = 8, f = 256
				// T (f, 8) (256 / 32)
				for (f = f1436, fp_2 = f1436_p_1, fp_1 = f1436_p_0, fp_0 = 0;
					f < f1436 + 256;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y756, yp_0 = 0;
							y < y756 + 18;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w704, wp_0 = 0;
								w < w704 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 8, f = 32
								// T (x, 17) (17 / 1)
								for (x = x1224, xp_1 = x1224_p_0, xp_0 = 0;
									x < x1224 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14476 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14477 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
												c < c1134 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14476);
												mem_vec_14476 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14477);
												mem_vec_14477 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14478);
												mem_vec_14478 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14479);
												mem_vec_14479 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14480);
												mem_vec_14480 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14481);
												mem_vec_14481 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14482);
												mem_vec_14482 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14483);
												mem_vec_14483 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14484);
												mem_vec_14484 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14485);
												mem_vec_14485 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14486);
												mem_vec_14486 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14487);
												mem_vec_14487 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14488);
												mem_vec_14488 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14489);
												mem_vec_14489 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14490);
												mem_vec_14490 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14491);
												mem_vec_14491 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14492);
												mem_vec_14492 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14493);
												mem_vec_14493 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_14476);
												mem_vec_14476 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_14477);
												mem_vec_14477 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_14478);
												mem_vec_14478 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_14479);
												mem_vec_14479 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_14480);
												mem_vec_14480 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_14481);
												mem_vec_14481 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_14482);
												mem_vec_14482 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_14483);
												mem_vec_14483 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_14484);
												mem_vec_14484 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_14485);
												mem_vec_14485 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_14486);
												mem_vec_14486 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_14487);
												mem_vec_14487 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_14488);
												mem_vec_14488 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_14489);
												mem_vec_14489 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_14490);
												mem_vec_14490 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_14491);
												mem_vec_14491 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_14492);
												mem_vec_14492 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_14493);
												mem_vec_14493 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_18);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_14476);
												mem_vec_14476 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_14477);
												mem_vec_14477 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_14478);
												mem_vec_14478 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_14479);
												mem_vec_14479 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_14480);
												mem_vec_14480 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_14481);
												mem_vec_14481 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_14482);
												mem_vec_14482 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_14483);
												mem_vec_14483 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_14484);
												mem_vec_14484 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_14485);
												mem_vec_14485 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_14486);
												mem_vec_14486 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_14487);
												mem_vec_14487 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_14488);
												mem_vec_14488 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_14489);
												mem_vec_14489 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_14490);
												mem_vec_14490 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_14491);
												mem_vec_14491 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_14492);
												mem_vec_14492 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_14493);
												mem_vec_14493 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14476);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14477);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14478);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14479);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14480);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14481);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14482);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14483);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14484);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14485);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14486);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14487);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14488);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14489);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14490);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14491);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14492);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14493);
								}
							}
						}
						for (y = y756 + 18, yp_0 = 0;
							y < y756 + 18 + 50;
							y += 10, yp_0 += 10){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w704, wp_0 = 0;
								w < w704 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 8, f = 32
								// T (x, 17) (17 / 1)
								for (x = x1224, xp_1 = x1224_p_0, xp_0 = 0;
									x < x1224 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14494 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14495 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_14512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_14513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
												c < c1134 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14494);
												mem_vec_14494 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14495);
												mem_vec_14495 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14496);
												mem_vec_14496 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14497);
												mem_vec_14497 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14498);
												mem_vec_14498 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14499);
												mem_vec_14499 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14500);
												mem_vec_14500 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14501);
												mem_vec_14501 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14502);
												mem_vec_14502 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14503);
												mem_vec_14503 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14504);
												mem_vec_14504 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14505);
												mem_vec_14505 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14506);
												mem_vec_14506 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14507);
												mem_vec_14507 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14508);
												mem_vec_14508 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14509);
												mem_vec_14509 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14510);
												mem_vec_14510 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14511);
												mem_vec_14511 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14512);
												mem_vec_14512 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14513);
												mem_vec_14513 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_14494);
												mem_vec_14494 = vec_32;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_14495);
												mem_vec_14495 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_14496);
												mem_vec_14496 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_14497);
												mem_vec_14497 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_14498);
												mem_vec_14498 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_14499);
												mem_vec_14499 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_14500);
												mem_vec_14500 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14501);
												mem_vec_14501 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_14502);
												mem_vec_14502 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_14503);
												mem_vec_14503 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_14504);
												mem_vec_14504 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_14505);
												mem_vec_14505 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_14506);
												mem_vec_14506 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_14507);
												mem_vec_14507 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_14508);
												mem_vec_14508 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_14509);
												mem_vec_14509 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_14510);
												mem_vec_14510 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14511);
												mem_vec_14511 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_14512);
												mem_vec_14512 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_14513);
												mem_vec_14513 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_14494);
												mem_vec_14494 = vec_64;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_14495);
												mem_vec_14495 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_14496);
												mem_vec_14496 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_14497);
												mem_vec_14497 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_14498);
												mem_vec_14498 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_14499);
												mem_vec_14499 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_14500);
												mem_vec_14500 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_14501);
												mem_vec_14501 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_14502);
												mem_vec_14502 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_14503);
												mem_vec_14503 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_14504);
												mem_vec_14504 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_14505);
												mem_vec_14505 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_14506);
												mem_vec_14506 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_14507);
												mem_vec_14507 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_14508);
												mem_vec_14508 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_14509);
												mem_vec_14509 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_14510);
												mem_vec_14510 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_14511);
												mem_vec_14511 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_14512);
												mem_vec_14512 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_14513);
												mem_vec_14513 = vec_95;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14494);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14495);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14496);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14497);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14498);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14499);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14500);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14501);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14502);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14503);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14504);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14505);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14506);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14507);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14508);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14509);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14510);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14511);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14512);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14513);
								}
							}
						}
				}
			}
		}
	}
}


}