#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (32, f);
  T (8, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1014_p_0, cp_1, c1014, f, fp_0, f1352_p_0, f1353_p_0, fp_1, f1352_p_1, fp_2, f1352, f1353, h, hp_0, x, xp_0, x1014_p_0, xp_1, x1014, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y676 = 0;
IND_TYPE x1015 = 0;
IND_TYPE h476 = 0;
IND_TYPE w = 0;
IND_TYPE c1015 = 0;
IND_TYPE f1354 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13412 ,mem_vec_13413 ,mem_vec_13414 ,mem_vec_13415 ,mem_vec_13416 ,mem_vec_13417 ,mem_vec_13418 ,mem_vec_13419 ,mem_vec_13420 ,mem_vec_13421 ,mem_vec_13422 ,mem_vec_13423 ,mem_vec_13424 ,mem_vec_13425 ,mem_vec_13426 ,mem_vec_13427 ,mem_vec_13428 ,mem_vec_13429 ,mem_vec_13430 ,mem_vec_13431 ,mem_vec_13432 ,mem_vec_13433 ,mem_vec_13434 ,mem_vec_13435 ,mem_vec_13436 ,mem_vec_13437 ,mem_vec_13438 ,mem_vec_13439 ,mem_vec_13440 ,mem_vec_13441 ,mem_vec_13442 ,mem_vec_13443 ,mem_vec_13444 ,mem_vec_13445 ,mem_vec_13446 ,mem_vec_13447 ,mem_vec_13448 ,mem_vec_13449 ,mem_vec_13450 ,mem_vec_13451 ,mem_vec_13452 ,mem_vec_13453 ,mem_vec_13454 ,mem_vec_13455 ,mem_vec_13456 ,mem_vec_13457 ,mem_vec_13458 ,mem_vec_13459 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f1353 = f1354, f1353_p_0 = 0;
	f1353 < f1354 + 1024;
	f1353 += 1024, f1353_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 8) (512 / 64)
	for (c1014 = c1015, c1014_p_0 = 0;
		c1014 < c1015 + 512;
		c1014 += 64, c1014_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 1024
		// T (f, 32) (1024 / 32)
		for (f1352 = f1353, f1352_p_1 = f1353_p_0, f1352_p_0 = 0;
			f1352 < f1353 + 1024;
			f1352 += 32, f1352_p_1 += 32, f1352_p_0 += 32){
				for (y = y676, yp_0 = 0;
					y < y676 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (x, 1) (17 / 17)
					for (x1014 = x1015, x1014_p_0 = 0;
						x1014 < x1015 + 17;
						x1014 += 17, x1014_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1352, fp_2 = f1352_p_1, fp_1 = f1352_p_0, fp_0 = 0;
							f < f1352 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h476, hp_0 = 0;
								h < h476 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 32
								// T (x, 17) (17 / 1)
								for (x = x1014, xp_1 = x1014_p_0, xp_0 = 0;
									x < x1014 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13412 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13413 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13414 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13415 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
												c < c1014 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13412);
												mem_vec_13412 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13413);
												mem_vec_13413 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13414);
												mem_vec_13414 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13415);
												mem_vec_13415 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13416);
												mem_vec_13416 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13417);
												mem_vec_13417 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13418);
												mem_vec_13418 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13419);
												mem_vec_13419 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13420);
												mem_vec_13420 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13421);
												mem_vec_13421 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13422);
												mem_vec_13422 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13423);
												mem_vec_13423 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13424);
												mem_vec_13424 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13425);
												mem_vec_13425 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13426);
												mem_vec_13426 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13427);
												mem_vec_13427 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13428);
												mem_vec_13428 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13429);
												mem_vec_13429 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13430);
												mem_vec_13430 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13431);
												mem_vec_13431 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_13412);
												mem_vec_13412 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_13413);
												mem_vec_13413 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_13414);
												mem_vec_13414 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_13415);
												mem_vec_13415 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_13416);
												mem_vec_13416 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_13417);
												mem_vec_13417 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_13418);
												mem_vec_13418 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_13419);
												mem_vec_13419 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_13420);
												mem_vec_13420 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_13421);
												mem_vec_13421 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_13422);
												mem_vec_13422 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_13423);
												mem_vec_13423 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_13424);
												mem_vec_13424 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_13425);
												mem_vec_13425 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_13426);
												mem_vec_13426 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_13427);
												mem_vec_13427 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_13428);
												mem_vec_13428 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_13429);
												mem_vec_13429 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_13430);
												mem_vec_13430 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_13431);
												mem_vec_13431 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_13412);
												mem_vec_13412 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_13413);
												mem_vec_13413 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_13414);
												mem_vec_13414 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_13415);
												mem_vec_13415 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_13416);
												mem_vec_13416 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_13417);
												mem_vec_13417 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_13418);
												mem_vec_13418 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_13419);
												mem_vec_13419 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_13420);
												mem_vec_13420 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_13421);
												mem_vec_13421 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_13422);
												mem_vec_13422 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_13423);
												mem_vec_13423 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_13424);
												mem_vec_13424 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_13425);
												mem_vec_13425 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_13426);
												mem_vec_13426 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_13427);
												mem_vec_13427 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_13428);
												mem_vec_13428 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_13429);
												mem_vec_13429 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_13430);
												mem_vec_13430 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_13431);
												mem_vec_13431 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13412);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13413);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13414);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13415);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13416);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13417);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13418);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13419);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13420);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13421);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13422);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13423);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13424);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13425);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13426);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13427);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13428);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13429);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13430);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13431);
								}
							}
						}
					}
				}
				for (y = y676 + 10, yp_0 = 0;
					y < y676 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (x, 1) (17 / 17)
					for (x1014 = x1015, x1014_p_0 = 0;
						x1014 < x1015 + 17;
						x1014 += 17, x1014_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1352, fp_2 = f1352_p_1, fp_1 = f1352_p_0, fp_0 = 0;
							f < f1352 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h476, hp_0 = 0;
								h < h476 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 32
								// T (x, 17) (17 / 1)
								for (x = x1014, xp_1 = x1014_p_0, xp_0 = 0;
									x < x1014 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13432 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13433 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13434 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13435 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_13448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_13450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_13452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_13454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_13456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_13457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_13458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_13459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
												c < c1014 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13432);
												mem_vec_13432 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13433);
												mem_vec_13433 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13434);
												mem_vec_13434 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13435);
												mem_vec_13435 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13436);
												mem_vec_13436 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13437);
												mem_vec_13437 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13438);
												mem_vec_13438 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13439);
												mem_vec_13439 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13440);
												mem_vec_13440 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13441);
												mem_vec_13441 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13442);
												mem_vec_13442 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13443);
												mem_vec_13443 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13444);
												mem_vec_13444 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13445);
												mem_vec_13445 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13446);
												mem_vec_13446 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13447);
												mem_vec_13447 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13448);
												mem_vec_13448 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13449);
												mem_vec_13449 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13450);
												mem_vec_13450 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13451);
												mem_vec_13451 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13452);
												mem_vec_13452 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13453);
												mem_vec_13453 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13454);
												mem_vec_13454 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13455);
												mem_vec_13455 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_13456);
												mem_vec_13456 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_13457);
												mem_vec_13457 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_13458);
												mem_vec_13458 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_13459);
												mem_vec_13459 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_13432);
												mem_vec_13432 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_13433);
												mem_vec_13433 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_13434);
												mem_vec_13434 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_13435);
												mem_vec_13435 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_13436);
												mem_vec_13436 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_13437);
												mem_vec_13437 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_13438);
												mem_vec_13438 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_13439);
												mem_vec_13439 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_13440);
												mem_vec_13440 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_13441);
												mem_vec_13441 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_13442);
												mem_vec_13442 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_13443);
												mem_vec_13443 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_13444);
												mem_vec_13444 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_13445);
												mem_vec_13445 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_13446);
												mem_vec_13446 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_13447);
												mem_vec_13447 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_13448);
												mem_vec_13448 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_13449);
												mem_vec_13449 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_13450);
												mem_vec_13450 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_13451);
												mem_vec_13451 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_13452);
												mem_vec_13452 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_13453);
												mem_vec_13453 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_13454);
												mem_vec_13454 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_13455);
												mem_vec_13455 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_13456);
												mem_vec_13456 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_13457);
												mem_vec_13457 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_13458);
												mem_vec_13458 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_13459);
												mem_vec_13459 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_13432);
												mem_vec_13432 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_13433);
												mem_vec_13433 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_13434);
												mem_vec_13434 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_13435);
												mem_vec_13435 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_13436);
												mem_vec_13436 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_13437);
												mem_vec_13437 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_13438);
												mem_vec_13438 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_13439);
												mem_vec_13439 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_13440);
												mem_vec_13440 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_13441);
												mem_vec_13441 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_13442);
												mem_vec_13442 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_13443);
												mem_vec_13443 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_13444);
												mem_vec_13444 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_13445);
												mem_vec_13445 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_13446);
												mem_vec_13446 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_13447);
												mem_vec_13447 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_13448);
												mem_vec_13448 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_13449);
												mem_vec_13449 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_13450);
												mem_vec_13450 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_13451);
												mem_vec_13451 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_13452);
												mem_vec_13452 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_13453);
												mem_vec_13453 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_13454);
												mem_vec_13454 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_13455);
												mem_vec_13455 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_13456);
												mem_vec_13456 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_13457);
												mem_vec_13457 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_13458);
												mem_vec_13458 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_13459);
												mem_vec_13459 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13432);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13433);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13434);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13435);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13436);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13437);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13438);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13439);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13440);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13441);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13442);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13443);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13444);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13445);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13446);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13447);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13448);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13449);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13450);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13451);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13452);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13453);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13454);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13455);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13456);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_13457);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13458);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_13459);
								}
							}
						}
					}
				}
		}
	}
}


}