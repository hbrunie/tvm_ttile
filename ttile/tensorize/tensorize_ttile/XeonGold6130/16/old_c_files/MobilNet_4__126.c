#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (8, c); T (2, f); T (4, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c183_p_0, cp_1, c183, f, fp_0, f183_p_0, fp_1, f183, h, hp_0, w, wp_0, x, xp_0, x167_p_0, xp_1, x167, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y122 = 0;
IND_TYPE x168 = 0;
IND_TYPE h101 = 0;
IND_TYPE w104 = 0;
IND_TYPE c184 = 0;
IND_TYPE f184 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1412 ,mem_vec_1413 ,mem_vec_1414 ,mem_vec_1415 ,mem_vec_1416 ,mem_vec_1417 ,mem_vec_1418 ,mem_vec_1419 ,mem_vec_1420 ,mem_vec_1421 ,mem_vec_1422 ,mem_vec_1423 ,mem_vec_1424 ,mem_vec_1425 ,mem_vec_1426 ,mem_vec_1427 ,mem_vec_1428 ,mem_vec_1429 ,mem_vec_1430 ,mem_vec_1431 ,mem_vec_1432 ,mem_vec_1433 ,mem_vec_1434 ,mem_vec_1435 ,mem_vec_1436 ,mem_vec_1437 ,mem_vec_1438 ,mem_vec_1439 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f183 = f184, f183_p_0 = 0;
	f183 < f184 + 128;
	f183 += 64, f183_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 2) (28 / 14)
	for (y = y122, yp_0 = 0;
		y < y122 + 28;
		y += 14, yp_0 += 14){
		// y = 14, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 4) (28 / 7)
		for (x167 = x168, x167_p_0 = 0;
			x167 < x168 + 28;
			x167 += 7, x167_p_0 += 7){
			// y = 14, x = 7, h = 3, w = 3, c = 128, f = 64
			// T (f, 2) (64 / 32)
			for (f = f183, fp_1 = f183_p_0, fp_0 = 0;
				f < f183 + 64;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 14, x = 7, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c183 = c184, c183_p_0 = 0;
					c183 < c184 + 128;
					c183 += 16, c183_p_0 += 16){
					// y = 14, x = 7, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w104, wp_0 = 0;
						w < w104 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 7, h = 3, w = 1, c = 16, f = 32
						// T (x, 7) (7 / 1)
						for (x = x167, xp_1 = x167_p_0, xp_0 = 0;
							x < x167 + 7;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h101, hp_0 = 0;
								h < h101 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1412 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1413 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_1430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_1431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_1432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_1433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_1434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_1435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_1436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_1437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_1438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_1439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c183, cp_1 = c183_p_0, cp_0 = 0;
											c < c183 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1412);
											mem_vec_1412 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1413);
											mem_vec_1413 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1414);
											mem_vec_1414 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1415);
											mem_vec_1415 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1416);
											mem_vec_1416 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1417);
											mem_vec_1417 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1418);
											mem_vec_1418 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1419);
											mem_vec_1419 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1420);
											mem_vec_1420 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1421);
											mem_vec_1421 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1422);
											mem_vec_1422 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1423);
											mem_vec_1423 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1424);
											mem_vec_1424 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1425);
											mem_vec_1425 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1426);
											mem_vec_1426 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1427);
											mem_vec_1427 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1428);
											mem_vec_1428 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1429);
											mem_vec_1429 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1430);
											mem_vec_1430 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1431);
											mem_vec_1431 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1432);
											mem_vec_1432 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1433);
											mem_vec_1433 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1434);
											mem_vec_1434 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1435);
											mem_vec_1435 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1436);
											mem_vec_1436 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1437);
											mem_vec_1437 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1438);
											mem_vec_1438 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1439);
											mem_vec_1439 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1413);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1421);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1422);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1423);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1424);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1425);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1426);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1427);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1428);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1429);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1430);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1431);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1432);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1433);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1434);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1435);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1436);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1437);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1438);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1439);
							}
						}
					}
				}
			}
		}
	}
}


}