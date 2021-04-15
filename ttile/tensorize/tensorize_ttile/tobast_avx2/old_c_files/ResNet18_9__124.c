#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (8, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1020_p_0, cp_1, c1020, f, fp_0, f1360_p_0, f1361_p_0, fp_1, f1360_p_1, fp_2, f1360, f1361, h, hp_0, x, xp_0, x1020_p_0, xp_1, x1020, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y680 = 0;
IND_TYPE x1021 = 0;
IND_TYPE h502 = 0;
IND_TYPE w = 0;
IND_TYPE c1021 = 0;
IND_TYPE f1362 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11344 ,mem_vec_11345 ,mem_vec_11346 ,mem_vec_11347 ,mem_vec_11348 ,mem_vec_11349 ,mem_vec_11350 ,mem_vec_11351 ,mem_vec_11352 ,mem_vec_11353 ,mem_vec_11354 ,mem_vec_11355 ,mem_vec_11356 ,mem_vec_11357 ,mem_vec_11358 ,mem_vec_11359 ,mem_vec_11360 ,mem_vec_11361 ,mem_vec_11362 ,mem_vec_11363 ,mem_vec_11364 ,mem_vec_11365 ,mem_vec_11366 ,mem_vec_11367 ,mem_vec_11368 ,mem_vec_11369 ,mem_vec_11370 ,mem_vec_11371 ,mem_vec_11372 ,mem_vec_11373 ,mem_vec_11374 ,mem_vec_11375 ,mem_vec_11376 ,mem_vec_11377 ,mem_vec_11378 ,mem_vec_11379 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1361 = f1362, f1361_p_0 = 0;
	f1361 < f1362 + 256;
	f1361 += 256, f1361_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (c, 16) (256 / 16)
	for (c1020 = c1021, c1020_p_0 = 0;
		c1020 < c1021 + 256;
		c1020 += 16, c1020_p_0 += 16){
		// y = 14, x = 14, h = 3, w = 3, c = 16, f = 256
		// T (f, 8) (256 / 32)
		for (f1360 = f1361, f1360_p_1 = f1361_p_0, f1360_p_0 = 0;
			f1360 < f1361 + 256;
			f1360 += 32, f1360_p_1 += 32, f1360_p_0 += 32){
				for (y = y680, yp_0 = 0;
					y < y680 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 7) (14 / 2)
					for (x1020 = x1021, x1020_p_0 = 0;
						x1020 < x1021 + 14;
						x1020 += 2, x1020_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1360, fp_2 = f1360_p_1, fp_1 = f1360_p_0, fp_0 = 0;
							f < f1360 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h502, hp_0 = 0;
								h < h502 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1020, xp_1 = x1020_p_0, xp_0 = 0;
									x < x1020 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11344 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11345 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11346 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11347 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1020, cp_1 = c1020_p_0, cp_0 = 0;
												c < c1020 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11344);
												mem_vec_11344 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11345);
												mem_vec_11345 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11346);
												mem_vec_11346 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11347);
												mem_vec_11347 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11348);
												mem_vec_11348 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11349);
												mem_vec_11349 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11350);
												mem_vec_11350 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11351);
												mem_vec_11351 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11352);
												mem_vec_11352 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11353);
												mem_vec_11353 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11354);
												mem_vec_11354 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11355);
												mem_vec_11355 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11356);
												mem_vec_11356 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11357);
												mem_vec_11357 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11358);
												mem_vec_11358 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11359);
												mem_vec_11359 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11344);
												mem_vec_11344 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11345);
												mem_vec_11345 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11346);
												mem_vec_11346 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11347);
												mem_vec_11347 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11348);
												mem_vec_11348 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11349);
												mem_vec_11349 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11350);
												mem_vec_11350 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11351);
												mem_vec_11351 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11352);
												mem_vec_11352 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11353);
												mem_vec_11353 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11354);
												mem_vec_11354 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11355);
												mem_vec_11355 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11356);
												mem_vec_11356 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11357);
												mem_vec_11357 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11358);
												mem_vec_11358 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11359);
												mem_vec_11359 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11344);
												mem_vec_11344 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11345);
												mem_vec_11345 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11346);
												mem_vec_11346 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11347);
												mem_vec_11347 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11348);
												mem_vec_11348 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11349);
												mem_vec_11349 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11350);
												mem_vec_11350 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11351);
												mem_vec_11351 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11352);
												mem_vec_11352 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11353);
												mem_vec_11353 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11354);
												mem_vec_11354 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11355);
												mem_vec_11355 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11356);
												mem_vec_11356 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11357);
												mem_vec_11357 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11358);
												mem_vec_11358 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11359);
												mem_vec_11359 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11359);
								}
							}
						}
					}
				}
				for (y = y680 + 4, yp_0 = 0;
					y < y680 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 7) (14 / 2)
					for (x1020 = x1021, x1020_p_0 = 0;
						x1020 < x1021 + 14;
						x1020 += 2, x1020_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1360, fp_2 = f1360_p_1, fp_1 = f1360_p_0, fp_0 = 0;
							f < f1360 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h502, hp_0 = 0;
								h < h502 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1020, xp_1 = x1020_p_0, xp_0 = 0;
									x < x1020 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_11376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_11378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c1020, cp_1 = c1020_p_0, cp_0 = 0;
												c < c1020 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11360);
												mem_vec_11360 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11361);
												mem_vec_11361 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11362);
												mem_vec_11362 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11363);
												mem_vec_11363 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11364);
												mem_vec_11364 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11365);
												mem_vec_11365 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11366);
												mem_vec_11366 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11367);
												mem_vec_11367 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11368);
												mem_vec_11368 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11369);
												mem_vec_11369 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11370);
												mem_vec_11370 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11371);
												mem_vec_11371 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11372);
												mem_vec_11372 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11373);
												mem_vec_11373 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11374);
												mem_vec_11374 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11375);
												mem_vec_11375 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11376);
												mem_vec_11376 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11377);
												mem_vec_11377 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11378);
												mem_vec_11378 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11379);
												mem_vec_11379 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11360);
												mem_vec_11360 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11361);
												mem_vec_11361 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11362);
												mem_vec_11362 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11363);
												mem_vec_11363 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11364);
												mem_vec_11364 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11365);
												mem_vec_11365 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11366);
												mem_vec_11366 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11367);
												mem_vec_11367 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11368);
												mem_vec_11368 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11369);
												mem_vec_11369 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11370);
												mem_vec_11370 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11371);
												mem_vec_11371 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11372);
												mem_vec_11372 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11373);
												mem_vec_11373 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11374);
												mem_vec_11374 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11375);
												mem_vec_11375 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11376);
												mem_vec_11376 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11377);
												mem_vec_11377 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11378);
												mem_vec_11378 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11379);
												mem_vec_11379 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11360);
												mem_vec_11360 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11361);
												mem_vec_11361 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11362);
												mem_vec_11362 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11363);
												mem_vec_11363 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11364);
												mem_vec_11364 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11365);
												mem_vec_11365 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11366);
												mem_vec_11366 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11367);
												mem_vec_11367 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11368);
												mem_vec_11368 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11369);
												mem_vec_11369 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11370);
												mem_vec_11370 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11371);
												mem_vec_11371 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11372);
												mem_vec_11372 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11373);
												mem_vec_11373 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11374);
												mem_vec_11374 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11375);
												mem_vec_11375 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11376);
												mem_vec_11376 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11377);
												mem_vec_11377 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11378);
												mem_vec_11378 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11379);
												mem_vec_11379 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11361);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11379);
								}
							}
						}
					}
				}
		}
	}
}


}