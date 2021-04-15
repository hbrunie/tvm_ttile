#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (2, f);
  T (32, c); T (2, f)]
*/
IND_TYPE c, cp_0, c1056_p_0, cp_1, c1056, f, fp_0, f1408_p_0, f1409_p_0, fp_1, f1408_p_1, fp_2, f1408, f1409, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y704 = 0;
IND_TYPE x704 = 0;
IND_TYPE h556 = 0;
IND_TYPE w = 0;
IND_TYPE c1057 = 0;
IND_TYPE f1410 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11368 ,mem_vec_11369 ,mem_vec_11370 ,mem_vec_11371 ,mem_vec_11372 ,mem_vec_11373 ,mem_vec_11374 ,mem_vec_11375 ,mem_vec_11376 ,mem_vec_11377 ,mem_vec_11378 ,mem_vec_11379 ,mem_vec_11380 ,mem_vec_11381 ,mem_vec_11382 ,mem_vec_11383 ,mem_vec_11384 ,mem_vec_11385 ,mem_vec_11386 ,mem_vec_11387 ,mem_vec_11388 ,mem_vec_11389 ,mem_vec_11390 ,mem_vec_11391 ,mem_vec_11392 ,mem_vec_11393 ,mem_vec_11394 ,mem_vec_11395 ,mem_vec_11396 ,mem_vec_11397 ,mem_vec_11398 ,mem_vec_11399 ,mem_vec_11400 ,mem_vec_11401 ,mem_vec_11402 ,mem_vec_11403 ,mem_vec_11404 ,mem_vec_11405 ,mem_vec_11406 ,mem_vec_11407 ,mem_vec_11408 ,mem_vec_11409 ,mem_vec_11410 ,mem_vec_11411 ,mem_vec_11412 ,mem_vec_11413 ,mem_vec_11414 ,mem_vec_11415 ,mem_vec_11416 ,mem_vec_11417 ,mem_vec_11418 ,mem_vec_11419 ,mem_vec_11420 ,mem_vec_11421 ,mem_vec_11422 ,mem_vec_11423 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 2) (512 / 256)
for (f1409 = f1410, f1409_p_0 = 0;
	f1409 < f1410 + 512;
	f1409 += 256, f1409_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 256
	// T (c, 32) (512 / 16)
	for (c1056 = c1057, c1056_p_0 = 0;
		c1056 < c1057 + 512;
		c1056 += 16, c1056_p_0 += 16){
		// y = 7, x = 7, h = 3, w = 3, c = 16, f = 256
		// T (f, 2) (256 / 128)
		for (f1408 = f1409, f1408_p_1 = f1409_p_0, f1408_p_0 = 0;
			f1408 < f1409 + 256;
			f1408 += 128, f1408_p_1 += 128, f1408_p_0 += 128){
				for (y = y704, yp_0 = 0;
					y < y704 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1408, fp_2 = f1408_p_1, fp_1 = f1408_p_0, fp_0 = 0;
						f < f1408 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h556, hp_0 = 0;
							h < h556 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
							// T (x, 7) (7 / 1)
							for (x = x704, xp_0 = 0;
								x < x704 + 7;
								x += 1, xp_0 += 1){
										mem_vec_11368 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11369 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11370 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11371 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11372 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_11373 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_11374 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_11375 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_11376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_11381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_11382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_11383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_11384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_11389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_11390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_11391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c1056, cp_1 = c1056_p_0, cp_0 = 0;
											c < c1056 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11368);
											mem_vec_11368 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11369);
											mem_vec_11369 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11370);
											mem_vec_11370 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11371);
											mem_vec_11371 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_11372);
											mem_vec_11372 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_11373);
											mem_vec_11373 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_11374);
											mem_vec_11374 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_11375);
											mem_vec_11375 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_11376);
											mem_vec_11376 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_11377);
											mem_vec_11377 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_11378);
											mem_vec_11378 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_11379);
											mem_vec_11379 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_11380);
											mem_vec_11380 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_11381);
											mem_vec_11381 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_11382);
											mem_vec_11382 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_11383);
											mem_vec_11383 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_11384);
											mem_vec_11384 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_11385);
											mem_vec_11385 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_11386);
											mem_vec_11386 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_11387);
											mem_vec_11387 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_11388);
											mem_vec_11388 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_11389);
											mem_vec_11389 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_11390);
											mem_vec_11390 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_11391);
											mem_vec_11391 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);
											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_11368);
											mem_vec_11368 = vec_35;

											vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_11369);
											mem_vec_11369 = vec_38;

											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_11370);
											mem_vec_11370 = vec_40;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_11371);
											mem_vec_11371 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_11372);
											mem_vec_11372 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_11373);
											mem_vec_11373 = vec_46;

											vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_11374);
											mem_vec_11374 = vec_48;

											vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_11375);
											mem_vec_11375 = vec_50;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_53 = _mm256_set1_ps(scal_4);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_11376);
											mem_vec_11376 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_11377);
											mem_vec_11377 = vec_54;



											vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_11378);
											mem_vec_11378 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_11379);
											mem_vec_11379 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_11380);
											mem_vec_11380 = vec_57;



											vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_11381);
											mem_vec_11381 = vec_58;



											vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_11382);
											mem_vec_11382 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_11383);
											mem_vec_11383 = vec_60;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_11384);
											mem_vec_11384 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_11385);
											mem_vec_11385 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_11386);
											mem_vec_11386 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_11387);
											mem_vec_11387 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_11388);
											mem_vec_11388 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_11389);
											mem_vec_11389 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_11390);
											mem_vec_11390 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_11391);
											mem_vec_11391 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);
											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_11368);
											mem_vec_11368 = vec_70;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_11369);
											mem_vec_11369 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_11370);
											mem_vec_11370 = vec_75;

											vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_11371);
											mem_vec_11371 = vec_77;

											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_11372);
											mem_vec_11372 = vec_79;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_11373);
											mem_vec_11373 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_11374);
											mem_vec_11374 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_11375);
											mem_vec_11375 = vec_85;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm256_set1_ps(scal_7);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11376);
											mem_vec_11376 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11377);
											mem_vec_11377 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11378);
											mem_vec_11378 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_11379);
											mem_vec_11379 = vec_91;



											vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_11380);
											mem_vec_11380 = vec_92;



											vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_11381);
											mem_vec_11381 = vec_93;



											vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_11382);
											mem_vec_11382 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_11383);
											mem_vec_11383 = vec_95;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_97 = _mm256_set1_ps(scal_8);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_11384);
											mem_vec_11384 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_11385);
											mem_vec_11385 = vec_98;



											vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_11386);
											mem_vec_11386 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_11387);
											mem_vec_11387 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_11388);
											mem_vec_11388 = vec_101;



											vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_11389);
											mem_vec_11389 = vec_102;



											vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_11390);
											mem_vec_11390 = vec_103;



											vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_11391);
											mem_vec_11391 = vec_104;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11368);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11369);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11370);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11371);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11372);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_11373);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11374);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_11375);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11376);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11377);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11378);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11379);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11380);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_11381);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11382);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_11383);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11384);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11385);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11386);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11387);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11388);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_11389);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11390);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_11391);
							}
						}
					}
				}
				for (y = y704 + 3, yp_0 = 0;
					y < y704 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1408, fp_2 = f1408_p_1, fp_1 = f1408_p_0, fp_0 = 0;
						f < f1408 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h556, hp_0 = 0;
							h < h556 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
							// T (x, 7) (7 / 1)
							for (x = x704, xp_0 = 0;
								x < x704 + 7;
								x += 1, xp_0 += 1){
										mem_vec_11392 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11393 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11394 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11395 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11396 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_11397 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
										mem_vec_11398 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_11399 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
										mem_vec_11400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_11405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
										mem_vec_11406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_11407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
										mem_vec_11408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_11413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
										mem_vec_11414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_11415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
										mem_vec_11416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_11418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_11420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_11421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
										mem_vec_11422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_11423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c1056, cp_1 = c1056_p_0, cp_0 = 0;
											c < c1056 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11392);
											mem_vec_11392 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11393);
											mem_vec_11393 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11394);
											mem_vec_11394 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11395);
											mem_vec_11395 = vec_7;

											vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_11396);
											mem_vec_11396 = vec_9;

											vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

											vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_11397);
											mem_vec_11397 = vec_11;

											vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_11398);
											mem_vec_11398 = vec_13;

											vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

											vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_11399);
											mem_vec_11399 = vec_15;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_18 = _mm256_set1_ps(scal_1);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_11400);
											mem_vec_11400 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_11401);
											mem_vec_11401 = vec_19;



											vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_11402);
											mem_vec_11402 = vec_20;



											vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_11403);
											mem_vec_11403 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_11404);
											mem_vec_11404 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_11405);
											mem_vec_11405 = vec_23;



											vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_11406);
											mem_vec_11406 = vec_24;



											vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_11407);
											mem_vec_11407 = vec_25;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_27 = _mm256_set1_ps(scal_2);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_11408);
											mem_vec_11408 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_11409);
											mem_vec_11409 = vec_28;



											vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_11410);
											mem_vec_11410 = vec_29;



											vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_11411);
											mem_vec_11411 = vec_30;



											vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_11412);
											mem_vec_11412 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_11413);
											mem_vec_11413 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_11414);
											mem_vec_11414 = vec_33;



											vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_11415);
											mem_vec_11415 = vec_34;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_36 = _mm256_set1_ps(scal_3);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_11416);
											mem_vec_11416 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_11417);
											mem_vec_11417 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_11418);
											mem_vec_11418 = vec_38;



											vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_11419);
											mem_vec_11419 = vec_39;



											vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_11420);
											mem_vec_11420 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_11421);
											mem_vec_11421 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_11422);
											mem_vec_11422 = vec_42;



											vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_11423);
											mem_vec_11423 = vec_43;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_45 = _mm256_set1_ps(scal_4);
											vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_11392);
											mem_vec_11392 = vec_44;

											vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_11393);
											mem_vec_11393 = vec_47;

											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_11394);
											mem_vec_11394 = vec_49;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_11395);
											mem_vec_11395 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_11396);
											mem_vec_11396 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

											vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_11397);
											mem_vec_11397 = vec_55;

											vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_11398);
											mem_vec_11398 = vec_57;

											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

											vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_11399);
											mem_vec_11399 = vec_59;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_62 = _mm256_set1_ps(scal_5);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_11400);
											mem_vec_11400 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_11401);
											mem_vec_11401 = vec_63;



											vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_11402);
											mem_vec_11402 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_11403);
											mem_vec_11403 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_11404);
											mem_vec_11404 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_11405);
											mem_vec_11405 = vec_67;



											vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_11406);
											mem_vec_11406 = vec_68;



											vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_11407);
											mem_vec_11407 = vec_69;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_71 = _mm256_set1_ps(scal_6);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_11408);
											mem_vec_11408 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_11409);
											mem_vec_11409 = vec_72;



											vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_11410);
											mem_vec_11410 = vec_73;



											vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_11411);
											mem_vec_11411 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_11412);
											mem_vec_11412 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_11413);
											mem_vec_11413 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_11414);
											mem_vec_11414 = vec_77;



											vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_11415);
											mem_vec_11415 = vec_78;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_80 = _mm256_set1_ps(scal_7);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_11416);
											mem_vec_11416 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_11417);
											mem_vec_11417 = vec_81;



											vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_11418);
											mem_vec_11418 = vec_82;



											vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_11419);
											mem_vec_11419 = vec_83;



											vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_11420);
											mem_vec_11420 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_11421);
											mem_vec_11421 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_11422);
											mem_vec_11422 = vec_86;



											vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_11423);
											mem_vec_11423 = vec_87;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_89 = _mm256_set1_ps(scal_8);
											vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_11392);
											mem_vec_11392 = vec_88;

											vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_11393);
											mem_vec_11393 = vec_91;

											vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_11394);
											mem_vec_11394 = vec_93;

											vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_11395);
											mem_vec_11395 = vec_95;

											vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_11396);
											mem_vec_11396 = vec_97;

											vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

											vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_11397);
											mem_vec_11397 = vec_99;

											vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_11398);
											mem_vec_11398 = vec_101;

											vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

											vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_11399);
											mem_vec_11399 = vec_103;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_106 = _mm256_set1_ps(scal_9);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_11400);
											mem_vec_11400 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_11401);
											mem_vec_11401 = vec_107;



											vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_11402);
											mem_vec_11402 = vec_108;



											vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_11403);
											mem_vec_11403 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_11404);
											mem_vec_11404 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_11405);
											mem_vec_11405 = vec_111;



											vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_11406);
											mem_vec_11406 = vec_112;



											vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_11407);
											mem_vec_11407 = vec_113;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_115 = _mm256_set1_ps(scal_10);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_11408);
											mem_vec_11408 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_11409);
											mem_vec_11409 = vec_116;



											vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_11410);
											mem_vec_11410 = vec_117;



											vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_11411);
											mem_vec_11411 = vec_118;



											vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_11412);
											mem_vec_11412 = vec_119;



											vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_11413);
											mem_vec_11413 = vec_120;



											vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_11414);
											mem_vec_11414 = vec_121;



											vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_11415);
											mem_vec_11415 = vec_122;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_124 = _mm256_set1_ps(scal_11);


											vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_11416);
											mem_vec_11416 = vec_123;



											vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_11417);
											mem_vec_11417 = vec_125;



											vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_11418);
											mem_vec_11418 = vec_126;



											vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_11419);
											mem_vec_11419 = vec_127;



											vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_11420);
											mem_vec_11420 = vec_128;



											vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_11421);
											mem_vec_11421 = vec_129;



											vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_11422);
											mem_vec_11422 = vec_130;



											vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_11423);
											mem_vec_11423 = vec_131;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11392);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11393);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11394);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11395);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11396);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_11397);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11398);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_11399);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11400);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11401);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11402);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11403);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11404);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_11405);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11406);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_11407);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11408);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11409);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11410);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11411);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11412);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_11413);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11414);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_11415);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11416);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11417);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11418);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11419);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11420);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_11421);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11422);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_11423);
							}
						}
					}
				}
		}
	}
}


}