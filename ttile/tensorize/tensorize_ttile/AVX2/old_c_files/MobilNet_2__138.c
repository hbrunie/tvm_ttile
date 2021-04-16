#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (28, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, f, fp_0, f206_p_0, f207_p_0, fp_1, f206_p_1, fp_2, f206, f207, h, hp_0, x, xp_0, x159_p_0, xp_1, x159, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y109 = 0;
IND_TYPE x160 = 0;
IND_TYPE h71 = 0;
IND_TYPE w = 0;
IND_TYPE c160 = 0;
IND_TYPE f208 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2408 ,mem_vec_2409 ,mem_vec_2410 ,mem_vec_2411 ,mem_vec_2412 ,mem_vec_2413 ,mem_vec_2414 ,mem_vec_2415 ,mem_vec_2416 ,mem_vec_2417 ,mem_vec_2418 ,mem_vec_2419 ,mem_vec_2420 ,mem_vec_2421 ,mem_vec_2422 ,mem_vec_2423 ,mem_vec_2424 ,mem_vec_2425 ,mem_vec_2426 ,mem_vec_2427 ,mem_vec_2428 ,mem_vec_2429 ,mem_vec_2430 ,mem_vec_2431 ,mem_vec_2432 ,mem_vec_2433 ,mem_vec_2434 ,mem_vec_2435 ,mem_vec_2436 ,mem_vec_2437 ,mem_vec_2438 ,mem_vec_2439 ,mem_vec_2440 ,mem_vec_2441 ,mem_vec_2442 ,mem_vec_2443 ,mem_vec_2444 ,mem_vec_2445 ,mem_vec_2446 ,mem_vec_2447 ,mem_vec_2448 ,mem_vec_2449 ,mem_vec_2450 ,mem_vec_2451 ,mem_vec_2452 ,mem_vec_2453 ,mem_vec_2454 ,mem_vec_2455 ,mem_vec_2456 ,mem_vec_2457 ,mem_vec_2458 ,mem_vec_2459 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f207 = f208, f207_p_0 = 0;
	f207 < f208 + 64;
	f207 += 64, f207_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (f, 2) (64 / 32)
	for (f206 = f207, f206_p_1 = f207_p_0, f206_p_0 = 0;
		f206 < f207 + 64;
		f206 += 32, f206_p_1 += 32, f206_p_0 += 32){
		// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
		// T (x, 28) (56 / 2)
		for (x159 = x160, x159_p_0 = 0;
			x159 < x160 + 56;
			x159 += 2, x159_p_0 += 2){
				for (y = y109, yp_0 = 0;
					y < y109 + 42;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f206, fp_2 = f206_p_1, fp_1 = f206_p_0, fp_0 = 0;
						f < f206 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c159 = c160, c159_p_0 = 0;
							c159 < c160 + 64;
							c159 += 32, c159_p_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h71, hp_0 = 0;
								h < h71 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x159, xp_1 = x159_p_0, xp_0 = 0;
									x < x159 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2408 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2409 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2410 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2411 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_2424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_2428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
												c < c159 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2408);
												mem_vec_2408 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2409);
												mem_vec_2409 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2410);
												mem_vec_2410 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2411);
												mem_vec_2411 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2412);
												mem_vec_2412 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2413);
												mem_vec_2413 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2414);
												mem_vec_2414 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2415);
												mem_vec_2415 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2416);
												mem_vec_2416 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2417);
												mem_vec_2417 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2418);
												mem_vec_2418 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2419);
												mem_vec_2419 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2420);
												mem_vec_2420 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2421);
												mem_vec_2421 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2422);
												mem_vec_2422 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2423);
												mem_vec_2423 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2424);
												mem_vec_2424 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2425);
												mem_vec_2425 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2426);
												mem_vec_2426 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2427);
												mem_vec_2427 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2428);
												mem_vec_2428 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2429);
												mem_vec_2429 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_2430);
												mem_vec_2430 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_2431);
												mem_vec_2431 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);
												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_2408);
												mem_vec_2408 = vec_34;

												vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_2409);
												mem_vec_2409 = vec_37;

												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_2410);
												mem_vec_2410 = vec_39;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_2411);
												mem_vec_2411 = vec_41;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_2412);
												mem_vec_2412 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_2413);
												mem_vec_2413 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_2414);
												mem_vec_2414 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_2415);
												mem_vec_2415 = vec_47;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_2416);
												mem_vec_2416 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_2417);
												mem_vec_2417 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_2418);
												mem_vec_2418 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_2419);
												mem_vec_2419 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_2420);
												mem_vec_2420 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_2421);
												mem_vec_2421 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_2422);
												mem_vec_2422 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_2423);
												mem_vec_2423 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_2424);
												mem_vec_2424 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_2425);
												mem_vec_2425 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_2426);
												mem_vec_2426 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_2427);
												mem_vec_2427 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_2428);
												mem_vec_2428 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_2429);
												mem_vec_2429 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_2430);
												mem_vec_2430 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_2431);
												mem_vec_2431 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);
												vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_2408);
												mem_vec_2408 = vec_68;

												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_2409);
												mem_vec_2409 = vec_71;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_2410);
												mem_vec_2410 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_2411);
												mem_vec_2411 = vec_75;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_2412);
												mem_vec_2412 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_2413);
												mem_vec_2413 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_2414);
												mem_vec_2414 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_2415);
												mem_vec_2415 = vec_81;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_2416);
												mem_vec_2416 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_2417);
												mem_vec_2417 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_2418);
												mem_vec_2418 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_2419);
												mem_vec_2419 = vec_86;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_2420);
												mem_vec_2420 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_2421);
												mem_vec_2421 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_2422);
												mem_vec_2422 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_2423);
												mem_vec_2423 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_2424);
												mem_vec_2424 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_2425);
												mem_vec_2425 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_2426);
												mem_vec_2426 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_2427);
												mem_vec_2427 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_2428);
												mem_vec_2428 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_2429);
												mem_vec_2429 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_2430);
												mem_vec_2430 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_2431);
												mem_vec_2431 = vec_101;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2408);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2409);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2410);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2411);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2412);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2413);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2414);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2415);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2416);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2417);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2418);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2419);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2420);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2421);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2422);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2423);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2424);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2425);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2426);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2427);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2428);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2429);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2430);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_2431);
								}
							}
						}
					}
				}
				for (y = y109 + 42, yp_0 = 0;
					y < y109 + 42 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
					// T (f, 1) (32 / 32)
					for (f = f206, fp_2 = f206_p_1, fp_1 = f206_p_0, fp_0 = 0;
						f < f206 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (c, 2) (64 / 32)
						for (c159 = c160, c159_p_0 = 0;
							c159 < c160 + 64;
							c159 += 32, c159_p_0 += 32){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h71, hp_0 = 0;
								h < h71 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x159, xp_1 = x159_p_0, xp_0 = 0;
									x < x159 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2432 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2433 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2434 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2435 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_2436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_2438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_2440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_2442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_2444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_2446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_2448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_2450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											mem_vec_2452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_2454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
											mem_vec_2456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_2458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
												c < c159 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2432);
												mem_vec_2432 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2433);
												mem_vec_2433 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2434);
												mem_vec_2434 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2435);
												mem_vec_2435 = vec_7;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2436);
												mem_vec_2436 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2437);
												mem_vec_2437 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2438);
												mem_vec_2438 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2439);
												mem_vec_2439 = vec_13;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2440);
												mem_vec_2440 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2441);
												mem_vec_2441 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2442);
												mem_vec_2442 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2443);
												mem_vec_2443 = vec_18;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2444);
												mem_vec_2444 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2445);
												mem_vec_2445 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2446);
												mem_vec_2446 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2447);
												mem_vec_2447 = vec_23;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2448);
												mem_vec_2448 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2449);
												mem_vec_2449 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2450);
												mem_vec_2450 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2451);
												mem_vec_2451 = vec_28;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2452);
												mem_vec_2452 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2453);
												mem_vec_2453 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_2454);
												mem_vec_2454 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_2455);
												mem_vec_2455 = vec_33;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_35 = _mm256_set1_ps(scal_6);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_2456);
												mem_vec_2456 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_2457);
												mem_vec_2457 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_2458);
												mem_vec_2458 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_2459);
												mem_vec_2459 = vec_38;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
												vec_40 = _mm256_set1_ps(scal_7);
												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_2432);
												mem_vec_2432 = vec_39;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_2433);
												mem_vec_2433 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_2434);
												mem_vec_2434 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_2435);
												mem_vec_2435 = vec_46;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_2436);
												mem_vec_2436 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_2437);
												mem_vec_2437 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_2438);
												mem_vec_2438 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_2439);
												mem_vec_2439 = vec_52;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_2440);
												mem_vec_2440 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_2441);
												mem_vec_2441 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_2442);
												mem_vec_2442 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_2443);
												mem_vec_2443 = vec_57;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_2444);
												mem_vec_2444 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_2445);
												mem_vec_2445 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_2446);
												mem_vec_2446 = vec_61;



												vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_2447);
												mem_vec_2447 = vec_62;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
												vec_64 = _mm256_set1_ps(scal_11);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_2448);
												mem_vec_2448 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_2449);
												mem_vec_2449 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_2450);
												mem_vec_2450 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_2451);
												mem_vec_2451 = vec_67;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
												vec_69 = _mm256_set1_ps(scal_12);


												vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_2452);
												mem_vec_2452 = vec_68;



												vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_2453);
												mem_vec_2453 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_2454);
												mem_vec_2454 = vec_71;



												vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_2455);
												mem_vec_2455 = vec_72;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
												vec_74 = _mm256_set1_ps(scal_13);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_2456);
												mem_vec_2456 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_2457);
												mem_vec_2457 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_2458);
												mem_vec_2458 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_2459);
												mem_vec_2459 = vec_77;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
												vec_79 = _mm256_set1_ps(scal_14);
												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_2432);
												mem_vec_2432 = vec_78;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_2433);
												mem_vec_2433 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_2434);
												mem_vec_2434 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_2435);
												mem_vec_2435 = vec_85;
												scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
												vec_88 = _mm256_set1_ps(scal_15);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_2436);
												mem_vec_2436 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_2437);
												mem_vec_2437 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_2438);
												mem_vec_2438 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_2439);
												mem_vec_2439 = vec_91;
												scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
												vec_93 = _mm256_set1_ps(scal_16);


												vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_2440);
												mem_vec_2440 = vec_92;



												vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_2441);
												mem_vec_2441 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_2442);
												mem_vec_2442 = vec_95;



												vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_2443);
												mem_vec_2443 = vec_96;
												scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
												vec_98 = _mm256_set1_ps(scal_17);


												vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_2444);
												mem_vec_2444 = vec_97;



												vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_2445);
												mem_vec_2445 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_2446);
												mem_vec_2446 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_2447);
												mem_vec_2447 = vec_101;
												scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
												vec_103 = _mm256_set1_ps(scal_18);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_2448);
												mem_vec_2448 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_2449);
												mem_vec_2449 = vec_104;



												vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_2450);
												mem_vec_2450 = vec_105;



												vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_2451);
												mem_vec_2451 = vec_106;
												scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
												vec_108 = _mm256_set1_ps(scal_19);


												vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_2452);
												mem_vec_2452 = vec_107;



												vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_2453);
												mem_vec_2453 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_2454);
												mem_vec_2454 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_2455);
												mem_vec_2455 = vec_111;
												scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
												vec_113 = _mm256_set1_ps(scal_20);


												vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_2456);
												mem_vec_2456 = vec_112;



												vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_2457);
												mem_vec_2457 = vec_114;



												vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_2458);
												mem_vec_2458 = vec_115;



												vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_2459);
												mem_vec_2459 = vec_116;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2432);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2433);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2434);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2435);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2436);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2437);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2438);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2439);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2440);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2441);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2442);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2443);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2444);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2445);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2446);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2447);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2448);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2449);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2450);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2451);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2452);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2453);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2454);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_2455);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2456);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2457);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2458);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_2459);
								}
							}
						}
					}
				}
		}
	}
}


}