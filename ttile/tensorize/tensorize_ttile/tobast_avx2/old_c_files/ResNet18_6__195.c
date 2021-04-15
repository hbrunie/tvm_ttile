#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f);
  T (16, c); T (7, x)]
*/
IND_TYPE c, cp_0, c952_p_0, c953_p_0, cp_1, c952_p_1, cp_2, c952, c953, f, fp_0, w, wp_0, x, xp_0, x1188_p_0, x1189_p_0, xp_1, x1188_p_1, xp_2, x1188, x1189, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y576 = 0;
IND_TYPE x1190 = 0;
IND_TYPE h = 0;
IND_TYPE w482 = 0;
IND_TYPE c954 = 0;
IND_TYPE f940 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7336 ,mem_vec_7337 ,mem_vec_7338 ,mem_vec_7339 ,mem_vec_7340 ,mem_vec_7341 ,mem_vec_7342 ,mem_vec_7343 ,mem_vec_7344 ,mem_vec_7345 ,mem_vec_7346 ,mem_vec_7347 ,mem_vec_7348 ,mem_vec_7349 ,mem_vec_7350 ,mem_vec_7351 ,mem_vec_7352 ,mem_vec_7353 ,mem_vec_7354 ,mem_vec_7355 ,mem_vec_7356 ,mem_vec_7357 ,mem_vec_7358 ,mem_vec_7359 ,mem_vec_7360 ,mem_vec_7361 ,mem_vec_7362 ,mem_vec_7363 ,mem_vec_7364 ,mem_vec_7365 ,mem_vec_7366 ,mem_vec_7367 ,mem_vec_7368 ,mem_vec_7369 ,mem_vec_7370 ,mem_vec_7371 ,mem_vec_7372 ,mem_vec_7373 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (x, 7) (28 / 4)
for (x1189 = x1190, x1189_p_0 = 0;
	x1189 < x1190 + 28;
	x1189 += 4, x1189_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 128, f = 128
	// T (c, 16) (128 / 8)
	for (c953 = c954, c953_p_0 = 0;
		c953 < c954 + 128;
		c953 += 8, c953_p_0 += 8){
		// y = 28, x = 4, h = 3, w = 3, c = 8, f = 128
		// T (f, 8) (128 / 16)
		for (f = f940, fp_0 = 0;
			f < f940 + 128;
			f += 16, fp_0 += 16){
				for (y = y576, yp_0 = 0;
					y < y576 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 16
					// T (x, 4) (4 / 1)
					for (x1188 = x1189, x1188_p_1 = x1189_p_0, x1188_p_0 = 0;
						x1188 < x1189 + 4;
						x1188 += 1, x1188_p_1 += 1, x1188_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c952 = c953, c952_p_1 = c953_p_0, c952_p_0 = 0;
							c952 < c953 + 8;
							c952 += 2, c952_p_1 += 2, c952_p_0 += 2){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (w, 3) (3 / 1)
							for (w = w482, wp_0 = 0;
								w < w482 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1188, xp_2 = x1188_p_1, xp_1 = x1188_p_0, xp_0 = 0;
									x < x1188 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7336 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7337 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_7350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_7352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c952, cp_2 = c952_p_1, cp_1 = c952_p_0, cp_0 = 0;
												c < c952 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7336);
												mem_vec_7336 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7337);
												mem_vec_7337 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7338);
												mem_vec_7338 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7339);
												mem_vec_7339 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7340);
												mem_vec_7340 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7341);
												mem_vec_7341 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7342);
												mem_vec_7342 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7343);
												mem_vec_7343 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7344);
												mem_vec_7344 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7345);
												mem_vec_7345 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7346);
												mem_vec_7346 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7347);
												mem_vec_7347 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7348);
												mem_vec_7348 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7349);
												mem_vec_7349 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7350);
												mem_vec_7350 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7351);
												mem_vec_7351 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_7352);
												mem_vec_7352 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_7353);
												mem_vec_7353 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_7336);
												mem_vec_7336 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_7337);
												mem_vec_7337 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_7338);
												mem_vec_7338 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_7339);
												mem_vec_7339 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_7340);
												mem_vec_7340 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_7341);
												mem_vec_7341 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_7342);
												mem_vec_7342 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_7343);
												mem_vec_7343 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_7344);
												mem_vec_7344 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_7345);
												mem_vec_7345 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_7346);
												mem_vec_7346 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_7347);
												mem_vec_7347 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_7348);
												mem_vec_7348 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_7349);
												mem_vec_7349 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_7350);
												mem_vec_7350 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_7351);
												mem_vec_7351 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_7352);
												mem_vec_7352 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_7353);
												mem_vec_7353 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_7336);
												mem_vec_7336 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_7337);
												mem_vec_7337 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_7338);
												mem_vec_7338 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_7339);
												mem_vec_7339 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_7340);
												mem_vec_7340 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_7341);
												mem_vec_7341 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_7342);
												mem_vec_7342 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_7343);
												mem_vec_7343 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_7344);
												mem_vec_7344 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_7345);
												mem_vec_7345 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_7346);
												mem_vec_7346 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_7347);
												mem_vec_7347 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_7348);
												mem_vec_7348 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_7349);
												mem_vec_7349 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_7350);
												mem_vec_7350 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_7351);
												mem_vec_7351 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_7352);
												mem_vec_7352 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_7353);
												mem_vec_7353 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7343);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_7351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_7353);
								}
							}
						}
					}
				}
				for (y = y576 + 18, yp_0 = 0;
					y < y576 + 18 + 10;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 16
					// T (x, 4) (4 / 1)
					for (x1188 = x1189, x1188_p_1 = x1189_p_0, x1188_p_0 = 0;
						x1188 < x1189 + 4;
						x1188 += 1, x1188_p_1 += 1, x1188_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c952 = c953, c952_p_1 = c953_p_0, c952_p_0 = 0;
							c952 < c953 + 8;
							c952 += 2, c952_p_1 += 2, c952_p_0 += 2){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (w, 3) (3 / 1)
							for (w = w482, wp_0 = 0;
								w < w482 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
								// T (x, 1) (1 / 1)
								for (x = x1188, xp_2 = x1188_p_1, xp_1 = x1188_p_0, xp_0 = 0;
									x < x1188 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7354 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7355 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_7364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_7366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_7368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_7370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_7372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
											// T (c, 2) (2 / 1)
											for (c = c952, cp_2 = c952_p_1, cp_1 = c952_p_0, cp_0 = 0;
												c < c952 + 2;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7354);
												mem_vec_7354 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7355);
												mem_vec_7355 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_7356);
												mem_vec_7356 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_7357);
												mem_vec_7357 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_7358);
												mem_vec_7358 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_7359);
												mem_vec_7359 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_7360);
												mem_vec_7360 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_7361);
												mem_vec_7361 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7362);
												mem_vec_7362 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7363);
												mem_vec_7363 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7364);
												mem_vec_7364 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7365);
												mem_vec_7365 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_7366);
												mem_vec_7366 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_7367);
												mem_vec_7367 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_7368);
												mem_vec_7368 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_7369);
												mem_vec_7369 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_7370);
												mem_vec_7370 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_7371);
												mem_vec_7371 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7372);
												mem_vec_7372 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7373);
												mem_vec_7373 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_7354);
												mem_vec_7354 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_7355);
												mem_vec_7355 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_7356);
												mem_vec_7356 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_7357);
												mem_vec_7357 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_7358);
												mem_vec_7358 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_7359);
												mem_vec_7359 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_7360);
												mem_vec_7360 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_7361);
												mem_vec_7361 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_7362);
												mem_vec_7362 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_7363);
												mem_vec_7363 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_7364);
												mem_vec_7364 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_7365);
												mem_vec_7365 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_7366);
												mem_vec_7366 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_7367);
												mem_vec_7367 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_7368);
												mem_vec_7368 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_7369);
												mem_vec_7369 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_7370);
												mem_vec_7370 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_7371);
												mem_vec_7371 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_7372);
												mem_vec_7372 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_7373);
												mem_vec_7373 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_7354);
												mem_vec_7354 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_7355);
												mem_vec_7355 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_7356);
												mem_vec_7356 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_7357);
												mem_vec_7357 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_7358);
												mem_vec_7358 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_7359);
												mem_vec_7359 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_7360);
												mem_vec_7360 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_7361);
												mem_vec_7361 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_7362);
												mem_vec_7362 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_7363);
												mem_vec_7363 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_7364);
												mem_vec_7364 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_7365);
												mem_vec_7365 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_7366);
												mem_vec_7366 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_7367);
												mem_vec_7367 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_7368);
												mem_vec_7368 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_7369);
												mem_vec_7369 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_7370);
												mem_vec_7370 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_7371);
												mem_vec_7371 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_7372);
												mem_vec_7372 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_7373);
												mem_vec_7373 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_7369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_7371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_7373);
								}
							}
						}
					}
				}
		}
	}
}


}