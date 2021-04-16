#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (3, w);
  T (68, x); T (1, c); T (16, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (1, c)]
*/
IND_TYPE c, cp_0, c39_p_0, c40_p_0, c41_p_0, cp_1, c39_p_1, c40_p_1, cp_2, c39_p_2, cp_3, c39, c40, c41, f, fp_0, w, wp_0, x, xp_0, x27_p_0, xp_1, x27, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y18 = 0;
IND_TYPE x28 = 0;
IND_TYPE h = 0;
IND_TYPE w12 = 0;
IND_TYPE c42 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,mem_vec_334 ,mem_vec_335 ,mem_vec_336 ,mem_vec_337 ,mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,mem_vec_346 ,mem_vec_347 ,mem_vec_348 ,mem_vec_349 ,mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c41 = c42, c41_p_0 = 0;
	c41 < c42 + 128;
	c41 += 128, c41_p_0 += 128){
		for (y = y18, yp_0 = 0;
			y < y18 + 55;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x27 = x28, x27_p_0 = 0;
				x27 < x28 + 68;
				x27 += 68, x27_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c40 = c41, c40_p_1 = c41_p_0, c40_p_0 = 0;
					c40 < c41 + 128;
					c40 += 128, c40_p_1 += 128, c40_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f24, fp_0 = 0;
						f < f24 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 1) (128 / 128)
						for (c39 = c40, c39_p_2 = c40_p_1, c39_p_1 = c40_p_0, c39_p_0 = 0;
							c39 < c40 + 128;
							c39 += 128, c39_p_2 += 128, c39_p_1 += 128, c39_p_0 += 128){
							// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
							// T (x, 68) (68 / 1)
							for (x = x27, xp_1 = x27_p_0, xp_0 = 0;
								x < x27 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
											mem_vec_312 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_313 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_328 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_329 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_330 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_331 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
											// T (c, 128) (128 / 1)
											for (c = c39, cp_3 = c39_p_2, cp_2 = c39_p_1, cp_1 = c39_p_0, cp_0 = 0;
												c < c39 + 128;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_312);
												mem_vec_312 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_313);
												mem_vec_313 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_314);
												mem_vec_314 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_315);
												mem_vec_315 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_316);
												mem_vec_316 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_317);
												mem_vec_317 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_318);
												mem_vec_318 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_319);
												mem_vec_319 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_320);
												mem_vec_320 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_321);
												mem_vec_321 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_322);
												mem_vec_322 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_323);
												mem_vec_323 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_324);
												mem_vec_324 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_325);
												mem_vec_325 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_326);
												mem_vec_326 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_327);
												mem_vec_327 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_328);
												mem_vec_328 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_329);
												mem_vec_329 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_330);
												mem_vec_330 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_331);
												mem_vec_331 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_332);
												mem_vec_332 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_333);
												mem_vec_333 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_312);
												mem_vec_312 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_313);
												mem_vec_313 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_314);
												mem_vec_314 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_315);
												mem_vec_315 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_316);
												mem_vec_316 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_317);
												mem_vec_317 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_318);
												mem_vec_318 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_319);
												mem_vec_319 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_320);
												mem_vec_320 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_321);
												mem_vec_321 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_322);
												mem_vec_322 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_323);
												mem_vec_323 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_324);
												mem_vec_324 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_325);
												mem_vec_325 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_326);
												mem_vec_326 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_327);
												mem_vec_327 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_328);
												mem_vec_328 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_329);
												mem_vec_329 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_330);
												mem_vec_330 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_331);
												mem_vec_331 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_332);
												mem_vec_332 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_333);
												mem_vec_333 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_312);
												mem_vec_312 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_313);
												mem_vec_313 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_314);
												mem_vec_314 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_315);
												mem_vec_315 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_316);
												mem_vec_316 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_317);
												mem_vec_317 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_318);
												mem_vec_318 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_319);
												mem_vec_319 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_320);
												mem_vec_320 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_321);
												mem_vec_321 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_322);
												mem_vec_322 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_323);
												mem_vec_323 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_324);
												mem_vec_324 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_325);
												mem_vec_325 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_326);
												mem_vec_326 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_327);
												mem_vec_327 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_328);
												mem_vec_328 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_329);
												mem_vec_329 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_330);
												mem_vec_330 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_331);
												mem_vec_331 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_332);
												mem_vec_332 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_333);
												mem_vec_333 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_312);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_313);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_314);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_315);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_316);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_317);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_318);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_319);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_320);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_321);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_322);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_323);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_324);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_325);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_326);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_327);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_328);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_329);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_330);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_331);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_332);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_333);
								}
							}
						}
					}
				}
			}
		}
		for (y = y18 + 55, yp_0 = 0;
			y < y18 + 55 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x27 = x28, x27_p_0 = 0;
				x27 < x28 + 68;
				x27 += 68, x27_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c40 = c41, c40_p_1 = c41_p_0, c40_p_0 = 0;
					c40 < c41 + 128;
					c40 += 128, c40_p_1 += 128, c40_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f24, fp_0 = 0;
						f < f24 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 1) (128 / 128)
						for (c39 = c40, c39_p_2 = c40_p_1, c39_p_1 = c40_p_0, c39_p_0 = 0;
							c39 < c40 + 128;
							c39 += 128, c39_p_2 += 128, c39_p_1 += 128, c39_p_0 += 128){
							// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
							// T (x, 68) (68 / 1)
							for (x = x27, xp_1 = x27_p_0, xp_0 = 0;
								x < x27 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
								// T (w, 3) (3 / 1)
								for (w = w12, wp_0 = 0;
									w < w12 + 3;
									w += 1, wp_0 += 1){
											mem_vec_334 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_335 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											mem_vec_358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
											// T (c, 128) (128 / 1)
											for (c = c39, cp_3 = c39_p_2, cp_2 = c39_p_1, cp_1 = c39_p_0, cp_0 = 0;
												c < c39 + 128;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_334);
												mem_vec_334 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_335);
												mem_vec_335 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_336);
												mem_vec_336 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_337);
												mem_vec_337 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_338);
												mem_vec_338 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_339);
												mem_vec_339 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_340);
												mem_vec_340 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_341);
												mem_vec_341 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_342);
												mem_vec_342 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_343);
												mem_vec_343 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_344);
												mem_vec_344 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_345);
												mem_vec_345 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_346);
												mem_vec_346 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_347);
												mem_vec_347 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_348);
												mem_vec_348 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_349);
												mem_vec_349 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_350);
												mem_vec_350 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_351);
												mem_vec_351 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_352);
												mem_vec_352 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_353);
												mem_vec_353 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_354);
												mem_vec_354 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_355);
												mem_vec_355 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_356);
												mem_vec_356 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_357);
												mem_vec_357 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm256_set1_ps(scal_12);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_358);
												mem_vec_358 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_359);
												mem_vec_359 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_42 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_334);
												mem_vec_334 = vec_41;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_335);
												mem_vec_335 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_336);
												mem_vec_336 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_337);
												mem_vec_337 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_338);
												mem_vec_338 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_339);
												mem_vec_339 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_340);
												mem_vec_340 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_341);
												mem_vec_341 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_342);
												mem_vec_342 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_343);
												mem_vec_343 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_344);
												mem_vec_344 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_345);
												mem_vec_345 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_346);
												mem_vec_346 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_347);
												mem_vec_347 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_348);
												mem_vec_348 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_349);
												mem_vec_349 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_350);
												mem_vec_350 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_351);
												mem_vec_351 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_352);
												mem_vec_352 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_353);
												mem_vec_353 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_354);
												mem_vec_354 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_355);
												mem_vec_355 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_77 = _mm256_set1_ps(scal_24);


												vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_356);
												mem_vec_356 = vec_76;



												vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_357);
												mem_vec_357 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_80 = _mm256_set1_ps(scal_25);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_358);
												mem_vec_358 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_359);
												mem_vec_359 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_334);
												mem_vec_334 = vec_82;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_335);
												mem_vec_335 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_336);
												mem_vec_336 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_337);
												mem_vec_337 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_338);
												mem_vec_338 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_339);
												mem_vec_339 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_340);
												mem_vec_340 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_341);
												mem_vec_341 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_342);
												mem_vec_342 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_343);
												mem_vec_343 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_344);
												mem_vec_344 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_345);
												mem_vec_345 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_346);
												mem_vec_346 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_347);
												mem_vec_347 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_348);
												mem_vec_348 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_349);
												mem_vec_349 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_350);
												mem_vec_350 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_351);
												mem_vec_351 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_352);
												mem_vec_352 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_353);
												mem_vec_353 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_115 = _mm256_set1_ps(scal_36);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_354);
												mem_vec_354 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_355);
												mem_vec_355 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_118 = _mm256_set1_ps(scal_37);


												vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_356);
												mem_vec_356 = vec_117;



												vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_357);
												mem_vec_357 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_121 = _mm256_set1_ps(scal_38);


												vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_358);
												mem_vec_358 = vec_120;



												vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_359);
												mem_vec_359 = vec_122;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_334);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_335);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_336);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_337);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_338);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_339);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_340);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_341);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_342);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_343);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_344);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_345);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_359);
								}
							}
						}
					}
				}
			}
		}
}


}