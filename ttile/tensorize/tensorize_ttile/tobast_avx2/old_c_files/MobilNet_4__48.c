#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f);
  T (1, c); T (28, x)]
*/
IND_TYPE c, cp_0, c1070_p_0, c1071_p_0, cp_1, c1070_p_1, cp_2, c1070, c1071, f, fp_0, w, wp_0, x, xp_0, x1296_p_0, x1297_p_0, xp_1, x1296_p_1, xp_2, x1296, x1297, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y640 = 0;
IND_TYPE x1298 = 0;
IND_TYPE h = 0;
IND_TYPE w536 = 0;
IND_TYPE c1072 = 0;
IND_TYPE f1044 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8340 ,mem_vec_8341 ,mem_vec_8342 ,mem_vec_8343 ,mem_vec_8344 ,mem_vec_8345 ,mem_vec_8346 ,mem_vec_8347 ,mem_vec_8348 ,mem_vec_8349 ,mem_vec_8350 ,mem_vec_8351 ,mem_vec_8352 ,mem_vec_8353 ,mem_vec_8354 ,mem_vec_8355 ,mem_vec_8356 ,mem_vec_8357 ,mem_vec_8358 ,mem_vec_8359 ,mem_vec_8360 ,mem_vec_8361 ,mem_vec_8362 ,mem_vec_8363 ,mem_vec_8364 ,mem_vec_8365 ,mem_vec_8366 ,mem_vec_8367 ,mem_vec_8368 ,mem_vec_8369 ,mem_vec_8370 ,mem_vec_8371 ,mem_vec_8372 ,mem_vec_8373 ,mem_vec_8374 ,mem_vec_8375 ,mem_vec_8376 ,mem_vec_8377 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 28) (28 / 1)
for (x1297 = x1298, x1297_p_0 = 0;
	x1297 < x1298 + 28;
	x1297 += 1, x1297_p_0 += 1){
	// y = 28, x = 1, h = 3, w = 3, c = 128, f = 128
	// T (c, 1) (128 / 128)
	for (c1071 = c1072, c1071_p_0 = 0;
		c1071 < c1072 + 128;
		c1071 += 128, c1071_p_0 += 128){
		// y = 28, x = 1, h = 3, w = 3, c = 128, f = 128
		// T (f, 8) (128 / 16)
		for (f = f1044, fp_0 = 0;
			f < f1044 + 128;
			f += 16, fp_0 += 16){
				for (y = y640, yp_0 = 0;
					y < y640 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
					// T (x, 1) (1 / 1)
					for (x1296 = x1297, x1296_p_1 = x1297_p_0, x1296_p_0 = 0;
						x1296 < x1297 + 1;
						x1296 += 1, x1296_p_1 += 1, x1296_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (c, 4) (128 / 32)
						for (c1070 = c1071, c1070_p_1 = c1071_p_0, c1070_p_0 = 0;
							c1070 < c1071 + 128;
							c1070 += 32, c1070_p_1 += 32, c1070_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w536, wp_0 = 0;
								w < w536 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1296, xp_2 = x1296_p_1, xp_1 = x1296_p_0, xp_0 = 0;
									x < x1296 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8340 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8341 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_8354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_8356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c1070, cp_2 = c1070_p_1, cp_1 = c1070_p_0, cp_0 = 0;
												c < c1070 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8340);
												mem_vec_8340 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8341);
												mem_vec_8341 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8342);
												mem_vec_8342 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8343);
												mem_vec_8343 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8344);
												mem_vec_8344 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8345);
												mem_vec_8345 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8346);
												mem_vec_8346 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8347);
												mem_vec_8347 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8348);
												mem_vec_8348 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8349);
												mem_vec_8349 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8350);
												mem_vec_8350 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8351);
												mem_vec_8351 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8352);
												mem_vec_8352 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8353);
												mem_vec_8353 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8354);
												mem_vec_8354 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8355);
												mem_vec_8355 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8356);
												mem_vec_8356 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8357);
												mem_vec_8357 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8340);
												mem_vec_8340 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8341);
												mem_vec_8341 = vec_32;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_8342);
												mem_vec_8342 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_8343);
												mem_vec_8343 = vec_36;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_8344);
												mem_vec_8344 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_8345);
												mem_vec_8345 = vec_39;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_8346);
												mem_vec_8346 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_8347);
												mem_vec_8347 = vec_42;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8348);
												mem_vec_8348 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8349);
												mem_vec_8349 = vec_45;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_8350);
												mem_vec_8350 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_8351);
												mem_vec_8351 = vec_48;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_8352);
												mem_vec_8352 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_8353);
												mem_vec_8353 = vec_51;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_8354);
												mem_vec_8354 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_8355);
												mem_vec_8355 = vec_54;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_8356);
												mem_vec_8356 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_8357);
												mem_vec_8357 = vec_57;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8340);
												mem_vec_8340 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8341);
												mem_vec_8341 = vec_61;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_8342);
												mem_vec_8342 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_8343);
												mem_vec_8343 = vec_65;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_8344);
												mem_vec_8344 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_8345);
												mem_vec_8345 = vec_68;
												scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_8346);
												mem_vec_8346 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_8347);
												mem_vec_8347 = vec_71;
												scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8348);
												mem_vec_8348 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8349);
												mem_vec_8349 = vec_74;
												scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_8350);
												mem_vec_8350 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_8351);
												mem_vec_8351 = vec_77;
												scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_8352);
												mem_vec_8352 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_8353);
												mem_vec_8353 = vec_80;
												scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_8354);
												mem_vec_8354 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_8355);
												mem_vec_8355 = vec_83;
												scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_8356);
												mem_vec_8356 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_8357);
												mem_vec_8357 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8343);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8357);
								}
							}
						}
					}
				}
				for (y = y640 + 18, yp_0 = 0;
					y < y640 + 18 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
					// T (x, 1) (1 / 1)
					for (x1296 = x1297, x1296_p_1 = x1297_p_0, x1296_p_0 = 0;
						x1296 < x1297 + 1;
						x1296 += 1, x1296_p_1 += 1, x1296_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (c, 4) (128 / 32)
						for (c1070 = c1071, c1070_p_1 = c1071_p_0, c1070_p_0 = 0;
							c1070 < c1071 + 128;
							c1070 += 32, c1070_p_1 += 32, c1070_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w536, wp_0 = 0;
								w < w536 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1296, xp_2 = x1296_p_1, xp_1 = x1296_p_0, xp_0 = 0;
									x < x1296 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8358 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8359 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_8370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_8372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_8374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_8376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c1070, cp_2 = c1070_p_1, cp_1 = c1070_p_0, cp_0 = 0;
												c < c1070 + 32;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8358);
												mem_vec_8358 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8359);
												mem_vec_8359 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8360);
												mem_vec_8360 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8361);
												mem_vec_8361 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8362);
												mem_vec_8362 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8363);
												mem_vec_8363 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8364);
												mem_vec_8364 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8365);
												mem_vec_8365 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8366);
												mem_vec_8366 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8367);
												mem_vec_8367 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8368);
												mem_vec_8368 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8369);
												mem_vec_8369 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8370);
												mem_vec_8370 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8371);
												mem_vec_8371 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8372);
												mem_vec_8372 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8373);
												mem_vec_8373 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8374);
												mem_vec_8374 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8375);
												mem_vec_8375 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8376);
												mem_vec_8376 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8377);
												mem_vec_8377 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_8358);
												mem_vec_8358 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_8359);
												mem_vec_8359 = vec_35;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_8360);
												mem_vec_8360 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_8361);
												mem_vec_8361 = vec_39;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_8362);
												mem_vec_8362 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_8363);
												mem_vec_8363 = vec_42;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_8364);
												mem_vec_8364 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8365);
												mem_vec_8365 = vec_45;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_8366);
												mem_vec_8366 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_8367);
												mem_vec_8367 = vec_48;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_8368);
												mem_vec_8368 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_8369);
												mem_vec_8369 = vec_51;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_8370);
												mem_vec_8370 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_8371);
												mem_vec_8371 = vec_54;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_8372);
												mem_vec_8372 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_8373);
												mem_vec_8373 = vec_57;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_8374);
												mem_vec_8374 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8375);
												mem_vec_8375 = vec_60;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_8376);
												mem_vec_8376 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_8377);
												mem_vec_8377 = vec_63;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_8358);
												mem_vec_8358 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_8359);
												mem_vec_8359 = vec_67;
												scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_8360);
												mem_vec_8360 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_8361);
												mem_vec_8361 = vec_71;
												scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8362);
												mem_vec_8362 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_8363);
												mem_vec_8363 = vec_74;
												scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_8364);
												mem_vec_8364 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_8365);
												mem_vec_8365 = vec_77;
												scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_8366);
												mem_vec_8366 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_8367);
												mem_vec_8367 = vec_80;
												scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_8368);
												mem_vec_8368 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_8369);
												mem_vec_8369 = vec_83;
												scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_8370);
												mem_vec_8370 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_8371);
												mem_vec_8371 = vec_86;
												scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_8372);
												mem_vec_8372 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_8373);
												mem_vec_8373 = vec_89;
												scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_8374);
												mem_vec_8374 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_8375);
												mem_vec_8375 = vec_92;
												scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_8376);
												mem_vec_8376 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_8377);
												mem_vec_8377 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8377);
								}
							}
						}
					}
				}
		}
	}
}


}