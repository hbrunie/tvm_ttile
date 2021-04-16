#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (16, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c30_p_0, c31_p_0, cp_1, c30_p_1, cp_2, c30, c31, f, fp_0, f33_p_0, fp_1, f33, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y24 = 0;
IND_TYPE x18 = 0;
IND_TYPE h16 = 0;
IND_TYPE w = 0;
IND_TYPE c32 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,mem_vec_400 ,mem_vec_401 ,mem_vec_402 ,mem_vec_403 ,mem_vec_404 ,mem_vec_405 ,mem_vec_406 ,mem_vec_407 ,mem_vec_408 ,mem_vec_409 ,mem_vec_410 ,mem_vec_411 ,mem_vec_412 ,mem_vec_413 ,mem_vec_414 ,mem_vec_415 ,mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f33 = f34, f33_p_0 = 0;
	f33 < f34 + 512;
	f33 += 512, f33_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 2) (256 / 128)
	for (c31 = c32, c31_p_0 = 0;
		c31 < c32 + 256;
		c31 += 128, c31_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
		// T (f, 16) (512 / 32)
		for (f = f33, fp_1 = f33_p_0, fp_0 = 0;
			f < f33 + 512;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y24, yp_0 = 0;
					y < y24 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c30 = c31, c30_p_1 = c31_p_0, c30_p_0 = 0;
						c30 < c31 + 128;
						c30 += 16, c30_p_1 += 16, c30_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x18, xp_0 = 0;
							x < x18 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
										mem_vec_372 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_373 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_374 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_375 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c30, cp_2 = c30_p_1, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_372);
											mem_vec_372 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_373);
											mem_vec_373 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_374);
											mem_vec_374 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_375);
											mem_vec_375 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_376);
											mem_vec_376 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_377);
											mem_vec_377 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_378);
											mem_vec_378 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_379);
											mem_vec_379 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_380);
											mem_vec_380 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_381);
											mem_vec_381 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_382);
											mem_vec_382 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_383);
											mem_vec_383 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_384);
											mem_vec_384 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_385);
											mem_vec_385 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_386);
											mem_vec_386 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_387);
											mem_vec_387 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_388);
											mem_vec_388 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_389);
											mem_vec_389 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_390);
											mem_vec_390 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_391);
											mem_vec_391 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_392);
											mem_vec_392 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_393);
											mem_vec_393 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_394);
											mem_vec_394 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_395);
											mem_vec_395 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_372);
											mem_vec_372 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_373);
											mem_vec_373 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_374);
											mem_vec_374 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_375);
											mem_vec_375 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_376);
											mem_vec_376 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_377);
											mem_vec_377 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_378);
											mem_vec_378 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_379);
											mem_vec_379 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_380);
											mem_vec_380 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_381);
											mem_vec_381 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_382);
											mem_vec_382 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_383);
											mem_vec_383 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_384);
											mem_vec_384 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_385);
											mem_vec_385 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_386);
											mem_vec_386 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_387);
											mem_vec_387 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_388);
											mem_vec_388 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_389);
											mem_vec_389 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_390);
											mem_vec_390 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_391);
											mem_vec_391 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_392);
											mem_vec_392 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_393);
											mem_vec_393 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_394);
											mem_vec_394 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_395);
											mem_vec_395 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_372);
											mem_vec_372 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_373);
											mem_vec_373 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_374);
											mem_vec_374 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_375);
											mem_vec_375 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_376);
											mem_vec_376 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_377);
											mem_vec_377 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_378);
											mem_vec_378 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_379);
											mem_vec_379 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_380);
											mem_vec_380 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_381);
											mem_vec_381 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_382);
											mem_vec_382 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_383);
											mem_vec_383 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_384);
											mem_vec_384 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_385);
											mem_vec_385 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_386);
											mem_vec_386 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_387);
											mem_vec_387 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_388);
											mem_vec_388 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_389);
											mem_vec_389 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_390);
											mem_vec_390 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_391);
											mem_vec_391 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_392);
											mem_vec_392 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_393);
											mem_vec_393 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_394);
											mem_vec_394 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_395);
											mem_vec_395 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_372);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_373);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_374);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_375);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_376);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_377);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_378);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_379);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_380);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_381);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_382);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_383);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_384);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_385);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_386);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_387);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_388);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_389);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_390);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_391);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_392);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_393);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_394);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_395);
							}
						}
					}
				}
				for (y = y24 + 6, yp_0 = 0;
					y < y24 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 8) (128 / 16)
					for (c30 = c31, c30_p_1 = c31_p_0, c30_p_0 = 0;
						c30 < c31 + 128;
						c30 += 16, c30_p_1 += 16, c30_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (x, 34) (34 / 1)
						for (x = x18, xp_0 = 0;
							x < x18 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h16, hp_0 = 0;
								h < h16 + 3;
								h += 1, hp_0 += 1){
										mem_vec_396 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_397 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_398 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_399 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c30, cp_2 = c30_p_1, cp_1 = c30_p_0, cp_0 = 0;
											c < c30 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_396);
											mem_vec_396 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_397);
											mem_vec_397 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_398);
											mem_vec_398 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_399);
											mem_vec_399 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_400);
											mem_vec_400 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_401);
											mem_vec_401 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_402);
											mem_vec_402 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_403);
											mem_vec_403 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_404);
											mem_vec_404 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_405);
											mem_vec_405 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_406);
											mem_vec_406 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_407);
											mem_vec_407 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_408);
											mem_vec_408 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_409);
											mem_vec_409 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_410);
											mem_vec_410 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_411);
											mem_vec_411 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_412);
											mem_vec_412 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_413);
											mem_vec_413 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_414);
											mem_vec_414 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_415);
											mem_vec_415 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_416);
											mem_vec_416 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_417);
											mem_vec_417 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_418);
											mem_vec_418 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_419);
											mem_vec_419 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_420);
											mem_vec_420 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_421);
											mem_vec_421 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_422);
											mem_vec_422 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_423);
											mem_vec_423 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_396);
											mem_vec_396 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_397);
											mem_vec_397 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_398);
											mem_vec_398 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_399);
											mem_vec_399 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_400);
											mem_vec_400 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_401);
											mem_vec_401 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_402);
											mem_vec_402 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_403);
											mem_vec_403 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_404);
											mem_vec_404 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_405);
											mem_vec_405 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_406);
											mem_vec_406 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_407);
											mem_vec_407 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_408);
											mem_vec_408 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_409);
											mem_vec_409 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_410);
											mem_vec_410 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_411);
											mem_vec_411 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_412);
											mem_vec_412 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_413);
											mem_vec_413 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_414);
											mem_vec_414 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_415);
											mem_vec_415 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_416);
											mem_vec_416 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_417);
											mem_vec_417 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_418);
											mem_vec_418 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_419);
											mem_vec_419 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_420);
											mem_vec_420 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_421);
											mem_vec_421 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_422);
											mem_vec_422 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_423);
											mem_vec_423 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_396);
											mem_vec_396 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_397);
											mem_vec_397 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_398);
											mem_vec_398 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_399);
											mem_vec_399 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_400);
											mem_vec_400 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_401);
											mem_vec_401 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_402);
											mem_vec_402 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_403);
											mem_vec_403 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_404);
											mem_vec_404 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_405);
											mem_vec_405 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_406);
											mem_vec_406 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_407);
											mem_vec_407 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_408);
											mem_vec_408 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_409);
											mem_vec_409 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_410);
											mem_vec_410 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_411);
											mem_vec_411 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_412);
											mem_vec_412 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_413);
											mem_vec_413 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_414);
											mem_vec_414 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_415);
											mem_vec_415 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_416);
											mem_vec_416 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_417);
											mem_vec_417 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_418);
											mem_vec_418 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_419);
											mem_vec_419 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_420);
											mem_vec_420 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_421);
											mem_vec_421 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_422);
											mem_vec_422 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_423);
											mem_vec_423 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_396);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_397);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_398);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_399);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_400);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_401);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_402);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_403);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_404);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_405);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_406);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_407);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_408);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_409);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_410);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_411);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_412);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_413);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_414);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_415);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_416);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_417);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_418);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_419);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_420);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_421);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_422);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_423);
							}
						}
					}
				}
		}
	}
}


}