#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (4, c); T (1, f); T (7, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, f, fp_0, f212_p_0, f213_p_0, fp_1, f212_p_1, fp_2, f212, f213, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y119 = 0;
IND_TYPE x106 = 0;
IND_TYPE h88 = 0;
IND_TYPE w = 0;
IND_TYPE c160 = 0;
IND_TYPE f214 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1344 ,mem_vec_1345 ,mem_vec_1346 ,mem_vec_1347 ,mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,mem_vec_1372 ,mem_vec_1373 ,mem_vec_1374 ,mem_vec_1375 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f213 = f214, f213_p_0 = 0;
	f213 < f214 + 128;
	f213 += 128, f213_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
	// T (f, 2) (128 / 64)
	for (f212 = f213, f212_p_1 = f213_p_0, f212_p_0 = 0;
		f212 < f213 + 128;
		f212 += 64, f212_p_1 += 64, f212_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 64, f = 64
		// T (y, 7) (28 / 4)
		for (y = y119, yp_0 = 0;
			y < y119 + 28;
			y += 4, yp_0 += 4){
			// y = 4, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (f, 1) (64 / 64)
			for (f = f212, fp_2 = f212_p_1, fp_1 = f212_p_0, fp_0 = 0;
				f < f212 + 64;
				f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
				// y = 4, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c159 = c160, c159_p_0 = 0;
					c159 < c160 + 64;
					c159 += 16, c159_p_0 += 16){
					// y = 4, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (x, 28) (28 / 1)
					for (x = x106, xp_0 = 0;
						x < x106 + 28;
						x += 1, xp_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h88, hp_0 = 0;
							h < h88 + 3;
							h += 1, hp_0 += 1){
									mem_vec_1344 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1345 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1346 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1347 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1348 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1349 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
									mem_vec_1350 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1351 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
									mem_vec_1352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
									mem_vec_1358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
									mem_vec_1360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_1365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
									mem_vec_1366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_1367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
									mem_vec_1368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_1373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
									mem_vec_1374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_1375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
									// y = 4, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
										c < c159 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1344);
										mem_vec_1344 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1345);
										mem_vec_1345 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1346);
										mem_vec_1346 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1347);
										mem_vec_1347 = vec_7;

										vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_1348);
										mem_vec_1348 = vec_9;

										vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

										vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_1349);
										mem_vec_1349 = vec_11;

										vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_1350);
										mem_vec_1350 = vec_13;

										vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

										vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_1351);
										mem_vec_1351 = vec_15;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_18 = _mm256_set1_ps(scal_1);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1352);
										mem_vec_1352 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1353);
										mem_vec_1353 = vec_19;



										vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_1354);
										mem_vec_1354 = vec_20;



										vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_1355);
										mem_vec_1355 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_1356);
										mem_vec_1356 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_1357);
										mem_vec_1357 = vec_23;



										vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_1358);
										mem_vec_1358 = vec_24;



										vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_1359);
										mem_vec_1359 = vec_25;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_27 = _mm256_set1_ps(scal_2);


										vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1360);
										mem_vec_1360 = vec_26;



										vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1361);
										mem_vec_1361 = vec_28;



										vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_1362);
										mem_vec_1362 = vec_29;



										vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_1363);
										mem_vec_1363 = vec_30;



										vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_1364);
										mem_vec_1364 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_1365);
										mem_vec_1365 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_1366);
										mem_vec_1366 = vec_33;



										vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_1367);
										mem_vec_1367 = vec_34;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_36 = _mm256_set1_ps(scal_3);


										vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_1368);
										mem_vec_1368 = vec_35;



										vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_1369);
										mem_vec_1369 = vec_37;



										vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_1370);
										mem_vec_1370 = vec_38;



										vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_1371);
										mem_vec_1371 = vec_39;



										vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_1372);
										mem_vec_1372 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_1373);
										mem_vec_1373 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_1374);
										mem_vec_1374 = vec_42;



										vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_1375);
										mem_vec_1375 = vec_43;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_45 = _mm256_set1_ps(scal_4);
										vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_1344);
										mem_vec_1344 = vec_44;

										vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_1345);
										mem_vec_1345 = vec_47;

										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_1346);
										mem_vec_1346 = vec_49;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_1347);
										mem_vec_1347 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_1348);
										mem_vec_1348 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

										vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_1349);
										mem_vec_1349 = vec_55;

										vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_1350);
										mem_vec_1350 = vec_57;

										vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

										vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_1351);
										mem_vec_1351 = vec_59;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_62 = _mm256_set1_ps(scal_5);


										vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_1352);
										mem_vec_1352 = vec_61;



										vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_1353);
										mem_vec_1353 = vec_63;



										vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_1354);
										mem_vec_1354 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_1355);
										mem_vec_1355 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_1356);
										mem_vec_1356 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_1357);
										mem_vec_1357 = vec_67;



										vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_1358);
										mem_vec_1358 = vec_68;



										vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_1359);
										mem_vec_1359 = vec_69;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_71 = _mm256_set1_ps(scal_6);


										vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_1360);
										mem_vec_1360 = vec_70;



										vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_1361);
										mem_vec_1361 = vec_72;



										vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_1362);
										mem_vec_1362 = vec_73;



										vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_1363);
										mem_vec_1363 = vec_74;



										vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_1364);
										mem_vec_1364 = vec_75;



										vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_1365);
										mem_vec_1365 = vec_76;



										vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_1366);
										mem_vec_1366 = vec_77;



										vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_1367);
										mem_vec_1367 = vec_78;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_80 = _mm256_set1_ps(scal_7);


										vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_1368);
										mem_vec_1368 = vec_79;



										vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_1369);
										mem_vec_1369 = vec_81;



										vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_1370);
										mem_vec_1370 = vec_82;



										vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_1371);
										mem_vec_1371 = vec_83;



										vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_1372);
										mem_vec_1372 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_1373);
										mem_vec_1373 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_1374);
										mem_vec_1374 = vec_86;



										vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_1375);
										mem_vec_1375 = vec_87;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_89 = _mm256_set1_ps(scal_8);
										vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_1344);
										mem_vec_1344 = vec_88;

										vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_1345);
										mem_vec_1345 = vec_91;

										vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_1346);
										mem_vec_1346 = vec_93;

										vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_1347);
										mem_vec_1347 = vec_95;

										vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_1348);
										mem_vec_1348 = vec_97;

										vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

										vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_1349);
										mem_vec_1349 = vec_99;

										vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_1350);
										mem_vec_1350 = vec_101;

										vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

										vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_1351);
										mem_vec_1351 = vec_103;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_106 = _mm256_set1_ps(scal_9);


										vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_1352);
										mem_vec_1352 = vec_105;



										vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_1353);
										mem_vec_1353 = vec_107;



										vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_1354);
										mem_vec_1354 = vec_108;



										vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_1355);
										mem_vec_1355 = vec_109;



										vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_1356);
										mem_vec_1356 = vec_110;



										vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_1357);
										mem_vec_1357 = vec_111;



										vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_1358);
										mem_vec_1358 = vec_112;



										vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_1359);
										mem_vec_1359 = vec_113;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_115 = _mm256_set1_ps(scal_10);


										vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_1360);
										mem_vec_1360 = vec_114;



										vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_1361);
										mem_vec_1361 = vec_116;



										vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_1362);
										mem_vec_1362 = vec_117;



										vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_1363);
										mem_vec_1363 = vec_118;



										vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_1364);
										mem_vec_1364 = vec_119;



										vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_1365);
										mem_vec_1365 = vec_120;



										vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_1366);
										mem_vec_1366 = vec_121;



										vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_1367);
										mem_vec_1367 = vec_122;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_124 = _mm256_set1_ps(scal_11);


										vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_1368);
										mem_vec_1368 = vec_123;



										vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_1369);
										mem_vec_1369 = vec_125;



										vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_1370);
										mem_vec_1370 = vec_126;



										vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_1371);
										mem_vec_1371 = vec_127;



										vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_1372);
										mem_vec_1372 = vec_128;



										vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_1373);
										mem_vec_1373 = vec_129;



										vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_1374);
										mem_vec_1374 = vec_130;



										vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_1375);
										mem_vec_1375 = vec_131;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1344);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1345);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1346);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1347);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1348);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_1349);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1350);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_1351);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1352);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1353);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1354);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1355);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1356);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_1357);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1358);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_1359);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1360);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1361);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1362);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1363);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_1365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_1367);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1368);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1369);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1370);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1371);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1372);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_1373);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1374);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_1375);
						}
					}
				}
			}
		}
	}
}


}