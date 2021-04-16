#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (4, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, f140_p_0, f141_p_0, fp_1, f140_p_1, fp_2, f140, f141, h, hp_0, w, wp_0, x, xp_0, x105_p_0, xp_1, x105, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y70 = 0;
IND_TYPE x106 = 0;
IND_TYPE h70 = 0;
IND_TYPE w65 = 0;
IND_TYPE c106 = 0;
IND_TYPE f142 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1344 ,mem_vec_1345 ,mem_vec_1346 ,mem_vec_1347 ,mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,mem_vec_1372 ,mem_vec_1373 ,mem_vec_1374 ,mem_vec_1375 ,mem_vec_1376 ,mem_vec_1377 ,mem_vec_1378 ,mem_vec_1379 ,mem_vec_1380 ,mem_vec_1381 ,mem_vec_1382 ,mem_vec_1383 ,mem_vec_1384 ,mem_vec_1385 ,mem_vec_1386 ,mem_vec_1387 ,mem_vec_1388 ,mem_vec_1389 ,mem_vec_1390 ,mem_vec_1391 ,mem_vec_1392 ,mem_vec_1393 ,mem_vec_1394 ,mem_vec_1395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f141 = f142, f141_p_0 = 0;
	f141 < f142 + 256;
	f141 += 64, f141_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f140 = f141, f140_p_1 = f141_p_0, f140_p_0 = 0;
		f140 < f141 + 64;
		f140 += 32, f140_p_1 += 32, f140_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x105 = x106, x105_p_0 = 0;
			x105 < x106 + 68;
			x105 += 17, x105_p_0 += 17){
				for (y = y70, yp_0 = 0;
					y < y70 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f140, fp_2 = f140_p_1, fp_1 = f140_p_0, fp_0 = 0;
						f < f140 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c105 = c106, c105_p_0 = 0;
							c105 < c106 + 128;
							c105 += 32, c105_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w65, wp_0 = 0;
								w < w65 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x105, xp_1 = x105_p_0, xp_0 = 0;
									x < x105 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h70, hp_0 = 0;
										h < h70 + 3;
										h += 1, hp_0 += 1){
												mem_vec_1344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
													c < c105 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1344);
													mem_vec_1344 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1345);
													mem_vec_1345 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1346);
													mem_vec_1346 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1347);
													mem_vec_1347 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1348);
													mem_vec_1348 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1349);
													mem_vec_1349 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1350);
													mem_vec_1350 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1351);
													mem_vec_1351 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1352);
													mem_vec_1352 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1353);
													mem_vec_1353 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1354);
													mem_vec_1354 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1355);
													mem_vec_1355 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1356);
													mem_vec_1356 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1357);
													mem_vec_1357 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1358);
													mem_vec_1358 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1359);
													mem_vec_1359 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1360);
													mem_vec_1360 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1361);
													mem_vec_1361 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1362);
													mem_vec_1362 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1363);
													mem_vec_1363 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1364);
													mem_vec_1364 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1365);
													mem_vec_1365 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1366);
													mem_vec_1366 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1367);
													mem_vec_1367 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1367);
									}
								}
							}
						}
					}
				}
				for (y = y70 + 12, yp_0 = 0;
					y < y70 + 12 + 56;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f140, fp_2 = f140_p_1, fp_1 = f140_p_0, fp_0 = 0;
						f < f140 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c105 = c106, c105_p_0 = 0;
							c105 < c106 + 128;
							c105 += 32, c105_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w65, wp_0 = 0;
								w < w65 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x105, xp_1 = x105_p_0, xp_0 = 0;
									x < x105 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h70, hp_0 = 0;
										h < h70 + 3;
										h += 1, hp_0 += 1){
												mem_vec_1368 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1369 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_1384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_1386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_1388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_1389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_1390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_1391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_1392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_1393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_1394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_1395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
													c < c105 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1368);
													mem_vec_1368 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1369);
													mem_vec_1369 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1370);
													mem_vec_1370 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1371);
													mem_vec_1371 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1372);
													mem_vec_1372 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1373);
													mem_vec_1373 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1374);
													mem_vec_1374 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1375);
													mem_vec_1375 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1376);
													mem_vec_1376 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1377);
													mem_vec_1377 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1378);
													mem_vec_1378 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1379);
													mem_vec_1379 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1380);
													mem_vec_1380 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1381);
													mem_vec_1381 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1382);
													mem_vec_1382 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1383);
													mem_vec_1383 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1384);
													mem_vec_1384 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1385);
													mem_vec_1385 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1386);
													mem_vec_1386 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1387);
													mem_vec_1387 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1388);
													mem_vec_1388 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1389);
													mem_vec_1389 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1390);
													mem_vec_1390 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1391);
													mem_vec_1391 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1392);
													mem_vec_1392 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1393);
													mem_vec_1393 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1394);
													mem_vec_1394 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1395);
													mem_vec_1395 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1369);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1371);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1372);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1373);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1374);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1375);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1376);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1377);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1378);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1379);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1380);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1381);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1382);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1383);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1384);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1385);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1386);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1387);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1388);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1389);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1390);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1391);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1392);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1393);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1394);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1395);
									}
								}
							}
						}
					}
				}
		}
	}
}


}