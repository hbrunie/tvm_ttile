#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (8, x);
  T (3, w); T (2, c); T (2, y); T (8, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (1, x)]
*/
IND_TYPE c, cp_0, c207_p_0, cp_1, c207, f, fp_0, w, wp_0, x, xp_0, x276_p_0, x277_p_0, xp_1, x276_p_1, xp_2, x276, x277, y, yp_0, y180_p_0, yp_1, y180;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y181 = 0;
IND_TYPE x278 = 0;
IND_TYPE h = 0;
IND_TYPE w129 = 0;
IND_TYPE c208 = 0;
IND_TYPE f165 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2346 ,mem_vec_2347 ,mem_vec_2348 ,mem_vec_2349 ,mem_vec_2350 ,mem_vec_2351 ,mem_vec_2352 ,mem_vec_2353 ,mem_vec_2354 ,mem_vec_2355 ,mem_vec_2356 ,mem_vec_2357 ,mem_vec_2358 ,mem_vec_2359 ,mem_vec_2360 ,mem_vec_2361 ,mem_vec_2362 ,mem_vec_2363 ,mem_vec_2364 ,mem_vec_2365 ,mem_vec_2366 ,mem_vec_2367 ,mem_vec_2368 ,mem_vec_2369 ,mem_vec_2370 ,mem_vec_2371 ,mem_vec_2372 ,mem_vec_2373 ,mem_vec_2374 ,mem_vec_2375 ,mem_vec_2376 ,mem_vec_2377 ,mem_vec_2378 ,mem_vec_2379 ,mem_vec_2380 ,mem_vec_2381 ,mem_vec_2382 ,mem_vec_2383 ,mem_vec_2384 ,mem_vec_2385 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x277 = x278, x277_p_0 = 0;
	x277 < x278 + 136;
	x277 += 136, x277_p_0 += 136){
		for (y180 = y181, y180_p_0 = 0;
			y180 < y181 + 16;
			y180 += 16, y180_p_0 += 16){
			// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 17) (136 / 8)
			for (x276 = x277, x276_p_1 = x277_p_0, x276_p_0 = 0;
				x276 < x277 + 136;
				x276 += 8, x276_p_1 += 8, x276_p_0 += 8){
				// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f165, fp_0 = 0;
					f < f165 + 128;
					f += 16, fp_0 += 16){
					// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
					// T (y, 2) (2 * ph_y / ph_y)
					for (y = y180, yp_1 = y180_p_0, yp_0 = 0;
						y < y180 + 16;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c207 = c208, c207_p_0 = 0;
							c207 < c208 + 64;
							c207 += 32, c207_p_0 += 32){
							// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w129, wp_0 = 0;
								w < w129 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 32, f = 16
								// T (x, 8) (8 / 1)
								for (x = x276, xp_2 = x276_p_1, xp_1 = x276_p_0, xp_0 = 0;
									x < x276 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2346 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2347 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c207, cp_1 = c207_p_0, cp_0 = 0;
												c < c207 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2346);
												mem_vec_2346 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2347);
												mem_vec_2347 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2348);
												mem_vec_2348 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2349);
												mem_vec_2349 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2350);
												mem_vec_2350 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2351);
												mem_vec_2351 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2352);
												mem_vec_2352 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2353);
												mem_vec_2353 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2354);
												mem_vec_2354 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2355);
												mem_vec_2355 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2356);
												mem_vec_2356 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2357);
												mem_vec_2357 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2358);
												mem_vec_2358 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2359);
												mem_vec_2359 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2360);
												mem_vec_2360 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2361);
												mem_vec_2361 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_2346);
												mem_vec_2346 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_2347);
												mem_vec_2347 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_2348);
												mem_vec_2348 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_2349);
												mem_vec_2349 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_2350);
												mem_vec_2350 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_2351);
												mem_vec_2351 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_2352);
												mem_vec_2352 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_2353);
												mem_vec_2353 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_2354);
												mem_vec_2354 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_2355);
												mem_vec_2355 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2356);
												mem_vec_2356 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2357);
												mem_vec_2357 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_2358);
												mem_vec_2358 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_2359);
												mem_vec_2359 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_2360);
												mem_vec_2360 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_2361);
												mem_vec_2361 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_2346);
												mem_vec_2346 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_2347);
												mem_vec_2347 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2348);
												mem_vec_2348 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2349);
												mem_vec_2349 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_2350);
												mem_vec_2350 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_2351);
												mem_vec_2351 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_2352);
												mem_vec_2352 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_2353);
												mem_vec_2353 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_2354);
												mem_vec_2354 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_2355);
												mem_vec_2355 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_2356);
												mem_vec_2356 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_2357);
												mem_vec_2357 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_2358);
												mem_vec_2358 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_2359);
												mem_vec_2359 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_2360);
												mem_vec_2360 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_2361);
												mem_vec_2361 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2346);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2347);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2348);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2349);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2350);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2351);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2352);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2353);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2354);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2355);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2356);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2357);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2358);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2359);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2360);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2361);
								}
							}
						}
					}
				}
			}
		}
		for (y180 = y181 + 16, y180_p_0 = 0;
			y180 < y181 + 16 + 120;
			y180 += 24, y180_p_0 += 24){
			// y = 2 * ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 17) (136 / 8)
			for (x276 = x277, x276_p_1 = x277_p_0, x276_p_0 = 0;
				x276 < x277 + 136;
				x276 += 8, x276_p_1 += 8, x276_p_0 += 8){
				// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 128
				// T (f, 8) (128 / 16)
				for (f = f165, fp_0 = 0;
					f < f165 + 128;
					f += 16, fp_0 += 16){
					// y = 2 * ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
					// T (y, 2) (2 * ph_y / ph_y)
					for (y = y180, yp_1 = y180_p_0, yp_0 = 0;
						y < y180 + 24;
						y += 12, yp_1 += 12, yp_0 += 12){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 16
						// T (c, 2) (64 / 32)
						for (c207 = c208, c207_p_0 = 0;
							c207 < c208 + 64;
							c207 += 32, c207_p_0 += 32){
							// y = ph_y, x = 8, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w129, wp_0 = 0;
								w < w129 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 3, w = 1, c = 32, f = 16
								// T (x, 8) (8 / 1)
								for (x = x276, xp_2 = x276_p_1, xp_1 = x276_p_0, xp_0 = 0;
									x < x276 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_2378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_2380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_2382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_2384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c207, cp_1 = c207_p_0, cp_0 = 0;
												c < c207 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2362);
												mem_vec_2362 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2363);
												mem_vec_2363 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2364);
												mem_vec_2364 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2365);
												mem_vec_2365 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2366);
												mem_vec_2366 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2367);
												mem_vec_2367 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2368);
												mem_vec_2368 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2369);
												mem_vec_2369 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2370);
												mem_vec_2370 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2371);
												mem_vec_2371 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2372);
												mem_vec_2372 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2373);
												mem_vec_2373 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2374);
												mem_vec_2374 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2375);
												mem_vec_2375 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2376);
												mem_vec_2376 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2377);
												mem_vec_2377 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_2378);
												mem_vec_2378 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_2379);
												mem_vec_2379 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2380);
												mem_vec_2380 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2381);
												mem_vec_2381 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_2382);
												mem_vec_2382 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_2383);
												mem_vec_2383 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_2384);
												mem_vec_2384 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_2385);
												mem_vec_2385 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_2362);
												mem_vec_2362 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_2363);
												mem_vec_2363 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_2364);
												mem_vec_2364 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_2365);
												mem_vec_2365 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_2366);
												mem_vec_2366 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_2367);
												mem_vec_2367 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_2368);
												mem_vec_2368 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_2369);
												mem_vec_2369 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_2370);
												mem_vec_2370 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_2371);
												mem_vec_2371 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_2372);
												mem_vec_2372 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_2373);
												mem_vec_2373 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_2374);
												mem_vec_2374 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_2375);
												mem_vec_2375 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_2376);
												mem_vec_2376 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_2377);
												mem_vec_2377 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_2378);
												mem_vec_2378 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_2379);
												mem_vec_2379 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_2380);
												mem_vec_2380 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_2381);
												mem_vec_2381 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_2382);
												mem_vec_2382 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_2383);
												mem_vec_2383 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_2384);
												mem_vec_2384 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_2385);
												mem_vec_2385 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_2362);
												mem_vec_2362 = vec_76;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_2363);
												mem_vec_2363 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_2364);
												mem_vec_2364 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_2365);
												mem_vec_2365 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_2366);
												mem_vec_2366 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_2367);
												mem_vec_2367 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_2368);
												mem_vec_2368 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_2369);
												mem_vec_2369 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_2370);
												mem_vec_2370 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_2371);
												mem_vec_2371 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_2372);
												mem_vec_2372 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_2373);
												mem_vec_2373 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_2374);
												mem_vec_2374 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_2375);
												mem_vec_2375 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_2376);
												mem_vec_2376 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_2377);
												mem_vec_2377 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_2378);
												mem_vec_2378 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_2379);
												mem_vec_2379 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_2380);
												mem_vec_2380 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_2381);
												mem_vec_2381 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_2382);
												mem_vec_2382 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_2383);
												mem_vec_2383 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_2384);
												mem_vec_2384 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_2385);
												mem_vec_2385 = vec_113;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2362);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2363);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2364);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2365);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2366);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2367);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2368);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2369);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2370);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2371);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2372);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2373);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2374);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2375);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2376);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2377);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2378);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_2379);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2380);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_2381);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2382);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_2383);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2384);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_2385);
								}
							}
						}
					}
				}
			}
		}
}


}