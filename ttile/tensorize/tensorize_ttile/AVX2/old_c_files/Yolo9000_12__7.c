#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, f);
  T (1, c); T (16, f)]
*/
IND_TYPE c, cp_0, c472_p_0, c473_p_0, cp_1, c472_p_1, cp_2, c472, c473, f, fp_0, f382_p_0, fp_1, f382, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y272 = 0;
IND_TYPE x244 = 0;
IND_TYPE h = 0;
IND_TYPE w208 = 0;
IND_TYPE c474 = 0;
IND_TYPE f383 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,mem_vec_5366 ,mem_vec_5367 ,mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 16) (512 / 32)
for (f382 = f383, f382_p_0 = 0;
	f382 < f383 + 512;
	f382 += 32, f382_p_0 += 32){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 32
	// T (c, 1) (256 / 256)
	for (c473 = c474, c473_p_0 = 0;
		c473 < c474 + 256;
		c473 += 256, c473_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 32
		// T (f, 1) (32 / 32)
		for (f = f382, fp_1 = f382_p_0, fp_0 = 0;
			f < f382 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y272, yp_0 = 0;
					y < y272 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c472 = c473, c472_p_1 = c473_p_0, c472_p_0 = 0;
						c472 < c473 + 256;
						c472 += 32, c472_p_1 += 32, c472_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x244, xp_0 = 0;
							x < x244 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w208, wp_0 = 0;
								w < w208 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5332 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5333 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5334 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5335 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5348 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5349 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5350 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5351 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_5352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_5354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c472, cp_2 = c472_p_1, cp_1 = c472_p_0, cp_0 = 0;
											c < c472 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5332);
											mem_vec_5332 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5333);
											mem_vec_5333 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5334);
											mem_vec_5334 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5335);
											mem_vec_5335 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5336);
											mem_vec_5336 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5337);
											mem_vec_5337 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5338);
											mem_vec_5338 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5339);
											mem_vec_5339 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5340);
											mem_vec_5340 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5341);
											mem_vec_5341 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5342);
											mem_vec_5342 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5343);
											mem_vec_5343 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5344);
											mem_vec_5344 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5345);
											mem_vec_5345 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5346);
											mem_vec_5346 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5347);
											mem_vec_5347 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5348);
											mem_vec_5348 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5349);
											mem_vec_5349 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5350);
											mem_vec_5350 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5351);
											mem_vec_5351 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5352);
											mem_vec_5352 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5353);
											mem_vec_5353 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5354);
											mem_vec_5354 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5355);
											mem_vec_5355 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_5332);
											mem_vec_5332 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_5333);
											mem_vec_5333 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_5334);
											mem_vec_5334 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_5335);
											mem_vec_5335 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_5336);
											mem_vec_5336 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_5337);
											mem_vec_5337 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_5338);
											mem_vec_5338 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_5339);
											mem_vec_5339 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_5340);
											mem_vec_5340 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_5341);
											mem_vec_5341 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_5342);
											mem_vec_5342 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_5343);
											mem_vec_5343 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_5344);
											mem_vec_5344 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_5345);
											mem_vec_5345 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_5346);
											mem_vec_5346 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_5347);
											mem_vec_5347 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_5348);
											mem_vec_5348 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_5349);
											mem_vec_5349 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_5350);
											mem_vec_5350 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_5351);
											mem_vec_5351 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_5352);
											mem_vec_5352 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_5353);
											mem_vec_5353 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_5354);
											mem_vec_5354 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_5355);
											mem_vec_5355 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_5332);
											mem_vec_5332 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_5333);
											mem_vec_5333 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_5334);
											mem_vec_5334 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_5335);
											mem_vec_5335 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_5336);
											mem_vec_5336 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_5337);
											mem_vec_5337 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_5338);
											mem_vec_5338 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_5339);
											mem_vec_5339 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_5340);
											mem_vec_5340 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_5341);
											mem_vec_5341 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_5342);
											mem_vec_5342 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_5343);
											mem_vec_5343 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_5344);
											mem_vec_5344 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_5345);
											mem_vec_5345 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_5346);
											mem_vec_5346 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_5347);
											mem_vec_5347 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_5348);
											mem_vec_5348 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_5349);
											mem_vec_5349 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_5350);
											mem_vec_5350 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_5351);
											mem_vec_5351 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_5352);
											mem_vec_5352 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_5353);
											mem_vec_5353 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_5354);
											mem_vec_5354 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_5355);
											mem_vec_5355 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5332);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5333);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5334);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5335);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5336);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5337);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5338);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5339);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5340);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5341);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5342);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5343);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5344);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5345);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5346);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5347);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5348);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5349);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5350);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5351);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5352);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5353);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5354);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5355);
							}
						}
					}
				}
				for (y = y272 + 6, yp_0 = 0;
					y < y272 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c472 = c473, c472_p_1 = c473_p_0, c472_p_0 = 0;
						c472 < c473 + 256;
						c472 += 32, c472_p_1 += 32, c472_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x244, xp_0 = 0;
							x < x244 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w208, wp_0 = 0;
								w < w208 + 3;
								w += 1, wp_0 += 1){
										mem_vec_5356 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5357 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_5358 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5359 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_5360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_5362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_5364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_5366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_5368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_5370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_5372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_5374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_5376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_5378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_5380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_5382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c472, cp_2 = c472_p_1, cp_1 = c472_p_0, cp_0 = 0;
											c < c472 + 32;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5356);
											mem_vec_5356 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5357);
											mem_vec_5357 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5358);
											mem_vec_5358 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5359);
											mem_vec_5359 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5360);
											mem_vec_5360 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5361);
											mem_vec_5361 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5362);
											mem_vec_5362 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5363);
											mem_vec_5363 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5364);
											mem_vec_5364 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5365);
											mem_vec_5365 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5366);
											mem_vec_5366 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5367);
											mem_vec_5367 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5368);
											mem_vec_5368 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5369);
											mem_vec_5369 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5370);
											mem_vec_5370 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5371);
											mem_vec_5371 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5372);
											mem_vec_5372 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5373);
											mem_vec_5373 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5374);
											mem_vec_5374 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5375);
											mem_vec_5375 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_5376);
											mem_vec_5376 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_5377);
											mem_vec_5377 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_5378);
											mem_vec_5378 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_5379);
											mem_vec_5379 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_5380);
											mem_vec_5380 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_5381);
											mem_vec_5381 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_5382);
											mem_vec_5382 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_5383);
											mem_vec_5383 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_5356);
											mem_vec_5356 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_5357);
											mem_vec_5357 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_5358);
											mem_vec_5358 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_5359);
											mem_vec_5359 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_5360);
											mem_vec_5360 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_5361);
											mem_vec_5361 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_5362);
											mem_vec_5362 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_5363);
											mem_vec_5363 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_5364);
											mem_vec_5364 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_5365);
											mem_vec_5365 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_5366);
											mem_vec_5366 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_5367);
											mem_vec_5367 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_5368);
											mem_vec_5368 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_5369);
											mem_vec_5369 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_5370);
											mem_vec_5370 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_5371);
											mem_vec_5371 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_5372);
											mem_vec_5372 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_5373);
											mem_vec_5373 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_5374);
											mem_vec_5374 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_5375);
											mem_vec_5375 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_5376);
											mem_vec_5376 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_5377);
											mem_vec_5377 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_5378);
											mem_vec_5378 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_5379);
											mem_vec_5379 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_5380);
											mem_vec_5380 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_5381);
											mem_vec_5381 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_5382);
											mem_vec_5382 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_5383);
											mem_vec_5383 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_5356);
											mem_vec_5356 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_5357);
											mem_vec_5357 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_5358);
											mem_vec_5358 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_5359);
											mem_vec_5359 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_5360);
											mem_vec_5360 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_5361);
											mem_vec_5361 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_5362);
											mem_vec_5362 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_5363);
											mem_vec_5363 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_5364);
											mem_vec_5364 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_5365);
											mem_vec_5365 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_5366);
											mem_vec_5366 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_5367);
											mem_vec_5367 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_5368);
											mem_vec_5368 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_5369);
											mem_vec_5369 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_5370);
											mem_vec_5370 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_5371);
											mem_vec_5371 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_5372);
											mem_vec_5372 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_5373);
											mem_vec_5373 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_5374);
											mem_vec_5374 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_5375);
											mem_vec_5375 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_5376);
											mem_vec_5376 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_5377);
											mem_vec_5377 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_5378);
											mem_vec_5378 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_5379);
											mem_vec_5379 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_5380);
											mem_vec_5380 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_5381);
											mem_vec_5381 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_5382);
											mem_vec_5382 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_5383);
											mem_vec_5383 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5356);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5357);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5358);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5359);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5360);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5361);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5362);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5363);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5364);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5365);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5366);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5367);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5368);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5369);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5370);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5371);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5372);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5373);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5374);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5375);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5376);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_5377);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5378);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_5379);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5380);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_5381);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5382);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_5383);
							}
						}
					}
				}
		}
	}
}


}