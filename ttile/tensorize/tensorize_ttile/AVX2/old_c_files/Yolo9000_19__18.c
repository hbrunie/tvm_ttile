#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, y);
  T (16, f); T (8, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c111_p_0, cp_1, c111, f, fp_0, x, xp_0, x111_p_0, xp_1, x111, y, yp_0, y111_p_0, yp_1, y111;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y112 = 0;
IND_TYPE x112 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c112 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1332 ,mem_vec_1333 ,mem_vec_1334 ,mem_vec_1335 ,mem_vec_1336 ,mem_vec_1337 ,mem_vec_1338 ,mem_vec_1339 ,mem_vec_1340 ,mem_vec_1341 ,mem_vec_1342 ,mem_vec_1343 ,mem_vec_1344 ,mem_vec_1345 ,mem_vec_1346 ,mem_vec_1347 ,mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y111 = y112, y111_p_0 = 0;
		y111 < y112 + 12;
		y111 += 4, y111_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x111 = x112, x111_p_0 = 0;
			x111 < x112 + 17;
			x111 += 1, x111_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 8) (1024 / 128)
			for (c111 = c112, c111_p_0 = 0;
				c111 < c112 + 1024;
				c111 += 128, c111_p_0 += 128){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 16) (512 / 32)
				for (f = f74, fp_0 = 0;
					f < f74 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y111, yp_1 = y111_p_0, yp_0 = 0;
						y < y111 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x111, xp_1 = x111_p_0, xp_0 = 0;
							x < x111 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1332 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1333 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1334 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1335 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
										c < c111 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1332);
										mem_vec_1332 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1333);
										mem_vec_1333 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1334);
										mem_vec_1334 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1335);
										mem_vec_1335 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1336);
										mem_vec_1336 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1337);
										mem_vec_1337 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1338);
										mem_vec_1338 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1339);
										mem_vec_1339 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1340);
										mem_vec_1340 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1341);
										mem_vec_1341 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1342);
										mem_vec_1342 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1343);
										mem_vec_1343 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1344);
										mem_vec_1344 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1345);
										mem_vec_1345 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1346);
										mem_vec_1346 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1347);
										mem_vec_1347 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1332);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1333);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1334);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1335);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1336);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1337);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1338);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1339);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1340);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1341);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1342);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1343);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1344);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1345);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1346);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1347);
						}
					}
				}
			}
		}
	}
	for (y111 = y112 + 12, y111_p_0 = 0;
		y111 < y112 + 12 + 5;
		y111 += 5, y111_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x111 = x112, x111_p_0 = 0;
			x111 < x112 + 17;
			x111 += 1, x111_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 8) (1024 / 128)
			for (c111 = c112, c111_p_0 = 0;
				c111 < c112 + 1024;
				c111 += 128, c111_p_0 += 128){
				// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 512
				// T (f, 16) (512 / 32)
				for (f = f74, fp_0 = 0;
					f < f74 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y111, yp_1 = y111_p_0, yp_0 = 0;
						y < y111 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x111, xp_1 = x111_p_0, xp_0 = 0;
							x < x111 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1348 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1349 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1350 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1351 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
										c < c111 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1348);
										mem_vec_1348 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1349);
										mem_vec_1349 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1350);
										mem_vec_1350 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1351);
										mem_vec_1351 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1352);
										mem_vec_1352 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1353);
										mem_vec_1353 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1354);
										mem_vec_1354 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1355);
										mem_vec_1355 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1356);
										mem_vec_1356 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1357);
										mem_vec_1357 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1358);
										mem_vec_1358 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1359);
										mem_vec_1359 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1360);
										mem_vec_1360 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1361);
										mem_vec_1361 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1362);
										mem_vec_1362 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1363);
										mem_vec_1363 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1364);
										mem_vec_1364 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1365);
										mem_vec_1365 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1366);
										mem_vec_1366 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1367);
										mem_vec_1367 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1348);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1349);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1350);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1351);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1352);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1353);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1354);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1355);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1356);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1357);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1358);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1359);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1360);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1361);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1362);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1363);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1367);
						}
					}
				}
			}
		}
	}


}