#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (14, x); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (8, c); T (8, f); T (1, c)]
*/
IND_TYPE c, cp_0, c172_p_0, c173_p_0, cp_1, c172_p_1, cp_2, c172, c173, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y86 = 0;
IND_TYPE x86 = 0;
IND_TYPE h = 0;
IND_TYPE w69 = 0;
IND_TYPE c174 = 0;
IND_TYPE f86 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,mem_vec_1372 ,mem_vec_1373 ,mem_vec_1374 ,mem_vec_1375 ,mem_vec_1376 ,mem_vec_1377 ,mem_vec_1378 ,mem_vec_1379 ,mem_vec_1380 ,mem_vec_1381 ,mem_vec_1382 ,mem_vec_1383 ,mem_vec_1384 ,mem_vec_1385 ,mem_vec_1386 ,mem_vec_1387 ,mem_vec_1388 ,mem_vec_1389 ,mem_vec_1390 ,mem_vec_1391 ,mem_vec_1392 ,mem_vec_1393 ,mem_vec_1394 ,mem_vec_1395 ,mem_vec_1396 ,mem_vec_1397 ,mem_vec_1398 ,mem_vec_1399 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c173 = c174, c173_p_0 = 0;
	c173 < c174 + 128;
	c173 += 128, c173_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
	// T (f, 8) (256 / 32)
	for (f = f86, fp_0 = 0;
		f < f86 + 256;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
		// T (c, 8) (128 / 16)
		for (c172 = c173, c172_p_1 = c173_p_0, c172_p_0 = 0;
			c172 < c173 + 128;
			c172 += 16, c172_p_1 += 16, c172_p_0 += 16){
				for (y = y86, yp_0 = 0;
					y < y86 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x = x86, xp_0 = 0;
						x < x86 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w69, wp_0 = 0;
							w < w69 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1362 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1363 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c172, cp_2 = c172_p_1, cp_1 = c172_p_0, cp_0 = 0;
										c < c172 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1360);
										mem_vec_1360 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1361);
										mem_vec_1361 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1362);
										mem_vec_1362 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1363);
										mem_vec_1363 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1364);
										mem_vec_1364 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1365);
										mem_vec_1365 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1366);
										mem_vec_1366 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1367);
										mem_vec_1367 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1368);
										mem_vec_1368 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1369);
										mem_vec_1369 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1370);
										mem_vec_1370 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1371);
										mem_vec_1371 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1372);
										mem_vec_1372 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1373);
										mem_vec_1373 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1374);
										mem_vec_1374 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1375);
										mem_vec_1375 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1360);
										mem_vec_1360 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1361);
										mem_vec_1361 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1362);
										mem_vec_1362 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1363);
										mem_vec_1363 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1364);
										mem_vec_1364 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1365);
										mem_vec_1365 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1366);
										mem_vec_1366 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1367);
										mem_vec_1367 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1368);
										mem_vec_1368 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1369);
										mem_vec_1369 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1370);
										mem_vec_1370 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1371);
										mem_vec_1371 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1372);
										mem_vec_1372 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1373);
										mem_vec_1373 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1374);
										mem_vec_1374 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1375);
										mem_vec_1375 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1360);
										mem_vec_1360 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1361);
										mem_vec_1361 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1362);
										mem_vec_1362 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1363);
										mem_vec_1363 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1364);
										mem_vec_1364 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1365);
										mem_vec_1365 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1366);
										mem_vec_1366 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1367);
										mem_vec_1367 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1368);
										mem_vec_1368 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1369);
										mem_vec_1369 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1370);
										mem_vec_1370 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1371);
										mem_vec_1371 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1372);
										mem_vec_1372 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1373);
										mem_vec_1373 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1374);
										mem_vec_1374 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1375);
										mem_vec_1375 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1360);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1361);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1362);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1363);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1367);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1368);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1369);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1370);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1371);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1372);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1373);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1374);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1375);
						}
					}
				}
				for (y = y86 + 8, yp_0 = 0;
					y < y86 + 8 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x = x86, xp_0 = 0;
						x < x86 + 14;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w69, wp_0 = 0;
							w < w69 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1376 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1377 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1378 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1379 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									mem_vec_1396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_1398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c172, cp_2 = c172_p_1, cp_1 = c172_p_0, cp_0 = 0;
										c < c172 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1376);
										mem_vec_1376 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1377);
										mem_vec_1377 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1378);
										mem_vec_1378 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1379);
										mem_vec_1379 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1380);
										mem_vec_1380 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1381);
										mem_vec_1381 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1382);
										mem_vec_1382 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1383);
										mem_vec_1383 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1384);
										mem_vec_1384 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1385);
										mem_vec_1385 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1386);
										mem_vec_1386 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1387);
										mem_vec_1387 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1388);
										mem_vec_1388 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1389);
										mem_vec_1389 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1390);
										mem_vec_1390 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1391);
										mem_vec_1391 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1392);
										mem_vec_1392 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1393);
										mem_vec_1393 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1394);
										mem_vec_1394 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1395);
										mem_vec_1395 = vec_28;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_30 = _mm256_set1_ps(scal_5);


										vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1396);
										mem_vec_1396 = vec_29;



										vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1397);
										mem_vec_1397 = vec_31;



										vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_1398);
										mem_vec_1398 = vec_32;



										vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_1399);
										mem_vec_1399 = vec_33;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_35 = _mm256_set1_ps(scal_6);
										vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_1376);
										mem_vec_1376 = vec_34;

										vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1377);
										mem_vec_1377 = vec_37;

										vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_1378);
										mem_vec_1378 = vec_39;

										vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_1379);
										mem_vec_1379 = vec_41;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1380);
										mem_vec_1380 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_1381);
										mem_vec_1381 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_1382);
										mem_vec_1382 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_1383);
										mem_vec_1383 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_49 = _mm256_set1_ps(scal_8);


										vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_1384);
										mem_vec_1384 = vec_48;



										vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_1385);
										mem_vec_1385 = vec_50;



										vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_1386);
										mem_vec_1386 = vec_51;



										vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_1387);
										mem_vec_1387 = vec_52;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_54 = _mm256_set1_ps(scal_9);


										vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_1388);
										mem_vec_1388 = vec_53;



										vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_1389);
										mem_vec_1389 = vec_55;



										vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_1390);
										mem_vec_1390 = vec_56;



										vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_1391);
										mem_vec_1391 = vec_57;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_59 = _mm256_set1_ps(scal_10);


										vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1392);
										mem_vec_1392 = vec_58;



										vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_1393);
										mem_vec_1393 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_1394);
										mem_vec_1394 = vec_61;



										vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_1395);
										mem_vec_1395 = vec_62;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_64 = _mm256_set1_ps(scal_11);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_1396);
										mem_vec_1396 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_1397);
										mem_vec_1397 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_1398);
										mem_vec_1398 = vec_66;



										vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_1399);
										mem_vec_1399 = vec_67;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_69 = _mm256_set1_ps(scal_12);
										vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_1376);
										mem_vec_1376 = vec_68;

										vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_1377);
										mem_vec_1377 = vec_71;

										vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_1378);
										mem_vec_1378 = vec_73;

										vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_1379);
										mem_vec_1379 = vec_75;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_78 = _mm256_set1_ps(scal_13);


										vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_1380);
										mem_vec_1380 = vec_77;



										vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_1381);
										mem_vec_1381 = vec_79;



										vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_1382);
										mem_vec_1382 = vec_80;



										vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_1383);
										mem_vec_1383 = vec_81;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_83 = _mm256_set1_ps(scal_14);


										vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_1384);
										mem_vec_1384 = vec_82;



										vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_1385);
										mem_vec_1385 = vec_84;



										vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_1386);
										mem_vec_1386 = vec_85;



										vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_1387);
										mem_vec_1387 = vec_86;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_88 = _mm256_set1_ps(scal_15);


										vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_1388);
										mem_vec_1388 = vec_87;



										vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1389);
										mem_vec_1389 = vec_89;



										vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1390);
										mem_vec_1390 = vec_90;



										vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_1391);
										mem_vec_1391 = vec_91;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_93 = _mm256_set1_ps(scal_16);


										vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_1392);
										mem_vec_1392 = vec_92;



										vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_1393);
										mem_vec_1393 = vec_94;



										vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_1394);
										mem_vec_1394 = vec_95;



										vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_1395);
										mem_vec_1395 = vec_96;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_98 = _mm256_set1_ps(scal_17);


										vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_1396);
										mem_vec_1396 = vec_97;



										vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_1397);
										mem_vec_1397 = vec_99;



										vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_1398);
										mem_vec_1398 = vec_100;



										vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_1399);
										mem_vec_1399 = vec_101;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1376);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1377);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1378);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1379);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1380);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1381);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1382);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1383);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1384);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1385);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1386);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1387);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1388);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1389);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1390);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1391);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1392);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1393);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1394);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1395);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1396);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1397);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1398);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_1399);
						}
					}
				}
		}
	}
}


}