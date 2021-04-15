#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, c); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (16, f);
  T (64, c); T (14, x)]
*/
IND_TYPE c, cp_0, c828_p_0, c829_p_0, cp_1, c828_p_1, cp_2, c828, c829, f, fp_0, w, wp_0, x, xp_0, x1064_p_0, x1065_p_0, xp_1, x1064_p_1, xp_2, x1064, x1065, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y532 = 0;
IND_TYPE x1066 = 0;
IND_TYPE h = 0;
IND_TYPE w428 = 0;
IND_TYPE c830 = 0;
IND_TYPE f1004 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6344 ,mem_vec_6345 ,mem_vec_6346 ,mem_vec_6347 ,mem_vec_6348 ,mem_vec_6349 ,mem_vec_6350 ,mem_vec_6351 ,mem_vec_6352 ,mem_vec_6353 ,mem_vec_6354 ,mem_vec_6355 ,mem_vec_6356 ,mem_vec_6357 ,mem_vec_6358 ,mem_vec_6359 ,mem_vec_6360 ,mem_vec_6361 ,mem_vec_6362 ,mem_vec_6363 ,mem_vec_6364 ,mem_vec_6365 ,mem_vec_6366 ,mem_vec_6367 ,mem_vec_6368 ,mem_vec_6369 ,mem_vec_6370 ,mem_vec_6371 ,mem_vec_6372 ,mem_vec_6373 ,mem_vec_6374 ,mem_vec_6375 ,mem_vec_6376 ,mem_vec_6377 ,mem_vec_6378 ,mem_vec_6379 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (x, 14) (28 / 2)
for (x1065 = x1066, x1065_p_0 = 0;
	x1065 < x1066 + 28;
	x1065 += 2, x1065_p_0 += 2){
	// y = 28, x = 2, h = 3, w = 3, c = 256, f = 256
	// T (c, 64) (256 / 4)
	for (c829 = c830, c829_p_0 = 0;
		c829 < c830 + 256;
		c829 += 4, c829_p_0 += 4){
		// y = 28, x = 2, h = 3, w = 3, c = 4, f = 256
		// T (f, 16) (256 / 16)
		for (f = f1004, fp_0 = 0;
			f < f1004 + 256;
			f += 16, fp_0 += 16){
				for (y = y532, yp_0 = 0;
					y < y532 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 16
					// T (x, 2) (2 / 1)
					for (x1064 = x1065, x1064_p_1 = x1065_p_0, x1064_p_0 = 0;
						x1064 < x1065 + 2;
						x1064 += 1, x1064_p_1 += 1, x1064_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
						// T (c, 4) (4 / 1)
						for (c828 = c829, c828_p_1 = c829_p_0, c828_p_0 = 0;
							c828 < c829 + 4;
							c828 += 1, c828_p_1 += 1, c828_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 16
							// T (w, 3) (3 / 1)
							for (w = w428, wp_0 = 0;
								w < w428 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1064, xp_2 = x1064_p_1, xp_1 = x1064_p_0, xp_0 = 0;
									x < x1064 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6344 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6345 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
											// T (c, 1) (1 / 1)
											for (c = c828, cp_2 = c828_p_1, cp_1 = c828_p_0, cp_0 = 0;
												c < c828 + 1;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6344);
												mem_vec_6344 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6345);
												mem_vec_6345 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6346);
												mem_vec_6346 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6347);
												mem_vec_6347 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6348);
												mem_vec_6348 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6349);
												mem_vec_6349 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6350);
												mem_vec_6350 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6351);
												mem_vec_6351 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6352);
												mem_vec_6352 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6353);
												mem_vec_6353 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6354);
												mem_vec_6354 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6355);
												mem_vec_6355 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6356);
												mem_vec_6356 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6357);
												mem_vec_6357 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6358);
												mem_vec_6358 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6359);
												mem_vec_6359 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_6344);
												mem_vec_6344 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_6345);
												mem_vec_6345 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_6346);
												mem_vec_6346 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_6347);
												mem_vec_6347 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_6348);
												mem_vec_6348 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_6349);
												mem_vec_6349 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_6350);
												mem_vec_6350 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_6351);
												mem_vec_6351 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_6352);
												mem_vec_6352 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_6353);
												mem_vec_6353 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6354);
												mem_vec_6354 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6355);
												mem_vec_6355 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_6356);
												mem_vec_6356 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_6357);
												mem_vec_6357 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_6358);
												mem_vec_6358 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_6359);
												mem_vec_6359 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_6344);
												mem_vec_6344 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_6345);
												mem_vec_6345 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6346);
												mem_vec_6346 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6347);
												mem_vec_6347 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_6348);
												mem_vec_6348 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_6349);
												mem_vec_6349 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_6350);
												mem_vec_6350 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_6351);
												mem_vec_6351 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_6352);
												mem_vec_6352 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_6353);
												mem_vec_6353 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_6354);
												mem_vec_6354 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_6355);
												mem_vec_6355 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_6356);
												mem_vec_6356 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_6357);
												mem_vec_6357 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_6358);
												mem_vec_6358 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_6359);
												mem_vec_6359 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6359);
								}
							}
						}
					}
				}
				for (y = y532 + 8, yp_0 = 0;
					y < y532 + 8 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 16
					// T (x, 2) (2 / 1)
					for (x1064 = x1065, x1064_p_1 = x1065_p_0, x1064_p_0 = 0;
						x1064 < x1065 + 2;
						x1064 += 1, x1064_p_1 += 1, x1064_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
						// T (c, 4) (4 / 1)
						for (c828 = c829, c828_p_1 = c829_p_0, c828_p_0 = 0;
							c828 < c829 + 4;
							c828 += 1, c828_p_1 += 1, c828_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 16
							// T (w, 3) (3 / 1)
							for (w = w428, wp_0 = 0;
								w < w428 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1064, xp_2 = x1064_p_1, xp_1 = x1064_p_0, xp_0 = 0;
									x < x1064 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_6376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_6378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
											// T (c, 1) (1 / 1)
											for (c = c828, cp_2 = c828_p_1, cp_1 = c828_p_0, cp_0 = 0;
												c < c828 + 1;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6360);
												mem_vec_6360 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6361);
												mem_vec_6361 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6362);
												mem_vec_6362 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6363);
												mem_vec_6363 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6364);
												mem_vec_6364 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6365);
												mem_vec_6365 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6366);
												mem_vec_6366 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6367);
												mem_vec_6367 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6368);
												mem_vec_6368 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6369);
												mem_vec_6369 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6370);
												mem_vec_6370 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6371);
												mem_vec_6371 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6372);
												mem_vec_6372 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6373);
												mem_vec_6373 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6374);
												mem_vec_6374 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6375);
												mem_vec_6375 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6376);
												mem_vec_6376 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6377);
												mem_vec_6377 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6378);
												mem_vec_6378 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6379);
												mem_vec_6379 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_6360);
												mem_vec_6360 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_6361);
												mem_vec_6361 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_6362);
												mem_vec_6362 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_6363);
												mem_vec_6363 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_6364);
												mem_vec_6364 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_6365);
												mem_vec_6365 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_6366);
												mem_vec_6366 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_6367);
												mem_vec_6367 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_6368);
												mem_vec_6368 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_6369);
												mem_vec_6369 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_6370);
												mem_vec_6370 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_6371);
												mem_vec_6371 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_6372);
												mem_vec_6372 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_6373);
												mem_vec_6373 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_6374);
												mem_vec_6374 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_6375);
												mem_vec_6375 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_6376);
												mem_vec_6376 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_6377);
												mem_vec_6377 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_6378);
												mem_vec_6378 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_6379);
												mem_vec_6379 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_6360);
												mem_vec_6360 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_6361);
												mem_vec_6361 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_6362);
												mem_vec_6362 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_6363);
												mem_vec_6363 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6364);
												mem_vec_6364 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_6365);
												mem_vec_6365 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_6366);
												mem_vec_6366 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_6367);
												mem_vec_6367 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_6368);
												mem_vec_6368 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_6369);
												mem_vec_6369 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_6370);
												mem_vec_6370 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_6371);
												mem_vec_6371 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_6372);
												mem_vec_6372 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_6373);
												mem_vec_6373 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_6374);
												mem_vec_6374 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_6375);
												mem_vec_6375 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_6376);
												mem_vec_6376 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_6377);
												mem_vec_6377 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_6378);
												mem_vec_6378 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_6379);
												mem_vec_6379 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_6379);
								}
							}
						}
					}
				}
		}
	}
}


}