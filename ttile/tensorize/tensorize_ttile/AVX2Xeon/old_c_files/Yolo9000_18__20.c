#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (16, f); T (16, c); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, f36_p_0, f37_p_0, fp_1, f36_p_1, fp_2, f36, f37, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y18 = 0;
IND_TYPE x18 = 0;
IND_TYPE h12 = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f37 = f38, f37_p_0 = 0;
	f37 < f38 + 1024;
	f37 += 512, f37_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (f, 1) (512 / 512)
	for (f36 = f37, f36_p_1 = f37_p_0, f36_p_0 = 0;
		f36 < f37 + 512;
		f36 += 512, f36_p_1 += 512, f36_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
		// T (c, 16) (512 / 32)
		for (c27 = c28, c27_p_0 = 0;
			c27 < c28 + 512;
			c27 += 32, c27_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 512
			// T (f, 16) (512 / 32)
			for (f = f36, fp_2 = f36_p_1, fp_1 = f36_p_0, fp_0 = 0;
				f < f36 + 512;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y18, yp_0 = 0;
						y < y18 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x18, xp_0 = 0;
							x < x18 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h12, hp_0 = 0;
								h < h12 + 3;
								h += 1, hp_0 += 1){
										mem_vec_364 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_365 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_366 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_367 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
											c < c27 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_364);
											mem_vec_364 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_365);
											mem_vec_365 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_366);
											mem_vec_366 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_367);
											mem_vec_367 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_368);
											mem_vec_368 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_369);
											mem_vec_369 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_370);
											mem_vec_370 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_371);
											mem_vec_371 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_372);
											mem_vec_372 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_373);
											mem_vec_373 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_374);
											mem_vec_374 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_375);
											mem_vec_375 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_376);
											mem_vec_376 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_377);
											mem_vec_377 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_378);
											mem_vec_378 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_379);
											mem_vec_379 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_364);
											mem_vec_364 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_365);
											mem_vec_365 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_366);
											mem_vec_366 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_367);
											mem_vec_367 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_368);
											mem_vec_368 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_369);
											mem_vec_369 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_370);
											mem_vec_370 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_371);
											mem_vec_371 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_372);
											mem_vec_372 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_373);
											mem_vec_373 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_374);
											mem_vec_374 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_375);
											mem_vec_375 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_376);
											mem_vec_376 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_377);
											mem_vec_377 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_378);
											mem_vec_378 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_379);
											mem_vec_379 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_364);
											mem_vec_364 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_365);
											mem_vec_365 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_366);
											mem_vec_366 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_367);
											mem_vec_367 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_368);
											mem_vec_368 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_369);
											mem_vec_369 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_370);
											mem_vec_370 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_371);
											mem_vec_371 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_372);
											mem_vec_372 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_373);
											mem_vec_373 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_374);
											mem_vec_374 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_375);
											mem_vec_375 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_376);
											mem_vec_376 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_377);
											mem_vec_377 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_378);
											mem_vec_378 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_379);
											mem_vec_379 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_364);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_365);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_366);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_367);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_368);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_369);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_370);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_371);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_372);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_373);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_374);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_375);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_376);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_377);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_378);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_379);
							}
						}
					}
					for (y = y18 + 12, yp_0 = 0;
						y < y18 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x18, xp_0 = 0;
							x < x18 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h12, hp_0 = 0;
								h < h12 + 3;
								h += 1, hp_0 += 1){
										mem_vec_380 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_381 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_382 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_383 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
											c < c27 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_380);
											mem_vec_380 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_381);
											mem_vec_381 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_382);
											mem_vec_382 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_383);
											mem_vec_383 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_384);
											mem_vec_384 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_385);
											mem_vec_385 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_386);
											mem_vec_386 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_387);
											mem_vec_387 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_388);
											mem_vec_388 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_389);
											mem_vec_389 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_390);
											mem_vec_390 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_391);
											mem_vec_391 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_392);
											mem_vec_392 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_393);
											mem_vec_393 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_394);
											mem_vec_394 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_395);
											mem_vec_395 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_396);
											mem_vec_396 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_397);
											mem_vec_397 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_398);
											mem_vec_398 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_399);
											mem_vec_399 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_380);
											mem_vec_380 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_381);
											mem_vec_381 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_382);
											mem_vec_382 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_383);
											mem_vec_383 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_384);
											mem_vec_384 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_385);
											mem_vec_385 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_386);
											mem_vec_386 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_387);
											mem_vec_387 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_388);
											mem_vec_388 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_389);
											mem_vec_389 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_390);
											mem_vec_390 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_391);
											mem_vec_391 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_392);
											mem_vec_392 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_393);
											mem_vec_393 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_394);
											mem_vec_394 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_395);
											mem_vec_395 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_396);
											mem_vec_396 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_397);
											mem_vec_397 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_398);
											mem_vec_398 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_399);
											mem_vec_399 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_380);
											mem_vec_380 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_381);
											mem_vec_381 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_382);
											mem_vec_382 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_383);
											mem_vec_383 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_384);
											mem_vec_384 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_385);
											mem_vec_385 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_386);
											mem_vec_386 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_387);
											mem_vec_387 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_388);
											mem_vec_388 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_389);
											mem_vec_389 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_390);
											mem_vec_390 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_391);
											mem_vec_391 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_392);
											mem_vec_392 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_393);
											mem_vec_393 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_394);
											mem_vec_394 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_395);
											mem_vec_395 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_396);
											mem_vec_396 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_397);
											mem_vec_397 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_398);
											mem_vec_398 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_399);
											mem_vec_399 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_380);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_381);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_382);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_383);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_384);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_385);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_386);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_387);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_388);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_389);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_390);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_391);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_392);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_393);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_394);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_395);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_396);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_397);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_398);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_399);
							}
						}
					}
			}
		}
	}
}


}