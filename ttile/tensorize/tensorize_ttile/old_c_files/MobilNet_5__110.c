#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, y); T (1, f); T (2, c); T (1, f); T (32, c); T (4, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c192_p_0, c193_p_0, cp_1, c192_p_1, cp_2, c192, c193, f, fp_0, f180_p_0, f181_p_0, fp_1, f180_p_1, fp_2, f180, f181, h, hp_0, w, wp_0, x, xp_0, x144_p_0, xp_1, x144, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y96 = 0;
IND_TYPE x145 = 0;
IND_TYPE h96 = 0;
IND_TYPE w96 = 0;
IND_TYPE c194 = 0;
IND_TYPE f182 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1344 ,mem_vec_1345 ,mem_vec_1346 ,mem_vec_1347 ,mem_vec_1348 ,mem_vec_1349 ,mem_vec_1350 ,mem_vec_1351 ,mem_vec_1352 ,mem_vec_1353 ,mem_vec_1354 ,mem_vec_1355 ,mem_vec_1356 ,mem_vec_1357 ,mem_vec_1358 ,mem_vec_1359 ,mem_vec_1360 ,mem_vec_1361 ,mem_vec_1362 ,mem_vec_1363 ,mem_vec_1364 ,mem_vec_1365 ,mem_vec_1366 ,mem_vec_1367 ,mem_vec_1368 ,mem_vec_1369 ,mem_vec_1370 ,mem_vec_1371 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f181 = f182, f181_p_0 = 0;
	f181 < f182 + 256;
	f181 += 64, f181_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 4) (28 / 7)
	for (x144 = x145, x144_p_0 = 0;
		x144 < x145 + 28;
		x144 += 7, x144_p_0 += 7){
		// y = 28, x = 7, h = 3, w = 3, c = 256, f = 64
		// T (c, 32) (256 / 8)
		for (c193 = c194, c193_p_0 = 0;
			c193 < c194 + 256;
			c193 += 8, c193_p_0 += 8){
			// y = 28, x = 7, h = 3, w = 3, c = 8, f = 64
			// T (f, 1) (64 / 64)
			for (f180 = f181, f180_p_1 = f181_p_0, f180_p_0 = 0;
				f180 < f181 + 64;
				f180 += 64, f180_p_1 += 64, f180_p_0 += 64){
				// y = 28, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c192 = c193, c192_p_1 = c193_p_0, c192_p_0 = 0;
					c192 < c193 + 8;
					c192 += 4, c192_p_1 += 4, c192_p_0 += 4){
					// y = 28, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f180, fp_2 = f180_p_1, fp_1 = f180_p_0, fp_0 = 0;
						f < f180 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 7, h = 3, w = 3, c = 4, f = 64
						// T (y, 4) (28 / 7)
						for (y = y96, yp_0 = 0;
							y < y96 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h96, hp_0 = 0;
								h < h96 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w96, wp_0 = 0;
									w < w96 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 7, h = 1, w = 1, c = 4, f = 64
									// T (x, 7) (7 / 1)
									for (x = x144, xp_1 = x144_p_0, xp_0 = 0;
										x < x144 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1346 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_1347 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_1348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_1351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_1352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_1355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_1356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_1359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_1360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_1363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_1364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_1367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_1368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_1371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c192, cp_2 = c192_p_1, cp_1 = c192_p_0, cp_0 = 0;
													c < c192 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1344);
													mem_vec_1344 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1345);
													mem_vec_1345 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1346);
													mem_vec_1346 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1347);
													mem_vec_1347 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1348);
													mem_vec_1348 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1349);
													mem_vec_1349 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1350);
													mem_vec_1350 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1351);
													mem_vec_1351 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1352);
													mem_vec_1352 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1353);
													mem_vec_1353 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1354);
													mem_vec_1354 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1355);
													mem_vec_1355 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1356);
													mem_vec_1356 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1357);
													mem_vec_1357 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1358);
													mem_vec_1358 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1359);
													mem_vec_1359 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1360);
													mem_vec_1360 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1361);
													mem_vec_1361 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1362);
													mem_vec_1362 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1363);
													mem_vec_1363 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1364);
													mem_vec_1364 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1365);
													mem_vec_1365 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1366);
													mem_vec_1366 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1367);
													mem_vec_1367 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1368);
													mem_vec_1368 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1369);
													mem_vec_1369 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1370);
													mem_vec_1370 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1371);
													mem_vec_1371 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1361);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1369);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1371);
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


}