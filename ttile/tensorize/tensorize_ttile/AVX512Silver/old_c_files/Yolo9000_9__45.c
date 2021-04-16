#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (34, x); T (4, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, x, xp_0, x140_p_0, x141_p_0, xp_1, x140_p_1, xp_2, x140, x141, y, yp_0, y105_p_0, yp_1, y105;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y106 = 0;
IND_TYPE x142 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c106 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,mem_vec_1372 ,mem_vec_1373 ,mem_vec_1374 ,mem_vec_1375 ,mem_vec_1376 ,mem_vec_1377 ,mem_vec_1378 ,mem_vec_1379 ,mem_vec_1380 ,mem_vec_1381 ,mem_vec_1382 ,mem_vec_1383 ,mem_vec_1384 ,mem_vec_1385 ,mem_vec_1386 ,mem_vec_1387 ,mem_vec_1388 ,mem_vec_1389 ,mem_vec_1390 ,mem_vec_1391 ,mem_vec_1392 ,mem_vec_1393 ,mem_vec_1394 ,mem_vec_1395 ,mem_vec_1396 ,mem_vec_1397 ,mem_vec_1398 ,mem_vec_1399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
for (y105 = y106, y105_p_0 = 0;
	y105 < y106 + 68;
	y105 += 34, y105_p_0 += 34){
	// y = 34, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 2) (68 / 34)
	for (x141 = x142, x141_p_0 = 0;
		x141 < x142 + 68;
		x141 += 34, x141_p_0 += 34){
			for (y = y105, yp_1 = y105_p_0, yp_0 = 0;
				y < y105 + 4;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (34 / 34)
				for (x140 = x141, x140_p_1 = x141_p_0, x140_p_0 = 0;
					x140 < x141 + 34;
					x140 += 34, x140_p_1 += 34, x140_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f70, fp_0 = 0;
						f < f70 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c105 = c106, c105_p_0 = 0;
							c105 < c106 + 256;
							c105 += 64, c105_p_0 += 64){
							// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 64
							// T (x, 34) (34 / 1)
							for (x = x140, xp_2 = x140_p_1, xp_1 = x140_p_0, xp_0 = 0;
								x < x140 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1360 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1361 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1362 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1363 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
											c < c105 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1360);
											mem_vec_1360 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1361);
											mem_vec_1361 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1362);
											mem_vec_1362 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1363);
											mem_vec_1363 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1364);
											mem_vec_1364 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1365);
											mem_vec_1365 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1366);
											mem_vec_1366 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1367);
											mem_vec_1367 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1368);
											mem_vec_1368 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1369);
											mem_vec_1369 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1370);
											mem_vec_1370 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1371);
											mem_vec_1371 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1372);
											mem_vec_1372 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1373);
											mem_vec_1373 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1374);
											mem_vec_1374 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1375);
											mem_vec_1375 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1375);
							}
						}
					}
				}
			}
			for (y = y105 + 4, yp_1 = y105_p_0, yp_0 = 0;
				y < y105 + 4 + 30;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (34 / 34)
				for (x140 = x141, x140_p_1 = x141_p_0, x140_p_0 = 0;
					x140 < x141 + 34;
					x140 += 34, x140_p_1 += 34, x140_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f70, fp_0 = 0;
						f < f70 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c105 = c106, c105_p_0 = 0;
							c105 < c106 + 256;
							c105 += 64, c105_p_0 += 64){
							// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 64
							// T (x, 34) (34 / 1)
							for (x = x140, xp_2 = x140_p_1, xp_1 = x140_p_0, xp_0 = 0;
								x < x140 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1376 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1377 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1378 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_1379 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_1380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_1383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_1384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_1387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_1388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_1391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_1392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_1395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_1396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_1399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
											c < c105 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1376);
											mem_vec_1376 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1377);
											mem_vec_1377 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1378);
											mem_vec_1378 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1379);
											mem_vec_1379 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1380);
											mem_vec_1380 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1381);
											mem_vec_1381 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1382);
											mem_vec_1382 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1383);
											mem_vec_1383 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1384);
											mem_vec_1384 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1385);
											mem_vec_1385 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1386);
											mem_vec_1386 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1387);
											mem_vec_1387 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1388);
											mem_vec_1388 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1389);
											mem_vec_1389 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1390);
											mem_vec_1390 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1391);
											mem_vec_1391 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1392);
											mem_vec_1392 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1393);
											mem_vec_1393 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1394);
											mem_vec_1394 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1395);
											mem_vec_1395 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1396);
											mem_vec_1396 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1397);
											mem_vec_1397 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1398);
											mem_vec_1398 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1399);
											mem_vec_1399 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1399);
							}
						}
					}
				}
			}
	}
}


}