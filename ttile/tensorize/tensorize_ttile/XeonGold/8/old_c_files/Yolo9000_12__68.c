#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, x);
  T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c21_p_0, cp_1, c21, f, fp_0, f26_p_0, f27_p_0, fp_1, f26_p_1, fp_2, f26, f27, h, hp_0, x, xp_0, x22_p_0, xp_1, x22, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y15 = 0;
IND_TYPE x23 = 0;
IND_TYPE h14 = 0;
IND_TYPE w = 0;
IND_TYPE c22 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f27 = f28, f27_p_0 = 0;
	f27 < f28 + 512;
	f27 += 512, f27_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (f, 8) (512 / 64)
	for (f26 = f27, f26_p_1 = f27_p_0, f26_p_0 = 0;
		f26 < f27 + 512;
		f26 += 64, f26_p_1 += 64, f26_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
		// T (x, 1) (34 / 34)
		for (x22 = x23, x22_p_0 = 0;
			x22 < x23 + 34;
			x22 += 34, x22_p_0 += 34){
				for (y = y15, yp_0 = 0;
					y < y15 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f26, fp_2 = f26_p_1, fp_1 = f26_p_0, fp_0 = 0;
						f < f26 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c21 = c22, c21_p_0 = 0;
							c21 < c22 + 256;
							c21 += 256, c21_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h14, hp_0 = 0;
								h < h14 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x22, xp_1 = x22_p_0, xp_0 = 0;
									x < x22 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_334 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_335 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_337 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
												c < c21 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_334);
												mem_vec_334 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_335);
												mem_vec_335 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_336);
												mem_vec_336 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_337);
												mem_vec_337 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_338);
												mem_vec_338 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_339);
												mem_vec_339 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_340);
												mem_vec_340 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_341);
												mem_vec_341 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_342);
												mem_vec_342 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_343);
												mem_vec_343 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_344);
												mem_vec_344 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_345);
												mem_vec_345 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_346);
												mem_vec_346 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_347);
												mem_vec_347 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_348);
												mem_vec_348 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_349);
												mem_vec_349 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_334);
												mem_vec_334 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_335);
												mem_vec_335 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_336);
												mem_vec_336 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_337);
												mem_vec_337 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_338);
												mem_vec_338 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_339);
												mem_vec_339 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_340);
												mem_vec_340 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_341);
												mem_vec_341 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_342);
												mem_vec_342 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_343);
												mem_vec_343 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_344);
												mem_vec_344 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_345);
												mem_vec_345 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_346);
												mem_vec_346 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_347);
												mem_vec_347 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_348);
												mem_vec_348 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_349);
												mem_vec_349 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_334);
												mem_vec_334 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_335);
												mem_vec_335 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_336);
												mem_vec_336 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_337);
												mem_vec_337 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_338);
												mem_vec_338 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_339);
												mem_vec_339 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_340);
												mem_vec_340 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_341);
												mem_vec_341 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_342);
												mem_vec_342 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_343);
												mem_vec_343 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_344);
												mem_vec_344 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_345);
												mem_vec_345 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_346);
												mem_vec_346 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_347);
												mem_vec_347 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_348);
												mem_vec_348 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_349);
												mem_vec_349 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_334);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_335);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_336);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_337);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_338);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_339);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_340);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_341);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_342);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_343);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_344);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_345);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_346);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_347);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_348);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_349);
								}
							}
						}
					}
				}
				for (y = y15 + 4, yp_0 = 0;
					y < y15 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f26, fp_2 = f26_p_1, fp_1 = f26_p_0, fp_0 = 0;
						f < f26 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c21 = c22, c21_p_0 = 0;
							c21 < c22 + 256;
							c21 += 256, c21_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h14, hp_0 = 0;
								h < h14 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x22, xp_1 = x22_p_0, xp_0 = 0;
									x < x22 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_350 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_351 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c21, cp_1 = c21_p_0, cp_0 = 0;
												c < c21 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_350);
												mem_vec_350 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_351);
												mem_vec_351 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_352);
												mem_vec_352 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_353);
												mem_vec_353 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_354);
												mem_vec_354 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_355);
												mem_vec_355 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_356);
												mem_vec_356 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_357);
												mem_vec_357 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_358);
												mem_vec_358 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_359);
												mem_vec_359 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_360);
												mem_vec_360 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_361);
												mem_vec_361 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_362);
												mem_vec_362 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_363);
												mem_vec_363 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_364);
												mem_vec_364 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_365);
												mem_vec_365 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_366);
												mem_vec_366 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_367);
												mem_vec_367 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_368);
												mem_vec_368 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_369);
												mem_vec_369 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_370);
												mem_vec_370 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_371);
												mem_vec_371 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_372);
												mem_vec_372 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_373);
												mem_vec_373 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_350);
												mem_vec_350 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_351);
												mem_vec_351 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_352);
												mem_vec_352 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_353);
												mem_vec_353 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_354);
												mem_vec_354 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_355);
												mem_vec_355 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_356);
												mem_vec_356 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_357);
												mem_vec_357 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_358);
												mem_vec_358 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_359);
												mem_vec_359 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_360);
												mem_vec_360 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_361);
												mem_vec_361 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_362);
												mem_vec_362 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_363);
												mem_vec_363 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_364);
												mem_vec_364 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_365);
												mem_vec_365 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_366);
												mem_vec_366 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_367);
												mem_vec_367 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_368);
												mem_vec_368 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_369);
												mem_vec_369 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_370);
												mem_vec_370 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_371);
												mem_vec_371 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_372);
												mem_vec_372 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_373);
												mem_vec_373 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_350);
												mem_vec_350 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_351);
												mem_vec_351 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_352);
												mem_vec_352 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_353);
												mem_vec_353 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_354);
												mem_vec_354 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_355);
												mem_vec_355 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_356);
												mem_vec_356 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_357);
												mem_vec_357 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_358);
												mem_vec_358 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_359);
												mem_vec_359 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_360);
												mem_vec_360 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_361);
												mem_vec_361 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_362);
												mem_vec_362 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_363);
												mem_vec_363 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_364);
												mem_vec_364 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_365);
												mem_vec_365 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_366);
												mem_vec_366 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_367);
												mem_vec_367 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_368);
												mem_vec_368 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_369);
												mem_vec_369 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_370);
												mem_vec_370 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_371);
												mem_vec_371 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_372);
												mem_vec_372 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_373);
												mem_vec_373 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_350);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_351);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_352);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_353);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_354);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_355);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_356);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_357);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_358);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_359);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_363);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_364);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_365);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_366);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_367);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_373);
								}
							}
						}
					}
				}
		}
	}
}


}